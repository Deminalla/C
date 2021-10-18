// LSP 2110527     denizaalijeva@gmail.com     2-os užduoties 5-tas variantas/numeris
#include <stdio.h>
#include <ctype.h> //reikalingas del isspace
void pozicija_max_min(int eilut, int stulp, int N, int skaicius[][N + 1], int stulp_maxmin[][2], int maximum[], int minimum[], int sveikieji[]);
void pasikartojanciu_paieska(int i, int j, int N, int kartojasi_max, int kartojasi_min, int kart_max_st[][N + 1], int kart_min_st[][N + 1], int eilut, int stulp, int maximum[], int minimum[], int skaicius[][N + 1]);
void isvedimas(int eilut, int N, int sveikieji[], int maximum[], int minimum[], int i, int kart_max_st[][N + 1], int kart_min_st[][N + 1], int stulp_maxmin[][2]);
int main()
{
    int N;
    printf("Kokio dydzio lenteles norite: "); // N*N
    scanf("%d", &N);
    int skaicius[N + 1][N + 1], sveikieji[N + 1]; // kiek sveikuju buvo ivesta i viena eilute
    int eilut, stulp, stulp_maxmin[N + 1][2];                 // N-kiek yra eiluciu, 2-kad 0-intoje vietoje butu max o 1-oje min
    int minimum[N + 1], maximum[N + 1];                       // max and min in every line
    int kartojasi_max, kartojasi_min;                         // ar kartojasi
    int kart_max_st[N + 1][N + 1], kart_min_st[N + 1][N + 1]; // kuriame stulpelyje yra pasikartojantis
    int i, j;

    for (eilut = 1; eilut <= N; eilut++)
    {
        sveikieji[eilut] = 0;
        for (stulp = 1; stulp <= N; stulp++)
        {
            if (scanf("%d", &skaicius[eilut][stulp]) == 1 && isspace(getchar()))
            {
                pozicija_max_min(eilut, stulp, N, skaicius, stulp_maxmin, maximum, minimum, sveikieji);
            }
            else
                while (!isspace(getchar())); // imti simbolius, kol nera tarpas arba nauja eilute, iki non-white space
        }
    }
    pasikartojanciu_paieska(i, j, N, kartojasi_max, kartojasi_min, kart_max_st, kart_min_st, eilut, stulp, maximum, minimum, skaicius);
    isvedimas(eilut, N, sveikieji, maximum, minimum, i, kart_max_st, kart_min_st, stulp_maxmin);
    return 0;
}
void pozicija_max_min(int eilut, int stulp, int N, int skaicius[][N + 1], int stulp_maxmin[][2], int maximum[], int minimum[], int sveikieji[])
{
    if (sveikieji[eilut] == 0)
    { // max ir min prilyginam pirmam ivestam skaiciui, kad paskui butu su kuo lyginti
        maximum[eilut] = skaicius[eilut][stulp];
        minimum[eilut] = skaicius[eilut][stulp];
        stulp_maxmin[eilut][0] = stulp;
        stulp_maxmin[eilut][1] = stulp;
    }
    else if (skaicius[eilut][stulp] > maximum[eilut])
    {
        maximum[eilut] = skaicius[eilut][stulp];
        stulp_maxmin[eilut][0] = stulp;
    }
    else if (skaicius[eilut][stulp] < minimum[eilut])
    {
        minimum[eilut] = skaicius[eilut][stulp];
        stulp_maxmin[eilut][1] = stulp;
    }
    sveikieji[eilut]++;
}
void pasikartojanciu_paieska(int i, int j, int N, int kartojasi_max, int kartojasi_min, int kart_max_st[][N + 1], int kart_min_st[][N + 1], int eilut, int stulp, int maximum[], int minimum[], int skaicius[][N + 1]){
    for (eilut = 1; eilut <= N; eilut++)
    {
        i = 1;
        j = 1;
        kartojasi_max = 0; // ar jis kartojasi ar ne
        kartojasi_min = 0;
        kart_max_st[eilut][i] = 0; // kuriame stulpelyje yra pasikartojantis
        kart_min_st[eilut][j] = 0;
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
            if (kartojasi_max > 1)
            {
                kart_max_st[eilut][i] = stulp;
                i++;
                kart_max_st[eilut][i] = 0; //nes isvedime ves iki tol, kol bus 0, tai reikia sustabdyti 
                kartojasi_max--;
            }
            if (kartojasi_min > 1)
            {
                kart_min_st[eilut][j] = stulp;
                j++;
                kart_min_st[eilut][j] = 0;
                kartojasi_min--;
            }
        }
    }
}
void isvedimas(int eilut, int N, int sveikieji[], int maximum[], int minimum[], int i, int kart_max_st[][N + 1], int kart_min_st[][N + 1], int stulp_maxmin[][2])
{
    for (eilut = 1; eilut <= N; eilut++) // rezultatai, isvedimas
    {
        if (sveikieji[eilut] == 0)
        {
            printf("%d eiluteje nera jokiu sveiku skaiciu\n", eilut);
        }
        else if (maximum[eilut] == minimum[eilut])
        {
            printf("%d eiluteje nera didziausio ar maziausio, nes ", eilut);
            if (sveikieji[eilut] == 1)
            {
                printf("buvo ivestas tik 1 sveikas skaicius\n");
            }
            else
                printf("buvo ivesti tie patys skaiciai\n");
        }
        else
        {
            printf("%d eilutes didziausias skaicius yra %d, esantis %d", eilut, maximum[eilut], stulp_maxmin[eilut][0]);
            i = 1;
            if (kart_max_st[eilut][i])
            {
                while (kart_max_st[eilut][i]) //kol kart_max_st nera 0
                {
                    printf(", %d", kart_max_st[eilut][i]);
                    i++;
                }
            }
            printf(" stulpelyje, o maziausias %d, esantis %d", minimum[eilut], stulp_maxmin[eilut][1]);
            i = 1;
            if (kart_min_st[eilut][i])
            {
                while (kart_min_st[eilut][i])
                {
                    printf(", %d", kart_min_st[eilut][i]);
                    i++;
                }
            }
            printf(" stulpelyje\n");
        }
    }
}
