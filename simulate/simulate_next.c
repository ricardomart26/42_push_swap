#include "../push_swap.h"


int simulate_next_f(stacks_t temp, int *chunks, int moves, int i)
{
    moves_t *cmd;
    stacks_t temp2;

    if (i == 0)
        printf("\n\t(simulate next f)Starting simualte next f with sim 1\n");
    if (i == 1)
        printf("\n\t(simulate next f)Starting simualte next f with sim 2\n");
    if (i == 2)
        printf("\n\t(simulate next f)Starting simualte next f with real 1\n");
    if (i == 3)
        printf("\n\t(simulate next f)Starting simualte next f with real 2\n");
    print_stacks(temp);
    cmd = malloc(sizeof(moves_t) + 1);

    temp2 = pass_stacks_to_temp(temp);
    moves += simulate_num1(&temp2, *cmd, chunks, 0);

    if (i == 0)
        printf("\n\t(simulate next f)Done simualte next f with sim 1\n");
    if (i == 1)
        printf("\n\t(simulate next f)Done simualte next f with sim 2\n");
    if (i == 2)
        printf("\n\t(simulate next f)Done simualte next f with real 1\n");
    if (i == 3)
        printf("\n\t(simulate next f)Done simualte next f with real 2\n");
    print_stacks(temp);
    return (moves);
}

int simulate_next_s(stacks_t temp, int *chunks, int moves, int i)
{
    moves_t *cmd;
    stacks_t temp2;

    if (i == 0)
        printf("\n\t(simulate next s)Starting simulate next s with sim 1\n");
    if (i == 1)
        printf("\n\t(simulate next s)Starting simulate next s with sim 2\n");
    if (i == 2)
        printf("\n\t(simulate next s)Starting simulate next s with real 1\n");
    if (i == 3)
        printf("\n\t(simulate next s)Starting simulate next s with real 2\n");
    print_stacks(temp);
    
    cmd = malloc(sizeof(moves_t) + 1);

    temp2 = pass_stacks_to_temp(temp);
    moves += simulate_num2(&temp2, *cmd, chunks, 0);

    if (i == 0)
        printf("\n\t(simulate next s)Done simualte next s with sim 1\n");
    if (i == 1)
        printf("\n\t(simulate next s)Done simualte next s with sim 2\n");
    if (i == 2)
        printf("\n\t(simulate next s)Done simualte next s with real 1\n");
    if (i == 3)
        printf("\n\t(simulate next s)Done simualte next s with real 2\n");
    print_stacks(temp);

    return (moves);
}


