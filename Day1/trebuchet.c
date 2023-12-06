#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {

    FILE *txtFile = fopen("input.txt", "r");
    FILE *outputFile = fopen("output.txt", "rw");

    const int maxLen = 256;
    char line[maxLen];

    while (fgets(line, maxLen, txtFile)) {
        char *text = strtok(line, "\n");
        int len = strlen(text);

        for (int i = 0; i < len; i++) {
            if (text[i] > 47 && text[i] < 58) {
                fprintf(outputFile, "%d", text[i] - '0');
            }
        }
        fprintf(outputFile, "\n");
    }

    fclose(txtFile);

    int sum = 0;

    while (fgets(line, maxLen, outputFile)) {
        char *text = strtok(line, "\n");
        int len = strlen(text);

        sum += ((text[0] - '0')*10) + (text[len-1] - '0');
    }

    printf("Sum: %d\n", sum);

    fclose(outputFile);

    return 0;
}