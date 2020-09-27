#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#define MAX 500

void die(const char *message)
{
	if (errno) {
		perror(message);
	} else {
		printf("ERROR: %s\n", message);
	}
	exit(1);
}

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
        printf("size %ld\n", sizeof(array_of_ints[i]));
    }
    for (i = 0; i < count; i++) {
      sum += array_of_ints[i];
    }
      printf("\nTotal is: %d\n", sum);

    return 0;
}
