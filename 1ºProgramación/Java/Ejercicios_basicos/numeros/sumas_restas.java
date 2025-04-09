public class sumas_restas {

	public static void main(String[] args) {
		int a=1, b=2, c=3;
		b= ++c;
		imprimir(a,b,c);
		a += b++;
		imprimir(a,b,c);
		a = a+++a;
		imprimir(a,b,c);
		a -= b--;
		imprimir(a,b,c);
		c = a++ - ++b;
		imprimir(a,b,c);
		c -= ++a;
		imprimir(a,b,c);
		a -= ++c;
		imprimir(a,b,c);
		a -= c++;
		imprimir(a,b,c);
		a -= --c;
		imprimir(a,b,c);

	}
	static void imprimir(int a, int b, int c) {
		System.out.println("a=" + a + " b=" + b + " c=" + c);
	}

}