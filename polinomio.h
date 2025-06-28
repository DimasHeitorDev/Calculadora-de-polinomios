#ifndef POLINOMIO_H
#define POLINOMIO_H

#include <stdio.h>

#define ID_SIZE 4

typedef struct {
    char id[ID_SIZE];
    int grau;
    double* coef;
} polinomio;

polinomio* load_polinomio(char* nome);
void free_polinomio(polinomio* p);

int build_polinomio(polinomio* p, char* name);
void view_polinomio(polinomio* p);

#endif