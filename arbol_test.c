#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

char** test(){
  char *result[] = {NULL, "1", "2"};
  return result;
}

int main(int argc, char *argv[])
{
    int i, height, width;

    if (argc!= 3) exit(0);

    height = atoi(argv[1]); /* height */
    width = atoi(argv[2]); /* width */

    /* init code */
    char cheight[10], cwidth[10];

    // Create parent
    if ((height > 1) && (fork() == 0)){
      sprintf(cheight, "%d", height - 1);
      sprintf(cwidth, "%d", width);
      char *result[] = {NULL, cheight, cwidth};
      main(3,result);

      return 0;
    }

    // Create son
    if ((width > 1) && (fork() == 0)){
      sprintf(cheight, "%d", 1);
      sprintf(cwidth, "%d", width - 1);
      char *result[] = {NULL, cheight, cwidth};
      main(3,result);

      return 0;
    }

    /* end code */

    printf("Soc el proces %d y meu pare es %d\n", getpid(), getppid());
    sleep(1);
    return 0;
}
