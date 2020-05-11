#include <stdio.h>
#include <stdlib.h>
#include "libdinamica.h"
#include "dato.h"

//funzione che crea la lista allocata dinamicamente
TipoListaDinamica creaListaDinamica(){
    TipoListaDinamica lista={NULL,0,EMPTYLIST};
    //alloco la memoria per la lista, controllando che ci sia abbastanza spazio
    lista.dati = (TipoDato *) malloc (DIM*sizeof(TipoDato));
    if(lista.dati!=NULL){
        lista.dimensione = DIM;
    }
    return lista;
}

void eliminaListaDinamica(TipoListaDinamica *lista){
    //se la lista non e' nulla, dealloco la memoria riservata alla lista
    if(lista!=NULL){
        free(lista->dati);
    }
    //setto i parametri al loro valore di default
    lista->dimensione=0;
    lista->last=EMPTYLIST;
}

int estendiListaDinamica(TipoListaDinamica *lista){
    //se la lista è piena, raddoppio lo spazio allocato ad essa
    if(fullDinamico(lista)){
        TipoDato *tmp;
        tmp=(TipoDato *) realloc(lista->dati,2*lista->dimensione*sizeof(TipoDato));
        //controllo se c'e' abbastanza spazio in memoria
        if(tmp!=NULL){
            //la lista è stata riallocata correttamente, raddoppio il valore che indica la dimensione della lista
            lista->dati=tmp;
            lista->dimensione*=2;
            return 1;
        }
    }
    return 0;
}

int fullDinamico(const TipoListaDinamica *lista){
    //controllo se l'ultimo elemento della lista e' salvato nell'ultima posizione disponibile
    return(lista->last==(lista->dimensione-1));
}

int emptyDinamico(const TipoListaDinamica *lista){
    //controllo se la lista è vuota
    return(lista->last==EMPTYLIST);
}

void inserisciInTestaDinamico(TipoListaDinamica *lista,TipoDato dato){
     //se la lista è piena la estendo
    if(fullDinamico(lista)){
        if(!estendiListaDinamica(lista)){
            return;
        }
    }
    //faccio scorrere tutti gli elementi di una posizione avanti
    for(int count=lista->last;count>=0;count--){
        lista->dati[count+1]=lista->dati[count];
    }
    //la testa diventa il nuovo elemento
    lista->dati[0]=dato;
    lista->last++;
}

void inserisciInCodaDinamico(TipoListaDinamica *lista,TipoDato dato){
    //se la lista è piena la estendo
    if(fullDinamico(lista)){
        if(!estendiListaDinamica(lista)){
            return;
        }
    }
    //metto il nuovo elemento nella nuova posizione
    lista->last++;
    lista->dati[lista->last]=dato;
}

void inserisciDopoPosizioneDinamico(TipoListaDinamica *lista,TipoDato dato,int posizione){
    //se la lista è piena la estendo
    if(fullDinamico(lista)){
        if(!estendiListaDinamica(lista)){
            return;
        }
    }
    if(posizione>=0 && posizione<=lista->last){
        //faccio scorrere gli elementi davanti alla posizione selezionata di una posizione avanti
        for(int count=lista->last;count>=posizione+1;count--){
            lista->dati[count+1]=lista->dati[count];
        }
        //metto i nuovo elemento nella posizione successiva a quella selezionata
        lista->dati[posizione+1]=dato;
        lista->last++;
    }
}

void cancellaDaCodaDinamico(TipoListaDinamica *lista){
    //se la lista non è vuota...
    if(!emptyDinamico(lista)){
        //il penultimo elemento diventa l'ultimo
        lista->last--;
    }
}

void cancellaDaTestaDinamico(TipoListaDinamica *lista){
    //se la lista non è vuota...
    if(!emptyDinamico(lista)){
        //faccio scorrere di una posizione indietro tutti gli elementi
        for(int count=0;count<lista->last;count++){
            lista->dati[count]=lista->dati[count+1];
        }
        //diminuisco di uno la posizione dell'ultimo elemento
        lista->last--;
    }
}

void cancellaOccorrenzaDinamico(TipoListaDinamica *lista,TipoDato dato){
    //cerco l'elemento nella lista
    int indice = cercaDinamico(lista,dato);
    //se è presente...
    if(indice!=-1){
        //scorro di una posizione indietro tutti gli elementi successivi ad esso
        for(int count=indice;count<lista->last;count++){
            lista->dati[count]=lista->dati[count+1];
        }
        //diminuisco di uno la posizione dell'ultimo elemento
        lista->last--;
    }
}

//ritorna l'indice del primo nodo del quale la parte dati combacia con quella inserita dall'utente (se non ci sono corrispondenze, ritorna -1)
int cercaDinamico(const TipoListaDinamica *lista,TipoDato dato){
    //se la lista non è vuota, scorro tutti i suoi elementi (se trovo una corrispondenza, ritorno l'indice del nodo)
    if(!emptyDinamico(lista)){
        for(int count=0;count<=lista->last;count++){
            if(confrontaDati(lista->dati[count],dato)==1){
                return count;
            }
        }
    }
    return -1;
}


void statoListaDinamica(const TipoListaDinamica *lista){
    printf("\nLista attuale:\nDimesione: %d;\n\n",lista->dimensione);
    if(lista->last==EMPTYLIST){
        printf("Lista vuota.\n");
    }else{
        //stampo le informazioni di ogni elemento
        for(int count=0;count<=lista->last;count++){
            printf("| %3d ",lista->dati[count]);
        }
        printf("|\n");
    }
}
