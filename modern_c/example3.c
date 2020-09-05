#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

void die(const char *message)
{
  //errno returns an error number and message
  if (errno) {
    // finds the errno value and writes it, if the *s in 'const char *s' is not null, it prepends it to the message with a colon
    perror(message);
  } else {
    printf("ERROR: %s\n", message);
  }
  exit(1);
}

void alive(const char *message)
{
  printf("The message is %s\n", message);
}

typedef int (*compare_cb) (int a, int b);

int *bsort(int *numbers, int count, compare_cb cmp)
{

  int temp = 0;
  int j = 0;
  int i = 0;
  //Setting malloc equal to the size of the count times the byte soze of an int
  int *target = malloc(count * sizeof(int));

  if(!target)
    die("Memory Error");

  memcpy(target, numbers, count * sizeof(int));

  for (i = 0; i < count; i++) {
    for (j = 0; j < count - 1; j++) {
      if (cmp(target[j], target[j + 1]) > 0){
        temp = target[j + 1];
        target[j + 1] = target[j];
        target[j] = temp;
      }
    }
  }
  return target;
}

int sorted_order(int a, int b)
{
	return a - b;
}

int reverse_order(int a, int b)
{
	return b - a;
}

void test_sorting(int *numbers, int count, compare_cb cmp)
{
	int i = 0;
	int *sorted = bsort(numbers, count, cmp);

	if (!sorted)
		die("Failed to sort as requested");

	for (i = 0; i < count; i++) {
		printf("Number %d ", sorted[i]);
	}
	printf("\n");

	free(sorted);
}

int main(int argc, char *argv[])
{
	if (argc < 2) die("USAGE: ex18 4 3 1 2 5");

	int count = argc - 1;
	int i = 0;
	char **inputs = argv + 1;

	int *numbers = malloc(count * sizeof(int));
	if (!numbers) die("Memory error");

	for (i = 0; i < count; i++) {
		numbers[i] = atoi(inputs[i]);
	}

	test_sorting(numbers, count, sorted_order);
	test_sorting(numbers, count, reverse_order);

	free(numbers);

	return 0;
}


//1 Test the error, how does perror interact with the printf
