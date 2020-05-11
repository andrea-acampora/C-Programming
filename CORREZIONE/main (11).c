#include <stdio.h>
#include <stdlib.h>

int main()
{
    //Variabili utilizzate
    int numero_studenti,temp, i = 0;
    float somma;

    printf("Inserire il numero di studenti\n");
    //ciclo utilizzato per controllare che il dato inserito in ingresso sia corretto
    while(i == 0)
    {
        scanf("%d",&numero_studenti);
        fflush(stdin);
        if(numero_studenti >= 0){
            i = numero_studenti;
        }
        else{
            printf("Il numero inserito non e' corretto, inserirne uno nuovo.\n");
        }
    }
    //ciclo utilizzato per inserire i voti ed aggiungerli alla somma
    for(i = 0; i<numero_studenti;i++){
            //ciclo utilizzato per controllare la correttezza del voto inserito
        do{
            printf("\nInserire il voto numero %d: ", i+1);
            scanf("%d",&temp);
            fflush(stdin);
        }while(!(temp >= 0 || temp <= 10));
        //aumento della somma
        somma += temp;
    }
    //calcolo della media
    somma /= numero_studenti;
    printf("La media e' %.1f : ",somma);
    //con una serie di if/else if si controlla il valore della somma.
    if(somma < 6){
        printf("MEDIA INSUFFICIENTE");
    }
    else if(somma >= 6 && somma <7){
        printf("MEDIA SUFFICIENTE" );
    }
    else if(somma >= 7 && somma <8){
        printf("MEDIA DISCRETA");
    }
    else if(somma >= 8 && somma < 9){
        printf("MEDIA BUONA");
    }
    else if(somma >= 9 && somma <= 10){
        printf("MEDIA OTTIMA");
    }

}
