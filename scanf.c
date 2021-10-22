#include <stdio.h>
int main(){
    char str1[256] = {0}; //visos reiksmes bus (null), ju neatspausdins, nebent specifiskai prasyisim
    char str2[256] = {0};
    int x, y;
    printf ("%s\n", str1[5]); //(null)

    scanf ("%s", &str1); //if we input 145, then the output will also be 145, it wont output the other (null)
    printf("%s\n", str1);
    fscanf (stdin, "%s", &str1); //same thing as scanf, reads from the keyboard

    sscanf (str1, "%s", &str2); //will read from str1, not from the keyboard anymore 
    printf("%s\n", str2); //will print out str1

    sscanf (str1, "(%d,%d)", &x, &y); // will only scan if its int eh format shown, for example, (12,56), if we made it "[%d/%d]" then it would onlcy accept [12/56]
    printf ("[%d - %d]", x, y); //output: [12 - 56], nes x=12, y=56

    scanf("%d %d", &x, &y) == 2; //2, since we verify 2 variables instead of 1 (will check if the input was correct, matches the given format)

    return 0;
}
