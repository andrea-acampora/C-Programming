#include <stdio.h>
#include <stdlib.h>

/* Scrivere un programma C che, preso in ingresso un valore intero n,
ne effettui la conversione nel corrispondente numero binario e lo memorizzi in un vettore.
Se si decide di effettuare limitazioni al valore di ingresso n,
assicurarsi che le stesse siano gestite a livello di programma.
Corredare il programma con gli opportuni commenti. */

  int main()
  {
    int n,i,b,vettore_conversione[10];
    printf("Inserire un numero intero n da convertire in binario (0-500) \n");
    scanf("%d",&n);
    fflush(stdin);
    b=0;
    while (n<=0 || n>500 )
    {
        printf("Numero inserito non corretto\n");
        printf("Inserire numero positivo\n");
        printf("Inserire un numero intero \n");
        scanf("%d",&n);
        fflush(stdin);
    }
    printf("Il binario del numero %d e' ",n);
    while(n!=0)
    {
        //PRENDO IL RESTO DELLA DIVISIONE
       if(n%2==1)
        vettore_conversione[b]=1;
       else
        vettore_conversione[b]=0;
        //CONTINUO LA DIVISIONE
        n=n/2;
        //PASSO AL PROSSIMO ELEMENTO DEL VETTORE
        b++;
    }
    //ESEGUO IL CICLO FOR PER STAMPARE GLI ELEMENTI DEL VETTORE IN ORDINE DECRESCENTE
    for(i=b-1;i>=0;i--)
    printf(" %d",vettore_conversione[i]);
    return 0;
    system("pause");
  }
