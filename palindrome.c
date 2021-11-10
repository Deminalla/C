//Parašyti funkciją, kuri randa ir atspausdina visus žodžius, kurie vienodai skaitomi iš pradžios ir iš galo
//14:00 - 15:00     1 hour for reading, creating file
//15:00 - 15:30     30 min for calloc and free
#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *myfile, *rezfile;
    char *my_filename, *rez_filename;
    char *words;
    int i=0;
    int success=0;
    while (!success){
    printf("Please enter a .txt file name to analyze: ");
    gets(my_filename);  //why does this work but not scanf("%c", &filename);?
    myfile = fopen(my_filename, "r"); //open file for reading
    if (myfile == NULL){
        printf ("Could not open file for reading\n"); 
        success=0;
    }
    else success=1;
    }
    words = (char*) calloc(255, sizeof(char));
    if (words==NULL){
        printf("Memory could not be allocated\n");
    }

    while (fgets(words, 255, myfile)!=NULL){ //maximum 255 symbols in each line
    //for (i=0; i<=255; i++){printf ("%c", *(words+i));} 
    }
    success=0;
    while (!success){
    printf("Please enter a .txt file name to write the results to: ");
    gets(rez_filename);
    rezfile = fopen(rez_filename, "a+"); //create file for writing at the eof each time
    if (rezfile == NULL){ 
        printf ("Could not create file\n");
        success=0;
    }
    else success=1;
    }
    free(words);
    fclose(myfile);
    fclose(rezfile);
    return 0;
}
