#include<stdio.h>
#include<stdlib.h>
long long *primi,ii=2;
int primo(long long num);
int main(){
    long long i, numeri;
    primi = (long long *)malloc(sizeof(long long));
    primi[0] = 2;
    printf("inserire il numero fino al quale arrivare : ");
    scanf("%lld",&numeri);
    for(i = 2;i<=numeri;i++)
        if(primo(i))
            printf("%lld\n",i);

    printf("numeri primi inferiori di %lld\n",numeri);
}

int primo(long long num){
    primi = (long long *)realloc(primi,sizeof(long long)*ii);
    long long i;
    int prim = 1;
    if(num == 2)
           return 1;
    for(i=0;i<ii-1;i++)
        if(num%primi[i] == 0)
            prim = 0;

    if (prim)
        primi[ii++-1] = num;
    return prim;
}
