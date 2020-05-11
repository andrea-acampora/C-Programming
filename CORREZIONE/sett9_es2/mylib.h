#ifndef MYLIB_H_INCLUDED
#define MYLIB_H_INCLUDED

typedef struct libro TipoLista;
typedef struct listaConcatenata ListaConcatenata;
typedef ListaConcatenata *NodoListaConcatenata;

struct libro
{
    char nome[50];
    char autore[50];
    char casa_editrice[50];
    char genere[50];
    int anno_pubb;
    int id;
    int valutazione;

};

struct listaConcatenata
{
	TipoLista val;
	NodoListaConcatenata next;
};

int ComparebyId(const TipoLista * a, const TipoLista * b);

int ComparebyNome(const TipoLista * a, const TipoLista * b);

int ComparebyValutazione(const TipoLista * a, const TipoLista * b);

char InserisciInTestaCon(NodoListaConcatenata *l, TipoLista newval);
char InserisciInCodaCon(NodoListaConcatenata *l, TipoLista newval);
char InserisciDopoUnCertoElementoCon(NodoListaConcatenata *l, TipoLista valDaCercare, TipoLista newval, int (*compar)(const TipoLista *, const TipoLista*));
char CancellaDallaTestaCon(NodoListaConcatenata *l);
char CancellaDallaCodaCon(NodoListaConcatenata *l);
char CancellaDopoUnCertoElementoCon(NodoListaConcatenata *l, TipoLista valDaCercare, int (*compar)(const TipoLista *, const TipoLista*));
char Cerca(NodoListaConcatenata *l, TipoLista valDaCercare,TipoLista result[], int *dimresult, int (*compar)(const TipoLista *, const TipoLista*));

#endif // MYLIB_H_INCLUDED
