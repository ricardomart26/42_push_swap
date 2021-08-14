/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricardo <ricardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 01:26:34 by ricardo           #+#    #+#             */
/*   Updated: 2021/08/12 01:27:46 by ricardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	closer_to_beg(t_stacks main, int *chunk, int size, t_moves *cmd)
{
	int	i;
	int	x;

	i = 0;
	while (size + 1)
	{
		x = 0;
		while (main.A[i] != chunk[x] && x < main.size_chunk + 1)
			x++;
		if (x == main.size_chunk + 1)
			i++;
		else
		{
			cmd->ra = i;
			cmd->rra = 0;
			cmd->num = main.A[i];
			break ;
		}
		size--;
	}
	if (size == 0)
		return (-1);
	return (1);
}

int	closer_to_end(t_stacks main, int *chunk, t_moves *cmd)
{
	int	size;
	int	x;

	size = main.sizeA - 1;
	while (size + 1)
	{
		x = 0;
		while (main.A[size] != chunk[x] && x < main.size_chunk + 1)
			x++;
		if (x == main.size_chunk + 1)
			size--;
		else
		{
			cmd->rra = main.sizeA - size;
			cmd->ra = 0;
			cmd->num = main.A[size];
			return (size);
		}
	}
	return (-1);
}
