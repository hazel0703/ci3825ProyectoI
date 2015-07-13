/******************************************************************************************
* Autor: Adriana Devera	y Maria Garcia						          *
* Carnet: 09-11286 y								          *
* Arhivo: lista.h									  *
* Asunto: tarea								                  *
*******************************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>


/*estructura para indicar que hay un objeto en la lista y poder recorrer la lista a crear*/

typedef struct ObjetoLista{
	void *cont;
	struct ObjetoLista *proximo,*anterior;
} objetoLista;


/*Estructura lista, se tiene a un apuntador del tipo objetoLista*/

typedef struct {
	objetoLista *primero;
	int size;
} lista;

/*Estructura que es utilizada para crear un archivo en la lista, contiene su posición, el nombre del archivo, el tipo y la cantidad 
de hijos que posee, por ejemplo un directorio que contenga mas de un archivo o directorio, eso representa alos hijos*/

typedef struct File{
	char *posicion;
	char *nombre;
	int tipo;
	lista *hijos;
} file;


int comparador2(objetoLista *c1, objetoLista *c2);

int comparador(objetoLista *c1, objetoLista *c2);

void inicializar(lista *l);

void agregarElemento(lista *l, objetoLista *c, int (*fp)(objetoLista *,objetoLista *));

void DeleteElement(lista *, objetoLista *, int (*fp)(objetoLista *,objetoLista *));

int verificadorEliminar(objetoLista *);

void liberar(objetoLista *);

objetoLista *esta(lista *, objetoLista *, int (*fp)(objetoLista *, objetoLista *), int);

//void imprimirLista(objetoLista *primero);
