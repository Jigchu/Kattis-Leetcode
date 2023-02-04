#include <math.h>
#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    // Gets number of blocks
    long blocks;
    if (!scanf("%li", &blocks))
    {
        return 1;
    }
    
    // Sets curr base size and curr level
    int base = 1;
    int height = 0;

    // Gets max height
    while (blocks > 0)
    {
        height++;
        blocks -= pow(base, 2);
        base += 2;
    }   
    
    if (blocks < 0)
    {
        height--;
    }

    // Returns max height
    printf("%i\n", height);

    return 0;
}