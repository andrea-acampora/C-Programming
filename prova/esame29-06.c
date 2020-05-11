#include <stdlib.h>
#include <stdio.h>
#include <string.h>
typedef struct{
    int codice_paziente;
    char nome[20];
    char cognome[20];
    char codice_fiscale[16];
    int ora_arrivo;
    int codice_colore;
    struct paziente * next;
}paziente;
paziente* inserisci_paziente(paziente **testa,int id_paziente,char nome[],char cognome[],char codice_fiscale,int ora_arrivo,int codice_colore)
{
    paziente *temp;
    temp=*testa;
    paziente *nuovo;
    paziente *prec=NULL;
    nuovo=(paziente*)malloc(sizeof(paziente));
    if(nuovo==NULL)
    {
        printf("ERRORE NELL'ALLOCAZIONE DELLA MEMORIA!\n");
        exit(1);
    }
    nuovo->codice_paziente=id_paziente;
    strcpy(nome,nuovo->nome);
    strcpy(nuovo->cognome,cognome);
    strcpy(nuovo->codice_fiscale,codice_fiscale);
    nuovo->ora_arrivo=ora_arrivo;
    nuovo->codice_colore=codice_colore;
    if(temp==NULL)
    {
        *testa=nuovo;
        return nuovo;
    }
    while(temp!=NULL&&(nuovo->codice_colore<=temp->codice_colore && nuovo->ora_arrivo>temp->ora_arrivo))
    {
        prec=temp;
        temp=temp->next;
    }
    if(prec==NULL)
    {
        *testa=nuovo;
        nuovo->next=temp;
    }
    if(temp->next==NULL)
    {
        temp->next=nuovo;
        nuovo->next=NULL;
    }
    prec->next=nuovo;
    nuovo->next=temp;
}
void stampa(paziente **testa)
{
    paziente *temp;
    temp=*testa;
    while(temp!=NULL)
    {
        printf("CODICE: %d \n",temp->codice_paziente);
        printf("NOME: %s \n",temp->nome[20]);
        printf("COGNOME: %s \n",temp->cognome);
        printf("CODICE FISCALE: %s \n",temp->codice_fiscale);
        printf("ORA ARRIVO: %d \n",temp->ora_arrivo);
        printf("CODICE COLORE: %d \n\n\n",temp->codice_colore);
        temp=temp->next;
    }
}
int main()
{
 paziente *testa=NULL;
 int flag=1;
 char nome[20],cognome[20],codice_fiscale[16];
 int scelta,ora_arrivo,codice_colore,codice_paziente;
 while(flag)
 {
     system("cls");
 printf("LISTA PAZIENTI IN OSPEDALE\n\n");
 printf("SCEGLIERE COSA EFFETTUARE: \n\n");
 printf("-1)AGGIUNGI PAZIENTE IN CODA\n\n");
 printf("-2)VISITA PAZIENTE IN TESTA\n\n");
 printf("-3)MODIFICA PRIORITA' PAZIENTE \n\n");
 printf("-4)STAMPA LISTA PAZIENTI\n\n");
 printf("-5)ESCI DAL PROGRAMMA\n\n\n");
scelta=getchar();
fflush(stdin);
    switch(scelta)
    {
      case '1':system("cls");
                printf("AGGIUNTA PAZIENTE IN CODA\n\n");
                printf("INSERIRE CODICE PAZIENTE: \n");
                scanf("%d",&codice_paziente);
                fflush(stdin);
                printf("INSERIRE NOME PAZIENTE: \n");
                scanf("%s",&nome[20]);
                fflush(stdin);
                printf("INSERIRE COGNOME PAZIENTE: \n");
                scanf("%s",&cognome[20]);
                fflush(stdin);
                printf("INSERIRE CODICE FISCALE PAZIENTE: \n");
                scanf("%s",&codice_fiscale[16]);
                fflush(stdin);
                printf("INSERIRE ORA ARRIVO PAZIENTE: \n");
                scanf("%d",&ora_arrivo);
                fflush(stdin);
                printf("INSERIRE CODICE COLORE PAZIENTE: \n");
                scanf("%d",&codice_colore);
                fflush(stdin);
                inserisci_paziente(&testa,codice_paziente,nome,cognome,codice_fiscale,ora_arrivo,codice_colore);
                system("pause");
                break;
    case '2':system("cls");
            system("pause");
            break;
    case '3':system("cls");
            system("pause");
            break;
    case '4':system("cls");
            stampa(&testa);
            system("pause");
            break;

     case '5':system("cls");
            flag=0;
            system("pause");
            break;

    }
 }





}
