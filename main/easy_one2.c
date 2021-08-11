#include "../push_swap.h"

stacks_t	pass_stacks_to_temp(stacks_t main)
{
	stacks_t	temp;
	int			x;

	temp.stackA = malloc(sizeof(int) * main.sizeA + 1);
	temp.lowest = main.lowest;
	temp.size_chunk = main.size_chunk;
	temp.middle_size = main.middle_size;
	temp.sizeA = main.sizeA;
	temp.sizeB = main.sizeB;
	x = 0;
	while (main.sizeA--)
	{
		temp.stackA[x] = main.stackA[x];
		x++;
	}
	x = 0;
	if (main.sizeB != 0)
	{
		temp.stackB = malloc(sizeof(int) * main.sizeB + 1);
		while (main.sizeB--)
		{
			temp.stackB[x] = main.stackB[x];
			x++;
		}
	}
	return (temp);
}

int	do_end(stacks_t temp, int *chunks)
{
	int		mv[2];
	moves_t	cmd[2];

	init_cmd(&cmd[0]);
	init_cmd(&cmd[1]);
	if (temp.sizeB == 4)
	{
		closer_to_beginning2(temp, chunks, temp.sizeA, &cmd[0]);
		closer_to_end2(temp, chunks, &cmd[1]);
		if (cmd[0].num <= cmd[1].num)
			return (4);
		return (5);
	}
	else
	{
		mv[0] = simulate_next_f(temp, chunks, 0);
		mv[1] = simulate_next_s(temp, chunks, 0);
		if (mv[0] <= mv[1])
			return (4);
		return (5);
	}
	return (0);
}

int	search_in_chunk(stacks_t temp, int *chunk, int sizeA)
{
	int	ret;
	int	i;
	int	x;

	i = 0;
	ret = 0;
	while (i < sizeA && ret < 2)
	{
		x = 0;
		while (temp.stackA[i] != chunk[x] && x < temp.size_chunk)
			x++;
		if (x != temp.size_chunk)
			ret++;
		i++;
	}
	return (ret);
}

int	check_four_opt(stacks_t main, int *chunks)
{
	stacks_t	temp;
	int			movesss;
	int			mv[4];
	int			nums_in_chunk;

	movesss = 0;
	temp = pass_stacks_to_temp(main);
	nums_in_chunk = search_in_chunk(temp, chunks, temp.sizeA);
	if (nums_in_chunk == 0 || temp.sizeA < 3)
		return (-1);
	else if (nums_in_chunk == 1 || temp.sizeA == 4)
		return (do_end(temp, chunks));
	movesss = simulate_num1(&temp, chunks, 0);
	mv[0] = simulate_next_f(temp, chunks, movesss);
	mv[1] = simulate_next_s(temp, chunks, movesss);
	temp = pass_stacks_to_temp(main);
	movesss = simulate_num2(&temp, chunks, 0);
	mv[2] = simulate_next_f(temp, chunks, movesss);
	mv[3] = simulate_next_s(temp, chunks, movesss);
	temp = pass_stacks_to_temp(main);
	return (return_best_opt(mv, temp, chunks));
}

stacks_t	push_chunk_to_b2(stacks_t main, int *chunks)
{
	int	counter;
	int	option;

	counter = 0;
	while (counter <= main.size_chunk + 1)
	{
		option = 0;
		option = check_four_opt(main, chunks);
		if (option == -1)
			break ;
		main = do_opt(main, chunks, option);
		if (main.sizeA == 3)
			break ;
		counter += 2;
	}
	return (main);
}

moves_t	stackB_correct(stacks_t *main, int size)
{
	int		max;
	int		max_place;
	moves_t	cmd;

	init_cmd(&cmd);
	max = biggest_num(main->stackB, size);
	max_place = place_in_array(main->stackB, max);
	if (max_place <= size / 2)
	{
		*main = gen_moves_fake(*main, 3, size - max_place, 0);
		cmd.rrb = size - max_place;
	}
	else if (max_place > size / 2)
	{
		*main = gen_moves_fake(*main, 2, max_place, 0);
		cmd.rb = max_place;
	}
	return (cmd);
}

stacks_t	last3_stackA(stacks_t main, moves_t cmd)
{
	int	lower;
	int	lower_pos;

	lower_pos = 0;
	lower = 0;
	if (!is_lowest_array(main.stackB[0], main.stackA, main.sizeA))
	{
		lower = lowest_num(main.stackA, main.sizeA);
		lower_pos = place_in_array(main.stackA, lower);
		if (lower_pos == 0 && main.stackA[1] < main.stackA[2])
		{
			main = ra_funct(main, 1);
			main = pa_funct(main, 1);
			main = rra_funct(main, 1);
		}
		if (lower_pos == 2 && main.stackA[0] > main.stackA[1])
		{
			main = sa_funct(main, 1);
			while (main.stackA[main.sizeA - 1] < main.stackB[0])
				main = pa_funct(main, 1);
		}
		else if (lower_pos == 2 && main.stackA[0] < main.stackA[1])
		{
			main = pa_funct(main, 1);
			main = rra_funct(main, 1);
		}
		cmd.rra = 1;
	}
	if (!is_correct(main.stackA, 3))
	{
		if (main.stackA[0] > main.stackA[1] && main.stackA[1] < main.stackA[2])
			main = ra_funct(main, 1);
		if (main.stackA[0] > main.stackA[1])
			main = sa_funct(main, 1);
		if (is_lowest_array(main.stackA[3], main.stackA, main.sizeA))
		{
			cmd.rra = 1;
			main = rra_funct(main, 1);
		}
		while (!is_lowest_array(main.stackA[0], main.stackA, main.sizeA))
		{
			cmd.ra++;
			main = ra_funct(main, 1);
		}
	}
	return (main);
}

stacks_t	do_easy_one2(stacks_t main)
{
	int		*chunks;
	int		*org;
	moves_t	cmd;

	while (main.sizeA != 3)
	{
		org = organize_array(main.stackA, main.sizeA - 1);
		init_main_loop(&main, org);
		 if (main.sizeA > 100)
			main.size_chunk = get_attr_chunks(&chunks, main.sizeA, org, 11);
		if (main.sizeA > 20)
			main.size_chunk = get_attr_chunks(&chunks, main.sizeA, org, 6);
		else
			main.size_chunk = get_attr_chunks(&chunks, main.sizeA, org, 2);
		main = push_chunk_to_b2(main, chunks);
	}
	cmd = stackB_correct(&main, main.sizeB);
	main = last3_stackA(main, cmd);
	while (main.stackB[0] < main.stackA[0] && main.sizeB != 0)
		main = pa_funct(main, 1);
	print_stacks(main);
	return (main);
}
