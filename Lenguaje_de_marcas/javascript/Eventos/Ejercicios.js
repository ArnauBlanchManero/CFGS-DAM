function genera_num_aleatorio(){
    let numero = Math.floor(Math.random()*(100));
    document.getElementById("numeroAleatorio").textContent = numero;
}

function empieza_cuenta_atras(){
    let num = document.getElementById("max").value;
    if(num>0){
        num--;
        document.getElementById("cooldown").innerHTML = num;
    } else {
        document.getElementById("cooldown").innerHTML = "La cuenta atrás ha finalizado";
    }
}

function load(){
    let botonNumero=document.getElementById("aleatorio");
    botonNumero.addEventListener("click", genera_num_aleatorio);

    let cuentaAtras = document.getElementById("atras");
    cuentaAtras.addEventListener("click", empieza_cuenta_atras);
}

window.addEventListener("DOMContentLoaded", load, false);