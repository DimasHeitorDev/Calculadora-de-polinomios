#include "polinomio.h"
#include <stdlib.h>
#include <string.h>

#define ID_SIZE 4

polinomio* load_polinomio(char* nome)
{
    FILE* file = NULL;

    file = fopen(nome, "rb");
    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo.");
        return NULL;
    }

    char tipo_de_arquivo[5];
    if (fread(tipo_de_arquivo, sizeof(char), ID_SIZE, file) != ID_SIZE)
    {
        printf("Erro ao ler o tipo do arquivo ou arquivo muito pequeno.\n");
        return NULL;
    }
    tipo_de_arquivo[ID_SIZE] = '\0';

    if (strcmp(tipo_de_arquivo, "poly") != 0)
    {
        printf("O arquivo lido nao corresponde a um polinomio.\n");
        fclose(file);
        return NULL;
    }

    polinomio* p = NULL;
    p = malloc(sizeof(polinomio));
    if (p == NULL)
    {
        printf("Erro ao alocar a memoria do polinomio.\n");
        fclose(file);
        return NULL;
    }

    int grau;
    if (fread(&grau, sizeof(int), 1, file) != 1)
    {
        printf("Erro ao ler o grau do polinomio.\n");
        free(p);
        fclose(file);
        return NULL;
    }

    p->grau = grau;
    p->coef = malloc((grau + 1) * sizeof(double));
    if (p->coef == NULL)
    {
        printf("Erro ao alocar a memória do polinomio.\n");
        free(p);
        fclose(file);
        return NULL;
    }

    int e;
    double c;
    for (e = 0; e <= grau; e++)
    {
        if (fread(&c, sizeof(double), 1, file) != 1)
        {
            printf("Erro ao ler o coeficiente com expoente %d do polinomio.\n", e);
            free(p->coef);
            free(p);
            fclose(file);
            return NULL;
        }
        p->coef[e] = c;
    }

    printf("Polinomio de grau %d carregado\n", grau);
    fclose(file);

    return p;
}

void free_polinomio(polinomio* p)
{
    printf("Liberando memória.\n");
    free(p->coef);
    printf("1\n");
    free(p);
    printf("Memória liberada.\n");
}

void build_polinomio(char* str_pol, char* pol_name)
{
    FILE* file = NULL;
    printf("Building a file with name %s\n", pol_name);
    file = fopen(pol_name, "wb");

    int grau = 0;
    int i;
    for (i = 0; str_pol[i] != '\0'; i++)
    {
        if (str_pol[i] == '^')
        {
            int coef;
            sscanf(str_pol + i + 1, "%d", &coef);

            if (coef > grau)
                grau = coef;
        }
    }

    fwrite("poly", sizeof(char), 4, file);
    fwrite(&grau, sizeof(int), 1, file);

    double* coef = NULL;
    coef = calloc(grau + 1, sizeof(double));
    
    double c;
    int pos = 0, e, n;
    while (str_pol[pos] != '\0')
    {
        sscanf(str_pol + pos, "%lf%*c%*c%d%n", &c, &e, &n);
        pos += n;

        coef[e] = c;
    }

    for (e = 0; e <= grau; e++)
    {
        double* c = &coef[e];
        fwrite(c, sizeof(double), 1, file);
    }

    fclose(file);
    free(coef);

    return;
}

void view_polinomio(polinomio* p)
{
    int e, termos_mostrados = 0;
    for (e = 0; e <= p->grau; e++)
    {
        if (termos_mostrados != 0 && p->coef[e] > 0)
            printf("+");

        if (p->coef[e] != 0)
        {
            printf("%.2lfx^%d", p->coef[e], e);
            termos_mostrados++;
        }
    }
    printf("\n");
}