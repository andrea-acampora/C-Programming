/*S8C2
Modificare il programma dell'esercizio 1 in modo che il vettore di studenti venga allocato dinamicamente
e successivamente riallocato al suo riempimento. Inizialmente usare la funzione malloc() per allocare lo spazio
sufficiente per un vettore di 10 strutture studente, Quando il vettore non ha più spazio per contenere nuovi studenti,
utilizzare la funzione realloc() per raddoppiare la sua dimensione. Ripetere il raddoppio delle dimensioni ogni volta che
il vettore si riempe.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NUM_ESAMI 5
#define NUM_STUDENTI 10
#define VOTO_MAX 30
#define VOTO_MIN 18
#define ANNO_MAX 2018
#define ANNO_MIN 1950

typedef struct
{
    char nome_insegnamento[50];
    unsigned int voto;
}ESAME;

struct studente
{
    unsigned int numero_mat;/*indica il numero di matricola di uno stuidente, se vale 0 indica l'assenza di uno studente in quella posizione*/
    char nome[50];
    char cognome[50];
    unsigned int anno_imm;
    ESAME piano_di_studi[NUM_ESAMI];
};

int cont = 1;/*contatore globale che indica la dimenione dell'array dinamico*/

void inizializza_pds_informatica(struct studente *s)
{
    strcpy(s->piano_di_studi[0].nome_insegnamento, "programmazione");
    s->piano_di_studi[0].voto = 0;
    strcpy(s->piano_di_studi[1].nome_insegnamento, "analisi");
    s->piano_di_studi[1].voto = 0;
    strcpy(s->piano_di_studi[2].nome_insegnamento, "fisica");
    s->piano_di_studi[2].voto = 0;
    strcpy(s->piano_di_studi[3].nome_insegnamento, "strutture dati");
    s->piano_di_studi[3].voto = 0;
    strcpy(s->piano_di_studi[4].nome_insegnamento, "algoritmi");
    s->piano_di_studi[4].voto = 0;
}

/*la funzione aggiunge un nuovo studente in una posizione dell'array vuota (con un piano di studi senza voti), ritornando -1 nel caso non ci sia spazio o 1 nel caso sia gia'
presente uno studente con lo stesso numero di matricola (il puntatore a puntatore serve per cambiare l'indirizzo nel main in caso di realloc)*/
int aggiungi_studente(struct studente *classe, struct studente **p, unsigned int n_mat, char *nome, char *cognome, unsigned int anno)//puo' essere usata solo per il controllo con anno = 0;
{
    struct studente *punt;
    unsigned int spazio_vuoto, flag = 0;
    for(int k = 0; k < (NUM_STUDENTI * cont); k++)
    {
        if(classe[k].numero_mat == 0 && flag == 0)/*controllo la presenza di almeno uno spazio libero e salvo il primo spazio libero*/
        {
            spazio_vuoto = k;
            flag = 1;
        }
        if(classe[k].numero_mat == n_mat)/*controllo la presenza di un numero di matricola uguale*/
            return 1;
    }
    if(flag == 0 && anno == 0)/*esco nel caso non ci sia spazio nell'array e stia usando la funzione solo per il controllo*/
        return -1;
    if(anno > 0)/*se anno = 0 la funzione e' usata solo per un controllo*/
    {
        if(flag == 0)
        {
            cont = cont * 2;
            punt = (struct studente*)realloc(classe, sizeof(struct studente) * (NUM_STUDENTI * cont));
            if(punt == NULL)/*controlla eventuali errori di allocazione*/
            {
                printf("Errore di allocazione\n");
                return -1;
            }
            else
            {
                classe = punt;
                *p = punt;/*utilizzo un puntatore di puntatore per cambiare l'indirizzo dell'array anche nel puntatore presente nel main*/
                printf("\nVettore espanso\n");
                spazio_vuoto = NUM_STUDENTI * (cont / 2);
                for(int k = NUM_STUDENTI * (cont / 2); k < NUM_STUDENTI * cont; k++)/*imizializzo tutti i numeri di matricola a 0*/
                    classe[k].numero_mat = 0;
            }
        }
        classe[spazio_vuoto].numero_mat = n_mat;/*salvo il numero di matricola in memoria*/
        strcpy(classe[spazio_vuoto].nome, nome);/*salvo il nome in memoria*/
        strcpy(classe[spazio_vuoto].cognome, cognome);/*salvo il cognome in memoria*/
        classe[spazio_vuoto].anno_imm = anno;/*salvo l'anno in memoria*/
        inizializza_pds_informatica(&classe[spazio_vuoto]);/*inizializzo il piano di studi con le materie del corso*/
    }
    return 0;
}

/*la funzione stampa i dati di uno studente della classe dato il numero di matricola, ritorna -1 se il numero di matricola dato non e' presente*/
int visualizza_studente(struct studente *classe, unsigned int n_mat)
{
    /*controllo che lo studente sia presente nel vettore*/
    unsigned int indice_studente, flag = 0;
    for(int k = 0; k < (NUM_STUDENTI * cont); k++)
        if(classe[k].numero_mat == n_mat)
        {
            indice_studente = k;
            flag = 1;
        }
    if(flag == 0)
        return -1;
    /*stampo nome e anno di immatricolazione*/
    printf("\n");
    printf("Studente: %s %s\n", classe[indice_studente].nome, classe[indice_studente].cognome);
    printf("Immatricolato nell'anno %u\n", classe[indice_studente].anno_imm);
    printf("Esito esami:\n\n");
    /*stampo tutti gli esiti degli esami*/
    for(int k = 0; k < NUM_ESAMI; k++)
    {
        printf("%s\n", classe[indice_studente].piano_di_studi[k].nome_insegnamento);
        if(classe[indice_studente].piano_di_studi[k].voto == 0)
        {
            printf("Esame non conseguito\n\n");
        }
        else
        {
            printf("Voto: %u\n\n", classe[indice_studente].piano_di_studi[k].voto);
        }
    }
    return 0;
}

/*la funzione permette di inserire da terminale un voto per un determinato studente, ritorna -1 se non e' presente il dato studente*/
int inserisci_voto(struct studente *classe, unsigned int n_mat)
{
    /*controllo la presenza dello studente nel vettore*/
    unsigned int indice_studente, flag = 0;
    for(int k = 0; k < (NUM_STUDENTI * cont); k++)
        if(classe[k].numero_mat == n_mat)
        {
            indice_studente = k;
            flag = 1;
        }
    if(flag == 0)
        return -1;
    /*stampo un indice con tutti i possibili esami del piano di studi dello studente*/
    int indice, c;
    printf("\n\n");
    for(int k = 0; k < NUM_ESAMI; k++)
        printf("%d - %s\n",k + 1, classe[indice_studente].piano_di_studi[k].nome_insegnamento);
    /*prendo in input l'esame che voglio valutare*/
    printf("\nInserire l'indice corrispontente all'esame di cui si vuole inserire il voto: ");
    c = scanf("%d", &indice);
    fflush(stdin);
    while(c == 0 || indice < 1 || indice > NUM_ESAMI)
    {
        printf("Input non valido, reinserire l'indice: ");
        c = scanf("%d", &indice);
        fflush(stdin);
    }
    /*inserisco il voto*/
    printf("\nInserire il voto conseguito da %s %s nell'esame di %s (min %d - max %d): ",classe[indice_studente].nome, classe[indice_studente].cognome, classe[indice_studente].piano_di_studi[indice].nome_insegnamento, VOTO_MIN, VOTO_MAX);
    c = scanf("%d", &classe[indice_studente].piano_di_studi[indice].voto);
    fflush(stdin);
    while(c == 0 || classe[indice_studente].piano_di_studi[indice].voto < VOTO_MIN || classe[indice_studente].piano_di_studi[indice].voto > VOTO_MAX)
    {
        printf("Input non valido, reinserire il voto (min %d - max %d): ", VOTO_MIN, VOTO_MAX);
        c = scanf("%d", &classe[indice_studente].piano_di_studi[indice].voto);
        fflush(stdin);
    }
    return 0;
}

/*la funzione permette di rimuovere dal vettore uno studente tramite il suo numero di matricola, se lo studente specificato non e' presente la funzione ritorna -1*/
int rimuovi_studente(struct studente *classe, unsigned int n_mat)
{
    /*imposto il numero di matricola dello studente a 0*/
    unsigned int indice_studente, flag = 0;
    for(int k = 0; k < NUM_STUDENTI * cont; k++)
        if(classe[k].numero_mat == n_mat)
        {
            classe[k].numero_mat = 0;
            flag = 1;
        }
    if(flag == 0)/*se non trovo un numero di matricola corrispondente ritorno -1*/
        return -1;
    return 0;
}

int main()
{
    struct studente *classe;
    classe = (struct studente*)malloc(NUM_STUDENTI * sizeof(struct studente));/*dichiaro dinamicamente il vettore di strutture*/
    for(int k = 0; k < NUM_STUDENTI; k++)/*imizializzo tutti i numeri di matricola a 0*/
        classe[k].numero_mat = 0;
    /*inserisco manualmente quattro studenti, con annessi voti*/
    aggiungi_studente(classe, &classe, 50, "Davide", "Freddi", 2018);
    classe[0].piano_di_studi[0].voto = 30;
    classe[0].piano_di_studi[1].voto = 30;
    classe[0].piano_di_studi[3].voto = 30;
    aggiungi_studente(classe, &classe, 87, "Carlo", "Conti", 2012);
    classe[1].piano_di_studi[0].voto = 24;
    classe[1].piano_di_studi[4].voto = 18;
    aggiungi_studente(classe, &classe, 91, "Fabio", "Fazio", 2015);
    classe[2].piano_di_studi[1].voto = 19;
    classe[2].piano_di_studi[4].voto = 18;
    aggiungi_studente(classe, &classe, 666, "Gerry", "Scotti", 2017);
    /*il ciclo permette di eseguire diverse operazioni fino all'uscita dal programma tramite apposito comando*/
    int indice, c, exit = 0;
    unsigned int n_mat, a_imm;
    char nome[50], cognome[50];
    printf("Registro studenti\n");
    while(!exit)
    {
        /*menu a scelta multipla*/
        printf("----------------Possibili operazioni----------------\n");
        printf("1) Visualizza lista studenti\n");
        printf("2) Aggiungi studente\n");
        printf("3) Rimuovi studente\n");
        printf("4) Visualizza voti studente\n");
        printf("5) Inserisci voto\n");
        printf("6) Esci dal programma\n");
        printf("Scegliere l'operazione da effettuare: ");
        c = scanf("%d", &indice);
        fflush(stdin);
        while(c == 0 || indice < 1 || indice > 6)/*controllo dell'input*/
        {
            printf("Input non valido, reinserire l'indice: ");
            c = scanf("%d", &indice);
            fflush(stdin);
        }
        int flag;
        switch(indice)
        {
        case 1:/*visualizza lista studenti*/
            flag = 0;
            for(int k = 0; k < NUM_STUDENTI * cont; k++)
                if(classe[k].numero_mat != 0)
                {
                    flag = 1;
                    printf("\n%s %s\n", classe[k].nome, classe[k].cognome);
                    printf("Numero matricola: %.6d\n", classe[k].numero_mat);
                }
            if(flag == 0)
                printf("Nessuno studente e' presente nel registro\n");
            printf("\n");
            break;
        case 2:/*Aggiungi studente*/
            printf("\ninserire il numero di matricola del nuovo studente: ");
            c = scanf("%d", &n_mat);
            fflush(stdin);
            while(c == 0 || n_mat < 1 || n_mat > 999999)/*controllo dell'input*/
            {
                printf("Input non valido, reinserire l'indice: ");
                c = scanf("%d", &n_mat);
                fflush(stdin);
            }
            /*controllo che ci sia spazio e che il numero matricola non sia ripetuto prima dell'inserimento dei dati*/
            if(aggiungi_studente(classe, 0, n_mat,"","",0) == 1)
                printf("\nQuesto numero di matricola e' gia' stato utilizzato\n");
            else
            {
                /*inserisco i dati*/
                printf("\nInserire il nome (max 49 caratteri): ");
                scanf("%49s", nome);
                fflush(stdin);
                printf("\nInserire il cognome (max 49 caratteri): ");
                scanf("%49s", cognome);
                fflush(stdin);
                printf("\nInserire l'anno di immatricolazione(valido da %d a %d): ", ANNO_MIN, ANNO_MAX);
                c = scanf("%d", &a_imm);
                fflush(stdin);
                while(c == 0 || a_imm < ANNO_MIN || a_imm > ANNO_MAX)/*controllo dell'input*/
                {
                    printf("Input non valido, reinserire l'anno: ");
                    c = scanf("%d", &a_imm);
                    fflush(stdin);
                }
                aggiungi_studente(classe, &classe, n_mat, nome, cognome, a_imm);/*richiamo la funzione completa*/
            }
            printf("\n");
            break;
        case 3:/*Rimuovi studente*/
            printf("\ninserire il numero di matricola dello studente da rimuovere: ");
            c = scanf("%d", &n_mat);
            fflush(stdin);
            while(c == 0 || n_mat < 1 || n_mat > 999999)/*controllo dell'input*/
            {
                printf("Input non valido, reinserire l'indice: ");
                c = scanf("%d", &n_mat);
                fflush(stdin);
            }
            if(rimuovi_studente(classe, n_mat)== -1)
                printf("\nNon e' presente uno studente con questo numero di matricola\n");
            printf("\n");
            break;
        case 4:/*Visualizza voti studente*/
            printf("\ninserire il numero di matricola dello studente da visualizzare: ");
            c = scanf("%d", &n_mat);
            fflush(stdin);
            while(c == 0 || n_mat < 1 || n_mat > 999999)/*controllo dell'input*/
            {
                printf("Input non valido, reinserire l'indice: ");
                c = scanf("%d", &n_mat);
                fflush(stdin);
            }
            if(visualizza_studente(classe, n_mat) == -1)
                printf("\nNon e' presente uno studente con questo numero di matricola\n\n");
            break;
        case 5:/*Inserisci voto*/
            printf("\ninserire il numero di matricola dello studente da valutare: ");
            c = scanf("%d", &n_mat);
            fflush(stdin);
            while(c == 0 || n_mat < 1 || n_mat > 999999)/*controllo dell'input*/
            {
                printf("Input non valido, reinserire l'indice: ");
                c = scanf("%d", &n_mat);
                fflush(stdin);
            }
            if(inserisci_voto(classe, n_mat) == -1)
                printf("\nNon e' presente uno studente con questo numero di matricola\n\n");
            break;
        case 6:/*esci dal programma*/
            exit = 1;
            break;
        }
    }
    return 0;
}
