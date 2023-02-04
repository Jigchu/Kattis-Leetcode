#include <stdio.h>

int main(void)
{
    // Gets number of stones
    long stones;
    if (!scanf("%li", &stones))
    {
        return 1;
    }

    // Checks if even or odd and prints answer
    if (stones % 2 == 0)
    {
        printf("Bob\n");
    }
    else
    {
        printf("Alice\n");
    }
    
    return 0;
}