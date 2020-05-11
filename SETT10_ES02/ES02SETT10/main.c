#include <stdio.h>
#include <stdlib.h>
#include "Library.h"
#include "Library2.h"
#include "Library3.h"
int main()
{

    int flag=1,num;
    char ch;
    TipoCoda *codaStruct;
    struct cella *testa=NULL;
    struct cella *coda=NULL;
    CODA_STATICA codaStat;//dichiarazione CODA statica
    CODA_STATICA *p_coda=&codaStat;
    codaStat.last_elem=-1;
    CODA_DINAMICA codaDin;//dichiarazione CODA dinamica
    codaDin=CreateList_dinamic();
printf("SCEGLIERE LA MODALITA'\n\n");
printf("1)CODA CON VETTORE STATICO\n");
printf("2)CODA CON VETTORE DINAMICO\n");
printf("3)CODA CON STRUTTURE COLLEGATE\n");
ch=getchar();
fflush(stdin);
switch(ch)//switch per scegliere quale modalita' utilizzare
{
/***************CODA IMPLEMENTATA CON STRUTTURE COLLEGATE***********************/
    case '3':
        while(flag)
        {
            system("cls");
            printf("--CODA CON STRUTTURE COLLEGATE\n\n");
            printf("SCEGLIERE COSA EFFETTUARE:\n\n");
            printf("1)AGGIUNGI IN CODA\n");
            printf("2)CANCELLA IN TESTA\n");
            printf("3)STAMPA E AZZERA\n");
            printf("4)AZZERA LA CODA\n");
            printf("5)USCIRE\n");
            ch=getchar();
            fflush(stdin);
            switch(ch)
            {
                case '1':system("cls");
                    printf("AGGIUNTA ELEMENTO IN CODA(PUSH) \n\n");
                    printf("INSERIRE NUMERO: \n");
                    scanf("%d",&num);
                    fflush(stdin);
                    push(&testa,num);//richiamo la funzione push per inserire in CODA
                    printf("COMANDO ESEGUITO CON SUCCESSO!\n");
                    stato(testa);
                    printf("\n");
                    system("pause");
                    break;
                case '2':system("cls");
                    printf("CANCELLAZIONE ELEMENTO IN TESTA (POP) \n\n");
                    if(testa==NULL)
                    {
                        printf("LA CODA E' VUOTA\n");
                    }
                    else
                    {
                    pop(&testa);//richiamo la funzione pop per cancellare in testa
                    printf("ELEMENTO CANCELLATO CON SUCCESSO\n");
                    }
                    stato(testa);
                    printf("\n");
                    system("pause");
                    break;
                    case '3':system("cls");
                    printf("STAMPA DELLA CODA\n\n");
                    if(testa==NULL)
                    {
                        printf("LA CODA E' VUOTA\n");
                    }
                    else
                    {
                  StampaAzzera(testa);//richiamo la funzione stampa e azzera
                    printf("LISTA AZZERATA\n");
                    }
                    system("pause");
                    break;
                case '4':system("cls");
                    printf("RESET DELLA CODA\n\n");
                   if(testa==NULL)
                    {
                        printf("LA CODA E' VUOTA\n");
                    }
                    else
                    {
                   ResetCoda(&testa);//richiamo a funzione
                        printf("CODA AZZERATA CON SUCCESSO\n");
                    }
                    system("pause");
                    break;
                case '5':system("cls");
                    flag=0;//COMANDO PER USCIRE DAL CICLO WHILE
                    system("pause");
                    break;

            }
        }
/***************CODA IMPLEMENTATA CON VETTORE STATICO ***********************/
    case '1':
            while(flag)
            {
            system("cls");
            printf("--CODA CON VETTORE STATICO\n\n");
            printf("SCEGLIERE COSA EFFETTUARE:\n\n");
            printf("1)AGGIUNGI IN CODA\n");
            printf("2)CANCELLA IN TESTA\n");
            printf("3)STAMPA E AZZERA\n");
            printf("4)AZZERA LA CODA\n");
            printf("5)USCIRE\n");
            ch=getchar();
            fflush(stdin);
            switch(ch)
            {
            case '1':system("cls");
                    printf("AGGIUNTA ELEMENTO IN CODA (PUSH)\n");
                    pushStatic(p_coda);//richiamo a funzione
                    printf("ELEMENTO INSERITO CON SUCCESSO!!\n");
                    StatoCoda_static(p_coda);//richiamo a funzione per mostrare lo stato della pila
                    printf("\n\n");
                    system("pause");
                    break;
            case '2':system("cls");
                    printf("CANCELLAZIONE ELEMENTO IN TESTA (POP)\n");
                    if(isEmpty_static(p_coda))                 /*se la lista è vuota*/
                     {
                    printf("CODA VUOTA!\n");     /*non faccio nulla e avviso l'utente*/
                     }
                    else
                    {
                    popStatic(p_coda);//richiamo a funzione
                    StatoCoda_static(p_coda);//richiamo a funzione
                    printf("\nELEMENTO CANCELLATO CON SUCCESSO!!\n");
                    }
                    system("pause");
                    break;
            case '3':system("cls");
                    printf("STAMPA E AZZERA DELLA CODA\n");
                    if (isEmpty_static(p_coda))                 /*se la lista è vuota*/
                    {
                    printf("LISTA VUOTA!\n");     /*non faccio nulla e avviso l'utente*/
                    }
                    else
                    {
                    StampaCoda_static(p_coda);//richiamo a funzione
                    printf("\nCODA STAMPATA E AZZERATA CON SUCCESSO!!\n");
                    }
                    system("pause");
                    break;
            case '4':system("cls");
                    printf("RESET DELLA CODA\n\n");
                    if (isEmpty_static(p_coda))               /*se la lista è vuota*/
                    {
                    printf("LISTA VUOTA!\n");     /*non faccio nulla e avviso l'utente*/
                    }
                    else
                    {
                    resetStatic(p_coda);
                    printf("\CODA AZZERATA CON SUCCESSO!!\n");
                    StatoCoda_static(p_coda);
                    }
                    printf("\n");
                    system("pause");
                    break;
            case '5':system("cls");
                    flag=0;//COMANDO PER USCIRE DAL CICLO WHILE
                    system("pause");
                    break;

            }
        }
/***************CODA IMPLEMENTATA CON VETTORE DINAMICO ***********************/
    case '2':
        while(flag)
        {
            system("cls");
            printf("--CODA CON VETTORE DINAMICO\n\n");
            printf("SCEGLIERE COSA EFFETTUARE:\n\n");
            printf("1)AGGIUNGI IN CODA\n");
            printf("2)CANCELLA IN TESTA\n");
            printf("3)STAMPA E AZZERA\n");
            printf("4)AZZERA LA CODA\n");
            printf("5)USCIRE\n");
            ch=getchar();
            fflush(stdin);
            switch(ch)
            {
            case '1':system("cls");
                    printf("-AGGIUNTA ELEMENTO IN CODA (PUSH)\n");
                    PushDinamic(&codaDin);//richiamo a funzione
                    printf("\n");
                    printf("ELEMENTO INSERITO CON SUCCESSO!!\n");
                    StatoDinamic(&codaDin);//richiamo a funzione
                    printf("\n");
                    system("pause");
                    break;
            case '2':system("cls");
                    printf("-CANCELLAZIONE ELEMENTO IN TESTA (POP)\n");
                    if(IsEmpty_dinamic(&codaDin))//richiamo a funzione
                    {
                        printf("LA CODA E' VUOTA\n");
                    }
                    else
                    {
                        PopDinamic(&codaDin);//richiamo a funzione
                        printf("\n");
                        printf("ELEMENTO CANCELLATO CON SUCCESSO!!\n");
                        StatoDinamic(&codaDin);
                    }
                    printf("\n");
                    system("pause");
                    break;
            case '3':system("cls");
                    printf("-STAMPA DELLA CODA\n\n");
                    if(IsEmpty_dinamic(&codaDin))
                    {
                        printf("LA CODA E' VUOTA\n");
                    }
                    else
                    {
                        PrintDinamic(&codaDin);//richiamo a funzione
                        printf("\n");
                        printf("LISTA STAMPATA E  AZZERATA!\n");
                    }
                    printf("\n");
                    system("pause");
                    break;
            case '4':system("cls");
                    printf("-RESET DELLA CODA\n\n");
                    if(IsEmpty_dinamic(&codaDin))
                    {
                        printf("LA CODA E' VUOTA!\n");
                    }
                    else
                    {
                        ResetDinamic(&codaDin);//richiamo a funzione
                        printf("\n");
                        printf("CODA AZZERATA CON SUCCESSO!!\n");
                        StatoDinamic(&codaDin);//richiamo a funzione
                    }
                    printf("\n");
                    system("pause");
                    break;
            case '5':system("cls");
                    flag=0;//COMANDO PER USCIRE DAL CICLO WHILE
                    system("pause");
                    break;

            }
        }
}
    return 0;
}
