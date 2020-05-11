#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void)
{

int scelta;
printf("SCEGLIERE MODALITA' CON LIBRERIA STRING.H(1) O MODALITA' SENZA LIBRERIA(2)\n");
scanf("%d",&scelta);
while (scelta<1 || scelta >2 )
{
printf("CARATTERE INSERITO NON CORRETTO \n");
printf("SCEGLIERE MODALITA' CON LIBRERIA STRING.H (1) O MODALITA' SENZA LIBRERIA (2) \n");
scanf("%1d",&scelta);
fflush(stdin);
}
if(scelta==1)
{
char str1[31],str2[31];
int leng1,leng2;
printf("Inserisci parola max 30 caratteri:");
fscanf(stdin,"%s",str1);
fflush(stdin);
printf("\nInserisci un'altra parola max 30 caratteri:") ;
fscanf(stdin,"%s",str2);
fflush(stdin);
leng1=strlen(str1);
leng2=strlen(str2);
printf("%d %d",leng1,leng2);
system("pause");
return 0;
}
if (scelta==2)
{
char par1[31],par2[31];
int i=0,k=0,j,flag,lung1,lung2 ;
printf("Inserisci parola max 30 caratteri:");
fscanf(stdin,"%s",par1);
fflush(stdin);
printf("\nInserisci un'altra parola max 30 caratteri:") ;
fscanf(stdin,"%s",par2);
fflush(stdin);
while(par1[i]!='\0')i++;
while(par2[k]!='\0')k++;
lung1=i;
lung2=k;
for ( i=0; i+(lung2-1)<lung1; i++ )
{
flag = 1 ;
for ( j=0; j<lung2 && flag==1; j++ )
{
if ( par1[i+j] != par2[j] )
flag = 0 ;
}
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
