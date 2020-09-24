/*
 * NIM       : 13519138
 * Nama      : Bintang Fajarianto
 * Tanggal   : 27 Agustus 2020
 * Praktikum : 1
 * Soal		 : 2
 * Deskripsi : Menampilkan maksimum dari 3 integer.
 */

#include <stdio.h>

int main() {
	/* KAMUS */
	int a, b, c;
	
	/* ALGORITMA */
	scanf("%d %d %d", &a, &b, &c);
	printf("%d\n", (a > b) ? a : (b > c) ? b : c);
	
	return 0;
}
