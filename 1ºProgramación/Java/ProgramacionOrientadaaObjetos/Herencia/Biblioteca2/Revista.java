package Biblioteca2;

public class Revista extends Articulo{
	private int numeroEdicion;

	public Revista(String id, String titulo, boolean disponible, int numeroEdicion) {
		super(id, titulo, disponible);
		this.numeroEdicion = numeroEdicion;
	}

	public String getDescripcion() {
		return "";
		
	}
	
	@Override
	public String toString() {
		return "Revista [id="+id+", numeroEdicion=" + numeroEdicion + "]";
	}

	public int getNumeroEdicion() {
		return numeroEdicion;
	}

	public void setNumeroEdicion(int numeroEdicion) {
		this.numeroEdicion = numeroEdicion;
	}
}
