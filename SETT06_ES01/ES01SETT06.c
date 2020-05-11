#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
//LUNGHEZZA MASSIMA VETTORE
const int max=20;
//VARIABILE PER IDENTIFICARE L'ELEMENTO TROVATO NEL VETTORE
int trovato=0;
int i,j,temp,posizione;
//FUNZIONE CERCA
int cerca(int vett[],int dimensione,int elemento)
{
trovato=0;
i=0;
//CICLO CHE CONFRONTA TUTTI GLI ELEMENTI DEL VETTORE CON IL NUMERO INSERITO
//FINO A CHE NON VIENE TROVATO OPPURE FINISCE IL VETTORE
do
{
    if(vett[i]==elemento)
    {
        trovato=1;
        posizione=i;
    }
    else
    {
    ++i;
    }
}while((i<dimensione)&&(trovato==0));
return trovato;
}
//FUNZIONE CERCA_VETTORE_ORDINATO
int cerca_vettore_ordinato(int vett[],int dimensione,int elemento)
{
trovato=0;
i=0;
//CICLO CHE CONFRONTA TUTTI GLI ELEMENTI DEL VETTORE CON IL NUMERO INSERITO
//FINO A CHE NON VIENE TROVATO OPPURE FINISCE IL VETTORE
do
{
    if(vett[i]==elemento)
    {
        trovato=1;
        posizione=i;
    }
    else
    {
    ++i;
    }
}while((i<dimensione)&&(trovato==0));
//ORDINAMENTO DEL VETTORE
for(i=0;i<dimensione-1;i++)
{
    for(j=i+1;j<dimensione;j++)
    {
        if(vett[i]>vett[j])
        {
            temp=vett[i];
            vett[i]=vett[j];
            vett[j]=temp;
        }
    }
}
return trovato;
}
//DICHIARAZIONI VARIABILI
int main(void)
{
int i,dimensione,vett[max],elemento;
printf("QUANTI NUMERI VUOI INSERIRE? \n");
scanf("%d",&dimensione);
fflush(stdin);
while(dimensione<0 || dimensione>20)
{
printf("Errore,riprovare \n");
printf("QUANTI NUMERI VUOI INSERIRE? \n");
scanf("%d",&dimensione);
fflush(stdin);
}
printf("\n");
for(i=0;i<dimensione;i++)
{
printf("INSERISCI IL %d ELEMENTO ",i);
scanf("%d",&vett[i]);
fflush(stdin);
}
printf("\n");
printf("INSERISCI UN ELEMENTO DA CERCARE NEL VETTORE \n");
scanf("%d",&elemento);
fflush(stdin);
for(i=0;i<60;i++)
{printf("-");};
printf("\n");
//SE LA FUNZIONE ASSUME VALORE 1 SIGNIFICA CHE IL NUMERO E' STATO TROVATO ALTRIMENTI NO
if(cerca(vett,dimensione,elemento)==1)
{
    printf("IL NUMERO %d E' PRESENTE NEL VETTORE NELLA POSIZIONE %d\n",elemento,posizione);
}
else
{
     printf("NUMERO INSERITO NON TROVATO \n");
}
for(i=0;i<60;i++)
{printf("-");};
printf("\n");
printf("\n");
system("pause");
system("cls");
return 0;
}
