#include <stdio.h>
#include <stdlib.h>
int main()
{
int matrice[2][3],i,j,numero,somma,sommaMax,rigaMax;
printf("Inserire i valori nella matrice\n");
for(i=0;i<2;i++)
{
    for(j=0;j<3;j++)
    {
        scanf("%d",&matrice[i][j]);
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
for(i=0;i<2;i++)
{
    somma=0;
    sommaMax=0;
    for(j=0;j<3;j++)
       somma+=matrice[i][j];
               if (somma>sommaMax)
        {
            rigaMax = i+1;
            sommaMax = somma;
        }
         printf("\nLa riga %d e\' quella con somma dei valori massima (corrispondente a: %d)\n",rigaMax,sommaMax);
}

printf("%d\n",somma);
printf("\n");
system("pause");
return 0;
}
