#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int num;
    pid_t t;

    for (num = 1; num <= 3; num++) {
        t = fork();
        if (num == 3 && t == 0)
            execlp ("ls","ls","-l", NULL);
    }
    return 0;
}
