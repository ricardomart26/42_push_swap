/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmds.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimartin <rimartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 02:20:06 by ricardo           #+#    #+#             */
/*   Updated: 2021/09/11 11:45:48 by rimartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_moves	set_b(t_moves cmd, int rb, int rrb)
{
	cmd.rb = rb;
	cmd.rrb = rrb;
	if (cmd.rb != 0 && cmd.ra != 0)
		moves_rb(&cmd);
	else if (cmd.rrb != 0 && cmd.rra != 0)
		moves_rrb(&cmd);
	else
	{
		cmd.rrr = 0;
		cmd.rr = 0;
	}
	return (cmd);
}

int	fuck_norm2(t_stacks stacks, int i, t_moves *cmd, int temp)
{
	if (stacks.b[i] > cmd->num)
		cmd->pos_b = i + 1;
	else if (stacks.b[i] < cmd->num)
		cmd->pos_b = i;
	return (temp);
}

void	check_diff(t_stacks stacks, t_moves *cmd, int i, int size)
{
	int	temp;
	int	diff;

	diff = 0;
	temp = 0;
	while (++i < size)
	{
		if (stacks.b[i] > cmd->num)
			temp = stacks.b[i] - cmd->num;
		else if (stacks.b[i] < cmd->num)
		{
			if (stacks.b[i] <= 0)
				temp = cmd->num + (stacks.b[i] * -1);
			else
				temp = cmd->num - stacks.b[i];
		}
		if (i == 0)
			diff = fuck_norm2(stacks, i, cmd, temp);
		else if (temp < diff)
			diff = fuck_norm2(stacks, i, cmd, temp);
	}
}

t_moves	place_to_put_nbr(t_stacks stacks, t_moves cmd, int size)
{
	int	i;

	i = -1;
	if (cmd.num > stacks.b[0] && cmd.num < stacks.b[size - 1])
		cmd.pos_b = 0;
	else
		check_diff(stacks, &cmd, i, size);
	if (cmd.pos_b > stacks.size_b / 2)
		cmd = set_b(cmd, 0, size - cmd.pos_b);
	else if (cmd.pos_b <= stacks.size_b / 2)
		cmd = set_b(cmd, cmd.pos_b, 0);
	return (cmd);
}

t_moves	get_cmds(t_stacks stacks, t_moves cmd, int size)
{
	int	max;
	int	max_place;

	if (size > 1)
	{
		max = biggest_num(stacks.b, size);
		max_place = place_in_array(stacks.b, max);
		if ((is_lowest_array(cmd.num, stacks.b, size) || cmd.num > max))
		{
			if (max_place == 0)
				set_b(cmd, 0, 0);
			else if (max_place == size - 1 && cmd.num > max)
				cmd = set_b(cmd, 0, 1);
			else if (max_place > stacks.size_b / 2)
				cmd = set_b(cmd, 0, size - max_place);
			else if (max_place <= stacks.size_b / 2)
				cmd = set_b(cmd, max_place, 0);
		}
		else
			cmd = place_to_put_nbr(stacks, cmd, stacks.size_b);
		cmd.total = 0;
	}
	return (cmd);
}
