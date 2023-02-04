#include <stdio.h>

// Max amount of cats
#define MAX 200000

// A struct to hold cat data
typedef struct
{
    char *name;
    int infec_lvl;
} 
cat_info;

// An arr to hold cats in clinic
cat_info cat_arr[MAX];
long cat_count;

// Function prototypes
void arrived(cat_info cat);
void update(cat_info cat, int increase);
void treated(cat_info car);
void mergesort(int start, int end);
void merge(int start, int mid, int end);
void query(void);

int main(void)
{
    // Gest number of lines
    int lines;
    if (scanf("%i", &lines) == EOF)
    {
        return 1;
    }

    // Gets the instructions
    for (int i = 0; i < lines; i++)
    {

    }
}

void arrived(cat_info cat)
{

}
void update(cat_info cat, int increase)
{

}
void treated(cat_info car)
{

}

// Merge sort using recursion
void mergesort(int start, int end)
{
    // Break case
    if (start == end)
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
    // Initialise auxilery array
    cat_info aux[end + 1];

    // Initialise pointers
    int i = 0;
    int j = mid + 1;
    int k = 0;

    // Merges items until we reach the end of one list
    while (i <= mid && j <= end)
    {
        // Gets difference in infec_lvl for both cats
        int val1 = cat_arr[i].infec_lvl;
        int val2 = cat_arr[j].infec_lvl;

        // Checks for larger difference (prioritises earlier place in array if both vals are same) and places pair in aux in sorted manner
        if (val1 >= val2)
        {
            aux[k] = cat_arr[i];
            i++;
        }
        else if (val2 > val1)
        {
            aux[k] = cat_arr[j];
            j++;
        }

        // Increments k by one for next pair in aux
        k++;
    }

    // Once we reach end of one list, assume that the rest of other list is sorted and copy into aux
    for (; i <= mid; i++)
    {
        aux[k] = cat_arr[i];
        k++;
    }

    for (; j <= end; j++)
    {
        aux[k] = cat_arr[j];
        k++;
    }

    // Copies sorted vals in aux into cat_arr
    for (k = 0; k <= end; k++)
    {
     cat_arr[k] = aux[k];
    }

    // Ends function
    return;
}

void query(void)
{

}