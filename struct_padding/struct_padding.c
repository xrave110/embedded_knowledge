#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define MAX_NAME 60
#define STRUCT_BY_MEM(inputStruct) (int)(((float)sizeof(inputStruct) / (float)sizeof(NULL)) + 0.5)

//#pragma pack(1) - this fixes padding issue but uses more computation power

typedef struct
{
    uint16_t a;
    uint8_t b;
    char c[MAX_NAME];
    uint16_t d;
    uint8_t e;
    uint32_t l;
    uint8_t g;
    uint8_t h;
} WrongStruct;

typedef struct
{
    uint32_t l;
    uint16_t a;
    uint16_t d;
    char c[MAX_NAME];
    uint8_t b;
    uint8_t e;
    uint8_t g;
    uint8_t h;
} GoodStruct;

typedef struct
{
    uint8_t e;
    uint32_t l;
    uint8_t g;
    uint16_t a;
    uint8_t b;
    char c[MAX_NAME];
    uint16_t d;
    uint8_t h;
} ReallyWrongStruct;

char *_fillCharArrayWithDD()
{
    uint16_t i;
    static char array[MAX_NAME];
    for (i = 0; i < MAX_NAME; i++)
    {
        // printf("Current value of array[%d]: %d\n", i, array[i]);
        array[i] = 0xDD; // + i
        // printf("Changed value of array[%d]: %d\n", i, array[i]);
    }
    return (char *)array;
}

void _fillMemoryWithFF(uint8_t *memory, uint16_t length)
{
    uint16_t i;
    for (i = 0; i < length; i++)
    {
        memory[i] = 0xFF;
    }
}

void checkWrongStruct()
{
    WrongStruct wrongStruct;
    uint8_t idx;
    /* Sizes of the struct */
    printf("Size of wrong struct: %lu\n", sizeof(wrongStruct));
    printf("Number of wrong struct: %d", STRUCT_BY_MEM(wrongStruct));

    /* Filling the structs */
    _fillMemoryWithFF((uint8_t *)&wrongStruct, sizeof(wrongStruct));
    /* Filling the array */
    char *retVal = _fillCharArrayWithDD();

    /* Changing each attributes of the same type */
    wrongStruct.b = 0xAA;
    wrongStruct.e = 0xAA;
    wrongStruct.a = 0xBBBB;
    wrongStruct.d = 0xBBBB;
    wrongStruct.l = 0xCCCCCCCC;
    uint8_t *byte = (uint8_t *)&wrongStruct;
    memcpy(wrongStruct.c, retVal, sizeof(wrongStruct.c));
    /* Array check */
    // printf("Function's address %#x\n", (int)retVal);
    for (idx = 0; idx < MAX_NAME; idx++)
    {
        // printf("Function's values %#01x (%d)\n", (uint8_t)*retVal, idx);
        //  printf("Size of array element %lu\n", sizeof(*retVal));
        retVal++;
    }
    // printf("Function's values %#01x (%d)\n", (uint8_t)*retVal, idx);

    /* Memory checks */
    for (idx = 0; idx < sizeof(wrongStruct); idx++)
    {
        if (idx % (sizeof(NULL)) == 0)
        {
            printf("\nValue %lu of wrong struct: %#x (%d)", (idx / (sizeof(NULL) - 1)), (uint8_t)*byte, idx);
        }
        else
        {
            printf("\t %#x (%d)", (uint8_t)*byte, idx);
        }
        if (*byte == 0xff)
        {
            printf(" !!");
        }
        byte++;
    }
    printf("\n\n");
}

void checkGoodStruct()
{
    GoodStruct goodStruct;
    uint8_t idx;

    /* Sizes of the struct */
    printf("Size of good struct: %lu\n", sizeof(goodStruct));
    printf("Number of good struct: %d", STRUCT_BY_MEM(goodStruct));

    /* Filling the structs */
    _fillMemoryWithFF((uint8_t *)&goodStruct, sizeof(goodStruct));
    /* Filling the array */
    char *retVal = _fillCharArrayWithDD();

    /* Changing each attributes of the same type */
    goodStruct.b = 0xAA;
    goodStruct.e = 0xAA;
    goodStruct.a = 0xBBBB;
    goodStruct.d = 0xBBBB;
    goodStruct.l = 0xCCCCCCCC;
    uint8_t *byte = (uint8_t *)&goodStruct;
    memcpy(goodStruct.c, retVal, sizeof(goodStruct.c));
    /* Array check */
    // printf("Function's address %#x\n", (int)retVal);
    for (idx = 0; idx < MAX_NAME; idx++)
    {
        // printf("Function's values %#01x (%d)\n", (uint8_t)*retVal, idx);
        //  printf("Size of array element %lu\n", sizeof(*retVal));
        retVal++;
    }
    // printf("Function's values %#01x (%d)\n", (uint8_t)*retVal, idx);

    /* Memory checks */
    for (idx = 0; idx < sizeof(goodStruct); idx++)
    {
        if (idx % (sizeof(NULL)) == 0)
        {
            printf("\nValue %lu of wrong struct: %#x (%d)", (idx / (sizeof(NULL) - 1)), (uint8_t)*byte, idx);
        }
        else
        {
            printf("\t %#x (%d)", (uint8_t)*byte, idx);
        }
        if (*byte == 0xff)
        {
            printf(" !!");
        }
        byte++;
    }
    printf("\n\n");
}

void checkVeryWrongStruct()
{
    ReallyWrongStruct reallyWrongStruct;
    uint8_t idx;

    /* Sizes of the struct */
    printf("Size of very bad struct: %lu\n", sizeof(reallyWrongStruct));
    printf("Number of very bad struct: %d", STRUCT_BY_MEM(reallyWrongStruct));

    /* Filling the structs */
    _fillMemoryWithFF((uint8_t *)&reallyWrongStruct, sizeof(reallyWrongStruct));
    /* Filling the array */
    char *retVal = _fillCharArrayWithDD();

    /* Changing each attributes of the same type */
    reallyWrongStruct.b = 0xAA;
    reallyWrongStruct.e = 0xAA;
    reallyWrongStruct.a = 0xBBBB;
    reallyWrongStruct.d = 0xBBBB;
    reallyWrongStruct.l = 0xCCCCCCCC;
    uint8_t *byte = (uint8_t *)&reallyWrongStruct;
    memcpy(reallyWrongStruct.c, retVal, sizeof(reallyWrongStruct.c));
    /* Array check */
    // printf("Function's address %#x\n", (int)retVal);
    for (idx = 0; idx < MAX_NAME; idx++)
    {
        // printf("Function's values %#01x (%d)\n", (uint8_t)*retVal, idx);
        //  printf("Size of array element %lu\n", sizeof(*retVal));
        retVal++;
    }
    // printf("Function's values %#01x (%d)\n", (uint8_t)*retVal, idx);

    /* Memory checks */
    for (idx = 0; idx < sizeof(reallyWrongStruct); idx++)
    {
        if (idx % (sizeof(NULL)) == 0)
        {
            printf("\nValue %lu of wrong struct: %#x (%d)", (idx / (sizeof(NULL) - 1)), (uint8_t)*byte, idx);
        }
        else
        {
            printf("\t %#x (%d)", (uint8_t)*byte, idx);
        }
        if (*byte == 0xff)
        {
            printf(" !!");
        }
        byte++;
    }
    printf("\n\n");
}

int main(void)
{
    checkVeryWrongStruct();
    checkWrongStruct();
    checkGoodStruct();
}