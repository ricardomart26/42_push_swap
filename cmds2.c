#include "push_swap.h"


stacks_t ra(stacks_t main)
{
    int size;
    int x;

    x = 0;
    size = main.sizeA;
    while (size--)
    {
        main.stackA[x] = main.stackA[x + 1];
    }
    return (main);
}

stacks_t rb(stacks_t main)
{
    int size;
    int x;

    x = 0;
    size = main.sizeB;
    while (size--)
    {
        main.stackB[x] = main.stackB[x + 1];
    }
    return (main);
}


stacks_t rr(stacks_t main)
{
    
    return (main);
}


stacks_t rra(stacks_t main)
{
    
    return (main);
}


stacks_t rrb(stacks_t main)
{
    
    return (main);
}
