/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimartin <rimartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 01:03:17 by ricardo           #+#    #+#             */
/*   Updated: 2021/09/11 11:41:10 by rimartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	simulate_next_f(t_stacks temp, int *chunks, int moves)
{
	t_stacks	temp2;

	temp2 = pass_stacks_to_temp(temp);
	moves += simulate_num1(&temp2, chunks, 0);
	free_all_stacks_t(&temp2, temp2.size_b);
	return (moves);
}

int	simulate_next_s(t_stacks temp, int *chunks, int moves)
{
	t_stacks	temp2;

	temp2 = pass_stacks_to_temp(temp);
	moves += simulate_num2(&temp2, chunks, 0);
	free_all_stacks_t(&temp2, temp2.size_b);
	return (moves);
}

int	simulate_num2(t_stacks *temp, int *chunks, int opt)
{
	t_moves	cmd;

	init_cmd(&cmd);
	closer_to_end(*temp, chunks, &cmd);
	cmd = get_cmds(*temp, cmd, temp->size_b);
	if (opt)
		cmd.total = num2(&temp, cmd);
	else
		cmd.total = num2_fake(&temp, cmd);
	return (cmd.total);
}

int	simulate_num1(t_stacks *temp, int *chunks, int opt)
{
	t_moves	cmd;

	init_cmd(&cmd);
	closer_to_beg(*temp, chunks, temp->size_a, &cmd);
	cmd = get_cmds(*temp, cmd, temp->size_b);
	if (opt)
		cmd.total = num1(&temp, cmd);
	else
		cmd.total = num1_fake(&temp, cmd);
	return (cmd.total);
}
