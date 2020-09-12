#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>


void die(const char *message)
{
	if (errno) {
		perror(message);
	} else {
		printf("ERROR: %s\n", message);
	}
	exit(1);
}

typedef struct Sum {
  int total;
} Sum;

Sum this = {.total = 0};

int main(int argc, char *argv[])
{
  if (argc < 1) die("USAGE: ./sumall");

  printf("What numbers do you want to add? ");
  fscanf(stdin, "%d", &this.total);

  printf("%d\n", this.total);

  return 0;
}
