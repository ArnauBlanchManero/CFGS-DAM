function exp2(){
    //Fecha ejericio 1
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
    //Correo electrónico ejercicio 2
    let correo=document.getElementById("correo").value;
    let expReg_correo=/^\w+@[A-Za-z]+.\w{2,}$/;
    if(expReg_correo.test(correo)){
        document.getElementById("solucion2").innerHTML += correo +" es válido <br>";
    } else {
        document.getElementById("solucion2").innerHTML += correo +" es inválido <br>";
    }
    //Teléfono ejercicio 3
    let telefono=/^[0-9]{2}-[0-9]{3}-[0-9]{2}-[0-9]{2}-[0-9]{2}$/;
    //Palabra ejemplo ejercicio 4
    let palabra_ejemplo=/\pejemplo\p/;
    //Palabra ipsum ejercicio 5
    let palabra_ipsum=/\pipsum\p/;
    //Contraseña ejercicio 6
    let contraseña=/^[A-Z0-9a-z]*$/;
}