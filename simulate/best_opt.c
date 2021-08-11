#include "../push_swap.h"

int check_two_opt(stacks_t temp, int *chunks)
{
    int mv[2];

    temp = pass_stacks_to_temp(temp);
    mv[0] = simulate_next_f(temp, chunks, 0);
    mv[1] = simulate_next_s(temp, chunks, 0);
	if (mv[1] >= mv[0])
		return (mv[1]);
	return (mv[0]);
}

int sim_1_1(stacks_t temp, int *chunks)
{
	int moves;

	moves = simulate_num1(&temp, chunks, 0);
	moves += simulate_num1(&temp, chunks, 0);
	moves += check_two_opt(temp, chunks);	
	return (moves);
}

int sim_1_2(stacks_t temp, int *chunks)
{
	int moves;

	moves = simulate_num1(&temp, chunks, 0);
	moves += simulate_num2(&temp, chunks, 0);
	moves += check_two_opt(temp, chunks);
	return (moves);
}

int sim_2_1(stacks_t temp, int *chunks)
{
	int moves;

	moves = simulate_num2(&temp, chunks, 0);
	moves += simulate_num1(&temp, chunks, 0);
	moves += check_two_opt(temp, chunks);
	return (moves);
}

int sim_2_2(stacks_t temp, int *chunks)
{
	int moves;

    moves = simulate_num2(&temp, chunks, 0);
	moves += simulate_num2(&temp, chunks, 0);
	moves += check_two_opt(temp, chunks);	
	return (moves);
}


int	see_best_opt(int i, int x, stacks_t temp, int *chunks)
{
	int moves;
	int moves2;
	stacks_t temp2;
	
    if (temp.sizeA - 2 != 3)
		return (i);
    temp2 = pass_stacks_to_temp(temp);
	moves = 0;
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
		moves2 = sim_1_1(temp2, chunks);
	else if (x == 1)
		moves2 = sim_1_2(temp2, chunks);
	else if (x == 2)
		moves2 = sim_2_1(temp2, chunks);
	else if (x == 3)
		moves2 = sim_2_2(temp2, chunks);
	if (moves >= moves2)
		return (x);
	return (i);
}

int	return_best_opt(int *mv, stacks_t temp, int *chunks)
{
	int i;
	int x;
	int value;

	i = 0;
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
			while (x < 4)
			{
				if (value != mv[x + 1] && x + 1 != 4)
					x++;
				else if (temp.sizeA > 5)
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