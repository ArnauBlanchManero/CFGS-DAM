function aleatorio(number){
    return Math.floor(Math.random()*(number+1));
}

function cambiarFondo(){
    console.log("funciona");
    document.body.style.background=`rgb(${aleatorio(255)},${aleatorio(255)},${aleatorio(255)})`;
}

function load(){
    let boton= document.querySelector("button");
    boton.addEventListener("mousedown", cambiarFondo, false);

}

window.addEventListener("DOMContentLoaded", load, false);