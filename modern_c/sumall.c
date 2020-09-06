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

int *sum_all(int *numbers, int count)
{
  for (i = 0; i < count; i++) {

  }
}

int main(int argc, char *argv[])
{
  if (argc < 2) die("USAGE: sumall 5 897 345");

  int count = argc - 1;
  int i = 0;
  char **inputs = argv + 1

}
