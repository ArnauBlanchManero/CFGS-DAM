import java.util.Scanner;

public class Ejercicio1 {
	static Scanner entrada = new Scanner(System.in);

	public static void main(String[] args) {
		int opcion_usuario;
		do {
			opcion_usuario = menu();
		} while (opcion_usuario != 6);
	}

	private static int menu() {
		int opcion;
		System.out.println("Elige una de las siguientes opciones escribiendo su número:");
		System.out.println("1. Sumar");
		System.out.println("2. Restar");
		System.out.println("3. Multiplicar");
		System.out.println("4. Dividir");
		System.out.println("5. Calcular porcentaje");
		System.out.println("6. Salir");
		System.out.print("Opcion: ");
		opcion = entrada.nextInt();
		entrada.nextLine();
		if (opcion >= 1 && opcion <= 6) {
			switch (opcion) {
				case 1:
					suma();
					break;
				case 2:
					resta();
					break;
				case 3:
					mult();
					break;
				case 4:
					dividir();
					break;
				case 5:
					porcentaje();
					break;
				default:
					break;
			}
		} else {
			System.out.println("ERROR, introduzca otro número.");
		}
		return opcion;
	}

	private static void suma() {
		int[] numeros = pedir_numeros();
		int suma = 0;
		System.out.print("La suma de ");
		for (int i = 0; i < numeros.length; i++) {
			if (i == numeros.length-1) {
				System.out.print(numeros[i]);
			} else {
				System.out.print(numeros[i] + " + ");
			}
			suma += numeros[i];
		}
		System.out.println(" es " + suma);
	}

	private static void resta() {
		int[] numeros = pedir_numeros();
		int resta = numeros[0];
		System.out.print("La resta de " + numeros[0] + " - ");
		for (int i = 1; i < numeros.length; i++) {
			if (i == numeros.length-1) {
				System.out.print(numeros[i]);
			} else {
				System.out.print(numeros[i] + " - ");
			}
			resta -= numeros[i];
		}
		System.out.println(" es " + resta);		
	}

	private static void mult() {
		int[] numeros = pedir_numeros();
		int multi = 1;
		System.out.print("La multiplicación de ");
		for (int i = 0; i < numeros.length; i++) {
			if (i == numeros.length-1) {
				System.out.print(numeros[i]);
			} else {
				System.out.print(numeros[i] + " · ");
			}
			multi *= numeros[i];
		}
		System.out.println(" es " + multi);		
	}

	private static void dividir() {
		int[] numeros = pedir_numeros();
		int div = numeros[0];
		System.out.print("La división de " + numeros[0]+ " / ");
		for (int i = 1; i < numeros.length; i++) {
			if (i == numeros.length-1) {
				System.out.print(numeros[i]);
			} else {
				System.out.print(numeros[i] + " / ");
			}
			div /= numeros[i];
		}
		System.out.println(" es " + div);		
	}
	
	private static void porcentaje() {
		int[] numeros = pedir_numeros();
		int porc = numeros[numeros.length-1];
		System.out.print("El porcentaje de ");
		for (int i = numeros.length-1; i >= 0; i--) {
			if (i == 0) {
				System.out.print(numeros[numeros.length-1-i]);
			} else {
				System.out.print(numeros[numeros.length-1-i] + " % ");
				porc = porc * numeros[i-1] / 100;
			}
		}
		System.out.println(" es " + porc);		
	}

	private static int[] pedir_numeros() {
		int cuantos_numeros=0;
		do {
			System.out.print("Introduce cuántos números quieres que tenga tu opceración (mínimo 2): ");
			cuantos_numeros = entrada.nextInt();
			entrada.nextLine();
		}while (cuantos_numeros<=1);
		
		// Aquí tengo que declarar un array de la longitud que me ha dicho el usuario pero no me acuerdo de la sintaxis
		int[] que_numeros = new int[cuantos_numeros];
		/*
		if (cuantos_numeros != 3) {
			System.out.println("Lo siento pero sólo funciona con tres números");
			cuantos_numeros = 3;
		}
		int[] que_numeros = {0, 0, 0};
		*/
		for (int i = 0; i < cuantos_numeros; i++) {
			System.out.print("Introduce el número que quieras: ");
			que_numeros[i] = entrada.nextInt();
			entrada.nextLine();
		}
		return que_numeros;
	}
}
