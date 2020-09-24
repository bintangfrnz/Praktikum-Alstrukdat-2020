/* 
 * NIM       : 13519138
 * Nama      : Bintang Fajarianto
 * Tanggal   : 27 Agustus 2020
 * Praktikum : 1
 * Soal		 : 6
 * Deskripsi : Menggambar pola belah ketupat menggunakan fungsi dan prosedur
 */

#include <stdio.h>

// Fungsi validasi input
int isValid(int N) {
    // isValid bertipe integer.
    // isValid mengembalikan nilai 1 bila N merupakan bilangan ganjil positif dan 0 jika bukan.
    return (N > 0 && N % 2 == 1);
}

// Fungsi membuat space
void GambarSpasi(int N, int i) {
    // Gambar spasi dari indeks j = 0 hingga N/2 - i - 1
    // Contoh: Jika N = 7 dan i = 2, spasi digambarkan dari indeks j = 0 hingga (7/2 - 2 - 1 = 0)

    /* KAMUS LOKAL */
    int j;

    /* ALGORITMA */
    for (j = 0; j < N/2 - i; j++) {
        printf(" ");
    }
}

// Fungsi mengeluarkan *
void GambarBintang(int N, int i) {
    // Gambar bintang dari indeks j = N/2 - i hingga N/2 + i
    // Contoh: Jika N = 7 dan i = 2, bintang digambarkan dari indeks j = (7/2 - 2 = 1) hingga (7/2 + 2 = 5)

    /* KAMUS LOKAL */
    int j;
    
    /* ALGORITMA */
    for (j = N/2 - i; j < N/2 + i + 1; j++) {
        printf("*");
    }
}

// Fungsi membentuk belah ketupat
void GambarBelahKetupat(int N) {
    // Gambar belah ketupat berukuran N * N

    /* KAMUS LOKAL */
    int i;

    /* ALGORITMA */
    for (i = 0; i < N/2; i++) {
        GambarSpasi(N, i);
        GambarBintang(N, i);
        // Tidak ada penggambaran spasi setelah N/2 + i + 1, langsung cetak newline / enter
        printf("\n");
    }
    for (i = N/2; i >= 0; i--) {
        GambarSpasi(N, i);
        GambarBintang(N, i);
        // Tidak ada penggambaran spasi setelah N/2 + i + 1, langsung cetak newline / enter
        printf("\n");
    }
}

// Program Utama
int main () {
    /* KAMUS */
    int N;

    /* ALGORITMA */
    scanf("%d", &N);

    if (isValid(N)){
        GambarBelahKetupat(N);
    } else {
        printf("Masukan tidak valid\n");
    }
    
    return 0;
}