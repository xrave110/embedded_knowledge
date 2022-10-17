#include <stdlib.h>
#include <stdio.h>

void printPassedArguments(int argc, char *argv[])
{
    unsigned i;
    *argv++;
    for (i = 1; i < argc; i++)
    {
        printf("Passed args: %s\n", *argv);
        *argv++;
    }
    if (i <= 1)
    {
        printf("There are no arguments passed! \n");
    }
}

unsigned howManyBits(char *argvn)
{
    unsigned bitsCntr = 0;
    unsigned long twoMul = 1;
    unsigned long val = atol(argvn);
    printf("%ld\n", val);
    while (val != 0 && twoMul <= val)
    {
        twoMul = twoMul << 1;
        bitsCntr++;
    }
    return bitsCntr;
}

// Assumes little endian
void printBits(size_t const size, void const *const ptr)
{
    unsigned char *b = (unsigned char *)ptr;
    unsigned char byte;
    int i, j;

    for (i = size - 1; i >= 0; i--)
    {
        for (j = 7; j >= 0; j--)
        {
            byte = (b[i] >> j) & 1;
            printf("%u", byte);
        }
    }
    puts("");
}

long unsetRightMostBitSimple(char *argvn)
{
    unsigned long n = atol(argvn);
    return n & (n - 1);
}

long unsetRightMostBit(unsigned numberOfBits, char *argvn)
{
    unsigned long val = atol(argvn);
    // printBits(sizeof(unsigned long), &val);
    for (unsigned i = 0; i < numberOfBits; i++)
    {
        if ((val & (unsigned long)(1 << i)) > 0)
        {
            val &= ~(1 << i);
            unsigned long tmp = ~(1 << i);
            return val;
        }
    }
    return val;
}

int main(int argc, char *argv[])
{
    unsigned numberOfBits = 0;
    printPassedArguments(argc, argv);
    for (unsigned i = 1; i < argc; i++)
    {
        numberOfBits = howManyBits(argv[i]);
        printf("Arg %u (%s) has %u bits\n", i, argv[i], numberOfBits);
        unsigned long afterUnset = unsetRightMostBit(numberOfBits, argv[i]);
        unsigned long afterUnsetSimple = unsetRightMostBitSimple(argv[i]);
        if (afterUnsetSimple == afterUnset)
        {
            printf("Arg %u (%s) after unset of bit: %ld\n", i, argv[i], afterUnset);
        }
        else
        {
            printf("Some faults... (%ld != %ld)", afterUnset, afterUnsetSimple);
        }
    }
}