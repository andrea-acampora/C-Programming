#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *vettore;
    int i;
    printf("INSERIRE UNA FRASE SENZA LIMITI \n");
    vettore=(char *)malloc(20*sizeof(char));
    for(i=0;i!='\n';i++)
    {
        scanf("%c",vettore+i);
    }
    for(i=0;i!='\0';i++)
    printf("\n %c",vettore+i);

    return 0;
}
