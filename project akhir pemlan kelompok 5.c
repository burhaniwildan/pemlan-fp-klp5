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

//void untuk bubble sort
void BubbleSort(Barang brg[], int n, int kolom, int ascending) {
    int i;
    int j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            int compare = 0;
            switch (kolom) {
                case 1:
                    compare = strcmp(brg[j].id, brg[j + 1].id);
                    break;
                case 2:
                    compare = strcasecmp(brg[j].nama, brg[j + 1].nama);
                    break;
                case 3:
                    compare = strcmp(brg[j].kategori, brg[j + 1].kategori);
                    break;
                case 4:
                    compare = (brg[j].stok > brg[j + 1].stok) - (brg[j].stok < brg[j + 1].stok);
                    break;
            }

            if ((ascending && compare > 0) || (!ascending && compare < 0)) {
                Barang temp = brg[j];
                brg[j] = brg[j + 1];
                brg[j + 1] = temp;
            }
        }
    }
}

//void untuk selection sort
void SelectionSort(Barang brg[], int n, int kolom, int ascending) {
    int i;
    int j;
    for (i = 0; i < n - 1; i++) {
        int minMaxIdx = i;
        for (j = i + 1; j < n; j++) {
            int compare = 0;
            switch (kolom) {
                case 1:
                    compare = strcmp(brg[j].id, brg[minMaxIdx].id);
                    break;
                case 2:
                    compare = strcasecmp(brg[j].nama, brg[minMaxIdx].nama);
                    break;
                case 3:
                    compare = strcmp(brg[j].kategori, brg[minMaxIdx].kategori);
                    break;
                case 4:
                    compare = (brg[j].stok > brg[minMaxIdx].stok) - (brg[j].stok < brg[minMaxIdx].stok);
                    break;
            }

            if ((ascending && compare < 0) || (!ascending && compare > 0)) {
                minMaxIdx = j;
            }
        }
        if (minMaxIdx != i) {
            Barang temp = brg[i];
            brg[i] = brg[minMaxIdx];
            brg[minMaxIdx] = temp;
        }
    }
}

//penulisan mantra ajaib bahasa c

//struct untuk data barang

//data barang

//void untuk menampilkan data barang

// void untuk melakukan bubble sort



//void untuk insertions sort
void InsertionSort(Barang brg[], int n, int kolom, int ascending) {
    int i;
    int j;
    for (i = 1; i < n; i++) {
        Barang key = brg[i];
        j = i - 1;
        int compare;

        while (j >= 0) {
            switch (kolom) {
                case 1:
                    compare = strcmp(key.id, brg[j].id);
                    break;
                case 2:
                    compare = strcasecmp(key.nama, brg[j].nama);
                    break;
                case 3:
                    compare = strcmp(key.kategori, brg[j].kategori);
                    break;
                case 4:
                    compare = (key.stok > brg[j].stok) - (key.stok < brg[j].stok);
                    break;
            }

            if ((ascending && compare < 0) || (!ascending && compare > 0)) {
                brg[j + 1] = brg[j];
                j--;
            } else {
                break;
            }
        }
        brg[j + 1] = key;
    }
}
//SYNTAX UNTUK MELAKUKAN BINARY SEARCH
int binarySearch(Barang brg[], int n, int kolom, char *key) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        int compare = 0;

        switch (kolom) {
            case 1:
                compare = strcmp(brg[mid].id, key);
                break;
            case 2:
                compare = strcasecmp(brg[mid].nama, key);
                break;
            case 3:
                compare = strcmp(brg[mid].kategori, key);
                break;
            case 4:
                compare = atoi(key) - brg[mid].stok;
                break;
        }

        if (compare == 0)
            return mid;

        if (compare < 0)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}
//SYNTAX UNTUK MELAKUKAN SEQUENSIAL SEARCH
int sequentialSearch(Barang brg[], int n, int kolom, char *key) {
    int i;
    for (i = 0; i < n; i++) {
        int compare = 0;

        switch (kolom) {
            case 1:
                compare = strcmp(brg[i].id, key);
                break;
            case 2:
                compare = strcasecmp(brg[i].nama, key);
                break;
            case 3:
                compare = strcmp(brg[i].kategori, key);
                break;
            case 4:
                compare = atoi(key) - brg[i].stok;
                break;
        }

        if (compare == 0)
            return i;
    }
    return -1;
}
// syntax untuk melakukan jump search
int jumpSearch(Barang brg[], int n, int kolom, char *key) {
    int step = 3;
    int prev = 0;
    int i;

    while (prev < n &&
           ((kolom == 1 && strcmp(brg[(step < n ? step : n) - 1].id, key) < 0) ||
            (kolom == 2 && strcasecmp(brg[(step < n ? step : n) - 1].nama, key) < 0) ||
            (kolom == 3 && strcmp(brg[(step < n ? step : n) - 1].kategori, key) < 0))) {
        prev = step;
        step += 3;
        if (prev >= n)
            return -1;
    }

    // Linear search dalam blok
    for (i = prev; i < (step < n ? step : n); i++) {
        if ((kolom == 1 && strcmp(brg[i].id, key) == 0) ||
            (kolom == 2 && strcasecmp(brg[i].nama, key) == 0) ||
            (kolom == 3 && strcmp(brg[i].kategori, key) == 0)) {
            return i;
        }
    }
    return -1;
}
// syntax utama
