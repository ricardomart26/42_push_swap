/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   organize_arr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimartin <rimartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 01:24:18 by ricardo           #+#    #+#             */
/*   Updated: 2021/09/10 17:58:20 by rimartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	fuck_norm(t_stacks *temp, t_stacks *stacks)
{
	temp->lowest = stacks->lowest;
	temp->size_chunk = stacks->size_chunk;
	temp->middle_size = stacks->middle_size;
	temp->size_a = stacks->size_a;
	temp->size_b = stacks->size_b;
}

t_stacks	pass_stacks_to_temp(t_stacks stacks)
{
	t_stacks	temp;
	int			x;

	temp.a = ft_calloc(stacks.size_a, sizeof(int));
	fuck_norm(&temp, &stacks);
	x = 0;
	while (stacks.size_a--)
	{
		temp.a[x] = stacks.a[x];
		x++;
	}
	x = 0;
	if (stacks.size_b != 0)
	{
		temp.b = ft_calloc(stacks.size_b, sizeof(int));
		while (stacks.size_b--)
		{
			temp.b[x] = stacks.b[x];
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
	org = ft_calloc(size, sizeof(int));
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
