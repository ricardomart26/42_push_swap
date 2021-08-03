#include "../push_swap.h"

int check_two_opt(stacks_t temp, int *chunks)
{
    int movesss;
    int mv[2];

    movesss = 0;
    temp = pass_stacks_to_temp(temp);

    mv[0] = simulate_next_f(temp, chunks, movesss);
    mv[1] = simulate_next_s(temp, chunks, movesss);

	if (mv[1] >= mv[0])
		return (mv[1]);
	else
		return (mv[0]);
}

int sim_1_1(stacks_t temp, int *chunks)
{
	int moves;
    moves_t *cmd;

	cmd = malloc(sizeof(moves_t) + 1);
	if ((!closer_to_beginning2(temp, chunks, temp.sizeA, *(&cmd))))
        perror("\n\n\tCannot find first number in chunk\n"); // Encontrar primeiro numero dentro do stackA do inicio

    cmd[0] = get_cmds(temp, cmd[0], temp.sizeB);
	moves = simulate_num1(&temp, cmd[0]);

	if ((!closer_to_beginning2(temp, chunks, temp.sizeA, *(&cmd))))
        perror("\n\n\tCannot find first number in chunk\n");

    cmd[0] = get_cmds(temp, cmd[0], temp.sizeB);
	moves += simulate_num1(&temp, cmd[0]);

	moves += check_two_opt(temp, chunks);
	
	return (moves);
}

int sim_1_2(stacks_t temp, int *chunks)
{
	int moves;
    moves_t *cmd;

	cmd = malloc(sizeof(moves_t) * 2  + 1);
	if ((!closer_to_beginning2(temp, chunks, temp.sizeA, &cmd[0])))
        perror("\n\n\tCannot find first number in chunk\n"); // Encontrar primeiro numero dentro do stackA do inicio

	if ((!closer_to_end2(temp, chunks, &cmd[1])))
        perror("\n\n\tCannot find first number in chunk\n"); // Encontrar primeiro numero dentro do stackA do inicio

    cmd[0] = get_cmds(temp, cmd[0], temp.sizeB);
    cmd[1] = get_cmds(temp, cmd[1], temp.sizeB);
	
	moves = simulate_num1(&temp, cmd[0]);
	moves = simulate_num2(&temp, cmd[1]);

	moves += check_two_opt(temp, chunks);
	return (moves);
}

int sim_2_1(stacks_t temp, int *chunks)
{
	int moves;
    moves_t *cmd;

	cmd = malloc(sizeof(moves_t) * 2  + 1);
	if ((!closer_to_beginning2(temp, chunks, temp.sizeA, *(&cmd))))
        perror("\n\n\tCannot find first number in chunk\n"); // Encontrar primeiro numero dentro do stackA do inicio

	if ((!closer_to_end2(temp, chunks, &cmd[1])))
        perror("\n\n\tCannot find first number in chunk\n"); // Encontrar primeiro numero dentro do stackA do inicio

    cmd[0] = get_cmds(temp, cmd[0], temp.sizeB);
    cmd[1] = get_cmds(temp, cmd[1], temp.sizeB);

	moves = simulate_num2(&temp, cmd[1]);
	moves = simulate_num1(&temp, cmd[0]);

	moves += check_two_opt(temp, chunks);
	
	return (moves);
}

int sim_2_2(stacks_t temp, int *chunks)
{
	int moves;
    moves_t *cmd;

	cmd = malloc(sizeof(moves_t) + 1);
	if ((!closer_to_end2(temp, chunks, *(&cmd))))
        perror("\n\n\tCannot find first number in chunk\n"); // Encontrar primeiro numero dentro do stackA do inicio

    cmd[0] = get_cmds(temp, cmd[0], temp.sizeB);
    moves = simulate_num2(&temp, cmd[0]);

	if ((!closer_to_end2(temp, chunks, *(&cmd))))
        perror("\n\n\tCannot find first number in chunk\n"); // Encontrar primeiro numero dentro do stackA do inicio

    cmd[0] = get_cmds(temp, cmd[0], temp.sizeB);
	moves = simulate_num2(&temp, cmd[0]);

	moves += check_two_opt(temp, chunks);	
	return (moves);
}


int	see_best_opt(int i, int x, stacks_t temp, int *chunks)
{
	int moves;
	int moves2;
	stacks_t temp2;
	
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
			x++;
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
			break;
		}
		i++;
	}
	return (i);
}