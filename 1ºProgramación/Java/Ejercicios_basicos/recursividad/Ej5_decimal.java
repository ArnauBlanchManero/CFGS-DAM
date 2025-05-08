import java.util.Scanner;

public class Ej5_decimal {
	static Scanner entrada = new Scanner(System.in);

	public static void main(String[] args) {
		System.out.print("Escribe un número decimal: ");
		int numDecimal = entrada.nextInt();
		entrada.nextLine();
		String numBinario = pasarAbinario(numDecimal);
		System.out.println("El número "+ numDecimal+ " en binario es " + numBinario);
	}

	private static String pasarAbinario(int numDecimal) {
		if (numDecimal == 0 || numDecimal == 1) return "" + numDecimal;
		return pasarAbinario(numDecimal/2) + numDecimal%2;
	}
}
