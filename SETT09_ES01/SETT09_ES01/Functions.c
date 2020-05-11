//FILE .C CON IL CORPO DELLE FUNZIONI
#include "Library_functions_Struct.h"
#include "Library_function_vettStat.h"
#include "Library_functions_vettDin.h"
#define EMPTYLIST -1
#include <stdio.h>
#include <stdlib.h>
int i;

int Full (const TipoLista *l)
{
return(l->last==MAX-1);
}
int Empty ( const TipoLista *l)
{
return (l->last == EMPTYLIST);
}
int End (const TipoLista *l)
{
return (l->last +1);
}
void InserToHeadVett(TipoLista *l,int p,int x)
{
int k;
if((p>=0)&&(p<=End(l)))
{
    for(k=l->last;k>=p;k--)
    {
    l->info[k+1]=l->info[k];
    }
l->info[p]=x;
l->last++;
}
}
void DeleteVett(TipoLista * l, int p)
{
int i;
if (!Empty(l))
{
if ((p >= 0) && (p <= l->last))
{
for (i =p; i< l->last; i++)
l->info[i] = l->info[i+1];
l->last--;
}
}
}
void InserToHead(struct cella **t,int elemento)
{
    struct cella *nuovo;
    nuovo=(struct cella*)malloc(sizeof(struct cella));
    if(nuovo==NULL)
    {
        printf("ERRORE NELL'ALLOCAZIONE DELLA MEMORIA\n");
        exit(1);
    }
    nuovo->val=elemento;
    nuovo->next=*t;
    *t=nuovo;
}

void InserToBottom(struct cella **t,int elemento)
{
    struct cella *ultimo;
    struct cella *ptemp;
    ptemp=(struct cella*)malloc(sizeof(struct cella));
    ptemp->val=elemento;
    ptemp->next=NULL;
    if(t==NULL)
    {
    *t=ptemp;
    }
    else
    {
    ultimo=*t;
    while(ultimo->next!=NULL)
    {
        ultimo=ultimo->next;
    }
        ultimo->next=ptemp;
    }
}
void InsAfterFind(struct cella **t,int elemento,int elemento2)
{
    struct cella *nuovo;
    struct cella *prec;
    struct cella *temp;
    temp=*t;
    prec=NULL;
    nuovo=(struct cella*)malloc(sizeof(struct cella));
        if(nuovo==NULL)
    {
        printf("ERRORE NELL'ALLOCAZIONE DELLA MEMORIA\n");
        exit(1);
    }
    nuovo->val=elemento2;
    while(temp!=NULL)
    {
        if(temp->val==elemento)
        {

            if(prec==NULL){

            nuovo->next=temp->next;
            temp->next=nuovo;
            }
            else{
                prec=temp;
                temp=temp->next;
                nuovo->next=temp;
                prec->next=nuovo;
                break;
            }
        }
        prec=temp;
        temp=temp->next;
    }
}

void PrintList(struct cella *t)
{
    {
    int i = 0;

    printf("\n");
    if (t==NULL)
    {
        printf("LA LISTA E' VUOTA\n");
        return;
    }

    while (t!=NULL)
    {
        i++;
        printf("- %d\n",t->val);
        t = t->next;
    }

}
}

int DeleteValue(struct cella **t,int num)
{
    struct cella *prec,*temp;

    temp=*t;
    prec=NULL;
    while(temp!=NULL)
        {
        if(temp->val==num)
        {
        if (prec == NULL)
            *t = (*t)->next;
        else
            prec->next = temp->next;
        free(temp);
        return 1;
        }
        prec = temp;
        temp = temp->next;
        }
    return 0;
}


int DeleteHead(struct cella **t)
{
    struct cella *temp;
    temp=*t;
    *t=(*t)->next;
    free(t);
}

int DeleteBottom(struct cella **t)
{
    struct cella *temp;
    struct cella *prec;
    prec=NULL;
    if(*t==NULL)
    {
        printf("TENTATIVO DI ELIMINARE LISTA VUOTA\n");
        exit(1);
    }
    if((*t)->next==NULL)
    {
        (*t)->val=NULL;
    }
    temp=*t;
    while(temp->next!=NULL)
    {
        prec=temp;
        temp=temp->next;
    }
    prec->next=NULL;
    free(temp);
}
/*void Insert(int *p,int elemento)
{
for(i=0;i<1;i++)
{
*p=elemento;
}
}*/
