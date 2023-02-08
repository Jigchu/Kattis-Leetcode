#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    // Starter vars
    long long num1;
    long long num2;
    long long result;

    // Actual code
    while (scanf("%lld %lld", &num1, &num2) != EOF)
    {
        result = num1 - num2;

        // Return val
        printf("%lld\n", llabs(result));
    }

    // Ends succesfully
    return 0;
}
