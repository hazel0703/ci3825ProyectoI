/******************************************************************************************
* Autor: Adriana Devera	y Maria Garcia						          *
* Carnet: 09-11286 y								          *
* Arhivo: funciones.c									  *
* Asunto: tarea								                  *
*******************************************************************************************/

#include"funciones.h"

/*Función utilizada para posicionarnos en el directorio pedido en la orden para verificar si se agrega el archivo
o el directorio, es en donde se maneja el ma, md, rm y ls*/

void listarArbol(char *posicion, lista *l, objetoLista *c,int direct1, int direct2, int choice, int (*fp)(objetoLista *, objetoLista*)){

	/*Una vez ubicados en el directorio actual, se pocede a agregar, consultar o eliminar algun elemento*/
	
		if(direct1>=direct2)
		{
		if(!choice) agregarElemento(l,c,fp);
		else DeleteElement(l,c,fp);
		return; 
		}
	
/*Busco el directorio en el cual debo estar, la primera posición debe ser /, el cual es la raíz, y así al obtener la posicion
agrego el archivo*/
	char *sig;
	int tmp = direct1;
	while(posicion[direct1]!='/') direct1++;
	int tam = direct1-tmp+5;
	sig = (char *) malloc(tam);
	memset(sig,0,sizeof sig);

	for(int i = tmp ;i<direct1;i++)sig[i-tmp] = posicion[i];	
	objetoLista *busc = l->primero;

	/*ubico el directorio*/	
	while(busc!=NULL)
	{
		if(!strcmp(sig,((file *)(busc->cont))->nombre)) 
		break;
		busc=busc->proximo;
	}
	
	direct1++;
	free(sig);

	/*verifico y si no existe entonces no se puede agregar tal archivo*/
	if(busc==NULL) return;
	if((((file *)(busc->cont))->tipo)==0)
	listarArbol(posicion,((file*)(busc->cont))->hijos,c,direct1,direct2,choice,fp);
	else liberar(c);

}

/*esta es una función llamada RecorridoBFS se adaptó el algoritmo BFS para poder hacer el recorrido respectivo 
del arbol por medio de la lista creada y mostrarlo por la consola*/

void RecorridoBFS(lista *arbol)
{
	lista *aux = (lista *) malloc(sizeof(lista));
	inicializar(aux);
	objetoLista *f = arbol->primero;
	while(f!=NULL)
	{
		objetoLista *new;
		new = (objetoLista*) malloc(sizeof(objetoLista));
		new->cont = (void *) f;
		f = f->proximo;
		agregarElemento(aux,new,&comparador2);
	}

	objetoLista *recorrido = aux->primero;
	
	while(NULL!=recorrido){
		file *ptr = (file *)(((objetoLista *)(recorrido->cont))->cont);
		printf("%s\n",ptr->posicion);
		objetoLista *ptr2 = (ptr->hijos)->primero;
		while(ptr2!=NULL){
			objetoLista *new;
			new = (objetoLista *) malloc(sizeof(objetoLista));
			new->cont=(void *) ptr2;
			agregarElemento(aux,new,&comparador2);
			ptr2=ptr2->proximo;
		}
		recorrido = recorrido->proximo;
		
	}

	recorrido = aux->primero;

	while(NULL!=recorrido){
		f=  recorrido;
		recorrido = recorrido->proximo;
		free(f);

	}

	free(aux);
	
}

/*Libero la memoria que ocupa el arbol tipo lista que he utilizado*/

void freeMemoria(lista *arbol){
	objetoLista *c = arbol->primero;
	while(c!=NULL){
		objetoLista *otr = c;
		freeMemoria(((file *)(c->cont))->hijos);

		c = c->proximo;
		liberar(otr);
	}
}
/*
void funcionMostrar()
{

}
*/

