/*Modificare il programma dell'esercizio 1 in modo che il vettore di studenti venga allocato dinamicamente e successivamente riallocato al suo riempimento.
Inizialmente usare la funzione malloc() per allocare lo spazio sufficiente per un vettore di 10 strutture studente,
Quando il vettore non ha più spazio per contenere nuovi studenti, utilizzare la funzione realloc() per raddoppiare la sua dimensione.
Ripetere il raddoppio delle dimensioni ogni volta che il vettore si riempe.
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct
{
    char insegnamento[21];    //Dichiarazione della struttura degli esami
    int voto;
} NUM_ESAMI;

struct studenti
{
    int matricola;
    char nome[21];      //Dichiarazione della struttura degli studenti
    char cognome[21];
    int anno;
    NUM_ESAMI piano_studi[2];
};

int numero_studenti = 0;    //Variabile globale che tiene conto del numero degli studenti inseriti

struct studenti *stud;

int posizione(int n_studente);  //Funzione che trova uno studente dal numero di matricola
void aggiunta(void);    //Funzione che aggiunge uno studente
void stampa(void);      //Funzione che stampa i dati di uno studente
void modifica(void);    //Funzione che modifica il piano di studi di uno studente

int main()
{
    stud = (struct studenti*) malloc(10 * sizeof(struct studenti));
    if(stud == NULL)
    {
        printf("Memoria terminata!");
        exit(1);
    }
    int azione;
    do
    {
        printf("Cosa vuoi fare? (0: Aggiungere uno studente; 1: Stampare le informazioni di uno studente; 2: Modificare il piano di studi di uno studente; Altri valori per uscire): ");
        scanf("%d", &azione);   //Si fa scegliere all'utente cosa vuole fare

        switch(azione)
        {
            case 0: aggiunta();
                break;
            case 1: stampa();
                break;
            case 2: modifica();
                break;
            default:
                free(stud);
                return 0;
        }
    } while(1);
}

int posizione(int n_studente)
{
    for(int i = 0; i < numero_studenti; i++)
    {
        if(n_studente == (stud + numero_studenti)->matricola)     //Funzione che trova uno studente dal numero di matricola
        {
            return i;   //Restituisce il numero di matricola se lo trova
        }
    }
    return -1;  //Restituisce -1 se non trova niente
}

void aggiunta(void)
{
    int n_matricola, controllo;
    char s_nome;
    if(numero_studenti == 20)   //Se l'array è pieno ritorna alla selezione
    {
        printf("Errore! Raggiunto il limite massimo di studenti inseribili! Provare un'altra funzione...\n");
        return;
    }
    else
    {
        do
        {
            printf("Inserire i dati relativi al nuovo studente: \nNumero di matricola: ");
            controllo = scanf("%d", &n_matricola);
            fflush(stdin);
            if(controllo == 0)
                printf("Formato errato! Reinserire!\n");
        }while(controllo == 0); //Per controllare l'inserimento della matricola
        if(posizione(n_matricola) >= 0)
        {
            printf("Lo studente e' gia' presente all'interno della struttura\n");   //Se la matricola inserita è già presente ritorna alla selezione
            return;
        }
        else    //Altrimenti procede a richiedere l'inserimento dei valori
        {
            (stud + numero_studenti)->matricola = n_matricola;
            printf("La matricola non e' presente; Inserire i dati del nuovo studente\nNome: ");
            fgets((stud + numero_studenti)->nome, 20, stdin);
            fflush(stdin);
            printf("Cognome: ");
            fgets((stud + numero_studenti)->cognome, 20, stdin);
            fflush(stdin);
            do
            {
                printf("Anno di immatricolazione: ");
                scanf("%d", &(stud + numero_studenti)->anno);
                fflush(stdin);
                if((stud + numero_studenti)->anno <= 2000)
                    printf("L'anno di immatricolazione deve essere almeno superiore a 2000\n");
            }while((stud + numero_studenti)->anno <= 2000);

            printf("Inserire il voto del corso di informatica: ");
            scanf("%d", &(stud + numero_studenti)->piano_studi[0].voto);
            printf("Inserire il voto del corso di analisi: ");
            scanf("%d", &(stud + numero_studenti)->piano_studi[1].voto);

            numero_studenti++;  //Aggiorno il numero degli studenti presenti

            if(numero_studenti == 10)
            {
                (struct studenti*) realloc(stud, numero_studenti * 2 * sizeof(struct studenti));
                if(stud == NULL)
                {
                    printf("Memoria terminata!");
                    exit(1);
                }
            }
            return;
        }
    }
}

void stampa(void)
{
    int matr, i, controllo;
    do
    {
    printf("Inserire la matricola che si vuole ricercare: ");
    controllo = scanf("%d", &matr);
    fflush(stdin);
    if(controllo == 0)
        printf("Formato errato! Reinserire!\n");
    }while(controllo == 0); //Per controllare l'inserimento della matricola
    i = posizione(matr);
    if(i == -1)
    {
        printf("Lo studente non e' presente all'interno della struttura\n");   //Se la matricola inserita non è presente nella struttura
        return;
    }
    else    //Se invece viene trovata stampa i vari valori
    {
        printf("Nome studente: %s\n", (stud + i)->nome);
        printf("Cognome studente: %s\n", (stud + i)->cognome);
        printf("Anno di immatricolazione: %d\n", (stud + i)->anno);
        printf("Voto di informatca: %d\n", (stud + i)->piano_studi[0].voto);
        printf("Voto di analisi: %d\n", (stud + i)->piano_studi[1].voto);
        return;
    }
}

void modifica(void)
{
    int matr, i, controllo;
    char materia[21];
    do
    {
    printf("Inserire la matricola che si vuole ricercare: ");
    controllo = scanf("%d", &matr);
    fflush(stdin);
    if(controllo == 0)
        printf("Formato errato! Reinserire!\n");
    }while(controllo == 0); //Per controllare l'inserimento della matricola
    i = posizione(matr);
    if(i == -1)
    {
        printf("Lo studente non e' presente all'interno della struttura\n");   //Se la matricola inserita non è presente nella struttura
        return;
    }
    printf("Di quale corso vuoi modificare il voto? "); //Si richiede il corso su cui si vogliono apportare modifiche
    fgets(materia, 20, stdin);
    if(strcmp(materia, "informatica"))  //Si controlla se il corso inserito sia informatica
    {
        printf("Inserire il nuovo voto della materia informatica: ");
        scanf("%d", &(stud + i)->piano_studi[0].voto);
    }
    else if(strcmp(materia, "analisi"))  //Si controlla se il corso inserito sia analisi
    {
        printf("Inserire il nuovo voto della materia analisi: ");
        scanf("%d", &(stud + i)->piano_studi[1].voto);
    }
    else
        printf("Non esiste un corso per la materia inserita!\n");
    return;
}







