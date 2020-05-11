#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX_CAR 51

int main()
{
char str[MAX_CAR], *pstr;
pstr=str;

    //INSERIMENTO FRASE IN INPUT
    printf("INSERIMENTO FRASE MAX 50 CARATTERI SENZA NUMERI ");
    gets(str);

    //CONTROLLO SULLA LUNHEZZA DELLA FRASE
    if(strlen(str)>=51){
		printf("\n FRASE TROPPO LUNGA,RIPROVARE");
		exit(1);
	}

	//CONTROLLO SU EVENTUALI NUMERI NELLA FRASE
    for(pstr=str;*pstr!='\0';pstr++){
		if (isdigit(*pstr)){
			printf("\n ERRORE: E' PRESENTE UN NUMERO");
			exit(1);
		}

		switch(*pstr){
			case '\x8A':{//è
				*pstr = (char) '\x90';
				break;
			}
			case '\x85':{//à
				*pstr = (char) '\xB7';
				break;
			}
			case '\x8D':{//ì
				*pstr = (char) '\xD6';
				break;
			}
			case '\x95':{//ò
				*pstr = (char) '\xE3';
				break;
			}
			case '\x97':{//ù
				*pstr = (char) '\xEb';
				break;
			}
			//CONVERSIONE DA MINUSCOLO A MAIUSCOLO
			default: {*pstr = toupper(*pstr);}
		}

	}
	//STAMPA DELLA FRASE
	printf("FRASE IN MAIUSCOLO:\n");
	for(pstr=str;*pstr!='\0';pstr++){
	printf("%c",*pstr);
	}
	printf("\n");

	//STAMPA SENZA PUNTEGGIATURA
	printf("stampa senza spazi e senza segni di punteggiatura \n");
	for (pstr=str;*pstr!='\0';pstr++)
		if(*pstr!=' ' && ispunct(*pstr)==0){
			printf("%c", *pstr);
		}
    return 0;
    system("pause");
    system("clr");
}
