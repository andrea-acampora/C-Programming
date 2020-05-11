#ifndef LIBRARY_FUNCTIONS_H_INCLUDED
#define LIBRARY_FUNCTIONS_H_INCLUDED
//FILE DI LIBRERIA .H CHE SERVE SOLO  A DICHIARARE I PARAMETRI DELLE FUNZIONI
//MENTRE IL CORPO DELLE FUNZIONI IN UN ALTRO FILE .C
typedef struct cella{
int val;
struct cella *next;
};
void InserToHead(struct cella **t,int elemento);
void InserToBottom(struct cella **t,int elemento);
void PrintList(struct cella *t);
int DeleteValue(struct cella **t,int num);
int DeleteHead(struct cella **t);
void InsAfterFind(struct cella **t,int elemento,int elemento2);
int DeleteBottom(struct cella **t);
#endif // LIBRARY_FUNCTIONS_H_INCLUDED
