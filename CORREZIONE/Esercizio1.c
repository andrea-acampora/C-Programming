/*
	Nome: Giulio Golinelli
	Data: 24/09/18
	Per: Ingengeria e scienze informatiche
	Titolo: Esercizio1
	Descrizione: Da decimale a binario
*/

#include <stdio.h> //libreria input output
#include "redae.h" //libreria di Giulio Golinelli

void main()
{
	//definizione variabili
	int numero;

	//prototipo funzioni
	void decToBin(int numero);

	do
	{
		system("cls");
		putsTitle("11/10/18", "decToBin");
		printf("Inserisci un numero intero: ");
		scanf("%d", &numero);
		printf("\nIl numero in binario = ");
		decToBin(numero);
		fflush(stdin);
		getchar();
	} while (1);
	return;
}

void decToBin(int numero)
{
	if (numero == 0)
		return;
	decToBin(numero / 2);
	printf("%d", numero % 2);
}