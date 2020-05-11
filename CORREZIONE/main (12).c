#include <stdio.h>
#include <stdlib.h>

int main()
{
    //Dichiarazione variabili
    int i;
    int voto_max=10;
    float numero_studenti,media,voti_studenti;
    float somma_voti=0;

    //Primo inserimento del numero di studenti
    printf("Inserisci un numero positivo di studenti\n\n");
    scanf("%f",&numero_studenti);
    fflush(stdin);

    //Tramite questo while, forzo l'utente a reinserire il numero di studenti nel caso in cui il primo input dovesse essere negativo o decimale
    while (numero_studenti<0 || numero_studenti!=(int)numero_studenti)
    {
        printf("\nQuantita' non valida! Inserisci una quantita' valida!\n\n");
        scanf("%f",&numero_studenti);
        fflush(stdin);
    }

    //Tramite un ciclo for faccio inserire un voto per ogni studente, basandomi sul numero di studenti dichiarati nella variabile numero_studenti
    //Con il while faccio ripetere l'input nel caso in cui il voto non dovesse essere compreso tra 0 e 10
    //Infine, eseguo di volta in volta la somma dei voti degli studenti
    for (i=1;i<=numero_studenti;i++)
    {
        printf("\nInserisci il voto dello studente numero %d\n\n",i);
        scanf("%f",&voti_studenti);
        fflush(stdin);
        while (voti_studenti<=0 || voti_studenti>voto_max)
        {
            printf("\nInserire un voto valido!\n\n");
            printf("Inserisci il voto dello studente numero %d\n\n",i);
            scanf("%f",&voti_studenti);
            fflush(stdin);;
        }
        somma_voti=somma_voti+voti_studenti;
    }
    //Calcolo e stampo a monitor la media della classe con 2 cifre decimali
    media=somma_voti/numero_studenti;
    printf("\nLa media della classe e' %.2f\n\n",media);

    //Tramite un if, stampo a monitor un commento in base al voto medio della classe
    if (media<6)
    {
        printf("MEDIA INSUFFICIENTE\n\n");
    }
    else if (media>=6 && media<7)
    {
        printf("MEDIA SUFFICIENTE\n\n");
    }
    else if (media>=7 && media<8)
    {
        printf("MEDIA DISCRETA\n\n");
    }
    else if (media>=8 && media<9)
    {
        printf("MEDIA BUONA\n\n");
    }
    else if (media>=9 && media<=10)
    {
        printf("MEDIA OTTIMA\n\n");
    }
    system("PAUSE");
    return 0;
}
