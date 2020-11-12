/*
 * NIM          : 13519138
 * Nama         : Bintang Fajarianto
 * Tanggal      : 12 November 2020
 * Praktikum    : 10
 * Soal         : 2
 */

// File: queuelist.c

#include <stdio.h>
#include <stdlib.h>
#include "queuelist.h"

/* Prototype manajemen memori */
void Alokasi (address *P, infotype X)
/* I.S. Sembarang */
/* F.S. Alamat P dialokasi, jika berhasil maka Info(P)=X dan 
        Next(P)=Nil */
/*      P=Nil jika alokasi gagal */
{   /* ALGORITMA */
	*P = (address) malloc(sizeof(ElmtQueue));
	if (*P != Nil) {
		Info(*P) = X;
		Next(*P) = Nil;
	}
}

void Dealokasi (address P)
/* I.S. P adalah hasil alokasi, P != Nil */
/* F.S. Alamat P didealokasi, dikembalikan ke sistem */
{	/* ALGORITMA */
	free(P);
}

boolean IsEmpty (Queue Q)
/* Mengirim true jika Q kosong: HEAD(Q)=Nil and TAIL(Q)=Nil */
{   /* ALGORITMA */
	return ((Head(Q) == Nil) && (Tail(Q) == Nil));
}

int NbElmt(Queue Q)
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong */
{   /* KAMUS */
	address P;
	int count = 0;

    /* ALGORITMA */
    P = Head(Q);
	while (P != Nil) {
		count++;
		P = Next(P);
	}
	return count;
}

/*** Kreator ***/
void CreateEmpty(Queue * Q)
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk */
{   /* ALGORITMA */
	Head(*Q) = Nil;
	Tail(*Q) = Nil;
}

/*** Primitif Enqueue/Dequeue ***/
void Enqueue (Queue * Q, infotype X)
/* Proses: Mengalokasi X dan menambahkan X pada bagian TAIL dari Q
   jika alokasi berhasil; jika alokasi gagal Q tetap */
/* Pada dasarnya adalah proses insert last */
/* I.S. Q mungkin kosong */
/* F.S. X menjadi TAIL, TAIL "maju" */
{   /* KAMUS */
    address P;

    /* ALGORITMA */
	if (!IsEmpty(*Q)) {
		P = Tail(*Q);
		Alokasi(&(Next(P)), X);
		if(Next(P) != Nil) {
			Tail(*Q) = Next(P);
		}
	} else {
		Alokasi(&(Head(*Q)), X);
		if (Head(*Q) != Nil) {
			P = Head(*Q);
			Next(P) = Nil;
			Tail(*Q) = P;
		}
	}
}

void Dequeue(Queue * Q, infotype * X)
/* Proses: Menghapus X pada bagian HEAD dari Q dan mendealokasi
   elemen HEAD */
/* Pada dasarnya operasi delete first */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "mundur" */
{   /* KAMUS */
	address P;

    /* ALGORITMA */
    P = Head(*Q);
	*X = Info(P);
	Head(*Q) = Next(P);
	if (Next(P) == Nil) {
		Tail(*Q) = Nil;
	}
	Dealokasi(P);
}