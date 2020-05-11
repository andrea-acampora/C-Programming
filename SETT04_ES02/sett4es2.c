#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Esercizio 2 - Settimana 4*/

/*AVVISO AL CORRETTORE!
Il programma da dei warning sui %s nelle funzioni scanf
si potrebbero sostituire con la chiamata alla funzione fgets()
ma il risultato non cambierebbe*/

#define STR_LEN 20  //lunghezza massima parole

int main()
{
    /*----------------------VERSIONE CON SENZA L'USO LIBRERIA STRING.H----------------------*/
    printf("--------VERSIONE SENZA L'USO DELLA LIBRERIA STRING.H--------\n");

    /*DICHIARAZIONE VARIABILI*/
    char parola1[STR_LEN+1];
    char p1[STR_LEN+1];

    /*LETTURA PRIMA PAROLA*/
    printf("Inserisci la prima parola (max20 car.): ");
    scanf("%s", &parola1);

    /*LETTURA SECONDA PAROLA*/
    printf("Inserisci seconda parola (max20 car): ");
    scanf("%s", &p1);

    for(int j=0; parola1[j]!='\0'; j++)
    {
        int k=0;
        /*CONTROLLO I CARATTERI UNO A UNO IN CERCA DI CORRISPONDEZE*/
        if(parola1[j] == p1[k])
        {
            for(k=1; p1[k]!='\0'; k++)
            {
                if(parola1[j+k]==p1[k])   //se sono uguali...
                {
                    parola1[j]='*';  //...sostituisco il primo carattere con un asterisco
                }
                else
                {
                    break;  //esco dal ciclo
                }

            }
        }
    }

    printf("\nLa stringa modificata e': ");
    for(int t=0; parola1[t]!='\0'; t++)
    {
        if(parola1[t]!='*')      //se è una lettera la visualizzo normalmente
            printf("%c", parola1[t]);
        else
        {
            printf("*");    //se invece è un asterisco lo visualizzo
            t=t+strlen(p1)-1;  //e sposto la variabile in modo da non visualizzare i caratteri seguenti
        }
    }

    printf("\n\n");
    system("pause");
    system("cls");

/*-------------------------------------------------------------------------------------------------------------------------------*/
/*----------------------------------------------VERSIONE CON USO LIBRERIA STRING.H-----------------------------------------------*/
/*-------------------------------------------------------------------------------------------------------------------------------*/
    printf("--------VERSIONE CON USO DELLA LIBRERIA STRING.H--------\n");

    /*DICHIARAZIONE VARIABILI*/
    char parola[STR_LEN+1];
    char p[STR_LEN+1];
    char *pOccorrenza;
    int i=0;

    /*LETTURA PRIMA PAROLA*/
    printf("Inserisci la prima parola (max20 car.): ");
    scanf("%s", &parola);

    /*LETTURA SECONDA PAROLA*/
    printf("Inserisci seconda parola (max20 car): ");
    scanf("%s", &p);

    int lungP = strlen(p);  //lunghezza della prima parola

    do{
        /*RICERCA CORRISPONDENZA DELLA SECONDA NELLA PRIMA*/
        pOccorrenza = strstr(parola, p);    //mi restituisce in puntatore alla prima occorrenza della seconda parola

        /*SOSTITUZIONE DELLA SECONDA NELLA PRIMA CON * */
        for(int j=0; j<lungP; j++)
        {
            strncpy(pOccorrenza+j, "*", 1); //sostituisco tutti i caratteri della parola con *
        }
    }while(strstr(parola, p) != NULL);  //continuo finchè non trovo più corrispondenze

    /*VISUALIZZAZIONE PRIMA PAROLA MODIFICATA IN OUTPUT*/
    printf("\nLa stringa modificata e': ");
    do
    {
        if(parola[i]=='*')  //se incontro un asterisco..
        {
            printf("*");    //visualizzo solo un asterisco
            i=i+lungP-1;    //salto gli altri incrementando la variabile
        }
        else{
            printf("%c", parola[i]);    //altrimenti visualizzo normalmente
        }

        i++;    //incremento la variabile

    }while(parola[i] != '\0');  //continuo finchè non finisce la parola (trovo il terminatore di stringa \0)



    /*FINE PROGRAMMA*/
    printf("\n\n");
    system("pause");
    return 0;
}
