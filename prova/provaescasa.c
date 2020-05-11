#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
int random,dir,i,j,riga,colonna,k,p;
char matrice[10][10];
char lettera='A';
srand(time(NULL));
for(riga=0;riga<10;riga++)
{
    for(colonna=0;colonna<10;colonna++)
    {
    matrice[riga][colonna]='.';
    }
}
for(riga=0;riga<10 && lettera !='[';riga++)
{
    for(colonna=0;colonna<10 && lettera!='[' ;colonna++)
{
random=rand()%4+1;
switch(random){
    while(lettera!='[')
{

case 1://sopra
        if(riga>0 && matrice[riga-1][colonna]=='.'){
        matrice[riga-1][colonna]=lettera;
        lettera=lettera+1;
        break;
        }
case 2://sotto
        if(riga<9 && matrice[riga+1][colonna]=='.'){
        matrice[riga+1][colonna]=lettera;
        lettera=lettera+1;
        break;
        }
case 3://destra
        if(colonna<9 && matrice[riga][colonna+1]=='.'){
        matrice[riga][colonna+1]=lettera;
        lettera=lettera+1;
        break;
       }
       random=rand()%4+1;
case 4://sinistra
        if(colonna>0&& matrice[riga][colonna-1]=='.'){
        matrice[riga][colonna-1]=lettera;
        lettera=lettera+1;
        break;
}
}
}
if (matrice[riga+1][colonna]!='.' && matrice[riga-1][colonna]!='.' && matrice[riga][colonna+1]!='.'&& matrice[riga][colonna-1]!='.' )
{
    break;
}

}
}
for(i=0;i<10;i++)
{
    for(j=0;j<10;j++)
    {
        printf("%c",matrice[i][j]);
    }
    printf("\n");
}
system("pause");
return 0;
}
