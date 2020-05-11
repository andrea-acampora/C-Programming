#ifndef LIBRARY_H_INCLUDED
#define LIBRARY_H_INCLUDED
/**LIBRERIA PER CODA IMPLEMENTATA CON STRUTTURE COLLEGATE**/
typedef struct cella{
int valore;
struct cella *next;
}TipoCoda;

/*=====PROTOTIPI FUNZIONI=================*/
void push(TipoCoda **c,int num);
struct cella  *pop(TipoCoda **c);
void stato(TipoCoda *c);
void ResetCoda(TipoCoda **c);
void StampaAzzera(TipoCoda **c);
#endif // LIBRARY_H_INCLUDED
