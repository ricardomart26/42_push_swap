#include "../push_swap.h"


int real_num2(stacks_t *temp, moves_t cmd, int *chunk)
{
    if ((!closer_to_end2(*temp, chunk, &cmd)))
        perror("\n\n\tCannot find first number in chunk\n"); // Encontrar primeiro numero dentro do stackA do inicio
    
    cmd = get_cmds(*temp, cmd, temp->sizeB);
    
    cmd.total = num2(&temp, cmd);
    return (cmd.total);
}

int real_num1(stacks_t *temp, moves_t cmd, int *chunk)
{
    if ((!closer_to_beginning2(*temp, chunk, temp->sizeA, &cmd)))
        perror("\n\n\tCannot find first number in chunk\n"); // Encontrar primeiro numero dentro do stackA do inicio

    cmd = get_cmds(*temp, cmd, temp->sizeB);

    cmd.total = num1(&temp, cmd);
    return (cmd.total);
}

stacks_t    do_opt(stacks_t main, int *chunks, int option)
{
    moves_t cmd;

    printf("\n\t(do opt) Got here option %d\n", option);
    if (option == 0)
        main = combo_opt0(main, chunks);
    else if (option == 1)
        main = combo_opt1(main, chunks);
    else if (option == 2)
        main = combo_opt2(main, chunks);
    else if (option == 3)
        main = combo_opt3(main, chunks);
    else if (option == 4)
        simulate_num1(&main, cmd, chunks, 1);
    else if (option == 5)
        simulate_num2(&main, cmd, chunks, 1);

    return (main);
}