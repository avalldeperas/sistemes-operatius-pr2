#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>


int main()
{
  char cadena1[10], cadena2[10];
  pid_t t;
  char ch;

  printf("Cadena 1:\n");
  while(read(STDIN_FILENO, &ch, 1) > 0 )
  {
    if (ch == '\n'){
      break;
    }
    strncat(cadena1, &ch, 1);
    fflush(stdin);
  }

  printf("Cadena 2:\n");
  while(read(STDIN_FILENO, &ch, 1) > 0 )
  {
    if (ch == '\n'){
      break;
    }
    strncat(cadena2, &ch, 1);
    fflush(stdin);
  }

  write(STDOUT_FILENO, cadena1, sizeof(cadena1)-1);
  write(STDOUT_FILENO, cadena2, sizeof(cadena2)-1);


  return 0;
}
