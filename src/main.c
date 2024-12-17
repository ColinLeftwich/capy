#include<stdio.h> 
#include <fcntl.h>
#include <unistd.h>


int main(int argc, char **argv) {
    for (int arg = 1; arg < argc; arg++) {
        if (argc >= 2) {
            int fd = open(argv[arg], O_RDONLY);
            if (fd == -1) {
                fprintf(stderr, "capy: %s: No such file or directory\n", argv[arg]);
                return -1;
            }

            dup2(fd, 0);

            char byte; 
            while(read(0, &byte, sizeof(byte))) {
                write(1, &byte, sizeof(byte));
            };
            close(fd);
        }
    }

    if (isatty(0)) {
        return 0;
    }

    char byte; 
    while(read(0, &byte, sizeof(byte)) > 0) {
        write(1, &byte, sizeof(byte));
    };

    return 0;
}