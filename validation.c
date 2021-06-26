#include "push_swap.h"


int is_valid(stacks_t main)
{
    int x;
    int i;

    x = 0;

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
