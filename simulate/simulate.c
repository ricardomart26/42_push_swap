#include "../push_swap.h"

int simulate_num2(stacks_t *temp, int *chunks, int opt)
{
    moves_t cmd;

    init_cmd(&cmd);
    closer_to_end2(*temp, chunks, &cmd);
    cmd = get_cmds(*temp, cmd, temp->sizeB);
    if (opt)
        cmd.total = num2(&temp, cmd);
    else
        cmd.total = num2_fake(&temp, cmd);
    return (cmd.total);
}

int simulate_num1(stacks_t *temp, int *chunks, int opt)
{
    moves_t cmd;

    init_cmd(&cmd);
    closer_to_beginning2(*temp, chunks, temp->sizeA, &cmd);
    cmd = get_cmds(*temp, cmd, temp->sizeB);
    if (opt)
        cmd.total = num1(&temp, cmd);
    else
        cmd.total = num1_fake(&temp, cmd);
    return (cmd.total);
}
