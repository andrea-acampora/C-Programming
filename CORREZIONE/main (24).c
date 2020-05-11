#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*Definisco alcune macro*/
#define MATRIX 10
#define RAND_MAX 3
#define RAND_MIN 0

/*L'ESERCIZIO PURTROPPO NON FUNZIONA, HO PROVATO A SISTEMARLO UN SACCO DI VOLTE
MA MI STAMPA SOLO LA LETTERA A E A VOLTE ANCHE LA B*/

int main()
{
    /*Dichiaro una matrice e alcune variabili*/
    char matrice[MATRIX][MATRIX];
    int i, j, k, numRand;

    /*Con un ciclo for riempo la matrice di puntini*/
    for (i=0; i<MATRIX; i++)
    {
        for (j=0; j<MATRIX; j++)
        {
            matrice[i][j] = '.';
        }
    }

    /*Stabilisco il seme di partenza per generare un numero random*/
    srand(time(NULL));

    matrice[0][0] = 65;
    i=0;
    j=0;

    /*Con questo ciclo for scorro l'alfabeto in maiuscolo*/
    for (k=66; k<=90; k++)
    {
        /*Genero il numero random*/
        numRand = rand() % (RAND_MAX+1);

        /*Con uno switch del numero random e 4 case inserisco ognuna delle lettere dell'alfabeto
        nelle quattro direzioni*/
        switch (numRand)
        {
            case 0: if (matrice[i][j]==k-1 && matrice[i][j+1]=='.') /*destra*/
                    {
                        matrice[i][j+1]=k;
                        k++;
                        break;
                    }
                    else
                    {
                        break;
                    }
            case 1: if (matrice[i][j]==k-1 && matrice[i-1][j]=='.') /*alto*/
                    {
                        matrice[i-1][j]=k;
                        k++;
                        break;
                    }
                    else
                    {
                        break;
                    }
            case 2: if (matrice[i][j]==k-1 && matrice[i][j-1]=='.') /*sinistra*/
                    {
                        matrice[i][j-1]=k;
                        k++;
                        break;
                    }
                    else
                    {
                        break;
                    }
            case 3: if (matrice[i][j]==k-1 && matrice[i+1][j]=='.') /*basso*/
                    {
                        matrice[i+1][j]=k;
                        k++;
                        break;
                    }
                    else
                    {
                        break;
                    }
        }
    }

    /*Con questo ciclo for stampo la matrice*/
    for (i=0; i<MATRIX; i++)
    {
        for (j=0; j<MATRIX; j++)
        {
            printf("%3c", matrice[i][j]);
        }
        printf("\n");
    }

    printf("\n\n");
    system("pause");
    return 0;
}
