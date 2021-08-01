#include "../push_swap.h"

stacks_t combo_opt0(stacks_t main, int *chunks)
{
    moves_t *cmd;

    cmd = malloc(sizeof(moves_t) + 1);
    if ((!closer_to_beginning2(main, chunks, main.sizeA, &cmd[0])))
        perror("\n\n\tCannot find first number in chunk\n"); // Encontrar primeiro numero dentro do stackA do inicio
    
    cmd[0] = get_cmds(main, cmd[0], main.sizeB);
    real_num1(&main, *cmd);

    if ((!closer_to_beginning2(main, chunks, main.sizeA, &cmd[0])))
        perror("\n\n\tCannot find first number in chunk\n"); // Encontrar primeiro numero dentro do stackA do inicio

    cmd[0] = get_cmds(main, cmd[0], main.sizeB);

    real_num1(&main, *cmd);
    return (main);    
}

stacks_t combo_opt1(stacks_t main, int *chunks)
{
    moves_t *cmd;

    cmd = malloc(sizeof(moves_t) * 2 + 1);

    if ((!closer_to_beginning2(main, chunks, main.sizeA, &cmd[0])))
        perror("\n\n\tCannot find first number in chunk\n"); // Encontrar primeiro numero dentro do stackA do inicio
    if ((!closer_to_end2(main, chunks, &cmd[1])))
        perror("\n\n\tCannot find first number in chunk\n"); // Encontrar primeiro numero dentro do stackA do inicio
    
    cmd[0] = get_cmds(main, cmd[0], main.sizeB);
    cmd[1] = get_cmds(main, cmd[1], main.sizeB);
    
    real_num1(&main, cmd[0]);
    real_num2(&main, cmd[1]);

    return (main);
}

stacks_t combo_opt2(stacks_t main, int *chunks)
{
    moves_t *cmd;

    cmd = malloc(sizeof(moves_t) * 2 + 1);
    if ((!closer_to_beginning2(main, chunks, main.sizeA, &cmd[0])))
        perror("\n\n\tCannot find first number in chunk\n"); // Encontrar primeiro numero dentro do stackA do inicio
    if ((!closer_to_end2(main, chunks, &cmd[1])))
        perror("\n\n\tCannot find first number in chunk\n"); // Encontrar primeiro numero dentro do stackA do inicio
    
    cmd[0] = get_cmds(main, cmd[0], main.sizeB);
    cmd[1] = get_cmds(main, cmd[1], main.sizeB);
    
    real_num1(&main, cmd[0]);
    real_num2(&main, cmd[1]);

    return (main);
}

stacks_t combo_opt3(stacks_t main, int *chunks)
{
    moves_t *cmd;

    cmd = malloc(sizeof(moves_t) + 1);
    if ((!closer_to_end2(main, chunks, &cmd[0])))
        perror("\n\n\tCannot find first number in chunk\n"); // Encontrar primeiro numero dentro do stackA do inicio
    
    cmd[0] = get_cmds(main, cmd[0], main.sizeB);
    real_num2(&main, *cmd);

    if ((!closer_to_end2(main, chunks, &cmd[0])))
        perror("\n\n\tCannot find first number in chunk\n"); // Encontrar primeiro numero dentro do stackA do inicio

    cmd[0] = get_cmds(main, cmd[0], main.sizeB);
    real_num2(&main, *cmd);

    return (main);
}
