// TASK
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>  //for isspace
void validacija(int eilut, int stulp, int N, int skaicius[][N + 1], int sveikieji[]);
void pozicija_max_min(int eilut, int stulp, int N, int skaicius[][N + 1], int stulp_max[][N + 1], int stulp_min[][N + 1], int maximum[], int minimum[]);
void pasikartojanciu_paieska(int i, int j, int N, int kartojasi_max, int kartojasi_min, int stulp_max[][N + 1], int stulp_min[][N + 1], int eilut, int stulp, int maximum[], int minimum[], int skaicius[][N + 1]);
void isvedimas(int eilut, int N, int maximum[], int minimum[], int i, int stulp_max[][N + 1], int stulp_min[][N + 1]);
int main()
{
    int N;
    printf("Kokio dydzio lenteles norite: "); // N*N
    scanf("%d", &N);
    int skaicius[N + 1][N + 1], sveikieji[N + 1]; // kiek sveikuju buvo ivesta i viena eilute
    int eilut, stulp;
    int minimum[N + 1], maximum[N + 1], stulp_max[N + 1][N + 1], stulp_min[N + 1][N + 1]; // max and min in every line and their positions
    int kartojasi_max, kartojasi_min;
    int i, j;
    printf("Iveskite %d eilutes, kuriose butu %d sveikieji skaiciai:\n", N, N); 
    for (eilut = 1; eilut <= N; eilut++)
    {
        validacija(eilut, stulp, N, skaicius, sveikieji);
        if (sveikieji[eilut] < N)
        {
            printf("Netinkami duomenys, is naujo iveskite sia eilute: ");
            eilut--;
        }
        else
            pozicija_max_min(eilut, stulp, N, skaicius, stulp_max, stulp_min, maximum, minimum);
    }
    pasikartojanciu_paieska(i, j, N, kartojasi_max, kartojasi_min, stulp_max, stulp_min, eilut, stulp, maximum, minimum, skaicius);
    isvedimas(eilut, N, maximum, minimum, i, stulp_max, stulp_min);
    return 0;
}
void validacija(int eilut, int stulp, int N, int skaicius[][N + 1], int sveikieji[])
{
    sveikieji[eilut] = 0; //cia tam, kad paskui zinot ar eiluteje buvo ivesta sveikuju ar visai jokiu nebuvo
    for (stulp = 1; stulp <= N; stulp++)
    {
        if (scanf("%d", &skaicius[eilut][stulp]) == 1 && isspace(getchar()))
        {
            sveikieji[eilut]++;
        }
        else
            while (!isspace(getchar())); // imti simbolius, kol nera tarpas arba nauja eilute, iki non-white space
    }
}
void pozicija_max_min(int eilut, int stulp, int N, int skaicius[][N + 1], int stulp_max[][N + 1], int stulp_min[][N + 1], int maximum[], int minimum[])
{
    for (stulp = 1; stulp <= N; stulp++) // max ir min prilyginam pirmam ivestam skaiciui, kad paskui butu su kuo lyginti 
    {
        if (stulp == 1)
        {
            maximum[eilut] = skaicius[eilut][stulp];
            minimum[eilut] = skaicius[eilut][stulp];
            stulp_max[eilut][0] = stulp;
            stulp_min[eilut][0] = stulp;
        }
        else if (skaicius[eilut][stulp] > maximum[eilut]) 
        {
            maximum[eilut] = skaicius[eilut][stulp];
            stulp_max[eilut][0] = stulp;
        }
        else if (skaicius[eilut][stulp] < minimum[eilut])
        {
            minimum[eilut] = skaicius[eilut][stulp];
            stulp_min[eilut][0] = stulp;
        }
    }
}
void pasikartojanciu_paieska(int i, int j, int N, int kartojasi_max, int kartojasi_min, int stulp_max[][N + 1], int stulp_min[][N + 1], int eilut, int stulp, int maximum[], int minimum[], int skaicius[][N + 1])
{
    for (eilut = 1; eilut <= N; eilut++)
    {
        i = 1;
        j = 1;
        kartojasi_max = 0;  // ar jis kartojasi ar ne
        kartojasi_min = 0;
        stulp_max[eilut][i] = 0; // kuriame stulpelyje yra pasikartojantis
        stulp_min[eilut][j] = 0;
        for (stulp = 1; stulp <= N; stulp++)
        {
            if (maximum[eilut] == skaicius[eilut][stulp]) 
            {
                kartojasi_max++;
            }
            if (minimum[eilut] == skaicius[eilut][stulp])
            {
                kartojasi_min++;
            }
            if (kartojasi_max > i) //daugiau uz i (is pradziu 1), nes bus iskaiciuota ir originalus maximumas, ai ziurim ar yra daugiau uz 1
            {
                stulp_max[eilut][i] = stulp; //jeigu randam dar viena maximuma, tai irgi isaugojam jo stulpeli i-tojoje pozicijoje
                i++;
                stulp_max[eilut][i] = 0; //nes isvedime ves iki tol, kol bus 0, tai kad nesuktu papildomo ciklo 
            }
            if (kartojasi_min > j)
            {
                stulp_min[eilut][j] = stulp;
                j++;
                stulp_min[eilut][j] = 0;
            }
        }
    }
}
void isvedimas(int eilut, int N, int maximum[], int minimum[], int i, int stulp_max[][N + 1], int stulp_min[][N + 1])
{
    for (eilut = 1; eilut <= N; eilut++)
    {
        if (maximum[eilut] == minimum[eilut])
        {
            printf("%d eiluteje nera didziausio ar maziausio, nes buvo ivesti tie patys skaiciai\n", eilut);
        }
        else
        {
            printf("%d eilutes didziausias skaicius yra %d, esantis %d", eilut, maximum[eilut], stulp_max[eilut][0]);
            i = 1;
            while (stulp_max[eilut][i])
            {
                printf(", %d", stulp_max[eilut][i]);
                i++;
            }
            printf(" stulpelyje, o maziausias %d, esantis %d", minimum[eilut], stulp_min[eilut][0]);
            i = 1;
            while (stulp_min[eilut][i])
            {
                printf(", %d", stulp_min[eilut][i]);
                i++;
            }
            printf(" stulpelyje\n");
        }
    }
}
