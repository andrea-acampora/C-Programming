#include <stdio.h>

/* Settimana 5 - esercizio 1 */

int main(){
    /* Dichiarazione variabili. */
    int intero;
    float flotti;
    double doppio;
    char car;
    int vet[] = {10, 20, 30, 40, 50};

    /* Dichiarazione puntatori. */
    int *pi = &intero;
    float *pf = &flotti;
    double *pd = &doppio;
    char *pc = &car;
    int *pvi = vet;

    /* Inizializzazione variabili. */
    do {fflush(stdin); printf("Inserire un intero valido: ");} while(!scanf("%d", &intero));
    do {fflush(stdin); printf("Inserire un float valido: ");} while(!scanf("%f", &flotti));
    do {fflush(stdin); printf("Inserire un double valido: ");} while(!scanf("%lf", &doppio));
    do {fflush(stdin); printf("Inserire un carattere valido: ");} while(!scanf("%c", &car));

    /* Visualizzazione variabili tramite accesso diretto. */
    printf("Visualizzazione variabili tramite accesso diretto:\n");
    printf("Valore int: %d\n", intero);
    printf("Valore float: %f\n", flotti);
    printf("Valore double: %lf\n", doppio);
    printf("Valore char: %c\n", car);
    printf("Valori array: ");
    for(int i = 0; i < 5; i++) printf("%d ", vet[i]);
    printf("\n");

    /* Visualizzazione variabili tramite accesso indiretto. */
    printf("Visualizzazione variabili tramite accesso indiretto:\n");
    printf("Valore int: %d\n", *pi);
    printf("Valore float: %f\n", *pf);
    printf("Valore double: %lf\n", *pd);
    printf("Valore char: %c\n", *pc);
    printf("Valori array: ");
    for(int *tmp = pvi; tmp < pvi + 5; tmp++) printf("%d ", *tmp);
    printf("\n");

    /* Visualizzazione indirizzi variabili tramite accesso diretto. */
    printf("Visualizzazione indirizzi variabili tramite accesso diretto:\n");
    printf("Indirizzo int: %p\n", &intero);
    printf("Indirizzo float: %p\n", &flotti);
    printf("Indirizzo double: %p\n", &doppio);
    printf("Indirizzo char: %p\n", &car);
    printf("Indirizzo array: %p\n", vet);

    /* Visualizzazione indirizzi variabili tramite accesso indiretto. */
    printf("Visualizzazione indirizzi variabili tramite accesso indiretto:\n");
    printf("Indirizzo int: %p\n", pi);
    printf("Indirizzo float: %p\n", pf);
    printf("Indirizzo double: %p\n", pd);
    printf("Indirizzo char: %p\n", pc);
    printf("Indirizzo array: %p\n", pvi);

    /* Visualizzazione indirizzi puntatori. */
    printf("Visualizzazione indirizzi puntatori:\n");
    printf("Indirizzo puntatore int: %p\n", &pi);
    printf("Indirizzo puntatore float: %p\n", &pf);
    printf("Indirizzo puntatore double: %p\n", &pd);
    printf("Indirizzo puntatore char: %p\n", &pc);
    printf("Indirizzo puntatore array: %p\n", &pvi);
}
