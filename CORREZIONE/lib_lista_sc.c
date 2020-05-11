#define MAX 10
#include <stdio.h>
#include <stdlib.h>
#include "hdr_lista_sc.h"

/**     INIZIALIZZAZIONE LISTA VUOTA     **/
lista_sc* init_sc()
{
    lista_sc *sc = NULL;
    return sc;
}

/**     STAMPA     **/
void stampa_sc(lista_sc *sc)
{
    if(sc==NULL)
    {
        puts("\nLista vuota!");
    }
    else
    {
        lista_sc *tmp=sc;
        int i=0;
        int check=0;
        do
        {
            printf("\nval+%d:\t[%d]",i,tmp->val);
            i++;
            if(tmp->next!=NULL)
            {
                tmp=tmp->next;
            }
            else
            {
                check=1;
            }
        }
        while(check==0);
    }
}

/**     INSERIMENTO IN TESTA     **/
lista_sc* ins_testa_sc(lista_sc *sc)
{
    if(sc!=NULL)
    {
        lista_sc *tmp=sc;
        sc = malloc(sizeof(lista_sc));
        if (sc==NULL)
        {
            printf("errore realloc");
            getchar();
            exit(1);
        }
        sc->next=tmp;
    }
    else
    {
        sc = malloc(sizeof(lista_sc));
        sc->next=NULL;
    }
    puts("\ninserire l'elemento da aggiungere in testa:\n");
    scanf("%d",&(sc->val));
    fflush(stdin);
    return sc;
}

/**     INSERIMENTO IN CODA     **/
lista_sc* ins_coda_sc(lista_sc *sc)
{
    if(sc!=NULL)
    {
        lista_sc* tmp=sc;
        lista_sc* tmp2;
        while(tmp->next!=NULL)
        {
            tmp=tmp->next;
        }
        tmp2 = malloc(sizeof(lista_sc));
        if (tmp2==NULL)
        {
            printf("errore realloc");
            getchar();
            exit(1);
        }
        tmp2->next=NULL;
        tmp->next=tmp2;
        puts("\ninserire l'elemento da aggiungere in coda:\n");
        scanf("%d",&(tmp2->val));
        fflush(stdin);
    }
    else
    {
        sc = malloc(sizeof(lista_sc));
        if (sc==NULL)
        {
            printf("errore realloc");
            getchar();
            exit(1);
        }
        sc->next=NULL;
        puts("\ninserire l'elemento da aggiungere in coda:\n");
        scanf("%d",&(sc->val));
        fflush(stdin);
    }
    return sc;
}

/**     INSERIMENTO DOPO ELEMENTO     **/
lista_sc* ins_dopoel_sc(lista_sc *sc)
{
    lista_sc* tmp=sc;
    lista_sc* tmp2;
    lista_sc* tmp3;
    int pos;
    int i=0;
    puts("dopo quale elemento si desidera aggiungere il dato?\n(es. per inserire dopo val[2], digitare 2)\n");
    scanf("%1d",&pos);
    fflush(stdin);
    puts("\ninserire elemento da aggiungere:\n");
    while(tmp->next!=NULL&&i!=pos)
    {
        tmp=tmp->next;
        i++;
    }
    if(tmp->next!=NULL)
    {
        tmp2=tmp->next;
        tmp3=malloc(sizeof(lista_sc));
        if (tmp3==NULL)
        {
            printf("errore realloc");
            getchar();
            exit(1);
        }
        scanf("%d",&(tmp3->val));
        fflush(stdin);
        tmp3->next=tmp2;
        tmp->next=tmp3;
    }
    else
    {
        tmp2=malloc(sizeof(lista_sc));
        if (tmp2==NULL)
        {
            printf("errore realloc");
            getchar();
            exit(1);
        }
        tmp2->next=NULL;
        tmp->next=tmp2;
        scanf("%d",&(tmp2->val));
        fflush(stdin);
    }
    return sc;
}

/**     CANCELLA TESTA     **/
lista_sc* canc_testa_sc(lista_sc *sc)
{
    lista_sc* tmp=sc;
    sc=sc->next;
    free(tmp);
    return sc;
}

/**     CANCELLA CODA     **/
lista_sc* canc_coda_sc(lista_sc *sc)
{
    lista_sc* tmp=sc;
    lista_sc* tmp2;
    while(tmp->next!=NULL)
    {
        tmp2=tmp;
        tmp=tmp->next;
    }
    (tmp2)->next=NULL;
    free(tmp);
    return sc;
}

/**     CANCELLA PRIMA OCCORRENZA     **/
lista_sc* canc_elem_sc(lista_sc *sc)
{
    lista_sc* tmp=sc;
    lista_sc* tmp2;
    int pos;
    int i=0;
    puts("quale elemento si desidera cancellare?\n(es. per cancellare val[2], digitare 2)\n");
    scanf("%1d",&pos);
    fflush(stdin);
    while(tmp->next!=NULL&&i!=pos)
    {
        tmp2=tmp;
        tmp=tmp->next;
        i++;
    }
    if(tmp->next!=NULL)
    {
        tmp2->next=tmp->next;
        free(tmp);
    }
    else
    {
        tmp2->next=NULL;
        free(tmp);
    }
    return sc;
}

