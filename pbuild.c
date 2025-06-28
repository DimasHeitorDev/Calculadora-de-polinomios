#include <stdio.h>
#include <stdlib.h>
#include "polinomio.h"

int main(int argc, char** argv)
{ 
    polinomio p;

    int i;
    char* str = argv[1];
    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == '^')
        {
            int exp;
            sscanf(str + i + 1, "%d", &exp);

            if (exp > p.grau)
                p.grau = exp;
        }
    }

    p.coef = calloc(p.grau + 1, sizeof(double));
    if (p.coef == NULL)
    {
        printf("Erro ao alocar memoria para o vetor de coeficientes.\n");
        return 0;
    }
    
    double c;
    int pos = 0, e, n;
    while (str[pos] != '\0')
    {
        sscanf(str + pos, "%lf%*c%*c%d%n", &c, &e, &n);

        pos += n;
        p.coef[e] = c;
    }

    int r = build_polinomio(&p, argv[2]);
    if (r == 1)
    {
        printf("Parando execucao de pbuild.\n");
        free(p.coef);
        return 0;
    }
    printf("O arquivo para o polinomio %s foi criado.\n", argv[2]);
    
    free(p.coef);

    return 0;
}