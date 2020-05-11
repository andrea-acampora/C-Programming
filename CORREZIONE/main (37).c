#include <stdio.h>
#include <stdlib.h>
#define DIM 5

/*Lo scopo della funzione è controllare se il numero inserito è primo*/
/*Se è vero, restituisce il valore 1, altrimenti il valore 0*/
int nPrimo(int i)
{

    for(int n = 2; n<i; n++){
        if ((i%n)==0)
            return 0;
    }
    return 1;
}

int main()
{
    /*Dichiaro le variabili: 'i' è il n max, dimensione è il numero di celle di memoria che dovranno essere disponibili per ptrI*/
    int i, dimensione;
    int *ptrI;
    /*Creo un ciclo for perchè mi consente di inizializzare la variabile i1 che occuperebbe spazio inutile*/
    /*Il ciclo mi consente di controllare se il numero inserito dall'utente è o meno valido*/
    /*Ho preferito usqare un ciclo per non dover interrompere il programma nel caso l'utente inserisca un valore sbagliato*/
    for (int i1=0; i1==0;){
        printf("Inserire il numero di numeri: ");
        i1=scanf("%d", &i);
        fflush(stdin);
        /*Controllo se l'utente ha inserito un valore != int*/
        if(i1==0)
            printf("Errore nella digitazione: riprovare...\n");
        /*Controllo se il numero è negativo o = 0*/
        else if(i<=0){
            printf("Errore nella digitazione: NON puoi inserire numeri negativi o il valore 0...\n");
            i1=0;
        }
    }
    /*Uso la malloc per usufruire di DIM*sizeof(int) spazi di memoria liberi*/
    ptrI = (int *)malloc((DIM)*sizeof(int));
    /*Controllo se c'è spazzio*/
    if (ptrI==NULL){
        printf("Non e' stato trovato spazio in memoria...");
        exit(1);
    }
    dimensione=DIM;
    if(i==1){
        printf("\nIl numero 1 non è considerato primo");
        return 0;
    }
    else if(i==2){
        printf("Numero primo: 2");
        return 0;
    }
    else if(i==3){
        printf("Numero primo: 2\nNumero primo: 3");
        return 0;
    }
    else{
        for(int i1=0; i1<dimensione; i1++){
            if(i1==0)
                *(ptrI+i1)=2;
            else if(i1==1)
                *(ptrI+i1)=3;
            else
                *(ptrI+i1)=0;
        }
    }
    /*Uso il for per lo stesso morivo di prima*/
    /*i2 è il numero da controllare, c è il numero di controllo della funzione nPrimo, c1 è il numero che controlla la dimensione del puntatore dinamico*/
    for(int i2=4, c=0, c1=2; i2<=i; i2++){
        c=nPrimo(i2);
        /*Controllo se i1 è primo*/
        if(c!=0){
            /*REALLOC nel caso c sia uguale a dimensione*/
            if(c1==dimensione){
                ptrI = (int *) realloc(ptrI, (10+dimensione)*sizeof(int));
                /*Aggiorno dimensione*/
                dimensione+=10;
                /*Controllo se ha trovato spazio*/
                if (ptrI==NULL){
                    printf("Non e' stato trovato spazio in memoria...");
                    exit(1);
                }
                for(int c2=c1; c2<dimensione+1; c2++){
                    *(ptrI+c2)=0;
                }
            }
            *(ptrI+c1)=i2;
            c1++;
        }
    }
    /*Stampo i numeri primi memorizzati*/
    for(int i1=0; i1<=dimensione-1; i1++){
        printf("Numero primo: %d\n", *(ptrI+i1));
        if(*(ptrI+i1+1)==0)
            break;
    }
    free(ptrI);
    return 0;
}
