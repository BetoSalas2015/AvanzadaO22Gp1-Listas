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

nodo *insert1(nodo *raiz, char dato)
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
	return raiz;
}

nodo *insertn(nodo *raiz, char dato, int n)
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
		return raiz;					//  Ya inserté el nodo. se acabo!
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
	return raiz;
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

nodo *remueve(nodo *raiz, char *dato)
{
	nodo *recorre = raiz;
	if( recorre == NULL)				//  La lista está vacia
	{
		printf("La lista está vacía, no hay nada que remover.\n");
		pausa;
		return NULL;
	}
	if(	recorre->sig == NULL )			// Estoy posicionado en el último
	{
		*dato = recorre->info;			//  Regresamos el dato extraído de la lista
		raiz = NULL;					//  Vacio la lista
		free(recorre);					//  Libero memoria reservada por malloc()
		return raiz;					//  Regresamos la raiz de la lista manipulada
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
		*dato = ultimo->info;			//  Regresamos el dato extraído de la lista
		free(ultimo);					//  Libero memoria reservada por malloc()
		return raiz;					//  Regresamos la raiz de la lista manipulada
	}
}

nodo *remueven(nodo *raiz, int n, char *dato)
{
	nodo *recorre = raiz;
	if( recorre == NULL)				//  La lista está vacia
	{
		printf("La lista está vacía, no hay nada que remover.\n");
		pausa;
		return NULL;
	}
	if(	n == 1 )			// Estoy posicionado en el último
	{
		*dato = recorre->info;			//  Preservo el dato
		raiz = raiz ->sig;				//  Nos movemos al siquiente de raiz (nodo o NULL)
		free(recorre);					//  Libero memoria reservada por malloc()
		return raiz;					//  Regresamos el dato extraído de la lista
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
		*dato = ultimo->info;			//  Preservo la información
		free(ultimo);					//  Libero memoria reservada por malloc()
		return raiz;					//  Regresamos el dato extraído de la lista
	}
}

nodo *remueve1(nodo *raiz, char *dato)
{
	nodo *recorre = raiz;
	if( recorre == NULL)				//  La lista está vacia
	{
		printf("La lista está vacía, no hay nada que remover.\n");
		pausa;
		return NULL;
	}
	*dato = recorre->info;			//  Preservo el dato
	raiz = raiz->sig;				//  apunto a lo que sigue (null u otro nodo)
	free(recorre);					//  Libero memoria reservada por malloc()
	return raiz;					//  Regresamos el dato extraído de la lista
}	
