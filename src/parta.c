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
        printf("USAGE:/n/tparta WORD");
        exit(1);
    } else {
        int fork_ret = fork();
        if(fork_ret == 0) {
            int status = execv("/usr/bin/grep", argv);
            exit(status);
        } else if(fork_ret > 0) {
            int status;
            wait(&status);
            if(status == 0) {
                printf("%s found", argv[1]);
            } else {
                printf("%s not found", argv[1]);
            }
        }

    }
    return 0;
}
