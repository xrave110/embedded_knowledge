#include <stdio.h>

void pointerArrayAndArrayPointer()
{
    // Pointer to an integer
    int *p;

    // Pointer to an array of 5 integers
    int(*ptr)[5];
    int arr[5];

    printf("arr = %p, &arr = %p\n", arr, &arr);
    // Points to 0th element of the arr.
    p = arr;

    // Points to the whole array arr.
    ptr = &arr;

    printf("p = %p, ptr = %p\n", p, ptr);

    p++;
    ptr++;

    printf("p = %p, ptr = %p\n", p, ptr);
}

void poinetrsOffsets()
{
    int arr[] = {10, 20, 30, 40, 50, 60};
    int *ptr1 = arr;
    int *ptr2 = arr + 5;
    printf("Number of elements between two pointer are: %d.\n",
           (ptr2 - ptr1));
    printf("Number of bytes between two pointers are: %d",
           (char *)ptr2 - (char *)ptr1);
}
void intsAndChars()
{
    /* Depend on endianess */
    int a;
    char *x;
    x = (char *)&a;
    a = 512;
    x[0] = 1;
    x[1] = 2;
    printf("%d\n", a);
}

/* it always should be arr size here otherwise the arr size calculated from sizeof(arr) / sizeof(arr[0]); is machine dependent */
void loopWithoutSize(int arr[])
{
    int i;
    printf("Wrong size of table:\n%ld\t%ld\n", sizeof(arr), sizeof(arr[0]));
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    for (i = 0; i < arr_size; i++)
        printf("Iter: %d\n", arr[i]);
}

void changePointer(int *p)
{
    int q = 10;
    p = &q;
}

void changePointerValid(int **pptr)
{
    static int q = 10;
    *pptr = &q;
}

void inrementationWithPointers()
{
    int i;
    int *ptr = (int *)malloc(5 * sizeof(int));

    for (i = 0; i < 5; i++)
        *(ptr + i) = i;

    printf("%d \t", *ptr++);
    printf("T%d \t", *ptr);
    printf("%d \t", (*ptr)++);
    printf("T%d \t", *ptr);
    printf("%d \t", *++ptr);
    printf("T%d \t", *ptr);
    printf("%d \t", *++ptr);
    printf("T%d \t", *ptr);
    printf("%d \t", ++*ptr);
    printf("\n");
}

int main()
{
    struct student
    {
        int num;
    } t_var;
    printf("Struct student: %d\n", t_var.num);

    int x = ~1;
    int arr[5] = {1, 2, 3, 4, 5};
    int var = 23;
    int *ptr = &var;

    puts(__DATE__); // __DATE__ as a build in variabel
    printf("int:%d\tunsigned:%d\tshort:%d\tlong:%d\tfloat:%d\tdouble:%d\n", sizeof(int), sizeof(unsigned), sizeof(short), sizeof(long), sizeof(float), sizeof(double));
    printf("x=~1 = %d\n", x);
    pointerArrayAndArrayPointer();
    poinetrsOffsets();
    loopWithoutSize(arr);

    changePointer(ptr);
    printf("After pointer change func: %d\n", *ptr);
    ptr = &x;
    printf("After pointer change: %d\n", *ptr);
    changePointerValid(&ptr);
    printf("After valid pointer change: %d\n", *ptr);
    inrementationWithPointers();
    return 0;
}
