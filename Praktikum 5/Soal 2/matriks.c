/*
 * NIM          : 13519138
 * Nama         : Bintang Fajarianto
 * Tanggal      : 24 September 2020
 * Praktikum    : 5
 * Soal         : 1
 */

// File: matriks.c
// Modifikasi pra-praktikum matriks.c

#include <stdio.h>
#include "matriks.h"

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */              
/* *** Konstruktor membentuk MATRIKS *** */
void MakeMATRIKS (int NB, int NK, MATRIKS * M)
/* Membentuk sebuah MATRIKS "kosong" yang siap diisi berukuran NB x NK di "ujung kiri" memori */
/* I.S. NB dan NK adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks M sesuai dengan definisi di atas terbentuk */
{ /* KAMUS */
   indeks i,j;
   /* ALGORITMA */
   (*M).NBrsEff = NB;
   (*M).NKolEff = NK;
   for(i = BrsMin; i < NB; i++) {
      for(j = KolMin; j < NK; j++) {
         (*M).Mem[i][j] = 0;
      }   
   }
}

/* *** Selektor "DUNIA MATRIKS" *** */
boolean IsIdxValid (int i, int j)
/* Mengirimkan true jika i, j adalah indeks yang valid untuk matriks apa pun */
{ /* ALGORITMA */
   return (i >= BrsMin && i <= BrsMax && j >= KolMin && j <= KolMax);
}

/* *** Selektor: Untuk sebuah matriks M yang terdefinisi: *** */
indeks GetFirstIdxBrs (MATRIKS M)
/* Mengirimkan indeks baris terkecil M */
{ /* ALGORITMA */
   return BrsMin;
}

indeks GetFirstIdxKol (MATRIKS M)
/* Mengirimkan indeks kolom terkecil M */
{ /* ALGORITMA */
   return KolMin;
}

indeks GetLastIdxBrs (MATRIKS M)
/* Mengirimkan indeks baris terbesar M */
{ /* ALGORITMA */
   return M.NBrsEff-1;
}

indeks GetLastIdxKol (MATRIKS M)
/* Mengirimkan indeks kolom terbesar M */
{ /* ALGORITMA */
   return M.NKolEff-1;
}

boolean IsIdxEff (MATRIKS M, indeks i, indeks j)
/* Mengirimkan true jika i, j adalah indeks efektif bagi M */
{ /* ALGORITMA */
   return (i >= GetFirstIdxBrs(M) && i <= GetLastIdxBrs(M) && j >= GetFirstIdxKol(M) && j <= GetLastIdxKol(M));
}

ElType GetElmtDiagonal (MATRIKS M, indeks i)
/* Mengirimkan elemen M(i,i) */
{ /* ALGORITMA */
   return M.Mem[i][i];
}

/* ********** Assignment  MATRIKS ********** */
void CopyMATRIKS (MATRIKS MIn, MATRIKS * MHsl)
/* Melakukan assignment MHsl  MIn */
{ /* KAMUS */
   indeks i,j;
   /* ALGORITMA */
   MakeMATRIKS(MIn.NBrsEff, MIn.NKolEff, MHsl);
   for(i = GetFirstIdxBrs(*MHsl); i <= GetLastIdxBrs(*MHsl); i++) {
      for(j = GetFirstIdxKol(*MHsl); j <= GetLastIdxKol(*MHsl); j++) {
         (*MHsl).Mem[i][j] = MIn.Mem[i][j];
      }   
   }
}

/* ********** KELOMPOK BACA/TULIS ********** */ 
void BacaMATRIKS (MATRIKS * M, int NB, int NK)
/* I.S. IsIdxValid(NB,NK) */ 
/* F.S. M terdefinisi nilai elemen efektifnya, berukuran NB x NK */
/* Proses: Melakukan MakeMATRIKS(M,NB,NK) dan mengisi nilai efektifnya */
/* Selanjutnya membaca nilai elemen per baris dan kolom */
/* Contoh: Jika NB = 3 dan NK = 3, maka contoh cara membaca isi matriks :
1 2 3
4 5 6
8 9 10 
*/
{ /* KAMUS */
   indeks i,j;
   /* ALGORITMA */
   MakeMATRIKS(NB, NK, M);
   for(i = GetFirstIdxBrs(*M); i <= GetLastIdxBrs(*M); i++) {
      for(j = GetFirstIdxKol(*M); j <= GetLastIdxKol(*M); j++) {
         scanf("%d", &(*M).Mem[i][j]);
      }   
   }
}

void TulisMATRIKS (MATRIKS M)
/* I.S. M terdefinisi */
/* F.S. Nilai M(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris 
   dipisahkan sebuah spasi */
/* Proses: Menulis nilai setiap elemen M ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/
{ /* KAMUS */
   indeks i,j;
   /* ALGORITMA */
   for(i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++) {
      for(j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); j++) {
         if (j != GetLastIdxKol(M)) {
            printf("%d ", M.Mem[i][j]);
         } else {
            if (i != GetLastIdxBrs(M)) {
               printf("%d\n", M.Mem[i][j]);
            } else {
               printf("%d", M.Mem[i][j]);
            }
         }   
      }
   }
}

/* ********** KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE ********** */                                  
MATRIKS TambahMATRIKS (MATRIKS M1, MATRIKS M2)
/* Prekondisi : M1  berukuran sama dengan M2 */
/* Mengirim hasil penjumlahan matriks: M1 + M2 */ 
{ /* KAMUS */
   MATRIKS Msum;
   indeks i,j;
   /* ALGORITMA */
   MakeMATRIKS(M1.NBrsEff, M1.NKolEff, &Msum);
   for(i = GetFirstIdxBrs(Msum); i <= GetLastIdxBrs(Msum); i++) {
      for(j = GetFirstIdxKol(Msum); j <= GetLastIdxKol(Msum); j++) {
         Msum.Mem[i][j] = M1.Mem[i][j] + M2.Mem[i][j];
      }   
   }
   return Msum;
}

MATRIKS KurangMATRIKS (MATRIKS M1, MATRIKS M2)
/* Prekondisi : M berukuran sama dengan M */
/* Mengirim hasil pengurangan matriks: salinan M1 – M2 */ 
{ /* KAMUS */
   MATRIKS Mmin;
   indeks i,j;
   /* ALGORITMA */
   MakeMATRIKS(M1.NBrsEff, M1.NKolEff, &Mmin);
   for(i = GetFirstIdxBrs(Mmin); i <= GetLastIdxBrs(Mmin); i++) {
      for(j = GetFirstIdxKol(Mmin); j <= GetLastIdxKol(Mmin); j++) {
         Mmin.Mem[i][j] = M1.Mem[i][j] - M2.Mem[i][j];
      }   
   }
   return Mmin;
}

MATRIKS KaliMATRIKS (MATRIKS M1, MATRIKS M2)
/* Prekondisi : Ukuran kolom efektif M1 = ukuran baris efektif M2 */
/* Mengirim hasil perkalian matriks: salinan M1 * M2 */
{ /* KAMUS */
   MATRIKS Mx;
   indeks i,j,k;
   /* ALGORITMA */
   MakeMATRIKS(M1.NBrsEff, M2.NKolEff, &Mx);
   for(i = GetFirstIdxBrs(M1); i <= GetLastIdxBrs(M1); i++) {
      for(j = GetFirstIdxKol(M2); j <= GetLastIdxKol(M2); j++) {
         for(k = GetFirstIdxKol(M1); k <= GetLastIdxKol(M1); k++) {
            Mx.Mem[i][j] += M1.Mem[i][k]*M2.Mem[k][j];
         }
      }   
   }
   return Mx;
}

MATRIKS KaliKons (MATRIKS M, ElType X)
/* Mengirim hasil perkalian setiap elemen M dengan X */
{ /* KAMUS */
   MATRIKS Mc;
   indeks i,j;
   /* ALGORITMA */
   MakeMATRIKS(M.NBrsEff, M.NKolEff, &Mc);
   for(i = GetFirstIdxBrs(Mc); i <= GetLastIdxBrs(Mc); i++) {
      for(j = GetFirstIdxKol(Mc); j <= GetLastIdxKol(Mc); j++) {
         Mc.Mem[i][j] = X*M.Mem[i][j];
      }   
   }
   return Mc;
}

void PKaliKons (MATRIKS * M, ElType K)
/* I.S. M terdefinisi, K terdefinisi */
/* F.S. Mengalikan setiap elemen M dengan K */
{ /* KAMUS */
   MATRIKS Mc;
   /* ALGORITMA */
   Mc = KaliKons(*M, K);
   *M = Mc;
}

/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP MATRIKS ********** */
boolean EQ (MATRIKS M1, MATRIKS M2)
/* Mengirimkan true jika M1 = M2, yaitu NBElmt(M1) = NBElmt(M2) dan */
/* untuk setiap i,j yang merupakan indeks baris dan kolom M1(i,j) = M2(i,j) */
/* Juga merupakan strong EQ karena GetFirstIdxBrs(M1) = GetFirstIdxBrs(M2) 
   dan GetLastIdxKol(M1) = GetLastIdxKol(M2) */
{ /* KAMUS */
   indeks i,j;
   boolean isSame = (NBElmt(M1) == NBElmt(M2));
   /* ALGORITMA */
   if (isSame) {
      for(i = GetFirstIdxBrs(M1); i <= GetLastIdxBrs(M1); i++) {
         for(j = GetFirstIdxKol(M1); j <= GetLastIdxKol(M1); j++) {
            if (M1.Mem[i][j] != M2.Mem[i][j]) {
               isSame = false;
               break;
            }
         }
      }
   }
   return isSame;
}

boolean NEQ (MATRIKS M1, MATRIKS M2)
/* Mengirimkan true jika M1 tidak sama dengan M2 */
{ /* ALGORITMA */
   return (!EQ(M1,M2));
}

boolean EQSize (MATRIKS M1, MATRIKS M2)
/* Mengirimkan true jika ukuran efektif matriks M1 sama dengan ukuran efektif M2 */
/* yaitu GetBrsEff(M1) = GetNBrsEff (M2) dan GetNKolEff (M1) = GetNKolEff (M2) */
{ /* ALGORITMA */
   return (M1.NBrsEff == M2.NBrsEff && M1.NKolEff == M2.NKolEff);
}

/* ********** Operasi lain ********** */
int NBElmt (MATRIKS M)
/* Mengirimkan banyaknya elemen M */
{ /* ALGORITMA */
   return (M.NBrsEff*M.NKolEff);
}

/* ********** KELOMPOK TEST TERHADAP MATRIKS ********** */
boolean IsBujurSangkar (MATRIKS M)
/* Mengirimkan true jika M adalah matriks dg ukuran baris dan kolom sama */
{ /* ALGORITMA */
   return (M.NBrsEff == M.NKolEff);
}

boolean IsSimetri (MATRIKS M)
/* Mengirimkan true jika M adalah matriks simetri : IsBujurSangkar(M) 
   dan untuk setiap elemen M, M(i,j)=M(j,i) */
{ /* KAMUS */
   indeks i,j;
   boolean simetri = IsBujurSangkar(M);
   /* ALGORITMA */
   if (simetri) {
      for(i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++) {
         for(j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); j++) {
            if (M.Mem[i][j] != M.Mem[j][i]) {
               simetri = false;
               break;
            }
         }
      }
   }
   return simetri;
}

boolean IsSatuan (MATRIKS M)
/* Mengirimkan true jika M adalah matriks satuan: IsBujurSangkar(M) dan 
   setiap elemen diagonal M bernilai 1 dan elemen yang bukan diagonal bernilai 0 */ 
{ /* KAMUS */
   indeks i,j;
   boolean satuan = IsBujurSangkar(M);
   /* ALGORITMA */
   if (satuan) {
      for(i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++) {
         for(j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); j++) {
            if (i != j) {
               if (M.Mem[i][j] != 0) {
                  satuan = false;
                  break;
               }
            } else {
               if (M.Mem[i][j] != 1) {
                  satuan = false;
                  break;
               }
            }
         }
      }
   }
   return satuan;
}

boolean IsSparse (MATRIKS M)
/* Mengirimkan true jika M adalah matriks sparse: mariks “jarang” dengan definisi: 
   hanya maksimal 5% dari memori matriks yang efektif bukan bernilai 0 */ 
{ /* KAMUS */
   indeks i,j;
   int count = 0;
   /* ALGORITMA */
   for(i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++) {
      for(j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); j++) {
         if (M.Mem[i][j] != 0) {
            count += 1;
         }
      }
   }
   return (20*count <= NBElmt(M));
}

MATRIKS Inverse1 (MATRIKS M)
/* Menghasilkan salinan M dengan setiap elemen "di-invers", yaitu dinegasikan (dikalikan -1) */
{ /* ALGORITMA */
   return KaliKons(M, -1);
}

float Determinan (MATRIKS M)
/* Prekondisi: IsBujurSangkar(M) */
/* Menghitung nilai determinan M */
{ /* KAMUS */
   indeks i,j;
   boolean swap;
   int NxN = M.NBrsEff;
   int countSwap = 0;
   float det = 1, temp;
   float NewM[NxN][NxN];
   /* ALGORITMA */
   // Meng-copy elemen matriks
   for (i = BrsMin; i < NxN; i++) {
      for (j = KolMin; j < NxN; j++) {
         NewM[i][j] = M.Mem[i][j];
      }
   }
   // Proses
   while (NxN > 0) {
      i = 0;
      swap = false;
      // Cek Swap
      if (NewM[NxN-1][NxN-1] == 0) {
         while (!swap && (i < (NxN-1))) {
            if (NewM[i][NxN-1] == 0) {
               i++;
            } else {
               swap = true;
            }
         }
      }

      // Swap Baris
      if ((NxN > 1) && (i == (NxN-1))) {
         return 0;
      } else if (swap) {
         for(j = 0; j < NxN; j++) {
            temp = NewM[NxN-1][j];
            NewM[NxN-1][j] = NewM[i][j];
            NewM[i][j] = temp;
         }
      }

      //  OBE (membuat matriks segitiga bawah)
      for (i = 0; i < (NxN-1); i++) {
         for (j = 0; j < NxN; j++) {
            NewM[i][j] = NewM[i][j] - (NewM[NxN-1][j]*(NewM[i][NxN-1]/NewM[NxN-1][NxN-1]));
         }
      }

      // Hitung determinan dengan mengali elemen diagonalnya
      det *= NewM[NxN-1][NxN-1];
      // Hitung berapa kali swap dilakukan
      countSwap += (swap ? 1 : 0);
      // Pindah baris
      NxN--;
   }
   det = det*((countSwap%2 == 0) ? 1.0f : -1.0f);
   if (det < 1 && det > -1) {
      return 0.0f;
   } else {
      return det;
   }
}

void PInverse1 (MATRIKS * M)
/* I.S. M terdefinisi */
/* F.S. M di-invers, yaitu setiap elemennya dinegasikan (dikalikan -1) */
{ /* KAMUS */
   MATRIKS Minv;
   /* ALGORITMA */
   Minv = Inverse1(*M);
   *M = Minv;
}

void Transpose (MATRIKS * M)
/* I.S. M terdefinisi dan IsBujursangkar(M) */
/* F.S. M "di-transpose", yaitu setiap elemen M(i,j) ditukar nilainya dengan elemen M(j,i) */
{ /* KAMUS */
   MATRIKS MT;
   indeks i,j;
   /* ALGORITMA */
   MakeMATRIKS((*M).NBrsEff, (*M).NKolEff, &MT);
   for(i = GetFirstIdxBrs(MT); i <= GetLastIdxBrs(MT); i++) {
      for(j = GetFirstIdxKol(MT); j <= GetLastIdxKol(MT); j++) {
         MT.Mem[i][j] = (*M).Mem[j][i];
      }   
   }
   *M = MT;
}

float RataBrs (MATRIKS M, indeks i)
/* Menghasilkan rata-rata dari elemen pada baris ke-i */
/* Prekondisi: i adalah indeks baris efektif dari M */
{ /* KAMUS */
   indeks j;
   float sum = 0;
   /* ALGORITMA */
   for(j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); j++) {
      sum += (M).Mem[i][j];
   }
   return (sum/NKolEff(M));
}

float RataKol (MATRIKS M, indeks j)
/* Menghasilkan rata-rata dari elemen pada kolom ke-j */
/* Prekondisi: j adalah indeks kolom efektif dari M */
{ /* KAMUS */
   indeks i;
   float sum = 0;
   /* ALGORITMA */
   for(i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++) {
      sum += (M).Mem[i][j];
   }
   return (sum/NBrsEff(M));
}

void MaxMinBrs (MATRIKS M, indeks i, ElType * max, ElType * min)
/* I.S. i adalah indeks baris efektif dari M, M terdefinisi */
/* F.S. max berisi elemen maksimum pada baris i dari M
           min berisi elemen minimum pada baris i dari M */
{ /* KAMUS */
   indeks j;
   /* ALGORITMA */
   *min = Elmt(M, i, 0);
   *max = Elmt(M, i, 0);
   for(int j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); j++) {
      if (Elmt(M,i,j) > *max) {
         *max = Elmt(M,i,j);
      }
      if (Elmt(M,i,j) < *min) {
         *min = Elmt(M,i,j);
      }
   }
}

void MaxMinKol (MATRIKS M, indeks j, ElType * max, ElType * min)
/* I.S. j adalah indeks kolom efektif dari M, M terdefinisi */
/* F.S. max berisi elemen maksimum pada kolom j dari M
           min berisi elemen minimum pada kolom j dari M */
{ /* KAMUS */
   indeks i;
   /* ALGORITMA */
   *min = Elmt(M, 0, j);
   *max = Elmt(M, 0, j);
   for(int i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++) {
      if (Elmt(M,i,j) > *max) {
         *max = Elmt(M,i,j);
      }
      if (Elmt(M,i,j) < *min) {
         *min = Elmt(M,i,j);
      }
   }
}

int CountXBrs (MATRIKS M, indeks i, ElType X)
/* Menghasilkan banyaknya kemunculan X pada baris i dari M */
{ /* KAMUS */
   indeks j;
   int count = 0;
   /* ALGORITMA */
   for(j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); j++) {
      count += ((Elmt(M,i,j) == X) ? 1 : 0);
   }
   return (count);
}

int CountXKol (MATRIKS M, indeks j, ElType X)
/* Menghasilkan banyaknya kemunculan X pada kolom j dari M */
{ /* KAMUS */
   indeks i;
   int count =0;
   /* ALGORITMA */
   for(i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++) {
      count += ((Elmt(M,i,j) == X) ? 1 : 0);
   }
   return (count);
}