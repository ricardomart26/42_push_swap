#include "../push_swap.h"


int simulate_next_f(stacks_t temp, int *chunks, int moves)
{
    moves_t *cmd;
    stacks_t temp2;

    cmd = malloc(sizeof(moves_t) + 1);

    temp2 = pass_stacks_to_temp(temp);
    moves += simulate_num1(&temp2, *cmd, chunks);

    return (moves);
}

int simulate_next_s(stacks_t temp, int *chunks, int moves)
{
    moves_t *cmd;
    stacks_t temp2;

    cmd = malloc(sizeof(moves_t) + 1);

    temp2 = pass_stacks_to_temp(temp);
    moves += simulate_num2(&temp2, *cmd, chunks);

    return (moves);
}


