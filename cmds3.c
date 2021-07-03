#include "push_swap.h"

stacks_t rrr(stacks_t main)
{
    main = rra(main, 0);
    main = rrb(main, 0);
    write(1, "rrr ", 4);
    return (main);
}

stacks_t sa(stacks_t main, int option)
{
    int temp;

    if (!main.stackA)
        perror("\n\tIN SA: main stack A esta vazio\n");
    temp = main.stackA[0];
    main.stackA[0] = main.stackA[1];
    main.stackA[1] = temp;
    if (option)
        write(1, "sa ", 4);
    return (main);
}

stacks_t sb(stacks_t main, int option)
{
    int x;
    int temp;

    if (!main.stackB)
        perror("\n\tIN SB: main stack B esta vazio\n");

    x = 0;
    temp = main.stackB[x];
    main.stackB[x] = main.stackB[x + 1];
    main.stackB[x + 1] = temp;
    if (option)
        write(1, "sb ", 4);
    return (main);
}

stacks_t ss(stacks_t main)
{
    main = sa(main, 0);
    main = sb(main, 0);
    return (main);
}
