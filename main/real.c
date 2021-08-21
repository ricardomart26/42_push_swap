/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   real.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricardo <ricardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 00:46:23 by ricardo           #+#    #+#             */
/*   Updated: 2021/08/20 23:06:18 by ricardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	real_num2(t_stacks *temp, int *chunk)
{
	t_moves	cmd;

	init_cmd(&cmd);
	closer_to_end(*temp, chunk, &cmd);
	cmd = get_cmds(*temp, cmd, temp->sizeB);
	cmd.total = num2(&temp, cmd);
	return (cmd.total);
}

int	real_num1(t_stacks *temp, int *chunk)
{
	t_moves	cmd;

	init_cmd(&cmd);
	closer_to_beg(*temp, chunk, temp->sizeA, &cmd);
	cmd = get_cmds(*temp, cmd, temp->sizeB);
	cmd.total = num1(&temp, cmd);
	return (cmd.total);
}

t_stacks	combo_opt(t_stacks main, int *chunks, int option)
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

t_stacks	do_opt(t_stacks main, int *chunks, int option)
{
	if (option < 4)
		main = combo_opt(main, chunks, option);
	else if (option == 4)
		simulate_num1(&main, chunks, 1);
	else if (option == 5)
		simulate_num2(&main, chunks, 1);
	return (main);
}
