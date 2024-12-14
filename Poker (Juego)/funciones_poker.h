//Librerias
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>

//Constantes
#define NUM_PALOS 4
#define NUM_VALORES 13
#define MAX_LENGTH 15
#define MAX_CARTAS 5



//Inicio Estructuras
typedef struct Carta {
    char valor [MAX_LENGTH];
    char palo[MAX_LENGTH];
} Carta;

typedef Carta Mano[MAX_CARTAS];

typedef struct{
    char *palin[NUM_PALOS];
    char *valorcartas[NUM_VALORES];
}TiposDe;

TiposDe tipos = {
    .palin = {"Picas", "Corazones", "Diamantes", "Treboles"},
    .valorcartas = {"As", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"}
};

//Fin Estructuras


//Inicio Funciones
void bienvenida(){

    printf("\n\t--------------------------------------------------------\n");
    printf("\t\t**** Bienvenido/a al juego de Poker ****");
    printf("\n\t--------------------------------------------------------\n");
    printf("\n\t Se le otorgara aleatoriamente un mazo de 5 cartas.");
    printf("\n\t El programa le indicara cuales son las categorias que la mano gano.");
    printf("\n\n\t Presione cualquier tecla para comenzar...");
    getch();
    system("cls");

}

int sacarRandomValor() {
    return rand() % NUM_VALORES;
}

int sacarRandomPalo() {
    return rand() % NUM_PALOS;
}

void mostrarMano(Mano mano)
{
    int i;
    for(i=0; i < MAX_CARTAS ; i++)
        printf("\nCarta %d \t Palo: %s    \t\t Valor: %s \n", i+1,mano[i].palo, mano[i].valor);
}

void manoRepetida(Mano mano) {
    int i, j;
    for (i = 0; i < MAX_CARTAS - 1; i++) {
        for (j = i + 1; j < MAX_CARTAS; j++) {
            if (strcmp(mano[i].palo, mano[j].palo) == 0 && strcmp(mano[i].valor, mano[j].valor) == 0) {
                strcpy(mano[i].palo, tipos.palin[sacarRandomPalo()]);
                strcpy(mano[i].valor, tipos.valorcartas[sacarRandomValor()]);
            }
        }
    }
}


void generarMano(Mano mano){
    int i;
    for(i = 0; i < MAX_CARTAS; i++)
    {
        strcpy(mano[i].valor, tipos.valorcartas[sacarRandomValor()]);
        strcpy(mano[i].palo, tipos.palin[sacarRandomPalo()]);
    }
}

void esPar(int *vecCont)
{
  int i, cont=0;

    for(i=0; i < NUM_VALORES; i++)
    {
        if(vecCont[i] == 2)
        {
            cont++;
        }
    }

    if(cont == 2)
    {
        printf("\n Es Doble Par. \n");
    }else{
        if(cont == 1)
        {
            printf("\n Es Par. \n");
        }else{
            printf("\n No es Par.\n");
            printf("\n No es Doble Par.\n");
        }
    }
}


 int esFull(int *vecCont)
 {
    int i;
    int hayDos=0, hayTres=0;

     for (i = 0; i < NUM_VALORES; i++) {
        if (vecCont[i] == 2) {
            hayDos = 1;
        }
        if (vecCont[i] == 3) {
            hayTres = 1;
        }
    }


    if (hayTres && hayDos) {
        printf("\n Es Full.\n");
    } else {
        printf("\n No es Full.\n");
    }
    return hayTres;
 }


 void esTriple(int hayTres)
 {
     if(hayTres == 1)
     {
        printf("\n Es Triple.\n");
     }else{
        printf("\n No es Triple.\n");
     }

 }

 void esEscalera(int *vecCont,int color)
 {
    int i=0,j, es=0, consecutivas = 0;

    if (vecCont[9] == 1 && vecCont[10] == 1 && vecCont[11] == 1 && vecCont[12] == 1 && vecCont[0] == 1) {
        es = 1;             //Caso en donde sean cartas con valor 10,J,Q,K,As consecutivas
    }

    while((es != 1) && (i < NUM_VALORES))
    {
        if(vecCont[i] == 1)
        {
            consecutivas++;
        }else
        {
            consecutivas = 0;
        }
        if(consecutivas == 5)
        {
            es = 1;
        }
        i++;
    }
    if(es == 1)
    {
        printf("\n Es Escalera.\n");
        if(color == 1)
        {
            printf("\n Es Escalera Real.\n");
        }else{
            printf("\n No es Escalera Real.\n");
        }
    }else{
        printf("\n No es Escalera.\n");
        printf("\n No es Escalera Real.\n");
    }
 }

 int esColor (Mano mano)
{
    int i, val=1;
    for(i=1; i < MAX_CARTAS; i++)
    {
        if(strcmp(mano[0].palo,mano[i].palo) != 0)
        {
            val = 0;
            break;
        }
    }

    if(val == 1)
    {
        printf("\n Es Color. \n");
    }else{
        printf("\n No es Color. \n");
    }
    return val;
}


int casosEspeciales(Mano mano)
{
    int i,j;
    int soloTres;
    int es;
    int vecContador[NUM_VALORES] = {0};
    for(i = 0; i < MAX_CARTAS; i++)
    {
        for(j=0; j < NUM_VALORES; j++)
        {
            if(strcmp(mano[i].valor, tipos.valorcartas[j]) == 0){
                vecContador[j] += 1;
                break;
            }
        }
    }

    esPar(vecContador);
    soloTres = esFull(vecContador);
    esTriple(soloTres);
    es = esColor(mano);
    esEscalera(vecContador,es);

}
//Fin Funciones

