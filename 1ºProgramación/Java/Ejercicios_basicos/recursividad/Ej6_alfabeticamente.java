import java.util.Scanner;

public class Ej6_alfabeticamente {
	static Scanner entrada = new Scanner(System.in);

	public static void main(String[] args) {
		System.out.print("Escribe un una palabra: ");
		String palabra = entrada.next();
		entrada.nextLine();
		palabra = palabra.toLowerCase();
		boolean ordenado = alfabeticamente(palabra, palabra.length());
		if (ordenado)
			System.out.println("La palabra " + palabra + " está ordenada alfabeticamente.");
		else
			System.out.println("La palabra " + palabra + " no está ordenada alfabeticamente.");
	}

	private static boolean alfabeticamente(String palabra, int longitud) {
		if (longitud <= 1) return true;
		if(palabra.charAt(longitud-1)<=palabra.charAt(longitud-2)) return false;
		return true && alfabeticamente(palabra, longitud-1);
	}

}
