/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricardo <ricardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 01:27:03 by ricardo           #+#    #+#             */
/*   Updated: 2021/08/30 00:56:54 by ricardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	attr_chunks(t_stacks *main, int *org, int divisor)
{
	int	i;
	int	sizeA;

	sizeA = main->sizeA;
	sizeA /= divisor;
	main->chunks = (int *)ft_calloc(sizeA + 1, sizeof(int));
	main->alloc_chunks = true;
	i = 0;
	while (i < sizeA)
	{
		main->chunks[i] = *org;
		i++;
		org++;
	}
	main->chunks[i] = '\0';
	main->size_chunk = sizeA - 1;
}

void	init_main_loop(t_stacks *main, int *org)
{
	main->lowest = org[0];
	if (main->sizeA % 2 != 0)
		main->middle_size = main->sizeA / 2 + 1;
	else
		main->middle_size = main->sizeA / 2;
	main->alloc_chunks = false;
}

void	init_cmd(t_moves *cmd)
{
	cmd->num = 0;
	cmd->pos_B = 0;
	cmd->total = 0;
	cmd->ra = 0;
	cmd->rb = 0;
	cmd->rr = 0;
	cmd->rra = 0;
	cmd->rrb = 0;
	cmd->rrr = 0;
}

void	init_struct(t_stacks *main, int ac)
{
	main->ac = ac - 1;
	main->A = ft_calloc((ac), sizeof(int));
	if (!main->A)
		return ;
	main->sizeA = main->ac;
	main->sizeB = 0;
}
