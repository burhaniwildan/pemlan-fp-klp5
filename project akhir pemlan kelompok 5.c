#include <conio.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max_lines 100

typedef struct
{
    char id[15];
    char nama[50];
    char kategori[30];
    int stok;
} Barang;

void printDataBarang(Barang brg[], int n) {
    printf("+-------------------+-----------------------------------+-----------------------+--------+\n");
    printf("| ID                | NAMA BARANG                       |KATEGORI               |STOK    |\n");
    printf("+-------------------+-----------------------------------+-----------------------+--------+\n");
    int i;
    for (i = 0; i < n; i++) {
        printf("| %-17s | %-33s | %-21s | %-6d |\n", brg[i].id, brg[i].nama, brg[i].kategori, brg[i].stok);
    }
    printf("+-------------------+-----------------------------------+-----------------------+--------+\n");
    printf("\n");
}










//penulisan mantra ajaib bahasa c

//struct untuk data barang

//data barang

//void untuk menampilkan data barang

// void untuk melakukan bubble sort

//void untuk selection sort

//void untuk insertions sort

// syntax untuk melakukan jump search

// syntax utama
