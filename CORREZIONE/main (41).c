#include <stdio.h>
#include <stdlib.h>

//funzione per l'indentazione ad ogni ricorsiva
int indentazione(int volte) //passo il parametro volte per memorizzare quante volte la ricorsiva viene richiamata
{
    int i;
    for(i=0;i<volte;i++)
    {
        printf("\t");
    }
}
//funzione per il calcolo del fattoriale
int fattoriale(int n) //passo il numero del quale si vuole calcolare il fattoriale
{
    static risultato,copiaN,cont=0; //static per mantenere i valori e mostrare le variabili locali
    if(n<=1)
    {
        printf("||CASO BASE||-->Il risultato del fattoriale di 1 e': 1\n");//caso base che produce la chiusura delle varie ricorsive
        return(1);
    }
    risultato=fattoriale(n-1)*n; //per il valore di ritorno e mostrare il risultato finale

    copiaN=n;
    cont++; //parametro che passo alla funzione indentazione

    indentazione(cont);

    printf("||DENTRO ALLA RICORSIVA||-->Il risultato del fattoriale di %d e': %d\n",copiaN,risultato); //output mostrato ad ogni ricorsiva
    return risultato;
}

int main()
{
    int numero,controllo,risultato;
    printf("Inserire un numero il quale si vuole calcolare il fattoriale (MIN 0, MAX 15): "); //inserimento numero per calcolo del fattoriale
    controllo=scanf("%d",&numero); //controllo inserimento die ventuale stringa
    printf("\n\n");
    printf("\n --------------- OUTPUT DI OGNI CHIAMATA RICORSIVA(APRI L'INTERA FINESTRA) ---------------- \n\n\n");
    fflush(stdin);
    //controllo massimo, minimo e stringa
    do
    {
        if(numero>15 || numero<0 || controllo==0)
        {
            printf("ERRORE, REINSERIRE: ");
            controllo=scanf("%d",&numero);
            fflush(stdin);
        }
    }
    while(numero>15 || numero<0 || controllo==0);

    risultato=fattoriale(numero);
    printf("\n\n\n --------------------- IL RISULTATO E': %d -------------------- \n\n\n",risultato); //output risultato finale

    return 0;
}
