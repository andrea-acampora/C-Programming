#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*Avendo posto al vettore numBinario[] una grandezza di 8 elementi, il numero decimale da convertire
      dovrà essere compreso tra 0 e 255 */
    int numDecimale;
    int numBinario[8];
    int i = 0;
    int k;

    //Chiedo in input il numero in base decimale da convertire in binario
    printf("Inserire un numero in base decimale da convertire in binario:");
    scanf("%d",&numDecimale);

    //Controllo che il numero decimale sia compreso tra 0 e 255
    while (numDecimale < 0 || numDecimale > 255)
    {
        printf("Inserire un numero in base decimale compreso tra 0 e 255:");
        scanf("%d",&numDecimale);
    }

    /*Attraverso un ciclo while assegno agli elementi del vettore numBinario il resto della divisione per
      2 del numDecimale che dovrà successivamente dividersi per 2 fino ad arrivare a 0*/
    while (numDecimale != 0)
    {
        numBinario[i] = numDecimale % 2;
        numDecimale = numDecimale / 2;
        i++;
    }

    printf("\nIl corrispettivo numero binario equivale a: ");

    /*Con questo ciclo for stampo il vettore numBinario al contrario utilizzando un secondo contatore (k) per
      assicurarmi che non vengano stampati anche elementi a cui non ho assegnato un valore*/
    for (k = i - 1; k != -1; k--){
        printf("%d", numBinario[k]);

    }

    printf("\n\n");
    system("PAUSE");

    return 0;
}
