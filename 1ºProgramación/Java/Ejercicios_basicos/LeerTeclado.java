import java.util.Scanner;

public class LeerTeclado {

	public static void main(String[] args) {
		String nombre; // Variable de tipo String
		@SuppressWarnings("unused") // Para no tener en cuenta el warning
		String segundoNombre;
		String apellido;
		int edad;
		
		Scanner entrada= new Scanner(System.in); // Declaramos un objeto, empezamos con el nombre (instancia) de la clase y le damos un nombre. new llama a un constructor de la clase

		System.out.print("Introduzca su nombre: "); // Pedimos al usuario el nombre
		nombre=entrada.next();
		segundoNombre=entrada.nextLine();
		
		System.out.print("Introduzca su edad: ");
		edad= entrada.nextInt();
		entrada.nextLine(); // Para limpiar el buffer, cuando introducimos un número se queda el \n
		
		System.out.print("Introduzca su apellido: ");
		apellido=entrada.nextLine();

		System.out.println("Hola " + nombre + " " + apellido);
		System.out.println("Tienes " + edad + " años");
		entrada.close();
	}
}