#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>
#include <iostream>
#include <cstring>

int main() {
    int fd = open("example.txt", O_RDWR | O_CREAT, 0666);
    write(fd, "Hello, World!", 13);
    lseek(fd, 0, SEEK_SET);

    struct stat st;
    fstat(fd, &st);
    char *map = (char*) mmap(NULL, st.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);

    std::cout << "Mapped content: " << map << std::endl;

    munmap(map, st.st_size);
    close(fd);
    unlink("example.txt");

    return 0;
}