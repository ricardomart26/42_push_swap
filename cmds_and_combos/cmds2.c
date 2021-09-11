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

t_stacks	ra_funct(t_stacks main, int option)
{
	int	size;
	int	x;
	int	temp;

	temp = main.a[0];
	x = 0;
	size = main.size_a - 1;
	while (size--)
	{
		main.a[x] = main.a[x + 1];
		x++;
	}
	main.a[x] = temp;
	if (option)
		write(1, "ra\n", 3);
	return (main);
}

t_stacks	rb_funct(t_stacks main, int option)
{
	int	size;
	int	x;
	int	temp;

	temp = main.b[0];
	x = 0;
	size = main.size_b - 1;
	while (size--)
	{
		main.b[x] = main.b[x + 1];
		x++;
	}
	main.b[x] = temp;
	if (option)
		write(1, "rb\n", 3);
	return (main);
}

t_stacks	rr_funct(t_stacks main, int opt)
{
	main = ra_funct(main, 0);
	main = rb_funct(main, 0);
	if (opt)
		write(1, "rr\n", 3);
	return (main);
}

t_stacks	rra_funct(t_stacks main, int option)
{
	int	size;
	int	last;

	last = main.a[main.size_a - 1];
	size = main.size_a;
	while (size--)
		main.a[size] = main.a[size - 1];
	main.a[0] = last;
	if (option)
		write(1, "rra\n", 4);
	return (main);
}

t_stacks	rrb_funct(t_stacks main, int option)
{
	int	size;
	int	last;

	last = main.b[main.size_b - 1];
	size = main.size_b;
	while (size--)
		main.b[size] = main.b[size - 1];
	main.b[0] = last;
	if (option)
		write(1, "rrb\n", 4);
	return (main);
}
