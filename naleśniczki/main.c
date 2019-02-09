#include <stdio.h>
#include <stdlib.h>

int czy_posortowany(int stos[], int n){  //posortowany: bul = 2, nieposortowany: bul = 1
    int bul = 0;
    int i;
    for(i = 0; i < n - 1; i++){
        if(stos[i] > stos[i + 1]){
            bul = 1;
            break;
        }
        else
            bul = 2;
    }
    return bul;
}

int znajduje_najwiekszy(int stos[], int n){
    int tmp = stos[0];
    int i;
    int znacznik = 0;
    for (i = 0; i +1 <= n; i++){
        if(tmp < stos[i]){
            tmp = stos[i];
            znacznik = i;
        }
    }
    return znacznik;
}

void obrot(int stos[], int n){
    int i;
    int tmp = 0;
    for(i = 0; i < (n/2); i++){
        tmp = stos[n - i - 1];
        stos[n - i - 1] = stos[i];
        stos[i] = tmp;
    }
}

int main(int argc, char *argv[])
{
    int i;
    int n = 0; // po kazdym ulozeniu najwiekszej na dole zwieksza sie o jeden
    int stos[100];
    int ilosc_elementow = 0;
    for(i = 1; i < argc; i++){
        stos[i - 1] = atoi(argv[i]);
        ilosc_elementow++;
    }
    while (czy_posortowany(stos, ilosc_elementow) == 1){  //pêtla wykonywana do momentu posortowania
            printf("%i \n", (znajduje_najwiekszy(stos, ilosc_elementow-n)+1));
            obrot(stos, (znajduje_najwiekszy(stos, ilosc_elementow-n)+1));
         //   for(i = 0; i < ilosc_elementow; i++)
           //     printf("%i ", stos[i]);
          //  printf("\n");
            obrot(stos, ilosc_elementow - n);
            n++;
           // printf("%i \n", (znajduje_najwiekszy(stos, ilosc_elementow-n)+1));
            for(i = 0; i < ilosc_elementow; i++)
                printf("%i ", stos[i]);
            printf("\n");
    }
    printf("\nNalesniki posortowane!\n");
    return 0;
}
