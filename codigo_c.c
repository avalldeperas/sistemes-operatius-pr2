#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int pid, i , j;
    pid_t t;

    for (i = 0; i < 2; i++) {
        pid = getpid();
        for (j = 0 ; j < i+2; j++){
            t = fork();
            if (t != 0) {
                t = fork();
                break;
            }
        }
        if (pid != getpid())
            break;
    }
    return 0;
}
