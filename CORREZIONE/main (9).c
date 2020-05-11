#include <stdio.h>
#include <stdlib.h>

int num_primi[10];

int *numeri_primi(int num)
{
    int ris, i, j=0, *p_num_primi;
    p_num_primi=num_primi;

    for (i=2; i<=num; i++)
    {
        if (i%2==0)
        {
            continue;
        }
        else
        {
            do
            {
                for (int div=3; div<=i/2; div+2)
                {
                    ris=i/div;

                    if (i%div==0)
                    {
                        break;
                        break;
                    }
                }

            } while (ris>div);

            num_primi[j]=i;
            j++;
        }
    }

    return (*p_num_primi);
}

int main()
{
    int num, i;

    printf("\n  Inserisci il numero entro cui vuoi calcolare tutti i numeri primi: ");
    scanf("%d", &num);
    fflush(stdin);

    num_primi[0]=numeri_primi(num);

    for (i=0; i<10; i++)
    {
        printf("%d", num_primi[i]);
    }

    printf("\n\n");
    system("pause");
    return 0;
}

