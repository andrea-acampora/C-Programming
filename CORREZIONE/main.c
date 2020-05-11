#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int main()
{
    /**definizione delle variabili*/
    int     i;
    float   f;
    double  d;
    char    c;
    int     arr[MAX]={10,20,30,40,50};

    /**valore per visualizzare l'array*/
    int     a;

    /**verifica inserimento valori corretti*/
    int     verificai;
    float   verificaf;
    double  verificad;
    char    verificac;

    /**definizione dei puntatori*/
    int     *pi;
    float   *pf;
    double  *pd;
    char    *pc;
    int     *parr;

    /**assegnazione dei puntatori alle variabili*/
    pi=     &i;
    pf=     &f;
    pd=     &d;
    pc=     &c;
    parr=   &arr[0];

    /**richiesta inserimento di valori per le variabili*/
    /*intero*/
    printf("Inserire un numero intero:");
    verificai=scanf("%d",&i);
    fflush(stdin);
    if (verificai!=1)
    {
        printf("\nErrore...Il valore inserito non risulta un intero...Chiusura del programma in corso\n\n");
        exit(1);
    }

    /*float*/
    printf("Inserire un numero float:");
    verificaf=scanf("%f",&f);
    fflush(stdin);
    if (verificaf!=1)
    {
        printf("\nErrore...Il valore inserito non risulta un float...Chiusura del programma in corso...\n\n");
        exit(1);
    }

    /*double*/
    printf("Inserire un numero double:");
    verificad=scanf("%lf",&d);
    fflush(stdin);
    if (verificad!=1)
    {
        printf("\nErrore...Il valore inserito non risulta un double...Chiusura del programma in corso...\n\n");
        exit(1);
    }

    /*char*/
    printf("Inserire un char:");
    verificac=scanf("%c",&c);
    fflush(stdin);
    if (verificac!=1)
    {
        printf("\nErrore...Il valore inserito non risulta char...Chiusura del programma in corso...\n\n");
        exit(1);
    }

    /**visualizzazione a schermo dei valori in modo diretto e indiretto(tramite puntatori)*/
    /*intero*/
    printf("\n\nIl valore visualizzato in modo diretto dell'intero e\':%d\n",i);
    printf("Il valore visualizzato in modo indiretto dell'intero e\':%d\n",*pi);

    /*float*/
    printf("\n\nIl valore visualizzato in modo diretto del float e\':%f\n",f);
    printf("Il valore visualizzato in modo indiretto del float e\':%f\n",*pf);

    /*double*/
    printf("\n\nIl valore visualizzato in modo diretto del double e\':%lf\n",d);
    printf("Il valore visualizzato in modo indiretto del double e\':%lf\n",*pd);

    /*char*/
    printf("\n\nIl valore visualizzato in modo diretto del char e\':%c\n",c);
    printf("Il valore visualizzato in modo indiretto del char e\':%c\n",*pc);

    /*array*/
    printf("\n\nIl valore visualizzato in modo diretto dell'array e\':");
    for(a=0;a<MAX;a++)
        printf(" %d",arr[a]);
    printf("\nIl valore visualizzato in modo indiretto dell'array e\':");
    for(a=0;a<MAX;a++)
        printf(" %d",parr[a]);


    /**posizione di memoria dei vettori senza e tramite l'utilizzo dei puntatori*/
    /*intero*/
    printf("\n\nLa posizione in memoria dell'intero visualizzata in modo diretto e\':%p\n",&i);
    printf("La posizione in memoria dell'intero visualizzata in modo indiretto e\':%p\n",&*pi);

    /*float*/
    printf("\nLa posizione in memoria del float visualizzata in modo diretto e\':%p\n",&f);
    printf("La posizione in memoria del float visualizzata in modo indiretto e\':%p\n",&*pf);

    /*double*/
    printf("\nLa posizione in memoria del double visualizzata in modo diretto e\':%p\n",&d);
    printf("La posizione in memoria del double visualizzata in modo indiretto e\':%p\n",&*pd);

    /*char*/
    printf("\nLa posizione in memoria del char visualizzata in modo diretto e\':%p\n",&c);
    printf("La posizione in memoria del char visualizzata in modo indiretto e\':%p\n",&*pc);

    /*array*/
    printf("\nLe posizioni in memoria dei valori contenuti nell'array visualizzate in modo diretto sono:\n");
    for(a=0;a<MAX;a++)
        printf(" %p",&arr[a]);
    printf("\nLe posizioni in memoria dei valori contenuti nell'array visualizzate in modo indiretto sono:\n");
    for(a=0;a<MAX;a++)
        printf(" %p",&parr[a]);

    /**posizioni in memoria dei puntatori*/
    /*intero*/
    printf("\n\nLa posizione in memoria del puntatore per l'intero e\':%p\n",&pi);

    /*float*/
    printf("\nLa posizione in memoria del puntatore per il float e\':%p\n",&pf);

    /*double*/
    printf("\nLa posizione in memoria del puntatore per il double e\':%p\n",&pd);

    /*char*/
    printf("\nLa posizione in memoria del puntatore per il char e\':%p\n",&pc);

    /*array*/
    printf("\nLe posizioni in memoria del puntatore per l'array e\':%p\n",&parr);

    /**fine*/
    printf("\n\n");

    return 0;
}
