#include<stdio.h>
#include <stdlib.h>
// I don't what I am doing :D

int main(int argc, char **argv) {
    for (int arg = 1; arg <= argc - 1; arg++) {
        FILE * file_ptr = fopen(argv[arg], "r");

        if (file_ptr == NULL) {
            printf("capy: ");
            printf("%s: ", argv[arg]);
            printf("No such file or directory\n");
            return 1;
        }
        int file_fd = fileno(file_ptr);

        idup2(file_fd, 0);
        close(file_fd);
        fclose(file_ptr);
    }

    char buffer[256];
    size_t data;

    while(fgets(buffer, sizeof(buffer), stdin)) {
        printf("%s", buffer);
    }
            
    return 0;
}