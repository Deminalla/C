// Parašyti funkciją, kuri randa ir atspausdina visus žodžius, kurie vienodai skaitomi iš pradžios ir iš galo
#include <stdio.h>
#include <stdlib.h>
#include <string.h> //for memset
#include <ctype.h>  //for isspace
void finding_begin_end(int i, int *first_position, int *last_position, int lenght, char *words);
void check_palindrome(int k, int l, int *first_position, int *last_position, char *words, int *num_letters, int *palindrome, FILE *rezfile);
int main()
{
    FILE *myfile, *rezfile;
    char *my_filename, *rez_filename;
    char *words;
    int i, k, l;
    int lenght;
    int first_position = -1, last_position = -1;
    int num_letters = 0; // number of letters (skirtumas tarp l ir f) in a word if we count from 0
    int palindrome = 0;

    my_filename = (char *)calloc(100, sizeof(char));
    if (my_filename == NULL)
    {
        printf("Memory could not be allocated\n");
    }
    rez_filename = (char *)calloc(100, sizeof(char));
    if (rez_filename == NULL)
    {
        printf("Memory could not be allocated\n");
    }

first_file:
    printf("Please enter a .txt file name to analyze: ");
    scanf("%s", my_filename);
    myfile = fopen(my_filename, "r"); // open file for reading
    if (myfile == NULL)
    {
        printf("Could not open file for reading\n");
        goto first_file;
    }
second_file:
    printf("Please enter a .txt file name to write the results to: ");
    scanf("%s", rez_filename);
    rezfile = fopen(rez_filename, "a"); // create file for writing at the eof each time
    if (rezfile == NULL)
    {
        printf("Could not create file\n");
        goto second_file;
    }

    words = (char *)calloc(255, sizeof(char));
    if (words == NULL)
    {
        printf("Memory could not be allocated\n");
    }

    while (fgets(words, 255, myfile) != NULL)
    { // maximum 255 symbols in each line, do I need !=NULL ?
        lenght = strlen(words);
        for (i = 0; i <= lenght - 1; i++)
        { // lenght-1 because we start from
            finding_begin_end(i, &first_position, &last_position, lenght, words);
            if (first_position >= 0 && last_position >= 0)
            {
                check_palindrome(k, l, &first_position, &last_position, words, &num_letters, &palindrome, rezfile);
            }
        }
        //memset(words, 0, 255); // clear all elements from words, why wont free and calloc work again?
    }
    if (!palindrome)
    {
        fprintf(rezfile, "Unfortunately, no palindromes were found in the file");
    }
    fclose(myfile);
    fclose(rezfile);
    free(words);
    return 0;
}
void finding_begin_end(int i, int *first_position, int *last_position, int lenght, char *words)
{
    if ((*first_position) < 0)
    { // kol dar nera rasta zodzio pirmos raides vieta
        if (!isspace(*(words + i)))
        {
            (*first_position) = i;
        }
    }
    if ((*first_position) >= 0 && (*last_position) < 0)
    { // kol dar nera rasta zodzio pirmos raides vieta
        if (isspace(*(words + i)))
        { // if theres a space or this is the last word
            (*last_position) = i - 1;
        }
        else if (i == (lenght - 1))
        { // if the word is the last symbol
            (*last_position) = i;
        }
    }
}
void check_palindrome(int k, int l, int *first_position, int *last_position, char *words, int *num_letters, int *palindrome, FILE *rezfile)
{
    k = *first_position;
    for (l = *last_position; l >= *first_position; l--)
    {
        if (tolower(*(words + k)) == tolower(*(words + l))) // so capital and non capital letters are the same
        {
            (*num_letters)++;
        }
        k++;
    }
    if (*num_letters == (*last_position - *first_position + 1))
    {
        (*palindrome)++;
        if ((*palindrome) == 1)
        {
            fprintf(rezfile, "The palindromes that were found in the file: "); // fputs and not fputc because this is a string and not a single symbol
        }
        for (k = *first_position; k <= *last_position; k++)
        {
            fprintf(rezfile, "%c", (*(words + k))); // you need int for fputc(int _Ch, FILE *_File);
        }
        fprintf(rezfile, " ");
    }
    (*first_position) = -1; // so we can search for the next word
    (*last_position) = -1;
    (*num_letters) = 0; // brackets are necessary because pointers are read from right to left
}
