#include "push_swap.h"

int    *organize_the_stack(int *stack, int size)
{
    int x;
    int size2;

    // printf("THIS NUMBER IN SENDO TO STACK A IS %d", number);
    size2 = size - 1;
    x = 0;
    stack = realloc(stack, sizeof(int) * size2 + 1);
    printf("stack x = %d\n", stack[x]);
    printf("stack x = %d\n", stack[x + 1]);
    // printf("stack x = %d", *stack[x + 2]);
    // printf("stack x = %d", *stack[x + 3]);

    printf("\tTHIS SIZE IN SENDO TO STACK A IS %d\n", size2);
    while (size2--)
    {
        printf("stack x = %d", stack[x]);
        stack[x] = stack[x + 1];
        x++;
    }
    stack[x] = 0;
    return (stack);
    printf("\tFINISH IN SEND TO STACK\n");

}

int *not_first_in_p(int *stack1, int **stack2, int *size, int *size2)
{
    int temp;
    int x;

    temp = *stack2[0];
    *stack2[0] = stack1[0];
    x = 1;
    printf("\t\ntemp = %d", temp);
    printf("\t\nsize2 = %d", *size2);
    while (*size2)
    {
            // printf("\n\tstackA[x] = %d && stackA[x+1] = %d", stackB[x], stackB[x + 1]);
            *stack2[x] = temp;
            if (*size2 == 1)
                break;
            temp = *stack2[x + 1];
            x++;
            (*size2)--;
    }
    stack1 = organize_the_stack(stack1, *size);
    (*size2)++;
    (*size)--;
    return (stack1);
}

stacks_t pa(stacks_t main)
{
    if (main.sizeA == 0)
    {
        main.stackA = malloc(sizeof(int) + 1);
        main.stackA[0] = main.stackB[0];
        main.stackB = organize_the_stack(main.stackB, main.sizeB);
        main.sizeB--;
        main.sizeA++;
        return (main);
    }
    else
    {
        main.stackA = realloc(main.stackA, main.sizeA * 4 + 4);
        main.stackB = not_first_in_p(main.stackB, &main.stackA, &main.sizeB - 1, &main.sizeA);
        return (main);
    }
}

stacks_t pb(stacks_t main)
{

    if (!main.stackA)
        perror("\n\tIN PB: main stack A esta vazio\n");
    printf("\n\tsizeB = %d", main.sizeB);
    if (main.sizeB == 0)
    {
        main.stackB = malloc(sizeof(int) + 1); // Posso fazer isto?
        main.stackB[0] = main.stackA[0];
        main.stackA = organize_the_stack(main.stackA, main.sizeA);
        main.sizeB++;
        main.sizeA--;
        return (main);
    }
    else
    {
        // printf("\n\tsizeB = %d", main.sizeB);
        main.stackB = realloc(main.stackB, (main.sizeB * 4) + 5);
        main.stackA = not_first_in_p(main.stackA, &main.stackB, &main.sizeA - 1, &main.sizeB);
        return (main);
    }
}


stacks_t sa(stacks_t main)
{
    int x;
    int temp;

    if (!main.stackA)
        perror("\n\tIN SA: main stack A esta vazio\n");

    x = 0;
    temp = main.stackA[x];
    main.stackA[x] = main.stackA[x + 1];
    main.stackA[x + 1] = temp;
    return (main);
}


stacks_t sb(stacks_t main)
{
    int x;
    int temp;

    if (!main.stackB)
        perror("\n\tIN SB: main stack B esta vazio\n");

    x = 0;
    temp = main.stackB[x];
    main.stackB[x] = main.stackB[x + 1];
    main.stackB[x + 1] = temp;
    return (main);
}


stacks_t ss(stacks_t main)
{
    main = sa(main);
    main = sb(main);
    return (main);
}
