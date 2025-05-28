package Biblioteca2;

public class Usuario {
	private String idUsuario;
	private String nombre;
	public Usuario(String idUsuario, String nombre) {
		super();
		this.idUsuario = idUsuario;
		this.nombre = nombre;
	}
	
	public String getNombre() {
		return nombre;
	}
	public String getIdUsuario() {
		return idUsuario;
	}
	
	@Override
	public String toString() {
		return "Usuario [idUsuario=" + idUsuario + ", nombre=" + nombre + "]";
	}
	public void setIdUsuario(String idUsuario) {
		this.idUsuario = idUsuario;
	}
	public void setNombre(String nombre) {
		this.nombre = nombre;
	}
}
