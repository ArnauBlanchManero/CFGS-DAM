function aleatorio(number){
    return Math.floor(Math.random()*(number+1));
}

function cambiarFondo(){
    console.log("funciona");
    document.body.style.background=`rgb(${aleatorio(255)},${aleatorio(255)},${aleatorio(255)})`;
}

function load(){
    let boton= document.querySelector("button");
    let cuadroTexto = document.getElementsByName("texto").value;
    
    boton.addEventListener("mousedown", cambiarFondo, false);
    cuadroTexto.addEventListener("keydown", )
}

window.addEventListener("DOMContentLoaded", load, false);