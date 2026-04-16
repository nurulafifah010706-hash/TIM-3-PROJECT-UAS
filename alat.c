#include <stdio.h>
#include "alat.h"

void tambahAlat() {
  FILE *file = fopen("alat.txt", "a");

    Alat a;

    printf("ID: "); scanf("%u", &a.id);
    printf("Nama: "); scanf(" %[^\n]", a.nama);
    printf("Merek: "); scanf(" %[^\n]", a.merek);
    printf("Model: "); scanf(" %[^\n]", a.model);
    printf("Tahun: "); scanf("%u", &a.tahun);
    printf("Jumlah: "); scanf("%u", &a.jumlah);

    fprintf(file, "%u|%s|%s|%s|%u|%u\n",
        a.id, a.nama, a.merek, a.model, a.tahun, a.jumlah);

    fclose(file);

    printf("Alat berhasil ditambahkan!\n");
}

void editAlat() {
    FILE *file = fopen("alat.txt", "r");
    FILE *temp = fopen("temp.txt", "w");

    if (file == NULL || temp == NULL) {
        printf("File error!\n");
        return;
    }

    unsigned int idCari;
    printf("Masukkan ID alat: ");
    scanf("%u", &idCari);

    Alat a;
    int ketemu = 0;

    while (fscanf(file, "%u|%[^|]|%[^|]|%[^|]|%u|%u\n",
        &a.id, a.nama, a.merek, a.model, &a.tahun, &a.jumlah) != EOF) {

        if (a.id == idCari) {
            ketemu = 1;

            printf("Data baru:\n");
            printf("Nama: "); scanf(" %[^\n]", a.nama);
            printf("Merek: "); scanf(" %[^\n]", a.merek);
            printf("Model: "); scanf(" %[^\n]", a.model);
            printf("Tahun: "); scanf("%u", &a.tahun);
            printf("Jumlah: "); scanf("%u", &a.jumlah);
        }

        fprintf(temp, "%u|%s|%s|%s|%u|%u\n",
            a.id, a.nama, a.merek, a.model, a.tahun, a.jumlah);
    }

    fclose(file);
    fclose(temp);

    remove("alat.txt");
    rename("temp.txt", "alat.txt");

    if (ketemu)
        printf("Alat berhasil diedit!\n");
    else
        printf("ID tidak ditemukan!\n");
}


void hapusAlat() {
    FILE *file = fopen("alat.txt", "r");
    FILE *temp = fopen("temp.txt", "w");

    if (file == NULL || temp == NULL) {
        printf("File error!\n");
        return;
    }

    unsigned int idHapus;
    printf("Masukkan ID alat: ");
    scanf("%u", &idHapus);

    Alat a;
    int ketemu = 0;

    while (fscanf(file, "%u|%[^|]|%[^|]|%[^|]|%u|%u\n",
        &a.id, a.nama, a.merek, a.model, &a.tahun, &a.jumlah) != EOF) {

        if (a.id == idHapus) {
            ketemu = 1;
            continue; // skip (hapus)
        }

        fprintf(temp, "%u|%s|%s|%s|%u|%u\n",
            a.id, a.nama, a.merek, a.model, a.tahun, a.jumlah);
    }

    fclose(file);
    fclose(temp);

    remove("alat.txt");
    rename("temp.txt", "alat.txt");

    if (ketemu)
        printf("Alat berhasil dihapus!\n");
    else
        printf("ID tidak ditemukan!\n");
}

void lihatAlat() {
    FILE *file = fopen("alat.txt", "r");

    if (file == NULL) {
        printf("Data belum ada!\n");
        return;
    }

    Alat a;

    printf("\n=== DAFTAR ALAT ===\n");

    while (fscanf(file, "%u|%[^|]|%[^|]|%[^|]|%u|%u\n",
        &a.id, a.nama, a.merek, a.model, &a.tahun, &a.jumlah) != EOF) {

        printf("ID     : %u\n", a.id);
        printf("Nama   : %s\n", a.nama);
        printf("Merek  : %s\n", a.merek);
        printf("Model  : %s\n", a.model);
        printf("Tahun  : %u\n", a.tahun);
        printf("Jumlah : %u\n", a.jumlah);
        printf("----------------------\n");
    }

    fclose(file);
}

