#include <stdio.h>
#include <cstdlib>
typedef struct point
{
    int lenght;
    int start;
} point;

void Savepoint(struct point array[], int number_of_element, int lenght, int start){
array[number_of_element].lenght = lenght;
array[number_of_element].start = start;

}

int main(int argc, char const *argv[])
{
    // scanf variables
    int lenght = 0;
    int start = 0;
    // array of struct
    point *array_of_point;
    array_of_point = (point *)malloc(sizeof(point));
    int number_of_points = 0;

    scanf("%d\n", &lenght); // scanf first point
    printf("%d\n", lenght);

    Savepoint(array_of_point, number_of_points, lenght, start);
    array_of_point = (point *)realloc(array_of_point, number_of_points+1 * sizeof(point));
    number_of_points++;
    

    while (scanf("+ %d %d\n", &start, &lenght) != EOF)
    {
        printf("+ %d %d\n", start, lenght);
        array_of_point[number_of_points].lenght = lenght; // save first point
        array_of_point[number_of_points].start = start;
        array_of_point = (point *)realloc(array_of_point, number_of_points + 1 * sizeof(point));
    }


    free(array_of_point);
    return 0;
}
