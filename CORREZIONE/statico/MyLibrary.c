#include <stdio.h>
#include <stdlib.h>
#include "MyLibrary.h"

void StampaLista(int vettore[],int dim)
{
    int count = 0;
    for(int i=0;i<dim;i++)//stampa elementi del vettore
    {
        if (vettore[i]!=0)
        {
            printf("\nCella %d valore: %d",i,vettore[i]);
            count++;
            continue;
        }
        else
            continue;
    }
    if (count == 0)//se non ci sono elementi dice che il vettore è vuoto
    {
        printf("\n\nLa lista e\' vuota!\n\n");
        return;
    }
    else
    {
        printf("\n\nStampati %d valori\n ",count);//numero di valori stampati
    }
}

void InserisciInTesta (int vettore[],int dim,int numero, int elementiAggiunti)
{
    int i=0;
    int contat=0;
    for(i=0;i<dim;i++)//controllo che il numero di elementi non superi il limite massimo
    {
        if (vettore[i]==0)
        {
            continue;
        }
        else if (vettore[i]!=0)
        {
            contat++;
        }
    }
    if (contat==dim)
    {
        printf("Impossibile Inserire ulteriori elementi, limite massimo di elementi raggiunto!\n");
        return;
    }

    if (vettore[i]==0)//se il primo elemento è uguale a 0 lo sostituisce con il numero
    {
        vettore[i]=numero;
    }
    else if(vettore[i]!=0)//se no fa scorrere gli altri elementi di una posizione
        {
            for(i=elementiAggiunti;i>=0;i--)
            {
                vettore[i]=vettore[i-1];
            }
        }
    i=0;
    vettore[i]=numero;//da al primo elemento liberato il valore del numero
    return;
}

void InserisciInCoda (int vettore[],int dim,int numero,int elementiAggiunti)
{
    int i=0;
    int contat=0;
    for(i=0;i<dim;i++)//controllo che il numero di elementi non superi il limite massimo
    {
        if (vettore[i]==0)
        {
            continue;
        }
        else if (vettore[i]!=0)
        {
            contat++;
        }
    }
    if (contat==dim)
    {
        printf("Impossibile Inserire ulteriori elementi, limite massimo di elementi raggiunto!\n");
        return;
    }

    if (vettore[elementiAggiunti]==0)//aggiunge all'ultima posizione il nuovo numero
    {
        vettore[elementiAggiunti]=numero;
    }
    return;
}

void InserisciDopoElemento(int vettore[],int dim,int numero,int elemento)
{
    int i=0;
    int contat=0;
    for(i=0;i<dim;i++)//controllo che il numero di elementi non superi il limite massimo
    {
        if (vettore[i]==0)
        {
            continue;
        }
        else if (vettore[i]!=0)
        {
            contat++;
        }
    }
    if (contat==dim)
    {
        printf("Impossibile Inserire ulteriori elementi, limite massimo di elementi raggiunto!\n");
        return;
    }
    for(i=0;i<dim;i++)//conta il numero di elementi prima della ricorrenza da noi cercata
    {
        if (vettore[i]==elemento)
        {
            break;
        }
        else
            contat++;
    }
    for(i=dim;i>contat+1;i--)//sposta di una posizione gli elementi dopo quella ricorrenza
    {
        vettore[i]=vettore[i-1];
    }
    for(i=0;i<dim;i++)//dal allo spazio dopo la ricorrenza il valore desiderato
    {
        if (vettore[i]==elemento)
        {
            vettore[i+1]=numero;
            break;
        }
    }

}

void CancellaDallaTesta(int vettore[],int dim)
{
    int contat=0;
    int i=0;

    for(i=0;i<dim;i++)//conta il numero di elementi nel vettore
    {
        if(vettore[i]!=0)
        {
            contat++;
        }
    }
    if (contat==0)//se non ci sono elementi stampa il messaggio
    {
        printf("\nNessun elemento da eliminare!\n");
        return;
    }

    for(i=0;i<dim;i++)//pone a 0 il primo elemento incontrato
    {
        if (vettore[i]!=0)
        {
            vettore[i]=0;
            break;
        }
    }
    return;

}

void CancellaDallaCoda(int vettore[],int dim)
{
    int contat=0;
    int i=0;

    for(i=0;i<dim;i++)//conta il numero di elementi nel vettore
    {
        if(vettore[i]!=0)
        {
            contat++;
        }
    }
    if (contat==0)//se non ci sono elementi stampa il messaggio
    {
        printf("\nNessun elemento da eliminare!\n");
        return;
    }
    vettore[contat-1]=0;//pone a 0 l'ultimo elemento

    return;
}
void CancellaOccorrenza(int vettore[],int dim,int numero)
{
    int contat=0;
    int i=0;

    for(i=0;i<dim;i++)//conta il numero di elementi nel vettore
    {
        if(vettore[i]!=0)
        {
            contat++;
        }
    }
    if (contat==0)//se non ci sono elementi stampa il messaggio
    {
        printf("\nNessun elemento da eliminare!\n");
        return;
    }
    for(i=0;i<dim;i++)//pone a 0 la prima occorrenza
    {
        if (vettore[i]==numero)
        {
            vettore[i]=0;
            return;
        }
    }
    printf("\nElemento non presente nel vettore!");//se non è presente l'elemento che si vuole azzerare stampa questo messaggio
    return;

}

