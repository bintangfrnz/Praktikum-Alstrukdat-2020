/*
 * NIM          : 13519138
 * Nama         : Bintang Fajarianto
 * Tanggal      : 17 September 2020
 * PraPraktikum : 4
 */

// File: marraypos.c

#include <stdio.h>
#include <stdlib.h>
#include "arraydin.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void MakeEmpty(TabInt *T, int maxel)
/* I.S. T sembarang, maxel > 0 */
/* F.S. Terbentuk tabel T kosong dengan kapasitas maxel */
{ /* KAMUS */
   IdxType i;
   /* ALGORITMA */
   (*T).Neff = 0;
   (*T).MaxEl = maxel;
   (*T).TI = (int *) malloc(maxel * sizeof(int));
   for(i = IdxMin; i < maxel; i++) {
      Elmt(*T,i) = 0;
   }
}

void Dealokasi(TabInt *T)
/* I.S. T terdefinisi; */
/* F.S. TI(T) dikembalikan ke system, MaxEl(T)=0; Neff(T)=0 */
{ /* ALGORITMA */
   (*T).Neff = 0;
   (*T).MaxEl = 0;
   free((*T).TI);
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int NbElmt(TabInt T)
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
{ /* ALGORITMA */
   return T.Neff;
}

/* *** Daya tampung container *** */
int MaxElement(TabInt T)
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
{ /* ALGORITMA */
   return T.MaxEl;
}

/* *** Selektor INDEKS *** */
IdxType GetFirstIdx(TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T pertama */
{ /* ALGORITMA */
   return IdxMin;
}

IdxType GetLastIdx(TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T terakhir */
{ /* ALGORITMA */
   return (T.Neff-1);
}

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid(TabInt T, IdxType i)
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
{ /* ALGORITMA */
   return ((i >= 0) && (i <= T.MaxEl-1));
}

boolean IsIdxEff(TabInt T, IdxType i)
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */
{ /* ALGORITMA */
   return ((i >= 0) && (i <= T.Neff-1));
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmpty(TabInt T)
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
/* *** Test tabel penuh *** */
{ /* ALGORITMA */
   return (T.Neff == 0);
}

boolean IsFull(TabInt T)
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */
{ /* ALGORITMA */
   return (T.Neff == T.MaxEl);
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi tabel dari pembacaan *** */
void BacaIsi(TabInt *T)
/* I.S. T sembarang dan sudah dialokasikan sebelumnya */
/* F.S. Tabel T terdefinisi */
/* Proses : membaca banyaknya elemen T dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= MaxElement(T) */
/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < N <= MaxElement(T); Lakukan N kali: Baca elemen mulai dari indeks
      IdxMin satu per satu diakhiri enter */
/*    Jika N = 0; hanya terbentuk T kosong */
{ /* KAMUS */
   int N;
   IdxType i;
   /* ALGORITMA */
   scanf("%d",&N);
   while ((N < 0) || (N > MaxElement(*T))) {
      scanf("%d",&N);
   }
   
   if (N == 0){
      (*T).Neff = 0;
   } else {
      (*T).Neff = N;
      for(i = IdxMin; i <= GetLastIdx(*T); i++) {
         scanf("%d", &(Elmt(*T,i)));
      }
   }
}

void TulisIsiTab(TabInt T)
/* Proses : Menuliskan isi tabel dengan traversal, tabel ditulis di antara kurung siku;
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika tabel kosong : menulis [] */
{ /* KAMUS */
   int i;
   /* ALGORITMA */
   printf("[");
   if (!IsEmpty(T)){
      for (i = IdxMin; i <= GetLastIdx(T)-1; i++){
         printf("%d,", T.TI[i]);
      }
      printf("%d", T.TI[GetLastIdx(T)]);
   }
   printf("]");
}

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika tabel : Penjumlahan, pengurangan, perkalian, ... *** */
TabInt PlusMinusTab(TabInt T1, TabInt T2, boolean plus)
/* Prekondisi : T1 dan T2 memiliki Neff sama dan tidak kosong */
/* Jika plus = true, mengirimkan  T1+T2, yaitu setiap elemen T1 dan T2 pada indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan T1-T2, yaitu setiap elemen T1 dikurangi elemen T2 pada indeks yang sama */
{ /* KAMUS */
   TabInt newT;
   /* ALGORITMA */
   MakeEmpty(&newT, T1.MaxEl);
   newT.Neff = T1.Neff;
   if (plus) {
      for(int i = GetFirstIdx(T1); i <= GetLastIdx(T1); i++) {
         Elmt(newT,i) = Elmt(T1,i) + Elmt(T2,i);
      }
  } else {
      for(int i = GetFirstIdx(T1); i <= GetLastIdx(T1); i++) {
         Elmt(newT,i) = Elmt(T1,i) - Elmt(T2,i);
      }
   }
   return newT;
}


/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan tabel : < =, > *** */
boolean IsEQ(TabInt T1, TabInt T2)
/* Mengirimkan true jika T1 sama dengan T2 yaitu jika Neff T1 = T2 dan semua elemennya sama */
{ /* KAMUS */
   int i = IdxMin;
   boolean isSame = true;
   /* ALGORITMA */
   if (NbElmt(T1) == NbElmt(T2)) {
      while (i <= GetLastIdx(T1) && isSame) {
         if (Elmt(T1,i) == Elmt(T2,i)) {
            i++;
         } else {
         isSame = false;
         }
      }
   } else {
      isSame = false;
   }
   return isSame;
}

/* ********** SEARCHING ********** */
/* ***  Perhatian : Tabel boleh kosong!! *** */
IdxType Search1(TabInt T, ElType X)
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
/* Skema Searching yang digunakan bebas */
{ /* KAMUS */
   int i = IdxMin;
   int idx = IdxUndef;
   boolean isSame = false;
   /* ALGORITMA */
   if (IsEmpty(T)) {
      return idx;
   } else {
      while (i <= GetLastIdx(T) && !isSame) {
         if (Elmt(T,i) == X) {
            isSame = true;
            idx = i;
         } else {
            i++;
         }
      }
      return idx;
   }
}

boolean SearchB(TabInt T, ElType X)
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan true, jika tidak ada menghasilkan false */
/* Skema searching yang digunakan bebas */
{ /* KAMUS */
   int i = IdxMin;
   boolean found = false;
   /* ALGORITMA */
   while(!found && i <= GetLastIdx(T)){
      found = ((Elmt(T,i) == X));
      i++;
   }
   return found;
}

/* ********** NILAI EKSTREM ********** */
void MaxMin(TabInt T, ElType *Max, ElType *Min)
/* I.S. Tabel T tidak kosong */
/* F.S. Max berisi nilai maksimum T;
        Min berisi nilai minimum T */
{ /* ALGORITMA */
   *Min = Elmt(T,0);
   *Max = Elmt(T,0);
   for(int i = GetFirstIdx(T); i <= GetLastIdx(T); i++) {
      if (Elmt(T,i) > *Max) {
         *Max = Elmt(T,i);
      }
      if (Elmt(T,i) < *Min) {
         *Min = Elmt(T,i);
      }
   }
}

/* ********** OPERASI LAIN ********** */
void CopyTab(TabInt Tin, TabInt *Tout)
/* I.S. Tin terdefinisi tidak kosong, Tout sembarang */
/* F.S. Tout berisi salinan dari Tin (identik, Neff dan MaxEl sama) */
/* Proses : Menyalin isi Tin ke Tout */
{ /* KAMUS */
   TabInt newT;
   IdxType i;
   /* ALGORITMA */
   MakeEmpty(&newT,Tin.MaxEl);
   newT.Neff = Tin.Neff;
   for(i = 0; i <= GetLastIdx(Tin); i++) {
      Elmt(newT,i) = Elmt(Tin,i);
   }
   *Tout = newT;
}

ElType SumTab(TabInt T)
/* Menghasilkan hasil penjumlahan semua elemen T */
/* Jika T kosong menghasilkan 0 */
{ /* KAMUS */
   IdxType i;
   int sum = 0;
   /* ALGORITMA */
   for(i = 0; i <= GetLastIdx(T); i++){
      sum += Elmt(T,i);
   }
   return sum;
}

int CountX(TabInt T, ElType X)
/* Menghasilkan berapa banyak kemunculan X di T */
/* Jika T kosong menghasilkan 0 */
{ /* KAMUS */
   IdxType i;
   int count = 0;
   /* ALGORITMA */
   for(i = 0; i <= GetLastIdx(T); i++) {
      if(Elmt(T,i) == X) {
         count += 1;
      }
   }
   return count;
}

boolean IsAllGenap(TabInt T)
/* Menghailkan true jika semua elemen T genap. T boleh kosong */
{ /* KAMUS */
   int i = IdxMin;
   boolean allgenap = true;
   /* ALGORITMA */
   while(allgenap && i <= GetLastIdx(T)){
        allgenap = (allgenap && (Elmt(T,i)%2 == 0));
        i++;
   }
   return allgenap;
}

/* ********** SORTING ********** */
void Sort(TabInt *T, boolean asc)
/* I.S. T boleh kosong */
/* F.S. Jika asc = true, T terurut membesar */
/*      Jika asc = false, T terurut mengecil */
/* Proses : Mengurutkan T dengan salah satu algoritma sorting,
   algoritma bebas */
{ /* KAMUS */
   IdxType i, j;
   int temp;
   /* ALGORITMA */
   for (i = GetFirstIdx(*T) + 1; i <= GetLastIdx(*T); i++){
      temp = Elmt(*T, i);
      j = i-1;
      while (j >= GetFirstIdx(*T) && ((!asc && Elmt(*T,j) < temp) || (asc && Elmt(*T,j) > temp))){
         Elmt(*T,j+1) = Elmt(*T, j);
         j--;
      }
      Elmt(*T,j+1) = temp;
   }
}

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void AddAsLastEl(TabInt *T, ElType X)
/* Proses: Menambahkan X sebagai elemen terakhir tabel */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/* F.S. X adalah elemen terakhir T yang baru */
{ /* ALGORITMA */
   if (!IsFull(*T)) {
      (*T).TI[(GetLastIdx(*T)+1)] = X;
      (*T).Neff += 1;
   }
}

/* ********** MENGHAPUS ELEMEN ********** */
void DelLastEl(TabInt *T, ElType *X)
/* Proses : Menghapus elemen terakhir tabel */
/* I.S. Tabel tidak kosong */
/* F.S. X adalah nilai elemen terakhir T sebelum penghapusan, */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */
{ /* ALGORITMA */
   if (!IsEmpty(*T)) {
      *X = (*T).TI[(GetLastIdx(*T))];
      (*T).Neff -= 1;
   }
}

/* ********* MENGUBAH UKURAN ARRAY ********* */
void GrowTab(TabInt *T, int num)
/* Proses : Menambahkan max element sebanyak num */
/* I.S. Tabel sudah terdefinisi */
/* F.S. Ukuran tabel bertambah sebanyak num */
{ /* KAMUS */
   TabInt newT;
   IdxType i;
   /* ALGORITMA */
   MakeEmpty(&newT,(*T).MaxEl+num);
   newT.Neff = (*T).Neff;
   for(i = 0; i <= GetLastIdx(newT); i++) {
      Elmt(newT,i) = Elmt(*T,i);
   }
   Dealokasi(T);
   *T = newT;
}

void ShrinkTab(TabInt *T, int num)
/* Proses : Mengurangi max element sebanyak num */
/* I.S. Tabel sudah terdefinisi, ukuran MaxEl > num, dan Neff < MaxEl - num. */
/* F.S. Ukuran tabel berkurang sebanyak num. */
{ /* KAMUS */
   TabInt newT;
   IdxType i;
   /* ALGORITMA */
   MakeEmpty(&newT,(*T).MaxEl-num);
   newT.Neff = (*T).Neff;
   for(i = 0; i <= GetLastIdx(newT); i++) {
      Elmt(newT,i) = Elmt(*T,i);
   }
   Dealokasi(T);
   *T = newT;
}

void CompactTab(TabInt *T)
/* Proses : Mengurangi max element sehingga Neff = MaxEl */
/* I.S. Tabel tidak kosong */
/* F.S. Ukuran MaxEl = Neff */
{ /* KAMUS */
   TabInt newT;
   IdxType i;
   /* ALGORITMA */
   MakeEmpty(&newT,(*T).Neff);
   newT.Neff = (*T).Neff;
   for(i = 0; i <= GetLastIdx(newT); i++) {
      Elmt(newT,i) = Elmt(*T,i);
   }
   Dealokasi(T);
   *T = newT;
}