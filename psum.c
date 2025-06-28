#include <stdio.h>
#include "polinomio.h"

int main(int arg, char** argv)
{
    polinomio* p1 = load_polinomio(argv[1]);
    polinomio* p2 = load_polinomio(argv[2]);

    printf("Polinomios de grau %d e %d lidos com sucesso.\n", p1->grau, p2->grau);
    view_polinomio(p1);
    view_polinomio(p2);

    int menor_grau = p1->grau, maior_grau = p2->grau;
    if (p2->grau < menor_grau) menor_grau = p2->grau, maior_grau = p1->grau;

    build_polinomio("", argv[3]);
    polinomio* p = load_polinomio(argv[3]);
    p->grau = maior_grau;

    int e = 0;
    for (e = 0; e <= menor_grau; e++)
    {
        p->coef[e] = p1->coef[e] + p2->coef[e];
    }

    if (maior_grau == p1->grau)
        for (e; e <= p1->grau; e++)
            p->coef[e] = p1->coef[e];
    else
        for (e; e <= p2->grau; e++)
            p->coef[e] = p2->coef[e];

    printf("Deu tudo certo. Os polinomios foram somados.\n");
    printf("%lf\n", p->coef[1]);
    view_polinomio(p);
    printf("Polinomio visto.\n");

    free_polinomio(p1);
    free_polinomio(p2);
    free_polinomio(p);

    return 0;
}