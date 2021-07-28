#include "../push_swap.h"

//	printf("\n\t(sim_1_1)\n");

int sim_1_1(stacks_t temp, int *chunks)
{
	int moves;
    moves_t cmd;
	
	moves = 0;
	if ((!closer_to_beginning2(temp, chunks, temp.sizeA, &cmd)))
        perror("\n\n\tCannot find first number in chunk\n"); // Encontrar primeiro numero dentro do stackA do inicio
    if ((!closer_to_end2(temp, chunks, &cmd)))
    	perror("\n\n\tCannot find chunk number in stackA\n");
    get_pos(temp, &cmd); 

	printf("\n\t(sim_1_1) Check if stack temp is working\n");
	print_stacks(temp);
	sleep(5);
	moves = simulate_num1(&temp, &cmd);
    moves = simulate_next_f(temp, chunks, moves);
	printf("\n\t(sim_1_1) moves %d\n", moves);
	
	return (moves);
}

int sim_1_2(stacks_t temp, int *chunks)
{
	int moves;
    moves_t cmd;
	
	moves = 0;
	if ((!closer_to_beginning2(temp, chunks, temp.sizeA, &cmd)))
        perror("\n\n\tCannot find first number in chunk\n"); // Encontrar primeiro numero dentro do stackA do inicio
    if ((!closer_to_end2(temp, chunks, &cmd)))
    	perror("\n\n\tCannot find chunk number in stackA\n"); 
	printf("\n\t(sim_1_2) Check if stack temp is working\n");
	print_stacks(temp);
	sleep(5);
	moves = simulate_num1(&temp, &cmd);
    moves = simulate_next_s(temp, chunks, moves);

	printf("\n\t(sim_1_2) moves %d\n", moves);
	return (moves);
	
}

int sim_2_1(stacks_t temp, int *chunks)
{
	int moves;
    moves_t cmd;
	
	moves = 0;
	if ((!closer_to_beginning2(temp, chunks, temp.sizeA, &cmd)))
        perror("\n\n\tCannot find first number in chunk\n"); // Encontrar primeiro numero dentro do stackA do inicio
    if ((!closer_to_end2(temp, chunks, &cmd)))
    	perror("\n\n\tCannot find chunk number in stackA\n"); 
	printf("\n\t(sim_2_1) Check if stack temp is working\n");
	print_stacks(temp);	
	sleep(5);
	moves = simulate_num2(&temp, &cmd);
    moves = simulate_next_f(temp, chunks, moves);
	printf("\n\t(sim_2_1) moves %d\n", moves);
	return (moves);

}

int sim_2_2(stacks_t temp, int *chunks)
{
	int moves;
    moves_t cmd;
	
	moves = 0;
	if ((!closer_to_beginning2(temp, chunks, temp.sizeA, &cmd)))
        perror("\n\n\tCannot find first number in chunk\n"); // Encontrar primeiro numero dentro do stackA do inicio
    if ((!closer_to_end2(temp, chunks, &cmd)))
    	perror("\n\n\tCannot find chunk number in stackA\n"); 
	printf("\n\t(sim_2_2) Check if stack temp is working\n");
	print_stacks(temp);
	sleep(5);
	moves = simulate_num2(&temp, &cmd);
    moves = simulate_next_s(temp, chunks, moves);
	printf("\n\t(sim_2_2) moves %d\n", moves);
	return (moves);
}


int	see_best_opt(int i, int x, stacks_t temp, int *chunks)
{
	int moves;
	int moves2;

	moves = 0;
	if (i == 0)
		moves = sim_1_1(temp, chunks);
	else if (i == 1)
		moves = sim_1_2(temp, chunks);
	else if (i == 2)
		moves = sim_2_1(temp, chunks);
	else if (i == 3)
		moves = sim_2_2(temp, chunks);

	moves2 = 0;
 	if (x == 0)
		moves2 = sim_1_1(temp, chunks);
	else if (x == 1)
		moves2 = sim_1_2(temp, chunks);
	else if (x == 2)
		moves2 = sim_2_1(temp, chunks);
	else if (x == 3)
		moves2 = sim_2_2(temp, chunks);

	if (moves >= moves2)
		return (i);
	else
		return (x);
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
			x++;
		if (x == 4)
		{
			value = mv[i];
			x = i;
			while (x != 4)
			{
				if (value != mv[x + 1] && x != 4)
					x++;
				else
					i = see_best_opt(i, x, temp, chunks);
			}
			printf("\n\tvalue %d && i %d\n", value, i);
			break;
		}
		i++;
	}
	return (i);
}