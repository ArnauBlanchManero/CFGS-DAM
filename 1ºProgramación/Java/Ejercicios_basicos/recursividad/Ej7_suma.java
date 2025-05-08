import java.util.Scanner;

public class Ej7_suma {
	static Scanner entrada = new Scanner(System.in);

	public static void main(String[] args) {
		System.out.print("Escribe un número natural: ");
		int numero = entrada.nextInt();
		entrada.nextLine();
		System.out.println("La suma de 0 hasta " + numero + " es: ");
		System.out.print("0");
		int suma = sumar(numero, 0);
		System.out.println(" = " + suma);

	}

	private static int sumar(int max, int contador) {
		if (max==contador) return 0;
		contador++;
		System.out.print(" + "+contador);
		return contador + sumar(max, contador);
	}


}
