/*
 * NIM          : 13519138
 * Nama         : Bintang Fajarianto
 * Tanggal      : 22 Oktober 2020
 * Praktikum    : 8
 * Soal         : 2
 */

// File: backspace.c

#include <stdio.h>
#include "stackt.h"

int main() {
    /* KAMUS */
    int N, M, i, temp, trash;
    Stack Sn, Sm;
    boolean isSame;

    /* ALGORITMA */
    CreateEmpty(&Sn);
    CreateEmpty(&Sm);

    scanf("%d %d", &N, &M);

    for(i=0; i < N; i++) {
        scanf("%d", &temp);
        if (temp != 0) {
            Push(&Sn, temp);
        } else {
            if (!IsEmpty(Sn)) {
                Pop(&Sn, &trash);
            }
        }
    }
    for(i=0; i < M; i++) {
        scanf("%d", &temp);
        if (temp != 0) {
            Push(&Sm, temp);
        } else {
            if (!IsEmpty(Sm)) {
                Pop(&Sm, &trash);
            }
        }
    }

    isSame = (Sn.TOP == Sm.TOP);
    while(isSame && Sn.TOP != Nil) {
        if (InfoTop(Sn) == InfoTop(Sm)) {
            Pop(&Sn, &trash);
            Pop(&Sm, &trash);
        } else {
            isSame = false;
        }
    }

    if (isSame) printf("Sama\n");
    else printf("Tidak sama\n");

    return 0;
}