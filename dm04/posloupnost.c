#include <stdio.h>

int main(void)
{
     printf("Posloupnost:\n");
    int suma[2000000];
    int vstup[2000];
    int i = 0;
    int l = 0;
    int delka = 2;
    int start = 0;
    int vypocet = 0;
    while (scanf("%d", &vstup[i]) != EOF)
    {

        if (vstup[i] == 0)
        {
            printf("Nespravny vstup.\n");
            return 0;
        }
        if (i == 1999)
        {
            printf("Nespravny vstup.\n");
            return 0;
        }

        i++;
    }
    if (i == 0)
    {
        printf("Nespravny vstup.\n");
        return 0;
    }
    // spocitani sumy
c

    vypocet = 0;
    int finale = 0;
    for (int m = 0; m < l; m++)
    {
        start = m;
        vypocet = start + 1;
        while (vypocet < l)
        {
            if (suma[start] == suma[vypocet])
            {
                finale++;
            }

            // printf("%d == %d\n", suma[start], suma[vypocet]);
            // printf("%d === %d\n", vypocet, l-1);
            vypocet++;
        }
    }

    printf("Pocet dvojic: %d\n", finale);
    return 0;
}