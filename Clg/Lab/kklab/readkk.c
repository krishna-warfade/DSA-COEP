#include <stdio.h>

int main() {
    FILE *fp;
    char s[80];

    fp = fopen("data.txt", "r");
    if (fp == NULL) printf("File can't be read !!");

    while (fgets(s, 80, fp))
    {
        printf("%s", s);
        
    }
    fclose(fp);
}
