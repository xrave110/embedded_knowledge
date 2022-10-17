
#include "./safe_math.h";

int addWithSaturation(int a, int b)
{
    long long sum = (long long)a + (long long)b;
    return ((sum >= (long long)MAX_FOR_INT) ? MAX_FOR_INT : (sum <= (long long)MIN_FOR_INT) ? MIN_FOR_INT
                                                                                            : (int)sum);
}