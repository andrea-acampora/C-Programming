#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    /*senza librerie*/

    char parola1[30];   /*Dichiaro un po' di variabili*/
    char parola2[30];
    int a;
    int b;
    printf("Inserire prima parola ");
    fgets(parola1,sizeof(parola1),stdin);
    printf("Inserire seconda parola ");
    fgets(parola2,sizeof(parola2),stdin);
    printf("\n");
    a=printf("%s\n",parola1); /*acquisisco le dimensioni effettive delle parole messe in input*/
    b=printf("%s\n",parola2);
    int c;
    int c1;
    int conta1;
    int conta2;



    for (c=0; c<a-2; ++c){          /*vedo se la prima lettera della seconda stringa è uguale ad una lettera della prima*/
        if (parola2[0]==parola1[c]){
            conta1=c;
            conta2=0;
            for (c1=0; c1<b-3; ++c1){   /*in caso affermativo scorro in tutta la seconda stringa*/
                ++conta1;
                ++conta2;
                if (parola1[conta1]==parola2[conta2]){  /*valuto tutte le lettere successive di entrambe le parole*/
                    if (parola1[conta1]==parola2[b-3]){ /*finchè non arrivo alla fine della seconda e stampo **/
                        printf("*");
                        c+=b-3; /*riprendo da dopo a dove avevo trovato la prima corrispondenza*/
                    }

                }
                else{
                    printf("%c",parola1[conta1-1]); /*nel caso la condizione a questo else collgata fosse falsa stampo semplicemente la lettera di quella stringa*/
                    break;
                }
            }
        }
        else
            printf("%c", parola1[c]);   /*come sopra*/

    }

    printf("\n\nCon le librerie\n\n");

    /*con librerie*/

char *sostituisci(char *parola3, char *sottstrn)    /*creo la funzione per sostituire la sottostringa*/
{
    static char buffer[1024];   /*dichiaro un buffer per fare le operazioni tra le stringhe*/
    char *p;    /*questa variabile servirà per valutare la presenza della sottostringa nella principale*/
    int i = 0;  /*questa variabile andrà a scorrere tutti gli elementi del vettore nel quale è contenuta la stringa principale*/

    if (!(p = strstr(parola3 + i, sottstrn)))   /*se la sottostringa non è presente nella principale la funzione restituisce semplicemente la stringa principale*/
    {
        return parola3;
    }

    while (parola3[i])  /*inizio a scorrere nella stringa principale*/
    {
        if (!(p = strstr(parola3 + i, sottstrn)))   /*se non trova più occorrenze della sottostringa nella principale*/
        {
            strcat(buffer, parola3 + i);    /*salva quest'ultima nel buffer che sarà la stringa restituita dalla funzione*/
            break;
        }
        strncpy(buffer + strlen(buffer), parola3 + i, (p - parola3) - i);   /*altrimenti copio nel buffer la parte di stringa ciclata*/
        buffer[p - parola3] = '\0'; /*inserisco il terminatore*/
        strcat(buffer, "*");    /*attacco l'astersco nella posizione successiva*/
        i = (p - parola3) + strlen(sottstrn);   /*incremento la posizione della stringa principale reiniziando a ciclarla dal punto in cui avevo smesso*/
    }

    return buffer;  /*restituisco la stringa risultante salvata nel buffer*/
}



    char parola3[30],parola4[30];
    printf("Inserisci la prima parola ");
    gets(parola3);
    printf("\nInserisci la seconda parola ");
    gets(parola4);
    puts(sostituisci(parola3, parola4));/*dopo aver acquisito le parole chiamo la funzione chiedendo di mettere * per ogni parola4 in parola3*/


    return 0;
}
