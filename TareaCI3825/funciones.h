/******************************************************************************************
* Autor: Adriana Devera	y Maria Garcia						          *
* Carnet: 09-11286 y								          *
* Arhivo: funciones.h									  *
* Asunto: tarea								                  *
*******************************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"lista.h"

//Funciones que seran expicadas en el archivo del codigo fuente operaciones.c

void freeMemoria(lista *);

void RecorridoBFS(lista *);

void listarArbol(char *, lista *, objetoLista *,int, int, int, int (*fp)(objetoLista *, objetoLista*));

void funcionMostrar();
