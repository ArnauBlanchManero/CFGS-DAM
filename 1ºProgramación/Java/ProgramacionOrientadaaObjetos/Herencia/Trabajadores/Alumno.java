package Trabajadores;

enum Sexo {HOMBRE, MUJER}

public class Alumno extends Persona{
	private String fecha_nac;
	private Sexo sexoAlumno;
	private boolean repetidor;
	private Modulo [] modulos;
	
	public Alumno(String dni, String nombre, String apellido, String fecha_nac, Sexo sexoAlumno,
			boolean repetidor, Modulo[] modulos) {
		super(dni, nombre, apellido);
		this.fecha_nac = fecha_nac;
		this.sexoAlumno = sexoAlumno;
		this.repetidor = repetidor;
		this.modulos = modulos;
	}

	@Override
	public String toString() {
		String repetidorString = null;
		if (repetidor) {
			repetidorString = "sí es repetidor";
		} else {
			repetidorString = "no es repetidor";
		}
		return "Alumno "+nombre+" "+apellido+" DNI: " + dni+ ", fecha de nacimiento: " + fecha_nac
				+ ", sexo: " + sexoAlumno + ", " + repetidorString + "\n	"+ imprimirModulos(modulos);
	}
	private String imprimirModulos(Modulo[] modulos) {
		String ret = "";
		for (int i = 0; i < modulos.length; i++) {
			ret += modulos[i].toString();
		}
		return ret;
	}
	public String getFecha_nac() {
		return fecha_nac;
	}

	public void setFecha_nac(String fecha_nac) {
		this.fecha_nac = fecha_nac;
	}

	public Sexo getSexoAlumno() {
		return sexoAlumno;
	}

	public void setSexoAlumno(Sexo sexoAlumno) {
		this.sexoAlumno = sexoAlumno;
	}

	public boolean isRepetidor() {
		return repetidor;
	}

	public void setRepetidor(boolean repetidor) {
		this.repetidor = repetidor;
	}

	public Modulo[] getModulos() {
		return modulos;
	}

	public void setModulos(Modulo[] modulos) {
		this.modulos = modulos;
	}
	
}
