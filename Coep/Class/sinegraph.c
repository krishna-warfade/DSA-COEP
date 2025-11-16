#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    FILE *fp;
    fp = fopen("data.txt", "w");
    int i;

    for (i = 0; i < 100; i++) {
        fprintf(fp,"%d %f\n", i, sin(i));
    }
    fclose(fp);

    system("gnuplot -e\"set terminal png; set output 'plot.png';plot 'data.txt' with lines\"");

    return 0;
}