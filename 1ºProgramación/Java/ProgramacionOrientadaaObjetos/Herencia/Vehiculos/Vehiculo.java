package Vehiculos;

public class Vehiculo {
	public String marca;
	public String color;
	public String numero_bastidor;
	public int kilometros;
	protected int añofabricacion;
	
	public Vehiculo(String marca, String color, String numero_bastidor, int kilometros, int añofabricacion) {
		super();
		this.marca = marca;
		this.color = color;
		this.numero_bastidor = numero_bastidor;
		this.kilometros = kilometros;
		this.añofabricacion = añofabricacion;
	}

	public String getMarca() {
		return marca;
	}

	public void setMarca(String marca) {
		this.marca = marca;
	}

	public String getColor() {
		return color;
	}

	public void setColor(String color) {
		this.color = color;
	}

	public String getNumero_bastidor() {
		return numero_bastidor;
	}

	public void setNumero_bastidor(String numero_bastidor) {
		this.numero_bastidor = numero_bastidor;
	}

	public int getKilometros() {
		return kilometros;
	}

	public void setKilometros(int kilometros) {
		this.kilometros = kilometros;
	}

	public int getAñofabricacion() {
		return añofabricacion;
	}

	public void setAñofabricacion(int añofabricacion) {
		this.añofabricacion = añofabricacion;
	}

	@Override
	public String toString() {
		return "Vehículo [marca=" + marca + ", color=" + color + ", numero_bastidor=" + numero_bastidor
				+ ", kilometros=" + kilometros + ", añofabricacion=" + añofabricacion + "]";
	}
	
	
}
