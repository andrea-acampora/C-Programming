#include "mylib.h"
#include <stdlib.h>
#include <string.h>

int ComparebyId(const TipoLista * a, const TipoLista * b)
{
    return a->id==b->id;
}
int ComparebyNome(const TipoLista * a, const TipoLista * b)
{
    return strcmp(a->nome, b->nome);
}
int ComparebyValutazione(const TipoLista * a, const TipoLista * b)
{
    return a->valutazione== b->valutazione;
}

char InserisciInTestaCon(NodoListaConcatenata *l, TipoLista newval)
{
	if (*l == NULL)
	{
		*l = (NodoListaConcatenata)malloc(sizeof(ListaConcatenata));
		if (*l == NULL)
			return 0;
        (*l)->next=NULL;
        (*l)->val=newval;
		return 1;
	}
	else
	{
		NodoListaConcatenata newElem;
		newElem = (NodoListaConcatenata)malloc(sizeof(ListaConcatenata));
		if (newElem == NULL)
			return 0;
		newElem->next = *l;
		newElem->val = newval;
		*l = newElem;
		return 1;
	}
}
char InserisciInCodaCon(NodoListaConcatenata *l, TipoLista newval)
{
    if (*l == NULL)
	{
		*l = (NodoListaConcatenata)malloc(sizeof(ListaConcatenata));
		if (*l == NULL)
			return 0;
        (*l)->next=NULL;
        (*l)->val=newval;
		return 1;
	}
	else
	{
        NodoListaConcatenata newElem, testa=*l;
        while ((*l)->next != NULL)
            *l = (*l)->next;
        newElem = (NodoListaConcatenata)malloc(sizeof(ListaConcatenata));
        if (newElem == NULL)
            return 0;
        newElem->val = newval;
        (*l)->next = newElem;
        newElem->next = NULL;
        *l= testa;
        return 1;
	}
}
char InserisciDopoUnCertoElementoCon(NodoListaConcatenata *l, TipoLista valDaCercare, TipoLista newval, int (*Compare)(const TipoLista *, const TipoLista*))
{
	NodoListaConcatenata newElem, testa=*l;
	for (; *l != NULL && !Compare(&(*l)->val, &valDaCercare); *l = (*l)->next)
		;
	if (*l == NULL)
		return 0;
	newElem = (NodoListaConcatenata)malloc(sizeof(ListaConcatenata));
	if (newElem == NULL)
	{
		return -1;
	}
	newElem->val = newval;

	newElem->next = (*l)->next;
	(*l)->next = newElem;
	*l=testa;
	return 1;
}
char CancellaDallaTestaCon(NodoListaConcatenata *l)
{
	if (*l != NULL)
	{
		NodoListaConcatenata oldElem = *l;
		*l = (*l)->next;
		free(oldElem);
		return 1;
	}
    return 0;
}
char CancellaDallaCodaCon(NodoListaConcatenata *l)
{
	if (*l != NULL)
	{
	    NodoListaConcatenata testa= *l;
		while ((*l)->next->next != NULL)
			*l = (*l)->next;
		free((*l)->next);
		(*l)->next = NULL;
		*l=testa;
		return 1;
	}
	return 0;
}
char CancellaDopoUnCertoElementoCon(NodoListaConcatenata *l, TipoLista valDaCercare ,int (*Compare)(const TipoLista*, const TipoLista*))
{
	if (*l != NULL)
	{
	    NodoListaConcatenata oldElem, testa=*l;
	    if(Compare(&(*l)->val,&valDaCercare))
	    {
            CancellaDallaTestaCon(l);
            return 1;
	    }

		while((*l)->next!=NULL && !Compare(&(*l)->next->val, &valDaCercare))
        {
            *l= (*l)->next;
        }
        if(!Compare(&(*l)->next->val, &valDaCercare))
        {
            *l=testa;
			return 0;
        }
		oldElem = (*l)->next;
		(*l)->next = (*l)->next->next;
		free(oldElem);
		*l=testa;
		return 1;
	}
	return 0;
}
char Cerca(NodoListaConcatenata *l, TipoLista valDaCercare,TipoLista *result, int *dimresult, int (*Compare)(const TipoLista*, const TipoLista*))
{
    if (*l != NULL)
	{
	    char ok=0;
	    int tmpresult=0;
	    NodoListaConcatenata testa=*l;

		while((*l)!=NULL)
        {
            if(Compare(&(*l)->val, &valDaCercare))
            {
                ok=1;
                if(tmpresult<*dimresult)
                    result[tmpresult]=(*l)->val;
                tmpresult++;
            }
            *l= (*l)->next;
        }
        *dimresult=tmpresult;
        *l=testa;
        return ok;
	}
	*dimresult=0;
	return 0;
}
