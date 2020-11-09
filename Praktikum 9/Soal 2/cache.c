/*
 * NIM          : 13519138
 * Nama         : Bintang Fajarianto
 * Tanggal      : 05 November 2020
 * Praktikum    : 9
 * Soal         : 2
 */

// File: cache.c

#include <stdio.h>
#include "listlinier.h"

int main() {
    /* KAMUS */
    List L;
    address P;
    infotype X;
	int N, M; // M proses
    int i, dummy;


	/* ALGORITMA */
    scanf("%d",&N);
    scanf("%d",&M);

    CreateEmpty(&L);
    for(i = 1; i <= N; i++) {
        InsVLast(&L, i);
    }

    for(i = 0; i < M; i++) {
        scanf("%d",&X);
        P = Search(L,X);
        if (P != Nil) {
            DelP(&L,X);
            InsVFirst(&L,X);
            printf("hit ");
            PrintInfo(L);
            printf("\n");
        } else {
            InsVFirst(&L,X);
            DelVLast(&L,&dummy);
            printf("miss ");
            PrintInfo(L);
            printf("\n");
        }
    }
    return 0;
}