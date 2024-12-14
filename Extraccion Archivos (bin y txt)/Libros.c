#include <stdio.h>
#include "func_libros.h"


void main()
{
    Lineas li[MAXVECTOR];
    FILE *fp;
    FILE *fp2;
    int falla;
    falla = aperturaLectEsc(&fp,"libros.txt","rt");
    falla = aperturaLectEsc(&fp2,"librosEscr.dat","wb");
    if(falla == 0)
    {
        fclose(fp);
        exit(0);

    }
    escribirArchivo(fp,fp2,li);
    fclose(fp);
    fclose(fp2);
    falla = aperturaLectEsc(&fp2,"librosEscr.dat","rb");
    mostrarArchivo(&fp2,li);
    fclose(fp2);
}
