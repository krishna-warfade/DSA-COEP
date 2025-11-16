#include <stdio.h>
#include <math.h>

int main() {
    FILE *fp;

    fp = fopen("sine.txt", "w");

    for (int i = 0; i <= 100; i++) {
        fprintf(fp, "%d %f\n",i , sin(i*0.1));
    }
    fclose(fp);

    return 0;
}