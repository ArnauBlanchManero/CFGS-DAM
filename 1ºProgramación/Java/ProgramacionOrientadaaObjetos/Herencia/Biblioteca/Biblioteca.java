package Biblioteca;

public class Biblioteca {
	public Articulo [] articulos;
	public String nombre;

	public Biblioteca(Articulo[] articulos, String nombre) {
		super();
		this.articulos = articulos;
		this.nombre = nombre;
	}
	
	public Biblioteca(String nombre) {
		super();
		this.nombre = nombre;
	}
}
