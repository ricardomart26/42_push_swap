/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimartin <rimartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 01:27:03 by ricardo           #+#    #+#             */
/*   Updated: 2021/09/10 17:56:54 by rimartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	attr_chunks(t_stacks *stacks, int *org, int divisor)
{
	int	i;
	int	size_a;

	size_a = stacks->size_a;
	size_a /= divisor;
	stacks->chunks = (int *)ft_calloc(size_a, sizeof(int));
	stacks->alloc_chunks = true;
	i = 0;
	while (i < size_a)
	{
		stacks->chunks[i] = *org;
		i++;
		org++;
	}
	stacks->chunks[i] = '\0';
	stacks->size_chunk = size_a - 1;
}

void	init_stacks_loop(t_stacks *stacks, int *org)
{
	stacks->lowest = org[0];
	if (stacks->size_a % 2 != 0)
		stacks->middle_size = stacks->size_a / 2 + 1;
	else
		stacks->middle_size = stacks->size_a / 2;
	stacks->alloc_chunks = false;
}

void	init_cmd(t_moves *cmd)
{
	cmd->num = 0;
	cmd->pos_b = 0;
	cmd->total = 0;
	cmd->ra = 0;
	cmd->rb = 0;
	cmd->rr = 0;
	cmd->rra = 0;
	cmd->rrb = 0;
	cmd->rrr = 0;
}

void	init_struct(t_stacks *stacks, int ac)
{
	stacks->ac = ac - 1;
	stacks->a = ft_calloc((ac - 1), sizeof(int));
	if (!stacks->a)
		return ;
	stacks->size_a = stacks->ac;
	stacks->size_b = 0;
}
