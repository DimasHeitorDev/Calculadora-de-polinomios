#include <stdio.h>
#include "polinomio.h"

int main(int argc, char** argv)
{
    polinomio* p = load_polinomio(argv[1]);
    view_polinomio(p);

    free_polinomio(p);

    return 0;
}