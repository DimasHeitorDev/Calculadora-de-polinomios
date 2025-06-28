Este é um projeto feito na disciplina de Introdução à Programação. Que consiste em uma calculadora de polinomios. 

## Modo de usar:

Inicie declarando os polinomios com a função ./pbuild.
Depois, você irá poder usar as funções ./psum, ./psub e ./pview, que estão documentadas abaixo.

# exemplo de uso:

```bash
./pbuild "1x^2-2x^1+0.5x^0" polinomios/polinomioA
./pbuild "3x^2-15x^0" polinomios/polinomioB
./psum polinomios/polinomioA polinomios/polinomioB polinomios/polinomioC
./psub polinomios/polinomioA polinomios/polinomioB polinomios/polinomioD
```

## Documentação:

# ./pbuild "p" n
Cria um arquivo para o polinomio p com o nome n.

### Argumentos:
    * p: texto que armazena o polinomio. Deve ser da forma: "ax^p+bx^q+cx^r+...".
        * **Importante** ressaltar que esse texto não contém espaços e todos todos os vaores a, b, c, p, q, r, ... devem estar presentes.
    Ou seja, o polinomio "x^2-4x" não é válido, mas "1x^2-4x^1" é.
    * n: nome do polinomio. É sugerido que todos os nomes comecem com "polinomios/", para que eles sejam salvos na pasta polinomios.

# ./pview n
Exibe o polinomio de nome n no terminal.

### Argumentos
    * n: nome do polinomio a ser exibido no terminal.

# ./psum p1 p2 r
Realiza a soma r entre os polinomios p1 e p2, exibindo r no terminal. Além disso, ela cria um arquivo para o polinomio r.

### Argumentos
    * p1: nome do polinomio a ser somado com p2.
    * p2: nome do polinomio a ser somado com p1.
    * r: nome do polinomio que irá armazenar resultado da soma p1 + p2.

# ./psub p1 p2 r
Realiza a subtração r entre os polinomios p1 e p2, exibindo r no terminal. Além disso, ela cria um arquivo para o polinomio r.

### Argumentos
    * p1: nome do polinomio a ser subtraído por p2.
    * p2: nome do polinomio a ser subtraíso de p1.
    * r: nome do polinomio que irá armazenar o resultado da subtração p1 - p2.