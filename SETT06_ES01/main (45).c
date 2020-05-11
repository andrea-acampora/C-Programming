#include <stdio.h>
#include <stdlib.h>
#define NUM_MAX 50
int *cerca(int *vettore,int dimensione,int elemento)     /*FUNZIONE CERCA*/
{
    int i=0,j=0;     /*DICHIARAZIONE VARIABILI*/
    int *vetpos=(int*)malloc(sizeof(int)*dimensione);       /*MEMORIZZO DINAMICAMENTE UN VETTORE*/
    if(vetpos==NULL)
        printf("\nErrore nell'allocare la memoria");
    for(i=0;i<dimensione;i++)                       /*INSTANZIO IL VETTORE DINAMICO CON TUTTI -1 COSI' SE NON CI SONO STAMPO IL PRIMO VALORE*/
    {
        vetpos[i]=-1;
    }
    for(i=0;i<dimensione;i++){
        if(elemento==*(vettore+i)){ /*SCORRO VETTORE E CONTROLLO CORRISPONDENZA CON ELEMENTO DA CERCARE*/
            vetpos[j]=i;        /*SE SI MEMORIZZO*/
            j++;
        }
    }
    return (vetpos);       /*RITORNO PUNTATORE A VETTORE DINAMICO*/
}
int *cerca_ordinato(int *vettore,int dimensione,int elemento)     /*FUNZIONE CERCA*/
{
    int i=0,j=0;     /*DICHIARAZIONE VARIABILI*/
    int *vetpos=(int*)malloc(sizeof(int)*dimensione);       /*MEMORIZZO DINAMICAMENTE UN VETTORE*/
    if(vetpos==NULL)
        printf("\nErrore nell'allocare la memoria");
    for(i=0;i<dimensione;i++)                       /*INSTANZIO IL VETTORE DINAMICO CON TUTTI -1 COSI' SE NON CI SONO STAMPO IL PRIMO VALORE*/
    {
        vetpos[i]=-1;
    }
    for(i=0;i<dimensione;i++){
        if(elemento==*(vettore+i)){ /*SCORRO VETTORE E CONTROLLO CORRISPONDENZA CON ELEMENTO DA CERCARE*/
            vetpos[j]=i;        /*SE SI MEMORIZZO*/
            j++;
        }
        if(elemento!=*(vettore+i+1))
            return(vetpos);
    }     /*RITORNO PUNTATORE A VETTORE DINAMICO*/
}

int main()
{
    int dimensione,i=0,elemento,*punt;      /*DICHIARAZIONE VARIABILI*/
    do{
    printf("Inserire il numero di elementi del vettore (max 50 elementi) :");   /*INSERIMENTO DIMENSIONE*/
    scanf("%d",&dimensione);
    fflush(stdin);
    }
    while(dimensione<=0||dimensione>NUM_MAX+1);     /*NEI LIMITI STABILITI*/
    int vettore[dimensione];
    for(i=0;i<dimensione;i++){
        printf("\nInserire l'elemento %d :",i+1);       /*CARICAMENTO VETTORE*/
        scanf("%d",&vettore[i]);
        fflush(stdin);
    }
    printf("\nInserire l'elemento da cercare :");       /*INSERIRE ELEMENTO DA CERCARE*/
    scanf("%d",&elemento);
    punt=cerca(vettore,dimensione,elemento);
    if (*punt==-1)  /*SE IL VETTORE HA COME PRIMO ELEMENTO -1 E QUINDI NON CI SONO CORRISPONDENZE LO STAMPO*/
        printf("\n-1-> L'elemento cercato non e' presente nel vettore");
    else {
        for (i=0;i<dimensione&&*(punt+i)!=-1;i++){      /*SE NO STAMPO GLI ELEMENTI COMUNI NEL VETTORE FINCHE' NON SI ARRIVA ALL'ELEMENTO (POSIZIONE) -1 E QUINDI SONO FINITI GLI ELEMENTI COMUNI*/
        printf("\nL'elemento cercato e' in posizione :%d ",*(punt+i));
}
    }
free(punt);


printf("\n\n\n\n\n ESERCIZIO SU INSIEME ORDINATO\n\n");
    do{
    printf("Inserire il numero di elementi del vettore (max 50 elementi) :");   /*INSERIMENTO DIMENSIONE*/
    scanf("%d",&dimensione);
    fflush(stdin);
    }
    while(dimensione<=0||dimensione>NUM_MAX+1);     /*NEI LIMITI STABILITI*/
    int vettore2[dimensione];
    for(i=0;i<dimensione;i++){
        printf("\nInserire l'elemento %d :",i+1);       /*CARICAMENTO VETTORE*/
        scanf("%d",&vettore2[i]);
        fflush(stdin);
    }
    printf("\nInserire l'elemento da cercare :");       /*INSERIRE ELEMENTO DA CERCARE*/
    scanf("%d",&elemento);
    punt=cerca_ordinato(vettore2,dimensione,elemento);
    if (*punt==-1)  /*SE IL VETTORE HA COME PRIMO ELEMENTO -1 E QUINDI NON CI SONO CORRISPONDENZE LO STAMPO*/
        printf("\n-1-> L'elemento cercato non e' presente nel vettore");
    else {
        for (i=0;i<dimensione&&*(punt+i)!=-1;i++){      /*SE NO STAMPO GLI ELEMENTI COMUNI NEL VETTORE FINCHE' NON SI ARRIVA ALL'ELEMENTO (POSIZIONE) -1 E QUINDI SONO FINITI GLI ELEMENTI COMUNI*/
        printf("\nL'elemento cercato e' in posizione :%d ",*(punt+i));
}
    }
free(punt);
   return 0;
}
