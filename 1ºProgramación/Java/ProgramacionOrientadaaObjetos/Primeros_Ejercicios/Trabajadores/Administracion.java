package Trabajadores;

public class Administracion {
	String dni;
	String nombre;
	String apellidos;
	double salario;
	String estudios;
	int antiguedad;
	
	public Administracion(String dni, String nombre, String apellidos, double salario, String estudios,
			int antiguedad) {
		super();
		this.dni = dni;
		this.nombre = nombre;
		this.apellidos = apellidos;
		this.salario = salario;
		this.estudios = estudios;
		this.antiguedad = antiguedad;
	}

	@Override
	public String toString() {
		return "Administrador "+nombre+" "+apellidos+" DNI: " + dni + ", salario: " + salario
				+ ", estudios: " + estudios + ", antiguedad: " + antiguedad + " años.";
	}
	
	public String getDni() {
		return dni;
	}
	public void setDni(String dni) {
		this.dni = dni;
	}
	public String getNombre() {
		return nombre;
	}
	public void setNombre(String nombre) {
		this.nombre = nombre;
	}
	public String getApellidos() {
		return apellidos;
	}
	public void setApellidos(String apellidos) {
		this.apellidos = apellidos;
	}
	public double getSalario() {
		return salario;
	}
	public void setSalario(double salario) {
		this.salario = salario;
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
