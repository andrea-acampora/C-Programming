#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 30
#define num_esami 3
/*Si scriva un programma C, adeguatamente commentato, che gestisca un certo numero di studenti
iscritti ad un corso di laurea. Il programma utilizza un vettore di strutture,
ognuna delle quali memorizza le informazioni di uno studente
(numero matricola, nome e cognome, anno di immatricolazione, piano di studi).
Il programma deve fornire la possibilità di:

-aggiungere un nuovo studente, stampando un messaggio di errore se lo studente è già presente (individuato dalla matricola)
o se il vettore è pieno.
-dato il numero di matricola, stampare le informazioni dello studente oppure un messaggio di errore
 se la matricola non è presente nel vettore
-dato un numero di matricola, modificare le informazioni del piano di studi aggiungendo un voto
oppure stampando un messaggio di errore se la matricola non è presente nel vettore.
-Il piano di studi è un vettore di NUM_ESAMI elementi ognuno di tipo struttura contenete
 il nome dell'insegnamento e il voto corrispondente (0 se non sostenuto).*/
 //DICHIARAZIONE STRUTTURA PER PIANO DI STUDIO
 typedef struct s_esame
    {
     char materia[20];
     int voto;
    }esame;
//DICHIARAZIONE STRUTTURA PER GLI STUDENTI
typedef struct stud
        {
        int nmatr[20];
        char nome[20];
        char cognome[20];
        int annoimm;
        struct s_esame esame[num_esami];
        }studente;

 int main()
 {
    int i,j,k,l,p,n,n3,n2,flag=0,flag2=0,flag3=0;
    char scelta;
    int matricola[20],matricola2[20],matricola3[20];
    studente *classe=(studente *)malloc(10*sizeof(studente));
    printf("VUOI INSERIRE DEGLI STUDENTI?-(s/n) ");
    scanf("%c",&scelta);
    fflush(stdin);
    system("cls");
        //CICLO PER ENTRARE NELL'INSERIMENTO
        while(scelta!='n')
        {
        printf("QUANTI STUDENTI VUOI INSERIRE ?\n");
        scanf("%d",&n);
        fflush(stdin);
        system("cls");
            //INSERIMENTO DATI NELLA STRUTTURA
            for(i=0;i<n;i++)
            {
            printf("INSERIRE NUMERO MATRICOLA STUDENTE %d:\n",i+1);
            scanf("%d",&classe[i].nmatr);
            fflush(stdin);
            printf("INSERIRE NOME STUDENTE %d:\n",i+1);
            scanf("%s",&classe[i].nome);
            fflush(stdin);
            printf("INSERIRE COGNOME STUDENTE %d:\n",i+1);
            scanf("%s",&classe[i].cognome);
            fflush(stdin);
            printf("INSERIRE ANNO IMMATRICOLAZIONE STUDENTE %d:\n",i+1);
            scanf("%d",&classe[i].annoimm);
            fflush(stdin);
            printf("INSERIREMENTO PIANO DI STUDI DELLO STUDENTE %d:\n",i+1);
                //CICLO ANNIDATO PER INSERIRE I DATI DEL PIANO DI STUDIO
                for(l=0;l<1;l++)
                {
                printf("INSERIRE MATERIA: ");
                scanf("%s",&classe[i].esame[l].materia);
                fflush(stdin);
                printf("INSERIRE VOTO: ");
                scanf("%d",&classe[i].esame[l].voto);
                fflush(stdin);
                printf("\n");
                system("cls");
                }
        if(n!=0 && n%10==0)
        {
        classe=(studente *)realloc(classe,(n*2*sizeof(studente)));
        }
            }
    printf("VUOI INSERIRE ALTRI STUDENTI?(s/n)\n");
    scanf("%c",&scelta);
    fflush(stdin);
    }
    //SCELTA DI 3 OPZIONI:
    system("cls");
    printf("SCEGLIERE COSA EFFETTUARE:\n");
    printf("\n");
    printf("1)AGGIUNGERE NUOVO STUDENTE\n");
    printf("2)VISUALIZZARE INFORMAZIONI STUDENTE\n");
    printf("3)MODIFICARE PIANO DI STUDI\n");
    scanf("%d",&n2);
    fflush(stdin);
    system("cls");
        //CICLO DI CONTROLLO PER EVITARE COMPORTAMENTI INDEFINITI DEL COMPILATORE
        while(n2!=1 && n2!=2 && n2!=3)
        {
        printf("ERRORE\n");
        printf("SCEGLIERE COSA EFFETTUARE:\n");
        printf("\n");
        printf("1)AGGIUNGERE NUOVO STUDENTE\n");
        printf("2)VISUALIZZARE INFORMAZIONI STUDENTE\n");
        printf("3)MODIFICARE PIANO DI STUDI\n");
        scanf("%d",&n2);
        fflush(stdin);
        system("cls");
        }
    //CICLO PER ENTRARE NELLA SCELTA DELL'UTENTE
    if(n2==1)
        {
        printf("INSERIMENTO STUDENTE\n");
        printf("INSERIRE NUMERO MATRICOLA STUDENTE DA AGGIUNGERE\n");
            //INSERIMENTO DELLA MATRICOLA DA CONFRONTARE CON QUELLE NELLA STRUCT
            for(j=0;j<1;j++)
            {
            scanf("%d",&matricola[j]);
            fflush(stdin);
            printf("\n");
                //CONFRONTO TRA I NUMERI DI MATRICOLA
                for(i=0;i<n;i++)
                {
                    if(*classe[i].nmatr==matricola[j])
                    {
                    printf("STUDENTE GIA' ESISTENTE!\n");
                    flag=1;
                    system("pause");
                    system("cls");
                    }
                }
            }
            //FLAG=0 SIGNIFICA CHE NON ESISTE QUEL NUMERO DI MATR. E ALLORA POSSO INSERIRE I DATI
            if(flag==0)
            {//INSERIMENTO DARI NUOVO STUDENTE
                for(k=0;k<1;k++)
                {
                *classe[k].nmatr=matricola[j];
                printf("INSERIRE NOME STUDENTE\n");
                scanf("%s",&classe[k].nome);
                fflush(stdin);
                printf("INSERIRE COGNOME STUDENTE\n");
                scanf("%s",&classe[k].cognome);
                fflush(stdin);
                printf("INSERIRE ANNO IMMATRICOLAZIONE STUDENTE\n");
                scanf("%d",&classe[k].annoimm);
                fflush(stdin);
                    //CICLO ANNIDATO PER INSERIRE IL PIANO DI STUDI
                    for(p=0;p<1;p++)
                    {
                    printf("INSERIRE MATERIA: ");
                    scanf("%s",&classe[k].esame[p].materia);
                    fflush(stdin);
                    printf("\n");
                    printf("INSERIRE VOTO: ");
                    scanf("%d",&classe[k].esame[p].voto);
                    fflush(stdin);
                    printf("\n");
                    system("pause");
                    system("cls");
                    }
                }
            }
        system("cls");
        }
    //SCELTA N.2
   if(n2==2)
    {
    printf("STAMPA INFORMAZIONI STUDENTE-- \n\n");
    printf("INSERIRE NUMERO DI MATRICOLA DELLO STUDENTE \n");
    scanf("%d",&matricola2[20]);
    fflush(stdin);
        //CICLO DI CONFRONTO CON I NUMERI DI MATRICOLA
        for(i=0;i<n;i++)
        {
            if(*classe[i].nmatr==matricola2[20])
            {
            flag2=1;
            *classe[i].nmatr=matricola[20];
            printf("NOME STUDENTE: %s\n",classe[i].nome);
            printf("COGNOME STUDENTE: %s\n",classe[i].cognome);
            printf("ANNO IMMATRICOLAZIONE STUDENTE: %d\n",classe[i].annoimm);
                //CICLO ANNIDATO PER IL PIANO DI STUDI
                for(l=0;l<1;l++)
                {
                printf("MATERIA: %s\n",classe[i].esame[l].materia);
                printf("VOTO: %d\n",classe[i].esame[l].voto);
                }
                break;
            }
        }
        if(flag2==0)
        {
        printf("STUDENTE NON TROVATO\n");
        }
        //MENU PRINCIPALE
        system("pause");
        system("cls");
        }
    //SCELTA N.3
    if(n2==3)
    {
    printf("MODIFICA PIANO DI STUDI DELLO STUDENTE\n");
    printf("INSERIRE NUMERO MATRICOLA STUDENTE\n");
        //INSERIMENTO MATRICOLA PER CONFRONTARE
        for(j=0;j<1;j++)
        {
        scanf("%d",&matricola3[20]);
        fflush(stdin);
        printf("\n");
            //CICLO DI CONFRONTO TRA I NUMERI DI MATRICOLE
            for(i=0;i<=n;i++)
            {
                if(*classe[i].nmatr==matricola3[20])
                {
                printf("AGGIUNGERE VOTO MATERIA \n");
                flag3=1;
                }
            }
            if(flag3==1)
            {
                for(l=0;l<1;l++)
                {
                    for(k=0;k<1;k++)
                    {
                    printf("INSERIRE MATERIA \n");
                    scanf("%s",&classe[l].esame[k].materia);
                    fflush(stdin);
                    printf("INSERIRE VOTO \n");
                    scanf("%d",&classe[l].esame[k].voto);
                    fflush(stdin);
                    }
                }
            }
            else
            {
            printf("STUDENTE NON TROVATO\n");
            }
        }
        system("pause");
        system("cls");
        }
        //CICLO WHILE PER TORNARE AL MENU PRINCIPALE
        while(n2!=1 && n2!=2 && n2!=3)
        {
        printf("ERRORE\n");
        printf("SCEGLIERE COSA EFFETTUARE:\n");
        printf("\n");
        printf("1)AGGIUNGERE NUOVO STUDENTE\n");
        printf("2)VISUALIZZARE INFORMAZIONI STUDENTE\n");
        printf("3)MODIFICARE PIANO DI STUDI\n");
        scanf("%d",&n2);
        fflush(stdin);
        system("cls");
        }
return 0;
}
