/**ESERCIZIO 1
Realizzare un programma che calcoli il valore del fattoriale di un numero inserito da utente tramite una funzione
ricorsiva; il programma deve stampare le variabili locali e i parametri di ogni chiamata alla funzione ricorsiva.
In particolare, per ogni chiamata ricorsiva, visualizzare l’output su una riga separata e aggiungere un livello
di rientro. Fate del vostro meglio per rendere l’output chiaro, interessante e significativo. L’obiettivo è
quello di progettare e implementare un formato dell’output che aiuti l'utente a comprendere il meccanismo della
ricorsione.*/
#include <stdio.h>
#include <stdlib.h>

/*Istruzione: scrivo una funzione ricorsiva*/
int calcola_fattoriale(int n)
{
    static int contatore=0;//variabile statica
    unsigned long long int ris=1;

    /*Istruzione: se il valore inserito è 0 il fattoriale è 1*/
    if (n==0)
    {
        printf("1");
        return 1;
    }

    /*Istruzione: calcolo fattoriale*/
    else if(n!=1)
    {
        ris=n*calcola_fattoriale(n-1);
        for(int k=0;k<contatore;k++)//indenta
            printf("  ");
        printf("richiamo funzione ricorsiva ");
        printf("%d * %d!= %ld \n",n,n-1,ris);//stampa tutti i passaggi
        contatore++;
        return ris;
    }
}

int main(void)
{
    /*Istruzione: dichiaro variabili locali*/
    int n,c;
    printf("Enter a number: ");
    c=scanf("%d", &n);
    fflush(stdin);
    while(c==0)//se non è un numero allora chiede nuovamente l'inserimento
    {
        printf("Valore errato, inserisci nuovamente il numero\n");
        c=scanf("%d", &n);
        fflush(stdin);
    }
    printf("%d! = \n",n);

    /*Istruzione: chiama funzione ricorsiva*/
    calcola_fattoriale(n);
    printf("\n");
return 0;
}
