/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimartin <rimartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 02:20:18 by ricardo           #+#    #+#             */
/*   Updated: 2021/09/11 11:44:41 by rimartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stacks	ra_funct(t_stacks stacks, int option)
{
	int	size;
	int	x;
	int	temp;

	temp = stacks.a[0];
	x = 0;
	size = stacks.size_a - 1;
	while (size--)
	{
		stacks.a[x] = stacks.a[x + 1];
		x++;
	}
	stacks.a[x] = temp;
	if (option)
		write(1, "ra\n", 3);
	return (stacks);
}

t_stacks	rb_funct(t_stacks stacks, int option)
{
	int	size;
	int	x;
	int	temp;

	temp = stacks.b[0];
	x = 0;
	size = stacks.size_b - 1;
	while (size--)
	{
		stacks.b[x] = stacks.b[x + 1];
		x++;
	}
	stacks.b[x] = temp;
	if (option)
		write(1, "rb\n", 3);
	return (stacks);
}

t_stacks	rr_funct(t_stacks stacks, int opt)
{
	stacks = ra_funct(stacks, 0);
	stacks = rb_funct(stacks, 0);
	if (opt)
		write(1, "rr\n", 3);
	return (stacks);
}

t_stacks	rra_funct(t_stacks stacks, int option)
{
	int	size;
	int	last;

	last = stacks.a[stacks.size_a - 1];
	size = stacks.size_a;
	while (size--)
		stacks.a[size] = stacks.a[size - 1];
	stacks.a[0] = last;
	if (option)
		write(1, "rra\n", 4);
	return (stacks);
}

t_stacks	rrb_funct(t_stacks stacks, int option)
{
	int	size;
	int	last;

	last = stacks.b[stacks.size_b - 1];
	size = stacks.size_b;
	while (size--)
		stacks.b[size] = stacks.b[size - 1];
	stacks.b[0] = last;
	if (option)
		write(1, "rrb\n", 4);
	return (stacks);
}
