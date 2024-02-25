/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   real.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimartin <rimartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 00:46:23 by ricardo           #+#    #+#             */
/*   Updated: 2021/09/11 11:39:07 by rimartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	real_num2(t_stacks *temp, int *chunk)
{
	t_moves	cmd;

	init_cmd(&cmd);
	closer_to_end(*temp, chunk, &cmd);
	cmd = get_cmds(*temp, cmd, temp->size_b);
	cmd.total = num2(&temp, cmd);
	return (cmd.total);
}

int	real_num1(t_stacks *temp, int *chunk)
{
	t_moves	cmd;

	init_cmd(&cmd);
	closer_to_beg(*temp, chunk, temp->size_a, &cmd);
	cmd = get_cmds(*temp, cmd, temp->size_b);
	cmd.total = num1(&temp, cmd);
	return (cmd.total);
}

t_stacks	combo_opt(t_stacks stacks, int *chunks, int option)
{
	if (option == 0)
	{
		real_num1(&stacks, chunks);
		real_num1(&stacks, chunks);
	}
	if (option == 1)
	{
		real_num1(&stacks, chunks);
		real_num2(&stacks, chunks);
	}
	if (option == 2)
	{
		real_num2(&stacks, chunks);
		real_num1(&stacks, chunks);
	}
	if (option == 3)
	{
		real_num2(&stacks, chunks);
		real_num2(&stacks, chunks);
	}
	return (stacks);
}

t_stacks	do_opt(t_stacks stacks, int *chunks, int option)
{
	if (option < 4)
		stacks = combo_opt(stacks, chunks, option);
	else if (option == 4)
		simulate_num1(&stacks, chunks, 1);
	else if (option == 5)
		simulate_num2(&stacks, chunks, 1);
	return (stacks);
}
