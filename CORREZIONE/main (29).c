#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>

#define maxC 30

int main(int argc, char *argv[]) {
	/*variabili frase è il vettore contenente la frase e pf è il puntatore al primo carattere
	*c è un carattere usato per le varie operazioni*/
	char frase[maxC+1]="";
	char *pf=frase;
	char c;
	int b=1;
	int i=0;
	printf("a)Inserire una frase con al massiomo %d carattei\n",maxC);
	do{
		/*strumento per leggere un char alla volta*/
		c = getch();
		/*per identificare se è punteggiatura, carattere, vocale accentata*/ 
		printf("%c",c);
		if(ispunct(c)){
			*(pf+i)=c;
			i++;
		}else if(isalpha(c)){
			*(pf+i)=c;
			i++;
		}else if(c==' '){
			*(pf+i)=c;
			i++;
		}else if(c==0xFFFFFF8A||c==0xFFFFFF85||c==0xFFFFFF8D||c==0xFFFFFF95||c==0xFFFFFF97){
			*(pf+i)=c;
			i++;
		}
		if(i>maxC-1){
			b=0;
		}	
		if(c==13){
			b=0;
		}
		/*viene ripetuto fino al riempimento del vettore o la pressione dell'invio*/
	}while(b);
	
	printf("\nFrase inserita = %s ", pf);
	/*ciclo per rendere i caratteri maiuscoli, le vocali accentate vengono trasformate in maniera diretta*/
	for(i=0;i<strlen(pf);i++){
		switch(*(pf+i)){
			case ' ':{
				*(pf+i)=' ';
				break;
			}
			case 0xFFFFFF8A:{
				*(pf+i)=212;
				break;
			}
			case 0xFFFFFF85:{
				*(pf+i)=183;
				break;
			}
			case 0xFFFFFF8D:{
				*(pf+i)=222;
				break;
			}
			case 0xFFFFFF95:{
				*(pf+i)=227;
				break;
			}
			case 0xFFFFFF97:{
				*(pf+i)=235;
				break;
			}
			default:{
				*(pf+i)=toupper(*(pf+i));
				break;
			}
		}
	}
	printf("\nb)Frase inserita in maiuscolo= %s ", pf);
	printf("\nc)Frase inserita senza punteggiatura e spazzi=");
	/*ogni volta che trova uno spazio o della punteggiatura retrocede la frase eliminando il carattere indesiderato*/
	for(i=0;i<strlen(pf);i++){
		if(frase[i]==' '){
			strncpy((pf+i), (pf+i+1), strlen(frase)-i);//poi retrocede la frase eliminando la parte indesiderata	
   			i--;/*ripete l'operazione di quel punto pre assicurarsi che non ci sia un carattere indesiderato in cuello sucessivo*/
		}else if(ispunct(frase[i])){
			strncpy((pf+i), (pf+i+1), strlen(frase)-i);//poi retrocede la frase eliminando la parte indesiderata	
   			i--;/*ripete l'operazione di quel punto pre assicurarsi che non ci sia un carattere indesiderato in cuello sucessivo*/
		}else{
			printf("%c",*(pf+i));
			/*viene stampato carattere per carattere poichè a volte non copmleta il ciclo crascando,
			così può dare un output minimamente significaivo*/
		}

	}
	
	return 0;
}
