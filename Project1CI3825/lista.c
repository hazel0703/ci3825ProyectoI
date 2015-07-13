/******************************************************************************************
* Autor: Adriana Devera	y Maria Garcia						          *
* Carnet: 09-11286 y								          *
* Arhivo: lista.c									  *
* Asunto: tarea								                  *
*******************************************************************************************/

#include"lista.h"


//Funcion que compara si dos objetoListas que apuntan a file se refieren al mismo file
//La comparacion se hace por los nombres
int comparador(objetoLista *c1, objetoLista *c2){
	return !strcmp(((file *)(c1->cont))->nombre,((file *)(c2->cont))->nombre);
}

/*Funcion utilizada para siempre agregar una objetoLista a una lista*/

int comparador2(objetoLista *c1, objetoLista *c2){
	return 0;
}


/*Inicializo la lista*/
void inicializar(lista *l){
	l->primero=NULL;
	l->size=0;
}


/*Funcion que se utiliza para agregar un elemento a una lista si este no esta contenido en la misma*/

void agregarElemento(lista *l, objetoLista *c, int (*fp)(objetoLista *,objetoLista *))
	{
	if(esta(l,c,fp,0)==NULL)
		{

		//si esta vacia simplemente este objetoLista es el primer elemento de la lista
		if(l->primero==NULL) 
			l->primero=c,c->anterior=NULL;
		else{
			objetoLista *tmp = l->primero;

			//Me voy hasta el final de la lista y lo agrego
			while(tmp->proximo!=NULL)
			{
				tmp=tmp->proximo;
			}
			tmp->proximo = c;
			c->anterior=tmp;
	}

		c->proximo=NULL;

		(l->size)++;
		}
	else liberar(c);
}

/*Funcion que sirve para borrar un elemento contenido en la lista*/
void DeleteElement(lista *l, objetoLista *c, int (*fp)(objetoLista *,objetoLista *)){
	esta(l,c,fp,1);
/*if (int ){
}*/
	liberar(c);
}


/*Libero la memoria de los apuntadores que se encuentran en la lista, */
void liberar(objetoLista *c){
	c->proximo=c->anterior=NULL;
	file *ptr = (file *) (c->cont);
	free(ptr->nombre);
	free(ptr->posicion);
	free(ptr->hijos);
	free(ptr);
	free(c);
}


/*Verifica que se encuentre en un directorio y si el archivo se encuentra alli, entonces lo borra*/
int verificadorEliminar(objetoLista *borrar){
	if(borrar==NULL) 
	return 0;

	file *ptr = (file *)(borrar->cont);

	/*Si es un archivo se puede borrar*/
	if(ptr->tipo) 
	return 0;
	
	/*Si no, es un directorio, entonces se verifica que tenga hijos y se imprime*/
	return !((ptr->hijos)->size);

	return
	printf("ERROR: el directorio que desea borrar contiene archivos en el", ptr);
}


//Funcion utilizada para verificar si una objetoLista c esta en una lista l
//usando la funcion fp como funcion comparadora
//Si la opcion es 0 significa que solo quiero ver si esta el elemento
//Si es uno, quiero ver si esta, y si es asi borrar el elemento

	objetoLista *esta(lista *l, objetoLista *c, int (*fp)(objetoLista *, objetoLista *), int opcion){
	objetoLista *buscar = l->primero;

	while(buscar!=NULL){
		if((*fp)(buscar, c)) 
			break;
		buscar = buscar-> proximo;
	}

	
	//Si solo tengo que buscar, retorno
	if(!opcion) return buscar;

	//Si tengo que borrar libero memoria y actualizo
	if(verificadorEliminar(buscar)){
		if(buscar->anterior==NULL) 
			l->primero = buscar->proximo;
		else
			(buscar->anterior)->proximo = buscar->proximo;

		if(buscar->proximo!=NULL)
			(buscar->proximo)->anterior = buscar->anterior;

		(l->size)--;
		liberar(buscar);
	}
	return NULL;

}
/*
void imprimirLista(objetoLista *primero) {
    while (cont != 0) {
        printf("%s\n", primero->cont);
        primero = primero->proximo;
    }
}*/
