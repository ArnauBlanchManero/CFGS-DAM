package Biblioteca2;
import java.util.Scanner;

public class Main {
	public static Scanner entrada = new Scanner(System.in);
	
	public static void main(String[] args) {
		Biblioteca principal;
		Usuario [] usuarios;
		
		int respuesta = 0;
		principal = introduccionBiblio();
		usuarios = introducirUsuarios();
		menu(principal, usuarios);
	}
	private static void menu(Biblioteca principal, Usuario[] usuarios) {
		Prestamo[] prestamos = null;
		int respuesta;
		do {
			System.out.println("¿Qué quieres hacer con la biblioteca?\n1- Prestar un artículo\n2- Devolver un artículo\n3- Mostrar todo\n4- Salir");
			respuesta = entrada.nextInt();
			entrada.nextLine();
			prestamos = menuPrestamos(principal, usuarios, respuesta, prestamos);
		} while (respuesta != 4);
	}
	private static Prestamo[] menuPrestamos(Biblioteca principal, Usuario[] usuarios, int respuesta, Prestamo[] prestamos) {
		switch (respuesta) {
		case 1:
			prestamos = prestarArticulo(principal, usuarios);
			break;
		case 2:
			prestamos = devolverArticulo(principal, usuarios);
			break;
		case 3:
			mostrarTodo(principal, usuarios);
			break;
		default:
			break;
		}
		return prestamos;
	}
	private static void mostrarTodo(Biblioteca b, Usuario[] u) {
		// TODO Auto-generated method stub
		
	}
	private static Prestamo[] devolverArticulo(Biblioteca b, Usuario[] u) {
		String usuarioS;
		boolean encontrado = false;
		int usuarioI = 0;
		Articulo [] art_biblio = null;
		String articuloS;
		int articuloI = 0;
		Prestamo [] p = new Prestamo[5];
		int cantidad_p = 0;
		System.out.println("Tienes que seleccionar un usuario y el artículo que tiene que devolver.");
		System.out.println("¿Quién viene a devolverlo?");
		for (int i = 0; i < u.length; i++) {
			System.out.println(u[i].toString());
		}
		System.out.print("Id del usuario que devuelve: ");
		usuarioS = entrada.next();
		entrada.nextLine();
		for (int i = 0; i < u.length; i++) {
			if(u[i].getIdUsuario().equals(usuarioS)) {
				encontrado = true;
				usuarioI=i;
			}
		}
		if (encontrado) {
			encontrado = false;
			System.out.println("Ahora selecciona el articulo que devuelve "+u[usuarioI].getNombre());
			art_biblio = b.articulos;
			for (int i = 0; i < art_biblio.length; i++) {
				System.out.println(art_biblio[i].toString());
			}
			System.out.print("Id del articulo a devolver: ");
			articuloS = entrada.next();
			entrada.nextLine();
			for (int i = 0; i < art_biblio.length; i++) {
				if(art_biblio[i].getId().equals(articuloS)) {
					encontrado = true;
					articuloI=i;
				}
			}
			// Me he quedado por aquí porque no me da tiempo a más.
			if (encontrado) {
				System.out.println("El usuario "+u[usuarioI].getNombre()+ " va a devolver "+b.articulos[articuloI].getTitulo());
				cantidad_p = Prestamo.getContadorPrestamos();
				if(cantidad_p <= 5) {
					if(b.articulos[articuloI].estaDisponible()) {
						p[cantidad_p] = new Prestamo(b.articulos[articuloI], u[usuarioI], "22/05/2025");
						b.articulos[articuloI].prestar();
						Prestamo.incrementarContador();
					} else {
						System.out.println("No está disponible");
					}
				} else {
					System.out.println("Ya has prestado muchos libros.");
				}
			} else {
				System.out.println("No existe ese articulo");
			}
		} else {
			System.out.println("No existe ese usuario");
		}
		return p;
	}
	private static Prestamo[] prestarArticulo(Biblioteca b, Usuario[] u) {
		String usuarioS;
		boolean encontrado = false;
		int usuarioI = 0;
		Articulo [] art_biblio = null;
		String articuloS;
		int articuloI = 0;
		Prestamo [] p = new Prestamo[5];
		int cantidad_p = 0;
		System.out.println("Tienes que seleccionar un usuario al que prestarle un articulo.");
		System.out.println("¿A quién se lo prestas?");
		for (int i = 0; i < u.length; i++) {
			System.out.println(u[i].toString());
		}
		System.out.print("Id del usuario a prestar: ");
		usuarioS = entrada.next();
		entrada.nextLine();
		for (int i = 0; i < u.length; i++) {
			if(u[i].getIdUsuario().equals(usuarioS)) {
				encontrado = true;
				usuarioI=i;
			}
		}
		if (encontrado) {
			encontrado = false;
			System.out.println("Ahora selecciona un artículo para prestar a "+u[usuarioI].getNombre());
			art_biblio = b.articulos;
			for (int i = 0; i < art_biblio.length; i++) {
				System.out.println(art_biblio[i].toString());
			}
			System.out.print("Id del articulo a prestar: ");
			articuloS = entrada.next();
			entrada.nextLine();
			for (int i = 0; i < art_biblio.length; i++) {
				if(art_biblio[i].getId().equals(articuloS)) {
					encontrado = true;
					articuloI=i;
				}
			}
			if (encontrado) {
				System.out.println("Vas a prestar "+b.articulos[articuloI].getTitulo()+ " a "+u[usuarioI].getNombre());
				cantidad_p = Prestamo.getContadorPrestamos();
				if(cantidad_p <= 5) {
					if(b.articulos[articuloI].estaDisponible()) {
						p[cantidad_p] = new Prestamo(b.articulos[articuloI], u[usuarioI], "22/05/2025");
						b.articulos[articuloI].prestar();
						Prestamo.incrementarContador();
					} else {
						System.out.println("No está disponible");
					}
				} else {
					System.out.println("Ya has prestado muchos libros.");
				}
			} else {
				System.out.println("No existe ese articulo");
			}
		} else {
			System.out.println("No existe ese usuario");
		}
		return p;
	}
	private static Usuario[] introducirUsuarios() {
		Usuario[] usuarios_temp = new Usuario[2];
		System.out.println("Estos usuarios suelen venir a la biblioteca:");
		usuarios_temp[0] = new Usuario("001", "Pablo");
		usuarios_temp[1] = new Usuario("002", "Marta");
		for (int i = 0; i < usuarios_temp.length; i++) {
			System.out.println(usuarios_temp[i].toString());
		}
		return usuarios_temp;
	}
	private static Biblioteca introduccionBiblio() {
		String nombre_biblio;
		Biblioteca temp;
		Articulo [] articulos_introcucir;
		System.out.println("Bienvenido al gestor de bibliotecas.");
		System.out.print("Por favor, introduce el nombre de la biblioteca: ");
		nombre_biblio = entrada.nextLine();
		temp = new Biblioteca(nombre_biblio);
		System.out.println("Tu biblioteca está vacía, por favor, introduce artículos: ");
		do {
			articulos_introcucir = menuArticulos();
		} while (articulos_introcucir == null);
		System.out.println("Estos son los articulos que has añadido:");
		for (int i = 0; i < articulos_introcucir.length; i++) {
			System.out.println(articulos_introcucir[i].toString());
		}
		temp = new Biblioteca(nombre_biblio, articulos_introcucir, null);
		return temp;
	}
	private static Articulo[] menuArticulos() {
		Articulo[] art_temp = new Articulo[5];
		Articulo[] nuevo_art = null;
		boolean seguir;
		int contador = 0;
		int vueltas = 0;
		int respuesta = 0;
		do {
			seguir = true;
			System.out.println("¿Qué quieres añadir?\n1- Libro\n2- Revista\n3- Salir");
			respuesta = entrada.nextInt();
			entrada.nextLine();
			switch (respuesta) {
			case 1:
				art_temp[contador] = añadirLibro();
				contador++;
				break;
			case 2:
				art_temp[contador] = añadirRevista();
				contador++;
				break;
			case 3:
				seguir = false;
				break;
			default:
				break;
			}
			vueltas++;
			if (vueltas == 5) {
				seguir = false;
			}
		} while (seguir && vueltas<5);
		if (contador != 0) {
			nuevo_art = new Articulo[contador];
		} else {
			System.out.println("No has añadido nada");
		}
		for (int i = 0; i < contador; i++) {
			nuevo_art[i] = art_temp[i];
		}
		return nuevo_art;
	}
	private static Articulo añadirRevista() {
		String id;
		String titulo;
		int n_edicion;
		Revista revista_temp;
		System.out.println("Introduce los datos de la revista:");
		System.out.print("Id: ");
		id = entrada.next();
		entrada.nextLine();
		System.out.print("Titulo: ");
		titulo = entrada.nextLine();
		System.out.print("Número de edicion: ");
		n_edicion = entrada.nextInt();
		entrada.nextLine();
		revista_temp = new Revista(id, titulo, true, n_edicion);
		return revista_temp;
	}
	private static Articulo añadirLibro() {
		String id;
		String titulo;
		String autor;
		Libro libro_temp;
		System.out.println("Introduce los datos del libro:");
		System.out.print("Id: ");
		id = entrada.next();
		entrada.nextLine();
		System.out.print("Titulo: ");
		titulo = entrada.nextLine();
		System.out.print("Autor: ");
		autor = entrada.nextLine();
		libro_temp = new Libro(id, titulo, true, autor);
		return libro_temp;
	}

}
