#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int* cerca(int vettore[], int n, int elem) {
	int *trovati = (int*)malloc((n + 1) * sizeof(vettore[0]));  // Alloco un vettore grande come quello originale per salvare le posizioni
	int conta = 0;
	for(int i = 0; i < n; i++) {
		if(vettore[i] == elem)
			trovati[conta++] = i;
	}
	int *output = (int*)malloc((conta+1) * sizeof(vettore[0]));  // Alloco un nuovo vettore della dimensione giusta
	memcpy(output, trovati, conta * sizeof(vettore[0]));
	output[conta] = -1;
	free(trovati);
	return output;
}

int* cerca_vettore_ordinato(int vettore[], int n, int elem) {
	int primo = n, ultimo = -1;
	// Faccio 2 ricerche binarie per trovare la prima e ultima occorrenza di elem
	int left = 0, right = n;
	while(left < right-1) {
		int mid = (left+right) / 2;
		if(vettore[mid] == elem && mid < primo)
			primo = mid;
		if(vettore[mid] >= elem)
			right = mid;
		else
			left = mid;
	}
	left = 0, right = n;
	while(left < right-1) {
		int mid = (left+right) / 2;
		if(vettore[mid] == elem && mid > ultimo)
			ultimo = mid;
		if(vettore[mid] > elem)
			right = mid;
		else
			left = mid;
	}
	if(ultimo == -1)
		primo = -1;
	int *trovati = (int*)malloc((ultimo - primo + 2) * sizeof(vettore[0]));
	for(int i = primo; i <= ultimo; i++)
		trovati[i - primo] = i;
	trovati[ultimo - primo + 1] = -1;
	return trovati;
}

int main(void) {
	int a[] = {1, 2, 4, 3, 6, 3};  // Il nostro piccolo array di numeri :3
	int size = sizeof a / sizeof a[0];
	puts("Vettore iniziale:");
	for(int i = 0; i < size; i++)
		printf("%d ", a[i]);
	printf("\n");
	int *trovati;
	puts("Cerco il valore 3:");
	trovati = cerca(a, size, 3);
	for(int i = 0; trovati[i] >= 0; i++)
		printf("%d ", trovati[i]);
	printf("\n");
	free(trovati); // Non dimentichiamoci di liberare la memoria!
	
	puts("Cerco il valore 1:");
	trovati = cerca(a, size, 1);
	for(int i = 0; trovati[i] >= 0; i++)
		printf("%d ", trovati[i]);
	printf("\n");
	free(trovati); // Non dimentichiamoci di liberare la memoria!
	
	puts("Cerco il valore 5:");
	trovati = cerca(a, size, 5);
	for(int i = 0; trovati[i] >= 0; i++)
		printf("%d ", trovati[i]);
	printf("\n");
	free(trovati); // Non dimentichiamoci di liberare la memoria!
	
	// ORDINATO
	puts("");
	int b[] = {1, 4, 5, 5, 5, 6, 6, 7};
	size = sizeof b / sizeof b[0];
	puts("Vettore iniziale:");
	for(int i = 0; i < size; i++)
		printf("%d ", b[i]);
	printf("\n");
	puts("Cerco il valore 5:");
	trovati = cerca_vettore_ordinato(b, size, 5);
	for(int i = 0; trovati[i] >= 0; i++)
		printf("%d ", trovati[i]);
	printf("\n");
	free(trovati); // Non dimentichiamoci di liberare la memoria!
	
	puts("Cerco il valore 4:");
	trovati = cerca_vettore_ordinato(b, size, 4);
	for(int i = 0; trovati[i] >= 0; i++)
		printf("%d ", trovati[i]);
	printf("\n");
	free(trovati); // Non dimentichiamoci di liberare la memoria!
	
	puts("Cerco il valore 2:");
	trovati = cerca_vettore_ordinato(b, size, 2);
	for(int i = 0; trovati[i] >= 0; i++)
		printf("%d ", trovati[i]);
	printf("\n");
	free(trovati); // Non dimentichiamoci di liberare la memoria!

	return 0;
}
