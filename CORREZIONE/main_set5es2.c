#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>     // includo le librerie necessarie
#define MAX 50

int main()
{
    char str[MAX], *pstr;    //dichiaro la stringa e il puntatore a stringa
    int i=0, len;   //dichiaro la i per i cicli e len per la lunghezza della stringa
    pstr=&str[0];   //unisco il puntatore al primo elemento della stringa

    printf("Inserisci una frase di una canzone di max 50 caratteri, senza numeri: ");
    gets(str);  //chiedo all'utente di inserire la parola e la metto nel vettore

    len = strlen(str);
    if(len>MAX) {
        printf("Parola troppo lunga");  //controllo se la parola è più corta di 50 caratteri
        exit(0);
    }

    for(i=0;i<MAX;i++) {
        if(isdigit(str[i])!=0) {
            printf("Non puoi inserire numeri"); //controllo che l'utente non abbia inserito numeri
            exit(0);
        }
    }

    printf("\nLa frase convertita in stampatello maiuscolo e': ");

    i=0;

    printf("\n");
    for(pstr=str;pstr<str+MAX;pstr++) {  //uso il ciclo for per scorrere il vettore
        switch(*pstr) {
            case (char) 0x85:   //uso lo switch per i casi speciali à, è, ì, ò, ù
                printf("A");
                break;
            case (char) 0x8A:
                printf("E");
                break;
            case (char) 0x8D:
                printf("I");
                break;
            case (char) 0x95:
                printf("O");
                break;
            case (char) 0x97:
                printf("U");
                break;
            default:
                putchar(toupper(*pstr)); //analizzo ogni carattere e stampo il suo relativo maiuscolo col toupper
        }
        if(*pstr=='\0') //il ciclo termina quando si incontra il terminatore di stringa
            break;
    }

    printf("\nLa frase senza spazi e segni di punteggiatura e': ");

    printf("\n");
    for(pstr=str;pstr<str+MAX;pstr++) { //scorro il vettore
        if(isalpha(*pstr)!=0)   //controllo che il carattere sia una lettera con isalpha
            putchar(toupper(*pstr)); //se l'if è vero, stampo la lettera maiuscola
        switch(*pstr) {
            case (char) 0x85:   //uso lo switch per i casi speciali à, è, ì, ò, ù
                printf("A");
                break;
            case (char) 0x8A:
                printf("E");
                break;
            case (char) 0x8D:
                printf("I");
                break;
            case (char) 0x95:
                printf("O");
                break;
            case (char) 0x97:
                printf("U");
                break;
        }
        if(*pstr=='\0') {   //il ciclo termina quando incontra il terminatore di stringa
            printf("\n");
            break;
        }
    }


    system("pause");
    return 0;
}
