#define MAX 10
#include <stdio.h>
#include <stdlib.h>
#include "hdr_lista_is.h"

/**     INIZIALIZZAZIONE LISTA VUOTA      **/
lista_is init_is()
{
    lista_is is;
    is.last = -1;
    for(int i=0;i<MAX;i++)
    {
        is.val[i]=0;
    }
    return is;
}

/**     STAMPA     **/
void stampa_is(int da,int a, lista_is is)
{
    for(;(da<=a)&&(da<MAX);da++)
    {
        printf("\nval[%d]:\t[%d]",da,is.val[da]);
    }
}

/**     INSERIMENTO IN TESTA     **/
lista_is ins_testa_is(lista_is is)
{
    if((is.last+1)<MAX)
    {
        for(int i=(is.last+1);i>0;i--)
        {
            is.val[i]=is.val[i-1];
        }
        puts("\ninserire elemento da aggiungere in testa:\n");
        scanf("%d",&is.val[0]);
        is.last++;
    }
    else
    {
        puts("\nimpossibile aggiungere elementi, la lista e' piena\npremere invio per continuare\n");
        getchar();
    }
    return is;
}

/**     INSERIMENTO IN CODA     **/
lista_is ins_coda_is(lista_is is)
{
    if((is.last+1)<MAX)
    {
        puts("\ninserire elemento da aggiungere in coda:\n");
        scanf("%d",&is.val[is.last+1]);
        is.last++;
    }
    else
    {
        puts("\nimpossibile aggiungere elementi, la lista e' piena\npremere invio per continuare\n");
        getchar();
    }
    return is;
}

/**     INSERIMENTO DOPO ELEMENTO     **/
lista_is ins_dopoel_is(lista_is is)
{
    int pos;
    if((is.last+1)<MAX)
    {
        puts("dopo quale elemento si desidera aggiungere il dato?\n(es. per inserire dopo val[2], digitare 2)\n");
        scanf("%1d",&pos);
        puts("\ninserire elemento da aggiungere:\n");
        if(pos==is.last)
        {
            scanf("%d",&is.val[is.last+1]);
        }
        else
        {
            for(int i=(is.last+1);i>(pos+1);i--)
            {
                is.val[i]=is.val[i-1];
            }
            scanf("%d",&is.val[pos+1]);
        }
        is.last++;
    }
    else
    {
        puts("\nimpossibile aggiungere elementi, la lista e' piena\npremere invio per continuare\n");
        getchar();
    }
    return is;
}

/**     CANCELLA TESTA     **/
lista_is canc_testa_is(lista_is is)
{
    for(int i=0;i<is.last;i++)
    {
        if(is.last==MAX-1)
        {
            is.val[is.last]=0;
        }
        else
        {
            is.val[i]=is.val[i+1];
            is.val[i+1]=0;
        }
    }
    is.last--;
    return is;
}

/**     CANCELLA CODA     **/
lista_is canc_coda_is(lista_is is)
{
    is.val[is.last]=0;
    is.last--;
    return is;
}

/**     CANCELLA PRIMA OCCORRENZA     **/
lista_is canc_elem_is(lista_is is)
{
    int elem;
    puts("inserire elemento di cui cancellare la prima occorrenza\n");
    scanf("%d",&elem);
    for(int i=0;i<(MAX-1);i++)
    {
        if(is.val[i]==elem)
        {
            for(int j=i;j<=is.last;j++)
            {
                is.val[j]=is.val[j+1];
                is.val[j+1]=0;
            }
            i=MAX;
        }
    }
    is.last--;
    return is;
}
