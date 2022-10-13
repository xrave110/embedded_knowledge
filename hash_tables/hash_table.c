#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#define MAX_NAME 256
#define TABLE_SIZE 10
#define DELETED_NODE (person *)(0xFFFFFFFFFFFFFFFFUL)

typedef struct
{
    char name[MAX_NAME];
    int age;
} person;

person *hash_table[TABLE_SIZE];

void initHashTable()
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        hash_table[i] = NULL;
    }
    // table is empty
}

unsigned int hash(char *name)
{
    int length = strnlen(name, MAX_NAME);
    unsigned int hash_value = 0;
    for (int i = 0; i < length; i++)
    {
        hash_value += name[i];
        hash_value = (hash_value * name[i]) % TABLE_SIZE;
    }
    return hash_value;
}

void printTable()
{
    printf("\n-------HASH TABLE--------\n");
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        if (hash_table[i] == NULL)
        {
            printf("\t%i\t---\n", i);
        }
        else if (hash_table[i] == DELETED_NODE)
        {
            printf("\t%i\t-D-\n", i);
        }
        else
        {
            printf("\t%i\t%s\n", i, hash_table[i]->name);
        }
    }
}

bool hashTableInsert(person *p)
{
    if (p == NULL)
        return false;
    int index = hash(p->name);
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        int try = (i + index) % TABLE_SIZE;
        if (hash_table[try] == NULL ||
            hash_table[try] == DELETED_NODE)
        {
            hash_table[try] = p;
            return true;
        }
    }
    return false;
}

person *hashTableDelete(char *name)
{
    int index = hash(name);
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        int try = (index + i) % TABLE_SIZE;
        if (hash_table[try] == NULL)
        {
            return NULL;
        }
        if (hash_table[try] == DELETED_NODE)
            continue;
        if (strncmp(hash_table[try]->name, name, TABLE_SIZE) == 0)
        {
            person *tmp = hash_table[try];
            hash_table[try] = DELETED_NODE;
            return tmp;
        }
    }
    return NULL;
}

person *hashTableLookup(char *name)
{
    int index = hash(name);
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        int try = (index + i) % TABLE_SIZE;
        if (hash_table[try] == NULL)
        {
            return false; // not here
        }
        if (hash_table[try] == DELETED_NODE)
            continue;
        if (strncmp(hash_table[try]->name, name, TABLE_SIZE) == 0)
        {
            return hash_table[try];
        }
    }
    return NULL;
}

int main()
{
    initHashTable();
    printTable();
    person jacob = {.name = "Jacob",
                    .age = 23};
    person natalie = {.name = "Natalie",
                      .age = 24};
    person sasha = {.name = "Sasha",
                    .age = 26};
    person bruce = {.name = "Bruce",
                    .age = 19};
    person jessica = {.name = "Jessica",
                      .age = 27};
    person sarah = {.name = "Sarah",
                    .age = 17};
    person joseph = {.name = "Joseph",
                     .age = 57};
    hashTableInsert(&jacob);
    hashTableInsert(&natalie);
    hashTableInsert(&sasha);
    hashTableInsert(&bruce);
    hashTableInsert(&jessica);
    hashTableInsert(&sarah);
    hashTableInsert(&joseph);

    printTable();
    person *tmp = hashTableLookup("Jaco");
    if (tmp == NULL)
    {
        printf("Not found \n");
    }
    else
    {
        printf("Found %s \n", tmp->name);
    }
    tmp = hashTableLookup("Jacob");
    if (tmp == NULL)
    {
        printf("Not found \n");
    }
    else
    {
        printf("Found %s \n", tmp->name);
    }
    tmp = hashTableDelete("Natalie");
    printf("Deleted %s\n", tmp->name);
    printTable();
    // printf("Jacob => %u\n", hash("Jacob"));
    // printf("Natalie => %u\n", hash("Natalie"));
    // printf("Jessica => %u\n", hash("Jessica"));
    // printf("Bruce => %u\n", hash("Bruce"));
    // printf("BLEEEEE => %u\n", hash("BLEEEEE"));
    return 0;
}