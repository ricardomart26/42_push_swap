#include "../push_swap.h"

stacks_t rrr_funct(stacks_t main, int opt)
{
    main = rra_funct(main, 0);
    main = rrb_funct(main, 0);
    if (opt)
        write(1, "rrr\n", 4);
    return (main);
}

stacks_t sa_funct(stacks_t main, int option)
{
    int temp;

    if (!main.stackA)
        perror("\n\tIN SA: main stack A esta vazio\n");
    temp = main.stackA[0];
    main.stackA[0] = main.stackA[1];
    main.stackA[1] = temp;
    if (option)
        write(1, "sa\n", 4);
    return (main);
}

stacks_t sb_funct(stacks_t main, int option)
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
        write(1, "sb\n", 4);
    return (main);
}

stacks_t ss_funct(stacks_t main)
{
    main = sa_funct(main, 0);
    main = sb_funct(main, 0);
    return (main);
}
