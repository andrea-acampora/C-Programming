
/*ESERCIZIO 2
Due colleghi intendono fissare una riunione, pertanto devono identificare i giorni nei quali sono entrambi liberi da impegni.
A tale scopo, si realizzi un programma C che permetta a ciascuno di immettere le proprie disponibilità, e che identifichi i giorni
 nei quali entrambi sono liberi. In particolare, in una prima fase il programma deve acquisire un elenco di numeri interi che
 indicano i giorni del mese in cui essi sono disponibili e nella seconda fase il programma deve identificare e stampare i giorni
 in cui entrambi i colleghi sono disponibili. Corredare il programma con gli opportuni commenti.*/

//non essendo esplicitato nella consegna non è stato fatto il calcolo dei mesi
#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*Istruzione: dichiaro le variabili*/

    int liberi, contatore, k, giorno, c;
    int matrice[2][31]={NULL};
    //ripete il ciclo per 2 volte, quanti sono i colleghi
    for(contatore=0;contatore<2; contatore++)
    {
        /*Istruzione: se il giorno è <0 o>31 deve reinserirli*/
        do
        {
            printf(" Collega %d quanti giorni liberi hai?\n ", (contatore+1));
            c=scanf("%d", &liberi);
            fflush(stdin);
        }
        while((liberi<0)||(c==0)||(liberi>31));//c==0 (se non è un numero è errore
        /*Istruzione: se un collega non ha giorni liberi il programma termina*/
        if (liberi==0)
        {
            printf("spiacenti il collega %d non ha giorni liberi",(contatore+1));
            break;
        }
        else
        {
            /*Istruzione: inserire i giorni liberi*/
            for(k=0;k<liberi;k++)
            {
                printf("inserisci giorno libero ");
                c=scanf("%d", &giorno);
                fflush(stdin);
                /*Istruzione: se il giorno inserito è <0 o >31 deve reinserirlo*/
                while((giorno<0)||(giorno>31)||(c==0))
                {
                    printf("inserisci  nuovamente il giorno libero ");
                    c=scanf("%d", &giorno);
                    fflush(stdin);
                }
                /*Istruzione: inserisce il giorno nella matrice*/
                matrice[contatore][giorno]=1;
            }
        }
    }
    /*Istruzione: stampa i giorni in comune*/
    if(liberi==0)//se un collega non ha giorni liberi
        printf(" \n non ci sono giorni in comune liberi");
    else
    {
        printf("\n i giorni liberi in comune sono:");
        for(k=0; k<31; k++)
        {
            if((matrice[0][k]==1)&&(matrice[1][k]==1))
                printf(" %d", k);
            else
            {
                printf(" non ci sono");
                break;
            }
        }
    }
    return 0;
}
