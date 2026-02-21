#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Open file for read/write, create if doesn't exist using open()
    int fd = open("example.txt", O_RDWR | O_CREAT, 0666);
    // Write initial content to file
    write(fd, "Hello, World!", 13);
    // Seek back to beginning using lseek() - necessary for mmap
    lseek(fd, 0, SEEK_SET);

    struct stat st;
    // Get file status using fstat() - needed for file size
    fstat(fd, &st);
    // Map file into memory using mmap() - creates memory mapping
    // NULL: let system choose address, st.st_size: map entire file
    // PROT_READ|PROT_WRITE: allow read/write, MAP_SHARED: changes written back to file
    char *map = (char*) mmap(NULL, st.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);

    printf("Mapped content: %s\n", map);

    // Unmap memory using munmap() - removes mapping
    munmap(map, st.st_size);
    // Close file descriptor
    close(fd);
    // Remove the file
    unlink("example.txt");

    return 0;
}