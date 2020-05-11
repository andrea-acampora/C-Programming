#include <stdio.h>
#include <stdlib.h>

//Esercizio 1
int input_int()     //Funzione per fare l'input e il controllo dell'input: non chiede niente, ritorna il valore inserito in input
{
    int n_input;
    int controllo;      //Controllo serve per controllare che il valore inserito sia un int

    printf("Inserire numero intero positivo minore di 16 per il fattoriale: ");

    controllo = scanf("%d", &n_input);
    fflush(stdin);
    while ((controllo==0)||(n_input<0)||(n_input>16)){              //Se è negativo, maggiore di 16 (causa overflow) o non int, il valore viene fatto reinserire
        printf("Hai sbagliato, inserire numero intero positivo minore di 16 per il fattoriale: ");
        controllo = scanf("%d", &n_input);
        fflush(stdin);
    }
    return n_input;
}
int fatt_ric(int space,int n, int *p)               //Funzione ricorsiva del calcolo del fattoriale, richiede tre dati (lo spazio di indentazione, il numero e il puntatore) e ritorna il risultato
{
    int risult;
    *p=*p+1;
    printf("\n%*d-Chiamata della funzione, il valore n e' uguale a %d",space,*p, n);        //Utilizzo space per gestire l'indentazione
    space=space+3;
    if (n<=1){                      //Il fattoriale di 1 è 1
        return (1);
    }
    risult=fatt_ric(space,n-1,p)*n;         //Richiama la funzione con i valori abbasstati finchè non ritornerà 1
    *p=*p-1;
    printf("\n%*d-Chiamata della funzione, risult, cioe' il fattoriale di n (%d!) e' uguale a %d",space,*p,n, risult);
    space=space-3;
    return(risult);         //Ritorna il risultato
}

int main()          //Main
{
    int space=0;
    int n_input;
    n_input = input_int();      //Chiamo la funzione input per trovare n_input
    int risultato;

    int *p;
    p=malloc(sizeof(int));          //Alloco la memoria a *p
    *p=0;

    risultato = fatt_ric(space,n_input, p);         //Chiamo la funzione fattoriale

    printf("\n\n%d", risultato);        //Stampo il risultato
    return 0;
}
