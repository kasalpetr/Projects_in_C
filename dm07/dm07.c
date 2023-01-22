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
        printf("name is -- %s %s %s\n ", array[i].name_1, array[i].name_2, array[i].name_3);
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
        printf("%s\n",buffer);
    }

    return 0;
}
