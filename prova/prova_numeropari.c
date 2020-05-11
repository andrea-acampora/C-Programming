#include <stdio.h>
#include <stdlib.h>

int main()
{
int n,i,numero;
printf("Inserire 10 numeri interi \n");
for(i=0;i<10;i++)
{
    printf("Inserire numero \n");
    scanf("%d",&numero);
    fflush(stdin);
    if((numero%2)==0)
        printf("Il numero e' pari\n");
        else
        printf("Il numero e' dispari\n");
}
system("pause");
}
