#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numDec, a, mod, numBinSize=8; //a è una variabile d'appoggio per il controllo dell'errore
    int numBin[8]={0,0,0,0,0,0,0,0};

    printf("CONVERSIONE DA DECIMALE A BINARIO\nSi accettano valori interi positivi da 0 a 100. Eventuali numeri con la virgola verranno approssimati per difetto.\nInserire un numero intero positivo: ");
    a=scanf("%d",&numDec); //Inserimento del numero decimale da convertire
    fflush(stdin);
    if (a!=1 || numDec<0 || numDec>100) //in caso di errore...
    {
        printf("ERRORE: inserire un numero valido!\nL'esecuzione verra' terminata...");
    }
    else
    {
        /*int indice=numBinSize-1; ////////
        do
        {
            mod=numDec%2;
            numDec/=2;

        }
        while();*/

        /*for (int i=numBinSize-1; numDec>1; i--, numDec/=2)
        {
            numBin[i]=numDec%2;    ////////
        }

        for (int i2=)*/
        for (int i=0; numDec>0; i++, numDec/=2) //ciclo che converte il numero da decimale a binario. Ogni cifra del numero binario viene salvata come elemento del vettore "numBin"
        {

            numBin[i]=numDec%2;
        }

        for (int i=0, trasl, j=numBinSize-1;i<numBinSize/2;i++,j--) //ribaltamento del vettore: per una corretta lettura del numero appena convertito
        {
                trasl=numBin[i];
                numBin[i]=numBin[j];
                numBin[j]=trasl;
        }

        printf("Il numero equivale a: ");
        for (int i=0; i<numBinSize;i++) //stampa del vettore contenente il numero binario
        {
            printf("%d",numBin[i]);
        }
    }
}
