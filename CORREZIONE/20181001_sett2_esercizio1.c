
#include <stdio.h>
#include <stdlib.h>

int main()
{
    //inserimento orario in formato 24 ore
    float orarioArr, parteFraz;
    printf("Inserire l'orario di arrivo in formato 24h: ");
    scanf("%f",&orarioArr);
    fflush(stdin);

    //ciclo per il controllo dell'ora inserita
    parteFraz=orarioArr-(int)orarioArr;
    do
    {
        if(((orarioArr<0 || orarioArr>24) && (parteFraz>0.59)) || ((orarioArr<0 || orarioArr>24) || (parteFraz>0.59)))
        {
                printf("Inserire orario valido: \n");
                scanf("%f",&orarioArr);
                fflush(stdin);
        }
        parteFraz=orarioArr-(int)orarioArr;
    }
    while(((orarioArr<0 || orarioArr>24) && (parteFraz>0.59)) || ((orarioArr<0 || orarioArr>24) || (parteFraz>0.59)));


    //serie di if else per la gestione degli orari di partenza PM
   if((orarioArr>=11.19) && (orarioArr<12.47))
    {
        printf("L'orario di partenza del primo volo che e' possibile prendere e' 12.47PM -- 3.00PM\n");
    }
        else
        {
            if((orarioArr>=12.47) && (orarioArr<14.00))
            {
            printf("L'orario di partenza del primo volo che è possibile prendere e' 2.00PM -- 4.08PM\n");
            }
            else
            {
                if((orarioArr>=14.00) && (orarioArr<15.45))
                {
                printf("L'orario di partenza del primo volo che e' possibile prendere e' 3.45PM -- 5.55 PM\n");
                }
                else
                {
                    if ((orarioArr>=15.45) && (orarioArr<19.00))
                    {
                    printf("L'orario di partenza del primo volo che e' possibile prendere e' 7.00PM -- 9.20PM\n");
                    }
                    else
                    {
                        if((orarioArr>=19.00) && (orarioArr<21.45))
                        {
                        printf("L'orario di partenza del primo volo che e' possibile prendere e' 9.45PM -- 11.58PM\n");
                        }
                    }
                }
            }
        }

    //serie di if else per la gestione degli orari AM
    if(orarioArr>=21.45)
    {
    printf("L'orario di partenza del primo volo che e' possibile prendere e' 8.00AM -- 10.16AM\n");
    }
    else
    {
        if(orarioArr<8.00)
        {
        printf("L'orario di partenza del primo volo che e' possibile prendere e' 8.00AM -- 10.16AM\n");
        }
        else
        {
            if((orarioArr>=8.00) && (orarioArr<9.43))
            {
            printf("L'orario di partenza del primo volo che e' possibile prendere e' 9.43AM -- 11.52AM\n");
            }
            else
            {
                if((orarioArr>=9.43) && (orarioArr<11.19))
                {
                printf("L'orario di partenza del primo volo che e' possibile prendere e' 11.19AM -- 1.31PM\n");
                }
            }
        }
    }



    return 0;
}
