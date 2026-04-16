#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main() {
    int pilih;
    int berhasilLogin = 0;

    do {
        system("cls"); // kalau di Linux ganti "clear"

        printf("=================================\n");
        printf("        SISTEM APLIKASI\n");
        printf("=================================\n");
        printf("1. Login\n");
        printf("0. Keluar\n");
        printf("=================================\n");
        printf("Pilih menu: ");
        scanf("%d", &pilih);

        switch(pilih) {
            case 1:
                berhasilLogin = login();
                if (berhasilLogin == 1) {
                    menuUtama();
                }
                break;

            case 0:
                printf("Terima kasih!\n");
                break;

            default:
                printf("Pilihan tidak valid!\n");
        }

        printf("\nTekan ENTER untuk lanjut...");
        getchar(); 
        getchar();

    } while(pilih != 0);

    return 0;
}