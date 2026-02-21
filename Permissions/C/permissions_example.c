#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Create a file using fopen() for demonstration
    FILE *fp = fopen("test.txt", "w");
    fprintf(fp, "Test content\n");
    fclose(fp);

    // Change file permissions using chmod() - modifies file access permissions
    // S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH: rw-r--r-- (644)
    // S_IRUSR: read permission for owner, S_IWUSR: write for owner
    // S_IRGRP: read for group, S_IROTH: read for others
    if (chmod("test.txt", S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH) == -1) {
        perror("chmod failed");
        return 1;
    }

    printf("Permissions changed successfully\n");

    // Remove the file using remove() - deletes the file
    remove("test.txt");

    return 0;
}