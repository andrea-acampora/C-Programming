#ifndef LIBRARY_FUNCTION_VETTSTAT_H_INCLUDED
#define LIBRARY_FUNCTION_VETTSTAT_H_INCLUDED
#define MAX 10
typedef int TipoElemLista;
struct StructLista{
TipoElemLista info[MAX];
int last;
};
typedef struct StructLista TipoLista;
int Full(const TipoLista *l);
int Empty (const TipoLista *l);
int End (const TipoLista *l);
void InserToHeadVett(TipoLista *l,int p,TipoElemLista x);
void DeleteVett(TipoLista *l,int p);
//void printVett();
#endif // LIBRARY_FUNCTION_VETTSTAT_H_INCLUDED
