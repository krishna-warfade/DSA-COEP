#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    FILE *fpr, *fpw;
    char line[256];
    char *words[64];
    int count = 0;

    fpr = fopen("read.txt", "r");
    if (fpr == NULL) {
        printf("Error opening file");
        return 1;
    }
    fpw = fopen("sorted.txt", "w");
    if (fpw == NULL) {
        printf("Error opening file");
        return 1;
    }


    fclose(fpr);
    fclose(fpw);
    return 0;
}