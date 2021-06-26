#include "push_swap.h"

int find_lower(int *stackA, int lower)
{
    int x;
    int i;

    i = 0;
    x = 0;
    printf("\n\tlower before = %d", lower);

    while (stackA[x] != '\0')
    {
        if (stackA[x] <= lower)
        {
            x++;
            i++;
        }
        else if (stackA[i] < stackA[x + 1])
        {
            // printf("\n\tstack i = %d && stack x = %d", stackA[i], stackA[x]);
            x++;
        }
        else
            i = x;
    }
    printf("\n\tlower after = %d", stackA[i]);
    return(stackA[i]);
}

int find_lower_limit(int *stackA, int number, int bigger)
{
    int x;
    int i;

    i = 0;
    x = 0;
    while (stackA[x] != '\0')
    {
        if (stackA[x] < bigger || stackA[x] <= number)
            x++;
        else if (stackA[i] <= stackA[x])
            x++;
        else
            i++;
    }
    printf("\n\tlower = %d", stackA[i]);
    return(stackA[i]);
}


int array_cmp(int *arr, int number)
{
    while (*arr)
    {
        if (*arr == number)
            return (1);
        arr++;
    }
    return (0);
}

