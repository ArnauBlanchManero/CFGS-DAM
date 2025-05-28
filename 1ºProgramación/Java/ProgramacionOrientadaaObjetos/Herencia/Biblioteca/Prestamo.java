package Biblioteca;

public class Prestamo {
	public String fecha;
	public int contador;
	public Articulo articulo;
	
	public Prestamo(String fecha, int contador, Articulo articulo) {
		super();
		this.fecha = fecha;
		this.contador = contador;
		this.articulo = articulo;
	}
}
