#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>


#define BUFFSIZE 1024

int main()
{
  char buffer1[BUFFSIZE], buffer2[BUFFSIZE];
  ssize_t lengthBuffer1, lengthBuffer2;
  pid_t t;

  char askStr1[] = "Cadena 1:\n";
  write(STDOUT_FILENO, askStr1, sizeof(askStr1));
  lengthBuffer1 = read(STDIN_FILENO, buffer1,  sizeof(buffer1));

  char askStr2[] = "Cadena 2:\n";
  write(STDOUT_FILENO, askStr2, sizeof(askStr2));
  lengthBuffer2 = read(STDIN_FILENO, buffer2,  sizeof(buffer2));

  t = fork();

  if (t == 0)
    write(STDOUT_FILENO, buffer1, lengthBuffer1 - 1);

  if (wait(NULL) == -1)
    exit(1);

  if (t != 0)
    write(STDOUT_FILENO, buffer2, lengthBuffer2);


  return 0;
}
