#include<stdio.h>
#include<stdlib.h>

int *primi,dim=2;
int primo(int n);
int main(){
    int i, n;
    primi = (int *)malloc(sizeof(int));
    primi[0] = 2;
    printf("inserire il numero fino al quale arrivare : ");
    scanf("%d",&n);
    printf("1\n");
    for(i = 2;i<=n;i++)
        if(numeri_primi(i))
        {
        printf("%d\n",i);
        }

    printf("numeri primi inferiori di %d\n",n);
}

int numeri_primi(int n){
    primi = (int *)realloc(primi,sizeof(long int)*ii);
    int i;
    int prim = 1;
    if(n == 2)
           return 1;
    for(i=0;i<dim-1;i++)
        if(n%primi[i] == 0)
            prim = 0;

    if (prim)
        primi[dim++-1] = n;
    return prim;
}
