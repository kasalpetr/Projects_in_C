#ifndef __PROGTEST__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef struct TItem
{
  struct TItem *m_Next;
  char *m_Name;
  char m_Secret[24];
} TITEM;

#endif /* __PROGTEST__ */

TITEM *newItem(const char *name, TITEM *next)
{
  TITEM *l = (TITEM *)malloc(sizeof(*l));
  l->m_Name = strdup(name);
  l->m_Next = next;
  for (size_t i = 0; i < 24; i++)
  {
    l->m_Secret[i] = '\0';
  }

  return l;
}
void printlist(TITEM *src)
{
  while (1)
  {
    /* code */
    printf("%s\n", src->m_Name);
    if (src->m_Next == NULL)
    {
      break;
    }
    else
    {
      src = src->m_Next;
    }
  }
}
TITEM *swapItems(TITEM *current, TITEM *prev)
{
  // printf("Got current item: %s\n", current->m_Name);
  TITEM *tmp;
  tmp = current;
  current = current->m_Next;
  tmp->m_Next = current->m_Next;
  current->m_Next = tmp;
  if (prev != NULL)
  {
    // printf("Got previous item: %s\n", prev->m_Name);
    prev->m_Next = current;
  }
  return current;
}
TITEM *sortList(TITEM *l, int ascending)
{
  if (l == NULL)
  {
    return NULL;
  }
  if (l->m_Next == NULL)
  {
    return NULL;
  }
  TITEM *start = l;
  // printf("Orig state:\n");
  // printlist(start);
  // printf("\n\n");
  TITEM *current = start;
  TITEM *previous = NULL;
  int swapped = 0;
  int issort = 1;


  while (current->m_Next != NULL)
  {
    swapped = 0;
    // printf("Checking items: %s|%s\n", current->m_Name, current->m_Next->m_Name);
    if ((strcmp(current->m_Name, current->m_Next->m_Name) > 0 && ascending != 0) || (strcmp(current->m_Next->m_Name, current->m_Name) > 0 && ascending == 0))
    {
      // printf("swapping...\n");
      if (start == current)
      {
        // printf("First item\n");
        start = swapItems(current, previous);
      }
      else
      {
        // printf("Other items\n");
        swapItems(current, previous);
      }
      swapped = 1;
      issort = 0;
    }
    if (swapped == 0)
    {
      previous = current;
      current = current->m_Next;

      if (current->m_Next == NULL)
      {
        if (issort)
        {
          break;
        }
        current = start;
        previous = NULL;
        issort = 1;
      }
    }
    else
    {
      if (previous == NULL)
      {
        previous = start;
      }
      else
      {
        previous = previous->m_Next;
      }

      if (current->m_Next == NULL)
      {
        if (issort)
        {
          break;
        }

        current = start;
        previous = NULL;
        issort = 1;
      }
    }
    // printf("New state:\n");
    // printf("swapped: %d\n", swapped);
    // printf("issort: %d\n", issort);
    // printf("CURRENT: %s\n", current->m_Name);
    // printlist(start);
    // printf("\n");
  }

  return start;
}

void freeList(TITEM *src)
{

  while (src)
  {
    TITEM *p = src->m_Next; /* ukazatel je zachov´an */
    free(src);
    src = p;
  }
}

#ifndef __PROGTEST__
int main(int argc, char *argv[])
{
  TITEM *l;
  char tmp[50];

  assert(sizeof(TITEM) == sizeof(TITEM *) + sizeof(char *) + 24 * sizeof(char));
  // l = NULL;
  // l = newItem("B", l);
  // l = newItem("A", l);
  // l = newItem("A", l);
  // l = newItem("A", l);
  


  // // l = newItem("C", l);
  // // l = newItem("D", l);
  // // // // l = newItem("AG1", l);
  // // // // l = newItem("LIN", l);

  // // l = sortList(l, 1);
  // printlist(l);
  // freeList(l);
  // l = sortList(l, 1);

  // printf("%s\n", l->m_Name);
  // printf("%s\n", l->m_Next->m_Name);
  // printf("%s\n", l->m_Next->m_Next->m_Name);
  // printf("%s\n", l->m_Next->m_Next->m_Next->m_Name);
  // printf("%s\n", l->m_Next->m_Next->m_Next->m_Next->m_Name);
  // printf("------\n");

  l = NULL;
  l = newItem("PA1", l);
  l = newItem("PA2", l);
  l = newItem("UOS", l);
  l = newItem("AG1", l);
  l = newItem("LIN", l);
  assert(l && !strcmp(l->m_Name, "LIN"));
  assert(l->m_Next && !strcmp(l->m_Next->m_Name, "AG1"));
  assert(l->m_Next->m_Next && !strcmp(l->m_Next->m_Next->m_Name, "UOS"));
  assert(l->m_Next->m_Next->m_Next && !strcmp(l->m_Next->m_Next->m_Next->m_Name, "PA2"));
  assert(l->m_Next->m_Next->m_Next->m_Next && !strcmp(l->m_Next->m_Next->m_Next->m_Next->m_Name, "PA1"));
  assert(l->m_Next->m_Next->m_Next->m_Next->m_Next == NULL);
  l = sortList(l, 1);
  printf("%s\n", l->m_Name);
  printf("%s\n", l->m_Next->m_Name);
  printf("%s\n", l->m_Next->m_Next->m_Name);
  printf("%s\n", l->m_Next->m_Next->m_Next->m_Name);
  printf("%s\n", l->m_Next->m_Next->m_Next->m_Next->m_Name);
  printf("------\n");
  assert(l && !strcmp(l->m_Name, "AG1"));
  assert(l->m_Next && !strcmp(l->m_Next->m_Name, "LIN"));
  assert(l->m_Next->m_Next && !strcmp(l->m_Next->m_Next->m_Name, "PA1"));
  assert(l->m_Next->m_Next->m_Next && !strcmp(l->m_Next->m_Next->m_Next->m_Name, "PA2"));
  assert(l->m_Next->m_Next->m_Next->m_Next && !strcmp(l->m_Next->m_Next->m_Next->m_Next->m_Name, "UOS"));
  assert(l->m_Next->m_Next->m_Next->m_Next->m_Next == NULL);
  l = newItem("programming and algorithmic I", l);
  l = newItem("AAG", l);
  assert(l && !strcmp(l->m_Name, "AAG"));
  assert(l->m_Next && !strcmp(l->m_Next->m_Name, "programming and algorithmic I"));
  assert(l->m_Next->m_Next && !strcmp(l->m_Next->m_Next->m_Name, "AG1"));
  assert(l->m_Next->m_Next->m_Next && !strcmp(l->m_Next->m_Next->m_Next->m_Name, "LIN"));
  assert(l->m_Next->m_Next->m_Next->m_Next && !strcmp(l->m_Next->m_Next->m_Next->m_Next->m_Name, "PA1"));
  assert(l->m_Next->m_Next->m_Next->m_Next->m_Next && !strcmp(l->m_Next->m_Next->m_Next->m_Next->m_Next->m_Name, "PA2"));
  assert(l->m_Next->m_Next->m_Next->m_Next->m_Next->m_Next && !strcmp(l->m_Next->m_Next->m_Next->m_Next->m_Next->m_Next->m_Name, "UOS"));
  assert(l->m_Next->m_Next->m_Next->m_Next->m_Next->m_Next->m_Next == NULL);
  l = sortList(l, 0);
  assert(l && !strcmp(l->m_Name, "programming and algorithmic I"));
  assert(l->m_Next && !strcmp(l->m_Next->m_Name, "UOS"));
  assert(l->m_Next->m_Next && !strcmp(l->m_Next->m_Next->m_Name, "PA2"));
  assert(l->m_Next->m_Next->m_Next && !strcmp(l->m_Next->m_Next->m_Next->m_Name, "PA1"));
  assert(l->m_Next->m_Next->m_Next->m_Next && !strcmp(l->m_Next->m_Next->m_Next->m_Next->m_Name, "LIN"));
  assert(l->m_Next->m_Next->m_Next->m_Next->m_Next && !strcmp(l->m_Next->m_Next->m_Next->m_Next->m_Next->m_Name, "AG1"));
  assert(l->m_Next->m_Next->m_Next->m_Next->m_Next->m_Next && !strcmp(l->m_Next->m_Next->m_Next->m_Next->m_Next->m_Next->m_Name, "AAG"));
  assert(l->m_Next->m_Next->m_Next->m_Next->m_Next->m_Next->m_Next == NULL);
  freeList(l);
  l = NULL;
  strncpy(tmp, "PA1", sizeof(tmp) - 1);
  tmp[sizeof(tmp) - 1] = '\0';
  l = newItem(tmp, l);
  strncpy(tmp, "PA2", sizeof(tmp) - 1);
  tmp[sizeof(tmp) - 1] = '\0';
  l = newItem(tmp, l);
  strncpy(tmp, "UOS", sizeof(tmp) - 1);
  tmp[sizeof(tmp) - 1] = '\0';
  l = newItem(tmp, l);
  strncpy(tmp, "LIN", sizeof(tmp) - 1);
  tmp[sizeof(tmp) - 1] = '\0';
  l = newItem(tmp, l);
  strncpy(tmp, "AG1", sizeof(tmp) - 1);
  tmp[sizeof(tmp) - 1] = '\0';
  l = newItem(tmp, l);
  assert(l && !strcmp(l->m_Name, "AG1"));
  assert(l->m_Next && !strcmp(l->m_Next->m_Name, "LIN"));
  assert(l->m_Next->m_Next && !strcmp(l->m_Next->m_Next->m_Name, "UOS"));
  assert(l->m_Next->m_Next->m_Next && !strcmp(l->m_Next->m_Next->m_Next->m_Name, "PA2"));
  assert(l->m_Next->m_Next->m_Next->m_Next && !strcmp(l->m_Next->m_Next->m_Next->m_Next->m_Name, "PA1"));
  assert(l->m_Next->m_Next->m_Next->m_Next->m_Next == NULL);
  l = sortList(l, 1);
  assert(l && !strcmp(l->m_Name, "AG1"));
  assert(l->m_Next && !strcmp(l->m_Next->m_Name, "LIN"));
  assert(l->m_Next->m_Next && !strcmp(l->m_Next->m_Next->m_Name, "PA1"));
  assert(l->m_Next->m_Next->m_Next && !strcmp(l->m_Next->m_Next->m_Next->m_Name, "PA2"));
  assert(l->m_Next->m_Next->m_Next->m_Next && !strcmp(l->m_Next->m_Next->m_Next->m_Next->m_Name, "UOS"));
  assert(l->m_Next->m_Next->m_Next->m_Next->m_Next == NULL);
  strncpy(tmp, "programming and algorithmic I", sizeof(tmp) - 1);
  tmp[sizeof(tmp) - 1] = '\0';
  l = newItem(tmp, l);
  strncpy(tmp, "AAG", sizeof(tmp) - 1);
  tmp[sizeof(tmp) - 1] = '\0';
  l = newItem(tmp, l);
  assert(l && !strcmp(l->m_Name, "AAG"));
  assert(l->m_Next && !strcmp(l->m_Next->m_Name, "programming and algorithmic I"));
  assert(l->m_Next->m_Next && !strcmp(l->m_Next->m_Next->m_Name, "AG1"));
  assert(l->m_Next->m_Next->m_Next && !strcmp(l->m_Next->m_Next->m_Next->m_Name, "LIN"));
  assert(l->m_Next->m_Next->m_Next->m_Next && !strcmp(l->m_Next->m_Next->m_Next->m_Next->m_Name, "PA1"));
  assert(l->m_Next->m_Next->m_Next->m_Next->m_Next && !strcmp(l->m_Next->m_Next->m_Next->m_Next->m_Next->m_Name, "PA2"));
  assert(l->m_Next->m_Next->m_Next->m_Next->m_Next->m_Next && !strcmp(l->m_Next->m_Next->m_Next->m_Next->m_Next->m_Next->m_Name, "UOS"));
  assert(l->m_Next->m_Next->m_Next->m_Next->m_Next->m_Next->m_Next == NULL);
  l = sortList(l, 0);
  assert(l && !strcmp(l->m_Name, "programming and algorithmic I"));
  assert(l->m_Next && !strcmp(l->m_Next->m_Name, "UOS"));
  assert(l->m_Next->m_Next && !strcmp(l->m_Next->m_Next->m_Name, "PA2"));
  assert(l->m_Next->m_Next->m_Next && !strcmp(l->m_Next->m_Next->m_Next->m_Name, "PA1"));
  assert(l->m_Next->m_Next->m_Next->m_Next && !strcmp(l->m_Next->m_Next->m_Next->m_Next->m_Name, "LIN"));
  assert(l->m_Next->m_Next->m_Next->m_Next->m_Next && !strcmp(l->m_Next->m_Next->m_Next->m_Next->m_Next->m_Name, "AG1"));
  assert(l->m_Next->m_Next->m_Next->m_Next->m_Next->m_Next && !strcmp(l->m_Next->m_Next->m_Next->m_Next->m_Next->m_Next->m_Name, "AAG"));
  assert(l->m_Next->m_Next->m_Next->m_Next->m_Next->m_Next->m_Next == NULL);
  freeList(l);
  return EXIT_SUCCESS;
}
#endif /* __PROGTEST__ */

//  if (l == NULL)
//   {
//     return NULL;
//   }
//   if (l->m_Next == NULL)
//   {
//     return NULL;
//   }

//   if (ascending != 0)
//   {
//     while (1)
//     {

//       if (strcmp(l->m_Name, l->m_Next->m_Name) > 0)
//       {
//         if (change == 0)
//         {
//           change = 1;
//           TITEM *tmp = l->m_Next;
//           l->m_Next = l;
//           l = tmp;
//         }
//         else
//         {
//           if (l->m_Next->m_Next == NULL)
//           {
//             /* code */
//           }

//           change = 1;
//           TITEM *tmp = l->m_Next;
//           l->m_Next = l;
//           l = tmp;
//           predchozi->m_Next = tmp;
//         }
//       }
//       if (l->m_Next->m_Next == NULL)
//       {
//           printf("1\n");
//         if (change == 1)
//         {
//           l = start;
//           change = 0;
//         }
//         else
//         {
//           break;
//         }
//       }
//       else
//       {
//           printf("2\n");
//         // printf("%s\n",l->m_Name);
//         predchozi = l;
//         l = l->m_Next;
//       }
//     }
//   }
//   else
//   {
//     while (1)
//     {
//       if (strcmp(l->m_Next->m_Name, l->m_Name) > 0)
//       {
//         change = 1;
//         char *tmp = l->m_Next->m_Name;
//         l->m_Next->m_Name = l->m_Name;
//         l->m_Name = tmp;
//       }
//       if (l->m_Next->m_Next == NULL)
//       {
//         if (change == 1)
//         {
//           l = start;
//           change = 0;
//         }
//         else
//         {
//           break;
//         }
//       }
//       else
//       {
//         l = l->m_Next;
//       }
//     }
//   }

/* int change = 0; */
/* TITEM *start = l; */
/* TITEM *predchozi; */
/* while (change < 2) */
/* { */
/*   if (strcmp(l->m_Name, l->m_Next->m_Name) > 0) */
/*   { */
/*     if (start == l) */
/*     { */
/*       printf("first swap\n"); */
/*       TITEM *prvni = l; */
/*       TITEM *druhy = l->m_Next; */
/*       TITEM *treti = l->m_Next->m_Next; */
/*       l = druhy; */
/*       l->m_Next = prvni; */
/*       l->m_Next->m_Next = treti; */
/*       start = l; */
/*       predchozi = l; */
/*       l = l->m_Next; */
/*     } */
/*     else */
/*     { */
/*       printf("second swap\n"); */
/*       l = predchozi; */
/*       TITEM *tmp = l->m_Next->m_Next; */
/*       l->m_Next->m_Next = l->m_Next; */
/*       l->m_Next = tmp; */

/*       printf("%s\n", l->m_Name); */
/*       printf("%s\n", l->m_Next->m_Name); */
/*       printf("%s\n", l->m_Next->m_Next->m_Name); */
/*     } */
/*   } */
/*   else */
/*   { */
/*     l = l->m_Next; */
/*   } */
/*   printlist(l); */
/*   change++; */
/* } */

/* l = start; */
/* printf("END"); */
/* return l; */