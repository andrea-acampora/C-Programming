#ifndef LIBRARY2_H_INCLUDED
#define LIBRARY2_H_INCLUDED
#define M 10
#define EMPTY (-1)

/**LIBRERIA PER CODA IMPLEMENTATA CON VETTORE STATICO**/

typedef int tipo_elemento;
typedef struct {
     tipo_elemento elem[M];
     tipo_elemento last_elem;
}CODA_STATICA;
/*=====PROTOTIPI FUNZIONI=================*/
int isEmpty_static(const CODA_STATICA *codaStat);
void StampaCoda_static(CODA_STATICA *codaStat);
void StatoCoda_static(CODA_STATICA *codaStat);
void pushStatic(CODA_STATICA *codaStat);
void popStatic(CODA_STATICA *codaStat);
void resetStatic(CODA_STATICA *codaStat);
#endif // LIBRARY2_H_INCLUDED
