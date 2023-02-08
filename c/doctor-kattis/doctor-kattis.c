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
void mergealpha(int start, int end);
void amerge(int start, int mid, int end);
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
        char *command = malloc(sizeof(char) * 33);
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

                char *name = malloc(sizeof(char) * i);

                for (int j = 2; j <= i; j++)
                {
                    name[j - 2] = command[j];
                }
                
                name[i - 1] = '\0';

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

                // Calls arrive function
                arrived(name, infec_lvl);
                
                break;
            }
            case 1:
            {
                // Gets cat name
                int i = 2;

                while (isalpha(command[i + 1]))
                {
                    i++;
                }

                char *temp_name = malloc(sizeof(char) * i);

                for (int j = 2; j <= i; j++)
                {
                    temp_name[j - 2] = command[j];
                }
                
                temp_name[i - 1] = '\0';

                // Gets infect level
                int plus_infec;

                char *temp = malloc(sizeof(char) * len - (i + 2));

                i++;

                for (int j = 0; i < len; i++, j++)
                {
                    temp[j] = command[i];
                }

                plus_infec = atoi(temp);

                free(temp);

                // Calls update function
                update(temp_name, plus_infec);

                free(temp_name);

                break;
            }
            case 2:
            {
                // Gets cat name
                int i = 2;

                while (isalpha(command[i + 1]))
                {
                    i++;
                }

                char *temp_name = malloc(sizeof(char) * i);

                for (int j = 2; j <= i; j++)
                {
                    temp_name[j - 2] = command[j];
                }
                
                temp_name[i - 1] = '\0';

                // Calls treated
                treated(temp_name);

                free(temp_name);
                
                break;
            }
            default:
            {
                return 3;
                break;
            }
        }
    }
}


// Implementation of binary search
int bisearch(char *name)
{
    // Start vars
    int start = 0;
    int end = cat_count - 1;
    int repeat = 0;

    // Sorts cat_info alphabetically
    mergealpha(0, cat_count - 1);

    // Start search
    while (true)
    {
        int mid = (start + end) / 2;
        int result = strcmp(cat_arr[mid].name, name);

        // Checks for match
        if (!result)
        {
            // Reverts to numerical order
            mergesort(0, cat_count - 1);

            // Returns index
            return mid;
        }
        else if (result > 0)
        {
            // Checks left halve
            end = mid - 1;
        }
        else if (result < 0)
        {
            // Checks right halve
            start = mid + 1;
        }

        // Checks if the name does not exist
        if (start == mid || end == mid)
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
    }
}

// Merge sort using recursion to sort alphabetically
void mergealpha(int start, int end)
{
    // Break case
    if (start == end)
    {
        return;
    }

    // Finds middle of list
    int mid = (start + end) / 2;

    mergealpha(0, mid);                  // Sorts left part
    mergealpha(mid + 1, end);            // Sorts right part

    // Merges left and right part
    amerge(start, mid, end);

    // Ends function
    return;
}

// Function to merge items in mergealpha
void amerge(int start, int mid, int end)
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
        // Gets difference in name for both cats
        char *val1 = cat_arr[i].name;
        char *val2 = cat_arr[j].name;

        int result = strcmp(val1, val2);

        // Checks for larger difference (prioritises earlier place in array if both vals are same) and places pair in aux in sorted manner
        if (result >= 0)
        {
            aux[k] = cat_arr[i];
            i++;
        }
        else if (result < 0)
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
    // Initialise auxiliary array
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
    // Adds cat to array
    cat_arr[cat_count].name = cat;
    cat_arr[cat_count].infec_lvl = infec_lvl;

    // Sorts array to maintained a sorted array
    mergesort(0, cat_count);

    cat_count++;

    // Ends function
    return;
}

// Updates cat's infec_lvl
void update(char *cat, int increase)
{
    // Gets index of car
    int index = bisearch(cat);

    // Error handling for bisearch
    if (index < 0)
    {
        printf("Invalid name entered");
        return;
    }

    // Updates infect level
    cat_arr[index].infec_lvl += increase;

    // Maintains sorted array
    mergesort(0, cat_count - 1);

    // Ends function
    return;
}

// Removes cat_info into cat_arr
void treated(char *cat)
{
    // Removes cat from list
    int index = bisearch(cat);
    free(cat_arr[index].name);

    for (int i = index; i < cat_count; i++)
    {
        cat_arr[i] = cat_arr[i + 1];
    }

    // Clears info about cat that left
    cat_arr[cat_count - 1].name = '\0';
    cat_arr[cat_count - 1].infec_lvl = 0;
    cat_count--;

    // Ends function
    return;
}

// Prints out cat with highest infec_lvl
void query(void)
{

}