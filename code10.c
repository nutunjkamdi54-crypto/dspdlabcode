#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *inputFile, *outputFile;
    char ch;

    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error: Cannot open input.txt\n");
        return 1;
    }

    outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("Error: Cannot create output.txt\n");
        fclose(inputFile);
        return 1;
    }

    while ((ch = fgetc(inputFile)) != EOF) {
        fputc(ch, outputFile);
    }

    printf("File copied successfully.\n");

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}