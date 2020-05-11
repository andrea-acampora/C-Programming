#include <stdio.h>
#include <stdlib.h>

int ConversioneSemplice(int, short *);
void ComplementoA2(short *, int);

int main()
{
    int input;  //input dell'utente
    char segno; //+ o -
    char ok = 0;

    while(!ok)
    {   //chiedo un valore finche' non ne viene inserito uno valido
        printf("inserire un numero intero: ");
        ok = scanf("%d", &input);
        fflush(stdin);

        if(!ok) //se il valore non e' valido
            printf("numero inserito non valido!");
    }

    //controllo il segno dell'input
    if(input >= 0)
            segno = 0; //piu'
    else
    {   //valore assoluto
        segno = 1; //meno
        input = -input;
    }

    int n_max = sizeof(input) * 8;  //creo un vettore grande per contenere un vettore
    short arr[n_max];               //8 serve per convertire da byte a bit
    for(int i = 0; i < n_max; i++)
    {   //inizializzo tutti i valori del vettore a 0. E' necessario per il compl. a 2
        arr[i] = 0;
    }

    //converto il valore da decimale a binario e salvo quanti bit ho usato
    int calcolati = ConversioneSemplice(input, arr); //VEDI METODO IN BASSO

    //output
    printf("numero calcolato: ");
    for (int i = calcolati-1; i >= 0; i--)
    {   //stampo un carattere alla volta dall'ultimo al primo
        printf("%d", arr[i]);
    }

    if(segno == 1)
    {   //se il segno e' negativo calcolo anche il compl. a 2
        ComplementoA2(arr, n_max);  //non salvo quanti bit perche' li usa tutti
        //VEDI METODO IN BASSO
        printf("\ncomplemento a 2: "); //output
        for (int i = n_max-1; i >= 0; i--)
        {
            printf("%d", arr[i]);
        }   /** se il complemento a 2 e' corretto la somma algebrica di n e -n dovrebbe essere 0 */
    }

    getchar(); //aspetto un carattere e poi chiedo
    return 0;//array in cui contengo il numero 1 ed eventuali riporti
}

int ConversioneSemplice(int numero, short * arr)
{
    int i = 0; //variabile di iterazione del ciclo

    while(numero > 0)
    {
        arr[i] = numero % 2;
        numero = numero / 2;
        i++;
    }

    return i; //contiene il numero di cifre binarie prodotte
}

void ComplementoA2(short * arr, int n)
{
    //inverto i valori di ogni bit
    for(int i = 0; i < n; i++)
    {
        arr[i] = arr[i] == 0 ? 1 : 0;
    }

    int tmp;
    short compl[n+1];   //array in cui contengo il numero 1 ed eventuali riporti
    compl[0] = 1; //salvo nella prima cella 1; le seguenti conterranno 0  o 1 in base al riporto

    for(int i = 0; i < n; i++)
    {   //sommo l'array base all'array contenente 1, tenendo conto dei riporti
        tmp = arr[i] + compl[i];

        if(tmp > 1) //controllo i riporti
        {
            tmp = 0;
            compl[i+1] = 1; //riporto nella prossima cifra
        }
        else
        {   //metto 0 altrimenti la cella di memoria conterrebbe un valore indeterminato
            compl[i+1] = 0;
        }
        arr[i] = tmp; // salvo il risultato
    }
}
