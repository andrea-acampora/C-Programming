/* Find the first flight from a list of available */

#include <stdlib.h>
#include <stdio.h>

#define NUMFLIGHTS 10
    struct voli{
        int hh;
        int mm;
    }list[NUMFLIGHTS];
int main()
{
    struct voli flights[NUMFLIGHTS];
    /* List of available flights */
    int i, j, index,timeInput, timeFirst, hhfirst, mmfirst;
    char point;

    /* times of available flights:
    hh.mm
    08:15 ->
    09:30
    10:45
    12:00
    13:15
    14:30
    15:45
    17:00
    18:15
    19:30
    */
    flights[0].hh=(8*60)+15;
    flights[1].hh=(9*60)+30;
    flights[2].hh=(10*60)+45;
    flights[3].hh=(12*60)+0;
    flights[4].hh=(13*60)+15;
    flights[5].hh=(14*60)+30;
    flights[6].hh=(15*60)+45;
    flights[7].hh=(17*60)+0;
    flights[8].hh=(18*60)+15;
    flights[9].hh=(19*60)+30;

    /* Print the list of available fights */
    printf("List of available flights:\n");
    for (i=0; i<NUMFLIGHTS; i++)
    {
        hhfirst = flights[i].hh/60;
        mmfirst = flights[i].hh%60;
        printf("\tFlight %2d: %02d.%02d\n", i+1, hhfirst, mmfirst);
    }

    /* Ask the time to the user */
    printf("\nInsert the time of the arrival at the airport in the format hh.mm (24-hours):\n");
    scanf("%2d%c%2d", &flights[i].hh, &point, &flights[i].mm);
    timeInput = (flights[i].hh*60)+flights[i].mm;

    /* Find the first flight available */
    index = 0;
    timeFirst = flights[0].hh;
    for (i=0; i<NUMFLIGHTS; i++)
    {
        if (timeInput < flights[i].hh)
        {
            index = i;
            timeFirst = flights[i].hh;
            break;
        }
    }
    hhfirst = flights[i].hh/60;
    mmfirst = flights[i].mm%60;

    printf("\nThe first flight available leaves at: %02d.%02d\n", hhfirst, mmfirst);
    printf("\nThe following flights available leave at:\n");
    for (i=index+1; i<NUMFLIGHTS; i++)
    {
        hhfirst = flights[i].hh/60;
        mmfirst = flights[i].mm%60;
        printf("\t%02d.%02d\n", hhfirst, mmfirst);
    }

	printf("\n\n");
    system("PAUSE");
    return 0;
}
