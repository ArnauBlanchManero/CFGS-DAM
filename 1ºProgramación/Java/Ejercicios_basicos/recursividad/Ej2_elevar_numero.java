import java.util.Scanner;

public class Ej2_elevar_numero {
	static Scanner entrada = new Scanner(System.in);

	public static void main(String[] args) {
		System.out.print("Escribe la base: ");
		int base = entrada.nextInt();
		entrada.nextLine();
		System.out.print("Escribe el exponente: ");
		int exponente = entrada.nextInt();
		entrada.nextLine();
		int solucion = elevar(base, exponente);
		System.out.println("El número " + base + " elevado a " + exponente + " es " + solucion);

	}

	private static int elevar(int base, int exponente) {
		if (exponente<1) return 1;
		return base * elevar(base, exponente-1);
	}

}
