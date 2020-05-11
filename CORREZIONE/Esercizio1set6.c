#include <stdio.h>
#include <stdlib.h>
#define DIMENSIONE 10
//dichiarazione delle funzioni
int *cerca(int [],int,int);
int *cerca_ordinato(int [],int,int);
void ordina_vettore(int [],int);

int main(){
    //istanzio le variabili ed il vettore di numeri
    int vettore[DIMENSIONE],elem,controllo,*risultato,count=0;
    printf("Inserisci 10 numeri interi.\n");
    //chiedo all'utente di inserire n interi
    for(int count=0;count<DIMENSIONE;count++){
        printf("Inserisci un numero: ");
        controllo = scanf("%d",&vettore[count]);
        fflush(stdin);
        //se l'utente non ha inserito un intero, esco dal programma
        if(controllo!=1){
            printf("Valore inserito non corretto.\n");
        }
    }
    //chiedo all'utente di inserire il numero da ricercare nel vettore
    printf("Inserisci il numero da cercare: ");
    controllo = scanf("%d",&elem);
    fflush(stdin);
    //se l'utente non ha inserito un intero, esco dal programma
    if(controllo!=1){
        printf("Valore inserito non corretto.\n");
    }

    printf("\nRicerca con vettore non ordinato. Vettore:\n");
    //stampo il vettore
    for(int count=0;count<DIMENSIONE;count++){
        printf("%3d ",vettore[count]);
    }
    printf("\n\n");
    //richiamo la funzione che cerca l'elemento nel vettore
    risultato=cerca(vettore,DIMENSIONE,elem);
    //a seconda del risultato, stampo uno specifico commento
    if(*risultato==-1){
        printf("Non sono state trovate corrispondenze.\n");
    }else{
        count=0;
        //scorro tutti gli elementi del risultato
        while(risultato[count]!=-1){
            printf("Corrispondenza nell'indice %d.\n",risultato[count]);
            count++;
        }
        free(risultato);
    }

    //ordino il vettore
    ordina_vettore(vettore,DIMENSIONE);
    printf("\nRicerca con vettore ordinato. Vettore: \n");
    //stampo il vettore
    for(int count=0;count<DIMENSIONE;count++){
        printf("%3d ",vettore[count]);
    }
    printf("\n\n");
    //richiamo la funzione che cerca l'elemento nel vettore ordinato
    risultato=cerca_ordinato(vettore,DIMENSIONE,elem);
    //a seconda del risultato, stampo uno specifico commento
    if(*risultato==-1){
        printf("Non sono state trovate corrispondenze.\n");
    }else{
        count=0;
        //scorro tutti gli elementi del risultato
        while(risultato[count]!=-1){
            printf("Corrispondenza nell'indice %d.\n",risultato[count]);
            count++;
        }
        free(risultato);
    }

    getchar();
    return 0;

}
//funzione che cerca un elemento in un vettore di interi
int *cerca(int vettore[],int dimensione,int numero){
    //riservo uno spazio in memoria per memorizziare gli indici dov'e' presente l'elemento
    int ricorrenze=0;
    int *risultato;
    int posizione=0;

    //conto il numero di ricorrenze così da non allocare spazio inutile in memoria
    for(int count=0;count<dimensione;count++){
        //se l'elemento attuale del vettore è uguale al numero che sto cercando, aumento di uno il numero di ricorrenze
        if(vettore[count]==numero)
            ricorrenze++;
    }
    //se non ci sono ricorrenze, ritorno -1
    if(ricorrenze==0){
        risultato = (int *) malloc(sizeof(int));
        *risultato=-1;
        return risultato;
    }
    //altrimenti alloco in memoria lo spazio che necessito (ricorrenze+1 perchè l'ultimo spazio indica la fine del vettore)
    risultato = (int *) malloc(sizeof(int)*ricorrenze+1);
    //scorro tutti gli elementi del vettore
    for(int count=0;count<dimensione;count++){
        //se l'elemento attuale del vettore è uguale al numero che sto cercando, inserisco l'indice nel risultato
        if(vettore[count]==numero){
            risultato[posizione] = count;
            //avanzo di una posizione nel risultato
            posizione++;
        }
        //indico la fine del vettore
    }
    risultato[posizione]=-1;
    //ritorno il risultato
    return risultato;
}

//funzione che cerca un elemento in un vettore di interi ordinato
int *cerca_ordinato(int vettore[],int dimensione,int numero){
    //riservo uno spazio in memoria per memorizziare gli indici dov'e' presente l'elemento
    int ricorrenze=0,posizione=0,indice,count;
    int *risultato;

    //conto il numero di ricorrenze così da non allocare spazio inutile in memoria; cerco l'indice dov'e' presente la prima ricorrenza
    for(indice=0;indice<dimensione;indice++){
        //se l'elemento attuale del vettore è uguale al numero che sto cercando, esco dal ciclo
        if(vettore[indice]==numero)
            break;
    }
    //se ci sono ricorrenze
    if(indice!=dimensione){
        //uso una variabile diversa perchè l'indice della prima ricorrenza mi servirà in seguito
        count=indice;
        //scorro finchè trovo ricorrenze (e aumento le ricorrenze di uno)
        do{
            ricorrenze++;
            count++;
        }while(count<dimensione && vettore[count]==numero);
    //altrimenti ritorno -1
    }else{
        risultato = (int *) malloc(sizeof(int));
        *risultato=-1;
        return risultato;
    }
    //alloco in memoria lo spazio che necessito (ricorrenze+1 perchè l'ultimo spazio indica la fine del vettore)
    risultato = (int *) malloc(sizeof(int)*ricorrenze+1);
    //a partire dalla prima ricorrenza, scorro il vettore finchè trovo ricorrenze e salvo gli indici del vettore nel risultato
    do{
        risultato[posizione] = indice;
        //avanzo di una posizione nel risultato
        posizione++;
        indice++;
    }while(indice<dimensione && vettore[indice]==numero);
    risultato[posizione]=-1;
    //ritorno il risultato
    return risultato;
}

void ordina_vettore(int vettore[],int dimensione){
    //istanzio i contatori
    int count1=0,count2=0;
    int temp;
    //algoritmo di ordinamento bubble sort
    for(count1=0; count1<dimensione-1; count1++){
        for(count2=0; count2<dimensione-count1-1; count2++){
            //se il valore a sinistra è maggiore di quello a destra, li scambio
            if(vettore[count2]>vettore[count2+1]){
                temp=vettore[count2];
                vettore[count2]=vettore[count2+1];
                vettore[count2+1]=temp;
			}
		}
    }
}
