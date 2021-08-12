#include "../push_swap.h"

int is_valid(stacks_t main)
{
    int x;
    int i;

    x = 0;
    if (is_correct(main.A, main.sizeA))
        return (2);
    while (main.A[x])
    {
        i = x + 1;
        while (main.A[i])
        {
            if (main.A[x] == main.A[i])
                error_mes();
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
    while (i + 1 < size)
    {
        if (stack[i] < stack[i + 1])
            i++;
        else
            return (0);
    }
    return (1);
}

int is_correct_B(int *B, int size)
{
    int i;

    i = 0;
    while (size)
    {

        if (B[i] > B[i + 1])
            i++;
        else if (i < size)
            return (0);
        size--;
    }
    return (1);
}
