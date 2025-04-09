public class alumnosSuspensos {

	public static void main(String[] args) {
		int[] n = {4,6,8,1,10};
		int s=0;
		boolean suspensos;
		suspensos = false;
		for (int i = 0; i<5; i++){
			System.out.print("Introduzca nota (de 0 a 10): ");
			System.out.println(n[i]);
			if (n[i]<5) {
				suspensos=true;
				s++;
			}
		}
		if(suspensos)
			System.out.println("Hay alumnos suspensos " + s);
		else
			System.out.println("No hay suspensos");
	}

}