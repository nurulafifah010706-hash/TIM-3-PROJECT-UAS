#include <stdio.h>
<<<<<<< HEAD
#include "alat/alat.h"
=======
#include "alat.h"
>>>>>>> 608e2391435f6e1bc4cf49f0cd3841d9b1578604

int main() {
    int pilih;

    do {
<<<<<<< HEAD
        printf("\n=== MENU ALAT ===\n");
=======
        printf("\n=== MENU ADMIN ===\n");
>>>>>>> 608e2391435f6e1bc4cf49f0cd3841d9b1578604
        printf("1. Tambah Alat\n");
        printf("2. Edit Alat\n");
        printf("3. Hapus Alat\n");
        printf("4. Lihat Alat\n");
<<<<<<< HEAD
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
=======
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
>>>>>>> 608e2391435f6e1bc4cf49f0cd3841d9b1578604
