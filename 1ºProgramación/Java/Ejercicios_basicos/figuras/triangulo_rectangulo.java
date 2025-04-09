import java.util.Scanner;

public class triangulo_rectangulo {
	static Scanner entrada = new Scanner(System.in);

	public static void main(String[] args) {
		/*	Crea un programa en JAVA que dibuje un triángulo rectángulo formado por asteriscos(*). Se debe
			pedir la altura del triángulo por teclado. Además, añade código adicional para que dibuje dicho
			triángulo sin relleno
		 */
		System.out.print("¿Qué altura quieres que tenga tu triángulo rectángulo? ");
		int altura = entrada.nextInt();
		entrada.nextLine();
		System.out.println('\n'+"Tu triángulo con relleno:");
		for (int i = 0; i < altura; i++) {
			for (int j = 0; j < i; j++) {
				System.out.print("* ");
			}
			System.out.println("");
		}
		System.out.println('\n'+"Tu triángulo sin relleno:");
		for (int i = 0; i < altura; i++) {
			for (int j = 0; j < i; j++) {
				if (i==0 || i == altura-1 || j == 0 || j == i-1) {
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