package Biblioteca;

public class Articulo {
	public int id;
	public String titulo;
	public boolean disponibilidad;
	
	public Articulo(int id, String titulo, boolean disponibilidad) {
		super();
		this.id = id;
		this.titulo = titulo;
		this.disponibilidad = disponibilidad;
	}
	public void prestar() {
		disponibilidad = !disponibilidad;
	}
	public int getId() {
		return id;
	}

	public void setId(int id) {
		this.id = id;
	}

	public String getTitulo() {
		return titulo;
	}

	public void setTitulo(String titulo) {
		this.titulo = titulo;
	}

	public boolean isDisponibilidad() {
		return disponibilidad;
	}

	public void setDisponibilidad(boolean disponibilidad) {
		this.disponibilidad = disponibilidad;
	}
	
}
