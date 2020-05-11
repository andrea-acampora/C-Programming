#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "lista_strutture_concatenate.h"

/*Funzione per inizializzare la lista a vuota*/
void InitLista(TipoLista*lis)
{
    *lis=NULL;
}

/*Funzione per inserire le informazioni del libro*/
void inserisci_info(TipoLista *lis,TipoLista paux)
{
    /*Variabili di tipo int per i controlli*/
    int valoreScanf;
    int contaNo;
    TipoLista controlloCodice;

    /*Inserimento titolo*/
    printf("\nQual e' il titolo del libro\? ");
    do
    {
        fgets(paux->info.titolo,NOME,stdin);
        fflush(stdin);
    }
    while(paux->info.titolo[0]=='\n');

    /*Inserimento autore*/
    printf("\nQual e' il nome dell'autore\? ");
    do
    {

        fgets(paux->info.autore,NOME,stdin);
        fflush(stdin);
        for(int i=0;paux->info.autore[i]!='\0';i++)
        {
           contaNo=0;
           if(isdigit(paux->info.autore[i])!=0)
           {
                printf("\nInserimento non valido\n");
                contaNo++;
                break;
           }
        }
    }
    while(paux->info.autore[0]=='\n'||contaNo!=0);

    /*Inserimento anno*/
    printf("\nIn che anno e' stato pubblicato\? ");
    do
    {
        valoreScanf=scanf("%d",&paux->info.annoPubblicazione);
        fflush(stdin);
        if(valoreScanf==0)
            printf("\nInserimento non valido\n");
    }
    while(valoreScanf==0);

    /*Inserimento casa editrice*/
    printf("\nDa quale casa editrice e' stato pubblicato\? ");
    do
    {
        fgets(paux->info.casaEditrice,NOME,stdin);
        fflush(stdin);

    }
    while(paux->info.casaEditrice[0]=='\n');

    /*Inserimento lunghezza*/
    printf("\nQuante pagine ha\? ");
    do
    {
        valoreScanf=scanf("%d",&paux->info.numeroPagine);
        fflush(stdin);
        if (valoreScanf==0)
            printf("\nInserimento non valido\n");
    }
    while(valoreScanf==0);

    /*Inserimento genere*/
    printf("\nA quale genere appartiene\? ");
    do
    {
        fgets(paux->info.genere,NOME,stdin);
        fflush(stdin);
        for(int i=0;paux->info.genere[i]!='\0';i++)
        {
           contaNo=0;
           if(isdigit(paux->info.genere[i])!=0)
           {
                printf("\nInserimento non valido\n");
                contaNo++;
                break;
           }
        }
    }
    while(paux->info.genere[0]=='\n'||contaNo!=0);

    /*Inserimento codice*/
    printf("\nInserisci il codice di 5 cifre: ");
    do
    {   controlloCodice=*lis;

        valoreScanf=scanf("%5d",&paux->info.codice);
        fflush(stdin);
        if(valoreScanf!=0)
        {
            contaNo=0;
            for(;controlloCodice!=NULL;)
            {
                if(controlloCodice->info.codice==paux->info.codice)
                {
                    printf("\nCodice già presente\n");
                    contaNo++;
                    break;
                }

                if(controlloCodice->next!=NULL)
                controlloCodice=controlloCodice->next;
                else
                    break;
            }

        }
        else
            printf("\nInserimento non valido\n");
    }
    while(valoreScanf==0||contaNo!=0);

    do
    {
        printf("\nInserisci valutazione da 1 a 10: ");
        valoreScanf=scanf("%d",&paux->info.valutazione);
        fflush(stdin);
        if(valoreScanf==0||(paux->info.valutazione<1||paux->info.valutazione>10))
            printf("\nInserimento non valido\n");
    }
    while(valoreScanf==0||(paux->info.valutazione<1||paux->info.valutazione>10));


}

/*Funzione per inserire in cima alla lista. Riceve in ingresso un puntatore al puntatore di tipo "TipoLista" e l'elemento da inserire*/
void InserisciTestaLista(TipoLista*lis)
{
    /*Inizializzo un puntatore ausiliario. Gli assegno l'indirizzo dato dalla "malloc" che alloca spazio per un unico elemento di "TipoNodoLista"(intero e puntatore)*/
    TipoLista paux;
    paux=(TipoLista)malloc(sizeof(TipoNodoLista));

    /*Controllo sul puntatore restituito dalla malloc*/
    if(paux!=NULL)
    {
       /*Assegno a info "elem" e faccio puntare "next" al contenuto del puntatore (ovvero il puntatore alla lista)*/
       inserisci_info(lis,paux);
       paux->next = *lis;

       /*Faccio puntare il puntatore alla lista a quello ausiliario*/
       *lis= paux;
    }
    else
        printf("Impossibile allocare memoria sufficiente.");
}

/*Funzione per inserire un elemento dopo uno già presente nella lista.*/
void inserisci_dopo_elemento(TipoLista *lis,int cercato)
{
    /*Due puntatori: il primo punterà alla zona allocata dalla malloc mentre il secondo per scorrere tutti gli elementi della lista*/
    TipoLista paux;
    TipoLista p_scorrimento;

    /*Contatore per informare l'utente del mancato inserimento*/
    int contaUguale=0;

    p_scorrimento=*lis;

    /*Ciclo "for" per controllare la presenza dell'elemento dopo il quale si vuole andare ad inserire*/
    for(;p_scorrimento!=NULL;)
    {
        /*Se p_scorrimento punta alla cella in cui c'è l'elemento cercato*/
        if(p_scorrimento->info.codice==cercato)
        {
            /*Chiamo la malloc*/
            paux=(TipoLista)malloc(sizeof (TipoElemLista));

            if(paux!=NULL)
                /*Inserisco l'elemento*/
                inserisci_info(lis,paux);
            else
                printf("\nNon e' possibile allocare memoria sufficiente");

            /*Faccio puntare il puntatore della nuova struttura alla cella che segue quella dove si trova l'elemento dopo cui devo inserire*/
            paux->next=p_scorrimento->next;
            /*Faccio puntare il puntatore della strutura in cui c'è "cercato" alla nuova struttura*/
            p_scorrimento->next=paux;
            /*Incremento*/
            contaUguale++;
            /*Interrompo il ciclo*/
            break;
        }
        else
            p_scorrimento=p_scorrimento->next;
    }

    if(contaUguale==0)
        printf("\nL'elemento non e' stato trovato.Impossibile inserire");
}

/*Funzione per inserire in fondo alla lista.*/
void InserisciCodaLista(TipoLista*lis)
{
    TipoLista ultimo;
    TipoLista paux;

    /*Alloco spazio per l'elemento che si vuole inserire*/
    paux= malloc(sizeof(TipoNodoLista));

    if(paux!=NULL)
    {
        /*Assegno a "info" "elem" e faccio puntare "next" a NULL*/
        inserisci_info(lis,paux);
        paux->next = NULL;

        /*Se il puntatore alla lista punta a NULL gli assegno il puntatore restituito dalla "malloc"*/
        if (*lis== NULL)
            *lis=paux;

        /*Se non punta a NULL:assegno l'indirizzo a "ultimo" puntatore che uso per scorrere la lista fino a che non trovo NULL*/
        else
        {
            ultimo = *lis;
            /*Assegno a ultimo ultimo->next (prima che arrivi a NULL)*/
            while (ultimo->next != NULL)
                ultimo=ultimo->next;
            /*Assegno a ultimo puntato a next il puntatore ausiliario*/
            ultimo->next=paux;
        }
    }
    else
        printf("Impossibile allocare spazio sufficiente.");
}

/*Funzione per cancellare il primo libro*/
void CancellaPrimoLista(TipoLista *lis)
{
    TipoLista paux;
    /*Se la lista non e' vuota*/
    if (*lis!= NULL)
    {
        /*Assegno a "paux" l'indirizzo della lista*/
        paux= *lis;
        /*Sposto il puntatore alla lista all'elemento dopo*/
        *lis= (*lis)->next;
        /*Chiamo la free*/
        free(paux);
    }
}

/*Funzione per cancellare uno specifico libro*/
void CancLista(TipoLista*lis, int cercato)
{
    TipoLista p_scorrimento;
    TipoLista precedente;
    /*Per scorrere*/
    p_scorrimento=*lis;
    /*Per puntare la casella che precede quella da eliminare*/
    precedente=*lis;

    if(*lis==NULL)
        printf("\nNon e' possibile effettuare l'operazione");
    else
    {
        /*Ciclo for per scorrere tutta la lista*/
        for(;p_scorrimento!=NULL;)
        {
            /*Se il puntatore di scorrimento punta alla cella col libro cercato(ovvero puntatore indica la cella da eliminare)*/
            if(p_scorrimento->info.codice==cercato)
            {
                /*Se e' il primo elemento chiamo "CancellaPrimoLista*/
                if(p_scorrimento==*lis)
                    CancellaPrimoLista(lis);

                /*Altrimenti assegno al puntatore all'elemento da eliminare il puntatore che segue e libero p_scorrimento che punta all'elemento da eliminare*/
                else
                {
                    precedente->next=p_scorrimento->next;
                    free(p_scorrimento);
                }
                break;
            }

            /*Se il puntatore non indica la cella da eliminare*/
            else
            {   /*Se sta controllando il primo elemento sposto solo p_scorrimento*/
                if(p_scorrimento==*lis)
                    p_scorrimento=p_scorrimento->next;

                /*Altrimenti sposto anche il puntatore precedente*/
                else
                {
                   precedente=precedente->next;
                   p_scorrimento=p_scorrimento->next;
                }
            }
        }

    }

}


/*Funzione per cancellare l'ultimo libro*/
void cancella_ultimo_elemento(TipoLista *lis)
{
    TipoLista p_scorrimento;
    TipoLista precedente;
    /*Per scorrere*/
    p_scorrimento=*lis;
    /*Per puntare la casella che precede quella da eliminare*/
    precedente=*lis;

    if(*lis==NULL)
        printf("\nNon e' possibile effettuare l'operazione");
    else
    {
        /*Ciclo for per scorrere tutta la lista*/
        for(;p_scorrimento!=NULL;)
        {
            /*Se il puntatore a next punta a NULL (ovvero puntatore indica la cella da eliminare)*/
            if(p_scorrimento->next==NULL)
            {
                /*Se e' il primo elemento chiamo "CancellaPrimoLista*/
                if(p_scorrimento==*lis)
                    CancellaPrimoLista(lis);

                /*Altrimenti assegno al puntatore all'elemento da eliminare NULL e libero p_scorrimento che punta all'elemento da eliminare*/
                else
                {
                    precedente->next=NULL;
                    free(p_scorrimento);
                }
                break;
            }

            /*Se il puntatore non indica la cella da eliminare*/
            else
            {   /*Se sta controllando il primo elemento sposto solo p_scorrimento*/
                if(p_scorrimento==*lis)
                    p_scorrimento=p_scorrimento->next;

                /*Altrimenti sposto anche il puntatore precedente*/
                else
                {
                   precedente=precedente->next;
                   p_scorrimento=p_scorrimento->next;
                }
            }
        }

    }

}

