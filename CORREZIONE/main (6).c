/*ESERCIZIO 1 SETTIMANA 8
Si scriva un programma C, adeguatamente commentato,
che gestisca un certo numero di studenti iscritti ad un corso di laurea.
Il programma utilizza un vettore di strutture, ognuna delle quali
memorizza le informazioni di uno studente (numero matricola, nome e cognome,
anno di immatricolazione, piano di studi).
Il programma deve fornire la possibilità di:

- aggiungere un nuovo studente, stampando un messaggio di errore se
lo studente è già presente (individuato dalla matricola) o se il vettore è pieno.
- dato il numero di matricola, stampare le informazioni dello studente
oppure un messaggio di errore se la matricola non è presente nel vettore
- dato un numero di matricola, modificare le informazioni del piano di studi
aggiungendo un voto oppure stampando un messaggio di errore se la matricola non è presente nel vettore.

Il piano di studi è un vettore di NUM_ESAMI elementi ognuno di tipo struttura
contenete il nome dell'insegnamento e il voto corrispondente (0 se non sostenuto).*/
#include <stdio.h>
#include <stdlib.h>
#define MAX_NOME 20
//Dichiarazione della prima struct contenente il piano di studi
typedef struct pstudio {
            int voto;
            char materia[MAX_NOME];
        }NUM_ESAMI;
//Dichiarazione seconda struct contenente le info dello studente
typedef struct persona {
            int numMatr, annoImm;
            char nome[MAX_NOME], cognome[MAX_NOME];
            NUM_ESAMI exam[11];
        }STUDENTE;

int main()
{
//Dichiarazione delle variabili
    STUDENTE vetS[11];
    int ret=0, tmp, tmp1, tmp2, tmp3, i=0, numMatrTemp, numMatrTemp1, count, count1;
//Inserimento dello studente e il ciclo do-while fa da controllo sull'input inerito dall'utente
    do {
        i++;
        printf("IL MAX NUMERO DI STUDENTI CHE SI PUO' INSERIRE E' 10\n\n");
        printf("INSERIRE I DATI DELLO STUDENTE %d\n\n", i);
        do {
            printf("NOME: ");
            ret=scanf("%s", vetS[i].nome);
            fflush(stdin);
        }
        while (ret==0);
        do {
            printf("COGNOME: ");
            ret=scanf("%s", vetS[i].cognome);
            fflush(stdin);
        }
        while (ret==0);
        do {
            printf("ANNO IMMATRICOLAZIONE: ");
            ret=scanf("%d", &vetS[i].annoImm);
            fflush(stdin);
        }
        while (ret==0);
        do {
            printf("NUMERO MATRICOLA: ");
            ret=scanf("%d", &vetS[i].numMatr);
            fflush(stdin);
        }
        while (ret==0);
//Controllo che il nuovo numero di matricola non sia già stato inserito
        for (int j=1;j<i;j++){
            if (vetS[i].numMatr==vetS[j].numMatr){
                printf("Lo studente e' gia' stato inserito. Il programma si chiudera' a breve\n\n");
                system("pause");
                exit(1);
            }
        }
//Si concede all'utente di inserire altri utenti e si ricomincia il ciclo se l'utente digita 0
        printf("\n\nSE SI VUOLE INSERIRE UN ALTRO STUDENTE PREMERE 0, SE SI VUOLE CONTINUARE PREMERE INVECE 1: ");
        scanf("%d", &tmp);
        system("cls");
    }
    while (tmp==0);
//Chiedere all'utente che altra funzione vuole fare con il nstro programma
    do {
        printf("INSERIRE 0 SE SI VUOLE SOLAMENTE VISUALIZZARE LE INFORMAZIONI DI UNO STUDENTE,\nMENTRE INSERIRE ");
        printf("1 SE SI VUOLE MODIFICARE IL PIANO DI STUDI: ");
        ret=scanf("%d", &tmp1);
        fflush(stdin);
    }
    while (ret==0);
    system("cls");
//Caso in cui l'utente abbia digitato 0 e voglia visualizzare le informazioni di hno studente
    if (tmp1==0){
//Utilizzo sempre un ciclo do while per poter ripetere l'operazione quante volte l'utente desidera
        do {
//Controllo sul dato inserito dall'utente
            do {
                printf("INSERIRE IL NUMERO DI MATRICOLA: ");
                ret=scanf("%d", &numMatrTemp);
                fflush(stdin);
            }
            while (ret==0);
//Visualizzazione delle informazioni dell'utente
            printf("\nIl numero di matricola inserito e': %d\n", numMatrTemp);
            for (int k=1;k<10;k++){
                if (vetS[k].numMatr==numMatrTemp){
                    count=1;
                    printf("E corrisponde all'utente con queste credenziali:\n");
                    printf("NOME: %s\n", vetS[k].nome);
                    printf("COGNOME: %s\n", vetS[k].cognome);
                    printf("ANNO IMMATRICOLAZIONE: %d\n", vetS[k].annoImm);
                    printf("NUMERO MATRICOLA: %d\n", vetS[k].numMatr);
                    break;
                }
                else
                    count=0;
            }
//Caso in cui non ci sia corrispondenza tra il numero di matricola inserito e quelli in precedenza
            if (count==0)
                printf("Non e' stato possibile trovare uno studente con il numero di matricola inserito\n");
//Chiedere all'utente di inserire 0 per continuare e 1 per uscire
        printf("\n\nINSERIRE 0 PER INSERIRE UN NUOVO NUMERO DI MATRICOLA E VISUALIZZARE LE INFORMAZIONI DI UN ALTRO STUDENTE\n");
        printf("ALTRIMENTI INSERIRE 1 PER CHIUDERE IL PROGRAMMA: ");
        scanf("%d", &tmp2);
        system("cls");
        if (tmp2!=0){
            printf("\n");
            system("pause");
            exit(1);
        }
        }
        while (tmp2==0);
    }
//Caso in cui si voglia modoficare il piano di studi
    if (tmp1==1){
        do {
            do {
                printf("INSERIRE IL NUMERO DI MATRICOLA: ");
                ret=scanf("%d", &numMatrTemp1);
                fflush(stdin);
                system("cls");
            }
            while (ret==0);
//Inserimento dai piano di studi
            printf("\nIl numero di matricola inserito e': %d\n", numMatrTemp1);
            for (int j=0;j<10;j++){
                if (vetS[j].numMatr==numMatrTemp1){
                    count1=1;
                    printf("\nINSERIRE ORA IL NOME DELLA MATERIA E IL VOTO CORRISPONDENTE:\n");
                    do {
                        printf("MATERIA: ");
                        ret=scanf("%s", vetS[j].exam[j].materia);
                        fflush(stdin);
                    }
                    while (ret==0);
                    do {
                        printf("VOTO: ");
                        ret=scanf("%d", &vetS[j].exam[j].voto);
                        fflush(stdin);
                    }
                    while (ret==0);
                    system("cls");
//Stampa delle credenziali aggiornate
                    printf("Ora le credenziale aggiornate dell'utente sono:\n");
                    printf("NOME: %s\n", vetS[j].nome);
                    printf("COGNOME: %s\n", vetS[j].cognome);
                    printf("ANNO IMMATRICOLAZIONE: %d\n", vetS[j].annoImm);
                    printf("NUMERO MATRICOLA: %d\n", vetS[j].numMatr);
                    printf("MATERIA: %s\n", vetS[j].exam[j].materia);
                    printf("VOTO: %d\n", vetS[j].exam[j].voto);
                    break;
                }
                else
                    count1=0;
            }
            if (count1==0){
                printf("Il numero di matricola inserito non corrisponde a nessun utente\n");
                tmp3=0;
            }
//Inserimento dell'utente che aggiorna o chiude il programma
            do {
                        printf("INSERIRE 0 SE SI VUOLE AGGIORNARE IL PIANO DI STUDI DI UN ALTRO STUDENTE,\n");
                        printf("ALTRIMENTI PREMERE 1 PER CHIUDERE IL PROGRAMMA: ");
                        ret=scanf("%d", &tmp3);
                        fflush(stdin);
            }
            while (ret==0);
            if (tmp3==1){
                system("pause");
                exit(1);
                    }
                }
        while (tmp3==0);
    }
    return 0;
}
