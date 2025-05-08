import java.util.Scanner;

public class Ej4_binario {
	static Scanner entrada = new Scanner(System.in);

	public static void main(String[] args) {
		System.out.print("Escribe un número binario: ");
		long numBinario = entrada.nextLong();
		entrada.nextLine();
		boolean binario = comprobarBinario(numBinario);
		if (binario) {
			System.out.println("El número " + numBinario + " es bianrio.");
		} else {
			System.out.println("El número " + numBinario + " no es binario.");
		}
	}

	private static boolean comprobarBinario(long numBinario) {
		if(numBinario<=0) return true;
		boolean ret = false;
		if(numBinario % 10 == 0 || numBinario % 10 == 1) ret = true;
		return ret && comprobarBinario(numBinario/10);
	}

}
