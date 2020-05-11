#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main()
{
    int num,numero, valmin, valmax, i;
valmin=1;
valmax=100;
num=valmin+(rand()+time(NULL))%(valmax+1-valmin);
for(i=0;i<3;i++)
{
    printf("\nInserire un numero");
    scanf("%d",&numero);

    if(numero>num)
    {
        printf("numero troppo grande\n");
    }
    if (numero<num)
    {
        printf("numero troppo piccolo\n");
    }
    if (numero==num)
    {
        printf("numero indovinato\n");
    }

}
printf("\n");
printf("\n");
printf("%d",num);
printf("\n");
system("pause");
return 0;
}

