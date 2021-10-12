#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    int sk=1;
    int c;
    int sk1, sk2;
    int i=0, j=0;
    while (sk!=0){
        c=scanf("%d", &sk);
        if (c==1 && isspace(getchar())){
        if (sk==0){
            break;
        }
        if (sk<0 || sk>999999999){
            printf ("%d bloga ivestis\n", sk);
        }
        else if(sk==2 || sk==3 || sk==5 || (sk!=1 && sk%2!=0 && sk%3!=0 && sk%5!=0)){
            printf ("%d pirminis\n", sk);
        }
        else {
            sk1 = sk;
            sk2 = sk;
            while (1){
                sk1++;
                sk2--;
            if (sk1==2 || sk1==3 || sk1==5 || (sk1!=1 && sk1%2!=0 && sk1%3!=0 && sk1%5!=0)){
                i++;
            }
            if (sk2>1 && (sk2==2 || sk2==3 || sk2==5 || (sk2%2!=0 && sk2%3!=0 && sk2%5!=0))){
                j++;
            }
            if (i==1 && j==1){
                printf ("%d ne pirminis, bet artimiausi yra %d ir %d\n", sk, sk1, sk2);
                break;
            }
            else if (i==1){
                printf ("%d ne pirminis, bet artimiausias yra %d\n", sk, sk1);
            break;
            }
            else if (j==1){
            printf ("%d ne pirminis, bet artimiausias yra %d\n", sk, sk2);
            break;
            }
            }
        }
        }
        else{
            while (!isspace(getchar()));
            printf ("bloga ivestis\n", sk);
            }
    }
    return 0;
}

//vartotojas ivedineja skaicius (sveikieji)
//gali spausti enter ar deti tarpus or whatever
//rasyt kad bloga ivestis, kurie yra realieji skaičiai, neigiami skaičiai, žodžiai kur yra raidės, visokie ženklai, turėtų būti atmetami kaip netinkami
//0 yra programos pabaiga
//ar tas skaicius pirminis (jei taip, taip ir rasyt)
//jeigu ne pirminis, tai atspausdint asrciausiai esanti pirmini, jeigu vienodai arti tai abu atspausdinti
//negalima masyvu
//negalima papildomo failo
//jeigu vidury ivedimo yra 0 tai ten ir baigti

//1) jei norite, galite naudotis biblioteka ctype.h, skirtukams tikrinti
//2) prieš darant, pasižiūrėkite į funkcijos scanf galimybes (o būtent, į scanset) bei į funkciją (jei reikia) ungetc - abi gyvena stdio.h

//2 3 5   2 pirminis  3 pirminis    5 pirminis
//5 a 9   5 pirminis  bloga ivestis   9 ne pirminis, artimiausi 7 ir 11

