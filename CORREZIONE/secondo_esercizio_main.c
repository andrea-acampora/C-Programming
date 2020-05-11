#include <stdio.h>
#include <stdlib.h>

int main() {
	
	
	//Dichiarazione variabili per le operazioni

	int a = 10, c = 6;
	float b = 5.5;
	char x = 7;
	double y = 13.123, risultato;

	//Operatori matematici
	printf("Operazioni matematiche\n\n\n");

	//Somma
	printf("Somma\n");
	risultato = a + b;
	printf("La somma tra %d e %g e\' %g\n\n\n",a, b, risultato);

	//Sottrazione
	printf("Sottrazione\n");
	risultato = a - b;
	printf("La differenza tra %d e %g e\' %g\n\n\n",a, b, risultato);

	//Moltiplicazione
	printf("Moltiplicazione\n");
	risultato = a * y;
	printf("Il prodotto tra %d e %lg e\' %lg\n\n\n",a, y, risultato);

	//Divisione
	printf("Divisione\n");
	risultato = a / y;
	printf("Il quoziente tra %d e %lg e\' %lg\n\n\n", a, y, risultato);

	//Resto
	printf("Resto di una divisione\n");
	risultato = a % c;
	printf("Il resto della divisione tra %d e %d e\' %g\n\n\n", a, c, risultato);
	
	//Inversione segno
	printf("Inversione del segno\n", a);
	printf("Prima dell'inversione del segno a vale %d, dopo l'inversione vale %d\n\n\n\n", a, -a);
	
	//Incremento e Riduzione prefisso e postfisso
	//incremento
	printf("Incremento prefisso e postfisso\n\n");
	printf("Il valore di a prima dell'incremento prefisso e\' %d\n", a);
	a = ++a;
	printf("Il valore di a dopo l'incremento prefisso e\' %d\n\n", a);

	//L'incremento postfisso non varia il valore di b senza una funzione di tipo ciclica poichè b viene aggiornato dopo la scrittura della stringa
	printf("Il valore di y prima dell'incremento postfisso e\' %lg\n",y);
	printf("Il valore di y dopo l'incremento postfisso e\' %lg\n\n\n", y++);
	
	//riduzione
	printf("Riduzione prefissa e postfissa\n\n");
	printf("Il valore di a prima della riduzione prefissa e\' %d\n", a);
	a = --a;
	printf("Il valore di a dopo la riduzione prefissa e\' %d\n\n", a);

	printf("Il valore di x prima della riduzione postfissa e\' %d\n", x);
	printf("Il valore di x dopo la riduzione postfissa e\' %d\n\n\n", x--);
	
	//Assegnamento semplice e composto
	printf("Assegnamento semplice e composto\n\n");
	printf("La variabile a ha valore %d, la variabile c ha valore %d\n", a, c);
	a = c;
	printf("Dopo la precedente istruzione a e c assumono lo stesso valore, rispettivamente a = %d e c = %d\n\n\n", a, c);
	
	printf("La variabile a ha valore %d\n", a);
	a += 3;
	printf("Dopo la precedente istruzione a assume un valore uguale a %d    (a = a+3)\n\n\n", a);

	printf("La variabile x ha valore %d\n", x);
	x -= 3;
	printf("Dopo la precedente istruzione a assume un valore uguale a %d    (a = a-3)\n\n\n", x);
	
	printf("La variabile a ha valore %d\n", a);
	a *= 3;
	printf("Dopo la precedente istruzione a assume un valore uguale a %d    (a = a*3)\n\n\n", a);

	printf("La variabile a ha valore %d\n", a);
	a /= 3;
	printf("Dopo la precedente istruzione a assume un valore uguale a %d    (a = a/3)\n\n\n", a);

	printf("La variabile a ha valore %d\n", a);
	a %= 3;
	printf("Dopo la precedente istruzione a assume un valore uguale a %d    (a = resto di a/3)\n\n\n\n", a);

	//Operatori logici
	a = 1;
	printf("Operatori logici\n\n");
	//minore
	printf("Il valore %d e\' minore del valore %d\?\n", a, c);
	if ((a < c) == 1) {
		printf("Vero\n\n");
	}
	else {
		printf("Falso\n\n");
	}

	//maggiore
	printf("Il valore %d e\' maggiore del valore %d\?\n", a, c);
	if ((a > c) == 1) {
		printf("Vero\n\n");
	}
	else {
		printf("Falso\n\n");
	}

	//minore o uguale
	printf("Il valore %d e\' minore o uguale al valore %d\?\n", a, c);
	if ((a <= c) == 1) {
		printf("Vero\n\n");
	}
	else {
		printf("Falso\n\n");
	}

	//maggiore o uguale
	printf("Il valore %d e\' maggiore o uguale al valore %d\?\n", a, c);
	if ((a >= c) == 1) {
		printf("Vero\n\n");
	}
	else {
		printf("Falso\n\n");
	}

	//identità
	printf("Il valore %d e\' uguale al valore %d\?\n", a, c);
	if ((a == c) == 1) {
		printf("Vero\n\n");
	}
	else {
		printf("Falso\n\n");
	}


	//diversità
	printf("Il valore %d e\' diverso dal valore %d\?\n", a, c);
	if ((a != c) == 1) {
		printf("Vero\n\n");
	}
	else {
		printf("Falso\n\n");
	}
	
	system("PAUSE");
	return 0;
}