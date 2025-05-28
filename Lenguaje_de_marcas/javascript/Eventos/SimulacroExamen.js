let matriz = [[0,0,0],[0,0,0],[0,0,0]];
let numeroAdivinar = 0;
let dinero = 10;
let puntos = [0,0];
function random(num){
    return Math.floor(Math.random()*(num+1));
}

function generar_num_aleatorio(){
    numeroAdivinar=random(9);
    document.getElementById("numeroAdivinar").innerHTML = numeroAdivinar;
}

function rellenarMatriz(){
    for(let i=0;i<3;i++){
        for(let j=0;j<3;j++){
            matriz[i][j]=random(9);
            console.log(matriz[i][j]);
            document.getElementById(""+i+j).disabled=false;
            document.getElementById(""+i+j).textContent="X";
        }
    }
}

function comprobarNumero(event){
    let i=event.target.value[0];
    let j=event.target.value[1];
    if(dinero<=0){
        alert("Te has quedado sin dinero para jugar");
    } else {
        if(matriz[i][j]===numeroAdivinar){
            document.getElementById(event.target.value).textContent=matriz[i][j];
            document.getElementById(event.target.value).disabled=true;
            dinero += 5;
        } else {
            console.log("matriz: " + matriz[i][j])
            document.getElementById(event.target.value).disabled=true;
            dinero --;
        }
    }
    document.getElementById("dinero").innerHTML = dinero;
}

function empezar_ej1(){
    rellenarMatriz();
    generar_num_aleatorio();
    document.getElementById("start1").style.display = "none";
    document.getElementById("ej1").style.display = "block";
    document.getElementById("dinero").innerHTML = dinero;
}

function crearMapa(idmapa){
    let tabla = "";
    let letras = ['A','B','C','D','E','F','G','H','I','J'];
    tabla += "<tr>";
    tabla += "<td></td>";
    for(let i=0;i<10;i++){
        tabla += "<td>" + letras[i] + "</td>";
    }
    tabla += "</tr>";
    for(let i=0;i<=9;i++){
        tabla += "<tr>";
        tabla += "<td>" + (i+1) + "</td>";
        for(let j=0;j<=9;j++){
            tabla += "<td>";
            tabla += "<button ";
            tabla += "class='boton2' ";
            if(idmapa=="mapaJugador"){
                tabla += "id='"+letras[j]+i+"p' ";
            } else if(idmapa=="mapaOponente"){
                tabla += "id='"+letras[j]+i+"o' ";
            } else{
                tabla += "id='"+letras[j]+i+"' ";
            }
            tabla += "value='0'>";
            tabla += "·";
            tabla += "</button>";
            tabla += "</td>";
        }
        tabla += "<td>" + (i+1) + "</td>";
        tabla += "</tr>";
    }
    tabla += "<tr>";
    tabla += "<td></td>";
    for(let i=0;i<10;i++){
        tabla += "<td>" + letras[i] + "</td>";
    }
    tabla += "</tr>";
    document.getElementById(idmapa).innerHTML = tabla;
    colocarBarcos(idmapa);
    if(idmapa=="mapaJugador"){
        mostrarMapa('p');
    }
}

function colocarBarcos(idmapa){
    for(let longitud=4;longitud>=1;longitud--){
        for(let cantidad=0;cantidad<5-longitud;cantidad++){
            colocaBarco(idmapa, longitud);
        }
    }
}

function colocaBarco(idmapa, longitud){
    let direccion = ""+random(3);
    switch(direccion){
        case '0': // Arriba
        direccion = 'N';
        break;
        case '1': // Abajo
        direccion = 'S';
        break;
        case '2': // Izquierda
        direccion = 'O';
        break;
        case '3': // Derecha
        direccion = 'E';
        break;
        default:
        direccion = 'N';
    }
    let letras = ['A','B','C','D','E','F','G','H','I','J'];
    let celdaRandom;
    do {
        celdaRandom = "";
        celdaRandom += letras[random(9)] + random(9);
        if(idmapa=="mapaJugador"){
            celdaRandom += 'p';
        } else if(idmapa=="mapaOponente"){
            celdaRandom += 'o';
        }
        console.log("Celda random: "+celdaRandom);
    }while(!comprobarCelda(celdaRandom, longitud, direccion));
    marcarBorde(celdaRandom, longitud, direccion);
    for(let i=0;i<longitud;i++){
        console.log("Celda buena: "+celdaRandom);
        console.log("Longitud:                     "+longitud);
        document.getElementById(celdaRandom).value = 1;
        if (direccion === 'N') {
            celdaRandom = celdaRandom[0] + (parseInt(celdaRandom[1]) - 1) + celdaRandom[2];
            console.log("Norte: "+celdaRandom);
        } else if (direccion === 'S') {
            celdaRandom = celdaRandom[0] + (parseInt(celdaRandom[1]) + 1) + celdaRandom[2];
            console.log("Sur: "+celdaRandom);
        } else if (direccion === 'O') {
            celdaRandom = String.fromCharCode(celdaRandom.charCodeAt(0) - 1) + celdaRandom[1] + celdaRandom[2];
            console.log("Oeste: "+celdaRandom);
        } else if (direccion === 'E') {
            celdaRandom = String.fromCharCode(celdaRandom.charCodeAt(0) + 1) + celdaRandom[1] + celdaRandom[2];
            console.log("Este: "+celdaRandom);
        }
    }
}

function comprobarCelda(celda, longitud, direccion){
    console.log("Comprobar celda: "+celda);
    console.log("Direccion: "+direccion);
    let letras = ['A','B','C','D','E','F','G','H','I','J'];
    let columna = letras.indexOf(celda[0]);
    console.log("Columna: "+columna);
    let fila = parseInt(celda[1]);
    console.log("Fila: "+fila);
    if(direccion === 'N' && fila - (longitud-1) < 0){
        return false;
    }
    if(direccion === 'S' && fila + (longitud-1) > 9){
        return false;
    }
    if(direccion === 'O' && columna - (longitud-1) < 0){
        return false;
    }
    if(direccion === 'E' && columna + (longitud-1) > 9){
        return false;
    }

    let tipoCelda = "";
    
    if(celda[2] === 'p'){
        tipoCelda = 'p';
    } else if(celda[2] === 'o'){
        tipoCelda = 'o';
    }
    for(let i=0;i<longitud;i++){
        if(direccion === 'N'){
            console.log("Norte: "+letras[columna]+(fila-i)+tipoCelda);
            if(document.getElementById(letras[columna]+(fila-i)+tipoCelda).value != 0){
                return false;
            }
        } else if(direccion === 'S'){
            console.log("Sur: "+letras[columna]+(fila+i)+tipoCelda);
            if(document.getElementById(letras[columna]+(fila+i)+tipoCelda).value != 0){
                return false;
            }
        } else if(direccion === 'O'){
            console.log("Oeste: "+letras[columna-i]+fila+tipoCelda);
            if(document.getElementById(letras[columna-i]+fila+tipoCelda).value != 0){
                return false;
            }
        } else if(direccion === 'E'){
            console.log("Este: "+letras[columna+i]+fila+tipoCelda);
            if(document.getElementById(letras[columna+i]+fila+tipoCelda).value != 0){
                return false;
            }
        }
    }
    return true;
}

function mostrarMapa(mapa){
    let valor = 0;
    let letras = ['A','B','C','D','E','F','G','H','I','J'];
    for(let i=0;i<10;i++){
        for(let j=0;j<10;j++){
            valor = document.getElementById(letras[j]+i+mapa).value;
            switch(valor){
                case '0':
                    document.getElementById(letras[j]+i+mapa).innerHTML = "~";
                    break;
                case '1':
                    document.getElementById(letras[j]+i+mapa).innerHTML = "X";
                    break;
                case '2':
                    document.getElementById(letras[j]+i+mapa).innerHTML = "~";
                    break;
                default:
                    document.getElementById(letras[j]+i+mapa).innerHTML = "?";
                    break;
            }
            document.getElementById(letras[j]+i+mapa).disabled = true;
        }
    }
}

function marcarBorde(celdaRandom, longitud, direccion){
    let letras = ['A','B','C','D','E','F','G','H','I','J'];
    let columna = letras.indexOf(celdaRandom[0]);
    let fila = parseInt(celdaRandom[1]);
    let mapa = celdaRandom[2];
    const coordenadas = [];

    // Recorremos todas las celdas del barco
    for(let i = 0; i < longitud; i++) {
        coordenadas.push([fila, columna]);

        switch(direccion){
            case 'N': fila--; break;
            case 'S': fila++; break;
            case 'O': columna--; break;
            case 'E': columna++; break;
        }
    }

    // Por cada celda del barco, marcamos el borde (3x3 alrededor de cada celda)
    for (const [f, c] of coordenadas) {
        for (let df = -1; df <= 1; df++) {
            for (let dc = -1; dc <= 1; dc++) {
                let nf = f + df;
                let nc = c + dc;
                if (nf >= 0 && nf <= 9 && nc >= 0 && nc <= 9) {
                    let id = letras[nc] + nf + mapa;
                    let celda = document.getElementById(id);
                    if (celda && celda.value == 0) {
                        celda.value = 2; // Marcamos borde
                    }
                }
            }
        }
    }
}

function comprobarBarco(event){
    let id = event.target.id;
    let valor = document.getElementById(id).value;
    console.log("ID: "+id);
    console.log("Valor: "+valor);
    if(valor == 1){
        document.getElementById(id).innerHTML = "X";
        document.getElementById(id).disabled = true;
        document.getElementById(id).value = 0;
        puntos[0]++;
    } else{
        document.getElementById(id).innerHTML = "O";
        document.getElementById(id).disabled = true;
        document.getElementById(id).value = 0;
    }
    if(puntos[0] == 20){
        alert("Has ganado");
    } else {
        atacaOponente();
    }
}

function atacaOponente(){
    let letras = ['A','B','C','D','E','F','G','H','I','J'];
    let celdaRandom;
    do {
        celdaRandom = "";
        celdaRandom += letras[random(9)] + random(9) + 'p';
        console.log("Celda random: "+celdaRandom);
   } while (document.getElementById(celdaRandom).value == 3);
   document.getElementById(celdaRandom).value = 3;
   document.getElementById(celdaRandom).style.backgroundColor = "red";
   if(document.getElementById(celdaRandom).value == 1){
        puntos[1]++;
   }
   if(puntos[1] == 20){
        alert("Has perdido");
        mostrarMapa('o');
    }
}

function empezar_ej2(){
    document.getElementById("start2").style.display = "none";
    document.getElementById("ej2").style.display = "block";
    crearMapa("mapaOponente");
    crearMapa("mapaJugador");
}

// Cache the result of document.querySelectorAll(".boton2") outside the load function
let cachedCeldas = document.querySelectorAll(".boton2");

function load(){
    let empezar1 = document.getElementById("start1");
    empezar1.addEventListener("click", empezar_ej1)
    let botonesX = document.querySelectorAll(".boton");
    botonesX.forEach(boton=>boton.addEventListener("click", comprobarNumero));
    let reset = document.getElementById("reiniciar");
    reset.addEventListener("click", rellenarMatriz);

    let empezar2 = document.getElementById("start2");
    empezar2.addEventListener("click", empezar_ej2);
    cachedCeldas.forEach(celda=>celda.addEventListener("click", comprobarBarco));
    document.body.addEventListener("click", function(event) {
        if (event.target.classList.contains("boton2")) {
            comprobarBarco(event);
        }
    });
}

window.addEventListener("DOMContentLoaded", load);