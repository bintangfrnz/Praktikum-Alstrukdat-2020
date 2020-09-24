/*
 * NIM       : 13519138
 * Nama      : Bintang Fajarianto
 * Tanggal   : 10 September 2020
 * Praktikum : 3
 * Soal		 : 2
 */

// File: array_mono.c
// Deskripsi
/*  Program membuat Array dengan elemen efektif sebanyak N.
 *  Program menentukan apakah Array tersebut:
 *     a. Array monotonik tidak mengecil
 *     b. Array monotonik tidak membesar
 *     c. Array monotonik statik
 *     d. Array tidak monotonik
 */

#include <stdio.h>
#include "arraypos.h"

int main() {
    /* KAMUS */
    TabInt T, Ta, Td;
    boolean besar, kecil;
    int i;

    /* ALGORITMA */
    // Baca array utama T dan mengcopy ke Ta (Asc) dan Td (Dsc)
    BacaIsi(&T);
    Ta = T;
    Td = T;
    
    // Sortir dan melihat apakah T membesar atau mengecil atau tidak
    Sort(&Ta, true);
    Sort(&Td, false);
    besar = IsEQ(T,Ta);
    kecil = IsEQ(T,Td);
    
    // Mengeluarkan hasil akhir
    if (besar && kecil) {
        printf("Array monotonik statik\n");
    } else {
        if (besar) {
            printf("Array monotonik tidak mengecil\n");
        } else if (kecil) {
            printf("Array monotonik tidak membesar\n");
        } else {
            printf("Array tidak monotonik\n");
        }
    }
    return 0;
}