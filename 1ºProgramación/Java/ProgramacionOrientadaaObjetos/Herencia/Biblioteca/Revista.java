package Biblioteca;

public class Revista extends Articulo{
	private int n_edicion;
	
	public Revista(int id, String titulo, boolean disponibilidad, int n_edicion) {
		super(id, titulo, disponibilidad);
		this.n_edicion = n_edicion;
	}

	@Override
	public String toString() {
		return "Revistas [n_edicion=" + n_edicion + "]";
	}
}
