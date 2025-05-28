import java.util.Scanner;

public class Ejercicio2 {
	static Scanner entrada = new Scanner(System.in);
	
	public static void main(String[] args) {
		int altura = pedir_altura();
		imprime_figura(altura);

	}
	private static void imprime_figura(int altura) {
		for (int i = 0; i < altura; i++) {
			for (int j = altura; j > i+1; j--) {
				System.out.print("*");
			}
			for (int k = 0; k < i*2; k++) {
				System.out.print(" ");
			}
			for (int l = altura; l > i+1; l--) {
				System.out.print("*");
			}
			System.out.println("");
		}
		
	}
	private static int pedir_altura() {
		int num = 0;
		while (num<3) {
			System.out.print("Escribe la altura del triángulo: ");
			num = entrada.nextInt();
			entrada.nextLine();
		}
		return num;
	}

}
