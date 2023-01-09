#include <stdio.h>
#include <math.h>
#include <malloc.h>
int main()
{
    double kreditniurok = 0;
    double debetniurok = 0;
    int den = 0;
    int castka = 1;
    double celkem = 0;
    int predchoziden = 0;
    double poceturoceni = 0;
    char pole;

    printf("Zadejte kreditni urok [%%]:\n");
    scanf("%lf", &kreditniurok);
      if (kreditniurok <= 0)
    {
        printf("Nespravny vstup.\n");
        return 0;
    }

        malloc(sizeof(10));

    kreditniurok = kreditniurok/100;
    // printf("%lf\n", kreditniurok);

    printf("Zadejte debetni urok [%%]:\n");
    scanf("%lf", &debetniurok);
      if (debetniurok <= 0)
    {
        printf("Nespravny vstup.\n");
        return 0;
    }
    debetniurok = debetniurok/100;   
    // printf("%lf\n", debetniurok);
    printf("Zadejte transakce:\n");


    while (castka != 0)
    {
    predchoziden = den;
    castka = 0;   

    
if (scanf("%d, %d", &den, &castka) !=2)
{
       printf("Nespravny vstup.\n");
    return 0;
}


   
    if (den  < predchoziden)
    {
    printf("Nespravny vstup.\n");
    return 0;
    }
    poceturoceni = den - predchoziden;
    if (celkem > 0)
    {
       for (int i = 0; i < poceturoceni; i++)
       {
        celkem += celkem*kreditniurok;
        celkem = celkem * 100;
       celkem = floor(celkem);
        celkem = celkem / 100;
       }
    }else
    {
        for (int i = 0; i < poceturoceni; i++)
       {
        celkem += celkem*debetniurok;
        celkem = celkem * 100;
        celkem = trunc(celkem);
        celkem = celkem / 100;
       }
    }
    celkem = celkem + castka;
    
        
    }
        printf("Zustatek: %.2lf\n",  celkem);
        
    return 0;
}
