#include<stdio.h> 
// I don't what I am doing :D

void print_stdin() {
    char buffer[256];
    while(fgets(buffer, sizeof(buffer), stdin)) {
        printf("%s", buffer);
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        print_stdin();
        return 0;
    }

    for (int arg = 1; arg <= argc - 1; arg++) {
        FILE * file_prt = freopen(argv[arg], "r", stdin);

        if (file_prt == NULL) {
            printf("capy: ");
            printf("%s: ", argv[arg]);
            printf("No such file or directory\n");
            return 1;
        }

        print_stdin();
        fclose(file_prt);
    }

    return 0;
}