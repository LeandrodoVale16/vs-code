#include <stdio.h>

double potencia(double x, int n){
    double resultado = 1;
    int i;

    if (n < 0)
    {
        x = 1 / x;
        n = -n;
    }

    for (i = 0; i < n; i++){
    resultado = x * resultado; 
    }

    return resultado;
}


long fatorial(long x){
    int i;
    long n = 1;
    if (x < 0){
        printf("Fatorial de numero negativo nao existe!\n");
        return -1;
    } else if (x == 0)
    {
     printf("Fatorial de 0 eh: 1\n");
    } else {
     for(i = 1; i <= x; i++){
            n = n * i;
        }
    }
    return n;
}

double seno(double x){
    double total = 0.0;
    double conta;
    int n = 0;
    int sinal = 1;

    do {
        int expoente = 2 * n + 1;
        conta = sinal * (potencia(x, expoente) / fatorial(expoente));
        total += conta;

        sinal *= -1;
        n++;
    } while (conta > 1e-10 || conta < -1e-10);

    return total;
}

double raizquadrada(double x){
    double superior;
    double inferior = 0;
    double chute;
    int i;

    superior = x + 1;
    for (i = 0; i < 50; i++)
    {
        chute = (superior + inferior) / 2;
        if (chute * chute > x)
        {
            superior = chute;
        } else if (chute * chute < x)
        {
            inferior = chute;
        }

    }

    return chute;
}

double cosseno(double x){
    double cos = 1 - potencia(seno(x), 2);

    return raizquadrada(cos);
}


int main(){
    int inicio = 0;
    int i;
    int n;
    double angulo = 0.0;
    double angulorad = 0.0;
    printf("┌─────┬────────────────┬────────────────┬────────────────┬────────────────┬────────────────┐\n");
    printf("│ ang │ seno   cosseno │ seno   cosseno │ seno   cosseno │ seno   cosseno │ seno   cosseno │\n");
    printf("├─────┼────────────────┼────────────────┼────────────────┼────────────────┼────────────────┤\n");
    for(i = 0; i <= 17; i++){
        printf("│ %2d  │", inicio);
        for (n = 1; n <= 5; n++)
        {
        printf(" %.4lf %.4lf  │", seno(angulorad), cosseno(angulorad));
        angulo = angulo + 1.0;
        angulorad = angulo * (3.141592653 / 180);
        }
        printf("\n");
        if (i < 17){
        printf("├─────┼────────────────┼────────────────┼────────────────┼────────────────┼────────────────┤\n");
        }
        inicio = inicio + 5;
    }
    printf("└─────┴────────────────┴────────────────┴────────────────┴────────────────┴────────────────┘\n");
    return 0;
}
