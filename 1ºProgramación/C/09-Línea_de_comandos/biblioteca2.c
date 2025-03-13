#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * 	Author: Arnau Blanch
 */

// Defines //
#define MAX_AUTHOR_LENGHT 50
#define MAX_TITLE_LENGHT 80
int books_quantity = 0;

// Las categorías en forma de enum //
typedef enum {
	FICTION,	// 0
	NON_FICTION,	// 1
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

// De numero a palabra y de palabra a número (categoria)

void show_book(const Book const * one_book){ //Sirve para mostrar toda la información del libro al que apunte la dirección de memoria que le pasan.
	printf("ID: %d\n", one_book->id);
	printf("\tTitle: %s\n", one_book->title);
	printf("\tAuthor: %s\n", one_book->author);
	printf("\tPrice: %.2f\n", one_book->price);
	// Aquí hago un switch para escribir cada categoría en vez de su número.
	switch(one_book->gender){
		case 0: 
			printf("\tCategory: FICTION\n");
			break;
		case 1: 
			printf("\tCategory: NON_FICTION\n");
			break;
		case 2: 
			printf("\tCategory: POETRY\n");
			break;
		case 3: 
			printf("\tCategory: THEATER\n");
			break;
		case 4: 
			printf("\tCategory: ESSAY\n");
			break;
	}
	printf("\tQuantity: %d\n", one_book->quantity);
}

void show_book_by_author(Book const * author_book, char * search_author, int author_size){ // Pongo la constante en el contenido del puntero porque me estáré moviendo entre las directiones de memoria pero no queiro modificar su contenido.
	int author_length;
	int string_length;
	author_length = author_size-1; // Usaba strlen para saber su longitud pero también me cuenta el \n así que le resto 1.

	for (int i = 0; i < books_quantity; ++i){
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

void show_book_by_category(Book const * first_book, int category_number){ // Pongo la constante en el contenido del puntero porque me estáré moviendo entre las directiones de memoria pero no queiro modificar su contenido.
	for (int i = 0; i < books_quantity; ++i){
		if (category_number-1 == first_book->gender){ // Pongo -1 porque yo pido al usuario números del 1 al 5 en vez del 0 al 4. Pongo -> porque first_book es una dirección de memoria.
			show_book(first_book);
		}
		first_book++; // Paso a buscar al siguiente libro.
	}
}

Book * search_one_id(Book const * one_id, int id_number){ // Es una función Book * porque devuelvo un puntero a Book.
	if(id_number > books_quantity || id_number <= 0){ // Si no encuentro el id, muestro un mensaje de error.
    	printf("ERROR, it doesn't exist that id\n");
    } else {
    	for (int i = 0; i < books_quantity; ++i){
		    	if(id_number == one_id->id){ // También podría poner one_id[i].id si no incrementara después de cada vuelta.
		    		return one_id; // Cuando encuentro el ID lo devuelvo y acabo el bucle.
		    		break; // Como sólo hay un ID salgo del bucle. (no hace falta ponerlo porque al haber un return se acaba el bucle igual)
		    	}
		    	one_id++; // Tengo que ir aumentando la dirección de memoria para buscar en todo el array y no apuntar simepre al primer elemento.
		    }
    }
}

void modify_stock(const Book * book_stock, int another_id, int stock_quantity){
	Book * book_to_change;
	book_to_change = search_one_id(book_stock, another_id);
	if(another_id <= books_quantity && another_id > 0){ // Compruebo que el ID exista para modificar su stock.
		printf("This is the initial information: \n");
		show_book(book_to_change);
		book_to_change->quantity += stock_quantity; // Añado la cantidad que quiera el usuario sobre lo que ya había.
		printf("This is the final information: \n");
		show_book(book_to_change);
	}
}

void show_book_by_id(Book const * idbook){
	int identification;
	Book * the_id;

	printf("Write an id and I'll show you the information: ");
    scanf("%d", &identification);
    
    the_id = search_one_id(idbook, identification); // Me devuelve la dirección de memoria del libro que tiene el ID que le he pasado.
    if(identification <= books_quantity && identification > 0){
    	show_book(the_id);
    }
}

void show_n_books(Book const * n_books, int max){ // Recibe la dirección de memoria en la que empieza el bucle y el número de vueltas que tiene que dar. 
	for (int i = 0; i < max; ++i){
		show_book(n_books+i); // Muestra el libro correspondiente
	}
}

Book * add_book(Book * direction, int add_id, char * add_title, char * add_author, float add_price, int add_gender, int add_quantity){
	direction = (Book *) realloc(direction, sizeof(Book) * (books_quantity+1)); // Pongo +1 porque se inicializa en 0
	if(direction == NULL) exit(1);
	direction[books_quantity].id = add_id;
	strcpy(direction[books_quantity].title, add_title);
	strcpy(direction[books_quantity].author, add_author);
	direction[books_quantity].price = add_price;
	direction[books_quantity].gender = add_gender;
	direction[books_quantity].quantity = add_quantity;
	books_quantity++; // Ya he añadido un libro y lo aumento en uno
	return direction;
}

Book * pedir_libro(Book * direction_to_send){
	int new_id, new_quantity, new_gender;
	char new_title[MAX_TITLE_LENGHT];
	char new_author[MAX_AUTHOR_LENGHT];
	float new_price;
	printf("Write the information of the new book:\n");
	printf("ID: ");
	scanf(" %d", &new_id);
	printf("Title: ");
	scanf(" %[^\n]", new_title);
	printf("Author: ");
	scanf(" %[^\n]", new_author);
	printf("Price: ");
	scanf(" %f", &new_price);
	printf("Gender (0 -> FICTION, 1 -> NON_FICTION, 2 -> POETRY, 3 -> THEATER, 4 -> ESSAY): ");
	scanf(" %d", &new_gender);
	printf("Quantity: ");
	scanf(" %d", &new_quantity);
	return add_book(direction_to_send, new_id, new_title, new_author, new_price, new_gender, new_quantity);
}

int show_P6(Book * book1){
	int option;
	printf("Menu\n");
	printf("\t1 - Show all the books\n\t2 - Show one book by ID\n\t3 - Modify the stock\n\t4 - Search books by category\n\t5 - Search books written by one author\n\t6 - Exit\nOption: ");
	scanf("%d", &option);
	switch (option){
		case 1:
		// Muestro todo el catálogo //
		    printf("All the books:\n");
		    show_n_books(book1, books_quantity); // Paso la dirección de memoria en la que tiene que empezar y la cantidad que tiene que imprimir.
			break;
		case 2:
		// Muestro la info de un libro a partir de un ID //
		    show_book_by_id(book1);   
			break;
		case 3:
		// Pido al usuario que cambie la cantidad de un libro por ID //
		    int id_stock, quantity_change;
			printf("Write the ID of the book whose stock you want to change: ");
			scanf("%d", &id_stock);
			printf("How much do you want to add? ");
			scanf("%d", &quantity_change);
		    modify_stock(book1, id_stock, quantity_change);
			break;
		case 4:
		// Muestro todos los libros que pertenecen a una categoría //
		    int number_of_category;
			printf("Write the number of one category\n1 -> FICCTION\n2 -> NON_FICTION\n3 -> POETRY\n4 -> THEATER\n5 -> ESSAY\nAll books with that category: ");
			scanf("%d", &number_of_category);
		    show_book_by_category(book1, number_of_category);
			break;
		case 5:
		// Muestro todos los libros que pertenecen a un autor //
		    char author_name[MAX_AUTHOR_LENGHT];
		    int author_length;
			printf("Write an author and I'll show you his books: ");
			scanf(" "); // Este scanf sirve para reiniciar el buffer y eliminar el \n que había después de buscar la categoría.
			fgets(author_name, sizeof(author_name), stdin); // Sirve para pedir al usuario una cadena de caracteres que pueda incluir espacios.
			author_length = strlen(author_name)-1;
		    show_book_by_author(book1, author_name, author_length);
			break;
		case 6:
			return 1;
			break;
	}
	return 0;
}

int main(int argc, char ** argv){ // int argumento_count, char ** argumento_value
	printf("Welcome to the library!\n");
	Book * books = (Book *) malloc(sizeof(Book));
	// Titulo y autor tambien pueden ser memoria dinámica
    books = add_book(books, 1, "To Kill a Mockingbird", "Harper Lee", 15.99, FICTION, 10);
    books = add_book(books, 2, "1984", "George Orwell", 12.49, FICTION, 5);
    books = add_book(books, 3, "The Great Gatsby", "F. Scott Fitzgerald", 10.99, FICTION, 8);
    books = add_book(books, 4, "Moby Dick", "Herman Melville", 18.99, FICTION, 12);
    books = add_book(books, 5, "War and Peace", "Leo Tolstoy", 20.00, FICTION, 7);
    books = add_book(books, 6, "Pride and Prejudice", "Jane Austen", 14.99, FICTION, 9);
    books = add_book(books, 7, "The Catcher in the Rye", "J.D. Salinger", 10.00, FICTION, 6);
    books = add_book(books, 8, "The Odyssey", "Homer", 17.49, FICTION, 4);
    books = add_book(books, 9, "Ulysses", "James Joyce", 25.00, FICTION, 2);
    books = add_book(books, 10, "The Divine Comedy", "Dante Alighieri", 22.00, POETRY, 3);
    books = add_book(books, 11, "Leaves of Grass", "Walt Whitman", 13.00, POETRY, 11);
    books = add_book(books, 12, "The Iliad", "Homer", 18.50, FICTION, 7);
    books = add_book(books, 13, "A Brief History of Time", "Stephen Hawking", 15.00, NON_FICTION, 15);
    books = add_book(books, 14, "The Art of War", "Sun Tzu", 9.99, NON_FICTION, 20);
    books = add_book(books, 15, "Sapiens: A Brief History of Humankind", "Yuval Noah Harari", 16.49, NON_FICTION, 13);
    books = add_book(books, 16, "The Selfish Gene", "Richard Dawkins", 14.00, NON_FICTION, 6);
    books = add_book(books, 17, "The Road to Serfdom", "F.A. Hayek", 10.50, NON_FICTION, 5);
    books = add_book(books, 18, "The Wealth of Nations", "Adam Smith", 30.00, NON_FICTION, 8);
    books = add_book(books, 19, "On the Origin of Species", "Charles Darwin", 24.99, NON_FICTION, 4);
    books = add_book(books, 20, "The Prince", "Niccolò Machiavelli", 8.99, NON_FICTION, 14);
    books = add_book(books, 21, "Hamlet", "William Shakespeare", 11.50, THEATER, 6);
    books = add_book(books, 22, "Macbeth", "William Shakespeare", 9.50, THEATER, 8);
    books = add_book(books, 23, "Othello", "William Shakespeare", 10.99, THEATER, 7);
    books = add_book(books, 24, "A Doll's House", "Henrik Ibsen", 12.50, THEATER, 5);
    books = add_book(books, 25, "Waiting for Godot", "Samuel Beckett", 13.99, THEATER, 4);
    books = add_book(books, 26, "Death of a Salesman", "Arthur Miller", 14.99, THEATER, 10);
    books = add_book(books, 27, "The Glass Menagerie", "Tennessee Williams", 11.00, THEATER, 9);
    books = add_book(books, 28, "Long Day's Journey into Night", "Eugene O'Neill", 19.50, THEATER, 3);
    books = add_book(books, 29, "The Importance of Being Earnest", "Oscar Wilde", 8.50, THEATER, 15);
    books = add_book(books, 30, "The Waste Land", "T.S. Eliot", 6.99, POETRY, 10);
    books = add_book(books, 31, "Paradise Lost", "John Milton", 12.00, POETRY, 7);
    books = add_book(books, 32, "Beowulf", "Anonymous", 15.00, POETRY, 5);
    books = add_book(books, 33, "Essays", "Michel de Montaigne", 20.00, ESSAY, 4);
    books = add_book(books, 34, "Self-Reliance and Other Essays", "Ralph Waldo Emerson", 9.00, ESSAY, 9);
    books = add_book(books, 35, "Civil Disobedience and Other Essays", "Henry David Thoreau", 7.50, ESSAY, 11);
    books = add_book(books, 36, "Meditations", "Marcus Aurelius", 11.99, ESSAY, 8);
    books = add_book(books, 37, "The Federalist Papers", "Alexander Hamilton, James Madison, John Jay", 18.00, ESSAY, 5);
    books = add_book(books, 38, "The Communist Manifesto", "Karl Marx and Friedrich Engels", 5.99, ESSAY, 12);
    books = add_book(books, 39, "The Republic", "Plato", 16.00, ESSAY, 6);
    books = add_book(books, 40, "Thus Spoke Zarathustra", "Friedrich Nietzsche", 14.99, ESSAY, 10);

	if (argc == 1){ // El primer argumento es el ejecutable .out
		int exit = 0;
		while (exit == 0){
			exit = show_P6(&books[0]);
		}
	} else if (argc == 2){ // Puede que haya escrito mostar o añadir
			if(strcmp(argv[1], "mostrar") == 0){
				show_n_books(&books[0], books_quantity);
			} else if (strcmp(argv[1], "añadir") == 0){
				books = pedir_libro(books);
				show_n_books(&books[0], books_quantity);
			}
	} else if (argc == 3){ // Hay que diferenciar entre mostrar, categoría o autor
			if(strcmp(argv[1], "mostrar") == 0){
				int id_mostar = atoi(argv[2]);
				show_book(&books[id_mostar-1]);
			} else if (strcmp(argv[1], "categoria") == 0){
			    printf("1 -> FICCTION\n2 -> NON_FICTION\n3 -> POETRY\n4 -> THEATER\n5 -> ESSAY\n");
				int category_number_arg = atoi(argv[2]);
			    show_book_by_category(&books[0], category_number_arg);
			} else if (strcmp(argv[1], "autor") == 0){
				int author_length_arg;
				author_length_arg = strlen(argv[2])-1;
				show_book_by_author(&books[0], argv[2], author_length_arg);
			}
	} else if (argc >= 4){
			if(strcmp(argv[1], "stock") == 0){
				int id_stock_arg = atoi(argv[2]);
				int quantity_stock_arg = atoi(argv[3]);
				modify_stock(&books[0], id_stock_arg, quantity_stock_arg);
			}
	}
	free(books);
	return EXIT_SUCCESS;
}