//Vartotojas įveda tris natūraliuosius skaičius (a, b, c). Programa turi atspausdinti du skaičius – šių trijų skaičių 
//didžiausią bendrąjį daliklį (DBD) bei mažiausiąjį bendrą kartotinį (MBK)
int gcd(int nr1, int nr2);
int lcm(int nr1, int nr2);
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int a, b, c;
    printf ("You will have to inout 3 whole, positive numbers\n");
    printf ("The program will find 2 numbers: greatest common divisor, lowest common multiple\n");
    printf ("Input decimal a, b and c: ");
    if(!scanf("%d", &a) || !scanf("%d", &b) || !scanf("%d", &c) || a<1 || b<1 || c<1 )
    {
        printf ("Wrong input, sorry");
        exit(1);
    }

    printf ("Greatest common divisor of %d, %d, %d is %d\n", a, b, c, gcd((a, b), c));

    printf ("Lowest common multiple of %d, %d, %d is %d", a, b, c, lcm((a, b), c));
    return 0;
}
int gcd(int nr1, int nr2)
{
    if (nr1 == 0){  //until it turns into 0, so it stops
        return nr2;
    }
    return gcd(nr2 % nr1, nr1);
}

int lcm(int nr1, int nr2)
{
    return (nr1 / gcd(nr1, nr2)) * nr2;
}
