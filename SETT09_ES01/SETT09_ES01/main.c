#include <stdio.h>
#include <stdlib.h>
#include "Library_functions_Struct.h"
#include "Library_function_vettStat.h"
#include "Library_functions_vettDin.h"
int main()
{
    int numero,numero2,numero3,num3,num4,num5,flag=1,flag2=1,flag3=1;
    char opzione,opzione2,opzione3,opzione4;
    struct cella *testa;
    testa=NULL;
    TipoLista *l;
printf("SCEGLIERE LA MODALITA' DI ESECUZIONE DELL'ESERCIZIO\n\n");
printf("1 - LISTA IMPLEMENTATA CON STRUTTURE COLLEGATE\n\n");
printf("2 - LISTA IMPLEMENTATA CON VETTORE DINAMICO\n\n");
printf("3 - LISTA IMPLEMENTATA CON VETTORE STATICO\n\n");
opzione2=getchar();
switch(opzione2)
{
case '1':
    while(flag)
    {
    system("cls");
    printf("SCEGLIERE L'OPERAZIONE DA EFFETTUARE \n");
    printf("\n\n");
    printf("1)STAMPA LA LISTA \n");
    printf("2)INSERIRE ELEMENTO IN TESTA ALLA LISTA \n");
    printf("3)INSERIRE ELEMENTO IN CODA ALLA LISTA \n");
    printf("4)INSERIRE ELEMENTO DOPO UN CERTO ELEMENTO \n");
    printf("5)CANCELLA ELEMENTO DALLA TESTA DELLA LISTA \n");
    printf("6)CANCELLA ELEMENTO DALLA CODA DELLA LISTA \n");
    printf("7)CANCELLA LA PRIMA OCCORRENZA DELL'ELEMENTO \n");
    printf("8)ESCI DAL PROGRAMMA\n\n");
    fflush(stdin);
    opzione=getchar();
    switch(opzione)
    {
    case '1':system("cls");
            printf("STAMPA DELLA LISTA");
            PrintList(testa);
            system("pause");
            break;

    case '2':system("cls");
            printf("INSERISCI UN NUMERO DA INSERIRE IN TESTA ALLA LISTA\n");
            printf("\n");
            scanf("%d",&numero);
            fflush(stdin);
            InserToHead(&testa,numero);
            printf("ELEMENTO INSERITO CORRETTTAMENTE  \n");
            system("pause");
            break;
    case '3':system("cls");
            printf("INSERISCI UN NUMERO DA INSERIRE IN CODA ALLA LISTA\n");
            printf("\n");
            scanf("%d",&numero2);
            fflush(stdin);
            InserToBottom(&testa,numero2);
            printf("ELEMENTO INSERITO CORRETTTAMENTE  \n");
            system("pause");
            break;

    case '4':system("cls");
            printf("INSERIMENTO ELEMENTO DOPO UN CERTO ELEMENTO \n");
            printf("\n");
            printf("ELEMENTO DA CERCARE NELLA LISTA \n\n");
            scanf("%d",&num3);
            fflush(stdin);
            printf("INSERIRE ELEMENTO DA AGGIUNGERE\n\n");
            scanf("%d",&num5);
            fflush(stdin);
            InsAfterFind(&testa,num3,num5);
            fflush(stdin);
            break;
    case '5':system("cls");
            printf("CANCELLAZIONE ELEMENTO IN TESTA ALLA LISTA\n\n");
            DeleteHead(&testa);
            printf("ELEMENTO CANCELLATO!\n");
            system("pause");
            break;
    case '6':system("cls");
            printf("CANCELLAZIONE ELEMENTO IN CODA ALLA LISTA\n\n");
            DeleteBottom(&testa);
            printf("ELEMENTO CANCELLATO!\n");
            system("pause");
            break;
    case '7':system("cls");
            printf("INSERIMENTO ELEMENTO DA CANCELLARE\n");
            scanf("%d",&num4);
            fflush(stdin);
            if(DeleteValue(&testa,num4))
            printf("ELEMENTO: %d CANCELLATO CORRETTTAMENTE  \n",num4);
            else
            printf("VALORE NON PRESENTE NELLA LISTA\n");
            system("pause");
            break;
    case '8':flag=0;
            break;
    }
}
break;
    case '2':system("cls");
            while(flag2)
    {
    system("cls");
    printf("SCEGLIERE L'OPERAZIONE DA EFFETTUARE \n");
    printf("\n\n");
    printf("1)STAMPA LA LISTA \n");
    printf("2)INSERIRE ELEMENTO IN TESTA ALLA LISTA \n");
    printf("3)INSERIRE ELEMENTO IN CODA ALLA LISTA \n");
    printf("4)INSERIRE ELEMENTO DOPO UN CERTO ELEMENTO \n");
    printf("5)CANCELLA ELEMENTO DALLA TESTA DELLA LISTA \n");
    printf("6)CANCELLA ELEMENTO DALLA CODA DELLA LISTA \n");
    printf("7)CANCELLA LA PRIMA OCCORRENZA DELL'ELEMENTO \n");
    printf("8)ESCI DAL PROGRAMMA\n\n");
    fflush(stdin);
    opzione3=getchar();
    system("cls");
    switch(opzione3)
    {
    system("cls");
    case '1':system("cls");
            printf("STAMPA DELLA LISTA");
            PrintList(testa);
            system("pause");
            break;
    case '2':system("cls");
            printf("INSERISCI UN NUMERO DA INSERIRE IN TESTA ALLA LISTA\n");
            printf("\n");
            scanf("%d",&numero);
            fflush(stdin);
           //Insert(&p,numero);
            printf("ELEMENTO INSERITO CORRETTTAMENTE  \n");
            system("pause");
            break;
    case '3':system("cls");
            printf("INSERISCI UN NUMERO DA INSERIRE IN CODA ALLA LISTA\n");
            printf("\n");
            scanf("%d",&numero2);
            fflush(stdin);
            InserToBottom(&testa,numero2);
            printf("ELEMENTO INSERITO CORRETTTAMENTE  \n");
            system("pause");
            break;
    case '4':system("cls");
            printf("INSERIMENTO ELEMENTO DOPO UN CERTO ELEMENTO \n");
            printf("\n");
            printf("INSERIRE ELEMENTO DELLA LISTA \n\n");
            scanf("%d",&num3);
            fflush(stdin);
            break;
    case '5':system("cls");
            printf("CANCELLAZIONE ELEMENTO IN TESTA ALLA LISTA\n\n");
            DeleteHead(&testa);
            printf("ELEMENTO CANCELLATO!\n");
            system("pause");
            break;
    case '6':system("cls");
            printf("CANCELLAZIONE ELEMENTO IN CODA ALLA LISTA\n\n");
            DeleteBottom(&testa);
            printf("ELEMENTO CANCELLATO!\n");
            system("pause");
            break;
    case '7':system("cls");
            printf("INSERIMENTO ELEMENTO DA CANCELLARE\n");
            scanf("%d",&num4);
            fflush(stdin);
            if(DeleteValue(&testa,num4))
            printf("ELEMENTO: %d CANCELLATO CORRETTTAMENTE  \n",num4);
            else
            printf("VALORE NON PRESENTE NELLA LISTA\n");
            system("pause");
            break;
    case '8':flag2=0;
            break;
            system("pause");
            break;
    }
    }
    break;
    case '3':system("cls");
            while(flag3)
    {
    system("cls");
    printf("SCEGLIERE L'OPERAZIONE DA EFFETTUARE \n");
    printf("\n\n");
    printf("1)STAMPA LA LISTA \n");
    printf("2)INSERIRE ELEMENTO IN TESTA ALLA LISTA \n");
    printf("3)INSERIRE ELEMENTO IN CODA ALLA LISTA \n");
    printf("4)INSERIRE ELEMENTO DOPO UN CERTO ELEMENTO \n");
    printf("5)CANCELLA ELEMENTO DALLA TESTA DELLA LISTA \n");
    printf("6)CANCELLA ELEMENTO DALLA CODA DELLA LISTA \n");
    printf("7)CANCELLA LA PRIMA OCCORRENZA DELL'ELEMENTO \n");
    printf("8)ESCI DAL PROGRAMMA\n\n");
    fflush(stdin);
    opzione4=getchar();
    switch(opzione4)
    {
    system("cls");
    case '1':system("cls");
            printf("STAMPA DELLA LISTA\n");
           // printVett(l);
            system("pause");
            break;

    case '2':system("cls");
            printf("INSERISCI UN NUMERO DA INSERIRE IN TESTA ALLA LISTA\n");
            printf("\n");
            scanf("%d",&numero3);
            fflush(stdin);
            InserToHeadVett(l,0,numero3);
            printf("ELEMENTO INSERITO CORRETTTAMENTE \n");
            system("pause");
            break;
    case '3':system("cls");
            printf("INSERISCI UN NUMERO DA INSERIRE IN CODA ALLA LISTA\n");
            printf("\n");
            scanf("%d",&numero2);
            fflush(stdin);
            InserToBottom(&testa,numero2);
            printf("ELEMENTO INSERITO CORRETTTAMENTE  \n");
            system("pause");
            break;
    case '4':system("cls");
            printf("INSERIMENTO ELEMENTO DOPO UN CERTO ELEMENTO \n");
            printf("\n");
            printf("INSERIRE ELEMENTO DELLA LISTA \n\n");
            scanf("%d",&num3);
            fflush(stdin);
            break;
    case '5':system("cls");
            printf("CANCELLAZIONE ELEMENTO IN TESTA ALLA LISTA\n\n");
            //DeleteVett(l,p);
            printf("ELEMENTO CANCELLATO!\n");
            system("pause");
            break;
    case '6':system("cls");
            printf("CANCELLAZIONE ELEMENTO IN CODA ALLA LISTA\n\n");
            //DeleteVett(l,p);
            printf("ELEMENTO CANCELLATO!\n");
            system("pause");
            break;
    case '7':system("cls");
            printf("INSERIMENTO ELEMENTO DA CANCELLARE\n");
            scanf("%d",&num4);
            fflush(stdin);
            if(DeleteValue(&testa,num4))
            printf("ELEMENTO: %d CANCELLATO CORRETTTAMENTE  \n",num4);
            else
            printf("VALORE NON PRESENTE NELLA LISTA\n");
            system("pause");
            break;
    case '8':flag3=0;
            break;
            system("pause");
            break;
}
    }
    break;
}
    return 0;
}
