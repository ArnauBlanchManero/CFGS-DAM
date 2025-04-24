import java.util.Scanner;

public class menuFiguras {
	static Scanner entrada = new Scanner(System.in);
	
	public static void main(String[] args) {
		System.out.println("Con este probrama podrás dibujar una gran variedad de formas.");
		String opcion;
		opcion = menu();
		if (opcion != null) {
			char opcion1 = opcion.charAt(0);
			char opcion2 = opcion.charAt(1);
			dibujar(opcion1, opcion2);
		}
		entrada.close();
	}

	private static void dibujar(char opcion1, char opcion2) {
		switch (opcion1) {
			case '1': {
				if (opcion2 == '1') {
					dibuja_rectangulo_compacto();
				}
				if (opcion2 == '2') {
					dibuja_rectangulo_vacio();
				}
				break;
			}
			case '2': {
				if (opcion2 == '1') {
					dibuja_triangulo_rectangulo_compacto();
				}
				if (opcion2 == '2') {
					dibuja_triangulo_rectangulo_vacio();
				}
				break;
			}
			case '3': {
				if (opcion2 == '1') {
					dibuja_triangulo_equilatero_compacto();
				}
				if (opcion2 == '2') {
					dibuja_triangulo_equilatero_vacio();
				}
				break;
			}
			default:
				System.out.println("Ha ocurrido un error.");
		}
	}

	private static void dibuja_triangulo_equilatero_vacio() {
		System.out.print("¿Qué altura quieres que tenga tu triángulo equilátero? ");
		int altura = entrada.nextInt();
		entrada.nextLine();
		System.out.println('\n'+"Tu triángulo sin relleno:");
		for (int i = 0; i < altura; i++) {
			for (int j = 0; j < altura-i; j++) {
				System.out.print(" ");
			}
			for (int k = 0; k <= i*2; k++) {
				if (i==0 || i == altura-1 || k == 0 || k == i*2) {
					System.out.print("*");
				} else {
					System.out.print(" ");
				}
			}
			System.out.println("");
		}
	}

	private static void dibuja_triangulo_equilatero_compacto() {
		System.out.print("¿Qué altura quieres que tenga tu triángulo equilátero? ");
		int altura = entrada.nextInt();
		entrada.nextLine();
		System.out.println('\n'+"Tu triángulo con relleno:");
		for (int i = 0; i < altura; i++) {
			for (int j = 0; j < altura-i; j++) {
				System.out.print(" ");
			}
			for (int k = 0; k <= i*2; k++) {
				System.out.print("*");
			}
			System.out.println("");
		}
	}

	private static void dibuja_triangulo_rectangulo_vacio() {
		System.out.print("¿Qué altura quieres que tenga tu triángulo rectángulo? ");
		int altura = entrada.nextInt();
		entrada.nextLine();
		System.out.println('\n'+"Tu triángulo sin relleno:");
		for (int i = 0; i <= altura; i++) {
			for (int j = 0; j < i; j++) {
				if (i==0 || i == altura || j == 0 || j == i-1) {
					System.out.print("* ");
				} else {
					System.out.print("  ");
				}
			}
			System.out.println("");
		}
	}

	private static void dibuja_triangulo_rectangulo_compacto() {
		System.out.print("¿Qué altura quieres que tenga tu triángulo rectángulo? ");
		int altura = entrada.nextInt();
		entrada.nextLine();
		System.out.println('\n'+"Tu triángulo con relleno:");
		for (int i = 0; i <= altura; i++) {
			for (int j = 0; j < i; j++) {
				System.out.print("* ");
			}
			System.out.println("");
		}		
	}

	private static void dibuja_rectangulo_vacio() {
		System.out.print("¿Qué altura quieres que tenga el rectángulo? ");
		int altura = entrada.nextInt();
		System.out.print("¿Qué base quieres que tenga el rectángulo? ");
		int base = entrada.nextInt();
		entrada.nextLine();
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

	private static void dibuja_rectangulo_compacto() {
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
	}

	private static String menu() {
		int opcion1 = 0, opcion2 = 0;
		boolean repetir = true;
		do {
			System.out.println('\n'+"¿Qué desea dibujar?");
			System.out.println("1. Rectángulo");
			System.out.println("2. Triángulo rectángulo");
			System.out.println("3. Triángulo equilátero");
			System.out.println("(Cualquier otro número para salir)"+'\n');
			System.out.print("Opción: ");
			if (entrada.hasNextInt()) {
				opcion1 = entrada.nextInt();
				entrada.nextLine();
				if(opcion1 == 1 || opcion1 == 2 || opcion1 == 3) {
					do {
						System.out.println('\n'+"¿Cómo quieres que se vea?");
						System.out.println("1. Compacto");
						System.out.println("2. Vacío"+'\n');
						System.out.print("Opción: ");
						if (entrada.hasNextInt()) {
							opcion2 = entrada.nextInt();
						} else {
							opcion2 = 0;
							System.out.println("Escribe 1 o 2");
						}
						entrada.nextLine();
					} while (opcion2 < 1 || opcion2 > 2);
					return ""+ opcion1 + opcion2;
				} else {
					repetir = false;
				}
			} else {
				entrada.nextLine();
				System.out.println("Introduce un número entre 1 y 3");
				repetir = true;
			}
		} while (repetir);
		return null;
	}
}