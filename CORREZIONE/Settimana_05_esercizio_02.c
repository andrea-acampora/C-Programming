//Settimana 05 esercizio 02

/*
    Scrivere un programma C che:
    (a) Chieda all'utente di digitare una frase di una canzone in italiano in cui siano presenti
        solo lettere, spazi e segni di punteggiatura
        (non devono quindi essere presenti numeri, ma possono essere presenti le seguenti 5 vocali accentate: à, è, ì, ò, ù);
    (b) La visualizzi convertendo tutte le lettere in stampatello maiuscolo;
    (c) A seguito rimuova tutti gli spazi e i segni di punteggiatura;
    (d) Ri-visualizzi la frase a monitor.
    Tutte le operazioni devono essere fatte usando puntatori, in pratica accedendo alla frase in modo indiretto.
*/

//Direttive del preprocessore
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

/*
    Dichiarazione variaibili:
    str è la frase da inserire,
    ptr è il puntatore alla stringa,
    verifica è la classica variabile di controllo dell'input.
*/
unsigned char str[100];
unsigned char *ptr;
short verifica=0;


int main(){

    //Per fugare ogni possibile dubbio, inizializzo l'ultimo carattere della stringa assegnando il carattere terminatore
    str[99]='\0';

    /*
        Inizializzo il puntatore facendolo puntare al primo elemento della stringa.
        Di seguito non modificherò più l'indirizzo a cui punta il puntatore, ma lo utilizzerò semplicemente aggiungendo un valore intero.
    */
    ptr=&str[0];

    /*
        Fase di input :
        con la funzione gets prendo in input tutti i caratteri inseriti fino a che non viene premuto INVIO,
        tramite il ciclo for, controllo carattere per carattere che non siano stati inseriti numeri o caratteri speciali come questo $.
    */
    do{
        if(verifica) printf("\nNon hai inserito una stringa corretta!\n");
        verifica=0;
        printf("Inserire una frase di massimo 100 caratteri :\n");
        gets(str);
        for(int i=0; i<100; i++){
            if(*(ptr+i)!='\0'){
                if(isdigit(*(ptr+i))!=0 || (isalpha(*(ptr+i))==0 && ispunct(*(ptr+i))==0 && isspace(*(ptr+i))==0 && *(ptr+i)!=130 && *(ptr+i)>=160 && *(ptr+i)<=163)){
                    verifica=1;
                    break;
                }
            }
        }
    }while(verifica==1);


    //Salvo la lunghezza della stringa in una variabile per evitare di richiamare la funzione strlen ogni vlta che serve.
    int strLEN=strlen(str);

    //FASE DI OUTPUT
    //Prima parte

    printf("\n\n\n");

    printf("Fase 1 : visualizzare la frase convertendo tutte le lettere in maiuscolo.\n");
    //Con questo ciclo controllo la stringa carattere per carattere
    for(int i=0; i<strLEN+1; i++){

        //Se il carattere in posizione *(ptr+i) è una lettera minuscola la stampa maiuscola
        if(islower(*(ptr+i))) printf("%c",toupper(*(ptr+i)));

        //Se è una lettera maiuscola la stampa tale e quale
        else if(isupper(*(ptr+i))) printf("%c",*(ptr+i));

        //Se è uno spazio bianco o una tabulazione stampa uno spazio bianco
        if(isblank(*(ptr+i))) printf(" ");

        //Se è un segno di punteggiatura lo stampa tale e quale
        if(ispunct(*(ptr+i))) printf("%c",*(ptr+i));

        /*
            Qui controllo le lettere accentate.
            Sul mio pc utilizzo Windows 10 e con queste condizioni il programma funziona riconoscendo correttamente le lettere accentate.
            I numeri indicati corrispondono alla codifica ASCII sulla mia macchina delle lettere accentate.
        */
        if(*(ptr+i)==138) printf("E'");
        else if(*(ptr+i)==133) printf("A'");
        else if(*(ptr+i)==141) printf("I'");
        else if(*(ptr+i)==149) printf("O'");
        else if(*(ptr+i)==151) printf("U'");
    }

    printf("\n\n\n");

    //FASE DI OUTPUT
    //Seconda parte

    printf("Fase 2 : visualizzare la frase convertita in maiuscolo senza segno di punteggiatura e spazi.\n");
    //Il ciclo seguente ha le stesse identiche condizioni del ciclo della prima parte senza però i controlli per spazi bianchi e segni di punteggiatura.
    for(int i=0; i<strLEN+1; i++){

        if(islower(*(ptr+i))) printf("%c",toupper(*(ptr+i)));

        else if(isupper(*(ptr+i))) printf("%c",*(ptr+i));

        if(*(ptr+i)==138) printf("E'");
        else if(*(ptr+i)==133) printf("A'");
        else if(*(ptr+i)==141) printf("I'");
        else if(*(ptr+i)==149) printf("O'");
        else if(*(ptr+i)==151) printf("U'");
    }

    printf("\n\n\n");
    system("pause");
    exit(0);
    return 0;
}
