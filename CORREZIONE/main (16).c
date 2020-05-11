#include <stdio.h>
#include <stdlib.h>

int main()
{

    /* Partendo dalla dichiarazione di quattro variabili, una variabile int, una float, una double, e una char */

    int varInt = 8;
    float varFloat = 4.34;
    double varDouble = 64.56;
    char varChar = 41;

    /* Stampo i valori delle variabili usate prima l’applicazione */

    printf("Valore iniziale della variabile di tipo Int:     %d\n", varInt);
    printf("Valore iniziale della variabile di tipo Float:   %.2f\n", varFloat);
    printf("Valore iniziale della variabile di tipo Double:  %.2f\n", varDouble);
    printf("Valore iniziale della variabile di tipo Char:    %d\n\n", varChar);

    /* Uso tutti gli operatori studiati */

    printf("Assegno un valore alla variabile di tipo Int: %d\n\n", varInt = 98);

    printf("Eseguo operazioni aritmetiche tra le variabili:\n");
    printf("%d + %.2f = %.2f\n", varInt, varFloat, varInt + varFloat);
    printf("%d - %.2f = %.2f\n", varInt, varFloat, varInt - varFloat);
    printf("%d * %.2f = %.2f\n", varInt, varFloat, varInt * varFloat);
    printf("%d / %.2f = %.2f\n\n", varInt, varFloat, varInt / varFloat);

    printf("Sommo alla variabile Float, quella di tipo Int. Assegno il risultato ottenuto alla variabile Float:\n");
    printf("%.2f + %d = %.2f\n", varFloat, varInt, varFloat += varInt);
    printf("Sottraggo alla variabile Float, quella di tipo Int. Assegno il risultato ottenuto alla variabile Float:\n");
    printf("%.2f - %d = %.2f\n", varFloat, varInt, varFloat -= varInt);
    printf("Moltiplico la variabile Float peer quella di tipo Int. Assegno il risultato ottenuto alla variabile Float:\n");
    printf("%.2f x %d = %.2f\n", varFloat, varInt, varFloat *= varInt);
    printf("Divido la variabile Float per quella ti tipo Int. Assegno il risultato ottenuto alla variabile Float:\n");
    printf("%.2f / %d = %.2f\n\n", varFloat, varInt, varFloat /= varInt);

    printf("Visualizzo il resto della divisione della variabile Int per un numero intero:\n");
    printf("%d / %d = %d resto: %d\n\n", varInt, 3, varInt / 3, varInt % 3);

    printf("Aumento di un' unita' la variabile di tipo Int: %d\n", ++varInt);
    printf("Aumento di un' unita' la variabile di tipo Int dopo averla utilizzata: %d, %d\n", varInt++, varInt);
    printf("Diminuisco di un' unita' la variabile di tipo Int: %d\n", --varInt);
    printf("Diminuisco di un' unita' la variabile di tipo Int dopo averla utilizzata: %d, %d\n\n", varInt--, varInt);

    /* Stamparo i valori delle variabili usate dopo l’applicazione */

    printf("Valore finale della variabile di tipo Int:     %d\n", varInt);
    printf("Valore finale della variabile di tipo Float:   %.2f\n", varFloat);
    printf("Valore finale della variabile di tipo Double:  %.2f\n", varDouble);
    printf("Valore finale della variabile di tipo Char:    %d\n\n", varChar);

    system("pause");

    return 0;
}
