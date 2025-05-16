package Trabajadores;
enum Turno {MAÑANA, TARDE}

public class Directivo {
	String dni;
	String nombre;
	String apellidos;
	double salario;
	boolean salesiano;
	Turno turno;
	
	public Directivo(String dni, String nombre, String apellidos, double salario, boolean salesiano, Turno turno) {
		super();
		this.dni = dni;
		this.nombre = nombre;
		this.apellidos = apellidos;
		this.salario = salario;
		this.salesiano = salesiano;
		this.turno = turno;
	}

	@Override
	public String toString() {
		String salesianoString = null;
		if (salesiano) {
			salesianoString = "sí es salesiano";
		} else {
			salesianoString = "no es salesiano";
		}
		return "Directivo "+nombre+" "+apellidos+" DNI: " + dni + ", salario: " + salario
				+ ", " + salesianoString + ", turno de " + turno + ".";
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
	public boolean isSalesiano() {
		return salesiano;
	}
	public void setSalesiano(boolean salesiano) {
		this.salesiano = salesiano;
	}
	public Turno getTurno() {
		return turno;
	}
	public void setTurno(Turno turno) {
		this.turno = turno;
	}
}
