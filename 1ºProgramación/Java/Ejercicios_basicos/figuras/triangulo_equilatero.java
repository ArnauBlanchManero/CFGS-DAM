import java.util.Scanner;

public class triangulo_equilatero {
	static Scanner entrada = new Scanner(System.in);

	public static void main(String[] args) {
		/*	Crea un programa en JAVA que dibuje un triángulo equilátero formado por asteriscos(*). Se debe
			pedir la altura del triángulo por teclado. Además, añade código adicional para que dibuje dicho
			rectángulo sin relleno
		 */
		System.out.print("¿Qué altura quieres que tenga tu triángulo equilátero? ");
		int altura = entrada.nextInt();
		entrada.nextLine();
		System.out.println('\n'+"Tu triángulo con relleno:");
		for (int i = 0; i < altura; i++) {
			for (int j = 0; j < altura-i; j++) {
				System.out.print(" ");
			}
			for (int k = 0; k < i; k++) {
				System.out.print("* ");
			}
			System.out.println("");
		}
		System.out.println('\n'+"Tu triángulo sin relleno:");
		for (int i = 0; i < altura; i++) {
			for (int j = 0; j < altura-i; j++) {
				System.out.print(" ");
			}
			for (int k = 0; k < i; k++) {
				if (i==0 || i == altura-1 || k == 0 || k == i-1) {
					System.out.print("* ");
				} else {
					System.out.print("  ");
				}
			}
			System.out.println("");
		}
		entrada.close();
	}

}