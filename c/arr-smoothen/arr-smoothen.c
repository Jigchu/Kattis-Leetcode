#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX 200000

// Struct to store each value's occurence
typedef struct
{
    long long num;
    int occurrence;
}
occ;


// Start vars
long long rand_arr[MAX];
occ occurence[MAX];
int occ_count;
int int_count;
int rm_count;

// Some function prototypes
int bisearch(long long num);
void mergesort(int start, int end);
void merge(int start, int mid, int end);
void mergesort2(int start, int end);
void merge2(int start, int mid, int end);

int main(void)
{
    while (true)
    {
        occ_count = 0;

        // Gets input
        scanf("%i %i", &int_count, &rm_count);
        
        for (int i = 0; i < int_count; i++)
        {
            scanf("%lli", rand_arr + i);
        }

        // Gets occurrence of each num
        for (int i = 0; i < int_count; i++)
        {
            // Checks if there is an entry for num and if there is not make one
            int index = bisearch(rand_arr[i]);

            if (index < 0)
            {
                occurence[occ_count].num = rand_arr[i];
                occurence[occ_count].occurrence = 1;
                occ_count++;
                // Sorts by nums
                mergesort2(0, occ_count - 1);
            }
            else
            {
                occurence[index].occurrence++;
            }
        }

        // Minmaxes occurance val
        while (rm_count > 0)
        {
            occurence[0].occurrence--;
            rm_count--;
            mergesort(0, occ_count - 1);
        }

        // Maintain sorted state
        mergesort(0, occ_count - 1);

        // Returns the highest occurance num
        printf("%lli\n", occurence[0].occurrence);
        
        // Resets everything
        for (int i = 0; i < MAX; i++)
        {
            occurence[i].num = '\0';
            occurence[i].occurrence = 0;
            rand_arr[i] = 0;
            occ_count = 0;
        }
    }

    return 0;
}

// Implementation of binary search
int bisearch(long long num)
{
    // Start vars
    int start = 0;
    int end = occ_count - 1;
    int repeat = 0;
    int last_mid;

    // Start search
    while (true)
    {
        int mid = (start + end) / 2;
        long long result = occurence[mid].num - num;

        // Checks for match
        if (!result)
        {
            // Returns index
            return mid;
        }
        else if (result < 0)
        {
            // Checks left halve
            end = mid - 1;
        }
        else if (result > 0)
        {
            // Checks right halve
            start = mid + 1;
        }

        // Checks if the num does not exist
        if (last_mid == mid)
        {
            if (repeat > 1)
            {
                // Returns negative index
                return -1;
            }
            else
            {
                repeat++;
            }
            
        }
        else
        {
            repeat = 0;
        }

        last_mid = mid;
    }
}

// Merge sort using recursion
void mergesort(int start, int end)
{
    // Break case
    if (start == end || end < 0)
    {
        return;
    }

    // Finds middle of list
    int mid = (start + end) / 2;

    mergesort(0, mid);                  // Sorts left part
    mergesort(mid + 1, end);            // Sorts right part

    // Merges left and right part
    merge(start, mid, end);

    // Ends function
    return;
}

// Function to merge items in mergesort
void merge(int start, int mid, int end)
{
    // Initialise auxiliary array
    occ aux[end + 1];

    // Initialise pointers
    int i = 0;
    int j = mid + 1;
    int k = 0;

    // Merges items until we reach the end of one list
    while (i <= mid && j <= end)
    {
        // Gets difference in occurence for each num
        int val1 = occurence[i].occurrence;
        int val2 = occurence[j].occurrence;

        // Checks for larger difference (prioritises earlier place in array if both vals are same) and places pair in aux in sorted manner
        if (val1 >= val2)
        {
            aux[k] = occurence[i];
            i++;
        }
        else if (val2 > val1)
        {
            aux[k] = occurence[j];
            j++;
        }

        // Increments k by one for next pair in aux
        k++;
    }

    // Once we reach end of one list, assume that the rest of other list is sorted and copy into aux
    for (; i <= mid; i++)
    {
        aux[k] = occurence[i];
        k++;
    }

    for (; j <= end; j++)
    {
        aux[k] = occurence[j];
        k++;
    }

    // Copies sorted vals in aux into occurence
    for (k = 0; k <= end; k++)
    {
        occurence[k] = aux[k];
    }

    // Ends function
    return;
}

// Merge sort using recursion
void mergesort2(int start, int end)
{
    // Break case
    if (start == end || end < 0)
    {
        return;
    }

    // Finds middle of list
    int mid = (start + end) / 2;

    mergesort2(0, mid);                  // Sorts left part
    mergesort2(mid + 1, end);            // Sorts right part

    // Merges left and right part
    merge2(start, mid, end);

    // Ends function
    return;
}

// Function to merge items in mergesort
void merge2(int start, int mid, int end)
{
    // Initialise auxiliary array
    occ aux[end + 1];

    // Initialise pointers
    int i = 0;
    int j = mid + 1;
    int k = 0;

    // Merges items until we reach the end of one list
    while (i <= mid && j <= end)
    {
        // Gets difference in occurence for each num
        long long val1 = occurence[i].num;
        long long val2 = occurence[j].num;

        // Checks for larger difference (prioritises earlier place in array if both vals are same) and places pair in aux in sorted manner
        if (val1 >= val2)
        {
            aux[k] = occurence[i];
            i++;
        }
        else if (val2 > val1)
        {
            aux[k] = occurence[j];
            j++;
        }

        // Increments k by one for next pair in aux
        k++;
    }

    // Once we reach end of one list, assume that the rest of other list is sorted and copy into aux
    for (; i <= mid; i++)
    {
        aux[k] = occurence[i];
        k++;
    }

    for (; j <= end; j++)
    {
        aux[k] = occurence[j];
        k++;
    }

    // Copies sorted vals in aux into occurence
    for (k = 0; k <= end; k++)
    {
        occurence[k] = aux[k];
    }

    // Ends function
    return;
}