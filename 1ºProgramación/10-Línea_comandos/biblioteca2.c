#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * 	Author: Arnau Blanch
 */

// Defines //
#define BOOKS_QUANTITY 40
#define MAX_AUTHOR_LENGHT 50
#define MAX_TITLE_LENGHT 80

// Las categorías en forma de enum //
typedef enum {
	FICTION,	// 0
	NON_FICTION,// 1
	POETRY,		// 2
	THEATER,	// 3
	ESSAY		// 4
} Category;
// Un struct de Book //
typedef struct{
	int id;
	char title[MAX_TITLE_LENGHT];
	char author[MAX_AUTHOR_LENGHT];
	float price;
	Category gender;
	int quantity;
} Book;

void show_book(const Book const * one_book){ //Sirve para mostrar toda la información del libro al que apunte la dirección de memoria que le pasan.
	printf("ID: %d\n", one_book->id);
	printf("\tTítulo: %s\n", one_book->title);
	printf("\tAutor: %s\n", one_book->author);
	printf("\tPrecio: %.2f\n", one_book->price);
	// Aquí hago un switch para escribir cada categoría en vez de su número.
	switch(one_book->gender){
		case 0: 
			printf("\tCategoría: FICTION\n");
			break;
		case 1: 
			printf("\tCategoría: NON_FICTION\n");
			break;
		case 2: 
			printf("\tCategoría: POETRY\n");
			break;
		case 3: 
			printf("\tCategoría: THEATER\n");
			break;
		case 4: 
			printf("\tCategoría: ESSAY\n");
			break;
	}
	printf("\tCantidad: %d\n", one_book->quantity);
}

void show_book_by_author(Book const * author_book){ // Pongo la constante en el contenido del puntero porque me estáré moviendo entre las direcciones de memoria pero no queiro modificar su contenido.
	char search_author[MAX_AUTHOR_LENGHT];
	int author_length;
	int string_length;

	printf("Dime un autor y yo te diré sus libros: ");
	scanf(" "); // Este scanf sirve para reiniciar el buffer y eliminar el \n que había después de buscar la categoría.
	fgets(search_author, sizeof(search_author), stdin); // Sirve para pedir al usuario una cadena de caracteres que pueda incluir espacios.
	author_length = strlen(search_author)-1; // Uso strlen para saber su longitud pero también me cuenta el \n así que le resto 1.

	for (int i = 0; i < BOOKS_QUANTITY; ++i){
		if(strlen(author_book->author) <= author_length){ // Esta comparación sirve para comprobar que el autor que estoy buscando tiene una longitud mayor al autor del libro que voy a comparar.
			string_length = 0;
		} else {
			string_length = strlen(author_book->author) - author_length; // Esta resta sirve para comparar hasta la longitud del libro que estoy comparando menos la longitud del libro que quiero buscar. Si no lo hiciera estaría accediendo a los siguientes caracteres que se salen del libro que quiero buscar.
		}
		for (int j = 0; j <= string_length; ++j){ // Hay que poner <= porque si no, no llega a la comparación que debe.
			// printf("i: %d j: %d\n", i,j); // Esto lo he puesto para depurar errores.
			if (strncmp(search_author, author_book->author+j, author_length) == 0){ // search_author tiene más cosas después del \0 así que tengo que comparar hasta ese caracter (uso strncmp) pero la longitud del autor varía así que uso la variable author_length
				show_book(author_book);
			}
		}
		author_book++; // Paso al siguiente libro.
	}
}

void show_book_by_category(Book const * first_book){ // Pongo la constante en el contenido del puntero porque me estáré moviendo entre las direcciones de memoria pero no queiro modificar su contenido.
	int category_number;
    printf("Dime una categoría (1, 2, 3, 4 o 5) y yo te mostraré todos sus libros: ");
    scanf("%d", &category_number);
	for (int i = 0; i < BOOKS_QUANTITY; ++i){
		if (category_number-1 == first_book->gender){ // Pongo -1 porque yo pido al usuario números del 1 al 5 en vez del 0 al 4. Pongo -> porque first_book es una dirección de memoria.
			show_book(first_book);
		}
		first_book++; // Paso a buscar al siguiente libro.
	}
}

Book * search_one_id(Book const * one_id, int id_number){ // Es una función Book * porque devuelvo un puntero a Book.
	if(id_number > BOOKS_QUANTITY || id_number <= 0){ // Si no encuentro el id, muestro un mensaje de error.
    	printf("ERROR, no existe ese id\n");
    } else {
    	for (int i = 0; i < BOOKS_QUANTITY; ++i){
		    	if(id_number == one_id->id){ // También podría poner one_id[i].id si no incrementara después de cada vuelta.
		    		return one_id; // Cuando encuentro el ID lo devuelvo y acabo el bucle.
		    		break; // Como sólo hay un ID salgo del bucle.
		    	}
		    	one_id++; // Tengo que ir aumentando la dirección de memoria para buscar en todo el array y no apuntar simepre al primer elemento.
		    }
    }
}

void modify_stock(const Book * book_stock){
	int another_id, stock_quantity;
	Book * book_to_change;
	printf("Vamos a modificar el stock de los libros, escribe el ID que quieras: ");
	scanf("%d", &another_id);
	book_to_change = search_one_id(book_stock, another_id);
	if(another_id <= BOOKS_QUANTITY && another_id > 0){ // Compruebo que el ID exista para modificar su stock.
		printf("Ésta es la información inicial: \n");
		show_book(book_to_change);
		printf("Cuánto quieres añadir a la cantidad? ");
		scanf("%d", &stock_quantity);
		book_to_change->quantity += stock_quantity; // Añado la cantidad que quiera el usuario sobre lo que ya había.
		printf("Ésta es la información final: \n");
		show_book(book_to_change);
	}
}

void show_book_by_id(Book const * idbook){
	int identification;
	Book * the_id;

	printf("Dime un ID y yo te mostraré la información de ese libro: ");
    scanf("%d", &identification);
    
    the_id = search_one_id(idbook, identification); // Me devuelve la dirección de memoria del libro que tiene el ID que le he pasado.
    if(identification <= BOOKS_QUANTITY && identification > 0){
    	show_book(the_id);
    }
}

void show_n_books(Book const * n_books, int max){ // Recibe la dirección de memoria en la que empieza el bucle y el número de vueltas que tiene que dar. 
	for (int i = 0; i < max; ++i){
		show_book(n_books+i); // Muestra el libro correspondiente
	}
}

int main(int argumento_count, char ** argumento_value){

	Book books[BOOKS_QUANTITY] = {
        {1, "To Kill a Mockingbird", "Harper Lee", 15.99, FICTION, 10},
        {2, "1984", "George Orwell", 12.49, FICTION, 5},
        {3, "The Great Gatsby", "F. Scott Fitzgerald", 10.99, FICTION, 8},
        {4, "Moby Dick", "Herman Melville", 18.99, FICTION, 12},
        {5, "War and Peace", "Leo Tolstoy", 20.00, FICTION, 7},
        {6, "Pride and Prejudice", "Jane Austen", 14.99, FICTION, 9},
        {7, "The Catcher in the Rye", "J.D. Salinger", 10.00, FICTION, 6},
        {8, "The Odyssey", "Homer", 17.49, FICTION, 4},
        {9, "Ulysses", "James Joyce", 25.00, FICTION, 2},
        {10, "The Divine Comedy", "Dante Alighieri", 22.00, POETRY, 3},
        {11, "Leaves of Grass", "Walt Whitman", 13.00, POETRY, 11},
        {12, "The Iliad", "Homer", 18.50, FICTION, 7},
        {13, "A Brief History of Time", "Stephen Hawking", 15.00, NON_FICTION, 15},
        {14, "The Art of War", "Sun Tzu", 9.99, NON_FICTION, 20},
        {15, "Sapiens: A Brief History of Humankind", "Yuval Noah Harari", 16.49, NON_FICTION, 13},
        {16, "The Selfish Gene", "Richard Dawkins", 14.00, NON_FICTION, 6},
        {17, "The Road to Serfdom", "F.A. Hayek", 10.50, NON_FICTION, 5},
        {18, "The Wealth of Nations", "Adam Smith", 30.00, NON_FICTION, 8},
        {19, "On the Origin of Species", "Charles Darwin", 24.99, NON_FICTION, 4},
        {20, "The Prince", "Niccolò Machiavelli", 8.99, NON_FICTION, 14},
        {21, "Hamlet", "William Shakespeare", 11.50, THEATER, 6},
        {22, "Macbeth", "William Shakespeare", 9.50, THEATER, 8},
        {23, "Othello", "William Shakespeare", 10.99, THEATER, 7},
        {24, "A Doll's House", "Henrik Ibsen", 12.50, THEATER, 5},
        {25, "Waiting for Godot", "Samuel Beckett", 13.99, THEATER, 4},
        {26, "Death of a Salesman", "Arthur Miller", 14.99, THEATER, 10},
        {27, "The Glass Menagerie", "Tennessee Williams", 11.00, THEATER, 9},
        {28, "Long Day's Journey into Night", "Eugene O'Neill", 19.50, THEATER, 3},
        {29, "The Importance of Being Earnest", "Oscar Wilde", 8.50, THEATER, 15},
        {30, "The Waste Land", "T.S. Eliot", 6.99, POETRY, 10},
        {31, "Paradise Lost", "John Milton", 12.00, POETRY, 7},
        {32, "Beowulf", "Anonymous", 15.00, POETRY, 5},
        {33, "Essays", "Michel de Montaigne", 20.00, ESSAY, 4},
        {34, "Self-Reliance and Other Essays", "Ralph Waldo Emerson", 9.00, ESSAY, 9},
        {35, "Civil Disobedience and Other Essays", "Henry David Thoreau", 7.50, ESSAY, 11},
        {36, "Meditations", "Marcus Aurelius", 11.99, ESSAY, 8},
        {37, "The Federalist Papers", "Alexander Hamilton, James Madison, John Jay", 18.00, ESSAY, 5},
        {38, "The Communist Manifesto", "Karl Marx and Friedrich Engels", 5.99, ESSAY, 12},
        {39, "The Republic", "Plato", 16.00, ESSAY, 6},
        {40, "Thus Spoke Zarathustra", "Friedrich Nietzsche", 14.99, ESSAY, 10}
    };

    printf("Lista de argumentos:%s\n", *argumento_value);
    for(int i = 0; i<argumento_count; i++){
    	printf("\t Argumento %d: %s\n", i, argumento_value[i]);
    }
    if (argumento_count > 1){
    	switch(**argumento_value){
    	case 0: 
    		break;
    	}
    } else {
// Muestro todo el catálogo //
    printf("Voy a mostrar todos los libros:\n");
    show_n_books(&books[0], BOOKS_QUANTITY); // Paso la dirección de memoria en la que tiene que empezar y la cantidad que tiene que imprimir.

// Muestro la info de un libro a partir de un ID //
    show_book_by_id(&books[0]);    

// Pido al usuario que cambie la cantidad de un libro por ID //
    modify_stock(&books[0]);

// Muestro todos los libros que pertenecen a una categoría //
    show_book_by_category(&books[0]);

// Muestro todos los libros que pertenecen a un autor //
    show_book_by_author(&books[0]);
	}


	return EXIT_SUCCESS;
}