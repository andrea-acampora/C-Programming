#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void)
{
int scelta;
printf("SCEGLIERE MODALITA' SENZA LIBRERIA(1) O MODALITA' CON LIBRERIA STRING.H(2)\n");
scanf("%d",&scelta);
fflush(stdin);
//CICLO DI CONTROLLO NELLA SCELTA DI UNA DELLE DUE MODALITA'
while (scelta<1 || scelta >2 )
{
printf("CARATTERE INSERITO NON CORRETTO \n");
printf("SCEGLIERE MODALITA' CON LIBRERIA STRING.H (1) O MODALITA' SENZA LIBRERIA (2) \n");
scanf("%1d",&scelta);
fflush(stdin);
}
//ENTRA NEL CICLO DELLA MODALITA CON LIBRERIA STRING.H
if(scelta==2)
{
char str1[31],str2[31],nuovastr[31],*i;
int j,k,flag,leng1,leng2;
printf("Inserisci parola max 30 caratteri:");
fscanf(stdin,"%30s",str1);
fflush(stdin);
printf("\nInserisci un'altra parola max 30 caratteri:") ;
fscanf(stdin,"%30s",str2);
fflush(stdin);
//CALCOLO LUNGHEZZA PAROLE
leng1=strlen(str1);
leng2=strlen(str2);
//CICLO PER SCORRERE LE LETTERE DEL VETTORE DI CARATTERI
for(j=0;j<leng1;j++)
{
    for(k=0;k<leng2;k++)
    {
        //FUNZIONE PER TROVARE CORRISPONDENZA TRA LE DUE STRINGHE
        i=strstr(str1,str2);
        if(i==1)
        {
            //ASSEGNAZIONE DI * NEL CARATTERE IN CUI CORRISPONDE
            str1[j]=="*";
            printf("%s\n",str1[j]);
        }
    }
}

system("pause");
return 0;
}
//CICLO SENZA LIBRERIA STRING.H
if (scelta==1)
{
char par1[31],par2[31];
int i=0,k=0,j,flag,lung1,lung2 ;
printf("Inserisci parola max 30 caratteri:");
fscanf(stdin,"%30s",par1);
fflush(stdin);
printf("\nInserisci un'altra parola max 30 caratteri:") ;
fscanf(stdin,"%30s",par2);
fflush(stdin);
//INCREMENTO IL CONTATORE I FINO ALLA FINE DELLA PAROLA E CALCOLO COSI LA LUNGHEZZA
while(par1[i]!='\0')i++;
//INCREMENTO IL CONTATORE K FINO ALLA FINE DELLA PAROLA E CALCOLO COSI LA LUNGHEZZA
while(par2[k]!='\0')k++;
lung1=i;
lung2=k;
//CICLO ESTERNO PER SCORRERE IL VETTORE
for ( i=0; i+(lung2-1)<lung1; i++ )
{
//INIZIALIZZO LA VARIABILE FLAG
flag = 1 ;
//CICLO PER SCORRERE IL SECONDO VETTORE
for ( j=0; j<lung2 && flag==1; j++ )
{
//SE NON C'E' CORRISPONDENZA LA VARIABILE FLAG DIVENTA 0
if ( par1[i+j] != par2[j] )
flag = 0 ;
}
//CON CORRISPONDENZA FACCIO UN CICLO PER ANDARE A SOSTITUIRE AI CARATTERI L'*
if ( flag==1 )
{
for ( j=0; j<lung2; j++ )
par1[i+j] = '*' ;
i = i + lung2 - 1 ;
}
}
printf("La nuova parola  e' %s \n", par1) ;
return(0) ;
}
}
