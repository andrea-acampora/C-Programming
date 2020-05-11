#define MAX 10

/*TYPEDEF*/
typedef struct lista_sc
{
    int val;
    struct lista_sc *next;
}
lista_sc;

/*PROTOTIPI*/
lista_sc* init_sc();
void stampa_sc(lista_sc *sc);
lista_sc* ins_testa_sc(lista_sc *sc);
lista_sc* ins_coda_sc(lista_sc *sc);
lista_sc* ins_dopoel_sc(lista_sc *sc);
lista_sc* canc_testa_sc(lista_sc *sc);
lista_sc* canc_coda_sc(lista_sc *sc);
lista_sc* canc_elem_sc(lista_sc *sc);
