#include <stdlib.h>
#include <stdio.h>

void keywordsOrderWithPointers()
{
    int var1 = 12;
    int var2 = 14;
    int var3 = 26;
    printf("%d\t%d\n", &var1, &var2);
    const int *ptr = 1167482112;
    printf("%d \t\n", ptr);
    const int *ptr1 = &var1;
    int const *ptr2 = &var3;
    int *const ptr3 = &var1;
    // const *int ptr4 = &var1; // illegal declaration
    const int *const ptr5 = &var3;
    int const *const ptr6 = &var1;
    //(*ptr1)++; // cannot do that !
    *ptr1++; // can do that !
    printf("const int *:\n%d\t%d\n", *ptr1, ptr1);
    ptr1 = &var3;
    printf("%d\t%d\n", *ptr1, ptr1);

    //(*ptr2)++;    // cannot do that !
    *ptr2++; // can do that !
    printf("int const*:\n%d\t%d\n", *ptr2, ptr2);
    ptr2 = &var1;
    printf("%d\t%d\n", *ptr2, ptr2);

    (*ptr3)++; // can do that
    printf("int* const:\n%d\t%d\n", *ptr3, ptr3);
    // *ptr3++;        // cannot do that !
    // ptr3 = &var2;   // cannot do that !

    // (*ptr5)++; //cannot do that !
    // *ptr5++;      // cannot do that !
    // ptr5 = &var3; // cannot do that !

    // (*ptr6)++;    // cannot do that !
    // *ptr6++;      // cannot do that !
    // ptr6 = &var3; // cannot do that !
}

int main()
{
    keywordsOrderWithPointers();
    return 0;
}