#include <stdio.h>
#include "header.h"

int main() {
    int pilihan;
    int a, b;

    do {
        tampilkanMenu();
        printf("Pilih menu: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                printf("Masukkan angka 1: ");
                scanf("%d", &a);
                printf("Masukkan angka 2: ");
                scanf("%d", &b);
                printf("Hasil: %d\n", tambah(a, b));
                break;

            case 2:
                printf("Masukkan angka 1: ");
                scanf("%d", &a);
                printf("Masukkan angka 2: ");
                scanf("%d", &b);
                printf("Hasil: %d\n", kurang(a, b));
                break;

            case 3:
                printf("Program selesai.\n");
                break;

            default:
                printf("Pilihan tidak valid!\n");
        }

    } while (pilihan != 3);

    return 0;
}