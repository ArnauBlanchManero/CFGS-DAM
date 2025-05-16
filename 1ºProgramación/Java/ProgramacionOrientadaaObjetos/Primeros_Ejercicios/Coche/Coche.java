package Coche;

enum TipoCoche{MINI, UTILITARIO, FAMILIAR, DEPORTIVO}
enum Seguro{TERCEROS, TODO_RIESGO}

public class Coche {
	String modelo;
	String color;
	boolean pintura_metalizada;
	String matricula;
	TipoCoche tipo_coche;
	int año;
	Seguro seguro;

	public Coche(String modelo, String color, boolean pintura_metalizada, String matricula, TipoCoche tipo_coche,
			int año, Seguro seguro) {
		super();
		this.modelo = modelo;
		this.color = color;
		this.pintura_metalizada = pintura_metalizada;
		this.matricula = matricula;
		this.tipo_coche = tipo_coche;
		this.año = año;
		this.seguro = seguro;
	}
	
	@Override
	public String toString() {
		return "Coche [modelo=" + modelo + ", color=" + color + ", pintura_metalizada=" + pintura_metalizada
				+ ", matricula=" + matricula + ", tipo_coche=" + tipo_coche + ", año=" + año + ", seguro=" + seguro
				+ "]";
	}
	
	public String getModelo() {
		return modelo;
	}
	public void setModelo(String modelo) {
		this.modelo = modelo;
	}
	public String getColor() {
		return color;
	}
	public void setColor(String color) {
		this.color = color;
	}
	public boolean isPintura_metalizada() {
		return pintura_metalizada;
	}
	public void setPintura_metalizada(boolean pintura_metalizada) {
		this.pintura_metalizada = pintura_metalizada;
	}
	public String getMatricula() {
		return matricula;
	}
	public void setMatricula(String matricula) {
		this.matricula = matricula;
	}
	public TipoCoche getTipo_coche() {
		return tipo_coche;
	}
	public void setTipo_coche(TipoCoche tipo_coche) {
		this.tipo_coche = tipo_coche;
	}
	public int getAño() {
		return año;
	}
	public void setAño(int año) {
		this.año = año;
	}
	public Seguro getSeguro() {
		return seguro;
	}
	public void setSeguro(Seguro seguro) {
		this.seguro = seguro;
	}
	
}
