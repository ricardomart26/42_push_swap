/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimartin <rimartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 01:26:34 by ricardo           #+#    #+#             */
/*   Updated: 2021/09/11 11:42:09 by rimartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	closer_to_beg(t_stacks stacks, int *chunk, int size, t_moves *cmd)
{
	int	i;
	int	x;

	i = 0;
	while (size + 1)
	{
		x = 0;
		while (stacks.a[i] != chunk[x] && x < stacks.size_chunk + 1)
			x++;
		if (x == stacks.size_chunk + 1)
			i++;
		else
		{
			cmd->ra = i;
			cmd->rra = 0;
			cmd->num = stacks.a[i];
			break ;
		}
		size--;
	}
	if (size == 0)
		return (-1);
	return (1);
}

int	closer_to_end(t_stacks stacks, int *chunk, t_moves *cmd)
{
	int	size;
	int	x;

	size = stacks.size_a - 1;
	while (size + 1)
	{
		x = 0;
		while (stacks.a[size] != chunk[x] && x < stacks.size_chunk + 1)
			x++;
		if (x == stacks.size_chunk + 1)
			size--;
		else
		{
			cmd->rra = stacks.size_a - size;
			cmd->ra = 0;
			cmd->num = stacks.a[size];
			return (size);
		}
	}
	return (-1);
}
