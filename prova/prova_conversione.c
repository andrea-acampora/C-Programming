#include <stdio.h>
#include <stdlib.h>

int main()
{
   int i,n,k,vet[10];
   printf ("INSERISCI UN NUMERO DA CONVERTIRE IN BINARIO\n");
   scanf ("%d", &n);
   k = 0;
   while (n!=0) {
      if (n%2 == 1)
         vet[k] = 1;
       else
          vet[k] = 0;
       n /= 2;
       k++;
   }
   for(i=k-1;i>=0;i--)
      printf("%d",vet[i]);
   return 0;
}
