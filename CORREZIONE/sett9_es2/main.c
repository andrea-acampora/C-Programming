#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "mylib.h"

int main()
{
    NodoListaConcatenata lista=NULL;
    char ch=0;
    printf("GESTIONE LIBRI\n\n");
    while(ch!='0')
    {
        printf("Selezionare:\n\n\t1 - Inserire un nuovo libro\n\t2 - Cancellare un libro\n\t3 - Visualizzare tutti i libri\n\t4 - Visualizzare solo i libri con un certo voto");
        ch=getch();
        system("cls");
        switch(ch)
        {

        case '1':
            {
                TipoLista newval;
                int tmp1=1;
                TipoLista tmp[tmp1];
                int index;
                printf("Inserire il nome del libro (MAX 49 caratteri): ");
                fgets(newval.nome, 50, stdin);
                for(index=0; index<50; index++)
                    if(newval.nome[index]=='\r'||newval.nome[index]=='\n')
                        newval.nome[index]='\0';
                printf("Inserisci l'autore (MAX 49 caratteri): ");
                fgets(newval.autore, 50, stdin);
                for(index=0; index<50; index++)
                    if(newval.autore[index]=='\r'||newval.autore[index]=='\n')
                        newval.autore[index]='\0';
                printf("Inserisci la casa editrice (MAX 49 caratteri): ");
                fgets(newval.casa_editrice, 50, stdin);
                for(index=0; index<50; index++)
                    if(newval.casa_editrice[index]=='\r'||newval.casa_editrice[index]=='\n')
                        newval.casa_editrice[index]='\0';
                printf("Inserisci il genere (MAX 49 caratteri): ");
                fgets(newval.genere, 50, stdin);
                for(index=0; index<50; index++)
                    if(newval.genere[index]=='\r'||newval.genere[index]=='\n')
                        newval.genere[index]='\0';
                printf("Inserisci l'anno di pubblicazione: ");
                scanf("%d", &newval.anno_pubb);
                fflush(stdin);
                printf("Inserire l'ID: ");
                scanf("%d", &newval.id);
                fflush(stdin);
                if(Cerca(&lista, newval,tmp ,&tmp1,  ComparebyId))
                {
                    printf("\nLibro inserito %d volte\n", tmp1);
                    system("Pause");
                    break;
                }
                printf("Inserire la valutazione: ");
                scanf("%d", &newval.valutazione);
                fflush(stdin);
                InserisciInCodaCon(&lista, newval);
                break;
            }
        case '2':
            {
                TipoLista val;
                printf("Inserire l'ID del libro da cancellare: ");
                scanf("%d", &val.id);
                fflush(stdin);
                CancellaDopoUnCertoElementoCon(&lista, val, ComparebyId);
                break;
            }
        case '3':
            {
                NodoListaConcatenata tmp=lista;
                while(tmp!=NULL)
                {
                    printf("ID: %d\n", tmp->val.id);
                    printf("Nome: %s\n", tmp->val.nome);
                    printf("Valutazione: %d\n", tmp->val.valutazione);
                    printf("Autore: %s\n", tmp->val.autore);
                    printf("Casa editrice: %s\n", tmp->val.casa_editrice);
                    printf("Genere: %s\n", tmp->val.genere);
                    printf("Anno pubblicazione: %d\n", tmp->val.anno_pubb);
                    tmp= tmp->next;
                }
                system("pause");
                break;
            }
        case '4':
            {
                int dim=50,index=0;
                TipoLista result[dim];
                TipoLista val;
                printf("Inserire la valutazione da cercare: ");
                scanf("%d", &val.valutazione);
                fflush(stdin);
                Cerca(&lista,val, result, &dim, ComparebyValutazione );
                printf("sono stati trovati %d risultati \n", dim);
                if(dim>0)
                {
                    for(index=0; index<dim; index++)
                    {
                        printf("ID: %d\n", result[index].id);
                        printf("Nome: %s\n", result[index].nome);
                        printf("Valutazione: %d\n", result[index].valutazione);
                        printf("Autore: %s\n", result[index].autore);
                        printf("Casa editrice: %s\n", result[index].casa_editrice);
                        printf("Genere: %s\n", result[index].genere);
                        printf("Anno pubblicazione: %d\n", result[index].anno_pubb);
                        printf("\n---------------------------------\n\n");
                    }
                }
                system("pause");
            }
        }
        system("cls");
    }
    return 0;
}
