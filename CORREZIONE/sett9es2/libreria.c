#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "libreria.h"

//Lista
//Pulisce la memoria
void resetLista(struct libro **t)
{
    struct libro *temp;

    while (*t != NULL)
    {
        temp = *t;
        *t = (*t)->next;
        free(temp);
    }
}
//Restituisce 1 se l'elemento e' stato eliminato, 0 altrimenti
int eliminaLibro(struct libro **t, int codice2)
{
    struct libro *prec, *temp;

    temp = *t;
    prec = NULL;

    while (temp != NULL)
    {
        if (temp->codice == codice2)
        {
            if (prec == NULL)
                *t = (*t)->next;
            else
                prec->next = temp->next;
            free(temp);
            return true;
        }
        prec = temp;
        temp = temp->next;
    }

    return false;
}
/*
La testa viene passata per valore quindi le modifiche non vengono viste all'esterno
La funzione restituisce la posizione della cella in cui � stato trovato il valore, 0 altrimenti
*/
int cercaLibro(struct libro *t, int codice)
{
    while (t != NULL)
    {
        if (t->codice == codice)
            return true;
        t = t->next;
    }
    return false;
}

void stampaTuttiLibri(struct libro *t)//La testa viene passata per valore quindi le modifiche non vengono viste all'esterno
{
    if (t == NULL)
    {
        printf(" La lista e\' vuota!\n");
        return;
    }

    while (t != NULL)
    {
        printf("Titolo: %s\n",t->titolo);
        printf("Autore: %s\n",t->autore);
        printf("Anno pubblicazione: %d\n",t->anno_pubb);
        printf("Casa editrice: %s\n",t->casa_ed);
        printf("Lunghezza: %d\n",t->lunghezza);
        printf("Genere: %s\n",t->genere);
        printf("Codice: %d\n",t->codice);
        printf("Valutazione: %d\n\n\n",t->valutazione);
        t = t->next;
    }
}

void stampaLibriValutazione(struct libro *t, int valutazione2)
{
    if (t == NULL)
    {
        printf(" La lista e\' vuota!\n");
        return;
    }
    while (t != NULL)
    {
        if (t -> valutazione >= valutazione2)
        {
            printf("Titolo: %s\n",t->titolo);
            printf("Autore: %s\n",t->autore);
            printf("Anno pubblicazione: %d\n",t->anno_pubb);
            printf("Casa editrice: %s\n",t->casa_ed);
            printf("Lunghezza: %d\n",t->lunghezza);
            printf("Genere: %s\n",t->genere);
            printf("Codice: %d\n",t->codice);
            printf("Valutazione: %d\n\n\n",t->valutazione);
        }
        t = t->next;
    }
}


//Viene restituito 1 se l'elemento � stato inserito, 0 se l'elemento � gi� presente in lista
int aggiungiLibro(struct libro **t, char *titolo2, char *autore2, int anno_pubb2, char *casa_ed2, int lunghezza2, char *genere2, int codice2, int valutazione2)
{
    char *ptrTitolo = (char *)calloc(sizeof(char), strlen(titolo2) + 1);
    if (ptrTitolo == NULL)
    {
        printf("\n\n Errore nell\'allocazione della memoria.\n Il programma verra\' chiuso!\n ");
        system("pause");
        exit(1);
    }
    char *ptrAutore = (char *)calloc(sizeof(char), strlen(autore2) + 1);
    if (ptrAutore == NULL)
    {
        printf("\n\n Errore nell\'allocazione della memoria.\n Il programma verra\' chiuso!\n ");
        system("pause");
        exit(1);
    }
    char *ptrCasa_ed = (char *)calloc(sizeof(char), strlen(casa_ed2) + 1);
    if (ptrCasa_ed == NULL)
    {
        printf("\n\n Errore nell\'allocazione della memoria.\n Il programma verra\' chiuso!\n ");
        system("pause");
        exit(1);
    }
    char *ptrGenere = (char *)calloc(sizeof(char), strlen(genere2) + 1);
    if (ptrGenere == NULL)
    {
        printf("\n\n Errore nell\'allocazione della memoria.\n Il programma verra\' chiuso!\n ");
        system("pause");
        exit(1);
    }
    strcpy(ptrTitolo, titolo2);
    strcpy(ptrAutore, autore2);
    strcpy(ptrCasa_ed, casa_ed2);
    strcpy(ptrGenere, genere2);

    struct libro *nuovoElemento;

    if (!cercaLibro(*t, codice2))
    {
        nuovoElemento = (struct libro*)malloc(sizeof(struct libro));
        if (nuovoElemento == NULL)
        {
            printf("\n\n Errore nell\'allocazione della memoria.\n Il programma verra\' chiuso!\n ");
            system("pause");
            exit(1);
        }
        nuovoElemento->titolo = ptrTitolo;
		nuovoElemento->autore = ptrAutore;
		nuovoElemento->anno_pubb = anno_pubb2;
		nuovoElemento->casa_ed = ptrCasa_ed;
		nuovoElemento->lunghezza = lunghezza2;
		nuovoElemento->genere = ptrGenere;
		nuovoElemento->codice = codice2;
		nuovoElemento->valutazione = valutazione2;

        nuovoElemento->next = *t;
        *t = nuovoElemento;
        return true;
    }
    else
        return false;
}
