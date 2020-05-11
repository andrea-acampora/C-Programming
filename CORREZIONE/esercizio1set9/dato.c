#include <stdio.h>
#include <stdlib.h>
#include "dato.h"

//funzione che chiede all'utente delle informazioni per creare il dato da inserire nel nodo di una lista
TipoDato ottieniDato(){
    TipoDato nuovoDato;
    int controllo;
    do{
        printf("Inserisci il dato: ");
        controllo=scanf("%d",&nuovoDato);
        fflush(stdin);
    }while(controllo!=1);
    return nuovoDato;
}
int confrontaDati(TipoDato dato1,TipoDato dato2){
    return (dato1==dato2)?1:0;
}
