#include "push_swap.h"


stacks_t ra(stacks_t main, int option)
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
        write(1, "ra ", 4);
    return (main);
}

stacks_t rb(stacks_t main, int option)
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
        write(1, "rb ", 4);
    return (main);
}


stacks_t rr(stacks_t main)
{
    main = ra(main, 0);
    main = rb(main, 0);
    write(1, "rr ", 4);
    return (main);
}


stacks_t rra(stacks_t main, int option)
{
    int size;
    int last;

    last = main.stackA[main.sizeA - 1];
    size = main.sizeA;
    while (size--)
        main.stackA[size] = main.stackA[size - 1];
    main.stackA[0] = last;
    if (option)
        write(1, "rra ", 5);
    return (main);
}


stacks_t rrb(stacks_t main, int option)
{
    int size;
    int last;

    last = main.stackB[main.sizeB - 1];
    size = main.sizeB;
    while (size--)
        main.stackB[size] = main.stackB[size - 1];
    main.stackB[0] = last;
    if (option)
        write(1, "rrb ", 5);
    return (main);
}
