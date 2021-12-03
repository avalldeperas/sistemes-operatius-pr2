#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int i, height, width;

    if (argc!= 3) exit(0);

    height = atoi(argv[1]); /* height */
    width = atoi(argv[2]); /* width */

    /* init code */
    int j;

    // Create Parents
    for(i = 1; i < height; i++)
      if (fork() != 0) break;

    // Create Childs
    for(j = 1; j < width; j++)
      if (fork() == 0) break;

    /* end code */

    printf("Soc el proces %d y meu pare es %d\n",getpid(), getppid());
    sleep(1);
    return 0;
}
