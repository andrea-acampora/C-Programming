#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    //dichiaro le variabili
    char parola1[31];
    char parola2[31];
    int lung_stringa1, lung_stringa2;
    int contenuto;
    int i,j;

    //inserisco le parole e calcolo la lunghezza
    printf ("Inserisci una parola: ");
    gets(parola1);
    lung_stringa1 = strlen(parola1);
    printf("La parola %s contiene %d lettere\n", parola1, lung_stringa1);
    printf ("Inserisci una parola: ");
    gets(parola2);
    lung_stringa2 = strlen(parola2);
    printf("La parola %s contiene %d lettere\n", parola2, lung_stringa2);

    //controllo la lunghezza
    if(lung_stringa1<lung_stringa2)
    {
        printf("La seconda parola e' piu' lunga della prima parola \n");
    }
    else
    {
        for (i=0; i+(lung_stringa2-1)<lung_stringa1; i++)
        {
            contenuto=1;//utilizzo contenuto per controllare che le due parole siano uguali e funge da flag per verificare la presenza
            for ( j=0; j<lung_stringa2 && contenuto==1; j++)//utilizzo j e i per i cicli di entrambi i vettore*/
            {
                if (parola1[i+j]!=parola2[j])
                    contenuto=0;
                }
                if(contenuto==1)
                {
                    for(j=0; j<lung_stringa2; j++)
                    parola1[i+j]='*';
                    i=i+lung_stringa2-1;
                }
            }
    }

    //stampo il risultato
    printf("La parola risultante e' %s \n", parola1);
    system("pause");
    return 0;

}
