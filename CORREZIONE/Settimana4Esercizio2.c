#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* Settimana4 Esercizio2*/
/*compilatore Xcode e CodeBlocks su OSX Mojave
 error: 0
 warnings: 0*/

int main(int argc, char const *argv[])
{
    /* dichiarazione variabili gli array contengono 30 elementi effettivi più \0 */
    char primaParola[31];
    char parola[31];
    char secondaParola[31];
    int controllo;
    int pos = 0;
    int lunghezza = 0;
    int lunghezzaPrima = 0;

    do
    {
        do
        {
            printf("inserire la prima parola, massimo 30 caratteri se superiore verranno considerati i primi 30 non si accettano spazi\n");
            controllo = scanf("%30s", primaParola); /* inserimento prima parola */
            char c;
            while ((c = getchar()) != EOF && c != '\n') /* pulizia buffer fflush(stdio) non funziona su OSX */
                continue;
            if (!controllo) /* se errata mostra il messaggio */
            {
                printf("devi inserire una parola\n"); /* se errata fa reinserire con un ciclo */
            }
        } while (!controllo);
        do
        {
            printf("inserire la seconda parola, massimo 30 caratteri se superiore verranno considerati i primi 30 non si accettano spazi\n");
            controllo = scanf("%30s", secondaParola); /* inserimento seconda parola */
            char c;
            while ((c = getchar()) != EOF && c != '\n') /* pulizia buffer fflush(stdio) non funziona su OSX */
                continue;
            if (!controllo) /* se errata mostra il messaggio */
            {
                printf("devi inserire una parola\n");
            }
        } while (!controllo);                    /* se errata fa reinserire con un ciclo */
        while (secondaParola[lunghezza] != '\0') /* calcola la lunghezza della seconda parola */
        {
            lunghezza++;
        }
        while (primaParola[lunghezzaPrima] != '\0') /* calcola la lunghezza della prima parola */
        {
            lunghezzaPrima++;
        }
    } while (lunghezzaPrima <= lunghezza);           /* fa reinserire se la seconda parola  e' maggiore della prima */
    strcpy(parola, primaParola);                     /* la la prima parola per il secondo modo di esecuzione */
    pos = 0;                                         /* azzero la posizione */
    while (primaParola[pos + lunghezza - 1] != '\0') /* ciclo da eseguire fino alla fine della stringa */
    {
        if (primaParola[pos] == secondaParola[0]) /* se la prima lettera della seconda corrisponde ad una della prima */
        {
            int uguale = 1;
            for (int i = 0; i < lunghezza; i++) /* controlla siano presenti tutte le lettera della seconda nella prima */
            {
                uguale = (primaParola[pos + i] == secondaParola[i]) && uguale;
            }
            if (uguale) /* se corrispondono tutte */
            {
                primaParola[pos] = '*'; /* sostituisce la prima con * */
                int i;
                for (i = 1; primaParola[pos + i + lunghezza - 1] != '\0'; i++) /* trasla tutte le seccesssive a quelle corrispondenti in modo da cancellare le altre */
                {
                    primaParola[pos + i] = primaParola[pos + i + lunghezza - 1];
                }
                primaParola[pos + i] = '\0'; /* aggiunge il trerminarore */
            }
        }
        pos++; /* possa alla lettera successiva */
    }
    printf("la stringa ottenuta con il metedo senza l'uso della libreria <string.h> e':\n%s\n", primaParola); /* stampa la parola */
    pos = 0;                                                                                                  /* azzera la posizione */
    lunghezza = (int)strlen(secondaParola);                                                                   /* calcola la lunghezza della seconda parola */
    char *c;
    while ((c = strstr(parola, secondaParola), c != NULL)) /* se la seconda parola e' contenuta nella prima ritorna l'indirizzo di dove inizia e lo mette in c */
    {
        pos = (int)(c - parola); /* calcola l'indice dell'elemeto di dove inzia la corrispondenza */
        char p[31];
        parola[pos] = '*';                   /* sostituisco al prima con * */
        strcpy(p, &parola[pos + lunghezza]); /* copio il resto della stringa dopo la corrispondenza in una variabile d'appoggio */
        strcpy(&parola[pos + 1], p);         /* copio la stringa nella variabil ed'appoggio dopo il carattere * */
    }
    printf("a stringa ottenuta con il metedo con l'uso della libreria <string.h> e':\n%s\n", parola); /* stampo la stringa */
    getchar();                                                                                        /* aspetto un carattere */
    return 0;
}
