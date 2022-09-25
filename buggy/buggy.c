#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define WHICH_ARG 1
#define LINE_LENGTH 4096

int main(int argc, char **argv)
{
    char *buffer = malloc(LINE_LENGTH);
    printf("I am HERE 1"); // not always does work as a good debbuging way
    // printf("I am HERE 1\n"); // in order to debug correctly you have to establish goos output streamline
    memset(buffer, 0, LINE_LENGTH);
    strcpy(buffer, argv[WHICH_ARG]);
    printf("I am HERE 2"); // not always does work as a good debbuging way
    printf("Input: %s\n", buffer);
    puts(buffer);
}