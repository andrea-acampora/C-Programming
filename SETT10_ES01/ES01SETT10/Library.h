#ifndef LIBRARY_H_INCLUDED
#define LIBRARY_H_INCLUDED
/**LIBRERIA PER PILA IMPLEMENTATA CON STRUTTURE COLLEGATE**/
typedef struct cella{
int valore;
struct cella *next;
};
/*=====PROTOTIPI FUNZIONI=================*/
void push(struct cella **p,int num);
struct cella *pop(struct cella **p);
void stato(struct cella *p);
void ResetPila(struct cella **p);
void StampaAzzera(struct cella **p);
#endif // LIBRARY_H_INCLUDED
