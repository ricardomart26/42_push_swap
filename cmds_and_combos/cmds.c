#include "../push_swap.h"

int    *organize_the_stack(int *stack, int size, int opt)
{
    int x;
    int size2;

    size2 = size - 1;
    x = 0;
    if (opt)
        stack = realloc(stack, sizeof(int) * size2 + 1);
    while (size2--)
    {
        stack[x] = stack[x + 1];
        x++;
    }
    stack[x] = 0;
    return (stack);
}

int    *push_to_p(int *stack, int *size, int number)
{
    int temp_size;
    int x;
    int temp;
    int temp2;

    x = 1;
    temp_size = *size;
    *size += 1;
    stack = realloc(stack, (*size * 4) + 1);
    temp = stack[0];
    stack[0] = number;
    while (temp_size--)
    {
        temp2 = stack[x];
        stack[x] = temp;
        temp = temp2;
        x++;
    }
    return (stack);
}

stacks_t pa_funct(stacks_t main, int opt)
{
    int number;

    number = main.stackB[0];
    if (!main.stackB)
        perror("\n\tIN PB: main stack A esta vazio\n");
    if (main.sizeA == 0)
    {
        main.stackA = malloc(sizeof(int) + 1);
        main.stackA[0] = number;
        main.stackB = organize_the_stack(main.stackB, main.sizeB, 0);
        main.sizeA++;
    }
    else
    {
        main.stackA = push_to_p(main.stackA, &main.sizeA, number);
        main.stackB = organize_the_stack(main.stackB, main.sizeB, 1);
    }
    main.sizeB--;
    if (opt)    
        write(1, "pa\n", 4);
    return (main);

}

stacks_t pb_funct(stacks_t main, int opt)
{
    int number;

    number = main.stackA[0];
    if (!main.stackA)
        perror("\n\tIN PB: main stack A esta vazio\n");
    if (main.sizeB == 0)
    {
        main.stackB = malloc(sizeof(int) + 1); // Posso fazer isto?
        main.stackB[0] = number;
        main.stackA = organize_the_stack(main.stackA, main.sizeA, 0);
        main.sizeB++;
    }
    else
    {
        main.stackB = push_to_p(main.stackB, &main.sizeB, number);
        main.stackA = organize_the_stack(main.stackA, main.sizeA, 1);
    }
    main.sizeA--;
    if (opt)
        write(1, "pb\n", 4);
    return (main);
}
