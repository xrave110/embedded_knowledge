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
    printf("Address of pointer: %d\n", p);
    printf("Value of pointer: %d\n", p[1]);
    for (int i = amount - 1; i >= 0; i--)
    {

        p[i] = i;
        printf("Value of pointer: %d\n", p[i]);
    }
    printf("Address of pointer: %d\n", p);
    printf("Value of pointer: %d\n", p[1]);
    free(p);
    printf("Address of pointer: %d\n", p);
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
    char *result1 = ((b + a) < -13 ? "puts result > 6 \n" : "puts result <= 6 \n");
    char *result2 = ((int)(b + a) < -13 ? "puts result > 6 \n" : "puts result <= 6 \n");
    printf("%f\n", (b + a));
    printf("%d\n", (int)(b + a));
}

int main()
{
    int a = 14;
    int *ptr = &a;
    int retValAdd;
    int arr[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    ex1(0x12345678);
    retValAdd = add(ptr);
    arrays(arr);
    expression();
    expressionFloat();
    dynamic();
    return 0;
}