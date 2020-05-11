#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/* Settimana 4 - esercizio 1 */

int main(){
    /* Dichiarazione variabili e costanti. */
    const int LMAT = 10;
    char mat[LMAT][LMAT];
    srand((unsigned)time(NULL));
    memset(mat, '.', LMAT * LMAT);
    int fSu = 0, fDestra = 0, fGiu = 0, fSinistra = 0;
    /* Coordinate posizione attuale (inizialmente casuali per differenziare l'output). */
    int r = rand() % LMAT, c = rand() % LMAT;
    r = c = 0;
    char cAtt = 'A';
    mat[r][c] = cAtt;
    /* Tanto finchè posso muovermi e non sorpasso Z, mi muovo. */
    do{
        /* Mi salvo in delle flag in quali direzioni posso muovermi. */
        fSu = r - 1 >= 0 && mat[r - 1][c] == '.';
        fGiu = r + 1 < LMAT && mat[r + 1][c] == '.';
        fSinistra = c - 1 >= 0 && mat[r][c - 1] == '.';
        fDestra = c + 1 < LMAT && mat[r][c + 1] == '.';
        int dir = rand() % 4;
        switch(dir){
            /* SOPRA */
        case 0:
            if(fSu)
                mat[--r][c] = ++cAtt;
            break;
            /* SOTTO */
        case 1:
            if(fGiu)
                mat[++r][c] = ++cAtt;
            break;
            /* DESTRA */
        case 2:
            if(fDestra)
                mat[r][++c] = ++cAtt;
            break;
            /* SINISTRA */
        case 3:
            if(fSinistra)
                mat[r][--c] = ++cAtt;
            break;
        }
    } while(cAtt < 'Z' && (fSu || fGiu || fDestra || fSinistra));
    if(fSu || fGiu || fDestra || fSinistra)
	printf("Cammino eseguito per intero\n");
    else
	printf("Cammino terminato per incastramento\n");
    /* Alla fine del cammino, sia che si sia fermato perchè terminato, o perchè incastrato, stampo la matrice. */
    for(int i = 0; i < LMAT; i++){
        for(int j = 0; j < LMAT; j++){
            printf("%c", mat[i][j]);
        }
        printf("\n");
    }
}
