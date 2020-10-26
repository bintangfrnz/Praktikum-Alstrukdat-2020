/*
 * NIM          : 13519138
 * Nama         : Bintang Fajarianto
 * Tanggal      : 22 Oktober 2020
 * Praktikum    : 8
 * Soal         : 1
 */

// File: ekspresi.c

#include <stdio.h>
#include <math.h>
#include "mesintoken.h"
#include "stackt.h"

boolean EndToken;
Token CToken;

int main() {
    /* KAMUS */
    Stack S;
    int angka1, angka2;
    int hasil = 0;

    /* ALGORITMA */
    CreateEmpty(&S);
    STARTTOKEN();

    while (!EndToken) {
        if (CToken.tkn == 'b') {
            Push(&S, CToken.val);
            printf("%d\n", CToken.val);
        } else {
            Pop(&S, &angka1);
            Pop(&S, &angka2);
            switch(CToken.tkn) {
                case '+':
                    hasil = angka2 + angka1;
                    printf("%d + %d\n", angka2, angka1);
                    break;
                case '-':
                    hasil = angka2 - angka1;
                    printf("%d - %d\n", angka2, angka1);
                    break;   
                case '*':
                    hasil = angka2 * angka1;
                    printf("%d * %d\n", angka2, angka1);
                    break;
                case '/':
                    hasil = (int) angka2 / angka1;
                    printf("%d / %d\n", angka2, angka1);
                    break;
                case '^':
                    hasil = pow(angka2,angka1);
                    printf("%d ^ %d\n", angka2, angka1);
                    break; 
                default:
                    hasil = hasil;
                    break;  
            }
            Push(&S, hasil);
            printf("%d\n", hasil);
        }
        ADVTOKEN();
    }

    if (IsEmpty(S)) printf("Ekspresi kosong\n");
    else printf("Hasil=%d\n", InfoTop(S));

    return 0;
}