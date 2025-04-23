function aleatorio(number){
    return Math.floor(Math.random()*(number+1));
}

function cambiarFondo(){
    console.log("color cambiado");
    document.body.style.background=`rgb(${aleatorio(255)},${aleatorio(255)},${aleatorio(255)})`;
}

function escribeTexto(event){
    event.preventDefault();
    let texto = document.getElementById("escribe").value;
    document.getElementById("texto") += texto;
}

function load(){
    let boton= document.querySelector("button");
    let escribeTexto = document.getElementById("escribe");
    let boton3=document.getElementById("boton3");
    let zona=document.getElementById("zona");
    let formulario=document.getElementById("Formulario");
    
    boton.addEventListener("mousedown", cambiarFondo, false);
    boton3.addEventListener("click",(event)=>console.log(event));
    escribeTexto.addEventListener("keydown",(event)=>(document.getElementById("textoSalida").textContent += `${event.key}`));
    zona.addEventListener("mousemove",(event)=>(document.getElementById("coordenada").textContent=`Coordenadas: X=${event.clientX} y Y=${event.clientY}`));
    formulario.addEventListener("submit",escribeTexto);
}

window.addEventListener("DOMContentLoaded", load, false);