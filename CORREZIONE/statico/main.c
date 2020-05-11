#include <stdio.h>
#include <stdlib.h>
#include "MyLibrary.h"
#define MAXVET 200

int main()
{
    char scelta=0;
    int verificaInt;//verifica inserimento interi
    int flag;
    int vettore[MAXVET];//vettore
    int numero;
    int i;
    int aggiunti=0;//conta il numero di elementi aggiunti al vettore
    int elemento;//elemento dopo il quale aggiungere il numero
    //ciclo per azzerare il vettore
    for (i=0;i<MAXVET;i++)
    {
        vettore[i]=0;
    }

    flag=1;
    while(flag)
    {
        StampaLista(vettore,MAXVET);//funzione che stampa il vettore ogni volta che si torna al menù
        printf("\n\n");
        puts("----------------------------------------");
        printf("Selezionare l'operazione che vuole eseguire:\n");
        printf("|1|Inserisci in testa;\n");
        printf("|2|Inserisci in coda;\n");
        printf("|3|Inserisci dopo un certo elemento;\n");
        printf("|4|Cancella dalla testa;\n");
        printf("|5|Cancella dalla coda;\n");
        printf("|6|Cancella la prima occorrenza dell'elemento;\n");
        printf("|7|Chiudere il programma;\n");

        printf("\nQuale operazione vuole eseguire:");//scelta operazione da eseguire
        scanf("%c",&scelta);
        fflush(stdin);
        while (scelta!='1'&&scelta!='2'&&scelta!='3'&&scelta!='4'&&scelta!='5'&&scelta!='6'&&scelta!='7')//ciclo per verificare corretto inserimento
        {
            printf("Quale operazione vuole eseguire:");
            scanf("%c",&scelta);
            fflush(stdin);
        }
        switch(scelta)
            {
                case '1'://inserimento in testa al vettore
                    system("cls");//azzera la schermata
                    puts("-----------INSERIMENTO IN TESTA-----------");
                    printf("\n\nInserisci il valore intero da inserire nella lista: ");
                    verificaInt=scanf("%d",&numero);//verifica corretto inserimento del numero che si vuole aggiungere
                    fflush(stdin);
                    while(verificaInt!=1)
                    {
                        printf("\nInserisci il valore intero da inserire nella lista: ");
                        verificaInt=scanf("%d",&numero);
                        fflush(stdin);
                    }
                    InserisciInTesta(vettore,MAXVET,numero,aggiunti);//funzione di inserimento in testa
                    aggiunti++;
                    system("pause");
                    system("cls");
                    break;
                case '2'://inserimento in coda
                    system("cls");
                    puts("-----------INSERIMENTO IN CODA-----------");
                    printf("\n\nInserisci il valore intero da inserire nella lista: ");
                    verificaInt=scanf("%d",&numero);//verifica corretto inserimento del numero che si vuole aggiungere
                    fflush(stdin);
                    while(verificaInt!=1)
                    {
                        printf("\nInserisci il valore intero da inserire nella lista: ");
                        verificaInt=scanf("%d",&numero);
                        fflush(stdin);
                    }
                    InserisciInCoda(vettore,MAXVET,numero,aggiunti);//funzione di inserimento in coda
                    aggiunti++;
                    system("pause");
                    system("cls");
                    break;
                case '3'://inserimento dopo un cero elemento
                    system("cls");
                    puts("-----------INSERIMENTO DOPO UN CERTO ELEMENTO----------");
                    printf("\n\nInserisci il valore intero da inserire nella lista: ");
                    verificaInt=scanf("%d",&numero);//verifica corretto inserimento del numero che si vuole aggiungere
                    fflush(stdin);
                    while(verificaInt!=1)
                    {
                        printf("\nInserisci il valore intero da inserire nella lista: ");
                        verificaInt=scanf("%d",&numero);
                        fflush(stdin);
                    }
                    printf("\n\nDopo che elemento lo vuoi inserire?");//richiesta del valore dopo il quale si vuole aggiungere l'elemento con verifica
                    verificaInt=scanf("%d",&elemento);
                    while(verificaInt!=1)
                    {
                        printf("\nDopo che elemento lo vuoi inserire?");
                        verificaInt=scanf("%d",&numero);
                        fflush(stdin);
                    }
                    InserisciDopoElemento(vettore,MAXVET,numero,elemento);//funzione di inserzione dopo un certo elemento
                    system("pause");
                    system("cls");
                    break;
                case '4'://cancella elemento in testa
                    system("cls");
                    puts("-----------CANCELLA DALLA TESTA-----------");
                    CancellaDallaTesta(vettore,MAXVET);//funzione di cancellazione dell'elemento in testa
                    aggiunti--;
                    system("pause");
                    system("cls");
                    break;
                case '5'://cancella elemento in coda
                    system("cls");
                    puts("-----------CANCELLA DALLA CODA-----------");
                    CancellaDallaCoda(vettore,MAXVET);//funzione di cancellazione dell'elemento in coda
                    aggiunti--;
                    system("pause");
                    system("cls");
                    break;
                case '6'://cancella elemento alla prima occorrenza
                    system("cls");
                    puts("-----------CANCELLA LA PRIMA OCCORRENZA DELL' ELEMENTO----------");
                    printf("\n\nInserisci il valore intero da cancellare nella lista: ");
                    verificaInt=scanf("%d",&numero);
                    fflush(stdin);
                    while(verificaInt!=1)
                    {
                        printf("\nInserisci il valore intero da cancellare nella lista: ");
                        verificaInt=scanf("%d",&numero);
                        fflush(stdin);
                    }
                    if(aggiunti!=0)
                    {
                        aggiunti--;
                    }
                    CancellaOccorrenza(vettore,MAXVET,numero);//funzione di cancellazione dell'elemento alla prima occorrenza
                    system("pause");
                    system("cls");
                    break;
                case '7'://chiusura del programma
                    system("cls");
                    printf("\nChiusura del programma in corso...\n");
                    flag=0;
                    break;
            }
    }
    return 0;
}
