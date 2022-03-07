/* EL2208 Praktikum Pemecahan Masalah dengan C 2019/2020
* MODUL 8 – TUGAS BESAR
* Kelompok : 1 Rombongan D
* Hari dan Tanggal : Jumat, 17 April 2020
* Asisten (NIM) : Arief Hirmanto (13217076)
* Nama File : animate.c
* Deskripsi : Fungsi runAnimation untuk menjalankan tick sebanyak iterasi yang diinginkan.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <windows.h>
//#include "runTick.c"                //Memasukkan file runTick.c agar dapat berjalan

void runAnimate(int M, int N, int grid[M][N])
{
    int i, n;
    printf("Masukkan jumlah iterasi yang Anda inginkan: ");
    scanf("%d", &n);                //Input jumlah iterasi yang diinginkan
    //system("clear");
    system("cls");                  //Menghapus tampilan layar sebelumnya
    for(i = 0; i < n; i++)
    {
        //system("clear");
        system("cls");              //Menghapus tampilan layar sebelumnya
        runTick(M, N, grid);        //Memanggil fungsi runTick
        Sleep(250);                 //Delay selama 250 ms
    }
}
