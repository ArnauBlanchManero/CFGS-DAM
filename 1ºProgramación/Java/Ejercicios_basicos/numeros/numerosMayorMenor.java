import java.util.Scanner;

public class numerosMayorMenor {
	static Scanner entrada = new Scanner(System.in);
	public static void main(String[] args) {
		// Leer una cantidad y luego introducir n números. Imprimir el mayor y el menor y las veces uqe aparece cada uno.
		
		System.out.print("¿Cuántos números quieres añadir? ");
		int cantidad = entrada.nextInt();
		entrada.nextLine();
		
		int[] numeros=new int[cantidad];
		numeros=pedirNumeros(cantidad);
		
		int menor = numeros[0];
		menor = encontrarMenor(numeros,cantidad);
		
		int mayor = numeros[0];
		mayor = encontrarMayor(numeros,cantidad);
		
		int cantidadMenor;
		cantidadMenor = contar(menor, numeros, cantidad);
		
		int cantidadMayor;
		cantidadMayor = contar(mayor, numeros, cantidad);
		
		System.out.println("El número más pequeño es el "+menor+" y se repite "+cantidadMenor+" veces.");
		System.out.println("El número más grande es el "+mayor+" y se repite "+cantidadMayor+" veces.");
		
		entrada.close();
	}
	
	private static int contar(int repetido, int[] numeros, int max) {
		int cantidad=0;
		for(int i=0; i<max;i++) {
			if(numeros[i]==repetido)
				cantidad++;
		}
		return cantidad;
	}

	private static int encontrarMayor(int[] numeros, int cantidad) {
		int max = numeros[0];
		for(int i=1; i<cantidad;i++) {
			if(numeros[i]>max) {
				max=numeros[i];
			}
		}
		return max;
	}

	private static int encontrarMenor(int[] numeros, int cantidad) {
		int min = numeros[0];
		for(int i=1; i<cantidad;i++) {
			if(numeros[i]<min) {
				min=numeros[i];
			}
		}
		return min;
	}

	private static int[] pedirNumeros(int cantidad) {
		int[] numeros=new int[cantidad];
		for(int i=0; i<cantidad; i++) {
			System.out.print("Número " +(i+1)+": ");
			numeros[i]=entrada.nextInt();
			entrada.nextLine();
		}
		return numeros;
	}
}