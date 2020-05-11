#include <stdio.h>
#include <stdlib.h>
#include "Library.h"
#include "Library2.h"
#include "Library3.h"
int main()
{
    struct cella *pila;//dichiarazione struttura collegata
    pila=NULL;
    int flag=1,num;
    char ch;
    PILA_STATICA pilaStat;//dichiarazione pila statica
    PILA_STATICA *p_pila=&pilaStat;
    pilaStat.last_elem=-1;
    PILA_DINAMICA pilaDin;//dichiarazione pila dinamica
    pilaDin=CreateList_dinamic();
printf("SCEGLIERE LA MODALITA'\n\n");
printf("1)PILA CON VETTORE STATICO\n");
printf("2)PILA CON VETTORE DINAMICO\n");
printf("3)PILA CON STRUTTURE COLLEGATE\n");
ch=getchar();
fflush(stdin);
switch(ch)//switch per scegliere quale modalita' utilizzare
{
/***************PILA IMPLEMENTATA CON STRUTTURE COLLEGATE***********************/
    case '3':
        while(flag)
        {
            system("cls");
            printf("--PILA CON STRUTTURE COLLEGATE\n\n");
            printf("SCEGLIERE COSA EFFETTUARE:\n\n");
            printf("1)AGGIUNGI IN TESTA\n");
            printf("2)CANCELLA IN TESTA\n");
            printf("3)STAMPA E AZZERA\n");
            printf("4)AZZERA LA PILA\n");
            printf("5)USCIRE\n");
            ch=getchar();
            fflush(stdin);
            switch(ch)
            {
                case '1':system("cls");
                    printf("AGGIUNTA ELEMENTO IN TESTA ALLA PILA \n\n");
                    printf("INSERIRE NUMERO: \n");
                    scanf("%d",&num);
                    fflush(stdin);
                    push(&pila,num);//richiamo la funzione push per inserire in testa
                    system("pause");
                    break;
                case '2':system("cls");
                    printf("CANCELLAZIONE ELEMENTO IN TESTA ALLA PILA \n\n");
                    if(pila==NULL)
                    {
                        printf("LA PILA E' VUOTA\n");
                    }
                    else
                    {
                        pop(&pila);//richiamo la funzione pop per cancellare in testa
                        printf("ELEMENTO CANCELLATO CON SUCCESSO\n");
                    }
                    system("pause");
                    break;
                case '3':system("cls");
                    printf("STAMPA DELLA PILA\n\n");
                    if(pila==NULL)
                    {
                        printf("LA PILA E' VUOTA\n");
                    }
                    else
                    {
                    StampaAzzera(&pila);//richiamo la funzione stampa e azzera
                    printf("LISTA AZZERATA\n");
                    }
                    system("pause");
                    break;
                case '4':system("cls");
                    printf("RESET DELLA PILA\n\n");
                    if(pila==NULL)
                    {
                        printf("LA PILA E' VUOTA\n");
                    }
                    else
                    {
                        ResetPila(&pila);//richiamo a funzione
                        printf("PILA AZZERATA CON SUCCESSO\n");
                    }
                    system("pause");
                    break;
                case '5':system("cls");
                    flag=0;//COMANDO PER USCIRE DAL CICLO WHILE
                    system("pause");
                    break;

            }
        }
/***************PILA IMPLEMENTATA CON VETTORE STATICO ***********************/
    case '1':
            while(flag)
            {
            system("cls");
            printf("--PILA CON VETTORE STATICO\n\n");
            printf("SCEGLIERE COSA EFFETTUARE:\n\n");
            printf("1)AGGIUNGI IN TESTA\n");
            printf("2)CANCELLA IN TESTA\n");
            printf("3)STAMPA E AZZERA\n");
            printf("4)AZZERA LA PILA\n");
            printf("5)USCIRE\n");
            ch=getchar();
            fflush(stdin);
            switch(ch)
            {
            case '1':system("cls");
                    printf("AGGIUNTA ELEMENTO IN TESTA ALLA PILA (PUSH)\n");
                    pushStatic(p_pila);//richiamo a funzione
                    printf("ELEMENTO INSERITO CON SUCCESSO!!\n");
                    StatoPila_static(p_pila);//richiamo a funzione per mostrare lo stato della pila
                    printf("\n\n");
                    system("pause");
                    break;
            case '2':system("cls");
                    printf("CANCELLAZIONE ELEMENTO IN TESTA ALLA PILA (POP)\n");
                    if(isEmpty_static(p_pila))                 /*se la lista è vuota*/
                     {
                    printf("PILA VUOTA!\n");     /*non faccio nulla e avviso l'utente*/
                     }
                    else
                    {
                    popStatic(p_pila);//richiamo a funzione
                    StatoPila_static(p_pila);//richiamo a funzione
                    printf("\nELEMENTO CANCELLATO CON SUCCESSO!!\n");
                    }
                    system("pause");
                    break;
            case '3':system("cls");
                    printf("STAMPA E AZZERA DELLA PILA\n");
                    if (isEmpty_static(p_pila))                 /*se la lista è vuota*/
                    {
                    printf("LISTA VUOTA!\n");     /*non faccio nulla e avviso l'utente*/
                    }
                    else
                    {
                    StatoPila_static(p_pila);//richiamo a funzione
                    printf("\nPILA STAMPATA E AZZERATA CON SUCCESSO!!\n");
                    }
                    system("pause");
                    break;
            case '4':system("cls");
                    printf("RESET DELLA PILA\n\n");
                    if (isEmpty_static(p_pila))                 /*se la lista è vuota*/
                    {
                    printf("LISTA VUOTA!\n");     /*non faccio nulla e avviso l'utente*/
                    }
                    else
                    {
                    resetStatic(p_pila);
                    printf("\nPILA AZZERATA CON SUCCESSO!!\n");
                    StatoPila_static(p_pila);
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
/***************PILA IMPLEMENTATA CON VETTORE DINAMICO ***********************/
    case '2':
        while(flag)
        {
            system("cls");
            printf("--PILA CON VETTORE DINAMICO\n\n");
            printf("SCEGLIERE COSA EFFETTUARE:\n\n");
            printf("1)AGGIUNGI IN TESTA\n");
            printf("2)CANCELLA IN TESTA\n");
            printf("3)STAMPA E AZZERA\n");
            printf("4)AZZERA LA PILA\n");
            printf("5)USCIRE\n");
            ch=getchar();
            fflush(stdin);
            switch(ch)
            {
            case '1':system("cls");
                    printf("-AGGIUNTA ELEMENTO IN TESTA ALLA PILA\n");
                    PushDinamic(&pilaDin);//richiamo a funzione
                    StatoDinamic(&pilaDin);//richiamo a funzione
                    printf("\n");
                    printf("ELEMENTO INSERITO CON SUCCESSO!!\n");
                    printf("\n");
                    system("pause");
                    break;
            case '2':system("cls");
                    printf("-CANCELLAZIONE ELEMENTO IN TESTA ALLA PILA\n");
                    if(IsEmpty_dinamic(&pilaDin))//richiamo a funzione
                    {
                        printf("LA PILA E' VUOTA\n");
                    }
                    else
                    {
                        PopDinamic(&pilaDin);//richiamo a funzione
                        printf("\n");
                        printf("ELEMENTO CANCELLATO CON SUCCESSO!!\n");
                        StatoDinamic(&pilaDin);
                    }
                    printf("\n");
                    system("pause");
                    break;
            case '3':system("cls");
                    printf("-STAMPA DELLA PILA\n\n");
                    if(IsEmpty_dinamic(&pilaDin))
                    {
                        printf("LA PILA E' VUOTA\n");
                    }
                    else
                    {
                        PrintDinamic(&pilaDin);//richiamo a funzione
                        printf("\n");
                        printf("LISTA STAMPATA E  AZZERATA!\n");
                    }
                    printf("\n");
                    system("pause");
                    break;
            case '4':system("cls");
                    printf("-RESET DELLA PILA\n\n");
                    if(IsEmpty_dinamic(&pilaDin))
                    {
                        printf("LA PILA E' VUOTA!\n");
                    }
                    else
                    {
                        ResetDinamic(&pilaDin);//richiamo a funzione
                        printf("\n");
                        printf("PILA AZZERATA CON SUCCESSO!!\n");
                        StatoDinamic(&pilaDin);//richiamo a funzione
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
