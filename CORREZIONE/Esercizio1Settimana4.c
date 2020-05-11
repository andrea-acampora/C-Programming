/* **************************************************************************************
*
* ESERCIZIO 1
* Scrivere un programma C che generi un “cammino casuale” all’interno di una matrice 10x10.
* La matrice conterrà dei caratteri (inizialmente saranno tutti ‘.’). Il programma deve
* passare casualmente da un elemento all'altro, muovendosi in alto, in basso, a sinistra o
* a destra di una posizione soltanto. Gli elementi visitati dal programma dovranno essere
* etichettati con lettere che vanno dalla A alla Z nell'ordine con cui vengono visitati.
*
*****************************************************************************************/

//librerie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROW 10
#define MAX_COLUMN 10

int main()
{
    //variabili
    int i = 0, direzione,riga = 0,colonna = 0,pos = 1;
    char  matrice[MAX_ROW][MAX_COLUMN], alphabet[]={'A','B','C','D','E','F','G','H','I','J','K','L','M', //matrice [RIGA][COLONNA]
                                       'N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

    for (i = 0; i<MAX_ROW; i++)
    {   //imposto tutti i valori della matrice a '.'
        for (int j = 0; j < MAX_COLUMN; j++)
        {
            matrice[i][j] = '.';
        }
    }
    printf("La matrice vuota:\n______________________________\n");    //stampo matrice vuota
    for (i = 0; i < MAX_ROW; i++)
    {   //stampo matrice vuota
        for (int j = 0; j < MAX_COLUMN; j++)
        {
           printf("%c  ",matrice[i][j]);
           if(j == 9)  printf("|");
        }
        printf("\n");   //newline dopo ogni riga per visualizzare matrice correttamente
    }
    printf("______________________________|\n\n");  //contorno matrice
    matrice[riga][colonna] = alphabet[0];       //A in alto a sinistra
    while(pos != 26)
    {       //ciclo principale, genero numero casuale, e verifico se le caselle richieste sono libere.
        direzione = ((rand()+time(NULL)) % 4);//0 == giù, 1 == sinistra, 2 == destra, 3 == sù
        if(direzione == 0)
        {   //GIU'
            if((matrice[riga+1][colonna] == '.')&&(riga < 9))       //per andare in basso incremento la riga di 1
                {   //se prossima casella in basso è libera e non va fuori dalla matrice sostituisco '.' con una lettera dell'alfabeto
                    matrice[++riga][colonna] = alphabet[pos];
                }
            else continue;  //altrimenti rigenera un'altro numero casuale, fino a quando non trovo una casella libera
        }
        else if(direzione == 1)
        {   //SINISTRA
            if((matrice[riga][colonna-1] == '.')&&(colonna > 0))    //per andare a sinistra decremento le colonne di 1
                {   //se prossima casella in basso è libera e non va fuori dalla matrice sostituisco '.' con una lettera dell'alfabeto
                    matrice[riga][--colonna] = alphabet[pos];
                }
            else continue;  //altrimenti rigenera un'altro numero casuale, fino a quando non trovo una casella libera
        }
        else if(direzione == 2)
        {   //DESTRA
            if((matrice[riga][colonna+1] == '.')&&(colonna < 9))    //per andare a destra incremento le colonne di 1
                {   //se prossima casella in basso è libera e non va fuori dalla matrice sostituisco '.' con una lettera dell'alfabeto
                    matrice[riga][++colonna] = alphabet[pos];
                }
            else continue;  //altrimenti rigenera un'altro numero casuale, fino a quando non trovo una casella libera
        }
        else if(direzione == 3)
        {   //SU'
            if((matrice[riga-1][colonna] == '.')&&(riga > 0))       //per andare in alto decremento la riga di 1
                {   //se prossima casella in basso è libera e non va fuori dalla matrice sostituisco '.' con una lettera dell'alfabeto
                    matrice[--riga][colonna] = alphabet[pos];
                }
            else continue;  //altrimenti rigenera un'altro numero casuale, fino a quando non trovo una casella libera
        }
        else if((matrice[riga+1][colonna]!='.')&&(matrice[riga][colonna-1]!='.')&&(matrice[riga][colonna+1]!='.')&&(matrice[riga-1][colonna]!='.'))
        {
            printf("Tutte le direzioni bloccate! Programma interrotto alla lettera %c",alphabet[pos]);  //se tutte direzioni bloccate
            break;
        }
    pos++;  //incremento pos che mi serve per memorizzare la posizione all'interno dell'alfabeto
    }
    printf("La matrice con cammino casuale generato:\n______________________________\n"); //contorno matrice
    for (i = 0; i < MAX_ROW; i++)
    {   //stampo matrice riempita
        for (int j = 0; j < MAX_COLUMN; j++)
        {
           printf("%c  ",matrice[i][j]);
           if(j == 9)   printf("|");
        }
        printf("\n");
    }
    printf("______________________________|");  //contorno matrice

    getchar();
    return 0;
}//chiudo main

