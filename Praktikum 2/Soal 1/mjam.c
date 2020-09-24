/*
 * NIM       : 13519138
 * Nama      : Bintang Fajarianto
 * Tanggal   : 03 September 2020
 * Praktikum : 2
 * Soal		 : 1
 */

// File: mjam.c

#include <stdio.h>
#include "jam.h"

int main(){
    /* KAMUS */
    JAM J1, J2;
    int N, mundur;
    long S1, S2, min, max;
    min = 86400;
    max = 0;

    /* ALGORITMA */
    scanf("%d", &N);
    mundur = N;
    while (mundur > 0) {
        mundur -= 1;
        printf("[%d]\n", N-mundur);
        BacaJAM(&J1);
        BacaJAM(&J2);
        S1 = JAMToDetik(J1);
        S2 = JAMToDetik(J2);
        if (JGT(J1, J2)){
            printf("%li", Durasi(J2, J1));
        } else {
            printf("%li", Durasi(J1, J2));
        }
        if (S1 > max){
            max = S1;
        }
        if (S2 > max){
            max = S2;
        }
        if (S1 < min){
            min = S1;
        }
        if (S2 < min){
            min = S2;
        }
        printf("\n");
    }
    TulisJAM(DetikToJAM(min));
    printf("\n");
    TulisJAM(DetikToJAM(max));
    printf("\n");

    return 0;
}