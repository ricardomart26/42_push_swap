/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmds.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricardo <ricardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 02:20:06 by ricardo           #+#    #+#             */
/*   Updated: 2021/08/12 02:54:02 by ricardo          ###   ########.fr       */
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

int	fuck_norm2(t_stacks main, int i, t_moves *cmd)
{
	if (main.B[i] > cmd->num)
		cmd->pos_B = i + 1;
	else if (main.B[i] < cmd->num)
		cmd->pos_B = i;
	return (cmd->pos_B);
}

void	check_diff(t_stacks main, t_moves *cmd, int i, int size)
{
	int	temp;
	int	diff;

	diff = 0;
	temp = 0;
	while (++i < size)
	{
		if (main.B[i] > cmd->num)
			temp = main.B[i] - cmd->num;
		else if (main.B[i] < cmd->num)
		{
			if (main.B[i] <= 0)
				temp = cmd->num + (main.B[i] * -1);
			else
				temp = cmd->num - main.B[i];
		}
		if (i == 0)
		{
			diff = temp;
			cmd->pos_B = fuck_norm2(main, i, cmd);
		}
		else if (temp < diff)
		{
			diff = temp;
			cmd->pos_B = fuck_norm2(main, i, cmd);
		}
	}
}

t_moves	place_to_put_nbr(t_stacks main, t_moves cmd, int size)
{
	int	i;

	i = -1;
	if (cmd.num > main.B[0] && cmd.num < main.B[size - 1])
		cmd.pos_B = 0;
	else
		check_diff(main, &cmd, i, size);
	if (cmd.pos_B > main.sizeB / 2)
		cmd = set_b(cmd, 0, size - cmd.pos_B);
	else if (cmd.pos_B <= main.sizeB / 2)
		cmd = set_b(cmd, cmd.pos_B, 0);
	return (cmd);
}

t_moves	get_cmds(t_stacks main, t_moves cmd, int size)
{
	int	max;
	int	max_place;

	if (size > 1)
	{
		max = biggest_num(main.B, size);
		max_place = place_in_array(main.B, max);
		if ((is_lowest_array(cmd.num, main.B, size) || cmd.num > max))
		{
			if (max_place == 0)
				set_b(cmd, 0, 0);
			else if (max_place == size - 1 && cmd.num > max)
				cmd = set_b(cmd, 0, 1);
			else if (max_place > main.sizeB / 2)
				cmd = set_b(cmd, 0, size - max_place);
			else if (max_place <= main.sizeB / 2)
				cmd = set_b(cmd, max_place, 0);
		}
		else
			cmd = place_to_put_nbr(main, cmd, main.sizeB);
		cmd.total = 0;
	}
	return (cmd);
}
