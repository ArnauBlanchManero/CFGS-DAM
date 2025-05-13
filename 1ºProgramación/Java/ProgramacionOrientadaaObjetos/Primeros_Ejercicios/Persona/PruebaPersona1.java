package Persona;

public class PruebaPersona1 {

	public static void main(String[] args) {
		Persona player1 = new Persona(55, 1.8, 85, false, "aguda");
		System.out.println(player1.toString());
		player1.setAltura(1.2);
		System.out.println(player1.toString());
		System.out.println("La altura de esta persona es "+ player1.getAltura());
		
		
	}

}
