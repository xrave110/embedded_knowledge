#include <pthread.h>
#include <unistd.h>
#include <stdio.h>

void *myturn(void *arg)
{
    for (unsigned i = 0; i < 8; i++)
    {
        sleep(1);
        printf("My turn: %d\n", i);
    }
    return NULL;
}

void yourturn()
{
    for (unsigned i = 0; i < 3; i++)
    {
        sleep(2);
        printf("Your turn: %d\n", i);
    }
}

int main()
{
    pthread_t newThread;
    pthread_create(&newThread, NULL, myturn, NULL);
    //  myturn();
    yourturn();
    // wait until the thread is done
    pthread_join(newThread, NULL);
}
