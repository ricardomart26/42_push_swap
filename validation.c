#include "push_swap.h"

int is_valid(stacks_t main)
{
    int x;
    int i;

    x = 0;
    if (main.ac <= 3)
        perror("Error: No minimo 3 numeros e necessario\n");
    while (main.stackA[x])
    {
        i = x + 1;
        while (main.stackA[i])
        {
            // printf("\n\tx = %d && i = %d", main.stackA[x], main.stackA[i]);
            if (main.stackA[x] == main.stackA[i])
                return (0);
            i++;
        }
        x++;
    }
    return (1);
}


int ft_isntdigit(char c)
{
    if (c <= '9' && c >= '0')
        return (0);
    return (1);
}

int is_correct(int *stack, int size)
{
    int i;

    i = 0;
    while (size)
    {
        // printf("\n\tis correct stack A = %d && stack A + 1 %d", stack[i], stack[i + 1]);
        if (stack[i] < stack[i + 1])
            i++;
        else
            return (0);
        size--;
    }
    return (1);
}

int is_correct_stackB(int *stackB, int size)
{
    int i;

    i = 0;
    while (size)
    {
        printf("\n\tsize %d - stack A %d = %d && stack A %d %d", size, i, stackB[i], i + 1, stackB[i + 1]);
        // sleep(1);
        if (stackB[i] > stackB[i + 1])
            i++;
        else if (i < size)
            return (0);
        size--;
    }
    return (1);
}
