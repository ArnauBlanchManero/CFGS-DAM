package Vehiculos;
enum Tipo {VELA, PESCA, PASAJEROS}

public class Barco extends Vehiculo{
	private int eslora;
	private int calado;
	private Tipo tipo;
	
	public Barco(String marca, String color, String numero_bastidor, int kilometros, int añofabricacion, int eslora,
			int calado, Tipo tipo) {
		super(marca, color, numero_bastidor, kilometros, añofabricacion);
		this.eslora = eslora;
		this.calado = calado;
		this.tipo = tipo;
	}

	public int getEslora() {
		return eslora;
	}

	public void setEslora(int eslora) {
		this.eslora = eslora;
	}

	public int getCalado() {
		return calado;
	}

	public void setCalado(int calado) {
		this.calado = calado;
	}

	public Tipo getTipo() {
		return tipo;
	}

	public void setTipo(Tipo tipo) {
		this.tipo = tipo;
	}

	@Override
	public String toString() {
		return "Barco : \n\tMarca " + marca + "\n\tEs de color " + color + "\n\tSu número de bastidor es " + numero_bastidor+ "\n\tTiene " + kilometros + " kilómetros\n\tSe fabricó en el año " + añofabricacion+
				"\n\t[eslora=" + eslora + ", calado=" + calado + ", tipo=" + tipo + "]";
	}
	
	
}
