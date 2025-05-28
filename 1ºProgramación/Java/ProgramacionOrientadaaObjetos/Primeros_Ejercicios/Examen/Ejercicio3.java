import java.util.Scanner;

public class Ejercicio3 {
	static Scanner entrada = new Scanner(System.in);
	
	public static void main(String[] args) {
		int[] rango = determinar_rango();
		compribar_primo(rango);
		
	}

	private static void compribar_primo(int[] rango) {
		boolean esPrimo = true;
		//System.out.println("de " + rango[0] + " a " + rango[1]);
		for (int i = rango[0]; i <= rango[1]; i++) {
			esPrimo = true;
			for (int j = 2; j < i-1; j++) {
				if(i%j==0) {
					esPrimo=false;
				}
			}
			if (esPrimo) {
				System.out.println("El número "+ i + " es primo.");
			}
		}
	}

	private static int[] determinar_rango() {
		int[] min_max = {-1,-1};
		System.out.print("Escribe el número mínimo: ");
		min_max[0] = entrada.nextInt();
		entrada.nextLine();
		while (min_max[1]<min_max[0]) {
			System.out.print("Escribe el número máximo: ");
			min_max[1] = entrada.nextInt();
			entrada.nextLine();
		}
		if (min_max[0]<0 || min_max[1]<0) {
			System.out.println("ERROR");
			int[] error = {0,0};
			return error;
		}
		return min_max;
	}

}
