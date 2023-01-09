#include <stdio.h>
#include <cstring>
#include <strings.h>
#include <malloc.h>
#include <ctype.h>
#include <climits>
typedef struct
{
    int cisloregalu;
    char *item_in_regal;
} item_in_regal;

typedef struct
{
    int cisloseznamu;
    char *item_in_seznam;
    char *item_found;
    int regal_found;
} item_in_seznam;

int main()
{
    char error[] = "N/A";
    size_t pocetitemu = 0;
    int pocetregalu = 0;

    int cislo_seznamu = 0;
    size_t pocet_itemu_na_seznamech = 0;
    int ocislovani_seznamu = -1;
    int kontrola_spravneho_regalu = 0;

    item_in_regal *poleitemu;
    poleitemu = (item_in_regal *)malloc(sizeof(item_in_regal));

    item_in_seznam *poleitemunaseznamech;
    poleitemunaseznamech = (item_in_seznam *)malloc(sizeof(item_in_seznam));

    int item_find = 0;
    char *buffer;
    size_t bufsize = 65535;

    while (1) //načitaní regalu
    {
        char *regal;
        buffer = (char *)malloc(bufsize * sizeof(char));

        fgets(buffer, bufsize, stdin); // načtení řádky
        if (feof(stdin))               // konec souboru
        {
            for (size_t i = 0; i < pocetitemu; i++)
            {
                free(poleitemu[i].item_in_regal);
            }
            free(poleitemu);
            for (size_t i = 0; i < pocet_itemu_na_seznamech; i++)
            {
                free(poleitemunaseznamech[i].item_in_seznam);
            }
            free(poleitemunaseznamech);
            free(buffer);
            printf("Nespravny vstup.\n");
            return 0;
        }
        if (strcmp(buffer, "\n") == 0)
        {
            free(buffer);
            break;
        }
        buffer[strcspn(buffer, "\n")] = 0;

        if (pocetregalu == 0 && strncmp(buffer, "#", strlen("#")) != 0)
        {
            for (size_t i = 0; i < pocetitemu; i++) //uvolnovani každého itemu v poleitemu
            {
                free(poleitemu[i].item_in_regal);
            }
            free(poleitemu);
            for (size_t i = 0; i < pocet_itemu_na_seznamech; i++) // //uvolnovani každého itemu v poleiitemunaseznamech
            {
                free(poleitemunaseznamech[i].item_in_seznam);
            }
            free(poleitemunaseznamech);
            free(buffer);
            printf("Nespravny vstup.\n");
            return 0;
        }

        if (strncmp(buffer, "#", strlen("#")) == 0)
        {
            regal = buffer;
            char *velikost = regal + 1;
            if (!sscanf(velikost, "%d", &kontrola_spravneho_regalu))
            {
                for (size_t i = 0; i < pocetitemu; i++)//uvolnovani každého itemu v poleitemu
                {
                    free(poleitemu[i].item_in_regal);
                }
                free(poleitemu);
                for (size_t i = 0; i < pocet_itemu_na_seznamech; i++)//uvolnovani každého itemu v poleiitemunaseznamech
                {
                    free(poleitemunaseznamech[i].item_in_seznam);
                }
                free(poleitemunaseznamech);
                free(buffer);
                printf("Nespravny vstup.\n");
                return 0;
            }
            if (kontrola_spravneho_regalu != pocetregalu)
            {
                for (size_t i = 0; i < pocetitemu; i++)//uvolnovani každého itemu v poleitemu
                {
                    free(poleitemu[i].item_in_regal);
                }
                free(poleitemu);
                for (size_t i = 0; i < pocet_itemu_na_seznamech; i++)//uvolnovani každého itemu v poleiitemunaseznamech
                {
                    free(poleitemunaseznamech[i].item_in_seznam);
                }
                free(poleitemunaseznamech);
                free(buffer);
                printf("Nespravny vstup.\n");
                return 0;
            }
            pocetregalu++;
            free(buffer);
        }
        else // na vstupu je spravny regal a item
        {
            poleitemu[pocetitemu].cisloregalu = kontrola_spravneho_regalu;
            poleitemu[pocetitemu].item_in_regal = buffer;
            pocetitemu++;
            poleitemu = (item_in_regal *)realloc(poleitemu, (pocetitemu + 1) * sizeof(item_in_regal));
        }
    }
    while (1) //načítaní nákupního seznamu
    {

        // char *buffer;
        buffer = (char *)malloc(bufsize * sizeof(char));
        // fgets(buffer, bufsize, stdin); // načtení řádky

        if (fgets(buffer, bufsize, stdin) == NULL) // prázdná řádka
        {
            free(buffer);
            break;
        }

        if (strcmp(buffer, "\n") == 0) //kontrola prazdne radky mezi seznamy
        {
            cislo_seznamu++;
            free(buffer);
        }
        else
        {
            buffer[strcspn(buffer, "\n")] = 0;
            poleitemunaseznamech[pocet_itemu_na_seznamech].cisloseznamu = cislo_seznamu;
            poleitemunaseznamech[pocet_itemu_na_seznamech].item_in_seznam = buffer;

            pocet_itemu_na_seznamech++;
            poleitemunaseznamech = (item_in_seznam *)realloc(poleitemunaseznamech, (pocet_itemu_na_seznamech + 1) * sizeof(item_in_seznam));
        }

        if (feof(stdin)) // konec souboru -> konec načítaní
        {
            break;
        }
    }
    // free(buffer);


    for (size_t i = 0; i < pocet_itemu_na_seznamech; i++) //hledani produktu zda je v regalech a pak se do struktury zapíše jmeno produktu v regalech a cislo regalu
    {
        item_find = 0;
        for (size_t j = 0; j < pocetitemu; j++) //hledaní produktu v regalu se stejne presnym jmenem
        {
            if (!strcasecmp(poleitemu[j].item_in_regal, poleitemunaseznamech[i].item_in_seznam))
            {
                poleitemunaseznamech[i].regal_found = poleitemu[j].cisloregalu;
                poleitemunaseznamech[i].item_found = poleitemu[j].item_in_regal;
                item_find = 1;
                break;
            }
        }

        if (item_find == 0)
        {
            for (size_t j = 0; j < pocetitemu; j++) // hledani produktu v regalu s jmenem kde nezalezi na velikosti pismen
            {
                if (strcasestr(poleitemu[j].item_in_regal, poleitemunaseznamech[i].item_in_seznam))
                {
                    poleitemunaseznamech[i].regal_found = poleitemu[j].cisloregalu;
                    poleitemunaseznamech[i].item_found = poleitemu[j].item_in_regal;
                    item_find = 1;
                    break;
                }
            }
        }

        if (item_find == 0) //produkt se nekde nenasel
        {
            poleitemunaseznamech[i].regal_found = INT_MAX;
            poleitemunaseznamech[i].item_found = error;
        }
        ocislovani_seznamu++;
    }

    int x;
    if (pocetitemu == 0)
    {
        x = 0;
    }
    else
    {
        x = poleitemu[pocetitemu - 1].cisloregalu;
    }

    int max_seznamu = poleitemunaseznamech[pocet_itemu_na_seznamech - 1].cisloseznamu;
    int max_regalu = x;
    int regal = 0;
    int seznam = 0;
    size_t vypis = 0;
    printf("Optimalizovany seznam:\n");

    while (1) //While cyklus na konečné vypsání seřazeného seznamu
    {
        for (size_t i = 0; i < pocet_itemu_na_seznamech; i++)
        {
            if (seznam == poleitemunaseznamech[i].cisloseznamu && regal == poleitemunaseznamech[i].regal_found)
            {
                if (regal != INT_MAX)
                {
                    printf(" %ld. %s -> #%d %s\n", vypis, poleitemunaseznamech[i].item_in_seznam, poleitemunaseznamech[i].regal_found, poleitemunaseznamech[i].item_found);
                    vypis++;
                }
                else
                {
                    printf(" %ld. %s -> %s\n", vypis, poleitemunaseznamech[i].item_in_seznam, poleitemunaseznamech[i].item_found);
                    vypis++;
                }
            }
        }

        if (regal == INT_MAX)
        {
            seznam++;
            regal = -1;
            vypis = 0;
        }
        if (seznam <= max_seznamu && regal == -1)
        {
            printf("Optimalizovany seznam:\n");
        }

        if (regal < max_regalu)
        {
            regal++;
        }
        else
        {
            regal = INT_MAX;
        }

        if (seznam > max_seznamu)
        {
            break;
        }
    }

    for (size_t i = 0; i < pocetitemu; i++)//uvolnovani každého itemu v poleitemu
    {
        free(poleitemu[i].item_in_regal);
    }
    free(poleitemu);
    for (size_t i = 0; i < pocet_itemu_na_seznamech; i++) //uvolnovani každého itemu v poleiitemunaseznamech
    {
        free(poleitemunaseznamech[i].item_in_seznam);
        // free(poleitemunaseznamech[i].item_found);
    }
    free(poleitemunaseznamech);
    return 0;
}
