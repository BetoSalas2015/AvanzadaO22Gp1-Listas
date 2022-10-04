//  Sesión 21 - 04/10/2022
#include <stdio.h>				//  Para la I/O de programa
#include <stdlib.h>				//  Para las rutinas de utileria
#include <malloc.h>				//  Para la gestió	n de memoria dinámica

//  Macros
#define pausa system("pause")
#define cls system("cls")

struct Nodo 
{
	char info;
	struct Nodo *sig;
} *raiz = NULL;						// Creamos la lista vacía o nula

typedef struct Nodo nodo;			//  Definimos formalemtne el nuevo tipo de dato nodo

//  Primitivas de la lista ligada
nodo *insert(nodo *raiz, char dato)
{
	nodo *nuevo = NULL;
	nuevo = (nodo *) malloc( sizeof(nodo) );
	if( nuevo == NULL )				//  No hay memoria disponible
	{
		printf("Nohay memoria disponible! \n");
		pausa;
		exit(1);		//	Código de error personalizado 1. No hay memoria
	}
	nuevo -> info = dato;		//  Preservamos la información en la lista
	if( raiz == NULL )			//  Lista vacía, no hay nodos
	{
		raiz = nuevo;			//  Insertamos el nodo en la lista
		raiz ->sig = NULL;		//  Se vuelve el último nodo de la lista
	}
	else				//  La lista no esta vacía, hay al menos 1 nodo
	{
		nodo *recorre = raiz;
		while(recorre ->sig != NULL)		// Estoy posicionado en el ultimo nodo?
		{
			recorre = recorre-> sig; 
		}
		recorre->sig = nuevo;		// Insertamos el nodo en la lista ligada
		nuevo ->sig = NULL;
	}
	return raiz;
}

void insert1(char dato)
{
	nodo *nuevo = NULL;
	nuevo = (nodo *) malloc( sizeof(nodo) );
	if( nuevo == NULL )				//  No hay memoria disponible
	{
		printf("Nohay memoria disponible! \n");
		pausa;
		exit(1);		//	Código de error personalizado 1. No hay memoria
	}
	nuevo -> info = dato;		//  Preservamos la información en la lista
	nuevo->sig = raiz;
	raiz = nuevo;			//  Insertamos el nodo en la lista
}

void insertn(char dato, int n)
{
	nodo *nuevo = NULL;
	nuevo = (nodo *) malloc( sizeof(nodo) );
	if( nuevo == NULL )				//  No hay memoria disponible
	{
		printf("No hay memoria disponible! \n");
		pausa;
		exit(1);		//	Código de error personalizado 1. No hay memoria
	}
	nuevo -> info = dato;		//  Preservamos la información en la lista
	if( raiz == NULL )			//  Lista vacía, no hay nodos
	{
		raiz = nuevo;			//  Insertamos el nodo en la lista
		raiz ->sig = NULL;		//  Se vuelve el último nodo de la lista
		return;					//  Ya inserté el nodo. se acabo!
	}
	if( n == 1)
	{
		nuevo -> info = dato;		//  Preservamos la información en la lista
		nuevo->sig = raiz;
		raiz = nuevo;			//  Insertamos el nodo en la lista
	}
	else				//  La lista no esta vacía, hay al menos 1 nodo
	{
		nodo *recorre = raiz;
		int cont = 1;
		while(recorre ->sig != NULL && cont < n - 1 )		// Estoy posicionado en el ultimo nodo?
		{
			recorre = recorre-> sig; 
			cont++;
		}
		nuevo->sig = recorre->sig;
		recorre->sig = nuevo;		// Insertamos el nodo en la lista ligada
	}
}

void imprimeLista(nodo *raiz)
{
	nodo *recorre = raiz;
	while(recorre != NULL)		// Estoy posicionado en el ultimo nodo?
	{
		printf("%c, ", recorre->info );
		recorre = recorre-> sig; 
	}
	putchar('\n');
}

char remueve()
{
	nodo *recorre = raiz;
	char dato;
	if( recorre == NULL)				//  La lista está vacia
	{
		printf("La lista está vacía, no hay nada que remover.\n");
		pausa;
		return '\0';
	}
	if(	recorre->sig == NULL )			// Estoy posicionado en el último
	{
		dato = recorre->info;			//  Preservo el dato
		raiz = NULL;					//  Vacio la lista
		free(recorre);					//  Libero memoria reservada por malloc()
		return dato;					//  Regresamos el dato extraído de la lista
	}
	else
	{
		nodo *ultimo = recorre->sig;	//  Posicionamos ultimo en el "ultimo?"
		while( ultimo->sig != NULL)		// No estoy posicionado en el ultimo?
		{
			recorre = recorre->sig;		//  Recorre avanza al siguiente
			ultimo = ultimo->sig;		//  Ultimo avanza al siguiente
		}
		recorre->sig = NULL;			//  Recorre se vuelve el últmo nodo
		dato = ultimo->info;			//  Preservo la información
		free(ultimo);					//  Libero memoria reservada por malloc()
		return dato;					//  Regresamos el dato extraído de la lista
	}
}

char remueven(int n)
{
	nodo *recorre = raiz;
	char dato;
	if( recorre == NULL)				//  La lista está vacia
	{
		printf("La lista está vacía, no hay nada que remover.\n");
		pausa;
		return '\0';
	}
	if(	n == 1 )			// Estoy posicionado en el último
	{
		dato = recorre->info;			//  Preservo el dato
		raiz = raiz ->sig;				//  Nos movemos al siquiente de raiz (nodo o NULL)
		free(recorre);					//  Libero memoria reservada por malloc()
		return dato;					//  Regresamos el dato extraído de la lista
	}
	else
	{
		int cont = 1;
		nodo *ultimo = recorre->sig;	//  Posicionamos ultimo en el "ultimo?"
		while( recorre->sig != NULL && cont < n - 1 )		// No estoy posicionado en el ultimo?
		{
			recorre = recorre->sig;		//  Recorre avanza al siguiente
			ultimo = ultimo->sig;		//  Ultimo avanza al siguiente
			cont++;
		}
		if( cont < n - 1)
		{
			printf("No hay nodo para borrar\n");
			return '\0';
		}
		recorre->sig = ultimo->sig;			//  desligamos el nodo
		dato = ultimo->info;			//  Preservo la información
		free(ultimo);					//  Libero memoria reservada por malloc()
		return dato;					//  Regresamos el dato extraído de la lista
	}
}

char remueve1()
{
	nodo *recorre = raiz;
	char dato;
	if( recorre == NULL)				//  La lista está vacia
	{
		printf("La lista está vacía, no hay nada que remover.\n");
		pausa;
		return '\0';
	}
	dato = recorre->info;			//  Preservo el dato
	raiz = raiz->sig;				//  apunto a lo que sigue (null u otro nodo)
	free(recorre);					//  Libero memoria reservada por malloc()
	return dato;					//  Regresamos el dato extraído de la lista
}	

int main()
{	
	nodo *nombre = NULL;
	nodo *apellido = NULL;
	system("color 1E");

	imprimeLista(nombre);

	nombre = insert(nombre, 'R');
	nombre = insert(nombre, 'o');
	nombre = insert(nombre, 'b');
	nombre = insert(nombre, 'e');
	nombre = insert(nombre, 'r');
	nombre = insert(nombre, 't');
	nombre = insert(nombre, 'o');

	apellido = insert(apellido, 'S');
	apellido = insert(apellido, 'a');
	apellido = insert(apellido, 'l');
	apellido = insert(apellido, 'a');
	apellido = insert(apellido, 'z');
	apellido = insert(apellido, 'a');
	apellido = insert(apellido, 'r');

	/*insertn('z', 40);*/

	imprimeLista(nombre);
	imprimeLista(apellido);

	/*printf("Salio de la lista: %c \n", remueve() );

	imprimeLista();

	printf("Salio de la lista: %c \n", remueve1() );

	imprimeLista();
	printf("Salio de la lista: %c \n", remueven(40) );

	imprimeLista();*/

	
	pausa;
	return 0;
}


