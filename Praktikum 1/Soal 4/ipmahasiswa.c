/*
 * NIM       : 13519138
 * Nama      : Bintang Fajarianto
 * Tanggal   : 27 Agustus 2020
 * Praktikum : 1
 * Soal		   : 4
 * Deskripsi : Menampilkan perbandingan nilai dan rata-rata
 */

#include <stdio.h>
#include <stdbool.h>

// fungsi bantuan
bool IsWithinRange(float x, float min, float max) {
   return (x >= min && x <= max);
}

int main() {
	/* KAMUS */
  float x = 0;
  float totalNilai = 0;
  int jumlah = 0;
  int jumlahLulus = 0;
  int jumlahTidakLulus = 0;

  /* ALGORITMA */
  while(x != -999) {
    scanf("%f", &x);
    if(IsWithinRange(x, 2.75, 4)) {
      totalNilai += x;
      jumlahLulus += 1;
      jumlah += 1;
    } else if(IsWithinRange(x, 0, 2.75)) {
      totalNilai += x;
      jumlahTidakLulus += 1;
      jumlah += 1;
    }
  }

  if (jumlah == 0) {
    printf("Tidak ada data\n");
  } else {
    printf("%d\n", jumlah);
    printf("%d\n", jumlahLulus);
    printf("%d\n", jumlahTidakLulus);
    printf("%.2f\n", totalNilai / jumlah);
  }
	
	return 0;
}
