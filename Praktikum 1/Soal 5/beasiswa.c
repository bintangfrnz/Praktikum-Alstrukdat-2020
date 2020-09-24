/*
 * NIM       : 13519138
 * Nama      : Bintang Fajarianto
 * Tanggal   : 27 Agustus 2020
 * Praktikum : 1
 * Soal		   : 5
 * Deskripsi : Mengkategorikan berdasarkan input ip dan pot
 */

#include <stdio.h>

int main() {
  /* KAMUS */
  float ip, pot;

  /* ALGORITMA */
  scanf("%f", &ip);
  scanf("%f", &pot);

  if (ip >= 3.5) {
    printf("4\n");
  } else if (pot < 1 && ip < 3.5) {
    printf("1\n");
  } else if (pot >= 1 && pot < 3.5) {
    if (ip >= 2.0) {
      printf("3\n");
    } else {
      printf("2\n");
    }
  } else {
    printf("0\n");
  }

  return 0;
}
