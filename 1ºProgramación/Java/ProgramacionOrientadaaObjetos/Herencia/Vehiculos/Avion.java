package Vehiculos;

public class Avion extends Vehiculo{
	private byte motores;
	private double velocidadMax;
	private boolean combate;
	
	public Avion(String marca, String color, String numero_bastidor, int kilometros, int añofabricacion, byte motores,
			double velocidadMax, boolean combate) {
		super(marca, color, numero_bastidor, kilometros, añofabricacion);
		this.motores = motores;
		this.velocidadMax = velocidadMax;
		this.combate = combate;
	}

	public Avion(String marca, String color, String numero_bastidor, int kilometros, int añofabricacion, boolean combate) {
		super(marca, color, numero_bastidor, kilometros, añofabricacion);
		this.combate = combate;
	}

	public byte getMotores() {
		return motores;
	}

	public void setMotores(byte motores) {
		this.motores = motores;
	}

	public double getVelocidadMax() {
		return velocidadMax;
	}

	public void setVelocidadMax(double velocidadMax) {
		this.velocidadMax = velocidadMax;
	}

	public boolean isCombate() {
		return combate;
	}

	public void setCombate(boolean combate) {
		this.combate = combate;
	}

	@Override
	public String toString() {
		return "Avion : \n\tMarca " + marca + "\n\tEs de color " + color + "\n\tSu número de bastidor es " + numero_bastidor+ "\n\tTiene " + kilometros + " kilómetros\n\tSe fabricó en el año " + añofabricacion+
				"\n\t[motores=" + motores + ", velocidadMax=" + velocidadMax + ", combate=" + combate + "]";
	}
	
	
}
