#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_LINE_LENGTH 256
#define MAX_WORDS 64

int tokenize_words(char *line, char *words[]) {
    char *token = strtok(line, ",\n"); // tokenize at "," and newline
    int wordlen = 0;

    while (token != NULL && wordlen < MAX_WORDS) {
        words[wordlen] = malloc(strlen(token) + 1);
        strcpy(words[wordlen], token);
        wordlen++;
        token = strtok(NULL, ",\n");
    }
    return wordlen;
}

void sort_alphabetically(char *words[], int len) {
    char *temp;
    int i, j;
    
    for (i = 0; i < len; i++) {
        for (j = 0; j < len - i - 1; j++) {
            if (strcmp(words[j], words[j + 1]) > 0) {
                temp = words[j];
                words[j] = words[j + 1];
                words[j + 1] = temp;
            }
        }
    }
}

void free_words(char* words[], int len) {
    for (int i = 0; i < len; i++) free(words[i]);
}

// void write_words_to_file(FILE *fpw, char *words[], int len) {
//     for (int j = 0; j < len; j++) {
//         for (int k = 0; words[j][k] != '\0'; k++) {
//             fputc(words[j][k], fpw);
//         }
//         if (j == len - 1) fputc('\n', fpw);
//         else fputc(' ', fpw); // space between words
//     }
// }

int main() {
    FILE *fpr, *fpw;
    char line[256];
    char *words[64];
    int i = 0, wordlen = 0;

    fpr = fopen("read.txt", "r");

    fpw = fopen("sorted.txt", "w");

    if (fpr == NULL || fpw == NULL) {
        printf("Error opening file");
        return 1;
    }

    /*LINE BY LINE*/

    while (fgets(line, MAX_LINE_LENGTH, fpr) != NULL) {
        wordlen = tokenize_words(line, words);
        sort_alphabetically(words, wordlen);
        // Write sorted words to file
        for (int i = 0; i < wordlen; i++) {
            fputs(words[i], fpw);
            if (i < wordlen - 1) fputc(' ', fpw); // space between words
        }
        free_words(words, wordlen); // free each word after writing
    }

    /*CHAR BY CHAR*/

    // char ch; // read file character by character

    // while((ch = fgetc(fpr)) != EOF) {
    //     if (ch == '\n') {
    //         line[i] = '\0';
    //         int wordlen = tokenize_words(line, words);

    //         sort_alphabetically(words, wordlen);

    //         //write manually char by char to file
    //         write_words_to_file(fpw, words, wordlen);
    //         free_words(words, wordlen);
            
    //     } else {
    //         if (i < MAX_LINE_LENGTH - 1) {
    //             line[i] = ch;
    //             i++;
    //         }
    //     }      
    // }
    // if (i > 0) // handle the last line if it doesn't end with a newline OR single line input
    // {
    //     line[i] = '\0';
    //     int wordlen = tokenize_words(line, words);
    //     sort_alphabetically(words, wordlen);
    //     //write manually char by char to file
    //     write_words_to_file(fpw, words, wordlen);

    //     free_words(words, wordlen);
    // }

    fclose(fpr);
    fclose(fpw);
    return 0;
}