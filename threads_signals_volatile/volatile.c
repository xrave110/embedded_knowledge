#include <pthread.h> //thread
#include <unistd.h>  // sleep
#include <stdio.h>
#include <stdbool.h>

#define COMPILER_CHECK false
#define VOLATILE_DONE true

int other = 4;

#if VOLATILE_DONE
volatile bool done = false;
volatile int val = 8;
volatile int *p_val = &val;
#else
bool done = false;
int val = 8;
int *p_val = &val;
#endif

void *tfunc(void *arg)
{
    p_val = &other;
    sleep(2);
    done = true;
    return NULL;
}

// Why there will be some differences every run this function
// Pointer can change address which is pointing on
int square(volatile int *p)
{
    printf("SQUARE\n");
    sleep(1);
    return *p * *p;
}

int correct_square(volatile int *p)
{
    int x = *p;
    printf("SQUARE\n");
    sleep(1);
    return x * x;
}

int main()
{
    pthread_t t1;
    int sum = 0;
    // sum = square(p_val);
    pthread_create(&t1, NULL, tfunc, NULL);

    printf("Waiting...\n");

#if COMPILER_CHECK
    while (!done) // Here the compiler can optimalize the code to true !!
    {
        sleep(1); // compiler will check variable "done" if there is some action after the condition
    };
#else
    while (!done) // Here the compiler can optimalize the code to true !!
    {
    };
#endif
    printf("Ok. Moving on.\n");

    printf("The sum is: %d\n", sum);
    return 0;
}