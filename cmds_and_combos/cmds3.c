/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricardo <ricardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 02:20:12 by ricardo           #+#    #+#             */
/*   Updated: 2021/08/12 02:22:45 by ricardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stacks	rrr_funct(t_stacks main, int opt)
{
	main = rra_funct(main, 0);
	main = rrb_funct(main, 0);
	if (opt)
		write(1, "rrr\n", 4);
	return (main);
}

t_stacks	sa_funct(t_stacks main, int option)
{
	int	temp;

	if (!main.A)
		perror("\n\tIN SA: main stack A esta vazio\n");
	temp = main.A[0];
	main.A[0] = main.A[1];
	main.A[1] = temp;
	if (option)
		write(1, "sa\n", 3);
	return (main);
}

t_stacks	sb_funct(t_stacks main, int option)
{
	int	x;
	int	temp;

	if (!main.B)
		perror("\n\tIN SB: main stack B esta vazio\n");
	x = 0;
	temp = main.B[x];
	main.B[x] = main.B[x + 1];
	main.B[x + 1] = temp;
	if (option)
		write(1, "sb\n", 3);
	return (main);
}

t_stacks	ss_funct(t_stacks main)
{
	main = sa_funct(main, 0);
	main = sb_funct(main, 0);
	write(1, "ss\n", 3);
	return (main);
}
