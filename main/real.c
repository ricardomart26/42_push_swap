#include "../push_swap.h"

int	real_num2(stacks_t *temp, int *chunk)
{
	moves_t	cmd;

	init_cmd(&cmd);
	closer_to_end2(*temp, chunk, &cmd);
	cmd = get_cmds(*temp, cmd, temp->sizeB);
	cmd.total = num2(&temp, cmd);
	return (cmd.total);
}

int	real_num1(stacks_t *temp, int *chunk)
{
	moves_t	cmd;

	init_cmd(&cmd);
	closer_to_beginning2(*temp, chunk, temp->sizeA, &cmd);
	cmd = get_cmds(*temp, cmd, temp->sizeB);
	cmd.total = num1(&temp, cmd);
	return (cmd.total);
}

stacks_t	combo_opt(stacks_t main, int *chunks, int option)
{
	if (option == 0)
	{
		real_num1(&main, chunks);
		real_num1(&main, chunks);
	}
	if (option == 1)
	{
		real_num1(&main, chunks);
		real_num2(&main, chunks);
	}
	if (option == 2)
	{
		real_num2(&main, chunks);
		real_num1(&main, chunks);
	}
	if (option == 3)
	{
		real_num2(&main, chunks);
		real_num2(&main, chunks);
	}
	return (main);
}

stacks_t	do_opt(stacks_t main, int *chunks, int option)
{
	if (option < 4)
		main = combo_opt(main, chunks, option);
	else if (option == 4)
		simulate_num1(&main, chunks, 1);
	else if (option == 5)
		simulate_num2(&main, chunks, 1);
	return (main);
}
