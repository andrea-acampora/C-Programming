#include <stdio.h>
#include <stdlib.h>
#include "libpuntatori.h"
#include "dato.h"

void initLista(NodoLista **lista){
    //inizializzo il puntatore alla testa a void
    *lista = NULL;
}

void inserisciInTesta(NodoLista **lista,TipoDato dato){
    NodoLista *tmp = (NodoLista *) malloc(sizeof(NodoLista));
    if(tmp==NULL){
        printf("Spazio insufficiente.\n");
        return;
    }
    tmp->info=dato;
    tmp->next=*lista;
    *lista=tmp;
}

void inserisciInCoda(NodoLista **lista,TipoDato dato){
    //alloco la memoria per un nuovo nodo della lista
    NodoLista *tmp = (NodoLista *) malloc(sizeof(NodoLista));
    //controllo se ce spazio
    if(tmp==NULL){
        printf("Spazio insufficiente.\n");
        return;
    }
    //istanzio i campi del nuovo nodo
    tmp->info=dato;
    tmp->next=NULL;
    //se la lista è vuota, la testa diventa il nuovo elemento e la funzione termina
    if(*lista==NULL){
        *lista=tmp;
        return;
    }
    NodoLista *paux = *lista;
    //scorro la lista finchè non arrivo all'ultimo elemento
    while(paux->next!=NULL){
        paux=paux->next;
    }
    //faccio puntare l'ultimo elemento della lista al nuovo elemento
    paux->next=tmp;
}

void inserisciDopoPosizione(NodoLista **lista,TipoDato dato,int posizione){
    //controllo se la posizione è presente nella lista (in caso la lista sia nulla, nessuna posizione sarà accettata)
    if(posizione>=0 && posizione<contaElementi(*lista)){
        //alloco la memoria per un nuovo nodo della lista
        NodoLista *tmp = (NodoLista *) malloc(sizeof(NodoLista));
        //controllo se ce spazio
        if(tmp==NULL){
            printf("Spazio insufficiente.\n");
            return;
        }
        //imposto la parte dati del nuovo nodo
        tmp->info=dato;
        //creo un puntatore alla testa temporaneo
        NodoLista *paux=*lista;
        //scorro per n posizioni
        for(int i=0;i<posizione;i++){
            paux=paux->next;
        }
        //faccio puntare il nuovo elemento al nodo successivo al nodo nella posizione specificata dall'utente
        tmp->next=paux->next;
        //faccio puntare il nodo nella posizione specificata dall'utente al nuovo nodo
        paux->next=tmp;
    }
}

void cancellaDaTesta(NodoLista **lista){
    //se la testa non è nulla, tengo traccia di essa (per cancellarla) e, in seguito, la aggiorno
    if(*lista!=NULL){
        NodoLista *tmp=*lista;
        *lista=(*lista)->next;
        free(tmp);
    }
}

void cancellaDaCoda(NodoLista **lista){
    //creo un puntatore temporaneo per non perdere la testa
    NodoLista *tmp=*lista;
    NodoLista *paux;
    //se la testa è nulla, non faccio niente
    if(*lista==NULL){
        return;
    }
    //se la testa è l'ultimo nodo, la cancello
    if((*lista)->next==NULL){
        *lista=NULL;
        free(tmp);
        return;
    }
    //scorro finchè non vedo che l'elemento successivo a quello che sto puntando è l'ultimo elemento
    while(tmp->next->next!=NULL){
        tmp=tmp->next;
    }
    //salvo l'indirizzo dell'ultimo elemento in un puntatore temporaneo (che mi servirà per deallocare la memoria)
    paux=tmp->next;
    //faccio diventare il penutlimo elemento nell'ultimo elemento
    tmp->next=NULL;
    free(paux);
}

void cancellaOccorrenza(NodoLista **lista,TipoDato dato){
    //creo un puntatore temporaneo per non perdere la testa
    NodoLista *tmp=*lista;
    NodoLista *paux;
    //se la testa è nulla, non faccio niente
    if(*lista==NULL){
        return;
    }
    //se la testa contiene l'informazione, la cancello
    if(confrontaDati(tmp->info,dato)){
        *lista=(*lista)->next;
        free(tmp);
        return;
    }
    //scorro finchè non vedo che l'elemento successivo a quello che sto puntando contiene l'informazione cercata
    while(tmp->next!=NULL && confrontaDati(tmp->next->info,dato)==0){
        tmp=tmp->next;
    }
    //se ho trovato la corrispondenza...
    if(tmp->next!=NULL){
        //salvo l'indirizzo dell'elemento trovato in un puntatore temporaneo (che mi servirà per deallocare la memoria)
        paux=tmp->next;
        //collego l'elemento precedente all'elemento trovato al successivo
        tmp->next=paux->next;
        free(paux);
    }
}

void statoLista(NodoLista *lista){
    printf("\nLista attuale: \nNumero elementi: %d.\n\n",contaElementi(lista));
    //scorro tutta la lista e ne stampo il contenuto
    if(lista==NULL){
        printf("Lista vuota.\n");
        return;
    }
    while(lista!=NULL){
        printf("| %3d ",lista->info);
        lista=lista->next;
    }
    printf("|\n");
}

int contaElementi(NodoLista *lista){ //RICORSIVA
    //caso base
    if(lista==NULL){
        return 0;
    }
    //aggiungo uno al numero di elementi della sottolista che parte da lista->next
    return 1+(contaElementi(lista->next));
}

void cancellaLista(NodoLista **lista){
    //scorro finchè la testa non è nulla
    while(*lista!=NULL){
        //tengo traccia della testa attuale
        NodoLista *tmp =*lista;
        //avanzo al prossimo elemento
        *lista=(*lista)->next;
        //cancello la testa precedente
        free(tmp);
    }
}
