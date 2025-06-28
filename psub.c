#include <stdio.h>
#include <stdlib.h>
#include "polinomio.h"

int main(int arg, char** argv)
{
    polinomio* p1 = load_polinomio(argv[1]);
    polinomio* p2 = load_polinomio(argv[2]);

    int menor_grau = p1->grau, maior_grau = p2->grau;
    if (p2->grau < menor_grau) menor_grau = p2->grau, maior_grau = p1->grau;

    polinomio* p = NULL;
    p = malloc(sizeof(polinomio));
    if (p == NULL)
    {
        printf("Erro ao alocar memoria para o polinomio resultante.\n");
        free_polinomio(p1);
        free_polinomio(p2);
        return 0;
    }

    p->grau = maior_grau;
    p->coef = calloc(maior_grau + 1, sizeof(double));
    if (p->coef == NULL)
    {
        printf("Erro ao alocar memoria para os coeficientes do polinomio resultante.\n");
        free(p);
        free_polinomio(p1);
        free_polinomio(p2);
        return 0;
    }

    int e = 0;
    for (e = 0; e <= menor_grau; e++)
    {
        p->coef[e] = p1->coef[e] - p2->coef[e];
    }

    if (maior_grau == p1->grau)
        for (e; e <= p1->grau; e++)
            p->coef[e] = p1->coef[e];
    else
        for (e; e <= p2->grau; e++)
            p->coef[e] = p2->coef[e];

    build_polinomio(p, argv[3]);

    view_polinomio(p1);
    printf("-\n");
    view_polinomio(p2);
    printf("-------------------------\n");
    view_polinomio(p);

    free_polinomio(p1);
    free_polinomio(p2);
    free_polinomio(p);

    return 0;
}