package Trabajadores;
enum Turno {MAÑANA, TARDE}

public class Directivo extends Persona{
	private boolean salesiano;
	private Turno turno;
	
	public Directivo(String dni, String nombre, String apellido, double salario, boolean salesiano, Turno turno) {
		super(dni, nombre, apellido, salario);
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
		return "Directivo "+nombre+" "+apellido+" DNI: " + dni + ", salario: " + salario
				+ ", " + salesianoString + ", turno de " + turno + ".";	}
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
