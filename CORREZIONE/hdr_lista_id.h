#define MAX 10

/*TYPEDEF*/
typedef struct
{
    int *val; //puntatore array informazione
    int last; //posiz ultimo elemento
    int size; //dimensione corrente
}
lista_id;

/*PROTOTIPI*/
lista_id init_id();
void stampa_id(int da,int a, lista_id id);
lista_id ins_testa_id(lista_id id);
lista_id ins_coda_id(lista_id id);
lista_id ins_dopoel_id(lista_id id);
lista_id canc_testa_id(lista_id id);
lista_id canc_coda_id(lista_id id);
lista_id canc_elem_id(lista_id id);
lista_id raddoppia(lista_id id);
