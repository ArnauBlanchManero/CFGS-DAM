package Trabajadores;
import java.util.Scanner;

public class PruebaTrabajadores {
	static Scanner entrada = new Scanner(System.in);

	public static void main(String[] args) {
		int cantidad_profesores=0;
		Profesor [] profesores = null;
		int cantidad_admin=0;
		Administracion [] administradores = null;
		int cantidad_directivos=0;
		Directivo [] directivos = null;
		int cantidad_modulos=0;
		Modulo [] modulos = null;
		int cantidad_alumnos=0;
		Alumno [] alumnos = null;
		boolean repetir;
		do {
			repetir = true;
			int opcion;
			System.out.println("Menú del colegio");
			System.out.println("1- Añadir profesores");
			System.out.println("2- Añadir administradores");
			System.out.println("3- Añadir directivos");
			System.out.println("4- Añadir modulos");
			System.out.println("5- Añadir alumnos");
			System.out.println("6- Mostrar todo");
			System.out.println("7- Salir");
			System.out.print("Opcion: ");
			opcion = entrada.nextInt();
			entrada.nextLine();
			switch (opcion) {
				case 1:
					cantidad_profesores = pedirCantidad("profesores");
					profesores = new Profesor[cantidad_profesores];
					profesores = crearProfes(cantidad_profesores);
					break;
				case 2:
					cantidad_admin = pedirCantidad("administradores");
					administradores = new Administracion[cantidad_admin];
					administradores = crearAdmins(cantidad_admin);
					break;
				case 3:
					cantidad_directivos = pedirCantidad("directivos");
					directivos = new Directivo[cantidad_directivos];
					directivos = crearDirectivos(cantidad_directivos);
					break;
				case 4:
					if (profesores == null) {
						System.out.println("Lo siento pero tienes que añadir profesores antes.");
					} else {
						cantidad_modulos = pedirCantidad("modulos");
						modulos = new Modulo[cantidad_modulos];
						modulos = crearModulos(cantidad_modulos, profesores);
					}
					break;
				case 5:
					if (modulos == null) {
						System.out.println("Lo siento pero tienes que añadir modulos antes.");
					} else {
						cantidad_alumnos = pedirCantidad("alumnos");
						alumnos = new Alumno[cantidad_alumnos];
						alumnos = crearAlumnos(cantidad_alumnos, modulos);
					}
					break;
				case 6:
					System.out.println("Aquí está toda la información que has añadido.\n");
					if (profesores != null) {
						mostrarProfes(profesores);
					} else {
						System.out.println("No hay profesores.");
					}
					if (administradores != null) {
						mostrarAdmins(administradores);
					}else {
						System.out.println("No hay administradores");
					}
					if (directivos != null) {
						mostrarDirectivos(directivos);
					} else {
						System.out.println("No hay directivos");
					}
					if (alumnos != null) {
						mostrarAlumnosModulos(alumnos);
					} else {
						System.out.println("No hay alumnos");
					}
					break;
				case 7:
					repetir = false;
					break;
				default:
					repetir = true;
					break;
			}
		} while (repetir);
		

		
	}

	private static int pedirCantidad(String string) {
		System.out.println("¿Cuántos "+string+" quieres añadir?");
		int cant = entrada.nextInt();
		entrada.nextLine();
		return cant;
	}

	private static void mostrarAlumnosModulos(Alumno[] alumnos) {
		for (int i = 0; i < alumnos.length; i++) {
			System.out.println(alumnos[i].toString());
		}
	}

	private static Alumno[] crearAlumnos(int cantidad, Modulo[] modulos) {
		Alumno [] alumnos = new Alumno[cantidad];
		String dni;
		String nombre;
		String apellido;
		String fecha;
		int sexoI;
		Sexo sexo = null;
		String repetidorS;
		boolean repetidor;
		int[] modulos_alumnoI;
		Modulo[] modulos_alumno = null;
		for (int i = 0; i < alumnos.length; i++) {
			System.out.println("Alumno "+(i+1));
			System.out.print("DNI: ");
			dni = entrada.next();
			entrada.nextLine(); 
			System.out.print("Nombre: ");
			nombre = entrada.next();
			entrada.nextLine(); 
			System.out.print("Apellido: ");
			apellido = entrada.next();
			entrada.nextLine(); 
			System.out.print("Fecha de nacimiento: ");
			fecha = entrada.next();
			entrada.nextLine(); 
			do {
				System.out.println("Sexo \n1-Hombre\n2-Mujer");
				sexoI = entrada.nextInt();
				entrada.nextLine();
				switch (sexoI) {
					case 1:
						sexo = Sexo.HOMBRE;
						break;
					case 2:
						sexo = Sexo.MUJER;
						break;
					default:
						sexoI = 3;
				}
			} while (sexoI == 3);
			System.out.print("¿Es repetidor? ");
			repetidorS = entrada.next();
			entrada.nextLine();
			repetidorS.toLowerCase();
			repetidor=false;
			if (repetidorS == "si" || repetidorS == "sí") {
				repetidor=true;
			}
			int cant = pedirCantidad("módulos");
			modulos_alumnoI = new int[cant];
			modulos_alumno = new Modulo[cant];
			for (int j = 0; j < cant; j++) {
				do {
					System.out.println("Modulos:");
					for (int k = 0; k < modulos.length; k++) {
						System.out.println((k+1)+"- "+modulos[k].getNombre());
					}
					System.out.println("¿Cuál quieres añadir?");
					modulos_alumnoI[j] = entrada.nextInt();
					entrada.nextLine();
					if (modulos_alumnoI[j] > 0 && modulos_alumnoI[j] <= modulos.length) {
						modulos_alumno[j] = modulos[modulos_alumnoI[j]-1];
					} else {
						modulos_alumnoI[j] = 0;
						System.out.println("Introduce un número válido");
					}
				} while (modulos_alumnoI[j] == 0);
			}
			alumnos[i] = new Alumno(dni, nombre, apellido, fecha, sexo, repetidor, modulos_alumno);
		}
		return alumnos;
	}

	private static Modulo[] crearModulos(int cantidad, Profesor[] profesores) {
		Modulo [] modulos = new Modulo[cantidad];
		String nombre;
		int horas;
		int profeI;
		Profesor profe = null;
		String convalidaS;
		boolean convalida;
		for (int i = 0; i < modulos.length; i++) {
			System.out.println("Modulo "+(i+1));
			System.out.print("Nombre: ");
			nombre = entrada.next();
			entrada.nextLine(); 
			System.out.print("Horas: ");
			horas = entrada.nextInt();
			entrada.nextLine(); 
			do {
				System.out.println("Profesores:");
				for (int j = 0; j < profesores.length; j++) {
					System.out.println((j+1)+"- "+profesores[j].getNombre());
				}
				profeI = entrada.nextInt();
				entrada.nextLine();
				if (profeI > 0 && profeI <= profesores.length) {
					profe = profesores[profeI-1];
				} else {
					profeI = 0;
					System.out.println("Introduce un número válido");
				}
			} while (profeI == 0);
			System.out.print("¿Es convalidable? ");
			convalidaS = entrada.next();
			entrada.nextLine();
			convalidaS.toLowerCase();
			convalida=false;
			if (convalidaS == "si" || convalidaS == "sí") {
				convalida=true;
			}
			modulos[i] = new Modulo(nombre, horas, profe, convalida);
		}
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
		String dni;
		String nombre;
		String apellido;
		int salario;
		String salesianoS;
		boolean salesiano;
		int turnoI;
		Turno turno = null;
		for (int i = 0; i < directivos.length; i++) {
			System.out.println("Director "+(i+1));
			System.out.print("DNI: ");
			dni = entrada.next();
			entrada.nextLine(); 
			System.out.print("Nombre: ");
			nombre = entrada.next();
			entrada.nextLine(); 
			System.out.print("Apellido: ");
			apellido = entrada.next();
			entrada.nextLine(); 
			System.out.print("Salario: ");
			salario = entrada.nextInt();
			entrada.nextLine(); 
			System.out.print("¿Es salesiano? ");
			salesianoS = entrada.next();
			entrada.nextLine(); 
			salesianoS.toLowerCase();
			salesiano=false;
			if (salesianoS == "si" || salesianoS == "sí") {
				salesiano=true;
			}
			do {
				System.out.println("Turno \n1-Mañana\n2-Tarde");
				turnoI = entrada.nextInt();
				entrada.nextLine();
				switch (turnoI) {
					case 1:
						turno = Turno.MAÑANA;
						break;
					case 2:
						turno = Turno.TARDE;
						break;
					default:
						turnoI = 3;
						System.out.println("Introduce un número válido");
				}
			} while (turnoI == 3);
			directivos[i] = new Directivo(dni, nombre, apellido, salario, salesiano, turno);
		}
		return directivos;
	}

	private static Administracion[] crearAdmins(int cantidad) {
		Administracion [] administradores = new Administracion[cantidad];
		String dni;
		String nombre;
		String apellido;
		int salario;
		String estudios;
		int antiguedad;
		for (int i = 0; i < administradores.length; i++) {
			System.out.println("Administrador "+(i+1));
			System.out.print("DNI: ");
			dni = entrada.next();
			entrada.nextLine(); 
			System.out.print("Nombre: ");
			nombre = entrada.next();
			entrada.nextLine(); 
			System.out.print("Apellido: ");
			apellido = entrada.next();
			entrada.nextLine(); 
			System.out.print("Salario: ");
			salario = entrada.nextInt();
			entrada.nextLine(); 
			System.out.print("Estudios: ");
			estudios = entrada.next();
			entrada.nextLine(); 
			System.out.print("Antiguedad: ");
			antiguedad = entrada.nextInt();
			entrada.nextLine();
			administradores[i] = new Administracion(dni, nombre, apellido, salario, estudios, antiguedad);
		}
		return administradores;
	}

	private static Profesor[] crearProfes(int cantidad) {
		Profesor [] profesores = new Profesor[cantidad];
		String dni;
		String nombre;
		String apellido;
		int salario;
		int asignaturas;
		String tutorS;
		boolean tutor;
		for (int i = 0; i < profesores.length; i++) {
			System.out.println("Profesor "+(i+1));
			System.out.print("DNI: ");
			dni = entrada.next();
			entrada.nextLine(); 
			System.out.print("Nombre: ");
			nombre = entrada.next();
			entrada.nextLine(); 
			System.out.print("Apellido: ");
			apellido = entrada.next();
			entrada.nextLine(); 
			System.out.print("Salario: ");
			salario = entrada.nextInt();
			entrada.nextLine(); 
			System.out.print("Asignaturas: ");
			asignaturas = entrada.nextInt();
			entrada.nextLine(); 
			System.out.print("¿Es tutor? ");
			tutorS = entrada.next();
			entrada.nextLine();
			tutorS.toLowerCase();
			tutor=false;
			if (tutorS == "si" || tutorS == "sí") {
				tutor=true;
			}
			profesores[i] = new Profesor(dni, nombre, apellido, salario, asignaturas, tutor);
		}
		return profesores;
	}

}
