#include <stdio.h>
#include <cstdlib>

typedef struct domino
{
    struct domino *next;
    int number;
    char *name;
} domino;

void delList(domino *current)
{
    if (current != NULL)
    {
  domino *tmp;
  tmp = current->next;
  free(current->name);
  free(current);
  current = tmp;
        /* code */
    }
    
}

domino *createlist(int array[]){

    domino *head;
    domino *tmp;
    domino *current;

    head = (domino *)malloc(sizeof(domino));
    head->next = NULL;
    head->number = array[0];
    current = head;
    for (int i = 0; i < 3; i++)
    {
        tmp = (domino *)malloc(sizeof(domino));
        current->next = tmp;
        current = tmp;
        current->next = NULL;
        current->number = array[i+1];
    }
    current->next = head;

    printf("%d %d %d %d %d\n", head->number, head->next->number,head->next->next->number, head->next->next->next->number,head->next->next->next->next->number );
    delList(head);
    return head;
}

int main(int argc, char const *argv[])
{
    char name[65];
    int number[4];
    domino *array_of_domino;

    // while (1)
    // {
        if (scanf("%64s [%d, %d, %d, %d]", &name[65], &number[0], &number[1], &number[2], &number[3]) == EOF)
        {
            // break;
        }
       array_of_domino = createlist(number);
    // }
    return 0;
}



