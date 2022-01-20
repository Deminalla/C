#include <stdio.h>
#include <stdlib.h>
int add(int a, int b);
void greet(char *name);
void A();
void B(void (*ptr)()); //B takes function pointer as argument, ptr points to a void function with no arguments
int main()
{
    int a, b, c;
    int (*p)(int, int); 
    p = &add;  //or simply add
    c = (*p)(3, 2); //or simply p(3, 2)
    printf("c is %d\n", c);

    void (*k)(char*); //if its a void type function
    k = greet; //function address
    k("Jinx"); //execute function

    void (*t)() = A;
    B(t); //B takes function A as an argument, or simply B(A)
    return 0;
}
int add(int a, int b){
    return a+b;
}
void greet(char *name){
    printf("Hi %s\n", name);
}
void A(){
    printf("Welcome\n");
}
void B(void (*ptr)()){
    ptr(); //calls the function it's pointing to
}
