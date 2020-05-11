#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//LANCIARE IL PROGRAMMA PIU' VOLTE PER OTTENERE LA MATRICE PERCHE OGNI TANTO ENTRA IN LOOP
int main()
{
int random,dir,i,j,riga,colonna,k,p;
char matrice[10][10];
char lettera='A';
//INIZIALIZZO LA MATRICE CON UN . IN TUTTE LE POSIZIONI
for(riga=0;riga<10;riga++)
{
    for(colonna=0;colonna<10;colonna++)
    {
    matrice[riga][colonna]='.';
    }
}
//RICHIAMO ALLA FUNZIONE SRAND
srand(time(NULL));
//CICLO PER SCORRERE LE POSIZIONI DELLA MATRICE
for(riga=0;riga<10;riga++)
{
    for(colonna=0;colonna<10;colonna++)
    {
        //CICLO CHE SI INTERROMPE QUANDO INCONTRA IL CARATTERE [ CHE NELLA TABELLA ASCII VIENE DOPO LA Z
        while(lettera!='[')
        {
            //GENERAZIONE DI UN NUMERO CASUALE
            random=rand()%4+1;
            switch(random)
            {
            case 1://CONTROLLO SE LA CELLA E' LIBERA E INSERISCO IN ALTO UNA LETTERA
                if(riga>0 && matrice[riga-1][colonna]=='.')
                {
                riga--;
                matrice[riga][colonna]=lettera;
                lettera++;
                break;
                }
                else break;

            case 2://CONTROLLO SE LA CELLA E' LIBERA E INSERISCO IN BASSO UNA LETTERA
                if(riga<9 && matrice[riga+1][colonna]=='.'){
                riga++;
                matrice[riga][colonna]=lettera;
                lettera++;
                break;
                }
                else break;
            case 3://CONTROLLO SE LA CELLA E' LIBERA E INSERISCO A DESTRA UNA LETTERA
                if(colonna<9 && matrice[riga][colonna+1]=='.'){
                colonna++;
                matrice[riga][colonna]=lettera;
                lettera++;
                break;
                }
                else break;
            case 4://CONTROLLO SE LA CELLA E' LIBERA E INSERISCO A SINISTRA UNA LETTERA
                if(colonna>0&& matrice[riga][colonna-1]=='.'){
                colonna--;
                matrice[riga][colonna]=lettera;
                lettera++;
                break;
                }
                else break;
            }
        }
    }
}
//STAMPO LA MATRICE
for(i=0;i<10;i++)
{
    for(j=0;j<10;j++)
    {
        printf("%c",matrice[i][j]);
    }
printf("\n");
}
system("pause");
return 0;
}
