#include "../push_swap.h"

stacks_t combo_opt0(stacks_t main, int *chunks)
{
    moves_t *cmd;

    cmd = malloc(sizeof(moves_t) * 2 + 1);

    real_num1(&main, cmd[0], chunks);
    real_num1(&main, cmd[1], chunks);

    free(cmd);
    return (main);    
}

stacks_t combo_opt1(stacks_t main, int *chunks)
{
    moves_t *cmd;

    cmd = malloc(sizeof(moves_t) * 2 + 1);

    real_num1(&main, cmd[0], chunks);
    real_num2(&main, cmd[1], chunks);

    free(cmd);
    return (main);
}

stacks_t combo_opt2(stacks_t main, int *chunks)
{
    moves_t *cmd;

    cmd = malloc(sizeof(moves_t) * 2 + 1);
    
    real_num1(&main, cmd[0], chunks);
    real_num2(&main, cmd[1], chunks);

    free(cmd);
    return (main);
}

stacks_t combo_opt3(stacks_t main, int *chunks)
{
    moves_t *cmd;

    cmd = malloc(sizeof(moves_t) * 2 + 1);
    
    real_num2(&main, cmd[0], chunks);
    real_num2(&main, cmd[1], chunks);

    free(cmd);
    return (main);
}
