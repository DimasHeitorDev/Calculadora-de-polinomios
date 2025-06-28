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
    printf("Liberando a memoria de p->coef: (%p)\n", &p->coef);
    free(p->coef);
    printf("Liberando a memoria de p: (%p)\n", &p->coef);
    free(p);
    printf("Memoria do polinomio liberada.\n");

    return;
}

int build_polinomio(polinomio* p, char* name)
{
    FILE* file = NULL;
    printf("Criando um arquivo chamado %s\n", name);
    file = fopen(name, "wb");
    if (file == NULL)
    {
        printf("Falha ao criar arquivo.\n");
        return 1;
    }

    fwrite("poly", sizeof(char), 4, file);
    fwrite(&p->grau, sizeof(int), 1, file);

    int e;
    for (e = 0; e <= p->grau; e++)
    {
        double* c = &p->coef[e];
        fwrite(c, sizeof(double), 1, file);
    }

    fclose(file);

    return 0;
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