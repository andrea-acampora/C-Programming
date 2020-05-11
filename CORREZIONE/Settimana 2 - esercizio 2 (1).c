#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Dichiarazione delle variabili
    int numero_studenti,voto_studenti,conto_studenti,somma_voti,numero_materie,conto_voti,voto_max;
    float media_voti;
    somma_voti= 0;
    voto_max=10;

    // Richiesta input valore variabile numero_studenti
    printf(" Quanti studenti fanno parte della classe? ");
    scanf("%d",&numero_studenti);
    fflush(stdin);
    printf("\n Il numero di studenti della classe e\' %d\n\n",numero_studenti);

    // Richiesta input valore variabile numero_materie
    printf(" Quante materie si insegnano in classe? ");
    scanf("%d",&numero_materie);
    fflush(stdin);
    printf("\n Il numero di materie insegnate in classe e\' %d\n\n",numero_materie);

    // Richiesta input valore variabile voto_studenti per ciascuna materia
    printf(" Assegna un voto a ciascuno dei %d studenti della classe per ognuna delle materie insegnate\n",numero_studenti);


    for(conto_studenti=1;conto_studenti<=numero_studenti;conto_studenti++)  // Primo ciclo for per il numero di studenti della classe
        {

        conto_voti=1;
        while(conto_voti<=numero_materie)                       // Secondo ciclo  while per il numero di voti per ciascuna materia
            {

            printf(" Il voto %d dello studente %d e\': ",conto_voti,conto_studenti);
            scanf("%d",&voto_studenti);
                if(voto_studenti<=0 || voto_studenti>voto_max) // Controllo sull'input dell'utente per accertarsi che il voto inserito sia valido
                    {
                    printf(" Voto non valido\n");
                    conto_voti--;                           // Valore inserito non valido: il ciclo deve riprendere dal punto in cui è stato interrotto
                    somma_voti-=voto_studenti;              // Il valore inserito non valido non deve essere aggiunto alla somma_voti e perciò lo si sottrae dal conto
                    }
            conto_voti++;
            somma_voti+=voto_studenti;                              // In questo passaggio la somma totale dei voti non tiene del numero di materie insegnate
            }
        fflush(stdin);
        }

    // Calcolo della media dei voti della classe e stampa a video

    numero_studenti*= numero_materie;                               // Questa operazione è necessaria perché nel calcolo della media bisogna tenere conto del numero di materie insegnate
    media_voti= (float)somma_voti/numero_studenti;
    printf("\n La media e\': %.1f\n\n",media_voti);

    // Commento sull'andamento della classe in base alla media dei voti

    if(media_voti<6) {
        printf(" Media insufficiente\n");
    }
    else if (media_voti>=6 && media_voti<7) {
        printf(" Media sufficiente\n");
    }
    else if (media_voti>=7 && media_voti<8) {
        printf(" Media discreta\n");
    }
    else if (media_voti>=8 && media_voti<9) {
        printf(" Media buona\n");
    }
    else if (media_voti>=9 && media_voti<=10) {
        printf(" Media ottima\n");
    }

    return 0;
}
