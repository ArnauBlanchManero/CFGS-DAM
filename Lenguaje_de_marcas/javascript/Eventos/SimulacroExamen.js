let matriz = [[0,0,0],[0,0,0],[0,0,0]];
let numeroAdivinar = 0;
let dinero = 10;
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
    for(let i=0;i<=9;i++){
        tabla += "<tr>";
        for(let j=0;j<=9;j++){
            console.log(letras[j]+""+i);
            tabla += "<td>";
            tabla += "<button ";
            tabla += "class='boton2' ";
            tabla += "id='"+letras[j]+i+"' ";
            tabla += "value='0'>";
            tabla += "·";
            tabla += "</button>";
            tabla += "</td>";
        }
        tabla += "</tr>";
    }
    document.getElementById(idmapa).innerHTML = tabla;
    colocarBarcos(idmapa);
}

function colocarBarcos(idmapa){
    let j = 4;
    for(let i=1;i<5;i++){
        colocaBarco(idmapa, i, j);
        j--;
    }
}

function empezar_ej2(){
    crearMapa("mapaOponente");
    crearMapa("mapaJugador");
    document.getElementById("start2").style.display = "none";
    document.getElementById("ej2").style.display = "block";
}

function load(){
    let empezar1 = document.getElementById("start1");
    empezar1.addEventListener("click", empezar_ej1)
    let botonesX = document.querySelectorAll(".boton");
    botonesX.forEach(boton=>boton.addEventListener("click", comprobarNumero));
    let reset = document.getElementById("reiniciar");
    reset.addEventListener("click", rellenarMatriz);

    let empezar2 = document.getElementById("start2");
    empezar2.addEventListener("click", empezar_ej2);
    let celdas = document.querySelectorAll(".boton2");
    celdas.forEach(celda=>celda.addEventListener("click", comprobarBarco));
}

window.addEventListener("DOMContentLoaded", load);