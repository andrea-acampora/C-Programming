#include <stdio.h>
#include <stdlib.h>
#define MAX_STUDENTI 20
#define MAX_ESAMI 15
#define NOME 15
#define COGNOME 20

//struttura piano esami contenete il nome dell'insegnamento e il voto corrispondente
typedef struct
{
        char insegnamento[30];
        int voto;
}pianoEsami;

//struttura che memorizza le infomazone dello studente:numero matricola, nome e cognome, anno di immatricolazione, piano di studi
typedef struct
{
    int matricola;
    char nome[NOME];
    char cognome[COGNOME];
    int immatricolazione;
    pianoEsami esame[MAX_ESAMI];

}CLASSE;

int controllaMatricola (CLASSE*stud, int i)
{
    for (int j=0; j<i; j++)//controllo se la matricola è presente nel vettore
    {
        if (stud[i].matricola==stud[j].matricola)
            {
                printf("\n Errore: studente gia\' presente");//messaggio di errore se lo student è già presente
                return 1;
            }
    }
return 0;
}

int inserisciStud (CLASSE*stud, int i)
{
    int verifica, controllo;

    do
    {
        printf("\n Numero matricola %d studente: ", i+1);
        verifica=scanf(" %d", &stud[i].matricola);
        fflush(stdin);
    }
    while (verifica==0);
    controllo=controllaMatricola(stud, i);
    if (controllo==0)
    {
        do
        {
            printf(" Nome %d studente: ", i+1);
            fgets(stud[i].nome, NOME, stdin);
            fflush(stdin);
        }
        while (stud[i].nome[0]=='\n');
        do
        {
            printf(" Cognome %d studente: ", i+1);
            fgets(stud[i].cognome, COGNOME, stdin);
            fflush(stdin);
        }
        while (stud[i].cognome[0]=='\n');
        printf(" Anno di immatricolazione %d studente: ", i+1);
        scanf(" %d", &stud[i].immatricolazione);
        fflush(stdin);
        return 0;
    }
    else return 1;
}

void inserisciMateria (CLASSE*stud, int i, int j)
{
    printf(" Nome %d materia: ", j+1);
    scanf("%s", stud[i].esame[j].insegnamento);
    fflush(stdin);
    printf(" Voto %d materia: ", j+1);
    scanf("%d", &stud[i].esame[j].voto);
    fflush(stdin);
}



int main()
{
    int num, verifica, materie, scelta, matricola, trovato, controllo; //dichiarazione variabili

    //inserimento da tastiera del numero di studenti da inserire inizialmente, con controllo che il valore in input sia un numero>=0.
    do
    {
        printf("\n QUANTI STUDENTI VUOI INSERIRE?\n");
        verifica=scanf(" %d", &num);
        fflush(stdin);
    }while (verifica==0 || num<0);
    //controllo che il vettore possa contenere il numero di studenti inserito da tastiera, altrimenti termino il programma

    if (num>MAX_STUDENTI)
    {
        printf("\nRIPROVARE,TROPPI STUDENTI\n");
        exit(1);
    }
    //inserimento da tastiera del numero di materie da inserire inizialmente, con controllo che il valore in input sia un numero>=0.
    do
    {
        printf("\nQUANTE MATERIE VUOI INSERIRE? (MAX %d)", MAX_ESAMI);
        verifica=scanf(" %d", &materie);
        fflush(stdin);
    }while (verifica==0 || materie<0);
    //controllo che il vettore possa contenere il numero di esami inserito da tastiera, altrimenti termino il programma

    if (materie>MAX_ESAMI)
    {
        printf("\n NON E\' POSSIBILE INSERIRE %d ESAMI, MAX %d\n", materie, MAX_ESAMI);
        exit(1);
    }

    CLASSE studente[MAX_STUDENTI]; // dichiaro un vettore di strutture CLASSE che memorizzi le informazioni degli studenti
    CLASSE*pStud=studente;
pStud=(CLASSE*)malloc(10*sizeof(CLASSE));
    for (int i=0; i<num; i++) //per ogni studente vengono inserite le informazioni da tastiera
    {
        controllo=inserisciStud(pStud, i);
        if (controllo==1)
            exit (1);
        for (int j=0; j<materie; j++)
        {
            inserisciMateria (pStud, i, j);
        }
        printf("\n");
    }

    system("cls"); // "pulizia"dello schermo

    /* menu, in base al numero inserito da tastiera il programma permette di:
    1:Aggiungere un nuovo studente stampando un messaggio di errore se lo studente è già
    presente (individuato dalla matricola) o se il vettore è pieno.
    2:Inserire numero di matricola per stampare le informazioni dello studente
    oppure un messaggio di errore se la matricola non è presente nel vettore
    3:Modificare le informazioni del piano di studi aggiungendo un voto con
    messaggio di errore se la matricola non è presente nel vettore o se il vettore pianoEsami è pieno.
    4:Uscita dal ciclo do-while e terminazione del programma*/
    do
    {

        printf("\n 1:AGGIUNGERE NUOVO STUDENTE\n 2:STAMPA INFO STUDENTE DA N° MATRICOLA\n 3:MODIFICA DEL PIANO DI STUDI\n 4:USCIRE DAL PROGRAMMA\n");
        printf(" >");
        verifica=scanf(" %d", &scelta);

        switch(scelta)
        {
            //scelta==1:
            case(1):if (num+1<=MAX_STUDENTI) //se c'è spazio nel vettore di strutture
                    {
                        controllo=inserisciStud(pStud, num);
                        if (controllo==1)
                        {
                            exit (1);
                        }

                            for (int j=0; j<materie; j++)
                            {
                                inserisciMateria(pStud, num, j);
                            }
                            printf("\n");
                        num=num+1;
                    }
                    else
                    pStud=(CLASSE*)realloc(pStud->matricola,2*sizeof(CLASSE));
                    //se invece il vettore è pieno stampo un messaggio di errore
                    system("cls");// "pulizia"dello schermo
                    break;
            //scelta==2:
            case(2):printf("\n Inserisci il numero di matricola: ");//inserimento da tastiera della matricola dl uno studente
                    scanf("%d", &matricola);
                    fflush(stdin);
                    trovato=0;
                    for (int i=0; i<num; i++)//controllo se la matricola è presente nel vettore
                        {
                            if (matricola==studente[i].matricola)//se è presente
                                {
                                    trovato=1;//pongo la variabile trovato==1 per indicare che la matricola è presente e stampo tutte le informazione relative a quello studente
                                    printf("\n Numero matricola: %d", studente[i].matricola);
                                    printf("\n Nome: %s Cognome: %s", studente[i].nome, studente[i].cognome);
                                    printf(" Anno di immatricolazione: %d\n", studente[i].immatricolazione);
                                    for (int j=0; j<materie; j++)
                                    {
                                        printf("\n Materia: %s", studente[i].esame[j].insegnamento);
                                        printf("\n Voto: %d\n", studente[i].esame[j].voto);
                                    }
                                }
                        }
                    if (trovato==0)//se invece non è presente stampo un messaggio di errore
                        printf("\n Errore:studente non presente\n\n");
                    system("pause");
                    system("cls");// "pulizia"dello schermo
                    break;
            //scelta==3:
            case(3):printf("\n Inserisci il numero di matricola: ");//inserimento da tastiera della matricola dl uno studente
                    scanf("%d", &matricola);
                    trovato=0;
                    for (int i=0; i<num; i++)//controllo se la matricola è presente nel vettore
                        {
                            if (matricola==studente[i].matricola)//se è presente
                            {
                                trovato=1;
                                if (materie+1<=MAX_ESAMI)//se il vettore pianoEsami non è pieno
                                {   //stampo le informazioni dello studente
                                    printf("\n Numero matricola: %d", studente[i].matricola);
                                    printf("\n Nome: %s\n Cognome: %s", studente[i].nome, studente[i].cognome);
                                    printf("\n Anno di immatricolazione: %d\n", studente[i].immatricolazione);
                                    //inserimento del nuovo voto
                                    inserisciMateria(pStud, i, materie);

                                    materie=materie+1;//incremento il numero di materie
                                }
                                else//se il vettore pianoEsami è pieno stampo un messaggio di errore
                                    printf("\n Errore: spazio insufficiente per inserire un altro voto\n");
                            }
                        }
                    if (trovato==0)//se la matricola non è presente nel vettore non è presente stampo un messaggio di errore
                        printf("\n Errore:studente non presente\n\n");

                    system("pause");
                    system("cls");// "pulizia"dello schermo
                    break;
            //scelta==4:
            case(4):break;//esco dal ciclo
            //se l valore inserito è diverso da 1,2,3,4:
            default:printf("\n IL VALORE INSERITO NON E\' VALIDO\n"); break;
        }

    }while (scelta!=4 && verifica==1); //se scelta==4 o se il valore non è un numero esco dal ciclo

    return 0;
}
