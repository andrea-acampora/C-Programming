#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
/*
    Spiegazione:
    Scrivere un programma C che generi un “cammino casuale” all’interno di una matrice 10x10.
    La matrice conterrà dei caratteri (inizialmente saranno tutti ‘.’).
    Il programma deve passare casualmente da un elemento all'altro, muovendosi in alto, in basso,
    a sinistra o a destra di una posizione soltanto.
    Gli elementi visitati dal programma dovranno essere etichettati con lettere che vanno dalla A alla Z
    nell'ordine con cui vengono visitati.

    Suggerimento:
    generare un numero casual fra 0 e 3 indicante la direzione della prossima mossa.
    Prima di effettuare la mossa controllare che:
       - Non vada fuori dalla matrice
       - Non porti ad un elemento al quale è già stata assegnata una lettera.

    Se una delle due condizioni viene violata, provate a muovervi in un’altra direzione. Se tutte le direzioni sono bloccate, il programma deve terminare.
*/
int main()
{
    //Dichiarazione variabili
    char letteraAttuale=65; //Nella tabella ASCII il 65 corrisponde alla A e il 90 alla lettera Z
    bool mossaValida=true; //Variabile che memorizza la validita della mossa generata
    int mossa=0; //Variabile che memorizza la mossa generata
    int rigaAttuale=0; //Riga attuale di gioco
    int colonnaAttuale=0; //Colonna attuale di gioco
    bool mosseProvate[4]={0}; //Vettore che inizializzo a tutti false che mi contine tutte le mosse provate. Ogni indice corrisponde ad una mossa (da 0 a 3) che se provate verranno impostate a true.
    bool giocoTerminato=false; //Variabile che determina la fine del gioco
    char matriceGioco[10][10]; //Matrice di gioco


    //Inizializzo la matrice di gioco a tutti '.'
    for(int i=0;i<10;i++) //Passo tutte le righe della matrice
    {
        for(int j=0;j<10;j++) //Passo tutte le colonne
        {
            if(i==0 && j==0) //Il primo elemento lo imposto ad A
            {
                matriceGioco[0][0]='A';
                continue;
            }
            matriceGioco[i][j]='.'; //Tutti gli altri a .
        }
    }

    //Imposto il seed della generazione pseudocasuale dei numeri
    srand((unsigned int)time(NULL));


    //Ciclo di gioco
    do
    {
        mossa=rand() % 4; //Genero un numero da 0 a 3
        if(mosseProvate[mossa]==true) //Verifico se la mossa sia gia' stata provata
        {
            continue; //Mossa già provata ne genero un'altra
        }
        mossaValida=true; //Resetto la variabile mossaValida a true
        mosseProvate[mossa]=true; //Imposto la mossa generata come Provata all'interno del vettore

        //Controllo la validita della mossa generata
        //Commento dettagliatamente la prima mossa, dopodichè le altre sono simili
        switch(mossa)
        {
            case 0:
                //Mossa 0=muovi in alto
                if(rigaAttuale - 1<0) //Controllo che non esca dalla matrice
                {
                    mossaValida=false; //Se esce dalla matrice, mossa non valida.
                    break; //Esco dallo switch
                }
                else
                {
                    if(matriceGioco[rigaAttuale-1][colonnaAttuale]=='.') //Se la casella di destinazione e' un puntino allora la mossa è valida
                    {
                        rigaAttuale--; //Eseguo la mossa impostando l'indice attuale
                    }
                    else //Altrimenti significa che la casella è occupata percio' la mossa non è valida.
                    {
                        mossaValida=false;
                    }
                }
            break;

            case 1:
                //Mossa 1=muovi in basso
                if(rigaAttuale + 1>=10) //Controllo che non esca dalla matrice
                {
                    mossaValida=false;
                    break;
                }
                else
                {
                    if(matriceGioco[rigaAttuale+1][colonnaAttuale]=='.') //Se la casella di destinazione e' un puntino allora la mossa è valida
                    {
                        rigaAttuale++;
                    }
                    else
                    {
                        mossaValida=false;
                    }
                }
            break;

            case 2:
                //Mossa 2=muovi a destra
                if(colonnaAttuale + 1>=10) //Controllo che non esca dalla matrice
                {
                    mossaValida=false;
                    break;
                }
                else
                {
                    if(matriceGioco[rigaAttuale][colonnaAttuale+1]=='.') //Se la casella di destinazione e' un puntino allora la mossa è valida
                    {
                        colonnaAttuale++;
                    }
                    else
                    {
                        mossaValida=false;
                    }
                }
            break;

            case 3:
                //Mossa 3=muovi a sinistra
                if(colonnaAttuale - 1<0) //Controllo che non esca dalla matrice
                {
                    mossaValida=false;
                    break;
                }
                else
                {
                    if(matriceGioco[rigaAttuale][colonnaAttuale-1]=='.') //Se la casella di destinazione e' un puntino allora la mossa è valida
                    {
                        colonnaAttuale--;
                    }
                    else
                    {
                        mossaValida=false;
                    }
                }
            break;
        }

        //Se mossaValida è true
        if(mossaValida)
        {
            letteraAttuale++; //Incremento la lettera
            matriceGioco[rigaAttuale][colonnaAttuale]=(char)letteraAttuale; //Setto la lettera nella matrice.

            //Resetto le mosse prova.
            mosseProvate[0]=false;
            mosseProvate[1]=false;
            mosseProvate[2]=false;
            mosseProvate[3]=false;

            //Controllo il raggiungemento della lettera z
            if(letteraAttuale>=90)
            {
                mossaValida=false;
                giocoTerminato=true; //Se raggiungo la z il gioco termina
            }
        }
        else
        {
            //Se la mossa non è valida, controllo se ho già provate tutte le altre mosse, in caso, il gioco termina
            if(mosseProvate[0]==true && mosseProvate[1]==true && mosseProvate[2]==true && mosseProvate[3]==true)
            {
                giocoTerminato=true;
            }
        }

        system("cls"); //Pulisco il terminale (Funziona su Windows)
        //Printo tutte le informazioni delle variabili e la matrice di gioco.
        printf("mossa: %d\n",mossa);
        printf("mossaValida: %d\n",mossaValida);
        printf("giocoTerminato: %d\n",giocoTerminato);
        printf("ULTIMA LETTERA: %c\n",letteraAttuale);
        printf("mosseProvate[0]: %d\n",mosseProvate[0]);
        printf("mosseProvate[1]: %d\n",mosseProvate[1]);
        printf("mosseProvate[2]: %d\n",mosseProvate[2]);
        printf("mosseProvate[3]: %d\n",mosseProvate[3]);
        for(int i=0;i<10;i++)
        {
            for(int j=0;j<10;j++)
            {
                printf("%c\t",matriceGioco[i][j]);
            }
            printf("\n\n");
        }

        //getch();

    }while(giocoTerminato==false); //Finche il gioco non è terminato il ciclo viene eseguito

    if(letteraAttuale!='Z') //Se dopo la fine del gioco la lettera attuale non è z significa che il gioco è terminato in quanto tutte le direzioni erano bloccate.
    {
        printf("\nGioco terminato prima del raggiungimento della lettera Z\n\n");
    }

    getch(); //Funzione più efficiente e portabile di system("pause");
    return 0;
}
