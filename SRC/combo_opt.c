#include "../push_swap.h"


stacks_t combo_opt0(stacks_t main, int *chunks)
{
    moves_t cmd;

    if ((!closer_to_beginning2(main, chunks, main.sizeA, &cmd)))
        perror("\n\n\tCannot find first number in chunk\n"); // Encontrar primeiro numero dentro do stackA do inicio
    
    simulate_num1(&main, cmd);

    if ((!closer_to_beginning2(main, chunks, main.sizeA, &cmd)))
        perror("\n\n\tCannot find first number in chunk\n"); // Encontrar primeiro numero dentro do stackA do inicio

    simulate_num1(&main, cmd);

    printf("\n\t(combo_opt 0) Check stacks\n");
    print_stacks(main);
    sleep(3);
    return (main);    
}

stacks_t combo_opt1(stacks_t main, int *chunks)
{
    moves_t cmd;

    if ((!closer_to_beginning2(main, chunks, main.sizeA, &cmd)))
        perror("\n\n\tCannot find first number in chunk\n"); // Encontrar primeiro numero dentro do stackA do inicio
    
    simulate_num1(&main, cmd);

    if ((!closer_to_end2(main, chunks, &cmd)))
        perror("\n\n\tCannot find first number in chunk\n"); // Encontrar primeiro numero dentro do stackA do inicio

    simulate_num2(&main, cmd);

    printf("\n\t(combo_opt 1) Check stacks\n");
    print_stacks(main);
    sleep(3);

    return (main);
}

stacks_t combo_opt2(stacks_t main, int *chunks)
{
    moves_t cmd;

    if ((!closer_to_end2(main, chunks, &cmd)))
        perror("\n\n\tCannot find first number in chunk\n"); // Encontrar primeiro numero dentro do stackA do inicio
    
    simulate_num2(&main, cmd);

    if ((!closer_to_beginning2(main, chunks, main.sizeA, &cmd)))
        perror("\n\n\tCannot find first number in chunk\n"); // Encontrar primeiro numero dentro do stackA do inicio

    simulate_num1(&main, cmd);

    printf("\n\t(combo_opt 0) Check stacks\n");
    print_stacks(main);
    sleep(3);
    return (main);
}

stacks_t combo_opt3(stacks_t main, int *chunks)
{
    moves_t cmd;

    if ((!closer_to_end2(main, chunks, &cmd)))
        perror("\n\n\tCannot find first number in chunk\n"); // Encontrar primeiro numero dentro do stackA do inicio
    
    simulate_num2(&main, cmd);

    if ((!closer_to_end2(main, chunks, &cmd)))
        perror("\n\n\tCannot find first number in chunk\n"); // Encontrar primeiro numero dentro do stackA do inicio

    simulate_num2(&main, cmd);

    printf("\n\t(combo_opt 0) Check stacks\n");
    print_stacks(main);
    sleep(3);
    return (main);
}

stacks_t combo_opt4(stacks_t main, int *chunks)
{
    moves_t cmd;

    if ((!closer_to_beginning2(main, chunks, main.sizeA, &cmd)))
        perror("\n\n\tCannot find first number in chunk\n"); // Encontrar primeiro numero dentro do stackA do inicio
    
    simulate_num1(&main, cmd);

    if ((!closer_to_beginning2(main, chunks, main.sizeA, &cmd)))
        perror("\n\n\tCannot find first number in chunk\n"); // Encontrar primeiro numero dentro do stackA do inicio

    simulate_num1(&main, cmd);

    printf("\n\t(combo_opt 0) Check stacks\n");
    print_stacks(main);
    sleep(3);
    return (main);
}

stacks_t combo_opt5(stacks_t main, int *chunks)
{
    moves_t cmd;

    if ((!closer_to_beginning2(main, chunks, main.sizeA, &cmd)))
        perror("\n\n\tCannot find first number in chunk\n"); // Encontrar primeiro numero dentro do stackA do inicio
    
    simulate_num1(&main, cmd);

    if ((!closer_to_beginning2(main, chunks, main.sizeA, &cmd)))
        perror("\n\n\tCannot find first number in chunk\n"); // Encontrar primeiro numero dentro do stackA do inicio

    simulate_num1(&main, cmd);

    printf("\n\t(combo_opt 0) Check stacks\n");
    print_stacks(main);
    sleep(3);
    return (main);
}


stacks_t combo_opt6(stacks_t main, int *chunks)
{
    moves_t cmd;

    if ((!closer_to_beginning2(main, chunks, main.sizeA, &cmd)))
        perror("\n\n\tCannot find first number in chunk\n"); // Encontrar primeiro numero dentro do stackA do inicio
    
    simulate_num1(&main, cmd);

    if ((!closer_to_beginning2(main, chunks, main.sizeA, &cmd)))
        perror("\n\n\tCannot find first number in chunk\n"); // Encontrar primeiro numero dentro do stackA do inicio

    simulate_num1(&main, cmd);

    printf("\n\t(combo_opt 0) Check stacks\n");
    print_stacks(main);
    sleep(3);
    return (main);
}