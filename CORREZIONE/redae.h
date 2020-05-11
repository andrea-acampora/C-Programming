//_________________________________________________________________________
//________________________________________________________________________|
//                                                                        |
//	**     **  ********          ***    ***      ******       ***    **   |
//	 **   **   **    **          **********     ***  ***      ****   **   |
//	  ** **    **    **          ** **** **    ***    ***     ** **  **   |
//	   **      **    **          **  **  **   ************    **  ** **   |
//	   **      **    **          **      **  ***        ***   **   ****   |
//     **      ********          **      ** ***          ***  **    ***   |
//________________________________________________________________________|

// Libreria di Giulio Golinelli

#include <stdio.h>
#include <Windows.h> //libreria per interfacciarsi con le windows API

void setColor();
void setDefaultColor();
void putsTitle();

void setColor(int Color)
{
	//setta un colore desiderato nella console

	/*	TABELLA COLORI:
		Name         | Value
             		 |
		Black        |   0
		Blue         |   1
		Green        |   2
		Cyan         |   3
		Red          |   4
		Magenta      |   5
		Brown        |   6
		Light Gray   |   7
		Dark Gray    |   8
		Light Blue   |   9
		Light Green  |   10
		Light Cyan   |   11
		Light Red    |   12
		Light Magenta|   13
		Yellow       |   14
		White        |   15
	*/

	//HANDLE è un tipo usato da windows.h e racchiude una referenza.
	//A differenza del puntatore, l'HANDLE non trasporta informazioni
	//riguardo al tipo del dato a cui HANDLE fa riferimento.
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, Color); //mette il colore
	return;
}

void setDefaultColor()
{
	setColor(7);
	return;
}

void putsTitle(char date[], char title[])
{
	int i = 0;

	//Stampa un titolo personalizzato
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED); //sfondo bianco

	printf("%s %c %s %c %s\n", "GOLINELLI GIULIO", '|', date, '|', title);

	setDefaultColor(); //mette il colore di default

	for (; i < 75; i++)
		printf("%c", 205);
	printf("\n");
	return;
}

//prende una string e toglie tutte le occorenze di un carattere
void stripString(char *str, char c)
{
	char *pr = str, *pw = str;
	while (*pr)
	{
		*pw = *pr++;
		pw += (*pw != c);
	}
	*pw = '\0'; //aggiunge il carattere terminatore
}