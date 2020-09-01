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
    printf("ERROR: %s\n", message)
  }
  exit(1);
}

void alive(const char *message)
{

}



//1 Test the error, how does perror interact with the printf
