#include <stdio.h>
#include <stdlib.h>

int num_primo(int max)          //PRIMA FUNZIONE CON LA QUALE VERIFICO SE I NUMERI SONO PRIMI O NO
{
    int i;
    for(i=2; i<max; i++)
    {
        if(max%i==0)
        {
            return 0;           //SE NUMERO/TUTTI I NUMERI DA RESTO 0, NUMERO NON PRIMO
        }
    }
    return 1;           //AL CONTRARIO NUMERO PRIMO
}

int controlla_tutti(int max, int *array)            //SECONDA FUNZIONE CON LA QUALE CONTROLLO I RISULTATI DELLA PRIMA FUNZIONE E NEL CASO SIANO PRIMI LI MEMORIZZO E STAMPO DA ARRAY
{
    int i=0, k=0;
    array=malloc((max)*sizeof(int));            //DICHIARO MALLOC PER ALLOCAZIONE DINAMICA ARRAY
    if(array==NULL)
    {
        printf("spazio insufficiente !");       //FUNZIONE NULL MALLOC (LA FUNZIONE FREE E' ALLA FINE DEL MAIN)
    }
    for(i=0; i<=max; i++)
    {
        if(num_primo(i)==0)
        {
            printf("%d non e' primo\n", i);         //SE IL NUMERO NON E' PRIMO STAMPO DIRETTAMENTE CHE IL NUMERO NON E' PRIMO
        }
        else
        {
            *array=i;
            printf("%d e' primo\n", *array);     //SE IL NUMERO E' PRIMO, LO MEMORIZZO NELL'ARRAY USANDO LA NOTAZIONE VETTORIALE E POIMLO STAMPO
            k++;
        }
    }
}

int main()
{
    int max, *array;            //DICHIARO MAX(NUMERO FINO A CUI CALCOLARE I NUMERI PRIMI) E ARRAY (DOVE MEMORIZZARE UN NUMERO SE PRIMO)
    printf("inserisci valore massimo fino al quale trovare i numeri primi: ");      //INSERIMENTO VARIABILE MAX
    scanf("%d", &max);
    fflush(stdin);

    controlla_tutti(max, array);            //RICHIAMO LA SECONDA FUNZIONE PER LA STAMPA DEI RISULTATI

    free(array);            //FUNZIONE FREE RELATIVA ALL'ALLOCAZIONE DINAMICA
    return 0;           //FINE PROGRAMMA
}
