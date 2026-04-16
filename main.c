#include <stdio.h>
#include "alat/alat.h"

int main() {
    int pilih;

    do {
        printf("\n=== MENU ALAT ===\n");
        printf("1. Tambah Alat\n");
        printf("2. Edit Alat\n");
        printf("3. Hapus Alat\n");
        printf("4. Lihat Alat\n");
        printf("0. Keluar\n");
        printf("Pilih: ");
        scanf("%d", &pilih);

        switch(pilih) {
            case 1: tambahAlat(); break;
            case 2: editAlat(); break;
            case 3: hapusAlat(); break;
            case 4: lihatAlat(); break;
            case 0: printf("Keluar...\n"); break;
            default: printf("Pilihan tidak valid!\n");
        }
    } while(pilih != 0);

    return 0;
}