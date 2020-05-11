#include <stdio.h>
#include <limits.h>
#include <stdlib.h>



int main(){
	//NP è un vettore dinamico che conterrà tutti i numeri primi
	int *NP;
	int nmax = 10;
	//alloco NP e controllo che vi sia spazio nella memoria 
	NP = (int *) malloc(nmax*sizeof(int));
	if(NP == NULL)
	{
		printf("Memoria insufficiente\n");
		return 0;
	}
	//faccio inserire il numero fino a cui va calcolato il fattoriale
	int n;
	printf("Inserire un numero\n");
	int controllo = scanf("%d", &n);
	fflush(stdin);
	while(controllo == 0 || n < 2)
	{
		printf("Valore inserito errato\n");
		controllo = scanf("%d", &n);
		fflush(stdin);
	}
	NP[0] = 2;
	int j = 1;
	//calcolo il fattoriale fino a n
	for(int i = 3; i <= n; i++)
	{
		int flag = 0;
		if(i > nmax)
		{
			nmax*=2;
			NP = (int *) realloc(NP, nmax*sizeof(int));
			if(NP == NULL)
			{
				printf("Memoria insufficiente\n");
				return 0;
			}
		}
		for(int k = 0; k < j; k++)
		{
			if(i % NP[k] == 0)
			{
				flag = 1;
				break;
			}
		}
		if(!flag)
		{
			NP[j] = i;
			j++;
		}
	}
	for(int i = 0; i < j; i++)
	{
		printf("%4d e' un numero primo\n", NP[i]);
	}
	free(NP);
	getchar();
	return 0;
}