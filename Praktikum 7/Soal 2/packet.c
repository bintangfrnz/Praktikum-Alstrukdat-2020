/*
 * NIM          : 13519138
 * Nama         : Bintang Fajarianto
 * Tanggal      : 08 Oktober 2020
 * Praktikum    : 7
 * Soal         : 2
 */

// File: prioqueue.c

#include <stdio.h>
#include <stdlib.h>
#include "prioqueuechar.h"

int main() {
    /* KAMUS */
    PrioQueueChar Q;
    int i, N, urut;
    infotype CC;

    /* ALGORITMA */
    scanf("%d",&N);
    MakeEmpty(&Q, N);

    urut = 1;
    for (i = 1; i <= N; i++) {
        scanf("%d %c", &Prio(CC), &Info(CC));
        Enqueue(&Q, CC);
        while (Prio(InfoHead(Q)) == urut) {
            Dequeue(&Q, &CC);
            printf("%d %c\n", i, Info(CC));
            urut++;
        }
    }
    return 0;
}