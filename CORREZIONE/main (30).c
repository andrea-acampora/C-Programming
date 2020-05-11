/**
 * ESERCIZIO 2 - SETTIMANA 5
 * Scrivere un programma C che:
 * (a) Chieda all'utente di digitare una frase di una canzone in italiano in cui
 * siano presenti solo lettere, spazi e segni di punteggiatura (non devono quindi essere presenti numeri,
 * ma possono essere presenti le seguenti 5 vocali accentate: à, è, ì, ò, ù);
 * (b) La visualizzi convertendo tutte le lettere in stampatello maiuscolo;
 * (c) A seguito rimuova tutti gli spazi e i segni di punteggiatura;
 * (d) Ri-visualizzi la frase a monitor.
 * Tutte le operazioni devono essere fatte usando puntatori, in pratica accedendo alla frase in modo indiretto.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define ARRAY_SIZE 100 //dimensione massima dell'array

int main()
{
    char *pFrase, frase[ARRAY_SIZE];
    int offset=0, i=0, temp=0;  //offset= numero di indirizzi da scorrere

    printf("Inserisci la frase della canzone: ");
    gets(frase);

    pFrase = frase; //inizializzo puntatore al primo indirizzo di frase[]

    //ciclo per controllare se sono presenti numeri nella frase
    while(*(pFrase+offset)!='\0'){
        if(*(pFrase+offset)>47 && *(pFrase+offset)<58){
            printf("Non sono ammessi numeri!\n Reiscerisci la frase in modo corretto: ");
            gets(frase);
        }
        offset++;
    }

    pFrase = frase;

    //trasformo tutte le lettere in maiuscolo
    for(offset=0;*(pFrase+offset)!='\0';offset++){
        *(pFrase+offset)=toupper(*(pFrase+offset));
        switch(*(pFrase+offset)){
            case '\x8A':    //è maiuscola
                 *(pFrase+offset)='\xD4';
                 break;
            case '\x85':    //à maiuscola
                 *(pFrase+offset)='\xB7';
                 break;
            case '\x8D':    //ì maiuscola
                *(pFrase+offset)='\xD6';
                break;
            case '\x95':    //ò maiuscola
                *(pFrase+offset)='\xE3';
                break;
            case '\x97':    //ù maiucola
                 *(pFrase+offset)='\xEB';
                 break;
        }
    }

    //elimino gli spazi e i segni di punteggiatura
    for(offset=0;*(pFrase+offset)!='\0';offset++){
        if(isspace(*(pFrase+offset)) || (*(pFrase+offset)>32 && *(pFrase+offset)<65)){
            temp = offset;
            *(pFrase+offset) = *(pFrase+(offset));
            while(*(pFrase+offset+i)!='\0' || (*(pFrase+offset+i)>32 && *(pFrase+offset+i)<65)){ //ciclo perfar slittare le posizioni indietro di 1
                *(pFrase+offset) = *(pFrase+offset+1);
                    offset++;
            }
            offset = temp;
            offset--;
        }

    }

    //ri-visualizzazione frase a monitor
    puts(pFrase);
    return 0;
}
