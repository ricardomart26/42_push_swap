/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check4opt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimartin <rimartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 00:45:00 by ricardo           #+#    #+#             */
/*   Updated: 2021/09/11 11:40:25 by rimartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	return_best_opt(t_stacks stacks, t_stacks temp, int num_in_chunk)
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
		while (stacks.mv[i] <= stacks.mv[x] && x != 4)
			x++;
		if (x == 4)
		{
			value = stacks.mv[i];
			x = i;
			if (num_in_chunk != 2)
				i = see_if_is_equal(stacks, temp, value, i);
			break ;
		}
		i++;
	}
	free_all_stacks_t(&temp, temp.size_b);
	return (i);
}

int	do_end(t_stacks *temp, int *chunks)
{
	int		mv[2];
	t_moves	cmd[2];

	init_cmd(&cmd[0]);
	init_cmd(&cmd[1]);
	if (temp->size_b == 4)
	{
		closer_to_beg(*temp, chunks, temp->size_a, &cmd[0]);
		closer_to_end(*temp, chunks, &cmd[1]);
		free_all_stacks_t(temp, temp->size_b);
		if (cmd[0].num <= cmd[1].num)
			return (4);
		return (5);
	}
	else
	{
		mv[0] = simulate_next_f(*temp, chunks, 0);
		mv[1] = simulate_next_s(*temp, chunks, 0);
		free_all_stacks_t(temp, temp->size_b);
		if (mv[0] <= mv[1])
			return (4);
		return (5);
	}
	return (0);
}

int	check_four_opt(t_stacks stacks, int *chunks)
{
	t_stacks	temp;
	int			movesss;
	int			nums_in_chunk;

	movesss = 0;
	temp = pass_stacks_to_temp(stacks);
	nums_in_chunk = search_in_chunk(temp, chunks, temp.size_a);
	if (nums_in_chunk == 0 || temp.size_a < 3)
	{
		free_all_stacks_t(&temp, temp.size_b);
		return (-1);
	}
	else if (nums_in_chunk == 1 || temp.size_a == 4)
		return (do_end(&temp, chunks));
	movesss = simulate_num1(&temp, chunks, 0);
	stacks.mv[0] = simulate_next_f(temp, chunks, movesss);
	stacks.mv[1] = simulate_next_s(temp, chunks, movesss);
	free_all_stacks_t(&temp, temp.size_b);
	temp = pass_stacks_to_temp(stacks);
	movesss = simulate_num2(&temp, chunks, 0);
	stacks.mv[2] = simulate_next_f(temp, chunks, movesss);
	stacks.mv[3] = simulate_next_s(temp, chunks, movesss);
	free_all_stacks_t(&temp, temp.size_b);
	temp = pass_stacks_to_temp(stacks);
	return (return_best_opt(stacks, temp, nums_in_chunk));
}
