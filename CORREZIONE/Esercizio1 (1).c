/*

Consegna esercizio N.1 Davide Accetturi  @2018

*/

//#include <stdafx.h> //questa libreria è inclusa in quanto utilizzo visual studio come IDE in caso di altri compilatore/editor commentarla.
#include <stdio.h>
#include <limits.h>
#include <float.h>


int main()
{
	//dichiaro tutte le variabili di ogni tipo: chat,int,float,double || usando i prefissi: long,short,signed,unsigned

	int intero = 90;
	float decimale = 10.56;
	char carattere = 'a';
	double reale_doppio = 10.54653234;
	short int interoshort = 144;
	long int interolong = 1314241;
	long unsigned int lungointerononsegnato = 13214234;
	unsigned int interononsegnato = -214335;
	short unsigned int cortointerononsegnato = 6; //utilizzo numero così posso vedere la differenza tra signed e unsigned
	unsigned char charactnonsegnato = -50;
	long double doublelong = 2.34567865648948694646;

	//dichiaro una variabile intera lunghezza che verrà usata per gestire la lunghezza di printf

	int lunghezza;

	//Mostro il l'obbiettivo del programma

	puts("ESERCIZIO 1 PROGRAMMAZIONE A-L DAVIDE ACCETTURI \n \n Scrivere un programma C che dichiari una variabile per ogni tipo studiato (usando anche i qualificatori short, long, signed e unsigned), ne stampi il valore e l’occupazione di memoria in byte. Utilizzare TUTTI gli argomenti della funzione printf() studiati e TUTTE le diverse varianti (modificatore, campoMinimo, precisione, modificatoreLunghezza). Per ogni chiamata alla funzione printf(), mostrare a video anche il numero di caratteri che quest’ultima ha stampato (Aiuto: la funzione printf() restituisce un valore). Stampare inoltre il valore minimo e il valore massimo ammissibile per ogni tipo utilizzato. \n");

	//mostro tutti i valori delle variabili senza e usando i diversi specificatori (numero di cifre, specificatori)
	//associo lunghezza alla funzione (essendo una funzione int, mi rilascia il valore della sua lunghezza)

	{
		lunghezza = printf("Il valore della variabile (int) e': %d \n", intero);
		printf("La lunghezza di questa printf e': %d \n", lunghezza);

		  printf("Il valore della variabile (int) usando specificatore campoMinimo e': %5d \n", intero);

		  printf("Il valore della variabile (int) usando specificatore di precisione e': %.3d \n", intero);

		  printf("Il valore della variabile (int) usando specificatore di allinemento (-) e': %-d \n", intero);

		  printf("Questa variabile occupa: %zd bytes \n\n", sizeof intero);

	}
	//int

	{
		  printf("Il valore della variabile (float) e': %f \n", decimale);

		  printf("Il valore della variabile (float) usando specificatore campoMinimo e': %5f \n", decimale);

		  printf("Il valore della variabile (float) usando specificatore di precisione e': %.3f \n", decimale);

		  printf("Il valore della variabile (float) usando specificatore di allinemento (-) e': %-f \n", decimale);

		  printf("Questa variabile occupa: %zd bytes \n\n", sizeof(decimale));

	}
	//float

	{
		  printf("Il valore della variabile (char) e': %c \n", carattere);

		  printf("Il valore della variabile (char) usando specificatore campoMinimo e': %5c \n", carattere);

		  printf("Il valore della variabile (char) usando specificatore di precisione e': %.3c \n", carattere);

		  printf("Il valore della variabile (char) usando specificatore di allinemento (-) e': %-c \n", carattere);

		  printf("Questa variabile occupa: %zd bytes \n\n", sizeof(carattere));


	}
	//char

	{
		  printf("Il valore della variabile (double) e': %f \n", reale_doppio);

		  printf("Il valore della variabile (double) usando specificatore campoMinimo e': %5f \n", reale_doppio);

		  printf("Il valore della variabile (double) usando specificatore di precisione e': %.3f \n", reale_doppio);

		  printf("Il valore della variabile (double) usando specificatore di allinemento (-) e': %-f \n", reale_doppio);

		  printf("Questa variabile occupa: %zd bytes \n\n", sizeof(reale_doppio));

	}
	//double

	{
		  printf("Il valore della variabile (short int) e': %d \n", interoshort);


		  printf("Il valore della variabile (short int) usando specificatore campoMinimo e': %5d \n", interoshort);


		  printf("Il valore della variabile (short int) usando specificatore di precisione e': %.3d \n", interoshort);

		  printf("Il valore della variabile (short int) usando specificatore di allinemento (-) e': %-d \n", interoshort);

		  printf("Questa variabile occupa: %zd bytes \n\n", sizeof(interoshort));

	}
	//short int

	{
		  printf("Il valore della variabile (long int) e': %d \n", interolong);

		  printf("Il valore della variabile (long int) usando specificatore campoMinimo e': %5d \n", interolong);

		  printf("Il valore della variabile (long int) usando specificatore di precisione e': %.3d \n", interolong);

		  printf("Il valore della variabile (long int) usando specificatore di allinemento (-) e': %-d \n", interolong);

		  printf("Questa variabile occupa: %zd bytes \n\n", sizeof(interolong));

	}
	//long int

	{
		  printf("Il valore della variabile (long unsigned int) e': %d \n", lungointerononsegnato);

		  printf("Il valore della variabile (long unsigned int) usando specificatore campoMinimo e': %5d \n", lungointerononsegnato);

		  printf("Il valore della variabile (long unsigned int) usando specificatore di precisione e': %.3d \n", lungointerononsegnato);

		  printf("Il valore della variabile (long unsigned int) usando specificatore di allinemento (-) e': %-d \n", lungointerononsegnato);

		  printf("Questa variabile occupa: %zd bytes \n\n", sizeof(lungointerononsegnato));

	}
	//long unsigned int

	{
		  printf("Il valore della variabile (un-signed int) e': %d \n", interononsegnato);


		  printf("Il valore della variabile (un-signed int) usando specificatore campoMinimo e': %5d \n", interononsegnato);


		  printf("Il valore della variabile (un-signed int) usando specificatore di precisione e': %.3d \n", interononsegnato);


		  printf("Il valore della variabile (un-signed int) usando specificatore di allinemento (-) e': %-d \n", interononsegnato);


		  printf("Questa variabile occupa: %zd bytes \n\n", sizeof(interononsegnato));

	}
	//unsigned int

	{
		  printf("Il valore della variabile (short unsigned int) e': %d \n", cortointerononsegnato);

		  printf("Il valore della variabile (short unsigned int) usando specificatore campoMinimo e': %5d \n", cortointerononsegnato);

		  printf("Il valore della variabile (short unsigned int) usando specificatore di precisione e': %.3d \n", cortointerononsegnato);

		  printf("Il valore della variabile (short unsigned int) usando specificatore di allinemento (-) e': %-d \n", cortointerononsegnato);

		  printf("Questa variabile occupa: %zd bytes \n\n", sizeof(cortointerononsegnato));
	}
	//short unsigned int

	{
		  printf("Il valore della variabile (un-signed char) e': %c \n", charactnonsegnato);

		  printf("Il valore della variabile (un-signed char) usando specificatore campoMinimo e': %5c \n", charactnonsegnato);

		  printf("Il valore della variabile (un-signed char) usando specificatore di precisione e': %.3c \n", charactnonsegnato);

		  printf("Il valore della variabile (short int) usando specificatore di allinemento (-) e': %-c \n", charactnonsegnato);

		  printf("Questa variabile occupa: %zd bytes \n\n", sizeof(charactnonsegnato));
	}
	//unsigned char

	{
		//utilizzando Visual Studio non ho problemi con la rappresentazione delle variabili long double in caso di utilizzo di mingw come compiler è necessario includere le seguenti stringhe di codice al posto del normale printf

		  printf("Il valore della variabile (long double) e': %Le \n", doublelong);
		 //_mingw_printf("Il valore della variabile (long double) e': %Le \n", doublelong);

		  printf("Il valore della variabile (long double) usando specificatore campoMinimo e': %5Le \n", doublelong);
		 //_mingw_printf("Il valore della variabile (long double) usando specificatore campoMinimo e': %5Le \n", doublelong);

		  printf("Il valore della variabile (long double) usando specificatore di precisione e': %.15Le \n", doublelong);
		 //_mingw_printf("Il valore della variabile (long double) usando specificatore di precisione e': %.15Le \n", doublelong);

		  printf("Il valore della variabile (long double) usando specificatore di allinemento (-) e': %-Le \n", doublelong);
		  //_mingw_printf("Il valore della variabile (long double) usando specificatore di allinemento (-) e': %-Le \n", doublelong);

		  printf("Questa variabile occupa: %zd bytes \n\n", sizeof(doublelong));

	}
	//long double

	//mostro i limiti del compilatore
	{
		  printf("Il range di valori che puo' essere assegnato alla variabile di tipo INT va da: %d a %d \n", INT_MIN, INT_MAX);

		  printf("Il range di valori che puo' essere assegnato alla variabile di tipo DOUBLE va da: %e a %e \n", DBL_MIN , DBL_MAX);

		  printf("Il range di valori che puo' essere assegnato alla variabile di tipo FLOAT va da: %e a %e \n", FLT_MIN, FLT_MAX);

		  printf("Il range di valori che puo' essere assegnato alla variabile di tipo CHAR va da: %d a %d \n", CHAR_MIN, CHAR_MAX);

		  printf("Il range di valori che puo' essere assegnato alla variabile di tipo LONGE DOUBLE va da: %Le a %Le \n", LDBL_MIN, LDBL_MAX);

		  //_mingw_printf("Il range di valori che puo' essere assegnato alla variabile di tipo LONGE DOUBLE va da: %Le a %Le \n", LDBL_MIN, LDBL_MAX);

		  printf("Il range di valori che puo' essere assegnato alla variabile di tipo LONG INT va da: %d a %d \n", LONG_MIN, LONG_MAX);

		  printf("Il range di valori che puo' essere assegnato alla variabile di tipo SHORT INT va da: %d a %d \n", SHRT_MIN, SHRT_MAX);

		  printf("Il range di valori che puo' essere assegnato alla variabile di tipo UNSIGNED CHAR va da: 0 a %u \n", UCHAR_MAX);

		lunghezza = printf("Il range di valori che puo' essere assegnato alla variabile di tipo UNSIGNED INT va da: 0 a %u \n", UINT_MAX);
	}
	return 0;
}
