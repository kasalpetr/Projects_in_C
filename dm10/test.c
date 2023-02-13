#include <stdio.h>
#include <cstring>
#include <cstdlib>

typedef struct parking_place
{
  int x;
  int y;
  char *RZ;
} parking_place;

void PrintcarHouse(struct parking_place *array, int number_of_element)
{
  for (int i = 0; i < number_of_element; i++)
  {
    printf("park %d %d %s\n", array[i].x, array[i].y, array[i].RZ);
  }
}

void Freehousememory(struct parking_place *array, int number_of_element)
{
  for (int i = 0; i < number_of_element; i++)
  {
    free(array[i].RZ);
  }
  free(array);
}

int main(int argc, char const *argv[])
{
  int change = 0;
  char *element;
  int actual_x = 0;
  int actual_y = 0;
  char *actual_RZ;

  parking_place *parkingHouse;
  parkingHouse = (parking_place *)malloc(sizeof(parking_place) * 2);
  int number_of_cars = 0;
  int number_of_struct = 0;

  int max_X = 0;
  int max_Y = 0;
  printf("Velikost\n");
  scanf("%d %d", &max_X, &max_Y);
  printf("Pozadavky\n");

  while (1)
  {
    element = (char *)malloc(sizeof(element));
    actual_RZ = (char *)malloc(sizeof(actual_RZ) * 11);
    scanf("%s", element);
    if (strcmp(element, "+") == 0) // if na vstupu +
    {
      scanf(" %d %d %s\n", &actual_x, &actual_y, actual_RZ);
    }
    else if (strcmp(element, "-") == 0) // if na vstupu -
    {
      scanf(" %s\n", actual_RZ);
    }
    else // na vstupu není + ani - ->end
    {
      printf("není +/-\n");

      break;
    }

    if (actual_x > max_X || actual_y > max_Y) // if vetsi nez house
    {
      printf("Parkuješ někomu na zahradě\n");
      break;
    }
    if (strcmp(element, "+") == 0)
    {
      for (int i = 0; i < number_of_struct; i++)
      {
        if (parkingHouse[i].x == max_X + 1 && parkingHouse[i].y == max_Y + 1)
        {
          parkingHouse[i].RZ = actual_RZ;
          parkingHouse[i].x = actual_x;
          parkingHouse[i].y = actual_y;
          number_of_cars++;
          change = 1;
          break;
        }
      }
      if (!change)
      {
        printf("Ulozeno\n");
      parkingHouse[number_of_cars].RZ = actual_RZ;
      parkingHouse[number_of_cars].x = actual_x;
      parkingHouse[number_of_cars].y = actual_y;
      number_of_cars++;
      parkingHouse = (parking_place *)realloc(parkingHouse, number_of_cars + 32 * (sizeof(parking_place)));
      number_of_struct++;
      }
      
    }
    else
    {
      for (int i = 0; i < number_of_cars; i++)
      {
        if (strcmp(parkingHouse[i].RZ, actual_RZ) == 0)
        {
          printf("ok %d %d %s %s\n", actual_x, actual_y, actual_RZ, parkingHouse[i].RZ);
          free(parkingHouse[i].RZ);
          parkingHouse[i].RZ = NULL;
          parkingHouse[i].x = max_X + 1;
          parkingHouse[i].y = max_Y + 1;
          number_of_cars--;
        }
      }
      free(actual_RZ);
    }
    free(element);
  }
  PrintcarHouse(parkingHouse, number_of_struct);
  Freehousememory(parkingHouse, number_of_struct);
  free(actual_RZ);
  free(element);

  return 0;
}
