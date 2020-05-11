#include <stdio.h>
#include <stdlib.h>

int main()
{
int n,i,somma=0,numero;
printf("quanti numeri vuoi inserire?\n");
scanf("%d",&n);
while(n<0){
        printf("Numero non corretto\n");
        printf("quanti numeri vuoi inserire?\n");
        scanf("%d",&n);
}

for(i=0;i<n;i++)
{
    printf("Inserire numero \n");
    scanf("%d",&numero);
    somma=somma+numero;
}
printf("la somma e'%d ",somma);
}
