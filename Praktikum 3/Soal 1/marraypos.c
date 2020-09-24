/*
 * NIM       : 13519138
 * Nama      : Bintang Fajarianto
 * Tanggal   : 10 September 2020
 * Praktikum : 3
 * Soal		 : 1
 */

// File: marraypos.c
// Deskripsi
/*  Program membuat Array dengan elemen efektif sebanyak N dan menampilkannya.
    Kemudian, program menerima bilangan X dan mendeskripsikannya apakah X
    maksimum, minimum, atau median.
*/

#include <stdio.h>
#include "arraypos.h"

int main() {
    /* KAMUS */
    TabInt T;
    int X, panjang;
    int minEl = -1, maxEl = -1;
    int median = 0;

    /* ALGORITMA */
    BacaIsi(&T);
    scanf("%d", &X);
    TulisIsiTab(T);
    printf("\n");

    panjang = NbElmt(T);
    if (!SearchB(T, X)) { // Saat X tidak ada dalam Array
        printf("%d tidak ada\n", X);
    } else {
        printf("%d\n", Search1(T, X));
        MaxMin(T, &maxEl, &minEl);
        Sort(&T, true);
        if ((panjang % 2) != 0) {
            median = panjang/2;
        } else {
            median = (panjang/2)-1;
        }

        if (X == maxEl) { // Saat X nilai minimum
            printf("maksimum\n");
        }

        if (X == minEl) { // Saat X nilai maksimum
            printf("minimum\n");
        }

        if (Elmt(T,median) == X && median >= 0) { // Saat X adalah median
            printf("median\n");
        }
    }
    return 0;
}
