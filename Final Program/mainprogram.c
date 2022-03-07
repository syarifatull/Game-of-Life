/* EL2208 Praktikum Pemecahan Masalah dengan C 2019/2020
* MODUL 8 – TUGAS BESAR
* Kelompok : 1 Rombongan D
* Hari dan Tanggal : Jumat, 17 April 2020
* Asisten (NIM) : Arief Hirmanto (13217076)
* Nama File : main.c
* Deskripsi : Main program game of life
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <windows.h>
#include "readSeed.c"       //Memasukkan file readSeed.c pada file main untuk fungsi readSeed
#include "runTick.c"        //Memasukkan file runTick.c pada file main untuk fungsi runTick
#include "animate.c"        //Memasukkan file animate.c pada file main untuk fungsi runAnimation

//Deklarasi variable universal karena akan digunakan pada berbagai fungsi
FILE *file;
char filename[20];

int row, col;
int board[100][100];

//Fungsi pemilihan menu
void menu_game()
{

    int menu;
    printf("Silakan pilih salah satu menu :");
    printf("\n1.Animation");
    printf("\n2.Tick");
    printf("\n3.Quit");

    printf("\nMasukkan nomor menu : ");          //Meminta input menu
    scanf("%d", &menu);

    while((menu!=1) && (menu!=2) && (menu!=3))  //Keadaan bila input tidak valid
    {
        printf("Input menu tidak sesuai, ulangi!");

        printf("\nMasukkan nomor menu : ");
        scanf("%d", &menu);
    }

    if(menu==1)
    {
        printf("Anda memilih menu Animation\n");
        runAnimate(row, col, board);        //Memanggil fungsi runAnimate bila menu == 1
    }
    else if(menu==2)
    {
        printf("Anda memilih menu Tick\n");
        runTick(row, col, board);           //Memanggil fungsi runTick bila menu == 2

    }

    while(menu!=3)                        //Fungsi akan terus berjalan selama input menu adalah 1 atau 2
    {

        printf("Silakan pilih salah satu menu :");
        printf("\n1.Animation");
        printf("\n2.Tick");
        printf("\n3.Quit");

        printf("\nMasukkan nomor menu : ");          //Meminta input menu
        scanf("%d", &menu);

        while((menu!=1) && (menu!=2) && (menu!=3))  //Keadaan bila input tidak valid
        {
            printf("Input menu tidak sesuai, ulangi!");

            printf("\nMasukkan nomor menu : ");
            scanf("%d", &menu);
        }

        if(menu==1)
        {
            printf("Anda memilih menu Animation\n");
            runAnimate(row, col, board);        //Memanggil fungsi runAnimate bila menu == 1
        }
        else if(menu==2)
        {
            printf("Anda memilih menu Tick\n");
            runTick(row, col, board);           //Memanggil fungsi runTick bila menu == 2

        }
    }
    return;
}

//Program Utama
int main()
{
    //Judul dan Deskripsi Program
    printf("-----------------------------------GAME OF LIFE---------------------------------");
    printf("\n                            Welcome to Game of Life!");
    printf("\n");
    printf("\nProgram permainan simulasi sel yang menggambarkan perkembangan populasi");
    printf("\nProgram ini akan mensimulasikan sel yang berasal dari file seed yang anda inginkan.");
    printf("\nPerkembangan sel dan populasi yang terjadi akan dipengaruhi oleh beberapa aturan.");
    printf("\nPermainan ini akan meminta file seed dari anda, jadi jangan lupa siapkan file seed yang diinginkan!");
    printf("\n");
    printf("\n--------------------------------Selamat Bermain!-------------------------------");
    printf("\n");
    printf("\n");

    int pilihan_akhir;

    printf("Masukkan nama file eksternal berisi seed untuk simulasi: ");

    scanf("%s",filename);               //Meminta input file seed dari pengguna

    file = fopen(filename,"r+");        //Membuka file seed

    //Kondisi bila file input tidak valid atau kosong
    while(file==NULL)
    {
        printf("File yang anda masukkan kosong. Silakan ulangi!");

        printf("\nMasukkan nama file eksternal berisi seed untuk simulasi: ");

        scanf("%s",filename);

        file = fopen(filename,"r+");

    }

    readSeed(file, &row, &col, board);          //Mencetak file seed ke layar dengan memanggil fungsi readSeed
    menu_game();                                //Pemanggilan fungsi menu_game untuk memilih opsi

    printf("Anda memilih menu Quit");
    printf("\nMasukkan file seed baru?");       //Keadaan bila input menu = 3 atau quit
    printf("\n1. Ya");
    printf("\n2. Tidak");
    printf("\nNomor pilihan anda : ");

    //Meminta input pilihan akhir dari pengguna
    scanf("%d", &pilihan_akhir);

    //Kondisi bila input tidak valid
    while(pilihan_akhir!=1 && pilihan_akhir!=2)
    {
        printf("Pilihan anda salah, silakan ulangi!");
        printf("\nNomor pilihan anda : ");

        scanf("%d", &pilihan_akhir);
    }

    //Apabila pilihan_akhir == 1 maka program akan kembali ke awal dengan file seed baru
    while(pilihan_akhir==1)
    {
        printf("Masukkan nama file eksternal berisi seed untuk simulasi: ");    //Meminta kembali file seed baru

        scanf("%s",filename);

        file = fopen(filename,"r+");

        //Kondisi bila file yang dimasukkan tidak valid
        while(file==NULL)
        {
            printf("File yang anda masukkan kosong. Silakan ulangi!");

            printf("\nMasukkan nama file eksternal berisi seed untuk simulasi: ");

            scanf("%s",filename);

            file = fopen(filename,"r+");

        }

        //Memanggil fungsi untuk file seed yang baru
        readSeed(file, &row, &col, board);
        menu_game();

        printf("\nMasukkan file seed baru?");
        printf("\n1. Ya");
        printf("\n2. Tidak");
        printf("\nNomor pilihan anda : ");

        scanf("%d", &pilihan_akhir);

        while(pilihan_akhir!=1 && pilihan_akhir!=2)
        {
            printf("Pilihan anda salah, silakan ulangi!");
            printf("\nNomor pilihan anda : ");

            scanf("%d", &pilihan_akhir);
        }

    }

    //Program berakhir bila pengguna memilih pilihan_akhir == 2
    printf("                Terima kasih karena telah bermain Game of Life!");
    printf("\n                   Kami tunggu permainan anda berikutnya!");
    printf("\n------------------------------SEE YOU------------------------------\n");

    fclose(file);       //Menutup file

    return 0;
}
