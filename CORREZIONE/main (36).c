#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_SAFE_INPUT 1000000

int main()
{
    int limit, *prime_list, prime_list_max_size,  prime_list_size, current_number;
    bool valid_input = false, is_prime;
    //acquisisco il valore massimo dall'utente e controllo sia corretto
    while (!valid_input)
    {
        printf("Inserisci un valore fra 1 e %d esclusi: ", MAX_SAFE_INPUT);
        scanf("%d", &limit);
        if (limit>1 && limit < MAX_SAFE_INPUT)
        {
            valid_input = true;
        }
        else
        {
            printf("valore inserito non corretto. Riprova.\n");
        }
    }
    printf("Elaborazione in corso...\n");
    //il vettore dei numeri primi è inizializzato a 10 elementi
    prime_list_max_size = 10;
    prime_list = (int*) malloc(sizeof(int)*prime_list_max_size);
    if (!prime_list)
    {
        printf("Memoria esaurita.");
        return -1;
    }
    prime_list[0] = 2;
    prime_list_size = 1;
    current_number = 3;
    //controllo che il numero su cui sto lavorando sia inferiore al limite
    while (current_number<limit)
    {
        is_prime = true;
        //confronto il numero su cui sto lavorando con i precedenti numeri primi che ho trovato
        for (int i=0; i<prime_list_size; i++)
        {
            if (current_number>=(prime_list[i]*prime_list[i]))
            {
                if (current_number%prime_list[i]==0)
                {
                    is_prime=false;
                    break;
                }
            }
        }
        //se trovo un numero primo, lo aggiungo al vettore ed eventualmente aumento le dimensioni dello stesso
        if (is_prime)
        {
            if (prime_list_size+1>prime_list_max_size)
            {
                prime_list_max_size = prime_list_max_size*2;
                prime_list = (int*) realloc(prime_list, sizeof(int)*prime_list_max_size);
                if (!prime_list)
                {
                    printf("Memoria esaurita.");
                    return -1;
                }
            }
            prime_list[prime_list_size++] = current_number;
        }
        //lavoro sul prossimo numero
        current_number+=2;
    }

    printf("Elaborazione completata.\n");

    for (int i=0; i<prime_list_size; i++)
    {
        printf("%d\n", prime_list[i]);
    }
    return 0;
}
