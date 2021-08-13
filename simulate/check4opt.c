/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check4opt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricardo <ricardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 00:45:00 by ricardo           #+#    #+#             */
/*   Updated: 2021/08/12 02:55:34 by ricardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	return_best_opt(int *mv, stacks_t temp, int *chunks)
{
	int	i;
	int	x;
	int	value;

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
			i = see_if_is_equal(temp, chunks, value, i);
			break ;
		}
		i++;
	}
	return (i);
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
