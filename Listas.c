//  Sesión 21 - 04/10/2022
#include "Listas.h"

int main()
{	
	nodo *nombre = NULL;
	nodo *apellido = NULL;
	char dato;
	system("color 1E");

	imprimeLista(nombre);

	nombre = insert(nombre, 'R');
	nombre = insert(nombre, 'o');
	nombre = insert(nombre, 'b');
	nombre = insert(nombre, 'e');
	nombre = insert(nombre, 'r');
	nombre = insert(nombre, 't');
	nombre = insert(nombre, 'o');

	apellido = insert1(apellido, 'S');
	apellido = insert1(apellido, 'a');
	apellido = insert1(apellido, 'l');
	apellido = insert1(apellido, 'a');
	apellido = insert1(apellido, 'z');
	apellido = insert1(apellido, 'a');
	apellido = insert1(apellido, 'r');
	apellido = insertn(apellido, 'x', 5);

	/*insertn('z', 40);*/

	imprimeLista(nombre);
	imprimeLista(apellido);

	nombre = remueve(nombre, &dato);
	printf("Salio de la lista: %c \n", dato );
	imprimeLista(nombre);

	apellido = remueve1(apellido, &dato);
	printf("Salio de la lista: %c \n", dato );
	imprimeLista(apellido);

	nombre = remueven(nombre, 3, &dato);
	printf("Salio de la lista: %c \n", dato );
	imprimeLista(nombre);

	
	pausa;
	return 0;
}


