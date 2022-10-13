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
    // TODO: Complete this code and document
    //check if there is 1 argument
    if(argc != 2) {
        printf("USAGE:\n  parta WORD");
        exit(1);
    } else {
        char* args[] = {"grep", "-q", argv[1], NULL};
        int pid = fork();
        if(pid > 0) {
            int status = 0;
            wait(&status);
            if(status == 0) {
                printf("%s found", argv[0]);
            } else {
                printf("%s not found", argv[0]);
            }
            exit(0);
            
        } else if(pid == 0) {
            int status = execv("/usr/bin/grep", args);
            exit(status);
        } else {
            printf("fork error");
            exit(1);
        }

    }
    return 0;
}
