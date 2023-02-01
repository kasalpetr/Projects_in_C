#include <stdio.h>
#include <cstdlib>
typedef struct point
{
    int height;
    int start;
} point;

typedef struct trace
{
    int start_km;
    int end_km;
    int start_height;
    int end_height;
} trace;

void Printarray(struct point array[], int number_of_elements)
{
    for (int i = 0; i < number_of_elements; i++)
    {
        printf("%d --- %d\n", array[i].start, array[i].height);
    }
}

int main(int argc, char const *argv[])
{
    // scanf variables
    int height = 0;
    int start = 0;
    // array of struct
    point *array_of_point;
    array_of_point = (point *)malloc(sizeof(point));
    int number_of_points = 0;

    // array of trace
    trace *array_of_trace;
    array_of_trace = (trace *)malloc(sizeof(trace));
    int number_of_trace = 0;

    //
    int max_height = 0;
    int height_now = 0;
    int max_lenght = 0;
    int lenght_now = 0;

    scanf("%d\n", &height); // scanf first point

    array_of_point[number_of_points].height = height; // save first point
    array_of_point[number_of_points].start = start;
    number_of_points++;
    array_of_point = (point *)realloc(array_of_point, number_of_points * sizeof(point) * 2);

    while (scanf("+ %d %d\n", &start, &height) != EOF) // Scanf all points without first
    {
        array_of_point[number_of_points].height = height;
        array_of_point[number_of_points].start = start;
        number_of_points++;
        array_of_point = (point *)realloc(array_of_point, number_of_points * sizeof(point) * 2);
    }
    // Printarray(array_of_point, number_of_points);

    for (int i = 0; i < number_of_points; i++)
    {
        for (int j = i; j < number_of_points; j++)
        {

            height_now = array_of_point[i].height - array_of_point[j].height;
            lenght_now = array_of_point[j].start - array_of_point[i].start;
            if (max_height < height_now)
            {
                number_of_trace = 0;
                free(array_of_trace);
                array_of_trace = (trace *)malloc(sizeof(trace));
                array_of_trace[number_of_trace].start_km = array_of_point[i].start;
                array_of_trace[number_of_trace].start_height = array_of_point[i].height;
                array_of_trace[number_of_trace].end_km = array_of_point[j].start;
                array_of_trace[number_of_trace].end_height = array_of_point[j].height;
                max_height = height_now;
                max_lenght = lenght_now;
            }
            else
            {
                if (max_height == height_now)
                {
                    if (max_lenght == lenght_now)
                    {
                        number_of_trace++;
                        array_of_trace = (trace *)realloc(array_of_trace, number_of_trace * sizeof(trace) * 2);
                        array_of_trace[number_of_trace].start_km = array_of_point[i].start;
                        array_of_trace[number_of_trace].start_height = array_of_point[i].height;
                        array_of_trace[number_of_trace].end_km = array_of_point[j].start;
                        array_of_trace[number_of_trace].end_height = array_of_point[j].height;
                        max_height = height_now;
                        max_lenght = lenght_now;
                    }
                    if (max_lenght < lenght_now)
                    {
                        number_of_trace = 0;
                        free(array_of_trace);
                        array_of_trace = (trace *)malloc(sizeof(trace));
                        array_of_trace[number_of_trace].start_km = array_of_point[i].start;
                        array_of_trace[number_of_trace].start_height = array_of_point[i].height;
                        array_of_trace[number_of_trace].end_km = array_of_point[j].start;
                        array_of_trace[number_of_trace].end_height = array_of_point[j].height;
                        max_height = height_now;
                        max_lenght = lenght_now;
                    }
                }
            }
        }
    }

    if (max_lenght != 0)
    {
    printf("*%d km, klesani: %d m, varianty: %d*\r\n", max_lenght, max_height, number_of_trace+1);

    for (int i = 0; i <= number_of_trace; i++)
    {
        printf("*+ %d (%d) -> + %d (%d)*", array_of_trace[i].start_km, array_of_trace[i].start_height, array_of_trace[i].end_km, array_of_trace[i].end_height);
    }
    }else
    {
        printf("*Nenalezeno*");
    }
    
    free(array_of_trace);
    free(array_of_point);
    return 0;
}
