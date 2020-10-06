/*
 * NIM          : 13519138
 * Nama         : Bintang Fajarianto
 * Tanggal      : 17 September 2020
 * Praktikum    : 4
 * Soal         : 1
 */

// File: marraydin.c

#include <stdio.h>
#include <stdlib.h>
#include "arraydin.h"

void showIt(TabInt T);

int main() {
    /* KAMUS */
    TabInt T;
    int MaxEl, Q;
    int op, num;

    /* ALGORITMA */
    // Inisialisasi Tabel
    scanf("%d", &MaxEl);
    MakeEmpty(&T, MaxEl);
    BacaIsi(&T);

    // Operasi utama
    scanf("%d",&Q);
    for(int i = 0; i < Q; i++){
        scanf("%d",&op);
        if (op == 1) {
            scanf("%d",&num);
            if (IsFull(T)) {
                printf("array sudah penuh\n");
            } else {
                AddAsLastEl(&T,num);
                showIt(T);
            }
        } else if (op == 2){
            scanf("%d",&num);
            GrowTab(&T,num);
            showIt(T);

        } else if (op == 3) {
            scanf("%d",&num);
            if (T.MaxEl < num) {
                printf("array terlalu kecil\n");
            } else {
                ShrinkTab(&T,num);
                showIt(T);
            }
        } else if (op == 4) {
            CompactTab(&T);
            showIt(T);
        }
    }
    return 0;
}

void showIt (TabInt Tab)
{ /* ALGORITMA */
    printf("%d ",Tab.MaxEl);
    TulisIsiTab(Tab);
    printf("\n");
}

