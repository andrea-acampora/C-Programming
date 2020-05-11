#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX_STRING 30
#define NUM_ESAMI 3
#define MAX_STUD 500
typedef struct{
    char nome [MAX_STRING+1];   /*DICHIARO STRUTTURA PIANO DI STUDI*/
    int voto;
}piano;
struct stud{
    int matricola;
    char cognome[MAX_STRING+1];           /*DICHIARO STRUTTURA STUDENTE CON UN VETTORE DI TIPO PIANO DI STUDI*/
    char nome[MAX_STRING+1];
    int anno_immatr;
    piano pianoStudi[NUM_ESAMI];
}studente[MAX_STUD];
int annoMatr,matri,votoProg,votoMat,votoIng,code1,code2,code3;      /*DICHIARO VARIABILI GLOBALI*/
char COgnome[MAX_STRING],NOme[MAX_STRING];
int main()
{
    int n_stud,i=0,controllo,code,j,flag,k=0,controlloMatr;           /*DICHIARAZIONE VARIABILI*/
     do{
            printf("Quanti studenti si vogliono inserire? ");
            controllo=scanf("%d",&n_stud);   /*CONTROLLO SULL'ANNO DI IMMATRICOLAZIONE*/
            fflush(stdin);
            flag=0;
            if (n_stud<=0||n_stud>MAX_STUD)
            flag=1;
        }
        while(controllo==0||flag==1);
    /*inserimento nuovo studente*/
    for(i=0;i<n_stud;i++){
        printf("\nStudente [%d]:",i);
        do{
            printf("\nNumero matricola :");
            controlloMatr=scanf("%d",&studente[i].matricola);   /*CONTROLLO CHE NON CI SIA GIA' UNO STUDENTE CON LA STESSA MATRICOLA*/
            fflush(stdin);
            controllo=studente[i].matricola;
            flag=0;
            for(j=0;j<i;j++){
            if(controllo==studente[j].matricola){
                flag=1;
        }
            }
        }
        while(controlloMatr==0||flag==1);
        printf("\nCognome :");
        fgets(studente[i].cognome, MAX_STRING, stdin);      /*INSERIMENTI E CONTROLLI VARI*/
        fflush(stdin);
        printf("\nNome :");
        fgets(studente[i].nome, MAX_STRING, stdin);
             do{
            printf("\nAnno immatricolazione :");
            controllo=scanf("%d",&studente[i].anno_immatr);   /*CONTROLLO SULL'ANNO DI IMMATRICOLAZIONE*/
            fflush(stdin);
            flag=0;
            if (studente[i].anno_immatr>2018||studente[i].anno_immatr<1900)
            flag=1;
        }
        while(controllo==0||flag==1);
       strcpy(studente[i].pianoStudi[0].nome,"Programmazione");
       strcpy(studente[i].pianoStudi[1].nome,"Analisi Matematica");
       strcpy(studente[i].pianoStudi[2].nome,"Inglese");
       do{
            printf("\nInserire voto materia %s (se non sostenuto inserire 0 o 31 per 30 e lode):",studente[i].pianoStudi[0].nome);
            controllo=scanf("%d",&studente[i].pianoStudi[0].voto);   /*CONTROLLO SUI VOTI*/
            fflush(stdin);
            flag=0;
            if (studente[i].pianoStudi[0].voto<0||studente[i].pianoStudi[0].voto>31)
            flag=1;
        }
        while(controllo==0||flag==1);
       do{
            printf("\nInserire voto materia %s (se non sostenuto inserire 0 o 31 per 30 e lode):",studente[i].pianoStudi[1].nome);
            controllo=scanf("%d",&studente[i].pianoStudi[1].voto);   /*CONTROLLO SUI VOTI*/
            fflush(stdin);
            flag=0;
            if (studente[i].pianoStudi[1].voto<0||studente[i].pianoStudi[1].voto>31)
            flag=1;
        }
        while(controllo==0||flag==1);
       do{
            printf("\nInserire voto materia %s (se non sostenuto inserire 0 o 31 per 30 e lode):",studente[i].pianoStudi[2].nome);
            controllo=scanf("%d",&studente[i].pianoStudi[2].voto);   /*CONTROLLO SUI VOTI*/
            fflush(stdin);
            flag=0;
            if (studente[i].pianoStudi[2].voto<0||studente[i].pianoStudi[2].voto>31)
            flag=1;
        }
        while(controllo==0||flag==1);
    }
    do{
        printf("\n\nInserire un codice (1 per aggiungere un nuovo studente, 2 per sapere informazioni su uno studente, 3 per modificare informazioni su un piano di studi o 4 per terminare l'esecuzione: ");
        scanf(" %d", &code);
        switch (code) {
        case 1: insert(i);
                k++;
                i++;
                studente[i].matricola=matri;            /*ASSEGNO ALLA STRUTTURA POSIZIONE I+1 I VALORI GLOBALI*/
                //printf("\n%d",studente[i].matricola);
                studente[i].anno_immatr=annoMatr;
                //printf("\n%d",studente[i].anno_immatr);
                strcpy(studente[i].cognome,COgnome);
                //printf("\n%s",studente[i].cognome);
                strcpy(studente[i].nome,NOme);
                //printf("\n%s",studente[i].nome);
                strcpy(studente[i].pianoStudi[0].nome,"Programmazione");
                strcpy(studente[i].pianoStudi[1].nome,"Analisi");
                strcpy(studente[i].pianoStudi[2].nome,"Inglese");

                              /*CREAZIONE MENU PER SEGLIERE COSA FARE CON SWITCH, SE VIENE INSERITO UN CODICE SBAGLIATO CHIUDE IL PROGRAMMA*/
        break;
        case 2: search(i+k);      /*CHIAMATE A FUNZIONI*/
        break;
        case 3: update(i+k);
                if(code1>0){
                    studente[i].pianoStudi[0].voto=votoProg;
                    //printf("\n%d\n",studente[i].pianoStudi[0].voto);
                }
                else if(code2>0){
                    studente[i].pianoStudi[1].voto=votoMat;
                   // printf("\n%d\n",studente[i].pianoStudi[1].voto);
                }
                else if(code3>0){
                    studente[i].pianoStudi[2].voto=votoIng;
                    //printf("\n%d\n",studente[i].pianoStudi[2].voto);
                }
        break;
        case 4: printf("\nProgramma terminato");
        return 0;
        default:  printf("Codice non valido\n");
        } printf("\n");
    }
    while(code!=1||code!=2||code!=3||code!=4);
}
void insert(i){
int numero,controllo,j,contrMat,flag;     /*INSERIMENTO NUOVO STUDENTE*/
if(numero==MAX_STUD){
    printf("\E' stato raggiunto il limite massimo di studenti");    /*SE NON C'E' PIU' SPAZIO O E' GIA' PRESENTE DARE IL MESSAGGIO E CHIUDE IL PROGRAMMA*/
    return;
}
    i++;
    do{
    printf("\nNumero matricola :");
    contrMat=scanf("%d",&studente[i].matricola);
    fflush(stdin);
    controllo=studente[i].matricola;
    }
    while(contrMat==0);
    for(j=0;j<i;j++){
        if(controllo==studente[j].matricola){
            printf("\nE' gia' presente uno studente con questo numero di matricola");
            return;
    }
    }
    matri=studente[i].matricola;
    printf("\nCognome :");
    fgets(studente[i].cognome, MAX_STRING, stdin);      /*SE NO INSERIMENTO DEI CAMPI E VARI CONTROLLI*/
    fflush(stdin);
    strcpy(COgnome,studente[i].cognome);
    printf("\nNome :");
    fgets(studente[i].nome, MAX_STRING, stdin);
    strcpy(NOme,studente[i].nome);
    do{
            printf("\nAnno immatricolazione :");
            controllo=scanf("%d",&studente[i].anno_immatr);
            fflush(stdin);
            flag=0;
            if (studente[i].anno_immatr>2018||studente[i].anno_immatr<1900)
            flag=1;
        }
        while(controllo==0||flag==1);
        annoMatr=studente[i].anno_immatr;
printf("\nStudente inserito correttamente");
}

void search(i){
int controllo,flag=0,j,matrControllo;
do{
printf("\nInserire la matricola dello studente da cercare :");    /*FUNZIONE CERCA TRAMITE MATRICOLA, CON PRINTF DATI SE TROVATA O MESSAGGIO SE NON TROVATA*/
matrControllo=scanf("%d",&controllo);
fflush(stdin);
}
while(matrControllo==0);
for(j=0;j<i;j++){
    if(controllo==studente[j].matricola){
        printf("Cognome :%s",studente[j].cognome);
        printf("Nome :%s",studente[j].nome);
        printf("\nAnno immatricolazione :%d",studente[j].anno_immatr);
        printf("\nMateria %s",studente[j].pianoStudi[0].nome);
        printf(" voto %d",studente[j].pianoStudi[0].voto);
        printf("\nMateria %s",studente[j].pianoStudi[1].nome);
        printf(" voto %d",studente[j].pianoStudi[1].voto);
        printf("\nMateria %s",studente[j].pianoStudi[2].nome);
        printf(" voto %d",studente[j].pianoStudi[2].voto);
        flag=1;
    }
}
if(flag<1){
    printf("\nMatricola non presente");
    return;
}
}
void update(i){
int nmatr,numMateria,controllo,j,flag=0,matrControllo,k,K;    /*INSERIMENTO MATRICOLA DA MODIFICARE*/
do{
printf("\nInserire il numero di matricola della quale si vuole modificare il piano di studi: ");
matrControllo=scanf("%d",&nmatr);
fflush(stdin);
}
while(matrControllo==0);
for(j=0;j<i;j++){
    if(nmatr==studente[j].matricola)        /*CONTROLLO CHE SIA PRESENTE*/
        flag=1;
}
if(flag<1){
    printf("\nMatricola non presente");
    return;
}
do{
printf("\nDi quale materia si vuole inserire il voto? (1 per Programmazione, 2 per Analisi e 3 per Inglese: "); /*CHIEDO MATERIA DELLA QUALE INSERIRE VOTO*/
controllo=scanf("%d",&numMateria);
fflush(stdin);
}
while(controllo==0);
code1=0;
code2=0;
code3=0;
if(numMateria==1)
    code1++;
    else if (numMateria==2)
        code2++;
        else if (numMateria==3)
            code3++;
for(j=0;j<i;j++){
    if(nmatr==studente[j].matricola)
        k=j;
}
K=i;
i=k;
for(j=0;j<K;j++){
if(nmatr==studente[j].matricola){
    if(numMateria==1){
        do{
            printf("\nInserire voto materia %s (se non sostenuto inserire 0 o 31 per 30 e lode):",studente[i].pianoStudi[0].nome);
            controllo=scanf("%d",&studente[i].pianoStudi[0].voto);   /*CONTROLLO SUI VOTI*/
            fflush(stdin);
            flag=0;
            if (studente[i].pianoStudi[0].voto<0||studente[i].pianoStudi[0].voto>31)
            flag=1;
        }
        while(controllo==0||flag==1);
        printf("\nE' stato inserito il voto %d nella materia Programmazione",studente[i].pianoStudi[0].voto);
        votoProg=studente[i].pianoStudi[0].voto;
    }
        else if(numMateria==2){ /*SE CODICE CORRISPONDE A MATERIA CHIEDE E INSERISCE VOTO, SE NO DA MESSAGGIO E CHIUDE IL PROGRAMMA*/
            do{
            printf("\nInserire voto materia %s (se non sostenuto inserire 0 o 31 per 30 e lode):",studente[i].pianoStudi[1].nome);
            controllo=scanf("%d",&studente[i].pianoStudi[1].voto);   /*CONTROLLO SUI VOTI*/
            fflush(stdin);
            flag=0;
            if (studente[i].pianoStudi[1].voto<0||studente[i].pianoStudi[1].voto>31)
            flag=1;
        }
        while(controllo==0||flag==1);
        votoMat=studente[i].pianoStudi[1].voto;
            printf("\nE' stato inserito il voto %d nella materia Analisi Matematica",studente[i].pianoStudi[2].voto);
    }
            else if(numMateria==3){
            do{
            printf("\nInserire voto materia %s (se non sostenuto inserire 0 o 31 per 30 e lode):",studente[i].pianoStudi[2].nome);
            controllo=scanf("%d",&studente[i].pianoStudi[2].voto);   /*CONTROLLO SUI VOTI*/
            fflush(stdin);
            flag=0;
            if (studente[i].pianoStudi[2].voto<0||studente[i].pianoStudi[2].voto>31)
            flag=1;
        }
        while(controllo==0||flag==1);
            printf("\nE' stato inserito il voto %d nella materia Inglese",studente[i].pianoStudi[2].voto);
            votoIng=studente[i].pianoStudi[2].voto;
    }
            else {
                printf("\nInserito un codice non valido");
                return;
            }
}
}
}
