#include <stdio.h>
#include <stdlib.h>
int main()
{
int vettore[10],i,numero1,numero2,trovato;
printf("Inserisci dieci numeri interi \n");
for(i=0;i<10;i++)
{
    scanf("%d",&vettore[i]);
    fflush(stdin);
}
printf("Inserire numero intero compreso nel vettore \n");
scanf("%d",&numero1);
fflush(stdin);
printf("Inserire altro numero intero compreso nel vettore \n");
scanf("%d",&numero2);
fflush(stdin);
trovato=0;
for (i=0;i<10;i++)
{
    if(vettore[i]==numero1)
        trovato=1;
        posizione_prima=i;
}
for (i=0;i!=numero2;i++)
{
    vettore[i+1]=numero1;
}
for(i=0;i<10;i++)
{
    printf("\n");
    printf("%d",vettore[i]);
}
printf("\n");
system("pause");
return 0;
}
