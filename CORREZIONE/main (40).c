#include <stdio.h>
#include <stdlib.h>

unsigned long int fattoriale(unsigned int j);

int main()
{
unsigned long int f,i;

printf("\nInserire un valore intero tra 1 e 12: ");
scanf("%lu",&i);
fflush(stdin);

if (i>12 || i<1)
    printf("\nSono ammessi solo valori tra 1 e 12!");

else
f=fattoriale(i);
printf("\n%lu valore fattoriale = %lu",i,f);

printf("\n\n");
system("PAUSE");
return 0;

}

unsigned long int fattoriale(unsigned int j)

{
int k;
if (j==1)
    return 1 ;
else
k =j* fattoriale(j-1);
return k;
}
