package Trabajadores;

public class Profesor {
	String dni;
	String nombre;
	String apellidos;
	double salario;
	int n_asignaturas;
	boolean tutor;
	
	public Profesor(String dni, String nombre, String apellidos, double salario, int n_asignaturas, boolean tutor) {
		super();
		this.dni = dni;
		this.nombre = nombre;
		this.apellidos = apellidos;
		this.salario = salario;
		this.n_asignaturas = n_asignaturas;
		this.tutor = tutor;
	}

	@Override
	public String toString() {
		String tutorString = null;
		if (tutor) {
			tutorString = "sí es tutor";
		} else {
			tutorString = "no es tutor";
		}
		return "Profesor "+nombre+" "+apellidos+", DNI: " + dni + ", salario: " + salario
				+ ", número de asignaturas: " + n_asignaturas + ", " + tutorString + ".";
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
	public int getN_asignaturas() {
		return n_asignaturas;
	}
	public void setN_asignaturas(int n_asignaturas) {
		this.n_asignaturas = n_asignaturas;
	}
	public boolean isTutor() {
		return tutor;
	}
	public void setTutor(boolean tutor) {
		this.tutor = tutor;
	}
}
