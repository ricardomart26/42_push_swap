#include "../push_swap.h"

//	printf("\n\t(sim_1_1)\n");


// int	simulate_next_two(stacks_t temp, int *chunks, int moves)
// {
//     moves_t *cmd;
	

// 	cmd = malloc(sizeof(moves_t) + 1);

// 	if ((!closer_to_beginning2(temp, chunks, temp.sizeA, *(&cmd))))
//         perror("\n\n\tCannot find first number in chunk\n"); // Encontrar primeiro numero dentro do stackA do inicio
    
// 	if ((!closer_to_end2(temp, chunks, *(&cmd))))
//     	perror("\n\n\tCannot find chunk number in stackA\n");

// }



int check_two_opt(stacks_t temp, int *chunks)
{
    moves_t *cmd;
    int movesss;
    int mv[2];

    cmd = malloc(sizeof(moves_t) * 2  + 1);
    movesss = 0;

    temp = pass_stacks_to_temp(temp);
    
	if ((!closer_to_beginning2(temp, chunks, temp.sizeA, &cmd[0])))
        perror("\n\n\tCannot find first number in chunk\n"); // Encontrar primeiro numero dentro do stackA do inicio
    
	if ((!closer_to_end2(temp, chunks, &cmd[1])))
    	perror("\n\n\tCannot find chunk number in stackA\n"); // Encontrar primeiro numero dentro do stackA do final    
    
	
	cmd[0].pos_stackb = where_to_putnbr2(cmd[0].num, temp.stackB, temp.sizeB);
    cmd[1].pos_stackb = where_to_putnbr2(cmd[1].num, temp.stackB, temp.sizeB);
    
    mv[0] = simulate_next_f(temp, chunks, movesss);
    // printf("\n\t(check two opt/simnf0) Finished simulating the first one of the first %d\n", mv[0]);

    mv[1] = simulate_next_s(temp, chunks, movesss);
    // printf("\n\t(check two opt/simnfs1) Finished simulating the second one of the first %d\n", mv[1]);

	if (mv[1] >= mv[0])
		return (mv[1]);
	else
		return (mv[0]);
}


int sim_1_1(stacks_t temp, int *chunks)
{
	int moves;
    moves_t *cmd;

	// printf("\n\t******************\n");
	// printf("\n\t**** SIM 1 1 ***\n");
	// printf("\n\t******************\n");


	// printf("\n\t(sim_1_1) SEE HERE moves\n");
	// print_stacks(temp);
	// sleep(5);

	cmd = malloc(sizeof(moves_t) + 1);
	moves = 0;
	if ((!closer_to_beginning2(temp, chunks, temp.sizeA, *(&cmd))))
        perror("\n\n\tCannot find first number in chunk\n"); // Encontrar primeiro numero dentro do stackA do inicio

	// printf("\n\t(sim_1_1) Got here?\n");
    cmd->pos_stackb = where_to_putnbr2(cmd->num, temp.stackB, temp.sizeB);

	moves = simulate_num1(&temp, cmd[0]);
	if ((!closer_to_beginning2(temp, chunks, temp.sizeA, *(&cmd))))
        perror("\n\n\tCannot find first number in chunk\n");
	moves += simulate_num1(&temp, cmd[0]);
	// printf("\n\t(sim_1_1) SEE HERE moves %d\n", moves);

	// print_stacks(temp);
	// sleep(5);
	moves += check_two_opt(temp, chunks);
	// printf("\n\t(sim 1 1) SEE THIS moves %d\n", moves);
	// print_stacks(temp);
	// // sleep(2);

    // moves = simulate_next_two(temp, chunks, moves);
	// printf("\n\t(sim_1_1) moves %d\n", moves);
	// print_stacks(temp);
	// sleep(5);
	
	return (moves);
}

int sim_1_2(stacks_t temp, int *chunks)
{
	int moves;
    moves_t *cmd;


	// printf("\n\t******************\n");
	// printf("\n\t**** SIM 1 2 ***\n");
	// printf("\n\t******************\n");


	// printf("\n\t(sim_1_2) SEE HERE moves\n");
	// print_stacks(temp);
	// sleep(5);

	cmd = malloc(sizeof(moves_t) * 2  + 1);
	moves = 0;
	if ((!closer_to_beginning2(temp, chunks, temp.sizeA, *(&cmd))))
        perror("\n\n\tCannot find first number in chunk\n"); // Encontrar primeiro numero dentro do stackA do inicio

	if ((!closer_to_end2(temp, chunks, &cmd[1])))
        perror("\n\n\tCannot find first number in chunk\n"); // Encontrar primeiro numero dentro do stackA do inicio


	// printf("\n\t(sim_1_2) Got here?\n");
    cmd->pos_stackb = where_to_putnbr2(cmd->num, temp.stackB, temp.sizeB);

	moves = simulate_num1(&temp, cmd[0]);
	moves = simulate_num2(&temp, cmd[1]);

	moves += check_two_opt(temp, chunks);
	// printf("\n\t(sim 1 2) SEE THIS moves %d\n", moves);
	// print_stacks(temp);
	// // sleep(2);

    // moves = simulate_next_two(temp, chunks, moves);
	// printf("\n\t(sim_1_1) moves %d\n", moves);
	// print_stacks(temp);
	// sleep(5);	
	return (moves);
}

int sim_2_1(stacks_t temp, int *chunks)
{
	int moves;
    moves_t *cmd;


	// printf("\n\t******************\n");
	// printf("\n\t**** SIM 2 1 ***\n");
	// printf("\n\t******************\n");

	cmd = malloc(sizeof(moves_t) * 2  + 1);
	moves = 0;
	if ((!closer_to_beginning2(temp, chunks, temp.sizeA, *(&cmd))))
        perror("\n\n\tCannot find first number in chunk\n"); // Encontrar primeiro numero dentro do stackA do inicio

	if ((!closer_to_end2(temp, chunks, &cmd[1])))
        perror("\n\n\tCannot find first number in chunk\n"); // Encontrar primeiro numero dentro do stackA do inicio

	// printf("\n\t(sim_2_1) Got here?\n");
    cmd->pos_stackb = where_to_putnbr2(cmd->num, temp.stackB, temp.sizeB);

	moves = simulate_num2(&temp, cmd[0]);
	moves = simulate_num1(&temp, cmd[1]);

	// printf("\n\t(sim_2_1) SEE HERE moves %d\n", moves);
	// print_stacks(temp);
	moves += check_two_opt(temp, chunks);
	// printf("\n\t(sim 2 1) SEE THIS moves %d\n", moves);
	// print_stacks(temp);
	// // sleep(2);

    // moves = simulate_next_two(temp, chunks, moves);
	// printf("\n\t(sim_1_1) moves %d\n", moves);
	// print_stacks(temp);
	// sleep(5);
	
	return (moves);
}

int sim_2_2(stacks_t temp, int *chunks)
{
	int moves;
    moves_t *cmd;


	// printf("\n\t******************\n");
	// printf("\n\t**** SIM 2 2 ***\n");
	// printf("\n\t** VERIFICAR 1º/1º **\n");
	// printf("\n\t******************\n");


	cmd = malloc(sizeof(moves_t) + 1);
	moves = 0;

	if ((!closer_to_end2(temp, chunks, *(&cmd))))
        perror("\n\n\tCannot find first number in chunk\n"); // Encontrar primeiro numero dentro do stackA do inicio
    

	// print_stacks(temp);
	// sleep(5);
	// printf("\n\t(sim_2_2) Got here?\n");
    cmd->pos_stackb = where_to_putnbr2(cmd->num, temp.stackB, temp.sizeB);

	moves = simulate_num2(&temp, cmd[0]);

	if ((!closer_to_end2(temp, chunks, *(&cmd))))
        perror("\n\n\tCannot find first number in chunk\n"); // Encontrar primeiro numero dentro do stackA do inicio

	moves = simulate_num2(&temp, cmd[0]);

	moves += check_two_opt(temp, chunks);
	// printf("\n\t(sim 2 2) SEE THIS moves %d\n", moves);
	
	// print_stacks(temp);
	// sleep(5);
	// // print_stacks(temp);
	// // sleep(2);

    // moves = simulate_next_two(temp, chunks, moves);
	// printf("\n\t(sim_1_1) moves %d\n", moves);
	// print_stacks(temp);
	// sleep(5);
	
	return (moves);
}


int	see_best_opt(int i, int x, stacks_t temp, int *chunks)
{
	int moves;
	int moves2;
	stacks_t temp2;
	
	// printf("\n\t(see best opt)teste %d %d\n", i, x);
	moves = 0;

    temp2 = pass_stacks_to_temp(temp);	
	print_stacks(temp2);

	if (i == 0)
		moves = sim_1_1(temp2, chunks);
	else if (i == 1)
		moves = sim_1_2(temp2, chunks);
	else if (i == 2)
		moves = sim_2_1(temp2, chunks);
	else if (i == 3)
		moves = sim_2_2(temp2, chunks);

    temp2 = pass_stacks_to_temp(temp);	
	// print_stacks(temp2);
	// exit(0);

	moves2 = 0;
 	if (x == 0)
		moves2 = sim_1_1(temp, chunks);
	else if (x == 1)
		moves2 = sim_1_2(temp, chunks);
	else if (x == 2)
		moves2 = sim_2_1(temp, chunks);
	else if (x == 3)
		moves2 = sim_2_2(temp, chunks);

	// printf("\n\t(see best opt) SEE THIS moves %d %d moves2 %d %d\n", i, moves, x, moves2);
	// sleep(3);
	if (moves >= moves2)
		return (x);
	else
		return (i);
}

int	return_best_opt(int *mv, stacks_t temp, int *chunks)
{
	int i;
	int x;
	int value;

	i = 0;

	if (mv[0] == 0 || mv[1] == 0 || mv[2] == 0 || mv[3] == 0)
		perror("\n\t(return best opt) One of the val is equal to 0 \n");
	
	while (1)
	{
		if (i == 3)
			return (i);
		x = i + 1;
		while (mv[i] <= mv[x] && x != 4)
		{
			// printf("\n\t(return best opt)teste %d\n", x);
			x++;
		}
		// printf("\n\t(return best opt)teste %d\n", x);
		if (x == 4)
		{
			value = mv[i];
			x = i;
			while (x != 4)
			{
				if (value != mv[x + 1] && x + 1 != 4)
					x++;
				else
				{
					i = see_best_opt(i, x, temp, chunks);
					break;
				}
			}

			// printf("\n\t(return best opt)value %d && i %d\n", value, i);
			break;
		}
		i++;
	}
	return (i);
}