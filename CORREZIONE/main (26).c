#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define VAL_MAX 41

int main()
{
    /*Diciaro un puntatore e un vettore di caratteri*/
    char vettore[VAL_MAX + 1]={0};
    char *ptr = vettore;
    /*Faccio puntare il puntatore alla prima cella di memoria del vettore(in altre parole: ptr->&vettore[0]*/
    /*(a)Chiedo all'utente di digitare la prima frase di una canzone in Italiano*/
    printf("Digita la prima frase di una canzone in italiano (max: %d): ", VAL_MAX - 1);
    fgets(ptr, VAL_MAX, stdin);
    fflush(stdin);
    /*Inserisco un terminatore alla stringa*/
    for(int i = VAL_MAX+1; i!=0; i--){
        if(vettore[i]!=' '){
            *(ptr+i)='\0';
            break;
        }
    }
    /*Controllo che non vi siano numeri*/
    for(int i=0, is=11; i<=VAL_MAX; i++){
        is=*(ptr+i);
        if(isdigit(is)!=0){
            printf("\nNon e' permesso l'uso dei numeri...");
            return 0;
        }
        if(*(ptr+i)=='\0')
            break;
    }
    /*(b)Visualizzo la frase in stampatello minuscolo*/
    printf("Stringa convertita in maiuscolo: ");
    for(int i=0; *(ptr+i)!='\0'; i++){
        if(islower(*(ptr+i))!=0)
            *(ptr+i) -= 32;
        else if(*(ptr+i)=='\x8A') //è
            *(ptr+i)= '\xD4';
        else if(*(ptr+i)=='\x85') //à
            *(ptr+i)= '\xB7';
        else if(*(ptr+i)=='\x8D') //ì
            *(ptr+i)= '\xD6';
        else if(*(ptr+i)=='\x95') //ò
            *(ptr+i)= '\xE3';
        else if(*(ptr+i)=='\x97') //ù
            *(ptr+i)= '\xEB';
        printf("%c", *(ptr+i));
    }
    /*(c)Rimuovo eventuali spazzi e segni di punteggiatura*/
    for(int i=0; *(ptr+i)!='\0'; i++){
        if(isspace(*(ptr+i))!=0 || ispunct(*(ptr+i))!=0){
            for(int i1=i; *(ptr+i1)!='\0'; i1++)
                *(ptr+i1)=*(ptr+(1+i1));
            i--;
        }
    }
    /*(d)Ri-visualizzo la frase a monitor*/
    printf("Stringa finale: ");
    for(int i=0; *(ptr+i)!='\0'; i++)
        printf("%c", *(ptr+i));
    return 0;
}
