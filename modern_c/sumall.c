#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
# define MAX 12


void die(const char *message)
{
	if (errno) {
		perror(message);
	} else {
		printf("ERROR: %s\n", message);
	}
	exit(1);
}
// BELOE IS GOOD FOR ONE NUMBER
// int array[];
//
// typedef struct Sum {
//   int total;
// } Sum;
//
// Sum this = {.total = 0};
//
// int main(int argc, char *argv[])
// {
//   if (argc < 1) die("USAGE: ./sumall");
//
//   printf("What numbers do you want to add? ");
//
//   fscanf(stdin, "%d", &this.total);
//
//   printf("%d\n", this.total);
//
//   return 0;
// }
//ABOVE IS GOOD FOR 1 NUMBER


int main(int argc, char* argv[])
{
    int array_of_ints[MAX];
    int i;
    int count = argc;
    int sum = 0;

    for (i = 0; i < argc && i < MAX; i++)
    {
        array_of_ints[i] = atoi(argv[i]);
        printf("%d ", array_of_ints[i]);
    }
    for (i = 0; i < count; i++) {
      sum += array_of_ints[i];
    }
      printf("%d\n", sum);

    return 0;
}
