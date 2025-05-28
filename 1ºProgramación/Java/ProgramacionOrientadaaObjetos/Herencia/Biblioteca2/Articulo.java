package Biblioteca2;

public class Articulo {
	public String id;
	public String titulo;
	public boolean disponible;
	public Articulo(String id, String titulo, boolean disponible) {
		super();
		this.id = id;
		this.titulo = titulo;
		this.disponible = disponible;
	}
	
	public boolean prestar() {
		this.disponible = false;
		return false;
	}
	
	public void devolver() {
		this.disponible = true;
	}
	
	public boolean estaDisponible() {
		return disponible;
	}
	
	public String getDescripcion() {
		return "";
	}
	
	public String getTipo() {
		return "";
	}
	
	@Override
	public String toString() {
		return "Articulo [id=" + id + ", titulo=" + titulo + ", disponible=" + disponible + "]";
	}
	public String getId() {
		return id;
	}
	public void setId(String id) {
		this.id = id;
	}
	public String getTitulo() {
		return titulo;
	}
	public void setTitulo(String titulo) {
		this.titulo = titulo;
	}
	public boolean isDisponible() {
		return disponible;
	}
	public void setDisponible(boolean disponible) {
		this.disponible = disponible;
	}
}
