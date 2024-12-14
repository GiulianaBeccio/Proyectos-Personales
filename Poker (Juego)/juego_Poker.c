#include <stdio.h>
#include "funciones_poker.h"

int main() {

    bienvenida();
    Mano mano;
    /*
    Mano mano = {                           Para asignar valores manualmente
        {"10", "Corazones"},
        {"J", "Corazones"},
        {"Q", "Corazones"},
        {"K", "Corazones"},
        {"As", "Corazones"}
    };
    */
    srand(time(NULL));
    generarMano(mano);
    manoRepetida(mano);
    mostrarMano(mano);
    casosEspeciales(mano);       //Contiene: esFull, esPar y Doble Par, esTriple, esColor, esEscalera y EscaleraReal

    return 0;
}
