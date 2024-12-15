#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

 
typedef struct {
    char npm[15];
    char nama[50];
    char prodi[30];
    float ipk;
} Mahasiswa;

 
Mahasiswa dataMahasiswa[] = {
    {"23081010001", "Syaifudin Afandi", "Teknik Informatika", 3.5},
    {"23081010196", "Ahmad Anas", "Teknik Informatika", 3.2},
    {"23051010163", "Zidan Abidin", "Teknik Elektro", 3.8},
    {"23052010124", "Alfarizi Zizi", "Teknik Industri", 4.0},
    {"23071010045", "Ahmad Robi", "DKV", 3.7},
    {"23021010116", "Narendra Putra", "Akuntansi", 2.9},
    {"23061010017", "Gading Angkasa", "Hukum", 3.6},
    {"23022010058", "Dimas Waskita", "Psikologi", 3.9},
    {"23091010079", "Rafli Alfiro", "Kedokteran", 3.4},
    {"23091010110", "Ale Putra", "Biologi", 3.3},
    {"23081010051", "liam Saputra", "Teknik Informatika", 3.75},
    
};

 
void printDataMahasiswa(Mahasiswa mhs[], int n) {
    printf("+-------------------+-----------------------------------+-----------------------+------+\n");
    printf("| NPM               | NAMA                              | PRODI                 | IPK  |\n");
    printf("+-------------------+-----------------------------------+-----------------------+------+\n");
    for (int i = 0; i < n; i++) {
        printf("| %-17s | %-33s | %-21s | %.2f |\n", mhs[i].npm, mhs[i].nama, mhs[i].prodi, mhs[i].ipk);
    }
    printf("+-------------------+-----------------------------------+-----------------------+------+\n");
    printf("\n");
}

 
void BubbleSort(Mahasiswa mhs[], int n, int kolom, int ascending) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            int compare = 0;
            switch (kolom) {
                case 1: 
                    compare = strcmp(mhs[j].npm, mhs[j + 1].npm);
                    break;
                case 2:  
                    compare = strcasecmp(mhs[j].nama, mhs[j + 1].nama);
                    break;
                case 3:  
                    compare = strcmp(mhs[j].prodi, mhs[j + 1].prodi);
                    break;
                case 4:  
                    compare = (mhs[j].ipk > mhs[j + 1].ipk) - (mhs[j].ipk < mhs[j + 1].ipk);
                    break;
            }

            if ((ascending && compare > 0) || (!ascending && compare < 0)) {
                Mahasiswa temp = mhs[j];
                mhs[j] = mhs[j + 1];
                mhs[j + 1] = temp;
            }
        }
    }
}

 
void SelectionSort(Mahasiswa mhs[], int n, int kolom, int ascending) {
    for (int i = 0; i < n - 1; i++) {
        int minMaxIdx = i;
        for (int j = i + 1; j < n; j++) {
            int compare = 0;
            switch (kolom) {
                case 1: 
                    compare = strcmp(mhs[j].npm, mhs[minMaxIdx].npm);
                    break;
                case 2:  
                    compare = strcasecmp(mhs[j].nama, mhs[minMaxIdx].nama);
                    break;
                case 3: 
                    compare = strcmp(mhs[j].prodi, mhs[minMaxIdx].prodi);
                    break;
                case 4:  
                    compare = (mhs[j].ipk > mhs[minMaxIdx].ipk) - (mhs[j].ipk < mhs[minMaxIdx].ipk);
                    break;
            }

            if ((ascending && compare < 0) || (!ascending && compare > 0)) {
                minMaxIdx = j;
            }
        }
        if (minMaxIdx != i) {
            Mahasiswa temp = mhs[i];
            mhs[i] = mhs[minMaxIdx];
            mhs[minMaxIdx] = temp;
        }
    }
}

 
void InsertionSort(Mahasiswa mhs[], int n, int kolom, int ascending) {
    for (int i = 1; i < n; i++) {
        Mahasiswa key = mhs[i];
        int j = i - 1;
        int compare;

        while (j >= 0) {
            switch (kolom) {
                case 1:  
                    compare = strcmp(key.npm, mhs[j].npm);
                    break;
                case 2:  
                    compare = strcasecmp(key.nama, mhs[j].nama);
                    break;
                case 3:  
                    compare = strcmp(key.prodi, mhs[j].prodi);
                    break;
                case 4:  
                    compare = (key.ipk > mhs[j].ipk) - (key.ipk < mhs[j].ipk);
                    break;
            }

            if ((ascending && compare < 0) || (!ascending && compare > 0)) {
                mhs[j + 1] = mhs[j];
                j--;
            } else {
                break;
            }
        }
        mhs[j + 1] = key;
    }
}

int jumpSearch(Mahasiswa mhs[], int n, int kolom, char *key) {
    int step = 3;   
    int prev = 0;

   
    while (prev < n && 
           	((kolom == 1 && strcmp(mhs[(step < n ? step : n) - 1].npm, key) < 0) ||
            (kolom == 2 && strcasecmp(mhs[(step < n ? step : n) - 1].nama, key) < 0) ||
            (kolom == 3 && strcmp(mhs[(step < n ? step : n) - 1].prodi, key) < 0))) {
        prev = step;
        step += 3;
        if (prev >= n) return -1;  
    }

    // Linear search dalam blok
    for (int i = prev; i < (step < n ? step : n); i++) {
        if ((kolom == 1 && strcmp(mhs[i].npm, key) == 0) ||
            (kolom == 2 && strcasecmp(mhs[i].nama, key) == 0) ||
            (kolom == 3 && strcmp(mhs[i].prodi, key) == 0)) {
            return i;  
        }
    }
    return -1;  
}


int main() {
    int n = sizeof(dataMahasiswa) / sizeof(dataMahasiswa[0]);
    int pilihan, kolom, ascending, flag;
    char key[50];

    do {
    	do {
    		system("cls");
        	printf("Data Mahasiswa Sebelum diurutkan:\n");
        	printDataMahasiswa(dataMahasiswa, n);
        	printf("Menu Pengurutan:\n");
        	printf("1. Bubble Sorting\n");
        	printf("2. Selection Sorting\n");
        	printf("3. Insertion Sorting\n");
        	printf("4. Jump Search\n");
			printf("5. Keluar\n");
        	printf("Pilih opsi (1-5): ");
        	scanf("%d", &pilihan);
        	flag = 0;
        	if (pilihan != 1 && pilihan != 2 && pilihan != 3 && pilihan != 4 && pilihan != 5) {
            	printf("Pilihan Sorting Tidak Valid\n");
            	flag = 1;
            	system("pause");
			}
			
		} while (flag == 1);
		
        if (pilihan == 5) {
            printf("Keluar dari program.\n");
			break;
		}
		
		if (pilihan == 4) {
            printf("\nPilih kolom untuk pencarian:\n");
            printf("1. NPM\n");
            printf("2. Nama\n");
            printf("3. Prodi\n");
            printf("Pilihan (1-3): ");
            scanf("%d", &kolom);

            printf("\nMasukkan nilai yang ingin dicari: ");
            scanf(" %[^\n]", key);

            int index = jumpSearch(dataMahasiswa, n, kolom, key);

            if (index != -1) {
                printf("\nData ditemukan:\n");
                printDataMahasiswa(&dataMahasiswa[index], 1);
            } else {
                printf("\nData tidak ditemukan.\n");
            }
            system("pause");
        } 

        
        do {
        	if (pilihan == 4){
        		break;
			}
            printf("\nPilih kolom untuk pengurutan:\n");
            printf("1. NPM\n");
            printf("2. Nama\n");
            printf("3. Prodi\n");
            printf("4. IPK\n");
            printf("Pilihan (1-4): ");
            scanf("%d", &kolom);
            flag = 0;
            if (kolom != 1 && kolom != 2 && kolom != 3 && kolom != 4) {
            	printf("Pilihan Kolom Tidak Valid\n");
            	flag = 1;
			}
		} while (flag == 1);
        
        do {
        	if (pilihan == 4){
        		break;
			}
        	printf("\nPilih tipe pengurutan:\n");
            printf("1. Ascending  \n");
            printf("2. Descending \n");
            printf("Pilihan tipe (1-2): ");
            scanf("%d", &ascending);
            flag = 0;
			if (ascending != 1 && ascending != 2) {
				printf("Pilihan Tipe Pengurutan Tidak Valid\n");
				flag = 1;
			}
            ascending = (ascending == 1);
		} while (flag == 1);
            

        switch (pilihan) {
            case 1:
                BubbleSort(dataMahasiswa, n, kolom, ascending);
                break;
            case 2:
                SelectionSort(dataMahasiswa, n, kolom, ascending);
                break;
            case 3:
                InsertionSort(dataMahasiswa, n, kolom, ascending);
                break;
		}
		
		if (pilihan != 4){
			printf("\nData Mahasiswa setelah diurutkan:\n");
        	printDataMahasiswa(dataMahasiswa, n);
        	system("pause");
		}
        

    } while (pilihan != 5);

    return 0;
}

