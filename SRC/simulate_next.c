#include "../push_swap.h"


int simulate_next_f(stacks_t temp, int *chunks, int moves)
{
    moves_t cmd[2];
    stacks_t temp2;
    
    // cmd[0].rb = 0;
    // cmd[0].rrb = 0;
    // cmd[0].rrr = 0;
    // cmd[0].ra = 0;
    // cmd[0].rra = 0;
    // cmd[0].rr = 0;
    // cmd[0].total = 0;
    // printf("\n\t SEE THIS ONE\n");
    // print_cmds(cmd, 0);

    // printf("\n\t(simulate next f) How many moves until here? %d\n", moves);

    if ((!closer_to_beginning2(temp, chunks, temp.sizeA, &cmd[0])))
        perror("\n\n\tCannot find first number in chunk\n"); // Encontrar primeiro numero dentro do stackA do inicio

    cmd[0].pos_stackb = where_to_putnbr2(cmd[0].num, temp.stackB, temp.sizeB);
    // print_cmds(cmd, 0);
    
    temp2 = pass_stacks_to_temp(temp);
    moves += simulate_num1(&temp2, &cmd[0]);

    // print_cmds(cmd, 0);
    return (moves);
}


int simulate_next_s(stacks_t temp, int *chunks, int moves)
{
    moves_t cmd[2];
    stacks_t temp2;


    // printf("\n\t(simulate next s) How many moves until here? %d\n", moves);
    if ((!closer_to_end2(temp, chunks, &cmd[1])))
    	perror("\n\n\tCannot find chunk number in stackA\n"); // Encontrar primeiro numero dentro do stackA do final

    cmd[1].pos_stackb = where_to_putnbr2(cmd[1].num, temp.stackB, temp.sizeB);
    temp2 = pass_stacks_to_temp(temp);
    
    // printf("\n\tCHECKKKKK THIS 3\n");
    // print_stacks(temp2);
    moves += simulate_num2(&temp2, &cmd[1]);
    printf("\n\t(simulate next s) stack next s -> moves %d to push num %d to B\n", moves, cmd[1].num);
    print_stacks(temp);
    // print_cmds(cmd, 1);
    // printf("\n\t(simulate next s) Finished sim next s -> moves %d to num %d\n", moves, cmd[1].num);

    return (moves);
}


