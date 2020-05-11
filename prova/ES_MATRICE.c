#include <stdio.h>
#include <stdlib.h>
int main()
{
int matrice[2][3],i,j,numero,somma=0;
printf("Inserire i valori nella matrice\n");
for(i=0;i<2;i++)
{
    for(j=0;j<3;j++)
    {
        scanf("%d",&matrice[i][j]);
        somma=somma+matrice[i][j];
    }
}
for(i=0;i<2;i++)
{
    for(j=0;j<3;j++)
    {
        printf("%d",matrice[i][j]);
    }
    printf("\n");
}
printf("%d",somma);
printf("\n");
system("pause");
return 0;
}
