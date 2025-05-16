package Trabajadores;

public class PruebaTrabajadores {

	public static void main(String[] args) {
		int cantidad = 2;
		Profesor [] profesores = new Profesor[cantidad];
		Administracion [] administradores = new Administracion[cantidad];
		Directivo [] directivos = new Directivo[cantidad];

		profesores = crearProfes(cantidad);
		administradores = crearAdmins(cantidad);
		directivos = crearDirectivos(cantidad);
		System.out.println("Bienvenido al colegio, estos son nuestros trabajadores.\n");
		mostrarProfes(profesores);
		mostrarAdmins(administradores);
		mostrarDirectivos(directivos);
		
		Modulo [] modulos = new Modulo[cantidad];
		Alumno [] alumnos = new Alumno[cantidad];
		
		modulos = crearModulos(cantidad, profesores);
		alumnos = crearAlumnos(cantidad, modulos);
		System.out.println("\nEstos son nuestros alumnos con sus modulos. \n");
		mostrarAlumnosModulos(alumnos);
	}

	private static void mostrarAlumnosModulos(Alumno[] alumnos) {
		for (int i = 0; i < alumnos.length; i++) {
			System.out.println(alumnos[i].toString());
		}
	}

	private static Alumno[] crearAlumnos(int cantidad, Modulo[] modulos) {
		Alumno [] alumnos = new Alumno[cantidad];
		alumnos[0] = new Alumno("04592714Z", "Arnau", "Blanch", "16/07/2006", Sexo.HOMBRE, false, modulos);
		alumnos[1] = new Alumno("34912501J", "Samuel", "Carias", "08/03/2002", Sexo.HOMBRE, true, modulos);
		return alumnos;
	}

	private static Modulo[] crearModulos(int cantidad, Profesor[] profesores) {
		Modulo [] modulos = new Modulo[cantidad];
		modulos[0] = new Modulo("Programacion", 300, profesores[1], false);
		modulos[1] = new Modulo("Base de Datos", 800, profesores[0], true);
		return modulos;
	}

	private static void mostrarDirectivos(Directivo[] directivos) {
		for (int i = 0; i < directivos.length; i++) {
			System.out.println(directivos[i].toString());
		}
	}

	private static void mostrarAdmins(Administracion[] administradores) {
		for (int i = 0; i < administradores.length; i++) {
			System.out.println(administradores[i].toString());
		}
	}

	private static void mostrarProfes(Profesor[] profesores) {
		for (int i = 0; i < profesores.length; i++) {
			System.out.println(profesores[i].toString());
		}
	}

	private static Directivo[] crearDirectivos(int cantidad) {
		Directivo [] directivos = new Directivo[cantidad];
		directivos[0] = new Directivo("39473291K", "Jose", "Escamilla", 2100, true, Turno.MAÑANA);
		directivos[1] = new Directivo("59327814N", "Carlos", "Villaverde", 2000, false, Turno.TARDE);
		return directivos;
	}

	private static Administracion[] crearAdmins(int cantidad) {
		Administracion [] administradores = new Administracion[cantidad];
		administradores[0] = new Administracion("58236451D", "Victoria", "Fuentes", 900, "Cocina", 3);
		administradores[1] = new Administracion("94728471J", "Mario", "Borja", 900, "Administracion", 7);
		return administradores;
	}

	private static Profesor[] crearProfes(int cantidad) {
		Profesor [] profesores = new Profesor[cantidad];
		profesores[0] = new Profesor("12345678A", "Beatriz", "Martinez", 1700, 3, true);
		profesores[1] = new Profesor("98765432Z", "Sergio", "Crespo", 1500, 1, false);
		return profesores;
	}

}
