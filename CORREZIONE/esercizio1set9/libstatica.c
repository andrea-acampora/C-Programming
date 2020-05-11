#include <stdio.h>
#include <stdlib.h>
#include "libstatica.h"
#include "dato.h"

void initListaStatica(TipoLista *lista){
    //inizializzo il campo last
    lista->last=EMPTYLIST;
}

int fullStatico(const TipoLista *lista){
    //controllo se l'ultimo elemento della lista si trova nell'ultima posizione disponibile
    return(lista->last==(DIM-1));
}
int emptyStatico(const TipoLista *lista){
    //controllo se la lista è vuota
    return(lista->last==EMPTYLIST);
}

void inserisciInTestaStatico(TipoLista *lista,TipoDato dato){
    //se la lista non è piena...
    if(!fullStatico(lista)){
        //faccio scorrere tutti gli elementi di una posizione avanti
        for(int count=lista->last;count>=0;count--){
            lista->dati[count+1]=lista->dati[count];
        }
        //la testa diventa il nuovo elemento
        lista->dati[0]=dato;
        lista->last++;
    }
}

void inserisciDopoPosizioneStatico(TipoLista *lista,TipoDato dato,int posizione){
    //se la lista non è piena...
    if(!fullStatico(lista)){
        if(posizione>=0 && posizione<=lista->last){
            //faccio scorrere gli elementi davanti alla posizione selezionata di una posizione avanti
            for(int count=lista->last;count>posizione;count--){
                lista->dati[count+1]=lista->dati[count];
            }
            //metto i nuovo elemento nella posizione successiva a quella selezionata
            lista->dati[posizione+1]=dato;
            lista->last++;
        }
    }
}

void inserisciInCodaStatico(TipoLista *lista,TipoDato dato){
    //se la lista non è piena...
    if(!fullStatico(lista)){
        //metto il nuovo elemento nella nuova posizione
        lista->last++;
        lista->dati[lista->last]=dato;
    }
}

void cancellaDaCodaStatico(TipoLista *lista){
    //se la lista non è vuota...
    if(!emptyStatico(lista)){
        //il penultimo elemento diventa l'ultimo
        lista->last--;
    }
}

void cancellaDaTestaStatico(TipoLista *lista){
    //se la lista non è vuota...
    if(!emptyStatico(lista)){
        //faccio scorrere di una posizione indietro tutti gli elementi
        for(int count=0;count<lista->last;count++){
            lista->dati[count]=lista->dati[count+1];
        }
        //diminuisco di uno la posizione dell'ultimo elemento
        lista->last--;
    }
}

void cancellaOccorrenzaStatico(TipoLista *lista,TipoDato dato){
    //cerco l'elemento nella lista
    int indice = cerca(lista,dato);
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

void statoListaStatica(const TipoLista *lista){
    printf("\nLista attuale:\n\n");
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


//ritorna l'indice del primo nodo del quale la parte dati combacia con quella inserita dall'utente (se non ci sono corrispondenze, ritorna -1)
int cerca(const TipoLista *lista,TipoDato dato){
    //se la lista non è vuota, scorro tutti i suoi elementi (se trovo una corrispondenza, ritorno l'indice del nodo)
    if(!emptyStatico(lista)){
        for(int count=0;count<=lista->last;count++){
            if(confrontaDati(lista->dati[count],dato)==1){
                return count;
            }
        }
    }
    return -1;
}
