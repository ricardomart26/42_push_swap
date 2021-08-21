/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sim_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricardo <ricardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 01:03:42 by ricardo           #+#    #+#             */
/*   Updated: 2021/08/21 06:44:58 by ricardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	num1(t_stacks **temp, t_moves cmd)
{
	if (cmd.rr && !cmd.ra && !cmd.rb)
	{
		// printf("b1 1\n");
		// print_stacks(**temp);
		// sleep(2);
		**temp = gen_moves_real(**temp, 4, cmd.rr, 1);
		// printf("a1 1\n");
		// print_stacks(**temp);
		// sleep(2);
		return (cmd.rr + PB);
	}
	else if (cmd.rr)
	{
		// printf("b1 2\n");
		// print_stacks(**temp);
		// sleep(2);
		**temp = gen_moves_real(**temp, 4, cmd.rr, 0);
		**temp = gen_moves_real(**temp, 0, cmd.ra, 0);
		**temp = gen_moves_real(**temp, 2, cmd.rb, 0);
		**temp = gen_moves_real(**temp, 3, cmd.rrb, 1);
		// printf("a1 2\n");
		// print_stacks(**temp);
		// sleep(2);
		return (cmd.rr + cmd.ra + cmd.rb + cmd.rrb + PB);
	}
	else if (!cmd.rr)
	{
		// printf("b1 3\n");
		// print_stacks(**temp);
		// sleep(2);
		**temp = gen_moves_real(**temp, 0, cmd.ra, 0);
		**temp = gen_moves_real(**temp, 2, cmd.rb, 0);
		**temp = gen_moves_real(**temp, 3, cmd.rrb, 0);
		**temp = pb_funct(**temp, 1);
		// printf("a1 3\n");
		// print_stacks(**temp);
		// sleep(2);
		return (cmd.ra + cmd.rb + cmd.rrb + PB);
	}
	return (0);
}

int	num2(t_stacks **temp, t_moves cmd)
{
	if (cmd.rrr && !cmd.rra && !cmd.rrb)
	{
		// printf("b2 1\n");
		// print_stacks(**temp);
		// sleep(2);
		**temp = gen_moves_real(**temp, 5, cmd.rrr, 1);
		// printf("a2 1\n");
		// print_stacks(**temp);
		// sleep(2);
		return (cmd.rrr + PB);
	}
	else if (cmd.rrr)
	{
		// printf("b2 2\n");
		// print_stacks(**temp);
		// sleep(2);
		**temp = gen_moves_real(**temp, 5, cmd.rrr, 0);
		**temp = gen_moves_real(**temp, 1, cmd.rra, 0);
		**temp = gen_moves_real(**temp, 3, cmd.rrb, 0);
		**temp = gen_moves_real(**temp, 2, cmd.rb, 1);
		// printf("a2 2\n");
		// print_stacks(**temp);
		// sleep(2);
		return (cmd.rrr + cmd.rra + cmd.rb + cmd.rrb + PB);
	}
	else if (!cmd.rrr)
	{
		// printf("b2 3\n");
		// print_stacks(**temp);
		// sleep(2);
		**temp = gen_moves_real(**temp, 1, cmd.rra, 0);
		**temp = gen_moves_real(**temp, 2, cmd.rb, 0);
		**temp = gen_moves_real(**temp, 3, cmd.rrb, 1);
		// printf("a2 3\n");
		// print_stacks(**temp);
		// sleep(2);
		return (cmd.rra + cmd.rb + cmd.rrb + PB);
	}
	return (0);
}

int	num1_fake(t_stacks **temp, t_moves cmd)
{
	if (cmd.rr && !cmd.ra && !cmd.rb)
	{
		**temp = gen_moves_fake(**temp, 4, cmd.rr, 1);
		return (cmd.rr + PB);
	}
	else if (cmd.rr)
	{
		**temp = gen_moves_fake(**temp, 4, cmd.rr, 0);
		**temp = gen_moves_fake(**temp, 0, cmd.ra, 0);
		**temp = gen_moves_fake(**temp, 2, cmd.rb, 0);
		**temp = gen_moves_fake(**temp, 3, cmd.rrb, 1);
		return (cmd.rr + cmd.ra + cmd.rb + cmd.rrb + PB);
	}
	else if (!cmd.rr)
	{
		**temp = gen_moves_fake(**temp, 0, cmd.ra, 0);
		**temp = gen_moves_fake(**temp, 2, cmd.rb, 0);
		**temp = gen_moves_fake(**temp, 3, cmd.rrb, 1);
		return (cmd.ra + cmd.rb + cmd.rrb + PB);
	}
	return (0);
}

int	num2_fake(t_stacks **temp, t_moves cmd)
{
	if (cmd.rrr && !cmd.rra && !cmd.rrb)
	{
		**temp = gen_moves_fake(**temp, 5, cmd.rrr, 1);
		return (cmd.rrr + PB);
	}
	else if (cmd.rrr)
	{
		**temp = gen_moves_fake(**temp, 5, cmd.rrr, 0);
		**temp = gen_moves_fake(**temp, 1, cmd.rra, 0);
		**temp = gen_moves_fake(**temp, 3, cmd.rrb, 0);
		**temp = gen_moves_fake(**temp, 2, cmd.rb, 1);
		return (cmd.rrr + cmd.rra + cmd.rb + cmd.rrb + PB);
	}
	else if (!cmd.rrr)
	{
		**temp = gen_moves_fake(**temp, 1, cmd.rra, 0);
		**temp = gen_moves_fake(**temp, 2, cmd.rb, 0);
		**temp = gen_moves_fake(**temp, 3, cmd.rrb, 1);
		return (cmd.rra + cmd.rb + cmd.rrb + PB);
	}
	return (0);
}
