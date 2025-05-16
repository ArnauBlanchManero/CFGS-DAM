package Coche;

public class PruebaCoche {
	
	public static void main(String[] args) {
		int cantidad_coches = 10;
		Coche [] coches = new Coche[cantidad_coches];
		coches = crearCoches(cantidad_coches);
		imprimirTodosCoches(coches);
		imprimirAlgunosCoches(coches);
		
	}

	private static Coche[] crearCoches(int cant) {
		Coche [] coches = new Coche[cant];
		coches[0] = new Coche("Toyota Corolla", "Rojo", true, "1234BCD", TipoCoche.UTILITARIO, 2009, Seguro.TERCEROS);
		coches[1] = new Coche("Volkswagen Golf", "Negro", false, "5678FGH", TipoCoche.DEPORTIVO, 2017, Seguro.TODO_RIESGO);
		coches[2] = new Coche("BMW X5", "Azul", true, "9101JKL", TipoCoche.FAMILIAR, 2020, Seguro.TERCEROS);
		coches[3] = new Coche("Ford Fiesta", "Blanco", false, "1122MNO", TipoCoche.MINI, 2012, Seguro.TERCEROS);
		coches[4] = new Coche("Audi A4", "Gris", true, "3344PQR", TipoCoche.DEPORTIVO, 2018, Seguro.TODO_RIESGO);
		coches[5] = new Coche("Renault Scenic", "Verde", false, "5566STU", TipoCoche.FAMILIAR, 2015, Seguro.TERCEROS);
		coches[6] = new Coche("Seat León", "Amarillo", true, "7788VWX", TipoCoche.UTILITARIO, 2016, Seguro.TODO_RIESGO);
		coches[7] = new Coche("Mercedes-Benz CLA", "Negro", true, "9900YZA", TipoCoche.MINI, 2022, Seguro.TODO_RIESGO);
		coches[8] = new Coche("Peugeot 5008", "Azul Oscuro", false, "2233BCD", TipoCoche.FAMILIAR, 2019, Seguro.TERCEROS);
		coches[9] = new Coche("Kia Ceed", "Rojo", true, "4455EFG", TipoCoche.UTILITARIO, 2014, Seguro.TERCEROS);
		return coches;
	}

	private static void imprimirAlgunosCoches(Coche[] coches) {
		System.out.println("Los coches de tipo deportivo o con el año par:");
		for (int i = 0; i < coches.length; i++) {
			if (coches[i].getTipo_coche() == TipoCoche.DEPORTIVO || coches[i].getAño() % 2 == 0) {
				System.out.print(i+": ");
				System.out.println(coches[i].toString());
			}
		}
		
	}

	private static void imprimirTodosCoches(Coche[] coches) {
		System.out.println("Los coches del sistema son:");
		for (int i = 0; i < coches.length; i++) {
			System.out.print(i+": ");
			System.out.println(coches[i].toString());
		}
		
	}

}
