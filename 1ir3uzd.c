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
                suma = suma + laikinas_sk%10;
                laikinas_sk = laikinas_sk/10;
            }
            if (suma%2==1)
            {
                nelyg_nariai++;
            }
        }
        else while (getchar()!='\n'); //pasalina visus simbolius iki tol kol ju nelieka
    }
    printf("Nariu, kuriu skaitmenu suma nelygine, skaicius: %d", nelyg_nariai);
    return 0;
}


