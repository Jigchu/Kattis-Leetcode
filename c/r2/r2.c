#include <stdio.h>

int main(void)
{
    // Gets r1 and r2
    int r1;
    int s;
    
    if (!scanf("%i %i", &r1, &s))
    {
        return 1;
    }

    // Gets r2
    int r2 = (2 * s) - r1;

    // Prints answer
    printf("%i", r2);

    return 0;
}