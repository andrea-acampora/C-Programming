#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
/*Realizzare un programma che calcoli il valore del fattoriale di un numero inserito da utente tramite una funzione ricorsiva;
il programma deve stampare le variabili locali e i parametri di ogni chiamata alla funzione ricorsiva.
In particolare, per ogni chiamata ricorsiva, visualizzare l’output su una riga separata e aggiungere un livello di rientro.
Fate del vostro meglio per rendere l’output chiaro, interessante e significativo.
 L’obiettivo è quello di progettare e implementare un formato dell’output che aiuti l'utente
a comprendere il meccanismo della ricorsione.*/
//Dichiaro la funzione per calcolare il fattoriale
int fattoriale(int n)
{
    int ris,i;
    //controllo sul numero negativo perchè è impossibile calcolarne il fattoriale
    if(n<0)
        {return -1;}
        //for(i=n;i=0;i--)printf("\t");
        printf("Esamino fattoriale di n= %d, quindi \n",n);
        //Imposto il caso base
        
        if(n==0)
            {
            printf("\nTrovato caso base con fattoriale di 0 = 1 \n");
            ris=1;
            return ris;
            }
            //ciclo ricorsivo che serve a scorrere tutti i numeri fino ad arrivare al caso base
                else
                {
                ris=n*fattoriale(n-1);
                printf("\nFattoriale di %d = %d \n",n,ris);
                return ris;
                }
}
int main()
{
    int n,i;
    printf("INSERISCI UN NUMERO POSITIVO PER IL CALCOLO DEL FATTORIALE \n");
    scanf("%d",&n);
    fflush(stdin);
    //controllo sul numero inserito dall'utente
        while (n<0 || n>12)
        {
        printf("Errore, riprovare: \n");
        printf("INSERISCI UN NUMERO POSITIVO PER IL CALCOLO DEL FATTORIALE \n");
        scanf("%d",&n);
        fflush(stdin);
        }
    //stampo a video il fattoriale richiamando la funzione fattoriale(n)
    printf("\nIL FATTORIALE DI %d E' %d \n",n,fattoriale(n));
    printf("\n");
system("pause");
return 0;
}
