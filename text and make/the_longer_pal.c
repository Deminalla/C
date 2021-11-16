// Parašyti funkciją, kuri randa ir atspausdina visus žodžius, kurie vienodai skaitomi iš pradžios ir iš galo
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <ctype.h>  
void finding_begin_end(int i, int *first_position, int *last_position, int lenght, char *words);
void check_palindrome(int k, int l, int *first_position, int *last_position, char *words, int *num_letters, int *palindrome, int *p_exists, FILE *rezfile);
void print_results (int k, int *first_position, int *last_position, char *words, int *palindrome, FILE *rezfile);
int main()
{
    FILE *myfile, *rezfile;
    char *my_filename, *rez_filename;
    char *words;
    int i, k, l, skip, part=0;
    int lenght;
    int first_position = -1, last_position = -1;
    int num_letters = 0; 
    int palindrome = 0, p_exists=0;

    my_filename = (char *)calloc(100, sizeof(char));
    if (my_filename == NULL)
    {
        printf("Memory for file could not be allocated\n");
    }
    rez_filename = (char *)calloc(100, sizeof(char));
    if (rez_filename == NULL)
    {
        printf("Memory for file could not be allocated\n");
    }

first_file:
    printf("Please enter a .txt file name to analyze: ");
    scanf("%s", my_filename);
    myfile = fopen(my_filename, "r"); 
    if (myfile == NULL)
    {
        printf("Could not open file for reading\n");
        goto first_file;
    }
second_file: //funkcija, jei while tai bus +0.5 o ne +1
    printf("Please enter a .txt file name to write the results to: ");
    scanf("%s", rez_filename);
    rezfile = fopen(rez_filename, "a");  
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

    while (fgets(words, 255, myfile) != NULL) //toliau skaito
    { 
        lenght = strlen(words);
        if (part==0 && (*(words + lenght-1))== '\n'){ //if we are reading the line for the first time and it's \n before 255
            part = 0;
            skip = 0; 
        }
        else if (part>0 && (*(words + lenght-1))== '\n'){ //if we have read more than once from this line but its the end now, then we need to skip this and read the next 255 part
            part=0; //so we can read the new line afterwards
            skip=1; //we need to read the next 255 symbols, basically skip this and go to the next line
        }
        else {
            part++; //we're going to read this more than once until we reach end of line
            skip = 0; //dont skip this block yet
        }
        if (part<=1 && skip!=1){ //we are reading for the first time 
        for (i = 0; i <= lenght - 1; i++)
        { 
            finding_begin_end(i, &first_position, &last_position, lenght, words);
            if (first_position >= 0 && last_position >= 0)
            {
                check_palindrome(k, l, &first_position, &last_position, words, &num_letters, &palindrome, &p_exists, rezfile);
                if (p_exists){
                print_results (k, &first_position, &last_position, words, &palindrome, rezfile);
                }
                else {
                    first_position = -1; 
                    last_position = -1;
                }
            }
        }
        
    }
    }
    if (!palindrome)
    {
        fprintf(rezfile, "Unfortunately, no palindromes were found in the file");
    }
    fclose(myfile);
    fclose(rezfile);
    free(myfile);
    free(rezfile);
    free(words);
    return 0;
}
void finding_begin_end(int i, int *first_position, int *last_position, int lenght, char *words)
{
    if ((*first_position) < 0)
    { 
        if (!isspace(*(words + i)))
        {
            (*first_position) = i;
        }
    }
    if ((*first_position) >= 0 && (*last_position) < 0)
    { 
        if (isspace(*(words + i))) 
        { 
            (*last_position) = i - 1;
        }
        else if (i == (lenght - 1))
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
        if (tolower(*(words + k)) == tolower(*(words + l))) 
        {
            (*num_letters)++;
        }
        k++;
    }
    if (*num_letters == (*last_position - *first_position + 1)) 
    {
        (*palindrome)++; 
        (*p_exists) = 1;
    }
    else {(*p_exists) = 0;}
    (*num_letters) = 0;
}
void print_results (int k, int *first_position, int *last_position, char *words, int *palindrome, FILE *rezfile){
    if ((*palindrome) == 1) 
        {
            fprintf(rezfile, "The palindromes that were found in the file: "); 
        }
    for (k = *first_position; k <= *last_position; k++)
        {
            fprintf(rezfile, "%c", (*(words + k))); 
        }
        fprintf(rezfile, " ");
    (*first_position) = -1; 
    (*last_position) = -1;
}
