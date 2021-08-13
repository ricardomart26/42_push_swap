/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sim_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricardo <ricardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 01:03:42 by ricardo           #+#    #+#             */
/*   Updated: 2021/08/12 01:14:24 by ricardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	num1(stacks_t **temp, moves_t cmd)
{
	if (cmd.rr && !cmd.ra && !cmd.rb)
	{
		**temp = gen_moves_real(**temp, 4, cmd.rr, 1);
		return (cmd.rr + pb);
	}
	else if (cmd.rr)
	{
		**temp = gen_moves_real(**temp, 4, cmd.rr, 0);
		**temp = gen_moves_real(**temp, 0, cmd.ra, 0);
		**temp = gen_moves_real(**temp, 2, cmd.rb, 0);
		**temp = gen_moves_real(**temp, 3, cmd.rrb, 1);
		return (cmd.rr + cmd.ra + cmd.rb + cmd.rrb + pb);
	}
	else if (!cmd.rr)
	{
		**temp = gen_moves_real(**temp, 0, cmd.ra, 0);
		**temp = gen_moves_real(**temp, 2, cmd.rb, 0);
		**temp = gen_moves_real(**temp, 3, cmd.rrb, 1);
		return (cmd.ra + cmd.rb + cmd.rrb + pb);
	}
	return (0);
}

int	num2(stacks_t **temp, moves_t cmd)
{
	if (cmd.rrr && !cmd.rra && !cmd.rrb)
	{
		**temp = gen_moves_real(**temp, 5, cmd.rrr, 1);
		return (cmd.rrr + pb);
	}
	else if (cmd.rrr)
	{
		**temp = gen_moves_real(**temp, 5, cmd.rrr, 0);
		**temp = gen_moves_real(**temp, 1, cmd.rra, 0);
		**temp = gen_moves_real(**temp, 3, cmd.rrb, 0);
		**temp = gen_moves_real(**temp, 2, cmd.rb, 1);
		return (cmd.rrr + cmd.rra + cmd.rb + cmd.rrb + pb);
	}
	else if (!cmd.rrr)
	{
		**temp = gen_moves_real(**temp, 1, cmd.rra, 0);
		**temp = gen_moves_real(**temp, 2, cmd.rb, 0);
		**temp = gen_moves_real(**temp, 3, cmd.rrb, 1);
		return (cmd.rra + cmd.rb + cmd.rrb + pb);
	}
	return (0);
}

int	num1_fake(stacks_t **temp, moves_t cmd)
{
	if (cmd.rr && !cmd.ra && !cmd.rb)
	{
		**temp = gen_moves_fake(**temp, 4, cmd.rr, 1);
		return (cmd.rr + pb);
	}
	else if (cmd.rr)
	{
		**temp = gen_moves_fake(**temp, 4, cmd.rr, 0);
		**temp = gen_moves_fake(**temp, 0, cmd.ra, 0);
		**temp = gen_moves_fake(**temp, 2, cmd.rb, 0);
		**temp = gen_moves_fake(**temp, 3, cmd.rrb, 1);
		return (cmd.rr + cmd.ra + cmd.rb + cmd.rrb + pb);
	}
	else if (!cmd.rr)
	{
		**temp = gen_moves_fake(**temp, 0, cmd.ra, 0);
		**temp = gen_moves_fake(**temp, 2, cmd.rb, 0);
		**temp = gen_moves_fake(**temp, 3, cmd.rrb, 1);
		return (cmd.ra + cmd.rb + cmd.rrb + pb);
	}
	return (0);
}

int	num2_fake(stacks_t **temp, moves_t cmd)
{
	if (cmd.rrr && !cmd.rra && !cmd.rrb)
	{
		**temp = gen_moves_fake(**temp, 5, cmd.rrr, 1);
		return (cmd.rrr + pb);
	}
	else if (cmd.rrr)
	{
		**temp = gen_moves_fake(**temp, 5, cmd.rrr, 0);
		**temp = gen_moves_fake(**temp, 1, cmd.rra, 0);
		**temp = gen_moves_fake(**temp, 3, cmd.rrb, 0);
		**temp = gen_moves_fake(**temp, 2, cmd.rb, 1);
		return (cmd.rrr + cmd.rra + cmd.rb + cmd.rrb + pb);
	}
	else if (!cmd.rrr)
	{
		**temp = gen_moves_fake(**temp, 1, cmd.rra, 0);
		**temp = gen_moves_fake(**temp, 2, cmd.rb, 0);
		**temp = gen_moves_fake(**temp, 3, cmd.rrb, 1);
		return (cmd.rra + cmd.rb + cmd.rrb + pb);
	}
	return (0);
}
