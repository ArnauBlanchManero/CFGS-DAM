public class buscarNombres {

	public static void main(String[] args) {
		String fragmentoNombreAlumnos = "Víctor";
		String[] nombreAlumnos = {"Antonio", "Marta", "Víctor Hugo", "David"};
		
		int resultado = contarUsuarios(fragmentoNombreAlumnos, nombreAlumnos); // Cuenta 
		System.out.println("Total resultados: " + resultado);

	}
	
	static int contarUsuarios(String fragmentoNombreAlumno, String[] nombreAlumnos) {
		boolean encontrado = false;
		int totalEncontrados = 0;
		
		for (String nombreAlumnoActual : nombreAlumnos) {
			if (nombreAlumnoActual.contains(fragmentoNombreAlumno)) {
				encontrado = true;
			}
			
			if (encontrado) {
				totalEncontrados++;
				encontrado = false;
			}
		}
		return totalEncontrados;
	}

}