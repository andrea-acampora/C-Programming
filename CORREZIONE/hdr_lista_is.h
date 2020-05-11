#define MAX 10

/*TYPEDEF*/
typedef struct
{
    int val[MAX]; //array informazione
    int last; //posiz ultimo elemento
}
lista_is;

/*PROTOTIPI*/
lista_is init_is();
void stampa_is(int da,int a, lista_is is);
lista_is ins_testa_is(lista_is is);
lista_is ins_coda_is(lista_is is);
lista_is ins_dopoel_is(lista_is is);
lista_is canc_testa_is(lista_is is);
lista_is canc_coda_is(lista_is is);
lista_is canc_elem_is(lista_is is);
