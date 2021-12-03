#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define BUFFSIZE 10

char** get_argv(const int height,const int width){

  char** result = malloc(sizeof(char)*BUFFSIZE*3);
  for (int i=0; i < 3; i++)
    result[i] = malloc(sizeof(char)*BUFFSIZE);

  result[0] = NULL;
  sprintf(result[1], "%d", height);
  sprintf(result[2], "%d", width);

  return (char**)result;
}

int main(int argc, char *argv[])
{
    int i, height, width;

    if (argc!= 3) exit(0);

    height = atoi(argv[1]); /* height */
    width = atoi(argv[2]); /* width */

    /* init code */

    // Create parent
    if ((height > 1) && (fork() == 0)){
      main(3,get_argv(height - 1, width));
      return 0;
    }

    // Create son
    if ((width > 1) && (fork() == 0)){
      main(3,get_argv(1, width - 1));
      return 0;
    }

    /* end code */

    printf("Soc el proces %d y meu pare es %d\n", getpid(), getppid());
    sleep(50);
    return 0;
}
