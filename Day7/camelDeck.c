#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {

    FILE *txtFile = fopen("input.txt", "r");
    FILE *outputFile = fopen("output.txt", "w");

    const int maxLen = 256;
    char line[maxLen];

    while (fgets(line, maxLen, txtFile)) {
        char *text = strtok(line, " ");
        char *bid = strtok(NULL, " ");
        int len = strlen(text);

        int numVariables = 13;
        int variables[] = {0,0,0,0,0,0,0,0,0,0,0,0,0};

        for (int i = 0; i < len; i++) {
            if (text[i] == '2') { 
                variables[0] += 1;
            }
            else if (text[i] == '3') { 
                variables[1] += 1;
            }
            else if (text[i] == '4') { 
                variables[2] += 1;
            }
            else if (text[i] == '5') { 
                variables[3] += 1;
            }
            else if (text[i] == '6') { 
                variables[4] += 1;
            }
            else if (text[i] == '7') { 
                variables[5] += 1;
            }
            else if (text[i] == '8') { 
                variables[6] += 1;
            }
            else if (text[i] == '9') { 
                variables[7] += 1;
            }
            else if (text[i] == 'T') { 
                variables[8] += 1;
            }
            else if (text[i] == 'J') { 
                variables[9] += 1;
            }
            else if (text[i] == 'Q') { 
                variables[10] += 1;
            }
            else if (text[i] == 'K') { 
                variables[11] += 1;
            }
            else if (text[i] == 'A') { 
                variables[12] += 1;
            }
        }
        for (int i=0; i < numVariables; i++) {
            if (variables[i] == 5) {
                fprintf(outputFile, "5: %s; Bid: %s", text, bid);
            }
        }
        for (int i=0; i < numVariables; i++) {
            if (variables[i] == 4) {
                fprintf(outputFile, "4: %s; Bid: %s", text, bid);
            }
        }
        for (int i=0; i < numVariables; i++) {
            if (variables[i] == 3) {
                for (int j=0; j < numVariables; j++) {
                    if (variables[j] == 2) {
                        fprintf(outputFile, "6: %s; Bid: %s", text, bid);
                    }
                }
            }
        }
        int count1 = 0;
        for (int i=0; i < numVariables; i++) {
            if (variables[i] == 3) {
                for (int i=0; i < numVariables; i++) {
                    if (variables[i] != 2) {
                        count1++;
                    }
                }
                if (count1 == 13) {
                    fprintf(outputFile, "3: %s; Bid: %s", text, bid);
                }
            }
        }
        int count4 = 0;
        for (int i=0; i < numVariables; i++) {
            if (variables[i] == 2) {
                for (int i=0; i < numVariables; i++) {
                    if (variables[i] == 2) {
                        count4++;
                    }
                }
                if (count4 == 2) {
                    fprintf(outputFile, "2: %s; Bid: %s", text, bid);
                }
            }
        }
        int count2 = 0;
        for (int i=0; i < numVariables; i++) {
            if (variables[i] == 2) {
                for (int i=0; i < numVariables; i++) {
                    if (variables[i] != 2 && variables[i] != 3) {
                        count2++;
                    }
                }
                if (count2 == 12) {
                    fprintf(outputFile, "1: %s; Bid: %s", text, bid);
                }
            }
        }
        int count3 = 0;
        for (int i=0; i < numVariables; i++) {
            if (variables[i] == 1) {
                for (int i=0; i < numVariables; i++) {
                    if (variables[i] != 2 && variables[i] != 3 && variables[i] != 4) {
                        count3++;
                    }
                }
                if (count3 == 13) {
                    fprintf(outputFile, "0: %s; Bid: %s", text, bid);
                }
            }
        }
    }

    fclose(txtFile);
    fclose(outputFile);

    return 0;
}