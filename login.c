#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int login(char *role) {
    FILE *file = fopen("akun.txt", "r");
    if (file == NULL) {
        printf("File akun tidak ditemukan!\n");
        return 0;
    }

    char inputUser[50], inputPass[50];
    char fileUser[50], filePass[50], fileRole[50];

    printf("Username: ");
    scanf("%s", inputUser);
    printf("Password: ");
    scanf("%s", inputPass);

    while (fscanf(file, "%s %s %s", fileUser, filePass, fileRole) != EOF) {
        if (strcmp(inputUser, fileUser) == 0 && strcmp(inputPass, filePass) == 0) {
            strcpy(role, fileRole);
            fclose(file);
            return 1;
        }
    }

    fclose(file);
    return 0;
}