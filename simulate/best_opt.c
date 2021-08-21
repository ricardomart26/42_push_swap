/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_opt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricardo <ricardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 00:52:28 by ricardo           #+#    #+#             */
/*   Updated: 2021/08/21 19:01:44 by ricardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_two_opt(t_stacks temp, int *chunks)
{
	int	mv[2];
	
	mv[0] = simulate_next_f(temp, chunks, 0);
	mv[1] = simulate_next_s(temp, chunks, 0);
	if (mv[1] >= mv[0])
		return (mv[1]);
	return (mv[0]);
}

int	sim_all(t_stacks temp, int *chunks, int i, int x)
{
	int	moves;

	moves = 0;
	if (i == 1 && x == 1)
	{
		moves = simulate_num1(&temp, chunks, 0);
		moves += simulate_num1(&temp, chunks, 0);
	}
	else if (i == 1 && x == 2)
	{
		moves = simulate_num1(&temp, chunks, 0);
		moves += simulate_num2(&temp, chunks, 0);
	}
	else if (i == 2 && x == 1)
	{
		moves = simulate_num2(&temp, chunks, 0);
		moves += simulate_num1(&temp, chunks, 0);
	}
	else if (i == 2 && x == 2)
	{
		moves = simulate_num2(&temp, chunks, 0);
		moves += simulate_num2(&temp, chunks, 0);
	}
	moves += check_two_opt(temp, chunks);
	return (moves);
}

int	how_many_moves(t_stacks temp, int *chunks, int i)
{
	int	moves;

	moves = 0;
	if (i == 0)
		moves = sim_all(temp, chunks, 1, 1);
	else if (i == 1)
		moves = sim_all(temp, chunks, 1, 2);
	else if (i == 2)
		moves = sim_all(temp, chunks, 2, 1);
	else if (i == 3)
		moves = sim_all(temp, chunks, 2, 2);
	return (moves);
}

int	see_best_opt(int i, int x, t_stacks temp, int *chunks)
{
	int	moves;
	int	moves2;

	if (temp.sizeA - 2 != 3)
		return (i);
	moves = how_many_moves(temp, chunks, i);
	moves2 = how_many_moves(temp, chunks, x);
	if (moves >= moves2)
		return (x);
	return (i);
}

int	see_if_is_equal(t_stacks main, t_stacks temp, int value, int i)
{
	int	x;

	x = i;
	while (x < 4)
	{
		if (value != main.mv[x + 1] && x + 1 != 4)
			x++;
		else if (temp.sizeA > 5)
		{
			i = see_best_opt(i, x, temp, temp.chunks);
			break ;
		}
	}
	return (i);
}
