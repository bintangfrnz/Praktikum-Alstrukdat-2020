/*
 * NIM          : 13519138
 * Nama         : Bintang Fajarianto
 * Tanggal      : 24 September 2020
 * Praktikum    : 5
 * Soal         : 2
 */

// File: nilaikelas.c

#include <stdio.h>
#include "matriks.h"

void TulisNilaiX(MATRIKS M, indeks j, ElType X);
void TulisStatistikMhs(MATRIKS M, indeks i);
void TulisStatistikMK(MATRIKS M, indeks j);

int main() {
    /* KAMUS */
    indeks i, j;
    int n, m;
    MATRIKS M;

    /* ALGORITMA */
    // inisialisasi matriks
    scanf("%d", &n);
    scanf("%d", &m);
    BacaMATRIKS(&M, n, m);

    // menampilkan keluaran
    printf("STATISTIK PER MAHASISWA\n");
    for (i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++) {
        TulisStatistikMhs(M, i); printf("\n");  
    }
    printf("STATISTIK PER MATA KULIAH\n");
    for (j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); j++) {
        TulisStatistikMK(M, j); printf("\n");
    }
    return 0;
}

// procedure TulisNilaiX
void TulisNilaiX(MATRIKS M, indeks j, ElType X)
{ /* KAMUS */
    indeks i;
    int countX = CountXKol(M, j, X);
    int count = 0;
    /* ALGORITMA */

    printf("[");
    for(i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++) {
        if (Elmt(M,i,j) == X) {
            count++;
            printf("%d",i);
            printf((count == countX) ? "]" : ",");
        }
    }
}

// procedure TulisStatistikMhs
void TulisStatistikMhs(MATRIKS M, indeks i)
{ /* KAMUS */
    int max = 0;
    int min = 0;
    float rata;

    /* ALGORITMA */
    rata = RataBrs(M, i);
    MaxMinBrs(M, i, &max, &min);

    // Menuliskan keluaran
    printf("[%d] %.2f %d %d", i, rata, max, min);
}

// procedure TulisStatistikMK
void TulisStatistikMK(MATRIKS M, indeks j)
{ /* KAMUS */
    int max = 0, min = 0;
    int countMax = 0, countMin = 0;
    float rata;

    /* ALGORITMA */
    rata = RataKol(M, j);
    MaxMinKol(M, j, &max, &min);
    countMax = CountXKol(M, j, max);
    countMin = CountXKol(M, j, min);

    // Menuliskan keluaran
    printf("[%d]", j);
    printf(" %.2f", rata);
    printf(" [");
    printf("%d", max);
    printf(" %d ", countMax);
    TulisNilaiX(M, j, max);
    printf("]");
    printf(" [");
    printf("%d", min);
    printf(" %d ", countMin);
    TulisNilaiX(M, j, min);
    printf("]");
}