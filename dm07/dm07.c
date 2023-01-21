#include<stdio.h>
#include<string.h>
#include <cstdlib>

typedef struct RegistredStudent
{
    char *name;
}RegistredStudent;

typedef struct RegistredStudent
{
    char *name;
}RegistredStudent;



int main(int argc, char const *argv[])
{

    RegistredStudent *array_student;
    array_student = (RegistredStudent*)malloc(sizeof(RegistredStudent));
    printf("Studenti:\n");

        scanf("%s ", array_student[0].name);
    
    


    return 0;
}
