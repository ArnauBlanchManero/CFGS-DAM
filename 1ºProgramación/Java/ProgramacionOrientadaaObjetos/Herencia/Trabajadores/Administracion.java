package Trabajadores;

public class Administracion extends Persona{
	private String estudios;
	private int antiguedad;
	
	public Administracion(String dni, String nombre, String apellido, double salario, String estudios, int antiguedad) {
		super(dni, nombre, apellido, salario);
		this.estudios = estudios;
		this.antiguedad = antiguedad;
	}
	
	@Override
	public String toString() {
		return "Administrador "+nombre+" "+apellido+" DNI: " + dni + ", salario: " + salario
				+ ", estudios: " + estudios + ", antiguedad: " + antiguedad + " años.";
	}
	
	public String getEstudios() {
		return estudios;
	}
	public void setEstudios(String estudios) {
		this.estudios = estudios;
	}
	public int getAntiguedad() {
		return antiguedad;
	}
	public void setAntiguedad(int antiguedad) {
		this.antiguedad = antiguedad;
	}
}
