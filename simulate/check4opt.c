/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check4opt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricardo <ricardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 00:45:00 by ricardo           #+#    #+#             */
/*   Updated: 2021/08/21 19:15:53 by ricardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	return_best_opt(t_stacks main, t_stacks temp, int num_in_chunk)
{
	int	i;
	int	x;
	int	value;

	i = 0;
	while (1)
	{
		if (i == 3)
			break ;
		x = i + 1;
		while (main.mv[i] <= main.mv[x] && x != 4)
			x++;
		if (x == 4)
		{
			value = main.mv[i];
			x = i;
			if (num_in_chunk != 2)
				i = see_if_is_equal(main, temp, value, i);
			break ;
		}
		i++;
	}
	free_all_stacks_t(&temp, temp.sizeB);
	return (i);
}

int	do_end(t_stacks *temp, int *chunks)
{
	int		mv[2];
	t_moves	cmd[2];

	init_cmd(&cmd[0]);
	init_cmd(&cmd[1]);
	if (temp->sizeB == 4)
	{
		closer_to_beg(*temp, chunks, temp->sizeA, &cmd[0]);
		closer_to_end(*temp, chunks, &cmd[1]);
		free_all_stacks_t(temp, temp->sizeB);
		if (cmd[0].num <= cmd[1].num)
			return (4);
		return (5);
	}
	else
	{
		mv[0] = simulate_next_f(*temp, chunks, 0);
		mv[1] = simulate_next_s(*temp, chunks, 0);
		free_all_stacks_t(temp, temp->sizeB);
		if (mv[0] <= mv[1])
			return (4);
		return (5);
	}
	return (0);
}

int	check_four_opt(t_stacks main, int *chunks)
{
	t_stacks	temp;
	int			movesss;
	int			nums_in_chunk;

	movesss = 0;
	temp = pass_stacks_to_temp(main);
	nums_in_chunk = search_in_chunk(temp, chunks, temp.sizeA);
	if (nums_in_chunk == 0 || temp.sizeA < 3)
	{
		free_all_stacks_t(&temp, temp.sizeB);
		return (-1);
	}
	else if (nums_in_chunk == 1 || temp.sizeA == 4)
		return (do_end(&temp, chunks));
	movesss = simulate_num1(&temp, chunks, 0);
	main.mv[0] = simulate_next_f(temp, chunks, movesss);
	main.mv[1] = simulate_next_s(temp, chunks, movesss);
	free_all_stacks_t(&temp, temp.sizeB);
	temp = pass_stacks_to_temp(main);
	movesss = simulate_num2(&temp, chunks, 0);
	main.mv[2] = simulate_next_f(temp, chunks, movesss);
	main.mv[3] = simulate_next_s(temp, chunks, movesss);
	free_all_stacks_t(&temp, temp.sizeB);
	temp = pass_stacks_to_temp(main);
	return (return_best_opt(main, temp, nums_in_chunk));
}
