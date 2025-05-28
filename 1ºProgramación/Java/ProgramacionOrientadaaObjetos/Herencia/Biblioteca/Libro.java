package Biblioteca;

public class Libro extends Articulo{
	private String autor;

	public Libro(int id, String titulo, boolean disponibilidad, String autor) {
		super(id, titulo, disponibilidad);
		this.autor = autor;
	}

	@Override
	public String toString() {
		return "Libro [autor=" + autor + "]";
	}
	
}
