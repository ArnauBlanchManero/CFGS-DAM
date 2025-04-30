function expresionesRegulares(event){
    event.preventDefault();
    verificaNombre();
    verificaApellido();
    if(verificaNota(1) && verificaNota(2) && verificaNota(3))
        hacerMedia();
}

function verificaNombre(){
    let nombre = document.getElementById("nombreAlumno").value;
    let ExRegNombre = /^[A-Z][a-z]+$/;
    let correcto = escribeFunciona(nombre, ExRegNombre, "Nombre");
    return correcto;
}

function verificaApellido(){
    let apellido = document.getElementById("apellidoAlumno").value;
    let ExRegApellido = /^[A-Z][a-z]+$/;
    let correcto = escribeFunciona(apellido, ExRegApellido, "Apellido");
    return correcto;
}

function verificaNota(num){
    let nota = document.getElementById(`nota${num}`).value;
    let ExRegNota = /^[0-9]|[10]$/;
    let correcto = escribeFunciona(nota, ExRegNota, `Nota${num}`);
    return correcto;
}

function hacerMedia(){
    let nota1 = parseInt(document.getElementById("nota1").value);
    let nota2 = parseInt(document.getElementById("nota2").value);
    let nota3 = parseInt(document.getElementById("nota3").value);
    let media = (nota1 + nota2 + nota3) / 3;
    document.getElementById("media").innerHTML += media;
}

function escribeFunciona(dato, expresion, campo){
    if(expresion.test(dato)){
        document.getElementById(`funciona${campo}`).innerHTML = "Has escrito bien el " +campo;
        return true;
    } else {
        document.getElementById(`funciona${campo}`).innerHTML = "Has escrito mal el " +campo;
        return false;
    }
}

function load(){
    console.log("funca");
    let formulario = document.getElementById("enviar");
    formulario.addEventListener("click", expresionesRegulares);
}

window.addEventListener("DOMContentLoaded", load, false);