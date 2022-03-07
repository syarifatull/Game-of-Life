/* EL2208 Praktikum Pemecahan Masalah dengan C 2019/2020
* MODUL 8 – TUGAS BESAR
* Kelompok : 1 Rombongan D
* Hari dan Tanggal : Jumat, 17 April 2020
* Asisten (NIM) : Arief Hirmanto (13217076)
* Nama File : readSeed.c
* Deskripsi : Fungsi untuk menerima file eksternal berisi seed yang akan digunakan untuk simulasi,
              serta print file eksternal tersebut yang terdiri dari jumlah baris, jumlah kolom, dan array seed awal
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

// Fungsi readSeed dengan parameter input pointer file, pointer integer row, pointer integer coloumn, dan array of int board[][100]
void readSeed(FILE* file, int* row, int* col, int board[][100])
{
    // Deklarasi variabel string yang akan digunakan untuk membaca jumlah baris dan kolom
    char strrow[3];
    char strcol[3];

    // Deklarasi variabel string yang akan digunakan untuk membaca tiap baris seed
    char str[50];

    // Deklarasi array of char untuk menyimpan string tiap baris seed yang telah dibaca dari file eksternal
    char table[100][100];

    // Deklarasi variabel
    int height, width, i,j;

    // Membaca dua baris pertama berisi string jumlah baris dan string jumlah kolom
    fscanf(file, "%s\n", strrow);
    fscanf(file, "%s\n", strcol);

    // Mengubah string jumlah baris dan string jumlah kolom dalam bentuk integer dan menyimpannya di variabel row dan col
    *row = atoi(strrow);
    *col = atoi(strcol);

    // Output jumlah baris dan kolom seed
    printf("%d\n", *row);
    printf("%d", *col);

    // Looping membaca file sepanjang baris dan kolom
    for(width = 0; width < *row; width++)
    {
        fgets(str, 50, file); // membaca string pada tiap baris seed
        printf("\n");
        for(height = 0; height < *col; height++)
        {
            table[width][height] = str[height]; // menyimpannya dalam array of char
            printf("%c", table[width][height]); // print seed berisi char sel hidup dan sel mati
        }
    }

    printf("\n");

    // Looping untuk mengubah array of char menjadi array of integer agar dapat diproses untuk selanjutnya
    for(width = 0; width < *row; width++)
    {
        for(height = 0; height < *col; height++)
        {
            if ((table[width][height]) == 'X')
            {
                board[width][height] = 1; // jika dia sel hidup, maka bernilai 1
            }
            else
            {
                board[width][height] = 0; // jika dia sel mati, maka bernilai 0
            }
        }
    }
}
