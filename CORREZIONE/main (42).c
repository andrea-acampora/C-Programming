#include <stdio.h>
#include <stdlib.h>

    /*Realizzare un programma che calcoli il valore del fattoriale di un numero inserito da utente tramite una funzione ricorsiva;
    il programma deve stampare le variabili locali e i parametri di ogni chiamata alla funzione ricorsiva. In particolare,
    per ogni chiamata ricorsiva, visualizzare l’output su una riga separata e aggiungere un livello di rientro.
    Fate del vostro meglio per rendere l’output chiaro, interessante e significativo.
    L’obiettivo è quello di progettare e implementare un formato dell’output che aiuti l'utente a comprendere il meccanismo della ricorsione.*/

/*Funzione che calcola fattoriale*/
int fattoriale(int num)
{
    if(num==1)
    {
        return 1;
    }
    else
    {
         return  num *fattoriale(num-1); /*ricorsione*/
    }
}


int main()
{
    int numero;
    int risultato;
    int control;

    /*Inserimento dal numero*/
    do
    {
        printf("Enter the number from 1 to 12: ");
        control = scanf("%d",&numero);
        fflush(stdin);
    }while(control != 1 || numero<1 || numero>12); /*Controllo dall'input*/

    /*funzione*/
    risultato = fattoriale(numero);

    /*stampa risultato*/
    printf("\n\tFactorial: %d\n",risultato);

    return 0;
}


