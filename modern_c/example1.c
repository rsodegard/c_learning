#include <stdio.h>
#include <stdlib.h>

int main (void) {
  double A[5] = {
    [0] = 9.0,
    [3] = 5.54,
    [4] = .0007,
  };

  for (size_t i = 0; i < 5; i++) {
    printf("element %zu is %g, \tits square is %g\n", i, A[i], (A[i] * A[i]));
  };

  return EXIT_SUCCESS;
}
