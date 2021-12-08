#include "main.h"
#include <stdio.h>
void read_file(FILE *list_file, char *list_filename)
{
    printf("Name of the file which contains the values of the list: ");
    scanf("%s", list_filename);
    list_file = fopen(list_filename, "r");
    if (list_file == NULL)
    {
        read_file(list_file, list_filename); // recursion
    }
}
