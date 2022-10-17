#include "./lib_test/safe_math.h";
#include <stdio.h>

int main(int argc, char *argv[])
{
    int result = addWithSaturation(MAX_FOR_INT - 5, 7);
    printf("%d\n", result);
    result = addWithSaturation(MIN_FOR_INT + 5, -12);
    printf("%d\n", result);
    result = addWithSaturation(5, -12);
    printf("%d\n", result);
    return 0;
}