#include <stdio.h>
#include <string.h>
#include <cstdlib>

typedef struct RegistredStudent // Struct on student that registred on exam
{
    char *name_1;
    char *name_2;
    char *name_3;
} RegistredStudent;

typedef struct StudentCome // Struct on student that come on exam
{
    char *name_1;
    char *name_2;
    char *name_3;
    int was_registred;
} StudentCome;

void PrintArray(struct RegistredStudent array[], int number_of_element)
{
    for (int i = 0; i < number_of_element; i++)
    {
        printf("name is -- %s %s %s\n ", array[1].name_1, array[1].name_2, array[1].name_3);
    }
}

void Savename(struct RegistredStudent *array, int number_of_element, int number_of_name, char *buffer)
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

int main(int argc, char const *argv[])
{
    char *buffer;
    int number_of_name;
    // Registred Student
    RegistredStudent *array_registred;
    array_registred = (RegistredStudent *)malloc(sizeof(RegistredStudent));
    int number_of_registred = 0;

    // Student that come on exam
    StudentCome *array_come;
    array_come = (StudentCome *)malloc(sizeof(StudentCome));

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
    }

    return 0;
}
