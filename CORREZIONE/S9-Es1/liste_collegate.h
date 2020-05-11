#ifndef LISTE_COLLEGATE_H_INCLUDED
#define LISTE_COLLEGATE_H_INCLUDED

/*=====INCLUSIONE LIBRERIE==============================================================================================================*/
#include <stdlib.h>
#include <stdio.h>



/*=====DEFINE==============================================================================================================*/


/*=====TYPEDEF==============================================================================================================*/
typedef int tipo_elemento;

struct lista_collegata{
     tipo_elemento elem;
     struct lista_collegata *next;
};

typedef struct lista_collegata LISTA;


/*=====PROTOTIPI FUNZIONI==============================================================================================================*/

void stampa_lista(LISTA *testa);

LISTA* locate_position_elem_lista(LISTA *testa, tipo_elemento x);

void ins_testa_lista(LISTA **testa, tipo_elemento x);
void ins_coda_lista(LISTA **testa, tipo_elemento x);
void ins_elem_input_lista(LISTA **testa, tipo_elemento x, tipo_elemento x_position);

void canc_testa_lista(LISTA **testa);
void canc_coda_lista(LISTA **testa);
void canc_elem_input_lista(LISTA **testa, tipo_elemento x);



#endif // LISTE_COLLEGATE_H_INCLUDED
