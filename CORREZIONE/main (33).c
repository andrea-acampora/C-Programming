#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define lunghezzaVett 5


int* findNumber(int vettore[],int len, int numberToFind){
    int *indici = NULL,*inizio = NULL,i=0;
    indici = (int*) malloc(sizeof(int)*len);
    inizio = indici;
    for (i=0;i<len;i++) *(indici+i) = -1;

    indici = inizio;
    for(i=0;i<len;i++){
        if(vettore[i] == numberToFind ){
            *indici = i;
            indici++;
        }
    }
    return inizio;
}

int* findNumberVettoreOrdinato(int vettore[],int len, int numberToFind){
    int *indici = NULL ,*inizio = NULL,i=0;
    bool t = true;
    indici = (int*) malloc(sizeof(int)*len);
    inizio = indici;
    for (i=0;i<len;i++) *(indici+i) = -1;
    indici = inizio;
    i=0;
    while(i<len && t){
        if(vettore[i] == numberToFind){
            *indici = i;
            indici++;
            if(vettore[i+1] != numberToFind) t = false;
        }

        i++;
    }
    return inizio;
}



//Funzione che scambia due elementi di un vettore
void scambia(int vett[], int el1, int el2){
    int k;
    k = vett[el2];
    vett[el2] = vett[el1];
    vett[el1] = k;
}

//Funzione per ordinare il vettore con il bubble sort
void ordinaVettore(int vett[]){
    int n = lunghezzaVett-1,i;
    int ultimoScambiato = n;
    while(ultimoScambiato>0){
        ultimoScambiato=0;
        for(i=0;i<n;i++){
            if(vett[i]>vett[i+1]){
                scambia(vett,i,i+1);
                ultimoScambiato = i;
            }
        }
        n = ultimoScambiato;
    }

}


int main() {
    int vettore[lunghezzaVett]; //Vettore inserito dall'utente
    int number=0; //Numero da trovare
    int i,j=0,*find;

    //Chiedo in input all'utente i valori da inserire nel vettore
    for (i=0;i<lunghezzaVett;i++){
        printf("\nInserisci elemento %d del vettore:",i);
        scanf("%d",&vettore[i]);
        fflush(stdin);
    }

    //Chiedo in input all'utente il numero da cercare
    printf("\nInserisci il numero che vuoi cercare all'interno del vettore:");
    scanf("%d",&number);
    find = findNumber(vettore, lunghezzaVett, number);
    if(*find == -1) printf("\nNessuna occorrenza trovata");
    else{
        printf("\nOccorrenza trovata alla posizione del vettore: ");
        while(*find != -1){
            printf("%d ",*find);
            find++;
        }
    }

    ordinaVettore(vettore);

    printf("\nVettore ordinato: ");
    for(i=0;i<lunghezzaVett;i++) printf("%d ",vettore[i]);

    find = findNumberVettoreOrdinato(vettore, lunghezzaVett, number);

    if(*find == -1) printf("\nNessuna occorrenza trovata");
    else{
        printf("\nOccorrenza trovata alla posizione del vettore: ");
        while(*find != -1){
            printf("%d ",*find);
            find++;
        }
    }

    return 0;
}
