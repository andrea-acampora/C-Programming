#include <stdio.h>
#include <stdlib.h>

    /*ESERCIZIO 1, settimana 4*/

#define ALTEZZA 10
#define LARGHEZZA 10

int main()
{
    int i,j,conta; /*contatori*/
    int random_number; /*numero casuale*/
    char matrice[ALTEZZA][LARGHEZZA],lettere[26];

    /*riempiamo vettore lettere[26]  con  lettere dalla A alla Z*/
    conta=0;
    for(i=65;i<=90;i++)
    {
       lettere[conta]= ("%c",i);
       printf(" %c",lettere[conta]);/*stampiamo le lettere per facilitare verifica del esercizio*/
       conta++;

    }


    /*riempiamo matrice con '.'*/
    for(i=0;i<10;i++)
    {
        for(j=0;j<10;j++)
        {
            matrice[i][j]= '.';
        }

    }
    printf("\n\n");

    /*funzione random*/
    srand((unsigned) time(NULL));


    i=0;
    j=0;
    matrice[0][0] = lettere[0];/*Primo elemento di matrice mettiamo A */

    for(conta=1;conta<26;conta++)
    {
        random_number = rand()%4;/*Otteniamo numero casuale*/
        if(j==0 && matrice[i-1][j] != '.' &&  matrice[i+1][j] != '.' && matrice[i][j+1] != '.')/*Se ultimo lettera è nella prima colonna, e se  numero è bloccato da sopra,sotto e da destra , terminiamo la programma*/
        {
            printf("Tutte le direzioni sono bloccate, case 1");
            break;
        }
        else if(j == LARGHEZZA-1 && matrice[i-1][j] != '.' &&  matrice[i+1][j] != '.' && matrice[i][j-1] != '.')/*Se ultimo lettera è nella nona colonna, e se  numero è bloccato da sopra,sotto e da sinistra , terminiamo la programma*/
        {
            printf("Tutte le direzioni sono bloccate, case 2");
            break;
        }

        else if(matrice[i-1][j] == '.' ||  matrice[i+1][j] == '.' || matrice[i][j-1] == '.' || matrice[i][j+1] == '.')/*Se esiste almeno una "uscita" non bloccata dalla lettera eseguiamo seguenti istruzioni*/
        {

            if (random_number==0 && i>0 && matrice[i-1][j]=='.') /*Se numero casuale ugale a 0, ultima lettera non è nella prima riga e indirizzo i-1 non occupa una lettera eseguiamo seguenti istruzioni */
            {
                --i;
                matrice[i][j] = lettere[conta];
            }
            else if (random_number==1 && i < ALTEZZA-1 && matrice[i+1][j]=='.' )/*Se numero casuale ugale a 1, ultima lettera non è nella nona riga eindirizzo i+1 non occupa una lettera eseguiamo seguenti istruzioni */
            {
                ++i;
                matrice[i][j] = lettere[conta];
            }
            else if (random_number==2 && j > 0 && matrice[i][j-1]=='.' )/*Se numero casuale ugale a 2, ultima lettera non è nella prima colonna e indirizzo j-1 non occupa una lettera, seguiamo seguenti istruzioni */
            {
                --j;
                matrice[i][j] = lettere[conta];
            }
            else if (random_number==3 && j < LARGHEZZA-1 && matrice[i][j+1]=='.' )/*Se numero casuale ugale a 3, ultima lettera non è nella nona colonna e indirizzo j+1 non occupa una lettera eseguiamo seguenti istruzioni */
            {
                ++j;
                matrice[i][j] = lettere[conta];
            }
            else
            {
                --conta; /*Se la nuova lettera non è stata messa nella matrice ,cambiamo numero casuale*/
            }
        }
        else
        {
            printf("Tutte le direzioni sono bloccate, case 3"); /*Se lettera è bloccata da tutti i parti, terminiamo la programma*/
            break;
        }
    }

    /*Stampiamo la matrice*/
    for(i=0;i<10;i++)
    {
        printf("\n\n");
        for(j=0;j<10;j++)
        {
            printf(" %c",matrice[i][j]);
        }
    }
    printf("\n\n");
    return 0;
}
