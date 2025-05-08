import java.util.Scanner;

public class Ej3_invertir {
	static Scanner entrada = new Scanner(System.in);

	public static void main(String[] args) {
		System.out.print("Escribe un número: ");
		int numDerecho = entrada.nextInt();
		entrada.nextLine();
		int longitud = cuentaDigitos(numDerecho);
		int numReves = dar_vuelta(numDerecho, longitud);
		System.out.println("El número " + numDerecho + " del revés es " + numReves);

	}

	private static int dar_vuelta(int numDerecho, int longitud) {
		if(numDerecho<=0) {
			return 0;
		}
		int mod = numDerecho % 10;
		int agrandar = elevar(10, --longitud);
		return mod*agrandar + dar_vuelta(numDerecho/10, longitud);
	}

	private static int cuentaDigitos(int num) {
		if (num<10)
			return 1;
		return 1 + cuentaDigitos(num/10);
	}
	
	private static int elevar(int base, int exponente) {
		if (exponente<1) {
			return 1;
		}
		return base * elevar(base, exponente-1);
	}
	
}
