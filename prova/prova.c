#include <stdio.h>
#include <stdlib.h>
/*1.Dati tre valori a, b, c, rappresentanti i coefficienti di un’equazione di secondo grado
ax2+ b x + c = 0,
calcolare le due radici (se reali)*/
int main()
{
int conta, dato, somma;
printf("Immetti 10 interi: ");
somma= 0;
conta= 0;
while (conta< 10) {
scanf("%d", &dato);
somma+= dato;
conta++;
}
printf("La somma e‘ %d\n", somma);
}
