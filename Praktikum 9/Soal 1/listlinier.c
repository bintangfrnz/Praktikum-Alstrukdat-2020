/*
 * NIM          : 13519138
 * Nama         : Bintang Fajarianto
 * Tanggal      : 05 November 2020
 * Praktikum    : 9
 * Soal         : 1
 */

// File: listlinier.c

#include <stdio.h>
#include <stdlib.h>
#include "listlinier.h"

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (List L)
/* Mengirim true jika list kosong */
{	/* ALGORITMA */
	return (First(L) == Nil);
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L)
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
{	/* ALGORITMA */
	First(*L) = Nil;
}

/****************** Manajemen Memori ******************/
address Alokasi (infotype X)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
{	/* KAMUS */
	address P;

	/* ALGORITMA */
	P = (address) malloc(sizeof(ElmtList));
	if (P != Nil) {
		Info(P) = X;
		Next(P) = Nil;
	}
	return P;
}

void Dealokasi (address *P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
{	/* ALGORITMA */
	free(*P);
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search (List L, infotype X)
/* Mencari apakah ada elemen list dengan info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
{	/* KAMUS */
	address P;

	/* ALGORITMA */
	if (IsEmpty(L)) {
		return Nil;
	}

	P = First(L);
	while (P != Nil && Info(P) != X) {
		P = Next(P);
	}
	return P;
}

boolean FSearch (List L, address P)
/* Mencari apakah ada elemen list yang beralamat P */
/* Mengirimkan true jika ada, false jika tidak ada */
{	/* KAMUS */
	address cP;

	/* ALGORITMA */
	if (!IsEmpty(L)) {
		cP = First(L);
		while (cP != Nil) {
			if (cP == P) {
				return true;
			}
			cP = Next(cP);
		}
	}
	return false;
}

address SearchPrec (List L, infotype X)
/* Mengirimkan address elemen sebelum elemen yang nilainya=X */
/* Mencari apakah ada elemen list dengan Info(P)=X */
/* Jika ada, mengirimkan address Prec, dengan Next(Prec)=P dan Info(P)=X. */
/* Jika tidak ada, mengirimkan Nil */
/* Jika P adalah elemen pertama, maka Prec=Nil */
/* Search dengan spesifikasi seperti ini menghindari */
/* traversal ulang jika setelah Search akan dilakukan operasi lain */
{	/* KAMUS */
	address P, Pfound;

	/* ALGORITMA */
	Pfound = Search(L,X);
	if (Pfound != Nil) {
		P = First(L);
		while (P != Nil) {
			if (Next(P) == Pfound) {
				return P;
			}
			P = Next(P);
		}
	}
	return Nil;
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, infotype X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
{	/* KAMUS */
	address P;

	/* ALGORITMA */
	P = Alokasi(X);
	if (P != Nil) {
		Next(P) = First(*L);
		First(*L) = P;
	}
}

void InsVLast (List *L, infotype X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{	/* KAMUS */
	address P, last;

	/* ALGORITMA */
	P = Alokasi(X);
	if (P != Nil) {
		if (IsEmpty(*L)) {
			InsVFirst(L,X);
		} else {
			last = First(*L);
			while (Next(last) != Nil) {
				last = Next(last);
			}
			Next(last) = P;
			Next(P) = Nil;
		}
	}
}

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, infotype *X)
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
{	/* KAMUS */
	address P;

	/* ALGORITMA */
	P = First(*L);
	*X = Info(P);
	First(*L) = Next(P);
	Dealokasi(&P);
}

void DelVLast (List *L, infotype *X)
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
{	/* KAMUS */
	address prelast;

	/* ALGORITMA */
	prelast = First(*L);
	if (Next(prelast) == Nil) {
		DelVFirst(L,X);
	} else {
		while (Next(Next(prelast)) != Nil) {
			prelast = Next(prelast);
		}
		*X = Info(Next(prelast));
		Dealokasi(&Next(prelast));
		Next(prelast) = Nil;
	}
}

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
{	/* ALGORITMA */
	if (P != Nil) {
		Next(P) = First(*L);
		First(*L) = P;
	}
}

void InsertAfter (List *L, address P, address Prec)
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
{	/* ALGORITMA */
	Next(P) = Next(Prec);
	Next(Prec) = P;
}

void InsertLast (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
{	/* KAMUS */
	address last;

	/* ALGORITMA */
	if (P != Nil) {
		if (IsEmpty(*L)) {
			InsertFirst(L,P);
		} else {
			last = First(*L);
			while (Next(last) != Nil) {
				last = Next(last);
			}
			Next(last) = P;
			Next(P) = Nil;
		}
	}
}

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
{	/* KAMUS */
	address first;

	/* ALGORITMA */
	first = First(*L);
	*P = first;
	First(*L) = Next(first);
}

void DelP (List *L, infotype X)
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
{	/* KAMUS */
	address P, dummy;

	/* ALGORITMA */
	if (!IsEmpty(*L)) {
		P = First(*L);
		if (Info(P) == X) {
			DelFirst(L, &dummy);
		} else {
			while (Next(P) != Nil && Info(Next(P)) != X) {
				P = Next(P);
			}
			if (Next(P) != Nil) {
				DelAfter(L,&dummy,P);
			}
		}
	}
}

void DelLast (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen terakhir yg lama, */
/* jika ada */
{	/* KAMUS */
	address prelast;

	/* ALGORITMA */
	prelast = First(*L);
	if (Next(prelast) == Nil) {
		DelFirst(L,P);
	} else {
		while (Next(Next(prelast)) != Nil) {
			prelast = Next(prelast);
		}
		DelAfter(L,P,prelast);
	}
}

void DelAfter (List *L, address *Pdel, address Prec)
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
{	/* ALGORITMA */
	*Pdel = Next(Prec);
	Next(Prec) = Next(*Pdel);
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo (List L)
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
{	/* KAMUS */
	address P;

	/* ALGORITMA */
	printf("[");
	if (!IsEmpty(L)) {
		P = First(L);
		while (P != Nil) {
			printf("%d", Info(P));
			if (Next(P) != Nil) {
				printf(",");
			}
			P = Next(P);
		}
	}
	printf("]");
}

int NbElmt (List L)
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
{	/* KAMUS */
	address P;
	int count = 0;

	/* ALGORITMA */
	if (!IsEmpty(L)) {
		P = First(L);
		while (P != Nil) {
			count++;
			P = Next(P);
		}
	}
	return count;
}

/*** Prekondisi untuk Max/Min/rata-rata : List tidak kosong ***/
infotype Max (List L)
/* Mengirimkan nilai info(P) yang maksimum */
{	/* KAMUS */
	address P;
	infotype max;

	/* ALGORITMA */
	P = First(L);
	max = Info(P);
	while (Next(P) != Nil) {
		P = Next(P);
		if (Info(P) > max) {
			max = Info(P);
		}
	}
	return max;
}

address AdrMax (List L)
/* Mengirimkan address P, dengan info(P) yang bernilai maksimum */
{	/* KAMUS */
	address P;

	/* ALGORITMA */
	P = Search(L,Max(L));
	return P;
}

infotype Min (List L)
/* Mengirimkan nilai info(P) yang minimum */
{	/* KAMUS */
	address P;
	infotype min;

	/* ALGORITMA */
	P = First(L);
	min = Info(P);
	while (Next(P) != Nil) {
		P = Next(P);
		if (Info(P) < min) {
			min = Info(P);
		}
	}
	return min;
}

address AdrMin (List L)
/* Mengirimkan address P, dengan info(P) yang bernilai minimum */
{	/* KAMUS */
	address P;

	/* ALGORITMA */
	P = Search(L,Min(L));
	return P;
}

float Average (List L)
/* Mengirimkan nilai rata-rata info(P) */
{	/* KAMUS */
	address P;
	float sum, count;

	/* ALGORITMA */
	if (IsEmpty(L)) {
		return 0;
	} else {
		P = First(L);
		sum = Info(P);
		count = 1;
		while (Next(P) != Nil) {
			P = Next(P);
			sum += Info(P);
			count++;
		}
	}
	return sum/count;
}

/****************** PROSES TERHADAP LIST ******************/
void DelAll (List *L)
/* Delete semua elemen list dan alamat elemen di-dealokasi */
{	/* KAMUS */
	address deleted, cP;

	/* ALGORITMA */
	if(!IsEmpty(*L)) {
		cP = First(*L);
		while (cP != Nil) {
			DelFirst(L,&deleted);
			cP = Next(cP);
		}
		First(*L) = Nil;
	}
}

void InversList (List *L)
/* I.S. sembarang. */
/* F.S. elemen list dibalik : */
/* Elemen terakhir menjadi elemen pertama, dan seterusnya. */
/* Membalik elemen list, tanpa melakukan alokasi/dealokasi. */
{	/* KAMUS */
	address P, Prec, last;

	/* ALGORITMA */
	if(!IsEmpty(*L)) {
		P = First(*L);
		while (Next(P) != Nil) {
			P = Next(P);
		}
		last = P;
		while (P != First(*L)) {
			Prec = First(*L);
			while(Next(Prec) != P) {
				Prec = Next(Prec);
			}
			Next(P) = Prec;
			P = Next(P);
		}
		Next(P) = Nil;
		First(*L) = last;
	}
}

List FInversList (List L)
/* Mengirimkan list baru, hasil invers dari L */
/* dengan menyalin semua elemn list. Alokasi mungkin gagal. */
/* Jika alokasi gagal, hasilnya list kosong */
/* dan semua elemen yang terlanjur di-alokasi, harus didealokasi */
{	/* KAMUS */
	List newL;

	/* ALGORITMA */
	newL = FCopyList(L);
	InversList(&newL);
	return newL;
}

void CopyList (List *L1, List *L2)
/* I.S. L1 sembarang. F.S. L2=L1 */
/* L1 dan L2 "menunjuk" kepada list yang sama.*/
/* Tidak ada alokasi/dealokasi elemen */
{	/* ALGORITMA */
	First(*L2) = First(*L1);
}

List FCopyList (List L)
/* Mengirimkan list yang merupakan salinan L */
/* dengan melakukan alokasi. */
/* Jika ada alokasi gagal, hasilnya list kosong dan */
/* semua elemen yang terlanjur di-alokasi, harus didealokasi */
{	/* KAMUS */
	List newL;
	address P, cP;
	boolean gagal = false;
	
	/* ALGORITMA */
	CreateEmpty(&newL);
	
	P = First(L);
	while (!gagal && P != Nil) {
		cP = Alokasi(Info(P));
		if (cP != Nil) {
			InsertLast(&newL,cP);
		} else {
			gagal = true;
		}
		P = Next(P);
	}
	if (gagal) DelAll(&newL);
	return newL;
}

void CpAlokList (List Lin, List *Lout)
/* I.S. Lin sembarang. */
/* F.S. Jika semua alokasi berhasil,maka Lout berisi hasil copy Lin */
/* Jika ada alokasi yang gagal, maka Lout=Nil dan semua elemen yang terlanjur dialokasi, didealokasi */
/* dengan melakukan alokasi elemen. */
/* Lout adalah list kosong jika ada alokasi elemen yang gagal */
{	/* ALGORITMA */
	*Lout = FCopyList(Lin);
}

void Konkat (List L1, List L2, List * L3)
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 tetap, L3 adalah hasil konkatenasi L1 & L2 */
/* Jika semua alokasi berhasil, maka L3 adalah hasil konkatenasi*/
/* Jika ada alokasi yang gagal, semua elemen yang sudah dialokasi */
/* harus di-dealokasi dan L3=Nil*/
/* Konkatenasi dua buah list : L1 & L2 menghasilkan L3 yang "baru" */
/* Elemen L3 adalah hasil alokasi elemen yang “baru”. */
/* Jika ada alokasi yang gagal, maka L3 harus bernilai Nil*/
/* dan semua elemen yang pernah dialokasi didealokasi */
{	/* KAMUS */
	List nL1, nL2;

	/* ALGORITMA */
	CreateEmpty(L3);

	nL1 = FCopyList(L1);
	nL2 = FCopyList(L2);

    if (NbElmt(nL1) == NbElmt(L1) && NbElmt(nL2) == NbElmt(L2)) Konkat1(&nL1,&nL2,L3);
}

void Konkat1 (List *L1, List *L2, List *L3)
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
/* Konkatenasi dua buah list : L1 dan L2    */
/* menghasilkan L3 yang baru (dengan elemen list L1 dan L2) */
/* dan L1 serta L2 menjadi list kosong.*/
/* Tidak ada alokasi/dealokasi pada prosedur ini */
{	/* KAMUS */
	address P;

	/* ALGORITMA */
	CreateEmpty(L3);

	First(*L3) = First(*L1);
    if (IsEmpty(*L3)) {
        First(*L3) = First(*L2);
    } else {
        P = First(*L3);
        while (Next(P) != Nil){
            P = Next(P);
        }
        Next(P) = First(*L2);
    }
    First(*L1) = Nil;
    First(*L2) = Nil;
}

void PecahList (List *L1, List *L2, List L)
/* I.S. L mungkin kosong */
/* F.S. Berdasarkan L, dibentuk dua buah list L1 dan L2 */
/* L tidak berubah: untuk membentuk L1 dan L2 harus alokasi */
/* L1 berisi separuh elemen L dan L2 berisi sisa elemen L */
/* Jika elemen L ganjil, maka separuh adalah NbElmt(L) div 2 */
{	/* KAMUS */
	address P, cP;
	int count = 0;
	int bagi2 = NbElmt(L)/2;

	/* ALGORITMA */
	CreateEmpty(L1);
	CreateEmpty(L2);

	P = First(L);
	while (P != Nil) {
		count++;
		cP = Alokasi(Info(P));
		if (cP != Nil) {
			(count <= bagi2) ? InsertLast(L1,cP) : InsertLast(L2,cP);
		}
		P = Next(P);
	}
}