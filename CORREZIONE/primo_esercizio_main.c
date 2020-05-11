//Macro che evita errori CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
	//Formato orario 24h
	float dep1 = 00.47, dep2 = 8.00, dep3 = 9.43, dep4 = 11.19, dep5 = 14.00, dep6 = 15.45, dep7 = 19.00, dep8 = 21.45;

	//Valore input (dep_float) e parte decimale del valore in input (float_minute_time)
	float dep_time, float_minute_time;
	int int_time;

	printf("Enter a 24 hour time: ");
	scanf("%f", &dep_time);
	fflush(stdin);

	//Recupero il valore dei minuti dell'input inserito
	int_time = (int)dep_time;
	float_minute_time = dep_time - int_time;

	//Controllo che l'input sia compreso tra 0 e 24 e che la parte decimale sia compresa tra 0 e 59 (minuti)
	if ((dep_time <= 24) && (dep_time >= 0) && (float_minute_time >= 0) && (float_minute_time < 0.60)) {

		//Se l'input e' compreso tra l'orario di partenza dell'aereo precedente e l'orario di partenza del seguente, stampo l'orario del seguente
		if ((dep_time > dep1) && (dep_time <= dep2)) {
			//Secondo aereo a partire dalle 00.00 alle 23.59
			printf("Closest departure time is 8.00 am, arriving at 10.16 am\n\n\n");
		}
		else if ((dep_time > dep2) && (dep_time <= dep3)) {
			//Terzo aereo a partire dalle 00.00 alle 23.59
			printf("Closest departure time is 9.43 am, arriving at 11.52 am\n\n\n");
		}
		else if ((dep_time > dep3) && (dep_time <= dep4)) {
			//Quarto aereo a partire dalle 00.00 alle 23.59
			printf("Closest departure time is 11.19 am, arriving at 1.31 pm\n\n\n");
		}
		else if ((dep_time > dep4) && (dep_time <= dep5)) {
			//Quinto aereo a partire dalle 00.00 alle 23.59
			printf("Closest departure time is 2.00 pm, arriving at 4.08 pm\n\n\n");
		}
		else if ((dep_time > dep5) && (dep_time <= dep6)) {
			//Sesto aereo a partire dalle 00.00 alle 23.59
			printf("Closest departure time is 3.45 pm, arriving at 5.55 pm\n\n\n");
		}
		else if ((dep_time > dep6) && (dep_time <= dep7)) {
			//Settimo aereo a partire dalle 00.00 alle 23.59
			printf("Closest departure time is 7.00 pm, arriving at 9.20 pm\n\n\n");
		}
		else if ((dep_time > dep7) && (dep_time <= dep8)) {
			//Ottavo aereo a partire dalle 00.00 alle 23.59
			printf("Closest departure time is 9.45 pm, arriving at 11.58 pm\n\n\n");
		}
		else {
			//Primo aereo a partire dalle 00.00 alle 23.59
			printf("Closest departure time is 12.47 am, arriving at 3.00 pm\n\n\n");
		}
	}

	//Messaggio di errore nel caso l'input non rispetti le condizioni sopracitate
	else {
		printf("Formato input 24h non valido\n");
	}

	system("PAUSE");
	return 0;
}


