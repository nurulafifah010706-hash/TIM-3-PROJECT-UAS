#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "pinjam.txt"

struct Data {
    char nama[50];
    char alat[50];
};

void pinjamAlat() {
    FILE *file = fopen(FILE_NAME, "a");
    struct Data d;

    printf("Nama peminjam: ");
    scanf(" %[^\n]", d.nama);
    printf("Nama alat: ");
    scanf(" %[^\n]", d.alat);

    fprintf(file, "%s;%s\n", d.nama, d.alat);
    fclose(file);

    printf("Alat berhasil dipinjam!\n");
}

void lihatAlat() {
    FILE *file = fopen(FILE_NAME, "r");
    struct Data d;

    if (file == NULL) {
        printf("Belum ada data.\n");
        return;
    }

    printf("\nDaftar Peminjaman:\n");
    while (fscanf(file, "%[^;];%[^\n]\n", d.nama, d.alat) != EOF) {
        printf("Nama: %s | Alat: %s\n", d.nama, d.alat);
    }

    fclose(file);
}

void kembalikanAlat() {
    FILE *file = fopen(FILE_NAME, "r");
    FILE *temp = fopen("temp.txt", "w");

    struct Data d;
    char namaCari[50];
    int ditemukan = 0;

    printf("Masukkan nama yang mengembalikan: ");
    scanf(" %[^\n]", namaCari);

    while (fscanf(file, "%[^;];%[^\n]\n", d.nama, d.alat) != EOF) {
        if (strcmp(d.nama, namaCari) != 0) {
            fprintf(temp, "%s;%s\n", d.nama, d.alat);
        } else {
            ditemukan = 1;
        }
    }

    fclose(file);
    fclose(temp);

    remove(FILE_NAME);
    rename("temp.txt", FILE_NAME);

    if (ditemukan) {
        printf("Data berhasil dihapus (alat dikembalikan)\n");
    } else {
        printf("Data tidak ditemukan\n");
    }
}

int main() {
    int pilihan;

    do {
        printf("\n=== SISTEM PEMINJAMAN ===\n");
        printf("1. Pinjam Alat\n");
        printf("2. Kembalikan Alat\n");
        printf("3. Lihat Data\n");
        printf("4. Keluar\n");
        printf("Pilih: ");
        scanf("%d", &pilihan);

        switch(pilihan) {
            case 1: pinjamAlat(); break;
            case 2: kembalikanAlat(); break;
            case 3: lihatAlat(); break;
            case 4: printf("Keluar...\n"); break;
            default: printf("Pilihan tidak valid!\n");
        }

    } while (pilihan != 4);

    return 0;
}
