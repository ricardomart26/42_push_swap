/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easy_one_final_funct.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimartin <rimartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 17:48:44 by rimartin          #+#    #+#             */
/*   Updated: 2021/09/11 11:36:09 by rimartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stacks	fuck_norm3(t_stacks stacks)
{
	if (stacks.b[0] > stacks.a[0])
	{
		stacks = ra_funct(stacks, 1);
		stacks = pa_funct(stacks, 1);
		stacks = rra_funct(stacks, 1);
	}
	return (stacks);
}

t_moves	b_correct(t_stacks *stacks, int size)
{
	int		max;
	int		max_place;
	t_moves	cmd;

	init_cmd(&cmd);
	max = biggest_num(stacks->b, size);
	max_place = place_in_array(stacks->b, max);
	if (max_place <= size / 2)
	{
		*stacks = gen_moves_real(*stacks, 3, size - max_place, 0);
		cmd.rrb = size - max_place;
	}
	else if (max_place > size / 2)
	{
		*stacks = gen_moves_real(*stacks, 2, max_place, 0);
		cmd.rb = max_place;
	}
	return (cmd);
}

void	organize4_a(t_stacks *stacks)
{
	int	lower;
	int	lower_pos;

	lower = lowest_num(stacks->a, stacks->size_a);
	lower_pos = place_in_array(stacks->a, lower);
	if (lower_pos == 0 && stacks->a[1] < stacks->a[2])
		*stacks = fuck_norm3(*stacks);
	if (lower_pos == 2 && stacks->a[0] > stacks->a[1])
	{
		*stacks = sa_funct(*stacks, 1);
		while (stacks->a[stacks->size_a - 1] < stacks->b[0])
			*stacks = pa_funct(*stacks, 1);
	}
	else if (lower_pos == 2 && stacks->a[0] < stacks->a[1])
	{
		*stacks = pa_funct(*stacks, 1);
		*stacks = rra_funct(*stacks, 1);
	}
}

t_stacks	last3_a(t_stacks stacks)
{
	if (!is_lowest_array(stacks.b[0], stacks.a, stacks.size_a))
		organize4_a(&stacks);
	if (!is_correct(stacks.a, 3))
		stacks = do_only3(stacks);
	return (stacks);
}
