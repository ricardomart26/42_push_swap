#include "../push_swap.h"

stacks_t ra_funct(stacks_t main, int option)
{
    int size;
    int x;
    int temp;

    temp = main.stackA[0];
    x = 0;
    size = main.sizeA - 1;
    while (size--)
    {
        main.stackA[x] = main.stackA[x + 1];
        x++;
    }
    main.stackA[x] = temp;
    if (option)
        write(1, "ra \n", 5);
    return (main);
}

stacks_t rb_funct(stacks_t main, int option)
{
    int size;
    int x;
    int temp;

    temp = main.stackB[0];
    x = 0;
    size = main.sizeB - 1;
    while (size--)
    {
        main.stackB[x] = main.stackB[x + 1];
        x++;
    }
    main.stackB[x] = temp;
    if (option)
        write(1, "rb \n", 5);
    return (main);
}


stacks_t rr_funct(stacks_t main)
{
    main = ra_funct(main, 0);
    main = rb_funct(main, 0);
    write(1, "rr ", 4);
    return (main);
}


stacks_t rra_funct(stacks_t main, int option)
{
    int size;
    int last;

    last = main.stackA[main.sizeA - 1];
    size = main.sizeA;
    while (size--)
        main.stackA[size] = main.stackA[size - 1];
    main.stackA[0] = last;
    if (option)
        write(1, "rra \n", 6);
    return (main);
}

static int i = 0;

stacks_t rrb_funct(stacks_t main, int option)
{
    int size;
    int last;
    i++;
    last = main.stackB[main.sizeB - 1];
    size = main.sizeB;
    while (size--)
        main.stackB[size] = main.stackB[size - 1];
    main.stackB[0] = last;
    if (i == 20)
        exit(0);
    if (option)
        write(1, "rrb \n", 6);
    return (main);
}
