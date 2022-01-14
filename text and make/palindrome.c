// Parašyti funkciją, kuri randa ir atspausdina visus žodžius, kurie vienodai skaitomi iš pradžios ir iš galo
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <ctype.h>  
void files (FILE *thefile, char *filename, char *format);
void finding_begin_end(int i, int *first_position, int *last_position, int lenght, char *words);
void check_palindrome(int k, int l, int *first_position, int *last_position, char *words, int *num_letters, int *palindrome, int *p_exists, FILE *rezfile);
void print_results(int k, int *first_position, int *last_position, char *words, int *palindrome, FILE *rezfile);
int main()
{
    FILE *myfile, *rezfile;
    char *my_filename, *rez_filename;
    char *words;
    char c; // int c?
    int i, k, l;
    int lenght;
    int first_position = -1, last_position = -1;
    int num_letters = 0; // number of letters (last_position-first_position) in a word if we count from 0
    int palindrome = 0, p_exists = 0;

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
    words = (char *)calloc(255, sizeof(char));
    if (words == NULL)
    {
        printf("Memory could not be allocated\n");
    }
    printf("Please enter a .txt file name to analyze: ");
    files (myfile,  my_filename, "r");

    printf("Please enter a .txt file name to write the results to: ");
    files (rezfile, rez_filename, "a");

    myfile = fopen(my_filename, "r");
    rezfile = fopen(rez_filename, "a");
    
    while (fgets(words, 255, myfile) != NULL) // reads 255 symbols each time
    {
        lenght = strlen(words);
        if ((*(words + lenght - 1)) != '\n') // c moves the pointer to the beginning of the next line
        {
            while ((c = fgetc(myfile)) != '\n' && c != EOF); // moves the pointer to the beginning of the next line
        }
        for (i = 0; i <= lenght - 1; i++) // lenght-1 because we start from 0
        {
            finding_begin_end(i, &first_position, &last_position, lenght, words);
            if (first_position >= 0 && last_position >= 0)
            {
                check_palindrome(k, l, &first_position, &last_position, words, &num_letters, &palindrome, &p_exists, rezfile);
            }
        }
    }
    if (!palindrome)
    {
        fprintf(rezfile, "Unfortunately, no palindromes were found in the file");
    }
    fclose(myfile);
    fclose(rezfile);
    free(my_filename);
    free(rez_filename);
    free(words);
    return 0;
}
void files (FILE *thefile, char *filename, char *format){
    scanf("%s", filename);
    thefile = fopen(filename, format); 
    while (thefile == NULL)
    {
        printf("Try again: ");
        scanf("%s", filename);
        thefile = fopen(filename, format);
    }
}
void finding_begin_end(int i, int *first_position, int *last_position, int lenght, char *words)
{
    if ((*first_position) < 0) // if the first letter hasn't been found
    { 
        if (!isspace(*(words + i)))
        {
            (*first_position) = i;
        }
    }
    if ((*first_position) >= 0 && (*last_position) < 0) // if the last letter of the word hasn't been found yet
    { 
        if (isspace(*(words + i))) // if theres a whitespace
        { 
            (*last_position) = i - 1;
        }
        else if (i == (lenght - 1)) // if the the symbol is the last in the line
        { 
            (*last_position) = i;
        }
    }
}
void check_palindrome(int k, int l, int *first_position, int *last_position, char *words, int *num_letters, int *palindrome, int *p_exists, FILE *rezfile)
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
        print_results(k, first_position, last_position, words, palindrome, rezfile);
    }
    (*num_letters) = 0;
    (*first_position) = -1; // so we can search for the next word, brackets are necessary because pointers are read from right to left
    (*last_position) = -1;
}
void print_results(int k, int *first_position, int *last_position, char *words, int *palindrome, FILE *rezfile) //we need * because it was already a pointer in the previous function
{
    if ((*palindrome) == 1)
    {
        fprintf(rezfile, "The palindromes that were found in the file: ");
    }
    for (k = *first_position; k <= *last_position; k++)
    {
        fprintf(rezfile, "%c", (*(words + k)));
    }
    fprintf(rezfile, " ");
}
