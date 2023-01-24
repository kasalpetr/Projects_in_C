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

void Savearray(struct RegistredStudent array[], int number_of_element, int number_of_names){
    
}


void PrintArray(struct RegistredStudent array[], int number_of_element)
{
    printf("\n");
    for (int i = 0; i <= number_of_element; i++)
    {
        printf("name is -- %s %s %s\n", array[i].name_1, array[i].name_2, array[i].name_3);
    }
}

int main(int argc, char const *argv[])
{
    char *buffer;
    int number_of_name = 0;
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

        if (strcmp(buffer, "R:") != 0) // konec Registrovaných
        {

            printf("%s ", buffer);
            number_of_name++;

            switch (number_of_name)
            {
            case 1:
                array_registred[number_of_registred].name_1 = buffer;
                break;
            case 2:
                array_registred[number_of_registred].name_2 = buffer;
                break;
            case 3:
                array_registred[number_of_registred].name_3 = buffer;
                break;
            }
        }
        else
        {
            if (number_of_registred != 0 || number_of_name != 0 )
            {
            number_of_name = 0;

            number_of_registred++;
            array_registred = (RegistredStudent*)realloc(array_registred, number_of_registred*3  * sizeof(RegistredStudent));
            printf("\n");
            }
            number_of_name = 0;
        }
    }
    // for (size_t i = 0; i <= number_of_registred; i++)
    // {
    // printf("\n --- %s %s %s ---\n\n", array_registred[i].name_1, array_registred[i].name_2, array_registred[i].name_3);
    //     /* code */
    // }
    
    PrintArray(array_registred,number_of_registred);
    
    return 0;
}
