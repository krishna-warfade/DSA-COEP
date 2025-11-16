#include<stdio.h>

int main() {
    FILE *fp;
    fp = fopen("data.txt", "w");

    if (fp == NULL) printf("File can't be written");

    char ch;
    while((ch = getchar()) != EOF) {
        fputc(ch, fp);
    }
    fclose(fp);
    return 0;
}
