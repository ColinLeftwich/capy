#include<stdio.h>
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

        char buffer[256];
        while(fgets(buffer, sizeof(buffer), file_ptr)) {
            printf("%s", buffer);
        }

        fclose(file_ptr);
    }

    return 0;
}