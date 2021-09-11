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

t_stacks	fuck_norm3(t_stacks main)
{
	if (main.b[0] > main.a[0])
	{
		main = ra_funct(main, 1);
		main = pa_funct(main, 1);
		main = rra_funct(main, 1);
	}
	return (main);
}

t_moves	b_correct(t_stacks *main, int size)
{
	int		max;
	int		max_place;
	t_moves	cmd;

	init_cmd(&cmd);
	max = biggest_num(main->b, size);
	max_place = place_in_array(main->b, max);
	if (max_place <= size / 2)
	{
		*main = gen_moves_real(*main, 3, size - max_place, 0);
		cmd.rrb = size - max_place;
	}
	else if (max_place > size / 2)
	{
		*main = gen_moves_real(*main, 2, max_place, 0);
		cmd.rb = max_place;
	}
	return (cmd);
}

void	organize4_a(t_stacks *main)
{
	int	lower;
	int	lower_pos;

	lower = lowest_num(main->a, main->size_a);
	lower_pos = place_in_array(main->a, lower);
	if (lower_pos == 0 && main->a[1] < main->a[2])
		*main = fuck_norm3(*main);
	if (lower_pos == 2 && main->a[0] > main->a[1])
	{
		*main = sa_funct(*main, 1);
		while (main->a[main->size_a - 1] < main->b[0])
			*main = pa_funct(*main, 1);
	}
	else if (lower_pos == 2 && main->a[0] < main->a[1])
	{
		*main = pa_funct(*main, 1);
		*main = rra_funct(*main, 1);
	}
}

t_stacks	last3_a(t_stacks main)
{
	if (!is_lowest_array(main.b[0], main.a, main.size_a))
		organize4_a(&main);
	if (!is_correct(main.a, 3))
		main = do_only3(main);
	return (main);
}
