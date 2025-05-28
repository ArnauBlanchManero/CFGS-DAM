package Trabajadores;

public class Profesor extends Persona {
	private int n_asignaturas;
	private boolean tutor;
	
	public Profesor(String dni, String nombre, String apellido, double salario, int n_asignaturas, boolean tutor) {
		super(dni, nombre, apellido, salario);
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
		return "Profesor "+nombre+" "+apellido+", DNI: " + dni + ", salario: " + salario
				+ ", número de asignaturas: " + n_asignaturas + ", " + tutorString + ".";
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
