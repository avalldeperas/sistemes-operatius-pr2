#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int i, height, width;

    if (argc!= 3) exit(0);

    height = atoi(argv[1]); /* height */
    width = atoi(argv[2]); /* width */

    /* tu codigo aqui */

    printf("Soc el proces %d y meu pare es %d\n", getpid(), getppid());
    sleep(1);
    return 0;
}
