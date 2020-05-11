#include <stdio.h>
#include <stdlib.h>

//Esercizio 2 Settimana 1
int main()
{
    int op1=4, ris;
    char op2=8;
    float op3=2.0004, ris2;
    double op4=458.9270;
    printf("Valore variabile int: %d",op1);
    printf("\n Valore variabile char: %d", op2);
    printf("\n Valore variabile float: %f", op3);
    printf("\n Valore variabile double: %f", op4);

    ris=op2-op1;
    printf("\n Il risultato di %d-%d e': %d", op2, op1, ris); //uso sottrazione
    ris=op1+op2;
    printf("\n Il risultato di %d+%d e': %d", op1, op2, ris); //uso addizione
    ris2=op3*op4;
    printf("\n Il risultato di %f*%f e': %f", op3, op4, ris2); //uso moltiplicazione
    printf("\n Uso operatori matematici unari partendo da 4 e 8: \n %d %d", op1, op2, op1--, --op2);
    printf("\n %d, %d", op1++, ++op2);
    printf("\n %d, %d", ++op1, ++op2);
    printf("\n %d, %d", --op1, --op2);
    ris2=op4/op3;
    printf("\n Il risultato di %f:%f e': %f", op4, op3, ris2); //uso divisione
    printf("\n Risultato int+=char: %d", op1+=op2); //utilizzo op1+=op2
    printf("\n Risultato int=int-char: %d", op1-=op2); //utilizo op1-=op2
    printf("\n Risultato int=(int*char) :  %d", op1*=op2); //utilizzo op1*=op2
    printf("\n Risultato int=int:char : %d", op1/=op2); //utilizzo op1/=op2
    printf("\n Risultato int=int%char) : %d", op1%=op2); //utilizzo op1%=op2
    return 0;
}
