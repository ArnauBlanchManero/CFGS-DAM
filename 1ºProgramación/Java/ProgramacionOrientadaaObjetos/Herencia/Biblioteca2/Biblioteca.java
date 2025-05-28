package Biblioteca2;

import java.time.LocalDate;
import java.util.Arrays;

public class Biblioteca {
	public String nombre;
	public Articulo [] articulos = new Articulo[5]; // Defino tamaño 5
	public Prestamo [] prestamos = new Prestamo[5]; // Defino tamaño 5

	public Biblioteca(String nombre, Articulo[] articulos, Prestamo[] prestamos) {
		super();
		this.nombre = nombre;
		this.articulos = articulos;
		this.prestamos = prestamos;
	}
	
	public Biblioteca(String nombre) {
		super();
		this.nombre = nombre;
		this.articulos = null;
		this.prestamos = null;
	}
	
	public void agregarArticulo(Articulo a, int n) { // Trabajo con la n porque no se usar listas
		this.articulos[n] = a;
	}
	
	public Articulo buscarArticuloPorId(String id) {
		Articulo articulo_busacr = null;
		return articulo_busacr;
	}
	
	public boolean prestarArticulo(String idArticulo, Usuario usuario, LocalDate fecha) {
		return false;
	}
	
	public boolean devolverArticulo(String idArticulo) {
		return false;
	}
	
	public void mostrarTodosLosArticulos() {
		
	}
	
	public void mostarPrestamos() {
		
	}
	
	public void mostarPrestamosPorUsuario(String idUsuario) {
		
	}
	
	@Override
	public String toString() {
		return "Biblioteca [nombre=" + nombre + ", articulos=" + Arrays.toString(articulos) + ", prestamos="
				+ Arrays.toString(prestamos) + "]";
	}

	public String getNombre() {
		return nombre;
	}

	public void setNombre(String nombre) {
		this.nombre = nombre;
	}

	public Articulo[] getArticulos() {
		return articulos;
	}

	public void setArticulos(Articulo[] articulos) {
		this.articulos = articulos;
	}

	public Prestamo[] getPrestamos() {
		return prestamos;
	}

	public void setPrestamos(Prestamo[] prestamos) {
		this.prestamos = prestamos;
	}
	
	
}
