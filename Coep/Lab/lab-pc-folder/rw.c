#include<stdio.h>

int main() {
    FILE *fpw, *fpr;
    char ch;

    fpr = fopen("data.txt", "r");
    fpw = fopen("w.txt", "w");

    if (fpw == NULL || fpr == NULL) printf("No operation");

    char ch1;
    while (1) {
        ch = fgetc(fpr);
        if (ch == EOF) break;
        else fputc(ch, fpw);
    }

    fclose(fpr);
    fclose(fpw);
}