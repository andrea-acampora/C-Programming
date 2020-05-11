#include <stdio.h>
#include <stdlib.h>
#define MAX 32 /*MASSIMO 32 ELEMENTI DEL VETTORE (DA 0 A 31)*/


main(){
/*DICHIARAZIONE VARIABILI*/
int disponibilita1[MAX];
int disponibilita2[MAX];
int coincidenze[MAX];
int i,j,k,z,dim1,dim2,giorni1,giorni2,maxgiorni,confronto;
/*CICLO FOR CON INIZIALIZZAZIONE VARIABILI*/
for (i = 0; i<=MAX; i++) {
disponibilita1[MAX]=0;
disponibilita2[MAX]=0;
coincidenze[MAX]=0;
}

/*CICLO CON INSERMENTO DEI GIORNI DISPONIBILI DEL PRIMO COLLEGA*/
do {
printf("Utente 1\n");
printf("Inserisci il numero di giorni disponibili: ");
scanf("%d",&dim1);
if (dim1 <= 0 || dim1 > 31 )
printf("Il Valore inserito e' errato!\n\n");
}while(dim1 <= 0 || dim1 > 31); /*CICLO CON CONTROLLO IN CASO CI SIANO NUMERI NEGATIVO E/O SUPERIORI AL 31ESIMO GIORNO*/

/*CICLO FOR*/
for (i = 1; i<=dim1; i++) {

/*CICLO CON INSERMENTO DEI GIORNI DEL PRIMO COLLEGA*/
do {
printf("\nInserire il '%d' giorno: ",i);
scanf("%d",&giorni1);
if (giorni1 <= 0 || giorni1 > 31 ) {
printf("Il Valore Inserito e' Errato!\n\n");
} else {
disponibilita1[giorni1]=1;
}
}while(giorni1 <= 0 || giorni1 > 31);


}

/*ULTERIORI PASSAGGI DEFINITI PER IL COLLEGA 2*/
do {
printf("\nCollega 2\n");
printf("Inserisci il numero dei giorni disponibili: ");
scanf("%d",&dim2);
if (dim2 <= 0 || dim2 > 31 )
printf("Il Valore Inserito e' errato!\n\n");
}while(dim2 <= 0 || dim2 > 31);


for (j = 1; j<=dim2; j++) {

/*CICLO PER L'INERIMENTO DEI GIORNI E CONTROLLI SU DI ESSO*/
do {
printf("\nInserire '%d' giorno: ",j);
scanf("%d",&giorni2);


if (giorni2 <= 0 || giorni2 > 31 ) {
    printf("Il Valore Inserito e' errato!\n\n");
    }
else {
    disponibilita2[giorni2]=1;
    }
}
while(giorni2 <= 0 || giorni2 > 31);
}
/*STAMPA DEL MESSAGGIO E CICLO FOR PER L'EVENTUALITA' DELLE COINCIDENZE*/
printf("\nI giorni disponibili per entrambi i colleghi sono: \n");
for(k=0; k <=MAX; k++ ) {


if(disponibilita1[k] == 1 && disponibilita2[k] == 1) {
coincidenze[k]=k;
printf("Il Giorno %d\n",coincidenze[k]);
}
}

for(z=0; z<=MAX; z++) {
    if(coincidenze[z] != 0) {
    confronto=1;
    }
else {
confronto=0;
}
}

/*NEL CASO NON CI FOSSE NESSUN GIORNO UTILE PER INCONTRARSI*/
if(confronto == 0){
printf("Nessun giorno Disponibile!");
}
return 0;
}
