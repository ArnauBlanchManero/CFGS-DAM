/*
Definir expresión regular
    1. let expReg=/abc/
    2. let expReg= new RegExp("abc")
Aserciones
    + --> Uno o más caracteres
    ? --> Un caracter o ninguno
    * --> Ninguno o más caracteres
    \w --> [A-Za-z0-9_]
    \d --> [0-9]
    \s --> " "
    ^ --> /^A/ Inicio frase
    $ --> /\w+o$/ Final frase
    \b -->  /\ba/ Inicio palabra
            /a\b/ Final palabra
    \B --> /\w+/Bo/ Nose
*/
function exp1(){
    // Que empiece por A
    let expReg_A=/^A/;
    let expReg_O=/o$/;
    let expReg_b=/\bhola\b/;
    let expReg_az=/[A-Za-z]+/;
    let expReg_09=/[0-9]+/;
    let expReg_2_09=/\b\d{2}\b/;
        // Conocemos el número {2}
        // Rango {3,7}
        // A partir de {4,}
    let palabra=document.getElementById("palabra").value;
    if(expReg_A.test(palabra)){
        document.getElementById("solucion").innerHTML = palabra +" --> empieza por A <br>";
    } else {
        document.getElementById("solucion").innerHTML = palabra +" --> no empieza por A <br>";
    }
    if(expReg_O.test(palabra)){
        document.getElementById("solucion").innerHTML += palabra +" --> termina por O <br>";
    } else {
        document.getElementById("solucion").innerHTML += palabra +" --> no termina por O <br>";
    }
    if(expReg_b.test(palabra)){
        document.getElementById("solucion").innerHTML += palabra +" --> contiene \"hola\" <br>";
    } else {
        document.getElementById("solucion").innerHTML += palabra +" --> no contiene \"hola\" <br>";
    }
    if(expReg_az.test(palabra)){
        document.getElementById("solucion").innerHTML += palabra +" --> es una palabra alfabética <br>";
    } else {
        document.getElementById("solucion").innerHTML += palabra +" --> no es una palabra alfabética <br>";
    }
    if(expReg_09.test(palabra)){
        document.getElementById("solucion").innerHTML += palabra +" --> es una cadena numérica <br>";
    } else {
        document.getElementById("solucion").innerHTML += palabra +" --> no es una cadena numérica <br>";
    }
    if(expReg_2_09.test(palabra)){
        document.getElementById("solucion").innerHTML += palabra +" --> contiene una cadena numérica de dos dígitos <br>";
    } else {
        document.getElementById("solucion").innerHTML += palabra +" --> no contiene una cadena numérica de dos dígitos <br>";
    }
}
function exp2(){
    //Fecha
    let fecha=document.getElementById("fecha").value;
    //let expReg_fecha=/^\d{2},\d{2},\d{4}$/;
    let expReg_fecha=/^(0[1-9]|(1|2)[0-9]|3[0-1]),(0[1-9]|1[0-2]),\d{4}$/;
    if(expReg_fecha.test(fecha)){
        document.getElementById("solucion2").innerHTML = fecha +" es válido <br>";
    } else {
        document.getElementById("solucion2").innerHTML = fecha +" es inválido <br>";
    }
    let partesFecha=fecha.split(",");
    let day = parseInt(partesFecha[0]);
    let month = parseInt(partesFecha[1]);
    let year = parseInt(partesFecha[2]);

    let fechaIntroducida= new Date(day,month,year);
    //Correo electrónico
    let correo=document.getElementById("correo").value;
    let expReg_correo=/^\w+@[A-Za-z]+.\w{2,}$/;
    if(expReg_correo.test(correo)){
        document.getElementById("solucion2").innerHTML += correo +" es válido <br>";
    } else {
        document.getElementById("solucion2").innerHTML += correo +" es inválido <br>";
    }
}
function load(){
    //exp1();
    //exp2();
}
window.addEventListener("DOMContentLoaded", load, false);