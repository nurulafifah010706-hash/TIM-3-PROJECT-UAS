#include <stdio.h>
#include "alat.h"

int main() {
    int pilih;

    do {
        printf("\n=== MENU ADMIN ===\n");
        printf("1. Tambah Alat\n");
        printf("2. Edit Alat\n");
        printf("3. Hapus Alat\n");
        printf("4. Lihat Alat\n");
        printf("5. Keluar\n");
        scanf("%d", &pilih);

       switch(pilih) {
    case 1:
        tambahAlat();
        break;
    case 2:
        editAlat();
        break;
    case 3:
        hapusAlat();
        break;
    case 4:
        lihatAlat();
        break;
    case 5:
        printf("Keluar...\n");
        break;
    default:
        printf("Pilihan tidak valid!\n");
}

    } while(pilih != 4);

    return 0;
}
