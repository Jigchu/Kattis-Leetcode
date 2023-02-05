#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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
int bisearch(char *name);
void mergesort(int start, int end);
void merge(int start, int mid, int end);
void arrived(char *cat, int infec_lvl);
void update(char *cat, int increase);
void treated(char *cat);
void query(void);

int main(void)
{
    // Gets number of lines
    int lines;
    if (scanf("%i\n", &lines) == EOF)
    {
        return 1;
    }

    // Actual code execution
    for (int i = 0; i < lines; i++)
    {
        // Gets command
        char *command = malloc(sizeof(char) * 41);
        if (command == NULL)
        {
            return 2;
        }

        scanf("%[^\n]%*c", command);

        // Gets call and strlen
        int call = command[0] - '0';
        
        int len = strlen(command);

        switch (call)
        {
            case 0:
            {
                // Gets cat name
                int i = 2;

                while (isalpha(command[i + 1]))
                {
                    i++;
                }

                char name[i - 1];

                for (int j = 0; j <= i; j++)
                {
                    name[j] = command[j + 2];
                }

                // Gets infect level
                int infec_lvl;

                char *temp = malloc(sizeof(char) * len - (i + 2));

                i++;

                for (int j = 0; i < len; i++, j++)
                {
                    temp[j] = command[i];
                }

                infec_lvl = atoi(temp);

                free(temp);

                // Calls arrive functiona
                arrived(name, infec_lvl);

                break;
            }
            default:
                return 3;
                break;
        }
    }
}


// Implementation of binary search
int bisearch(char *name)
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

// Adds cat_info into cat_arr
void arrived(char *cat, int infec_lvl)
{

}

// Updates cat's infec_lvl
void update(char *cat, int increase)
{

}

// Removes cat_info into cat_arr
void treated(char *cat)
{

}

// Prints out cat with highest infec_lvl
void query(void)
{

}