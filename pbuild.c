#include <stdio.h>
#include <stdlib.h>
#include "polinomio.h"

int main(int argc, char** argv)
{ 
    build_polinomio(argv[1], argv[2]);
    printf("Deu certo. O polinomio foi criado.\n");

    return 0;
}