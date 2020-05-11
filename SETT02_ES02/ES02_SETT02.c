#include <stdio.h>
#include <stdlib.h>
/*Scrivere un programma C che, preso in input un valore numero_studenti, permetta l’inserimento da tastiera
 del voto di ciascuno degli studenti e ne calcoli la media utilizzando sia il costrutto for che il costrutto while.
 Visualizzare poi un commento in base al voto medio della classe come mostrato in tabella:
< 6: MEDIA INSUFFICIENTE
6-7: MEDIA SUFFICIENTE
7-8: MEDIA DISCRETA
8-9: MEDIA BUONA
9-10: MEDIA OTTIMA
Inserire nel codice il controllo sull’input dell’utente per verificare che il voto inserito non sia <= 0 e > di un valore voto_max*/
int main()
{
int i,num_stud,voto;
float media;
printf("Inserire un numero n di studenti \n");
scanf("%d",&num_stud);
int somma=0;
    for(i=0;i<num_stud;i++)
    {
        printf("Inserire voto dello studente (1-10)\n ");
        scanf("%d",&voto);
            while (voto<0 || voto >10)
            {
            printf("voto inserito non corretto\n ");
            printf("Inserire voto studente ");
            scanf("%d",&voto);
            }
    somma +=voto;
    }
media=(float)somma/num_stud;
printf("media : %2.2f ",media);
    if (media<6)
    {
        printf("MEDIA INSUFFICIENTE");
    }
        else if(media>=6 && media<7)
        {
        printf("MEDIA INSUFFICIENTE");
        }
            else if(media>=7 && media<8)
            {
            printf("MEDIA DISCRETA");
            }
                else if(media>=8 && media<9)
                {
                printf("MEDIA BUONA");
                }
                    else if(media>=9 && media<=10)
                    {
                    printf("MEDIA OTTIMA");
                    }

}
