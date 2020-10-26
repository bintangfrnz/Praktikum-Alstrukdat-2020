/*
 * NIM          : 13519138
 * Nama         : Bintang Fajarianto
 * Tanggal      : 08 Oktober 2020
 * Praktikum    : 7
 * Soal         : 1
 */

// File: prioqueue.c

#include <stdio.h>
#include <stdlib.h>
#include "prioqueuechar.h"

/* ********* Prototype ********* */
boolean IsEmpty (PrioQueueChar Q)
/* Mengirim true jika Q kosong: lihat definisi di atas */
{ /* ALGORITMA */
    return (Head(Q) == Nil && Tail(Q) == Nil);
}

boolean IsFull (PrioQueueChar Q)
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
{ /* ALGORITMA */
    return (NBElmt(Q) == MaxEl(Q));
}

int NBElmt (PrioQueueChar Q)
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */
{ /* KAMUS */
    int count = 0;
    /* ALGORITMA */
    if (!IsEmpty(Q)) {
        count = ((MaxEl(Q) + Tail(Q) - Head(Q)) % MaxEl(Q)) + 1;
    }
    return count;
}

/* *** Kreator *** */
void MakeEmpty (PrioQueueChar * Q, int Max)
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */
{ /* ALGORITMA */
    (*Q).T = (infotype *) malloc (Max * sizeof(infotype));
    if ((*Q).T != NULL) {
        MaxEl(*Q) = Max;
    } else {
        MaxEl(*Q) = 0;
    }
    Head(*Q) = Nil;
    Tail(*Q) = Nil;
}

/* *** Destruktor *** */
void DeAlokasi(PrioQueueChar * Q)
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */
{ /* ALGORITMA */
    Head(*Q) = Nil;
    Tail(*Q) = Nil;
    MaxEl(*Q) = 0;
    free((*Q).T);
}

/* *** Primitif Add/Delete *** */
void Enqueue (PrioQueueChar * Q, infotype X)
/* Proses: Menambahkan X pada Q dengan aturan priority queue, terurut mengecil berdasarkan prio */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X disisipkan pada posisi yang tepat sesuai dengan prioritas,
        TAIL "maju" dengan mekanisme circular buffer; */
{ /* KAMUS */
    int CC, Nxt;
    infotype temp;
    /* ALGORITMA */
    if (IsEmpty(*Q)) {
        Head(*Q) = 0;
    }
    Tail(*Q) = (Tail(*Q) + 1) % MaxEl(*Q);
    InfoTail(*Q) = X;
    CC = Tail(*Q);
    Nxt = (CC + MaxEl(*Q)-1) % MaxEl(*Q);
    while (CC != Head(*Q) && Prio(Elmt(*Q, CC)) < Prio(Elmt(*Q, Nxt))) {
        temp = Elmt(*Q, CC);
        Elmt(*Q, CC) = Elmt(*Q, Nxt);
        Elmt(*Q, Nxt) = temp;
        CC = Nxt;
        Nxt = (CC + MaxEl(*Q)-1) % MaxEl(*Q);
    }
}

void Dequeue (PrioQueueChar * Q, infotype * X)
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer;
        Q mungkin kosong */
{ /* ALGORITMA */
    *X = InfoHead(*Q);
    if (Head(*Q) == Tail(*Q)) {
        Head(*Q) = Nil;
        Tail(*Q) = Nil;
    } else {
        Head(*Q) = (Head(*Q) + 1) % MaxEl(*Q);
    }
}

/* Operasi Tambahan */
void PrintPrioQueueChar (PrioQueueChar Q)
/* Mencetak isi queue Q ke layar */
/* I.S. Q terdefinisi, mungkin kosong */
/* F.S. Q tercetak ke layar dengan format:
<prio-1> <elemen-1>
...
<prio-n> <elemen-n>
#
*/
{ /* KAMUS */
    int CC, i;
    /* ALGORITMA */
    if (!IsEmpty(Q)) {
        for (i = 0; i < NBElmt(Q); i++) {
            CC = (Head(Q) + MaxEl(Q) + i) % MaxEl(Q);
            printf("%d %c\n", Prio(Q.T[CC]), Info(Q.T[CC]));
        }
    }
    printf("#\n");
}