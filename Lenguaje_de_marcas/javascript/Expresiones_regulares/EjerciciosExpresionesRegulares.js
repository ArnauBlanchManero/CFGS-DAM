function exp1(){
    let solucion = "";

    //Fecha ejericio 1
    let fecha=document.getElementById("fecha").value;
    //let expReg_fecha=/^\d{2},\d{2},\d{4}$/;
    let expReg_fecha=/^(0[1-9]|(1|2)[0-9]|3[0-1]),(0[1-9]|1[0-2]),\d{4}$/;
    if(expReg_fecha.test(fecha)){
        solucion += fecha +" es válido <br>";
    } else {
        solucion += fecha +" es inválido <br>";
    }
    let partesFecha=fecha.split(",");
    let day = parseInt(partesFecha[0]);
    let month = parseInt(partesFecha[1]);
    let year = parseInt(partesFecha[2]);

    let fechaIntroducida= new Date(day,month,year);
    let fechaActual = new Date();
    solucion += fechaActual;
    let diferencia = fechaActual - fechaIntroducida;
    let diasTranscurridos = Math.floor(diferencia / (1000*60*60*24));
    solucion += "Han pasado " + diasTranscurridos + " días desde la fecha ingresada. <br>";

    //Correo electrónico ejercicio 2
    let correo=document.getElementById("correo").value;
    let expReg_correo=/^\w+@[A-Za-z]+.\w{2,3}$/;
    let partesCorreo=correo.split("@");
    let longitudUsuario=partesCorreo[0].length();
    if(expReg_correo.test(correo)){
        solucion += correo +" es válido <br>";
        solucion += "El nombre de usuario " +partesCorreo[0] +" tiene de longitud "+ longitudUsuario +"<br>";
    } else {
        solucion += correo +" es inválido <br>";
    }

    //Teléfono ejercicio 3
    let telefono = document.getElementById("telefono").value;
    let expReg_telefono = /^\d{2}-\d{3}-\d{2}-\d{2}-\d{2}$/;
    if (expReg_telefono.test(telefono)) {
        let prefijo = telefono.split("-");
        let origen = prefijo[0] == "91" ? "Madrid" : "Otro lugar";
        solucion += "Teléfono válido. Origen: " + origen + " <br>";
    } else {
        solucion += "Teléfono inválido. Longitud: " + telefono.length + " caracteres <br>";

    }
    
    //Palabra ejemplo ejercicio 4
    let frase = document.getElementById("frase").value;
    let palabra = "hola";
    let partes = frase.split(palabra);
    solucion += "La palabra "+palabra+" aparece "+partes.length()+ " veces. <br>";
    

    //Palabra ipsum ejercicio 5
    let palabraReemplazar = document.getElementById("reemplazar").value;
    let expReg_ipsum=/\pipsum\p/;
    if (expReg_ipsum.test(palabraReemplazar)) {
        palabraReemplazar = "dolor"
    }
    solucion += "Frase modificada: "+palabraReemplazar+" <br>";

    //Contraseña ejercicio 6
    let contrasena = document.getElementById("contrasena").value;
    //let expReg_contrasena = /^[[A-Z]+[0-9]+[a-z]+]*$/;
    let expReg_contrasena = /^(?=.*[a-z])(?=.*[A-Z])(?=.*\d).+$/;
    if(expReg_contrasena.test(contrasena)){
        solucion += "Contraseña válida <br>";
    } else {
        solucion += "Contraseña inválida <br>";
    }
    document.getElementById("solucion").innerHTML = solucion;
}