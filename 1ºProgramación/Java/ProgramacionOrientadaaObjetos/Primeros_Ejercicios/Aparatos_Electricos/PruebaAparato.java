package Aparatos_Electricos;

public class PruebaAparato {

	public static void main(String[] args) {
		Aparato bombilla = new Aparato("bombilla", 100);
		Aparato radiador = new Aparato("radiador", 2000);
		Aparato plancha = new Aparato("plancha", 1200);
		System.out.println(bombilla.toString());
		System.out.println(radiador.toString());
		System.out.println(plancha.toString());
		System.out.println("El consumo total es de "+Aparato.getConsumoTotal());
		bombilla.setEstado(true);
		Aparato.setConsumoTotal(bombilla.getConsumo());
		plancha.setEstado(true);
		Aparato.setConsumoTotal(plancha.getConsumo());
		System.out.println(bombilla.toString());
		System.out.println(radiador.toString());
		System.out.println(plancha.toString());
		System.out.println("El consumo total es de "+Aparato.getConsumoTotal());
		plancha.setEstado(false);
		Aparato.setConsumoTotal(0-plancha.getConsumo());
		radiador.setEstado(true);
		Aparato.setConsumoTotal(radiador.getConsumo());
		System.out.println(bombilla.toString());
		System.out.println(radiador.toString());
		System.out.println(plancha.toString());
		System.out.println("El consumo total es de "+Aparato.getConsumoTotal());
	}

}
