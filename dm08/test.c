#include <stdio.h>
#include <cstdlib>
typedef struct point
{
    int lenght;
    int start;
} point;

void Printarray(struct point array[], int number_of_elements)
{
    for (int i = 0; i < number_of_elements; i++)
    {
        printf("%d --- %d\n", array[i].start, array[i].lenght);
    }
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

    array_of_point[number_of_points].lenght = lenght; // save first point
    array_of_point[number_of_points].start = start;
    number_of_points++;
    array_of_point = (point *)realloc(array_of_point, number_of_points * sizeof(point) * 2);

    while (scanf("+ %d %d\n", &start, &lenght) != EOF) //Scanf all points without first
    {
        array_of_point[number_of_points].lenght = lenght;
        array_of_point[number_of_points].start = start;
        number_of_points++;
        array_of_point = (point *)realloc(array_of_point, number_of_points * sizeof(point) * 2);
    }

    Printarray(array_of_point, number_of_points);
    free(array_of_point);
    return 0;
}
