/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimartin <rimartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 02:20:12 by ricardo           #+#    #+#             */
/*   Updated: 2021/09/11 11:45:09 by rimartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stacks	rrr_funct(t_stacks stacks, int opt)
{
	stacks = rra_funct(stacks, 0);
	stacks = rrb_funct(stacks, 0);
	if (opt)
		write(1, "rrr\n", 4);
	return (stacks);
}

t_stacks	sa_funct(t_stacks stacks, int option)
{
	int	temp;

	if (!stacks.a)
		perror("\n\tIN SA: stacks stack A esta vazio\n");
	temp = stacks.a[0];
	stacks.a[0] = stacks.a[1];
	stacks.a[1] = temp;
	if (option)
		write(1, "sa\n", 3);
	return (stacks);
}

t_stacks	sb_funct(t_stacks stacks, int option)
{
	int	x;
	int	temp;

	if (!stacks.b)
		perror("\n\tIN SB: stacks stack B esta vazio\n");
	x = 0;
	temp = stacks.b[x];
	stacks.b[x] = stacks.b[x + 1];
	stacks.b[x + 1] = temp;
	if (option)
		write(1, "sb\n", 3);
	return (stacks);
}

t_stacks	ss_funct(t_stacks stacks)
{
	stacks = sa_funct(stacks, 0);
	stacks = sb_funct(stacks, 0);
	write(1, "ss\n", 3);
	return (stacks);
}
