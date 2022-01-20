#include <stdio.h>
#include <stdlib.h>
int add(int a, int b);
float sum(float e, float f);
float sub(float e, float f);
float mul(float e, float f);
float divi(float e, float f);
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

    int choice, e=6, f=2;
    scanf("Whcih function to execute: %d", &choice);
    float (*math[4])(float, float) = {sum, sub, mul, div};
    printf("%f", math[choice](e, f));
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
float sum(float e, float f){
    return e+f;
}
float sub(float e, float f){
    return e-f;
}
float mul(float e, float f){
    return e*f;
}
float divi(float e, float f){
    return e/f;
}
