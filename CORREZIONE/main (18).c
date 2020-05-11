//Esercizio 1 settimana 1

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>

int main()
 {
     char varChar = 'm';
     int varInt = 10, valorePrint;
     short int s_int = 1;
     long int l_int = 100;
     long long ll_int = 1000;
     unsigned char u_char = 'a';
     unsigned int u_int = 50;
     unsigned short us_int = 5;
     unsigned long ul_int = 500;
     unsigned long long ull_int = 5000;
     float varFloat = 2.71828182845904523536;
     double varDouble = 2.71828182845904523536;
     long double l_double = 2.71828182845904523536;

     //Prima parte
     //Variabili, Valore in byte, Max, Min e valore printf

     printf("//Variabili\n\n");
     valorePrint = printf("Char\tvalore=%c byte=%d max=%d min=%d\n", varChar, sizeof(varChar), CHAR_MAX, CHAR_MIN);
     printf("Valore printf = %d\n\n", valorePrint);

     valorePrint = printf("Int\tvalore=%d byte=%d max=%d min=%d\n", varInt, sizeof(varInt), INT_MAX, INT_MIN);
     printf("Valore printf = %d\n\n", valorePrint);

     valorePrint = printf("Short\tvalore=%d byte=%d max=%d min=%d\n", s_int, sizeof(s_int), SHRT_MAX, SHRT_MIN);
     printf("Valore printf = %d\n\n", valorePrint);

     valorePrint = printf("long\tvalore=%ld byte=%d max=%ld min=%ld\n", l_int, sizeof(l_int), LONG_MAX, LONG_MIN);
     printf("Valore printf = %d\n\n", valorePrint);

     valorePrint = printf("long long\tvalore=%lld byte=%d max=%lld min=%lld\n", ll_int, sizeof(ll_int), LONG_LONG_MAX, LONG_LONG_MIN);
     printf("Valore printf = %d\n\n", valorePrint);

     valorePrint = printf("unsigned char\tvalore=%c byte=%d max=%d min=0\n", u_char, sizeof(u_char), UCHAR_MAX);
     printf("Valore printf = %d\n\n", valorePrint);

     valorePrint = printf("unsigned int\tvalore=%d byte=%d max=%u min=0\n", u_int, sizeof(u_int), UINT_MAX);
     printf("Valore printf = %d\n\n", valorePrint);

     valorePrint = printf("unsigned short\tvalore=%d byte=%d max=%u min=0\n", us_int, sizeof(us_int), USHRT_MAX);
     printf("Valore printf = %d\n\n", valorePrint);

     valorePrint = printf("unsigned long\tvalore=%d byte=%d max=%lu min=0\n", ul_int, sizeof(ul_int), ULONG_MAX);
     printf("Valore printf = %d\n\n", valorePrint);

     valorePrint = printf("unsigned long long\tvalore=%llu byte=%d max=%llu min = 0\n", ull_int, sizeof(ull_int), ULONG_LONG_MAX);
     printf("Valore printf = %d\n\n", valorePrint);

     valorePrint = printf("float\tvalore=%f byte=%d max=%e min=%e\n", varFloat, sizeof(varFloat), FLT_MAX, FLT_MIN);
     printf("Valore printf = %d\n\n", valorePrint);

     valorePrint = printf("double\tvalore=%lE byte=%d max=%e min=%e\n", varDouble, sizeof(varDouble), DBL_MAX, DBL_MIN);
     printf("Valore printf = %d\n\n", valorePrint);

     valorePrint = printf("long double\tvalore=%llg byte=%d max=%llg min=%llg\n", l_double, sizeof(long double), LDBL_MAX, LDBL_MIN); //consapevole dell'errore provocato dal mingw
     printf("Valore printf = %d\n\n\n\n", valorePrint);


     //Seconda parte

     int anni = 19;
     char stringa [30]= "parole a caso";
     double precisione = 52.321;
     double pigreco = 3.141592653589793;

     //Varianti modificatore
     printf("//modificatore\n\n");
     printf("|%3d|\n", anni);
     printf("|%-3d|\n", anni);
     printf("|%+3d|\n", anni);
     printf("|% d|\n", anni);
     printf("|%04d|\n", anni);
     printf("|%#x|\n\n\n", anni);

     //Varianti campoMinimo e precisione
     printf("//campoMinimo e precisione\n\n", anni);
     printf("|%6d|\n", anni);
     printf("|%.2lf|\n", pigreco);
     printf("|%7.2lf|\n", pigreco);
     printf("|%4.5lf|\n", pigreco);
     printf("|%07.3lf|\n\n\n", pigreco);

     //Varianti modificatoreLunghezza
     printf("//modificatoreLunghezza\n\n", u_char);
     printf("|%hc|\n", u_char);
     printf("|%hd|\n", us_int);
     printf("|%ld|\n", ul_int);
     printf("|%lld|\n\n\n", ull_int);

     //Varianti specificaConversione
     printf("//specificaConversione mancanti\n\n");
     printf("Intero = %d\tIntero in notazione ottale = %o\n\n", varInt, varInt);
     printf("Intero = %d\tIntero in notazione esadeciamle = %x\n\n", anni, anni);
     printf("Stampa strnga = %s\n\n", stringa);

     //Fine programma


     system("pause");
     printf("\a");

     return 0;
 }
