function separar(){
    var frase = document.getElementById("palabrasSplit").value;
    frase = frase.split(",");
    var select = "<select name='palabras'>";
    for(var i = 0; i < frase.length; i++){
        select += "<option name='"+frase[i]+"' id='"+frase[i]+"'>"+frase[i]+"</option>";
    }
    select += "</select>";
    document.getElementById("resultadoSplit").innerHTML = select;
}

function buscar(){
    var frase = document.getElementById("palabrasInclude").value;
    frase = frase.toLowerCase();
    encontrado = frase.includes("hola");
    var sino;
    if(encontrado){
        sino = "Sí, "
    } else {
        sino = "No "
    }
    sino += "he encontrado 'hola'"
    document.getElementById("resultadoInclude").innerHTML = sino;
}

// Funcion que llama a todas las funciones y funciona como el main
function carga(){
    alert("Funciona!");
}
window.addEventListener("DOMContentLoaded",carga,false);
document.writeln("Hello World");