#include <stdio.h>
#include <stdlib.h>


int main()
{
    int a,b,somma;

    printf("\t\t\t OPERATORI MATEMATICI:\n");

    //SOMMA
    printf("SOMMA DI DUE OPERANDI\n");
    a=10;
    b=16;
    somma=0;
    printf("i due operandi valgono: %d, %d\n", a, b);
    somma=a+b;
    printf("il risultato di %d + %d e\' %d.\n", a, b, somma);
    printf("\n\n\n");

    //SOTTRAZIONNE
    printf("SOTTRAZIONE DI DUE OPERANDI\n");
    int c,d,risultato;
    c=300;
    d=120;
    risultato=0;
    printf("i due operandi valgono: %d, %d.\n", c, d);
    risultato=c-d;
    printf("il risultato di %d - %d e\' %d.\n", c, d, risultato);
    printf("\n\n\n");

    //MOLTIPLICAZIONE
    printf("MOLTIPLICAZIONE DI DUE OPERANDI\n");
    long int e,f,rismolt;
    e=20;
    f=400;
    rismolt=0;
    printf("i due operandi valgono: %d, %d.\n", e, f);
    rismolt=e*f;
    printf("il risultato di %ld * %ld e\' %ld.\n", e, f, rismolt);
    printf("\n\n\n");

    //DIVISIONE
    printf("DIVISIONE DI DUE OPERANDI\n");
    float g, h, divis;
    g=92;
    h=3;
    divis=0;
    printf("i due operandi valgono; %f, %f.\n", g , h);
    divis=g/h;
    printf("il risultato di %f : %f e\' %f.\n", g, h, divis);
    printf("\n\n\n");

    //RESTO
    printf("RESTO DI UNA DIVISIONE\n");
    int x, y, r;
    x=56;
    y=41;
    r=0;
    printf("i due operandi valgono: %d, %d.\n", x, y);
    r=x%y;
    printf("il resto della divisione %d : %d e\' pari a: %d.\n", x, y, r);
    printf("\n\n\n");

    //OPERATORI UNARI
     printf("\t\t\t OPERATORI UNARI:\n");
     int k, j;

     k=10;
     j=10;
     printf("entrambe le variabili sono state inizializzare con il valore 10.\n");

     printf("INCREMETO:\n");
     printf("POSTFISSI \t\t PREFISSI\n");
     printf("%d \t\t\t%d\n", k++, ++j);
     printf("%d \t\t\t%d\n", k++, ++j);
     printf("%d \t\t\t%d\n", k++, ++j);
     printf("%d \t\t\t%d\n", k++, ++j);
     printf("%d \t\t\t%d\n", k++, ++j);
     printf("%d \t\t\t%d\n\n\n", k++, ++j);

     k=10;
     j=10;

     printf("DECREMENTO:\n");
     printf("POSTFISSI \t\t PREFISSI\n");
     printf("%d \t\t\t%d\n", k--, --j);
     printf("%d \t\t\t%d\n", k--, --j);
     printf("%d \t\t\t%d\n", k--, --j);
     printf("%d \t\t\t%d\n", k--, --j);
     printf("%d \t\t\t%d\n", k--, --j);
     printf("%d \t\t\t%d\n", k--, --j);
     printf("\n\n\n");

     //OPERATORI COMPATTI
     printf("\t\t\t OPERATORI COMPATTI:\n\n");
     int t, v, l;
     t=60;
     v=20;
     l=8;
     printf("gli operandi sono stati inizializzari con i valori %d e %d\n", t, v);
     printf("dopo che viene eseguita un'operazione gli operandi riassumono il loro valore iniziale.\n\n");

     printf("MOLTIPLICAZIONE:\n");
     t-=v*l;
     printf("dopo aver moltiplicato, sottratto e trasferito il risultato nella variabile 't' essa vale: %d.\n", t);
     printf("\n\n\n");

     printf("DIVISIONE:\n");
     t=60;
     v=20;
     t/=v;
     printf("dopo aver diviso e trasferito il risultato nella variabile 't' essa vale: %d.\n", t);
     printf("\n\n\n");

     printf("RESTO:\n");
     t=60;
     v=20;
     t%=v;
     printf("dopo aver diviso e trasferito il resto della divisione nella variabile 't' essa vale: %d.\n", t);
     printf("\n\n\n");







    return 0;
}
