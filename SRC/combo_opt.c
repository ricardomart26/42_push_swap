#include "../push_swap.h"


stacks_t combo_opt0(stacks_t main, int *chunks)
{
    moves_t *cmd;

    // printf("\n\t(combo opt 0) Got to combo opt0\n");
    // print_stacks(main);
    // exit(0);
    cmd = malloc(sizeof(moves_t) + 1);
    if ((!closer_to_beginning2(main, chunks, main.sizeA, &cmd[0])))
        perror("\n\n\tCannot find first number in chunk\n"); // Encontrar primeiro numero dentro do stackA do inicio
    
    cmd = get_pos(main, cmd, 0);
    simulate_num1(&main, *cmd);

    // print_stacks(main);

    if ((!closer_to_beginning2(main, chunks, main.sizeA, &cmd[0])))
        perror("\n\n\tCannot find first number in chunk\n"); // Encontrar primeiro numero dentro do stackA do inicio
    cmd = get_pos(main, cmd, 0);

    simulate_num1(&main, *cmd);

    // printf("\n\t(combo_opt 0) Check stacks\n");
    // print_stacks(main);
    // sleep(3);
    return (main);    
}

stacks_t combo_opt1(stacks_t main, int *chunks)
{
    moves_t *cmd;

    printf("\n\tWHATTTTTTTTTTTT\n");
    cmd = malloc(sizeof(moves_t) * 2 + 1);

    if ((!closer_to_beginning2(main, chunks, main.sizeA, &cmd[0])))
        perror("\n\n\tCannot find first number in chunk\n"); // Encontrar primeiro numero dentro do stackA do inicio
    if ((!closer_to_end2(main, chunks, &cmd[1])))
        perror("\n\n\tCannot find first number in chunk\n"); // Encontrar primeiro numero dentro do stackA do inicio
    
    cmd = get_pos(main, cmd, 1);
    
    simulate_num1(&main, cmd[0]);
    simulate_num2(&main, cmd[1]);
    print_cmds(cmd, 0);
    sleep(2);
    // printf("\n\t(combo_opt 1) Check stacks\n");
    // print_stacks(main);
    // sleep(3);

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

    cmd = get_pos(main, cmd, 1);

    simulate_num2(&main, cmd[1]);
    simulate_num1(&main, cmd[0]);
    // printf("\n\t(combo_opt 2) Check stacks\n");
    // print_stacks(main);
    // sleep(3);
    return (main);
}

stacks_t combo_opt3(stacks_t main, int *chunks)
{
    moves_t *cmd;

    cmd = malloc(sizeof(moves_t) + 1);
    if ((!closer_to_end2(main, chunks, &cmd[0])))
        perror("\n\n\tCannot find first number in chunk\n"); // Encontrar primeiro numero dentro do stackA do inicio
    
    cmd = get_pos(main, cmd, 0);
    simulate_num2(&main, *cmd);

    if ((!closer_to_end2(main, chunks, &cmd[0])))
        perror("\n\n\tCannot find first number in chunk\n"); // Encontrar primeiro numero dentro do stackA do inicio

    cmd = get_pos(main, cmd, 0);
    simulate_num2(&main, *cmd);

    // printf("\n\t(combo_opt 3) Check stacks\n");
    // print_stacks(main);
    // sleep(3);
    return (main);
}
