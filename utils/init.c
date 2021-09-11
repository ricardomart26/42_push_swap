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

void	attr_chunks(t_stacks *main, int *org, int divisor)
{
	int	i;
	int	size_a;

	size_a = main->size_a;
	size_a /= divisor;
	main->chunks = (int *)ft_calloc(size_a, sizeof(int));
	main->alloc_chunks = true;
	i = 0;
	while (i < size_a)
	{
		main->chunks[i] = *org;
		i++;
		org++;
	}
	main->chunks[i] = '\0';
	main->size_chunk = size_a - 1;
}

void	init_main_loop(t_stacks *main, int *org)
{
	main->lowest = org[0];
	if (main->size_a % 2 != 0)
		main->middle_size = main->size_a / 2 + 1;
	else
		main->middle_size = main->size_a / 2;
	main->alloc_chunks = false;
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

void	init_struct(t_stacks *main, int ac)
{
	main->ac = ac - 1;
	main->a = ft_calloc((ac - 1), sizeof(int));
	if (!main->a)
		return ;
	main->size_a = main->ac;
	main->size_b = 0;
}
