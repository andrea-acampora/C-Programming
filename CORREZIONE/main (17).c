#include <stdio.h>
#include <stdlib.h>

int main()
{
    /* Dichiaro le variabili necessarie e utilizzo l'operatore assegnazione (=)*/
    int varInt = 10;
    float varFloat = 3.14;
    double varDouble = 5.234;
    char varChar = 'c';

    /* Utilizzo operatori matematici unari */
    printf("\n   La variabile intera: %d.", varInt);
    printf("\n   La variabile intera usando l'operatore matematico unario prefisso positivo (++variabile): %d.", ++varInt);
    varInt = 10; //Resetto il valore della variabile
    printf("\n   La variabile intera usando l'operatore matematico unario postfisso positivo (variabile++): %d. \n", varInt++);

    printf("\n   La variabile char: %c.", varChar);
    printf("\n   La variabile char usando l'operatore matematico unario prefisso negativo (--variabile): %c.", --varChar);
    varChar = 'c'; //Resetto il valore della variabile
    printf("\n   La variabile char usando l'operatore matematico unario postfisso negativo (variabile--): %c. \n", varChar--);

    /* Utilizzo operatori matematici binari */
    printf("\n   La prima variabile (float): %f. La seconda variabile (double): %f.", varFloat, varDouble);
    printf("\n   La somma: %f + %f = %f", varFloat, varDouble, varFloat+varDouble);
    printf("\n   La differenza: %f - %f = %f", varFloat, varDouble, varFloat-varDouble);
    printf("\n   Il prodotto: %f * %f = %f", varFloat, varDouble, varFloat*varDouble);
    printf("\n   Il quoziente: %f / %f = %f \n", varFloat, varDouble, varFloat/varDouble);

    varInt = 10;
    printf("\n   Il primo valore (intero): %d. Il secondo valore (intero): %d.", varInt+6, varInt);
    printf("\n   Il modulo/resto: %d %% %d = %d", varInt+6, varInt, ((varInt+6)%varInt));

    return 0;
}
