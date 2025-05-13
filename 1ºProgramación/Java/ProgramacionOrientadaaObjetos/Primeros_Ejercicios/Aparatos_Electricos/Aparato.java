package Aparatos_Electricos;

public class Aparato {
	String nombre;
	int consumo;
	boolean estado;
	static int consumoTotal;
	
	public Aparato(String nombre, int consumo) {
		super();
		this.nombre = nombre;
		this.consumo = consumo;
		this.estado = false;
	}

	@Override
	public String toString() {
		String estadoChar;
		if (estado) {
			estadoChar = "encendido";
		} else {
			estadoChar = "apagado";
		}
		return "El aparato " + nombre + " consume un total de " + consumo + " watios. Ahora está " + estadoChar + ".";
	}
	
	public String getNombre() {
		return nombre;
	}
	public void setNombre(String nombre) {
		this.nombre = nombre;
	}
	public int getConsumo() {
		return consumo;
	}
	public void setConsumo(int consumo) {
		this.consumo = consumo;
	}
	public boolean isEstado() {
		return estado;
	}
	public void setEstado(boolean estado) {
		this.estado = estado;
	}
	public static int getConsumoTotal() {
		return consumoTotal;
	}
	public static void setConsumoTotal(int consumoTotal) {
		Aparato.consumoTotal += consumoTotal;
	}
}
