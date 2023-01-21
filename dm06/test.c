#include <string.h>
#include <stdio.h>
#include <cstdlib>

typedef struct dictionary
{
    char *word;
    int lenght;
    int is_in_dictionary;
} dictionary;

void ArrayfreeMemory(struct dictionary array[], int numbers_of_element)
{
    for (int i = 0; i < numbers_of_element; i++)
    {
        free(array[i].word);
    }

    free(array);
}

void PrintArrayofStruct(struct dictionary array[], int numbers_of_element)
{
    for (int i = 0; i < numbers_of_element; i++)
    {
        int delka = strlen(array[i].word);
        printf("Word %d is %s and Lenght is %d\n", i, array[i].word, delka);
    }
}

int InDictionary(char *word_from_dictionary, struct dictionary array[], int numbers_of_element) // Return 1 when word from text is in Dictionary
{

    for (int i = 0; i < numbers_of_element; i++)
    {
        if (strcasecmp(word_from_dictionary, array[i].word) == 0)
        {
            return 1;
        }
    }

    return 0;
}

void AddCharacter(struct dictionary *array, int number_of_element) //Pridava znaky na zacatek a na konec
{

    for (int i = 0; i < number_of_element; i++)
    {
    char start[36] = "<arg>";
    char konec[] = "<arg>";
        if (array[i].is_in_dictionary == 0)
        {
            strcat(start, array[i].word);
            strcpy(array[i].word, start);
            strcat(array[i].word, konec);

            array[i].lenght = strlen(array[i].word);
        }
    }
}

int main(int argc, char const *argv[])
{
    // dictionary
    char *buffer;
    dictionary *array_dictionary;
    array_dictionary = (dictionary *)(malloc(sizeof(dictionary)));
    int number_of_word_dictionary = 0;
    // text
    char *buffer_text;
    dictionary *array_text;
    array_text = (dictionary *)(malloc(sizeof(dictionary)));
    int number_of_word_text = 0;

    while (1) // Scan the dictionary
    {
        buffer = (char *)malloc(31 * sizeof(char));
        if (scanf("%30s\n", buffer) == EOF)
        {
            free(buffer);
            ArrayfreeMemory(array_text, number_of_word_text);
            ArrayfreeMemory(array_dictionary, number_of_word_dictionary);
            printf("Spatný vstup\n");
            break;
        }
        if (strcmp(buffer, "*****") == 0)
        {

            break;
        }

        array_dictionary[number_of_word_dictionary].word = buffer;
        number_of_word_dictionary++;
        array_dictionary = (dictionary *)realloc(array_dictionary, (number_of_word_dictionary + 1) * sizeof(dictionary));
    }

    while (1) // Scan the text
    {
        buffer_text = (char *)malloc(31 * sizeof(char));
        if (scanf("%30s", buffer_text) == EOF)
        {
            break;
        }

        array_text[number_of_word_text].word = buffer_text;                                                                                                 // Save the word from text in to the struct
        array_text[number_of_word_text].lenght = strlen(buffer_text);                                                                                       // Save the lenght of word
        array_text[number_of_word_text].is_in_dictionary = InDictionary(array_text[number_of_word_text].word, array_dictionary, number_of_word_dictionary); // If is the word from text in Dictionary it will be set on 1
        number_of_word_text++;                                                                                                                              // at first string is go int from 0 to 1
        array_text = (dictionary *)realloc(array_text, (number_of_word_text + 1) * sizeof(dictionary));                                                     // realoc array
    }

    AddCharacter(array_text, number_of_word_text);

    // Just printing list its only for me to see what is happaning right now XD
    printf("Slovník:\n");
    PrintArrayofStruct(array_dictionary, number_of_word_dictionary);
    printf("Text:\n");
    PrintArrayofStruct(array_text, number_of_word_text);

    // Free memory
    free(buffer);
    free(buffer_text);
    ArrayfreeMemory(array_text, number_of_word_text);
    ArrayfreeMemory(array_dictionary, number_of_word_dictionary);
    return 0;
}
