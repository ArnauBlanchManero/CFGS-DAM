function genera_num_aleatorio(){
    let numero = Math.floor(Math.random()*(100));
    document.getElementById("numeroAleatorio").textContent = numero;
}

function empieza_cuenta_atras(){
    let num = parseInt(document.getElementById("max").value);
    let interval = setInterval(() => {
        if(num>0){
            document.getElementById("cooldown").innerHTML = num;
            num--;
        } else {
            document.getElementById("cooldown").innerHTML = "La cuenta atrás ha finalizado";
            clearInterval(interval); // Detiene el intervalo
        }
    }, 1000); // Ejecuta cada segundo
}

function rellenarTabla(){
    let numero = document.querySelectorAll(".numero").length
    for(let i = 1; i <= numero; i++){
        document.getElementById(`${i}`).innerHTML = i;
    }
}

function juegoBuscaminas(){
    crearMapa();

}

function numAleatorio(max){
    let numero = Math.floor(Math.random()*(max));
    return numero;
}

function cambiaColor(){
    let r= numAleatorio(255);
    let g= numAleatorio(255);
    let b= numAleatorio(255);
    let color = `rgb(${r},${g},${b})`;
    document.getElementById("ratonEncima").style.backgroundColor = color;
}

function juegoPalabras(){
    let palabras = ["perro", "gato", "raton", "elefante", "jirafa", "leon", "tigre", "lobo", "gallina", "pajaro"];
    let contador = 0;
    let num = numAleatorio(palabras.length);
    if (typeof juegoPalabras.palabra === 'undefined') {
        juegoPalabras.palabra = palabras[num];
    }
    let palabra = juegoPalabras.palabra;
    document.getElementById("ahorcado").style.display = "none";
    document.getElementById("letras").style.display = "block";
    console.log(palabra);
    let letra;
    let letras = ["a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "ñ", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"];
    let i = 0;
    while (contador != palabra.length || i == letras.length) {
        console.log("letras[i] = "+letras[i]);
        letra = document.getElementById(`${letras[i]}`).value;
        console.log("letra = "+letra);
        document.getElementById(letra).addEventListener("click", ()=>{
            document.getElementById("palabra").style.display = "block";
            document.getElementById(letra).style.display = "none";
            document.getElementById("palabra").innerHTML = letra;
        });
        for (let j = 0; j < palabra.length; j++) {
            console.log("palabra[j] = "+palabra[j]);
            console.log("letra = "+letra);
            if (palabra[j] === letra) {
                contador++;
                console.log(contador);
                console.log(contador != palabra.length);
            }
        }
        i++;
    }
    console.log("letra = "+letra);
    if (contador == palabra.length) {
        document.getElementById("palabra").innerHTML = palabra;
    } else {
        document.getElementById("palabra").innerHTML = "Has fallado";
    }
}

function load(){
    let botonNumero=document.getElementById("aleatorio");
    botonNumero.addEventListener("click", genera_num_aleatorio);

    let cuentaAtras = document.getElementById("atras");
    cuentaAtras.addEventListener("click", empieza_cuenta_atras);

    let rellenar = document.getElementById("rellenar");
    rellenar.addEventListener("click", rellenarTabla);

    let mouseOver = document.getElementById("ratonEncima");
    mouseOver.addEventListener("mouseover", cambiaColor);

    let empezarAhorcado =document.getElementById("ahorcado");
    empezarAhorcado.addEventListener("click", juegoPalabras);

    /*
    let buscaminas = document.getElementsByClassName("buscaminas");
    buscaminas.addEventListener("click", juegoBuscaminas);
    */
}

window.addEventListener("DOMContentLoaded", load, false);