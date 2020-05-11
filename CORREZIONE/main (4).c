#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define NUM_STUD 20
#define NUM_ESAMI 1

//Struct per gli esami del piano di studi
typedef struct Esame{
    char insegnante[30];
    int voto;
}Esame;

//Struct per gli studenti
typedef struct Matricola{
    char nMatricola[10];
    char nome[20];
    char cognome[20];
    char annoImmatricolazione[4];
    Esame pianoDiStudi[NUM_ESAMI];
}Matricola;

int main() {

    Matricola array[NUM_STUD];
    int count = 0;
    int scelta1 = 1;
    //Controllo sull'input
    while(true && scelta1 != 0){
        do{
            system("cls");
            printf("1) Aggiungi studente\n2) Cerca studente\n3) Modifica studente\n0) Esci\n\n> ");
            scanf("%d",&scelta1);
        }while(scelta1 < 0 || scelta1 > 3);

        switch (scelta1){
            //AGGIUNTA UTENTE
            case 1: {
                if(count == NUM_STUD){
                    system("cls");
                    printf("Numero massimo di studenti raggiunto!\n");
                    system("pause");
                    system("cls");
                }else{
                    char nMatricola[10];
                    bool flag;
                    //Controllo sull'inserimento del numero matricola
                    do{
                        flag = false;
                        system("cls");
                        printf("Inserisci il numero matricola del nuovo studente (n > 0):\n> ");
                        scanf("%s",nMatricola);
                        int i = 0;
                        for(i = 0;i < count; i++){
                            if(strcmp(array[i].nMatricola, nMatricola) == 0){
                                system("cls");
                                printf("Questo numero matricola e\' gia\' in uso! Inseriscine un altro!\n\n");
                                system("pause");
                                flag = true;
                            }
                        }
                    }while(flag);
                    strcpy(array[count].nMatricola, nMatricola);
                    //Nome
                    system("cls");
                    printf("Inserisci il nome del nuovo studente:\n> ");
                    fflush(stdin);
                    scanf("%s",array[count].nome);

                    //Cognome
                    system("cls");
                    printf("Inserisci il cognome del nuovo studente:\n> ");
                    fflush(stdin);
                    scanf("%s",array[count].cognome);

                    //Anno di immatricolazione
                    system("cls");
                    printf("Inserisci l'anno di immatricolazione del nuovo studente:\n> ");
                    scanf("%s",array[count].annoImmatricolazione);

                    //Piano di studi
                    system("cls");
                    printf("INSERIMENTO DEGLI ESAMI DEL PIANO DI STUDI\n\n\n");
                    int i;
                    //Ciclo per il numero di esami che l'utente deve sostenere
                    for(i = 0; i < NUM_ESAMI; i++){
                        system("cls");
                        printf("Esame N. %d\nInserisci il nome dell'insegnante:\n> ",i+1);
                        fflush(stdin);
                        getchar();
                        fgets(array[count].pianoDiStudi[i].insegnante,30,stdin);
                        system("cls");
                        printf("Inserisci il voto preso all'esame (0 se non e\' stato sostenuto):\n> ");
                        int voto;
                        fflush(stdin);
                        scanf("%d",&array[count].pianoDiStudi[i].voto);
                    }
                    count++;

                    system("cls");
                    printf("Studente aggiunto con successo!\n\n");
                    system("pause");
                }
                break;
            }
                //RICERCA STUDENTE
            case 2: {
                char nMatricola[10];
                system("cls");
                printf("Inserisci il numero matricola dello studente da ricercare:\n> ");
                scanf("%s",nMatricola);
                system("cls");
                int i;
                bool flag = false;
                for(i = 0; i < count; i++){
                    if(strcmp(array[i].nMatricola, nMatricola) == 0){
                        system("cls");
                        printf("Numero matricola: %s\nNome: %s\nCognome: %s\nAnno di immatricolazione: %s\n",array[i].nMatricola,array[i].nome,array[i].cognome,array[i].annoImmatricolazione);
                        int j;
                        puts("\nESAMI DEL PIANO DI STUDI\n");
                        for(j = 0; j < NUM_ESAMI; j++){
                            printf("Esame n. %d)\nNome insegnante: %s\nVoto: %d\n\n",j+1,array[i].pianoDiStudi[j].insegnante,array[i].pianoDiStudi[j].voto);
                        }
                        flag = true;
                    }
                }
                if(!flag){
                    system("cls");
                    printf("Nessuno studente trovato col numero matricola utilizzato!\n\n");
                    fflush(stdin);
                }
                system("pause");
                system("cls");
                break;
            }
                //MODIFICA ESAME
            case 3: {
                char nMatricola[10];
                system("cls");
                printf("Inserisci il numero matricola dello studente da ricercare:\n> ");
                scanf("%s",nMatricola);
                int i;
                bool flag = false;
                for(i = 0; i < count; i++){
                    if(strcmp(array[i].nMatricola, nMatricola) == 0){
                        flag = true;
                        int scelta2 = 0;
                        do{
                            system("cls");
                            printf("Inserisci il numero dell'esame che vuoi modificare(da 0 a %d):\n>  ",NUM_ESAMI-1);
                            scanf("%d",&scelta2);
                        }while(scelta2 < 0 || scelta2 > NUM_ESAMI-1);

                        system("cls");
                        printf("Esame N. %d\nInserisci il nome dell'insegnante:\n> ",scelta2+1);
                        fflush(stdin);
                        getchar();
                        fgets(array[i].pianoDiStudi[scelta2].insegnante,30,stdin);
                        system("cls");
                        printf("Inserisci il voto preso all'esame (0 se non e\' stato sostenuto):\n> ");
                        fflush(stdin);
                        scanf("%d",&array[i].pianoDiStudi[scelta2].voto);
                        system("cls");
                        puts("Esame modificato con successo!\n");
                    }
                }
                if(!flag){
                    system("cls");
                    printf("Nessuno studente trovato col numero matricola utilizzato!\n\n");
                    fflush(stdin);
                }
                system("pause");
                break;
            }

            default:
                break;
        }
    }
    system("cls");
    printf("Arrivederci!\n\n");
    return 0;
}