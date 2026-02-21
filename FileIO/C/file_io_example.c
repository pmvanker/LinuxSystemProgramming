#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    char buffer[100];

    // Open file for writing using fopen - creates or truncates the file
    // "w" mode: write mode, creates file if it doesn't exist
    fp = fopen("example.txt", "w");
    if (fp == NULL) {
        perror("Error opening file for writing");
        return 1;
    }
    // Write to file using fprintf - formatted output to file stream
    fprintf(fp, "Hello, World!\n");
    // Close the file using fclose - flushes buffers and releases resources
    fclose(fp);

    // Open file for reading using fopen
    // "r" mode: read mode, file must exist
    fp = fopen("example.txt", "r");
    if (fp == NULL) {
        perror("Error opening file for reading");
        return 1;
    }
    // Read from file using fgets - reads a line from file
    fgets(buffer, 100, fp);
    printf("Read from file: %s", buffer);
    // Close the file
    fclose(fp);

    return 0;
}