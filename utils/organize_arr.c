/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   organize_arr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricardo <ricardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 01:24:18 by ricardo           #+#    #+#             */
/*   Updated: 2021/08/21 06:43:54 by ricardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	fuck_norm(t_stacks *temp, t_stacks *main)
{
	temp->lowest = main->lowest;
	temp->size_chunk = main->size_chunk;
	temp->middle_size = main->middle_size;
	temp->sizeA = main->sizeA;
	temp->sizeB = main->sizeB;
}

t_stacks	pass_stacks_to_temp(t_stacks main)
{
	t_stacks	temp;
	int			x;

	temp.A = ft_calloc(main.sizeA, sizeof(int));
	fuck_norm(&temp, &main);
	x = 0;
	while (main.sizeA--)
	{
		temp.A[x] = main.A[x];
		x++;
	}
	x = 0;
	if (main.sizeB != 0)
	{
		temp.B = ft_calloc(main.sizeB, sizeof(int));
		while (main.sizeB--)
		{
			temp.B[x] = main.B[x];
			x++;
		}
	}
	return (temp);
}

int	*organize_array(int *stack, int size)
{
	int	i;
	int	*org;

	i = -1;
	org = ft_calloc(size, sizeof(int) + 1);
	while (i++ <= size)
		org[i] = stack[i];
	i = 0;
	while (!is_correct(org, size))
	{
		if (i >= size)
			i = 0;
		while (org[i] < org[i + 1] && i < size)
			i++;
		if (i < size)
			org = ft_swap(org, i);
	}
	return (org);
}
