import java.util.Scanner;

public class rectangulo {
	static Scanner entrada = new Scanner(System.in);

	public static void main(String[] args) {
		/*	Crear un programa en JAVA que dibuje un rectángulo formado por asteriscos(*). Se deben pedir JAVA
			base y altura por teclado. Además, añade código adicional para que dibuje dicho rectángulo sin
			relleno
		 */
		System.out.print("¿Qué altura quieres que tenga el rectángulo? ");
		int altura = entrada.nextInt();
		System.out.print("¿Qué base quieres que tenga el rectángulo? ");
		int base = entrada.nextInt();
		entrada.nextLine();
		System.out.println('\n'+"Tu rectángulo con relleno:");
		for (int i = 0; i < altura; i++) {
			for (int j = 0; j < base; j++) {
				System.out.print("* ");
			}
			System.out.println("");
		}
		System.out.println('\n'+"Tu rectángulo sin relleno:");
		for (int i = 0; i < altura; i++) {
			for (int j = 0; j < base; j++) {
				if (i==0 || i == altura-1 || j == 0 || j == base-1) {
					System.out.print("* ");
				} else {
					System.out.print("  ");
				}
			}
			System.out.println("");
			entrada.close();
		}
	}

}