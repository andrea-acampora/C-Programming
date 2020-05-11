#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CHAR 31

int main ()

{

/* ASSENZA DELLE FUNZIONI DI LIBRERIA */
    printf("\n CONFRONTO STRINGHE IN ASSENZA DI FUNZIONI DI LIBRERIA \n");

    char vetParola1[MAX_CHAR],vetParola2[MAX_CHAR];
    int i,k,l,lunghezza1,lunghezza2;

/* Inserimento delle stringhe da confrontare(lettere minuscole, maiuscole, numeri, simboli e segni di punteggiatura) */
    printf("\n Inserire parola 1: ");
    scanf("%30s",vetParola1);
    fflush(stdin);

    printf("\n Inserire parola 2: ");
    scanf("%30s",vetParola2);
    fflush(stdin);

/* Determinazione della lunghezza delle stringhe utilizzando la funzione di libreria strlen (+1 e\' lo spazio per il terminatore)*/
    lunghezza1 = strlen(vetParola1 + 1);
    lunghezza2 = strlen(vetParola2 + 1);
    vetParola1[lunghezza1 + 1] = '\0';
    vetParola2[lunghezza2 + 1] = '\0';

/* Confronto di ogni singolo carattere delle stringhe inserite per trovare sotto-stringa */
    for(i=0; i<=30; i++)
    {
       for(k=0; vetParola1[i+k] == vetParola2[k] && k<=30; k++)
       {
            while(k == lunghezza2) /* Parola 2 e\' ricorrente nella parola 1. Inserisco * al suo posto. */
            {
                l=1;
                vetParola1[i] = '*';
                k--;

                while(i+l<=MAX_CHAR) /* Per mandare avanti il controllo dela stringa */
                {
                    vetParola1[i+l]= vetParola1[i+k+l];
                    l++;
                }
            }
        }
    }

/* Stampa della parola confrontata */
    printf("\n La nuova parola modificata e\': %s", vetParola1);

    printf("\n\n");

/* PRESENZA DELLE FUNZIONI DI LIBRERIA */
    printf("\n CONFRONTO STRINGHE IN PRESENZA DELLE FUNZIONI DI LIBRERIA \n");

    char vetParola3[MAX_CHAR],vetParola4[MAX_CHAR],*ptr;
    int lunghezza3,lunghezza4;

/* Inserimento delle stringhe da confrontare(lettere minuscole, maiuscole, numeri, simboli e segni di punteggiatura)  */
    printf("\n Inserire parola 1: ");
    scanf("%30s",vetParola3);
    fflush(stdin);

    printf("\n Inserire parola 2: ");
    scanf("%30s",vetParola4);
    fflush(stdin);

/* Determinazione della lunghezza delle stringhe utilizzando la funzione di libreria strlen (+1 e\' lo spazio per il terminatore)*/
    lunghezza3 = strlen(vetParola3);
    lunghezza4 = strlen(vetParola4);
    vetParola3[lunghezza3 + 1] = '\0';
    vetParola4[lunghezza4 + 1] = '\0';

/* Confronto attraverso le funzioni delle stringhe inserite per trovare sotto-strigha */
    do
    {
        ptr = strstr(vetParola3,vetParola4);

        if(ptr != NULL)
        {
            *ptr = '*';
            strcpy(ptr+1, ptr+lunghezza4);
        }
    }
    while(ptr != NULL);

/* Stampa della parola confrontata */
    printf("\n La parola modificata e\': %s",vetParola3);

    printf("\n\n");
    getchar();
    return 0;

}
