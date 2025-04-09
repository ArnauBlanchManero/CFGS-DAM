import java.util.Scanner;

public class añadirAlumnos {

	public static void main(String[] args) {
		int[] alumnos= new int[100];
		String[] nombre= new String[100]; // Variable de tipo array de String
		String[] segundoNombre= new String[100];
		String[] apellido= new String[100];
		int[] edad= new int[100];
		
		Scanner entrada= new Scanner(System.in); // Declaramos un objeto, empezamos con el nombre (instancia) de la clase y le damos un nombre. new llama a un constructor de la clase
		
		String respuesta;
		int i = 0;
		boolean seguir;
		do {
			seguir = false;
			alumnos[i]=i+1;
			System.out.print("Introduzca su nombre: "); // Pedimos al usuario el nombre
			nombre[i]=entrada.next();
			//@SuppressWarnings("unused") // Para no tener en cuenta el warning
			segundoNombre[i]=entrada.nextLine();
			
			System.out.print("Introduzca su edad: ");
			edad[i] = entrada.nextInt();
			entrada.nextLine(); // Para limpiar el buffer, cuando introducimos un número se queda el \n
			
			System.out.print("Introduzca su apellido: ");
			apellido[i]=entrada.nextLine();

			
			i++;
			System.out.println("¿Quieres añadir otro alumno? (si/no)");
			respuesta=entrada.next();
			
			if(respuesta.contains("si")) {
				seguir = true;
				System.out.println("");
			}
		} while (seguir && i < 100);
		imprimir(i,nombre,segundoNombre,apellido,edad);
		entrada.close();
	}
	static void imprimir(int cantidad, String[] nombre, String[] segundoNombre, String[] apellido, int[] edad) {
		System.out.println('\n'+"IMPRIMIR ALUMNOS");
		for(int i=0; i<cantidad; i++) {
			System.out.println('\n'+"Alumno " + i);
			System.out.println("Hola " + nombre[i] + " " + apellido[i]);
			System.out.println("Tienes " + edad[i] + " años");
		}
	}

}