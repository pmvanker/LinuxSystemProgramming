#include <sys/stat.h>
#include <iostream>
#include <cstdio>

int main() {
    // Create a file
    FILE *fp = fopen("test.txt", "w");
    fprintf(fp, "Test content\n");
    fclose(fp);

    // Change permissions
    if (chmod("test.txt", S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH) == -1) {
        perror("chmod failed");
        return 1;
    }

    std::cout << "Permissions changed successfully" << std::endl;

    // Remove the file
    remove("test.txt");

    return 0;
}