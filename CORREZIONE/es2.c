#include <stdio.h>
#include <stdlib.h>

int main(void){
	int numVoti;
	int sommaPunteggi = 0;
	int voto_max = 10;
	float media;
	
	printf("Di quanti studenti vuoi calcolare la media dei voti?\n");
	scanf("%d", &numVoti);
	
	int c=0;
	
	while(c<numVoti){
		int voto=-1;
		
		printf("Voto %d: ", c+1);
		scanf("%d", &voto);
		while(voto<=0 || voto>voto_max){
			printf("Inserisci un voto maggiore di 0 e minore di &d!\n", voto_max);
			printf("Voto %d: ", c+1);
			scanf("%d", &voto);
		}
		
		sommaPunteggi+=voto;
		c++;
	}
	
	media = (float) sommaPunteggi/numVoti;
	printf("La media dei punteggi e' di %.2f\n", media);
	
	if(media<6.0){
		printf("MEDIA INSUFFICIENTE\n");
	}else if(media<7.0){
		printf("MEDIA SUFFICIENTE\n");
	}else if(media<8.0){
		printf("MEDIA DISCRETA\n");
	}else if(media<9.0){
		printf("MEDIA BUONA\n");
	}else{
		printf("MEDIA OTTIMA\n");
	}
	
	return 0;
}
