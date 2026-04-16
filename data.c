#include <stdio.h>
#include "header.h"

void tambahData() {
    FILE *file = fopen("data.txt", "a");
    char nama[50];

    printf("Masukkan nama: ");
    scanf("%s", nama);

    fprintf(file, "%s\n", nama);
    fclose(file);

    printf("Data berhasil ditambahkan!\n");
}

void lihatData() {
    FILE *file = fopen("data.txt", "r");
    char nama[50];

    if (file == NULL) {
        printf("Belum ada data!\n");
        return;
    }

    printf("=== DATA ===\n");
    while (fscanf(file, "%s", nama) != EOF) {
        printf("- %s\n", nama);
    }

    fclose(file);
}