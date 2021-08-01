#include "../push_swap.h"


int simulate_next_f(stacks_t temp, int *chunks, int moves)
{
    moves_t *cmd;
    stacks_t temp2;

    cmd = malloc(sizeof(moves_t) + 1);
    
    if ((!closer_to_beginning2(temp, chunks, temp.sizeA, *(&cmd))))
        perror("\n\n\tCannot find first number in chunk\n"); // Encontrar primeiro numero dentro do stackA do inicio

    cmd[0] = get_cmds(temp, cmd[0], temp.sizeB);

    // printf("\n\tCHECK THIS CMD NUM %d and place %d\n", cmd.num, cmd.pos_stackb);
    temp2 = pass_stacks_to_temp(temp);
    moves += simulate_num1(&temp2, *cmd);
    // print_stacks(temp2);

    return (moves);
}

int simulate_next_s(stacks_t temp, int *chunks, int moves)
{
    moves_t *cmd;
    stacks_t temp2;

    cmd = malloc(sizeof(moves_t) + 1);
    if ((!closer_to_end2(temp, chunks, *(&cmd))))
    	perror("\n\n\tCannot find chunk number in stackA\n"); // Encontrar primeiro numero dentro do stackA do final

    cmd[0] = get_cmds(temp, cmd[0], temp.sizeB);
    temp2 = pass_stacks_to_temp(temp);
    // printf("\n\tCHECK THIS CMD NUM %d and place %d\n", cmd.num, cmd.pos_stackb);
    // print_stacks(temp2);
    moves += simulate_num2(&temp2, *cmd);
    // printf("\n\t(simulate next s) stack next s -> moves %d to push num %d to B\n", moves, cmd.num);

    return (moves);
}


