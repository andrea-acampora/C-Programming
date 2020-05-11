#define MAX 10
#include <stdio.h>
#include <stdlib.h>
#include "hdr_lista_id.h"

/**     INIZIALIZZAZIONE LISTA VUOTA     **/
lista_id init_id()
{
    lista_id id;
    id.val = (int*)calloc(MAX,sizeof(int));
    if (id.val==NULL)
    {
        printf("errore malloc");
        getchar();
        exit(1);
    }
    id.last = -1;
    id.size = MAX;
    return id;
}

/**     RIALLOCA     **/
lista_id raddoppia(lista_id id)
{
    id.val = (int*)realloc(id.val,2*id.size*sizeof(int));
    id.size=2*id.size;
    for(int i=id.last+1;i<id.size;i++)
    {
        id.val[i]=0;
    }
    if (&(id.val)==NULL)
    {
        puts("\nerrore: memoria insufficiente\npremere invio per terminare");
        getchar();
        exit(1);
    }
    else
    {
        puts("\nrealloc completata con successo\n");
    }
    return id;
}

/**     STAMPA     **/
void stampa_id(int da,int a, lista_id id)
{
    for(;(da<=a)&&(da<id.size);da++)
    {
        printf("\nval+%d:\t[%d]",da,id.val[da]);
    }
}

/**     INSERIMENTO IN TESTA     **/
lista_id ins_testa_id(lista_id id)
{
    if((id.last+1)>=id.size)
    {
        puts("\nla lista e' piena, attendere...");
        id = raddoppia(id);
    }
    for(int i=(id.last+1);i>0;i--)
        {
            id.val[i]=id.val[i-1];
        }
    puts("\ninserire elemento da aggiungere in testa:\n");
    scanf("%d",&id.val[0]);
    id.last++;
    return id;
}

/**     INSERIMENTO IN CODA     **/
lista_id ins_coda_id(lista_id id)
{
    if((id.last+1)>=id.size)
    {
        puts("\nla lista e' piena, attendere...");
        id = raddoppia(id);
    }
    puts("\ninserire elemento da aggiungere in coda:\n");
    scanf("%d",&id.val[id.last+1]);
    id.last++;
    return id;
}

/**     INSERIMENTO DOPO ELEMENTO     **/
lista_id ins_dopoel_id(lista_id id)
{
    int pos;
    if((id.last+1)>=id.size)
    {
        puts("\nla lista e' piena, attendere...");
        id = raddoppia(id);
    }
    puts("dopo quale elemento si desidera aggiungere il dato?\n(es. per inserire dopo val[2], digitare 2)\n");
    scanf("%1d",&pos);
    puts("\ninserire elemento da aggiungere:\n");
    if(pos==id.last)
    {
        scanf("%d",&id.val[id.last+1]);
    }
    else
    {
        for(int i=(id.last+1);i>(pos+1);i--)
        {
            id.val[i]=id.val[i-1];
        }
        scanf("%d",&id.val[pos+1]);
    }
    id.last++;
    return id;
}

/**     CANCELLA TESTA     **/
lista_id canc_testa_id(lista_id id)
{

    for(int i=0;i<id.last;i++)
    {
        if(id.last==id.size-1)
        {
            id.val[id.last]=0;
        }
        else
        {
            id.val[i]=id.val[i+1];
            id.val[i+1]=0;
        }
    }
    id.last--;
    return id;
}

/**     CANCELLA CODA     **/
lista_id canc_coda_id(lista_id id)
{
    id.val[id.last]=0;
    id.last--;
    return id;
}

/**     CANCELLA PRIMA OCCORRENZA     **/
lista_id canc_elem_id(lista_id id)
{
    int elem;
    puts("inserire elemento di cui cancellare la prima occorrenza\n");
    scanf("%d",&elem);
    for(int i=0;i<(id.size-1);i++)
    {
        if(id.val[i]==elem)
        {
            for(int j=i;j<=id.last;j++)
            {
                id.val[j]=id.val[j+1];
                id.val[j+1]=0;
            }
            i=id.size;
        }
    }
    id.last--;
    return id;
}
