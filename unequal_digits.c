//Įvesti sveikų skaičių seką, kurios pabaiga žymima skaičiumi 0. Išvesti narių, kurių skaitmenų suma nelyginė, skaičių. 
//input integer numbers, the sequence should end with 0. Output the amount of times the input integers' digits' numbers added up to an unequal number
#include <stdio.h>

int main()
{
    int nelyg_nariai;
    int skaicius=1, suma;
    int laikinas_sk;

    while(skaicius!=0)
    {
        printf("Ivesk skaiciu: ");
        if(scanf("%d", &skaicius)==1)
        {
            if (skaicius<0)
            {
                skaicius = skaicius*(-1);
            }
            suma = 0;
            laikinas_sk = skaicius;
            while (laikinas_sk!=0)
            {
                suma = suma + laikinas_sk%10;  //the last digit of a number is added
                laikinas_sk = laikinas_sk/10;  //the last digit is taken out of the number
            }
            if (suma%2==1)
            {
                nelyg_nariai++;
            }
        }
        else while (getchar()!='\n'); //in case a letter or words are scanned, this cycle will get rid of all the symbols until the end of the line
    }   //if we input elements on the same line with spaces (4 asd gred 56), then we'd need it to ignore symbols until a spacebar so getchar()!=' '
    printf("Nariu, kuriu skaitmenu suma nelygine, skaicius: %d", nelyg_nariai);
    return 0;
}


