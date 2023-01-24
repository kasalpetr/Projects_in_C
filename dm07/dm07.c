#include <stdio.h>
#include <string.h>
#include <cstdlib>

typedef struct RegistredStudent // Struct on student that registred on exam
{
    char *name_1;
    char *name_2;
    char *name_3;
    int come_on_exam;
} RegistredStudent;

typedef struct StudentCome // Struct on student that come on exam
{
    char *name_1;
    char *name_2;
    char *name_3;
    int was_registred;
} StudentCome;

void Savearray(struct RegistredStudent array[], int number_of_element, int number_of_name, char *buffer) // ukladani registrovanych studentu
{
    switch (number_of_name)
    {
    case 1:
        array[number_of_element].name_1 = buffer;
        break;
    case 2:
        array[number_of_element].name_2 = buffer;
        break;
    case 3:
        array[number_of_element].name_3 = buffer;
        break;
    }
}
void SavearrayCome(struct StudentCome array[], int number_of_element, int number_of_name, char *buffer) // ukladani jmeno pro studenty co prisly
{
    switch (number_of_name)
    {
    case 1:
        array[number_of_element].name_1 = buffer;
        break;
    case 2:
        array[number_of_element].name_2 = buffer;
        break;
    case 3:
        array[number_of_element].name_3 = buffer;
        break;
    }
}

void PrintArray(struct RegistredStudent array[], int number_of_element) // vypis pole
{
    printf("\n");
    for (int i = 0; i <= number_of_element; i++)
    {
        printf("%d Name is -- %s %s", i, array[i].name_1, array[i].name_2);
        if (array[i].name_3 == NULL)
        {
            printf("\n");
        }
        else
        {
            printf(" %s\n", array[i].name_3);
        }
    }
}
void PrintArrayCome(struct StudentCome array[], int number_of_element) // vypis pole
{
    printf("\n");
    for (int i = 0; i <= number_of_element; i++)
    {
        printf("%d Name is -- %s %s", i, array[i].name_1, array[i].name_2);
        if (array[i].name_3 == NULL)
        {
            printf("\n");
        }
        else
        {
            printf(" %s\n", array[i].name_3);
        }
    }
}

void WasRegistred(struct RegistredStudent *registred, struct StudentCome *come, int number_of_registred, int number_of_come)
{
    for (int i = 0; i <= number_of_come; i++)
    {
        for (int j = 0; j <= number_of_registred; j++)
        {
            if (strcasecmp(come[i].name_1, registred[j].name_1) == 0 && strcasecmp(come[i].name_2, registred[j].name_2) == 0 && strcasecmp(come[i].name_3, registred[j].name_3) == 0)
            {
                printf("%s %s == %s %s\n", come[i].name_1, come[i].name_2, registred[j].name_1, registred[j].name_2);
            }
        }
    }
}

void Nullname(struct RegistredStudent *registred, struct StudentCome *come, int number_of_registred, int number_of_come)
{
    for (int i = 0; i <= number_of_registred; i++)
    {
        if (registred[i].name_3 == NULL)
        {
            registred[i].name_3 = registred[i].name_2;
        }
    }
    for (int i = 0; i <= number_of_come; i++)
    {
        if (come[i].name_3 == NULL)
        {
            come[i].name_3 = come[i].name_2;
        }
    }
}

int main(int argc, char const *argv[])
{
    int number_of_name = 0;
    // Registred Student
    char *buffer;
    RegistredStudent *array_registred;
    array_registred = (RegistredStudent *)malloc(sizeof(RegistredStudent));
    int number_of_registred = 0;

    // Student that come on exam
    char *buffer2;
    StudentCome *array_come;
    array_come = (StudentCome *)malloc(sizeof(StudentCome));
    int number_of_come = 0;

    printf("Studenti:\n");
    while (1)
    {
        buffer = (char *)malloc(32 * sizeof(char));

        if (scanf("%s", buffer) == EOF)
        {
            printf("Spatny vstup\n");
            break;
        }
        if (strcmp(buffer, "P:") == 0) // konec Registrovaných
        {
            break;
        }

        if (strcmp(buffer, "R:") != 0) // konec Registrovaných
        {
            printf("%s ", buffer);
            number_of_name++;
            Savearray(array_registred, number_of_registred, number_of_name, buffer);
        }
        else
        {
            if (number_of_registred != 0 || number_of_name != 0)
            {
                number_of_name = 0;

                number_of_registred++;
                array_registred = (RegistredStudent *)realloc(array_registred, number_of_registred * 3 * sizeof(RegistredStudent));
                printf("\n");
            }
            number_of_name = 0;
        }
    }
    number_of_name = 0;
    printf("\n---------------------\n");
    while (1)
    {

        buffer2 = (char *)malloc(32 * sizeof(char));

        if (scanf("%s", buffer2) == EOF)
        {
            printf("\n\nKonec Načítání\n-------------------\n");
            break;
        }
        if (strcmp(buffer2, "P:") != 0) // konec Registrovaných
        {
            printf("%s ", buffer2);
            number_of_name++;
            SavearrayCome(array_come, number_of_come, number_of_name, buffer2);
        }
        else
        {
            number_of_name = 0;
            number_of_come++;
            array_come = (StudentCome *)realloc(array_come, number_of_come * 3 * sizeof(StudentCome));
            printf("\n");
        }
    }

    Nullname(array_registred, array_come, number_of_registred, number_of_come);
    WasRegistred(array_registred, array_come, number_of_registred, number_of_come);

    PrintArray(array_registred, number_of_registred);
    PrintArrayCome(array_come, number_of_come);

    return 0;
}
