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
    //printf("argc: %d\n", argc);
    
    if (argc == 3) {
        //printf("): %s\n", argv[0]);
        //printf("1: %s\n", argv[1]);
        if(strcmp(argv[2], "lines") == 0) {
            char* args[] = {"wc", "-l", argv[1], NULL};
            int pid = fork();
            printf("pid: %d\n", pid);
            if(pid > 0) {
                printf("enter parent process");
                exit(0);
                int status = 0;
                wait(&status);
                exit(0);
            } else if(pid == 0) {
                printf("enter child process");
                int status = execv("/usr/bin/wc", args);
                printf("Child done\n");
                exit(status);
            }
        } else if(strcmp(argv[2], "words") == 0) {
            char* args[] = {"wc", "-w", argv[1], NULL};
            int pid = fork();
            if(pid > 0) {
                int status = 0;
                wait(&status);
                exit(0);
            } else if(pid == 0) {
                int status = execv("/usr/bin/wc", args);
                printf("Child done\n");
                exit(status);
            }
        } else {
            printf("USAGE:\n  partb FILENAME words|lines");
            exit(1);
        }
    } else {
        printf("USAGE:\n  partb FILENAME words|lines");
        exit(1);
    }
}
