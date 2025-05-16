package Trabajadores;

public class Modulo {
	String nombre;
	int horas;
	Profesor profeModulo;
	boolean convalidable;
	
	public Modulo(String nombre, int horas, Profesor profeModulo, boolean convalidable) {
		super();
		this.nombre = nombre;
		this.horas = horas;
		this.profeModulo = profeModulo;
		this.convalidable = convalidable;
	}

	@Override
	public String toString() {
		String convalidableString = null;
		if (convalidable) {
			convalidableString = "sí es convalidable";
		} else {
			convalidableString = "no es convalidable";
		}
		return "Modulo: " + nombre + ", horas: " + horas + ", "+ convalidableString+" \n"+"		" +profeModulo+'\n'+"	";
	}
	
	public String getNombre() {
		return nombre;
	}
	public void setNombre(String nombre) {
		this.nombre = nombre;
	}
	public int getHoras() {
		return horas;
	}
	public void setHoras(int horas) {
		this.horas = horas;
	}
	public Profesor getProfeModulo() {
		return profeModulo;
	}
	public void setProfeModulo(Profesor profeModulo) {
		this.profeModulo = profeModulo;
	}
	public boolean isConvalidable() {
		return convalidable;
	}
	public void setConvalidable(boolean convalidable) {
		this.convalidable = convalidable;
	}
}
