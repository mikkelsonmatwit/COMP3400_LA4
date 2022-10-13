#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

/**
 * The main function. Note that you don't need Javadoc here,
 * although you still need document major blocks (ifs, fors, etc.)
 */
int main(int argc, char* argv[]) {
    if(argc != 3) {
        printf("USAGE:\n  partb FILENAME words|lines");
        exit(1);
    } else {
        if(strcmp(argv[1], "lines") == 0) {
            char* args[] = {"wc", "-l", argv[0], NULL};
            int pid = fork();
            if(pid > 0) {
                int status = 0;
                wait(&status);
                exit(status);
            } else if(pid == 0) {
                int status = execv("/usr/bin/wc", args);
                printf("Child done\n");
                exit(status);
            }
        } else if(strcmp(argv[1], "words") == 0) {
            char* args[] = {"wc", "-w", argv[0], NULL};
            int pid = fork();
            if(pid > 0) {
                int status = 0;
                wait(&status);
                exit(status);
            } else if(pid == 0) {
                int status = execv("/usr/bin/wc", args);
                printf("Child done\n");
                exit(status);
            }
        } else {
            printf("USAGE:\n  partb FILENAME words|lines");
            exit(1);
        }
    }
}
