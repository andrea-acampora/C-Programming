#include <stdio.h>
#include <stdlib.h>

/* Due colleghi intendono fissare una riunione, pertanto devono identificare i giorni nei quali sono entrambi liberi da impegni.
A tale scopo, si realizzi un programma C che permetta a ciascuno di immettere le proprie disponibilità,
e che identifichi i giorni nei quali entrambi sono liberi. In particolare, in una prima fase
il programma deve acquisire un elenco di numeri interi che indicano i giorni del mese in cui essi sono disponibili e
nella seconda fase il programma deve identificare e stampare i giorni in cui entrambi i colleghi sono disponibili.
Corredare il programma con gli opportuni commenti. */

  int main()
  {
    float vettore1[31]={0},vettore2[31]={0};
    int giornook,i,k,j,h,ngiorni;
    //ESEGUO IL CICLO PER TUTTE E DUE LE PERSONE
    for(i=0;i<2;i++)
    {
        printf("\n");
        printf("Quanti giorni sei libero?\n");
        scanf("%d",&ngiorni);
        fflush(stdin);
            //CICLO DI CONTROLLO SUL NUMERO DEI GIORNI INSERITI IN INPUT
            while(ngiorni<0 || ngiorni>31)
            {
            printf("Numero giorni inseriti non corretto, riprovare \n");
            printf("Quanti giorni sei libero?\n");
            scanf("%d",&ngiorni);
            fflush(stdin);
            }
            //CICLO FOR PER CHIEDERE NEI QUALI DEI GIORNI INSERITI E' LIBERO
        for(k=0;k<ngiorni;k++)
            {
            printf("\n");
            printf("Inserire giorno del mese \n");
            scanf("%d",&giornook);
            fflush(stdin);
            //CICLO DI CONTROLLO PER EVITARE CHE I GIORNI NON SIANO COMPRESI TRA 1 E 31
            while(giornook<=0 || giornook>31)
            {
            printf("Giorno libero inserito non corretto, riprovare \n");
            printf("Inserire giorno del mese \n");
            scanf("%d",&giornook);
            fflush(stdin);
            }
        //ASSEGNAZIONE DEI GIORNI LIBERI DELLA PRIMA PERSONA AL VETTORE1
            if(i==0)
            {
            vettore1[k] = giornook;
            }
        //ASSEGNAZIONE DEI GIORNI LIBERI DELLA SECONDA PERSONA AL VETTORE2
            else
            vettore2[k] = giornook;
        }
    }
    printf("I giorni in cui potete vedervi sono: \n");
    //CICLI FOR PER INCROCIARE TUTTI GLI ELEMENTI DEI DUE VETTORI E TROVARE CORRISPONDENZA
    for(j=0;j<31;j++)
    {
        for(h=0;h<ngiorni;h++)
        {
            if(vettore1[j]==vettore2[h])
            printf(" %g -",vettore1[j]);
        }

    }
    return 0;
    system ("pause");
  }
