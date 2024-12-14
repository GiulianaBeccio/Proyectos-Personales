//Librerias
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//Constantes
#define AUTOR1 10
#define AUTOR2 8
#define TITULO 27
#define EDITORIAL 14
#define ANIO 5
#define CANTISBN 14
#define MAXVECTOR 7
#define MAXCADENA (AUTOR1 + AUTOR2 + TITULO + EDITORIAL + ANIO + CANTISBN)


//Inicio Estructura
typedef struct {
    char autor1[AUTOR1];
    char autor2[AUTOR2];
    char titulo[TITULO];
    char editorial[EDITORIAL];
    char anio[ANIO];
    char ISBN[CANTISBN];
}Lineas;

//Fin Estructura


//Inicio Funciones
int leerCampos(FILE *fp, Lineas *li,int posvec)
{
    char cadena[MAXCADENA];
    char empieza[] = {0,9,16,42,55,59};

    if((fgets(cadena,MAXCADENA+1,fp) == NULL)){
            return 0;
    }
        strncpy(li[posvec].autor1,cadena+empieza[0],AUTOR1-1);
        li[posvec].autor1[AUTOR1-1] = '\0';

        strncpy(li[posvec].autor2,cadena+empieza[1],AUTOR2-1);
        li[posvec].autor2[AUTOR2-1] = '\0';

        strncpy(li[posvec].titulo,cadena+empieza[2],TITULO-1);
        li[posvec].titulo[TITULO-1] = '\0';

        strncpy(li[posvec].editorial,cadena+empieza[3],EDITORIAL-1);
        li[posvec].editorial[EDITORIAL-1] = '\0';

        strncpy(li[posvec].anio,cadena+empieza[4],ANIO-1);
        li[posvec].anio[ANIO-1] = '\0';

        strncpy(li[posvec].ISBN,cadena+empieza[5],CANTISBN-1);
        li[posvec].ISBN[CANTISBN-1] = '\0';

        return 1;
}

void escribirArchivo(FILE *fp, FILE *fp2, Lineas *li)
{
    int i=0;
    while((i < MAXVECTOR) && (leerCampos(fp,li,i))){
        fwrite(&li[i],sizeof(Lineas),1,fp2);
        i++;
    }
}

int aperturaLectEsc(FILE **archivo, char *nombre, char *modo)
{
    if((*archivo = fopen(nombre,modo)) == NULL)
    {
        printf("\n ERROR. No se pudo encontrar o abrir el archivo.");
        return 0;
    }
    return 1;
}

void mostrarArchivo(FILE **archivo, Lineas *li)
{
    int i=0;
    while(fread(&li[i],sizeof(Lineas),1,*archivo) && i<MAXVECTOR){
        printf("\n %-10s %-8s %-27s %-14s %-5s %-14s\n",li[i].autor1,li[i].autor2,li[i].titulo,li[i].editorial,li[i].anio,li[i].ISBN);
        //printf("\n %s %s %s %s %s %s\n",li[i].autor1,li[i].autor2,li[i].titulo,li[i].editorial,li[i].anio,li[i].ISBN);
        i++;
    }

}

//Fin Funciones
