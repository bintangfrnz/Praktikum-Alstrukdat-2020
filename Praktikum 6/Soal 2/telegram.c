/*
 * NIM          : 13519138
 * Nama         : Bintang Fajarianto
 * Tanggal      : 01 Oktober 2020
 * Praktikum    : 6
 * Soal         : 2
 */

// File: telegram.c

#include <stdio.h>
#include "mesinkata.h"

boolean EndKata;
Kata CKata; Kata TITIK; Kata KOMA;

boolean IsKataSama(Kata K1, Kata K2);
void Titik_Koma();

int main() {
    /* KAMUS */
    int countReg = 0; int countPanj = 0; int price = 0; int countTK = 0;

    /* ALGORITMA */
    STARTKATA();
    Titik_Koma();
    while (!EndKata) {
        IgnoreBlank();
        if (!IsKataSama(CKata, TITIK) && !IsKataSama(CKata, KOMA)) {
            if (countPanj + countReg + countTK > 0) {
                printf(" ");
            }
            for (int i=0; i < CKata.Length; i++){
                printf("%c",CKata.TabKata[i]);
            }
            (CKata.Length >= 10) ? countPanj++ : countReg++;
        } else {
            (IsKataSama(CKata, TITIK)) ? printf(".") : printf(",");
            countTK++;
        }
        IgnoreBlank();
        ADVKATA();
    }
    price = countPanj*1500 + countReg*1000;
    price = (countPanj + countReg + countTK > 10) ? price - 10*price/100 : price;
    printf("\n%d\n%d\n%d\n", countReg, countPanj, price);

    return 0;
}

void Titik_Koma()
{ /* ALGORITMA */
    TITIK.Length = 5;
    TITIK.TabKata[0] = 'T';
    TITIK.TabKata[1] = 'I';
    TITIK.TabKata[2] = 'T';
    TITIK.TabKata[3] = 'I';
    TITIK.TabKata[4] = 'K';

    KOMA.Length = 4;
    KOMA.TabKata[0] = 'K';
    KOMA.TabKata[1] = 'O';
    KOMA.TabKata[2] = 'M';
    KOMA.TabKata[3] = 'A';
}

boolean IsKataSama(Kata K1, Kata K2)
{ /* KAMUS */
    boolean isSame;
    int idx = 0;
    /* ALGORITMA */
    isSame = (K1.Length == K2.Length);
    while ((idx < K1.Length) && (isSame)){
        if (K1.TabKata[idx] != K2.TabKata[idx]) {
            isSame = false;
        }
        idx++;
    }
    return isSame;
}