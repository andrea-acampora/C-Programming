#include <stdio.h>
#include <stdlib.h>


int main()
{
    char parola[11];
    printf("Enter a max 10 char word \n");
    scanf("%s",&parola);

        while (strlen(parola)>10){
                printf("Enter a max 10 char word \n");
                scanf("%s",&parola);
                }
    printf("parola : %s",parola);
}



