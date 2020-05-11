#ifndef LIBRARY2_H_INCLUDED
#define LIBRARY2_H_INCLUDED
#define M 10
#define EMPTY (-1)

/**LIBRERIA PER PILA IMPLEMENTATA CON VETTORE STATICO**/

typedef int tipo_elemento;
typedef struct {
     tipo_elemento elem[M];
     tipo_elemento last_elem;
}PILA_STATICA;
/*=====PROTOTIPI FUNZIONI=================*/
int isEmpty_static(const PILA_STATICA *pilaStat);
void StampaPila_static(PILA_STATICA *pilaStat);
void StatoPila_static(PILA_STATICA *pilaStat);
void pushStatic(PILA_STATICA *pilaStat);
void popStatic(PILA_STATICA *pilaStat);
void resetStatic(PILA_STATICA *pilaStat);
#endif // LIBRARY2_H_INCLUDED
