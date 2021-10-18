// LSP *****************     ***********.com     2-os užduoties 5-tas variantas/numeris
#include <stdio.h>
#include <ctype.h> //reikalingas del isspace
void pozicija_max_min(int eilut, int stulp, int N, int skaicius[][N + 1], int stulp_max[][N+1], int stulp_min[][N+1], int maximum[], int minimum[], int sveikieji[]);
void pasikartojanciu_paieska(int i, int j, int N, int kartojasi_max, int kartojasi_min, int stulp_max[][N + 1], int stulp_min[][N + 1], int eilut, int stulp, int maximum[], int minimum[], int skaicius[][N + 1]);
void isvedimas(int eilut, int N, int sveikieji[], int maximum[], int minimum[], int i, int stulp_max[][N+1], int stulp_min[][N+1]);
int main()
{
    int N;
    printf("Kokio dydzio lenteles norite: "); // N*N
    scanf("%d", &N);
    int skaicius[N + 1][N + 1], sveikieji[N + 1]; // kiek sveikuju buvo ivesta i viena eilute
    int eilut, stulp, stulp_max[N + 1][N+1], stulp_min[N+1][N+1];                 // N-kiek yra eiluciu, 2-kad 0-intoje vietoje butu max o 1-oje min, kiekvienos eilutes max ir min stulpeliai
    int minimum[N + 1], maximum[N + 1];                       // max and min in every line
    int kartojasi_max, kartojasi_min;                         // ar kartojasi
    int i, j;

    for (eilut = 1; eilut <= N; eilut++)
    {
        sveikieji[eilut] = 0;
        for (stulp = 1; stulp <= N; stulp++)
        {
            if (scanf("%d", &skaicius[eilut][stulp]) == 1 && isspace(getchar())) //jeigu tai sveikasis, sokam i funkcija
            {
                pozicija_max_min(eilut, stulp, N, skaicius, stulp_max, stulp_min, maximum, minimum, sveikieji);
            }
            else //jeigu kazkokie simboliai ar dar kazkas
                while (!isspace(getchar())); // imti simbolius, kol nera tarpas arba nauja eilute, iki non-white space
        }
    }
    pasikartojanciu_paieska(i, j, N, kartojasi_max, kartojasi_min, stulp_max, stulp_min, eilut, stulp, maximum, minimum, skaicius); //ieskom kuriose stulepiuose yra pasikartojasntys ir ar isvis pasikartoja max min
    isvedimas(eilut, N, sveikieji, maximum, minimum, i, stulp_max, stulp_min);
    return 0;
}
void pozicija_max_min(int eilut, int stulp, int N, int skaicius[][N + 1], int stulp_max[][N+1], int stulp_min[][N+1], int maximum[], int minimum[], int sveikieji[])
{
    if (sveikieji[eilut] == 0)
    { 
        maximum[eilut] = skaicius[eilut][stulp];  // max ir min prilyginam pirmam ivestam skaiciui, kad paskui butu su kuo lyginti 
        minimum[eilut] = skaicius[eilut][stulp];
        stulp_max[eilut][0] = stulp;          //max min pozicijos/stulpeliai eiluteje
        stulp_min[eilut][0] = stulp;
    }
    else if (skaicius[eilut][stulp] > maximum[eilut])  //jeigu ivestas skaicius didesnis uz pries tai nustatyta maximuma
    {
        maximum[eilut] = skaicius[eilut][stulp];      //tai dabar yra naujas maximumas
        stulp_max[eilut][0] = stulp;               //maximumo stulpelis eiluteje
    }
    else if (skaicius[eilut][stulp] < minimum[eilut])
    {
        minimum[eilut] = skaicius[eilut][stulp];
        stulp_min[eilut][0] = stulp;
    }
    sveikieji[eilut]++;  //nu ir didinam ivestu sveikuju kieki, cia ateiciai, kad zinot, jog isvis yra eiluteje sveikasis ar ne
}
void pasikartojanciu_paieska(int i, int j, int N, int kartojasi_max, int kartojasi_min, int stulp_max[][N + 1], int stulp_min[][N + 1], int eilut, int stulp, int maximum[], int minimum[], int skaicius[][N + 1]){
    for (eilut = 1; eilut <= N; eilut++)
    {
        i = 1;
        j = 1;
        kartojasi_max = 0; // ar jis kartojasi ar ne
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
            if (kartojasi_max > 1)  //daugiau uz 1, nes bus iskaiciuota ir originalus maximumas, ai ziurim ar yra daugiau uz 1
            {
                stulp_max[eilut][i] = stulp;
                i++;
                stulp_max[eilut][i] = 0; //nes isvedime ves iki tol, kol bus 0, tai reikia sustabdyti 
                kartojasi_max--;
            }
            if (kartojasi_min > 1)
            {
                stulp_min[eilut][j] = stulp;
                j++;
                stulp_min[eilut][j] = 0;
                kartojasi_min--;
            }
        }
    }
}
void isvedimas(int eilut, int N, int sveikieji[], int maximum[], int minimum[], int i, int stulp_max[][N+1], int stulp_min[][N+1])
{
    for (eilut = 1; eilut <= N; eilut++) //pravarom po kiekviena eilute
    {
        if (sveikieji[eilut] == 0)  //jeigu sveikuju sk yra 0
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
        else //tada be kitu pries tai minetu variantu liko paminet kur max min yra
        {
            printf("%d eilutes didziausias skaicius yra %d, esantis %d", eilut, maximum[eilut], stulp_max[eilut][0]);
            i = 1;
                while (stulp_max[eilut][i]) //kol kart_max_st nera 0
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
