/******************************************************************************************
* Autor: Adriana Devera	y Maria Garcia						          *
* Carnet: 09-11286 y								          *
* Arhivo: main.c									  *
* Asunto: tarea								                  *
*******************************************************************************************/


#include"funciones.h"

/**********************************************************/
/*							  */
/* 		    Programa Principal			  */
/*							  */
/**********************************************************/

int main(int argc, char **argv){
/*Se procede a leer los parámetros proporcionados por el usuario en la consola*/
	FILE *fp;
	char buffer[250000];

	if(argc<2) {
		
		printf("ERROR al ingresar los argumentos, indique: fileTree <nombre del archivo de órdenes>", argv[0]);
		return 1;
	}


/*Se utiliza la función de fopen para abrir el archivoivo, que se indica como 2do argumento en la consola*/
	
	fp = fopen(argv[1],"r");/*Indica la posición del argumento*/
	if(fp==NULL) {
		perror("Error al abrir archivo");
		//printf( "Error al abrir archivoivo: %s\n", strerror(errno));
		return 1;
	}

	//Veo cual es la funcion comparadora usada para agregar archivoivos
	int (*funcptr)(objetoLista *, objetoLista *);
	funcptr = &comparador;

	/*Procedemos a crear un arbol para imprimirlo posteriormente*/
	lista *arbol;
	arbol = (lista *) malloc(sizeof(lista));
	inicializar(arbol);

		/*Recorriendo el buffer*/
		while(fgets(buffer,25000,fp)!=NULL){
		int size = strlen(buffer);
		int indice = size-1;
		buffer[indice]='\0';
		indice--;

		/*Me ubico y busco el nombre del archivoivo*/
		while(indice>=0 && buffer[indice]!='/') 
			indice--;
			indice++;

		int opcion=-1;
		//Veo cual es la opcion (buffer) a utilizar
		if(buffer[0]=='m') opcion=0;
		if(buffer[1]=='m') opcion=1;
		
		if(opcion==-1) continue;
		objetoLista *nueva;
		file *archivo;

/*Se crea un nuevo objeto, el cual representa a un archivo en el buffer para así poderlo ejecutar*/
		nueva = (objetoLista *) malloc(sizeof(objetoLista));
		archivo = (file *) malloc(sizeof(file));
		archivo->hijos = (lista *) malloc(sizeof(lista));
		inicializar(archivo->hijos);
		archivo->nombre= (char *) malloc((size-indice+100)*(sizeof(char)));
		archivo->posicion= (char *) malloc(size*sizeof(char));

		memset(archivo->nombre,0,sizeof (archivo->nombre));

		
		if(!opcion && buffer[1]=='d') archivo->tipo = 0;
		else if(!opcion) archivo->tipo=1;
		strcpy(archivo->posicion,buffer+4);	
		strcpy(archivo->nombre,buffer+indice);
		nueva->proximo=nueva->anterior=NULL;
		nueva->cont = (void *) archivo;


		//Agrego o elimino el archivo dependiendo de la opcion
		listarArbol(buffer,arbol,nueva,4,indice,opcion,funcptr);		
	}

	RecorridoBFS(arbol); /*Se realiza el recorrido BFS*/
       // imprimirLista(arbol);
	fclose(fp);/*aqui se cierra el archivo de entrada*/
	freeMemoria(arbol);
	free(arbol);	
	
	return 0;
}
