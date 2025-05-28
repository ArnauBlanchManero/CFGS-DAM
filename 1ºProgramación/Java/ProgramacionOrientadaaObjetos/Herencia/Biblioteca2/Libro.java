package Biblioteca2;

public class Libro extends Articulo{
	private String autor;

	public Libro(String id, String titulo, boolean disponible, String autor) {
		super(id, titulo, disponible);
		this.autor = autor;
	}

	public String getDescripcion() {
		return "";
		
	}
	
	@Override
	public String toString() {
		return "Libro [id="+id+", autor=" + autor + "]";
	}

	public String getAutor() {
		return autor;
	}

	public void setAutor(String autor) {
		this.autor = autor;
	}
}
