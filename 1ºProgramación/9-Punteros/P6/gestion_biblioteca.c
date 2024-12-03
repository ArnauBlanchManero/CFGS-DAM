#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * 	Author: Arnau Blanch
 */

// Defines //
#define BOOKS_QUANTITY 40

// Las categorías en forma de enum //
typedef enum {
	FICTION,	// 1
	NON_FICTION,// 2
	POETRY,		// 3
	THEATER,	// 4
	ESSAY		// 5
} Category;
// Un struct de Book //
typedef struct{
	int id;
	char title[80];
	char author[50];
	float price;
	Category gender;
	int quantity;
} Book;

void show_book(const Book const * one_book){ //Sirve para mostrar toda la info del libro al que apunte la dirección de memoria que le pasan.
	printf("ID: %d ", one_book->id);
	printf("Título: %s ", one_book->title);
	printf("Autor: %s ", one_book->author);
	printf("Precio: %.2f ", one_book->price);
	// Aquí puedo hacer un switch para escribir cada categoría.
	printf("Categoría: %d ", one_book->gender);
	printf("Cantidad: %d\n", one_book->quantity);
}

void show_book_by_category(Book const * first_book){
	int category_number;
    printf("Dime una categoría (1, 2, 3, 4 o 5) y yo te mostraré todos sus libros: ");
    scanf("%d", &category_number);
	for (int i = 0; i < BOOKS_QUANTITY; ++i){
		if (category_number-1 == first_book->gender){ // Pongo -1 porque yo pido al usuario números del 1 al 5 en vez del 0 al 4.
			show_book(first_book);
		}
		first_book++;
	}
}

void show_book_by_id(Book const * idbook){
	int identification;
	printf("Dime un ID y yo te mostraré la información de ese libro: ");
    scanf("%d", &identification);
    
    if(identification > BOOKS_QUANTITY || identification <= 0){
    	printf("ERROR, no existe ese id\n"); // Si no encuentro el id, muestro un mensaje de error.
    } else {
    	for (int i = 0; i < BOOKS_QUANTITY; ++i){
	    	if(identification == idbook->id){
	    		show_book(idbook); // Cuando encuentro el ID lo imprimo y acabo el bucle.
	    		break;
	    	}
	    	idbook++; // Tengo que ir aumentando la dirección de memoria para buscar en todo el array.
	    }
    }
}

void show_n_books(Book const * n_books, int max){ // Recibe la dirección de memoria en la que empieza el bucle y el número de vueltas que tiene que dar. 
	for (int i = 0; i < max; ++i){
		show_book(n_books+i); // Muestra el libro correspondiente
	}
}

int main(){

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

// Muestro todo el catálogo //
    printf("Voy a mostrar todos los libros:\n");
    show_n_books(&books[0], BOOKS_QUANTITY); // Paso la dirección de memoria en la que tiene que empezar y la cantidad que tiene que imprimir.

// Muestro la info de un libro a partir de un ID //
    show_book_by_id(&books[0]);    

// Muestro todos los libros que pertenecen a una categoría //
    show_book_by_category(&books[0]);

	return EXIT_SUCCESS;
}
