package Vehiculos;

public class Coche extends Vehiculo{
	protected boolean electrico;
	private boolean antiguo;
	
	public Coche(String marca, String color, String numero_bastidor, int kilometros, int añofabricacion,
			boolean electrico) {
		super(marca, color, numero_bastidor, kilometros, añofabricacion);
		this.electrico = electrico;
	}

	public boolean isElectrico() {
		return electrico;
	}

	public void setElectrico(boolean electrico) {
		this.electrico = electrico;
	}

	public boolean isAntiguo() {
		return antiguo;
	}

	public void setAntiguo(boolean antiguo) {
		this.antiguo = antiguo;
	}

	@Override
	public String toString() {
		return "Coche: \n\tMarca " + marca + "\n\tEs de color " + color + "\n\tSu número de bastidor es " + numero_bastidor+ "\n\tTiene " + kilometros + " kilómetros\n\tSe fabricó en el año " + añofabricacion+
				"\n\t[electrico=" + electrico + ", antiguo=" + antiguo + "]";
	}
	
}
