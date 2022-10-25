#include <stdio.h>
#include <inttypes.h>

// Dependence between little endian (first LSB bits) and big endian (first MSB bits)
void ex1(uint32_t input)
{
    uint8_t tmp = *(uint8_t *)&input;
    printf("\n--ex1--\n%u\n", tmp);
}

// volatile do not optimize
void arrays(int arr[3][3])
{
    int *arr11 = &arr[1][1];
    int *arr12 = &arr[1][2];
    int arrDiff = arr12 - arr11;
    printf("\n--Arrays--\n%d\n", arr11);
    printf("\n--Arrays--\n%d\n", arr12);
    printf("\n--Arrays--\n%d\n", arrDiff);
}

void dynamic()
{
    int *p;
    int amount = 0;
    printf("Address of pointer: %d\n", p);
    // printf("Value of pointer: %d\n", *p); // Segmentation fault
    printf("Put amount of numbers:\n");
    scanf("%d\n", &amount);
    p = (int *)malloc(sizeof(int) * amount);
    printf("Address of pointer: %ls\n", p);
    printf("Value of pointer: %ls\n", p[1]);
    for (int i = amount - 1; i >= 0; i--)
    {

        p[i] = i;
        printf("Value of pointer: %d\n", p[i]);
    }
    printf("Address of pointer: %d\n", p);
    printf("Value of pointer: %d\n", p[1]);
    free(p);
    printf("Address of pointer: %ls\n", p);
    printf("Value of pointer: %d\n", p[1]);
}

// Relation to casting
void expression()
{
    printf("Expresion\n");
    int a = -20;
    unsigned b = 6;
    char *result1 = ((b + a) > 6 ? "puts result > 6 \n" : "puts result <= 6 \n");
    char *result2 = ((int)(b + a) > 6 ? "puts result > 6 \n" : "puts result <= 6 \n");
    printf("%s", result1);
    printf("%s", result2);
}

void expressionFloat()
{
    printf("Expresion  float\n");
    int a = -20;
    float b = 6.2;
    unsigned c = 7;
    char *result1 = ((b + a) < -13 ? "puts result > 6 \n" : "puts result <= 6 \n");
    char *result2 = ((int)(b + a) < -13 ? "puts result > 6 \n" : "puts result <= 6 \n");
    char *result3 = ((a + c) <= 7 ? printf("(a+c)%u smaller\n", (a + c)) : printf("(a+c)%u greater or equal\n", (a + c)));
    printf("[int + float]: %f\n", (b + a));
    printf("%d\n", (int)(b + a));
    printf("d[int + unsigned]: %d\tu[int + unsigned]:%u\n", (a + c));
}

void demo(void)
{
    unsigned int x = 10;
    int y = -40;
    if (x + y > 10)
    {
        printf("Greater than 10\n");
    }
    else
    {
        printf("Less than or equals 10\n");
    }
    if ((int)x + y > 10)
    {
        printf("Greater than 10\n");
    }
    else
    {
        printf("Less than or equals 10\n");
    }
}

void casting()
{
    long mem = 0x123456789;
    char memA = (char)mem;       // does not depend on endiannes
    char memB = (*(char *)&mem); // does depend on endiannes
    printf("Full value: %x\nCasted value A: %x\tCasted value B: %x\n", mem, memA, memB);
}

int main()
{
    int a = 14;
    int *ptr = &a;
    int retValAdd;
    int arr[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    ex1(0x12345678);
    arrays(arr);
    expression();
    expressionFloat();
    // dynamic();
    demo();
    casting();
    fprintf(stdout, "Hello, World!");
    return 0;
}
// arrays to pointers, pointers to arrays int (*ptr)[10];
//  #include<stdio.h>

// int main()
// {
//     int y = 100;
//     const int x = y;

//     printf("%d\n", x);
//     return 0;
// }

// #include<stdio.h>
// #include<stdarg.h>

// Void fun(char *msg, ...);
// int main ()
// {
//    fun("IndiaMAX", 1, 4, 7, 11, 0);
//    return 0;
// }
//    void fun(char *msg, ...)
// {
// va_list ptr;{
//    int num;
//    va_start(ptr, msg);
//    num = va_arg(ptr, int);
//    num = va_arg(ptr, int);
//    printf("%d", num);
// }

// #include <stdio.h>
// #include <math.h>

// int main()
// {
//     float a = 5.375;
//     char *p;
//     int i;

//     p = (char *)&a;
//     for (i = 0; i <= 3; i++)
//         printf("%02x\n", (unsigned char)p[i]);
//     return 0;
// }
