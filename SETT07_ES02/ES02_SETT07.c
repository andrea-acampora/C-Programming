#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define dim 10
int numeroPrimo(int n)
{
int i;
    for(i = 2; i<n; i++)
    {
        if ((n%i)==0)
            return 0;
    }
    return 1;
}
int main()
{
int var1;
    int n, dimensione;
    int *vettPrimi;
    for (var1=0; var1==0;)
        {
        printf("INSERIRE UN NUMERO FINO A CUI CALCOLARE I NUMERI PRIMI : ");
        var1=scanf("%d",&n);
        fflush(stdin);
        if(var1==0)
        {
            printf("ERRORE, RIPROVARE\n");
        }
        else if(n<=0){
            printf("ERRORE, RIPROVARE\n");
            var1=0;
        }
    }
    vettPrimi = (int *)malloc((dim)*sizeof(int));
    if (vettPrimi==NULL)
    {
        printf("ERRORE NELL'ALLOCAZIONE DELLA MEMORIA");
        exit(1);
    }
    dimensione=dim;
    if(n==1)
    {
    printf("- 1");
    return 0;
    }
    else if(n==2)
    {
        printf("- 2");
        return 0;
    }
    else if(n==3)
    {
        printf("- 2\n - 3\n");
        return 0;
    }
    else
    {
        for(int var1=0; var1<dimensione; var1++)
        {
            if(var1==0)
                *(vettPrimi+var1)=2;
            else if(var1==1)
                *(vettPrimi+var1)=3;
            else
                *(vettPrimi+var1)=0;
        }
    }
    for(int var2=4, contr=0, contDim=2; var2<=n; var2++)
    {
        contr=numeroPrimo(var2);
        if(contr!=0){
            if(contDim==dimensione)
            {
                vettPrimi = (int *) realloc(vettPrimi, (10+dimensione)*sizeof(int));
                dimensione+=10;
                if (vettPrimi==NULL)
                {
                    printf("ERRORE NELL'ALLOCAZIONE DELLA MEMORIA \n");
                    exit(1);
                }
                for(int contDim2=contDim; contDim2<dimensione+1; contDim2++)
                {
                    *(vettPrimi+contDim2)=0;
                }
            }
            *(vettPrimi+contDim)=var2;
            contDim++;
        }
    }
    for(int var11=0; var11<=dimensione-1; var11++)
    {
        printf("- %d\n", *(vettPrimi+var11));
        if(*(vettPrimi+var11+1)==0)
            break;
    }
    free(vettPrimi);
    return 0;
}
