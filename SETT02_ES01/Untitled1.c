#include <stdio.h>
#include <stdlib.h>
/*La seguente tabella mostra i voli giornalieri tra due città:
orario partenza -- orario arrivo
8.00 am -- 10.16 am
9.43 am -- 11.52 am
11.19 am -- 1.31 pm
12.47 am -- 3.00 pm
2.00 pm -- 4.08 pm
3.45 pm -- 5.55 pm
7.00 pm -- 9.20 pm
9.45 pm -- 11.58 pm
scrivere un programma che chieda all'utente di immettere il proprio orario di arrivo all'aeroporto
(espresso in ore e minuti utilizzando il formato a 24 ore). Il programma deve visualizzare
 gli orari di partenza e di arrivo  del primo volo che sarà possibile prendere
 (quello il cui orario di partenza è immediatamente successivo rispetto a quello immesso dall'utente).
Es.:
Enter a 24-hour time: 13.15
Closest departure time is 2.00 pm, arriving at 4.08 pm*/
int main()
{
    float orario_arrivo;
        printf("Enter a 24-hour time HH.MM\n");
        scanf("%f",&orario_arrivo);
        if(orario_arrivo>=23.59)
printf("Orario inserito non corretto");
else
{
if (orario_arrivo<=08.00)
    printf("Closest departure time is 08.00 am,arriving at 10.16");
if (orario_arrivo>08.00 && orario_arrivo<=09.43)
    printf("Closest departure time is 09.43, arriving at 11.52");
if (orario_arrivo>09.43 && orario_arrivo<=11.19)
    printf("Closest departure time is 11.19, arriving at 13.31");
if (orario_arrivo>11.19 && orario_arrivo<=12.47)
    printf("Closest departure time is 12.47, arriving at 15.00");
if (orario_arrivo>12.47 && orario_arrivo<=2.00)
    printf("Closest departure time is 14.00, arriving at 16.08");
if (orario_arrivo>02.00 && orario_arrivo<=03.45)
    printf("Closest departure time is 15.45, arriving at 17.55");
if (orario_arrivo>03.45 && orario_arrivo<=07.00)
    printf("Closest departure time is 19.00 pm, arriving at 21.20");
if (orario_arrivo>07.00 && orario_arrivo<=09.45)
    printf("Closest departure time is 21.45, arriving at 23.58");
}
}

