#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
/*
    Funzione che dato un massimo trova tutti i numeri primi n'precedenti
    Ritorno: vettore in cui alla prima posizione è inserito il numero di numeri primi e poi a seguire i numeri primi
    Parametri: numero massimo entro cui trovare i numeri primi
*/
int * TrovaNumeriPrimi(int max)
{
    int *numPrimi,dimensione=50,i,j,numeroPrimi=0,flag;
    if(!(numPrimi=(int*)malloc(dimensione*sizeof(int))))
    {
        printf("Memoria insufficente");
        exit(1);//chiusura prematura del programma per mancata allocazione di memoria
    }
    *(numPrimi+1)=2;
    numeroPrimi++;
    for(i=3;i<max;i++)
    {
        flag=0;
        for(j=2;j<=numeroPrimi;j++)
        {
            if(i%*(numPrimi+j)==0)
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            if(numeroPrimi==dimensione)
            {
                dimensione+=50;
                if(!(numPrimi=(int*)realloc(numPrimi,dimensione*sizeof(int))))
                {
                    printf("Memoria insufficente");
                    exit(1);//chiusura prematura del programma per mancata allocazione di memoria
                }
            }
            *(numPrimi+numeroPrimi+1)=i;
            numeroPrimi++;
        }
    }
    *numPrimi=numeroPrimi;
    return numPrimi;
}

/*
    Funzione che dato un vettore e la sua dimensione stampa gli elementi
    Parametri: vettore da stampare, dimensione del vettore
*/
void StampaVettore(int vet[],int dim)
{
    int i;
    for(i=0;i<dim;i++)
    {
        printf("%d\n",vet[i]);
    }
}
int main()
{
    int numero=0,verifica,*numeriPrimi;
    //Input del numero massimo entro cui trovere i numeri primi
    do
    {
        printf("Inserire un numero massimo entro cui trovare i numeri primi: ");
        verifica=scanf("%d",&numero);
        fflush(stdin);
    }while(verifica!=1||numero<2);
    numeriPrimi=TrovaNumeriPrimi(numero);//chiamata alla funzione per trovare i numeri primi minori del parametro attuale
    printf("Numeri primi minori di %d\n",numero);
    StampaVettore(numeriPrimi+1,*numeriPrimi);//chiamata alla funzione per stampare il vettore
    free(numeriPrimi);
    system("pause");
    return 0;
}
