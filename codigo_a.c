#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int num;
    pid_t t;

    for (num = 0; num < 2; num++) {
        t = fork(); /* 1 */
        if (t == 0)
            break;
    }
    t = fork(); /* 2 */
    printf("Soc el process %d y meu pare es %d\n", getpid(), getppid());
    
    return 0;
}
