/*
 * NIM       : 13519138
 * Nama      : Bintang Fajarianto
 * Tanggal   : 27 Agustus 2020
 * Praktikum : 1
 * Soal		 : 3
 * Deskripsi : Melakukan konversi suhu dari Celcius ke permintaan user
 */

#include <stdio.h>

int main() {
	/* KAMUS */
	float c;
	char tipe;
	
	/* ALGORITMA */
	scanf("%f %c", &c, &tipe);
	printf("%.2f\n", (tipe == 'R') ? c*4/5 : (tipe == 'F') ? c*9/5+32 : c+273.15);
	
	return 0;
}
