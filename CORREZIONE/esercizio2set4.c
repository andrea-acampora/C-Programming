#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DIMENSIONE 30

int main(){
    //istanzio i due vettori per le stinghe
    char stringa1[DIMENSIONE+1],stringa2[DIMENSIONE+1];
    char *puntatore;
    int scelta=0,controllo;
    //lunghezza indica la lunghezza della stringa 2
    int pos_attuale=0,pos_stringa2,tmp_attuale,flag,lunghezza=0;
    //chiedo all'utente di inserire la prima stringa
    printf("Inserisci la prima stringa: ");
    scanf("%30s",stringa1);
    fflush(stdin);

    //chiedo all'utente di inserire la seconda stringa
    printf("Inserisci la seconda stringa: ");
    scanf("%30s",stringa2);
    fflush(stdin);
    //chiedo all'utente in quale modo vuole eseguire l'operazione di sostituzione
    printf("Inserisci in che modo eseguire l'operazione (1 senza <string.h>; 2 con <string.h>): ");
    controllo=scanf("%d",&scelta);
    fflush(stdin);
    if(controllo!=1){
        printf("Errore nell'inserimento.");
        exit(0);
    }
    //esercizio senza l'uso della libreria <string.h>
    if(scelta==1){
        //scorro tutta la stringa1
        while(stringa1[pos_attuale]!='\0'){
            //se il carattere attuale della stringa1 è uguale al primo della seconda stringa, controllo se la stringa2 è contenuta nella stringa1
            if(stringa1[pos_attuale]==stringa2[0]){
                pos_stringa2=0;
                flag=0;
                //uso tmp_attuale per scorrere il vettore senza perdere la posizione attuale
                tmp_attuale=pos_attuale;
                lunghezza=0;
                //scorro tutta la stringa2
                while(stringa2[pos_stringa2]!='\0'){
                    if(stringa1[tmp_attuale]==stringa2[pos_stringa2]){
                        tmp_attuale++;
                        pos_stringa2++;
                        lunghezza++;
                    //se uno dei caratteri della prima string non combacia con uno della seconda, significa che questa porzione di stringa1 non è uguale alla stringa2
                    }else{
                        flag=1;
                        break;
                    }
                }
                //se la porzione di stringa1 combacia con la stringa2, sostituisco la prima lettera in '*' e comprimo la stringa (tolgo i caratteri della corrispondenza che non mi servono)
                if(flag==0){
                    pos_stringa2=0;
                    //il primo carattere della corrispondenza in stringa1 diventa '*'; gli altri vengono sovrascritti
                    stringa1[pos_attuale]='*';
                    tmp_attuale=pos_attuale+1;
                    //lunghezza-- indica di quante posizioni devo spostare indietro i caratteri dopo '*'
                    lunghezza--;
                    //sposto i carattteri successivi ad '*' di lunghezza-1 posizioni indietro (comprimo la stringa)
                    while(stringa1[tmp_attuale+(lunghezza-1)]!='\0'){
                        stringa1[tmp_attuale]=stringa1[tmp_attuale+(lunghezza)];
                        tmp_attuale++;
                    }
                }
            }
            //avanzo di un carattere
            pos_attuale++;
        }
    //utilizzo la libreria <string.h>
    }else if(scelta==2){
        size_t lunghezzaS2=strlen(stringa2);
        //finchè trovo delle corrispondenze
        while(strstr(stringa1,stringa2)!=NULL){
            //la funzione strstr cerca le corrispondenze di parola2 in parola1; se ne trova, restituisce un puntatore che punta al primo carattere della corrispondenza in parola1
            puntatore = strstr(stringa1,stringa2);
            //il primo carattere della corrispondenza in stringa1 diventa '*'; gli altri vengono sovrascritti (il puntatore punta ad una stringa all'interno di un vettore -> non è una stringa letterale)
            *puntatore='*';
            //dopo il carattere '*', scrivo il resto della stringa1 successiva  alla corrispondenza
            strcpy(puntatore+1,puntatore+lunghezzaS2);
        }
    }else{
        printf("Numero inserito sbagliato.");
        exit(0);
    }
    printf("\nRisultato: \n%s\n",stringa1);

    getchar();
    return 0;
}
