#include <stdio.h>
#include <stdlib.h>

int main()
{
/*inserimento variabili*/

    char a = 1;
    int b = 2;
    float c = 2.22;
    double d = 24.2662;

/*valori variabili*/

    printf("valore a = %d\n", a);
    printf("valore b = %d\n", b);
    printf("valore c = %g\n", c);
    printf("valore d = %g\n\n\n", d);

/*operatore somma*/

    int somma = a + b;
    printf("risultato a + b = %10d + %-10d = %10d\n",a,b,somma);

/*operatore sottrazione*/


    float sottrazione = b - c;
    printf("risultato b - c = %10d - %-10g = %10g\n",b,c,sottrazione);

/*operatore moltiplicazione*/


    double moltiplicazione = a * d;
    printf("risultato a * d = %10d * %-10g = %10g\n",a,d,moltiplicazione);


/*operatore divisione*/


    float divisione = b / c;
    printf("risultato b : c = %10d : %-10g = %10g\n",b,c,divisione);

/* operatore modulo
problemi fra variabili di tipo diverso*/

    int modulo = a % b;
    printf("risultato a modulo b = %5d modulo %-5d = %10d\n\n\n",a,b,modulo);


/*operatore incremento*/

    printf("a++ = %-5d\n", a++);
    printf("++b = %-5d\n", ++b);

/*operatore decremento*/

    printf("c-- = %-5g\n", c--);
    printf("--d = %-5g\n\n",--d);

/*operatore per invertire il segno */

    printf("-a = %-5d\n", -a);
    printf("-c = %-5g\n\n\n", -c);

/*operatore per assegna alla variabile il valore alla destra*/

    c = d;
    printf("c = d =%8g\n\n\n", c);

/*operatori,
l'utilizzo di variabili di diverso tipo causa problemi di calcolo*/

    a +=b;
    printf("a = (a + b) = %d\n", a);
    a -=b;
    printf("a = (a - b) = %d\n", a);
    a *=b;
    printf("a = (a * b) = %d\n", a);
    c /=d;
    printf("c = (c / d) = %g\n", c);
    a %=b;
    printf("a = (a modulo b) = %d\n\n\n", a);

    printf("%d == %d = %d\n", a, b, a == b);
    printf("%d != %d = %d\n", a, b, a != b);
    printf("%d > %d = %d\n", a, b, a > b);
    printf("%d < %d = %d\n\n\n", a, b, a < b);

/*nuovi valori delle variabili*/

    printf("nuovo valore a= %d\n", a);
    printf("nuovo valore b= %d\n", b);
    printf("nuovo valore c= %g\n", c);
    printf("nuovo valore d= %g\n", d);
    return 0;
}
