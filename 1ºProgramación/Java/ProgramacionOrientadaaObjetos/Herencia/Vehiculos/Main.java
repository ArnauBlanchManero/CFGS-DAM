package Vehiculos;
import java.util.Scanner;

public class Main {
	public static Scanner entrada = new Scanner(System.in);
	public static void main(String[] args) {
		boolean repetir = true;
		System.out.println("¡Bienvenido!\nCon este sistema podrás añadir tus dos coches y ver otros vehículos que tenemos.");

		Coche [] coches = new Coche[2];
		Barco barco1 = new Barco("Nike", "azul", "ABC123", 80, 1992, 5, 3, Tipo.VELA);
		Barco barco2 = new Barco("Adidas", "blanco", "ZYX987", 30, 2019, 9, 4, Tipo.PESCA);
		Avion avion1 = new Avion("Lenovo", "amarillo", "JKL567", 200, 2005, false);
		Avion avion2 = new Avion("HP", "negro", "TRI432", 4500, 2022, (byte) 2, 450, true);
		
		System.out.println("\nPrimer coche:");
		coches[0] = crearCoche();
		System.out.println("\nSegundo coche:");
		coches[1] = crearCoche();
		
		System.out.println("\nAqí están todos los vehículos:");
		mostrarTodo(coches[0], coches[1], barco1, barco2, avion1, avion2);
		
		System.out.println("\nUna vez ya tenemos todos los vehículos tienes estas opciones para hacer:");
		do {
			repetir = menu(coches[0], coches[1], barco1, barco2, avion1, avion2);
		} while(repetir);
	}

	private static boolean menu(Coche coche1, Coche coche2, Barco barco1, Barco barco2, Avion avion1, Avion avion2) {
		String respuesta;
		System.out.println("1- Contar vehículos.");
		System.out.println("2- Sacar la media de kilómetros.");
		System.out.println("3- Cambiar un dato de un coche.");
		System.out.println("4- Salir.");
		respuesta = entrada.next();
		entrada.nextLine();
		switch (respuesta) {
			case "1":
				System.out.println("¿Qué quieres contar exactamente?");
				System.out.println("1- Cuántos vehículos hay en total");
				System.out.println("2- Cuántos son eléctricos");
				System.out.println("3- Cuántos son de combate");
				respuesta = entrada.next();
				entrada.nextLine();
				switch (respuesta) {
				case "1":
					System.out.println("Hay 6 vehículos en total.\n");
					break;
				case "2":
					contarElectricos(coche1, coche2);
					break;
				case "3":
					contarCombate(avion1, avion2);
					break;
				default:
					System.out.println("No es una opcion válida\n");
				}
				break;
			case "2":
				calcularMediaKm(coche1, coche2, barco1, barco2, avion1, avion2);
				break;
			case "3":
				System.out.println("¿De qué coche quieres cambiar un dato?");
				System.out.println("1- "+coche1.toString());
				System.out.println("2- "+coche2.toString());
				respuesta = entrada.next();
				entrada.nextLine();
				if (respuesta.equals("1")) {
					coche1 = cambiarDato(coche1);
				} else if (respuesta.equals("2")) {
					coche2 = cambiarDato(coche2);
				} else {
					System.out.println("No es una opción válida\n");
				}
				
				break;
			case "4":
				return false;
			default:
				System.out.println("No has seleccionado una opcion válida.");
				break;
		}
		return true;
	}

	private static void contarCombate(Avion avion1, Avion avion2) {
		int total = 0;
		if (avion1.isCombate()) {
			total++;
		}
		if (avion2.isCombate()) {
			total++;
		}
		System.out.println("Hay "+total+" vehículos de combate\n");
	}

	private static void contarElectricos(Coche coche1, Coche coche2) {
		int total = 0;
		if (coche1.isElectrico()) {
			total++;
		}
		if (coche2.isElectrico()) {
			total++;
		}
		System.out.println("Hay "+total+" vehículos eléctricos\n");
	}

	private static Coche cambiarDato(Coche coche) {
		String marca, color, num, electricoS, antiguoS;
		int km, anio;
		boolean electrico = coche.isElectrico(), antiguo = coche.isAntiguo();
		System.out.println("¿Qué dato queieres cambiar?");
		System.out.println("1- Marca");
		System.out.println("2- Color");
		System.out.println("3- Número bastidor");
		System.out.println("4- Kilómetros");
		System.out.println("5- Año de fabricacion");
		System.out.println("6- Electrico");
		System.out.println("7- Antiguo");
		System.out.println("8- Nada");
		String respuesta = entrada.next();
		entrada.nextLine();
		switch (respuesta) {
		case "1":
			System.out.println("Inserte nueva marca");
			marca = entrada.nextLine();
			coche.setMarca(marca);
			break;
		case "2":
			System.out.println("Inserte nuevo color");
			color = entrada.nextLine();
			coche.setColor(color);
			break;
		case "3":
			System.out.println("Inserte nuevo número de bastidor");
			num = entrada.nextLine();
			coche.setNumero_bastidor(num);
			break;
		case "4":
			System.out.println("Inserte nuevos kilómetros");
			km = entrada.nextInt();
			entrada.nextLine();
			coche.setKilometros(km);
			break;
		case "5":
			System.out.println("Inserte nuevo año de fabricación");
			anio = entrada.nextInt();
			entrada.nextLine();
			coche.setAñofabricacion(anio);
			break;
		case "6":
			System.out.println("¿Es eléctrico?");
			electricoS = entrada.next();
			entrada.nextLine();
			electricoS.toLowerCase();
			if (electricoS.equals("si")||electricoS.equals("sí")) {
				electrico = true;
			}
			coche.setElectrico(electrico);
			break;
		case "7":
			System.out.println("¿Es antiguo?");
			antiguoS = entrada.next();
			entrada.nextLine();
			antiguoS.toLowerCase();
			if (antiguoS.equals("si")||antiguoS.equals("sí")) {
				antiguo = true;
			}
			coche.setAntiguo(antiguo);
			break;
		default:
			System.out.println("No es una opcion válida");
			break;
		}
		return coche;
	}

	private static void calcularMediaKm(Coche coche1, Coche coche2, Barco barco1, Barco barco2, Avion avion1,
			Avion avion2) {
		int km = 0;
		km += coche1.getKilometros();
		km += coche2.getKilometros();
		km += barco1.getKilometros();
		km += barco2.getKilometros();
		km += avion1.getKilometros();
		km += avion2.getKilometros();
		km /= 6;
		System.out.println("La media de kilómetros entre todos los coches es "+ km+"km\n");
		
	}

	private static void mostrarTodo(Coche coche1, Coche coche2, Barco barco1, Barco barco2, Avion avion1, Avion avion2) {
		System.out.println(coche1.toString());
		System.out.println(coche2.toString());
		System.out.println(barco1.toString());
		System.out.println(barco2.toString());
		System.out.println(avion1.toString());
		System.out.println(avion2.toString());
	}

	private static Coche crearCoche() {
		Coche coche_temp = null;
		String marca, color, num, electricoS;
		int km, anio;
		boolean electrico = false;
		System.out.println("¿Qué marca es tu coche?");
		marca = entrada.nextLine();
		System.out.println("¿De qué color es tu coche?");
		color = entrada.nextLine();
		System.out.println("¿Qué número de bastidor tiene tu coche?");
		num = entrada.nextLine();
		System.out.println("¿Cuántos kilómetros tiene tu coche?");
		km = entrada.nextInt();
		entrada.nextLine();
		System.out.println("¿De qué año es tu coche?");
		anio = entrada.nextInt();
		entrada.nextLine();
		System.out.println("¿Es tu coche electrico?");
		electricoS = entrada.next();
		entrada.nextLine();
		electricoS.toLowerCase();
		if (electricoS.equals("si")||electricoS.equals("sí")) {
			electrico = true;
		}
		coche_temp = new Coche(marca, color, num, km, anio, electrico);
		return coche_temp;
	}

}
