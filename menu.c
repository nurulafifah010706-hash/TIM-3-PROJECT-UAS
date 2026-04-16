#include <stdio.h>
#include <stdlib.h>
#include "header.h"

void menuUtama() {
    int pilih;

    do {
        system("cls");

        printf("=== MENU UTAMA ===\n");
        printf("1. Tambah Data\n");
        printf("2. Lihat Data\n");
        printf("0. Logout\n");
        printf("Pilih: ");
        scanf("%d", &pilih);

        switch(pilih) {
            case 1:
                tambahData();
                break;
            case 2:
                lihatData();
                break;
        }

        getchar(); getchar();

    } while(pilih != 0);
}