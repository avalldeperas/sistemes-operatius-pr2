#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

void printString(char *text){
  for (int i = 0; i < strlen(text) ; i++) {
    printf("%c", text[i]);
  }
}

int main()
{
  char firstString[20], secondString[20];
  pid_t t;

  printf("Cadena 1: \n");
  scanf("%s", firstString);

  printf("Cadena 2: \n");
  scanf("%s", secondString);

  t = fork();

  if (t == 0)
    printString(firstString);

  if (wait(NULL) == -1)
    exit(1);

  if (t != 0)
    printString(secondString);


  return 0;
}
