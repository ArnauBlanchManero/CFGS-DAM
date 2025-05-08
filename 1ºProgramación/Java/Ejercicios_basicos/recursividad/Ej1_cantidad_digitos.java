import java.util.Scanner;

public class Ej1_cantidad_digitos {
	static Scanner entrada = new Scanner(System.in);

	public static void main(String[] args) {
		System.out.print("Escribe un número: ");
		int numLargo = entrada.nextInt();
		entrada.nextLine();
		int digitos = cuentaDigitos(numLargo);
		System.out.println("El número " + numLargo + " tiene " + digitos + " digitos.");
	}

	private static int cuentaDigitos(int num) {
		if (num<10) return 1;
		return 1 + cuentaDigitos(num/10);
	}

}
