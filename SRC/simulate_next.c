#include "../push_swap.h"


int simulate_next_f(stacks_t temp, int *chunks, int moves)
{
    moves_t cmd[2];
    stacks_t temp2;
    
    if ((!closer_to_beginning2(temp, chunks, temp.sizeA, &cmd[0])))
        perror("\n\n\tCannot find first number in chunk\n"); // Encontrar primeiro numero dentro do stackA do inicio

    cmd[0].pos_stackb = where_to_putnbr2(cmd[0].num, temp.stackB, temp.sizeB);
    temp2 = pass_stacks_to_temp(temp);
    moves += simulate_num1(&temp2, cmd[0]);
    print_stacks(temp2);

    return (moves);
}


int simulate_next_s(stacks_t temp, int *chunks, int moves)
{
    moves_t cmd[2];
    stacks_t temp2;

    if ((!closer_to_end2(temp, chunks, &cmd[1])))
    	perror("\n\n\tCannot find chunk number in stackA\n"); // Encontrar primeiro numero dentro do stackA do final

    cmd[1].pos_stackb = where_to_putnbr2(cmd[1].num, temp.stackB, temp.sizeB);
    temp2 = pass_stacks_to_temp(temp);
    printf("\n\tCHECK THIS CMD NUM %d\n", cmd[1].num);
    moves += simulate_num2(&temp2, cmd[1]);
    printf("\n\t(simulate next s) stack next s -> moves %d to push num %d to B\n", moves, cmd[1].num);
    print_stacks(temp2);

    return (moves);
}


