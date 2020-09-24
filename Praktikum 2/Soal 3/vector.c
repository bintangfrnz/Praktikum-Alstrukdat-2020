/*
 * NIM       : 13519138
 * Nama      : Bintang Fajarianto
 * Tanggal   : 03 September 2020
 * Praktikum : 2
 * Soal      : 3
 */

// File: vector.c

#include <stdio.h>
#include "vector.h"

/* *** Konstruktor membentuk VECTOR *** */
VECTOR MakeVector(float x, float y)
/* Membentuk sebuah VECTOR dengan komponen absis x dan
   komponen ordinat y */
{ /* KAMUS */
    VECTOR v;
    /* ALGORITMA */
    v.X = x;
    v.Y = y;
    return v;
}

/* *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS  *** */
void TulisVector(VECTOR v)
/* Nilai v ditulis ke layar dengan format "<X,Y>"
   tanpa spasi, enter, atau karakter lain di depan, belakang, atau di antaranya
   Output X dan Y harus dituliskan dalam bilangan riil dengan 2 angka di belakang koma.
*/
/* I.S. v terdefinisi */
/* F.S. v tertulis di layar dengan format "<X,Y>" */
{ /* ALGORITMA */
    printf("<%.2f,%.2f>", v.X, v.Y);
}

/* *** KELOMPOK OPERASI LAIN TERHADAP TYPE *** */
float Magnitude(VECTOR v)
/* Menghasilkan magnitudo dari vector, yakni sqrt(v.x^2+v.y^2) */
{ /* KAMUS */
    float x, y;
    /* ALGORITMA */
    x = v.X;
    y = v.Y;
    return sqrt(x*x + y*y);
}

VECTOR Add(VECTOR a, VECTOR b)
/* Menghasilkan sebuah vector yang merupakan hasil a + b.
   Komponen absis vector hasil adalah vector pertama
   ditambah vector kedua, begitu pula dengan ordinatnya */
{ /* KAMUS */
    VECTOR newV;
    /* ALGORITMA */
    newV = MakeVector(a.X + b.X, a.Y + b.Y);
    return newV;
}

VECTOR Substract(VECTOR a, VECTOR b)
/* Menghasilkan sebuah vector yang merupakan hasil a - b.
   Komponen absis vector hasil adalah vector pertama
   dikurangi vector kedua, begitu pula dengan ordinatnya */
{ /* KAMUS */
    VECTOR newV;
    /* ALGORITMA */
    newV = MakeVector(a.X - b.X, a.Y - b.Y);
    return newV;
}

float Dot(VECTOR a, VECTOR b)
/* Menghasilkan perkalian dot vector, yakni a.x * b.x + a.y * b.y */
{ /* KAMUS */
    float x, y;
    /* ALGORITMA */
    x = a.X*b.X;
    y = a.Y*b.Y;
    return x+y;
}

VECTOR Multiply(VECTOR v, float s)
/* Menghasilkan perkalian skalar vector dengan s, yakni
   (s * a.x, s * a.y) */
{ /* KAMUS */
    VECTOR newV;
    /* ALGORITMA */
    newV = MakeVector(v.X*s, v.Y*s);
    return newV;
}

// Bintang Fajarianto
// NIM 13519138
