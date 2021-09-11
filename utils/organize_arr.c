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

void	fuck_norm(t_stacks *temp, t_stacks *main)
{
	temp->lowest = main->lowest;
	temp->size_chunk = main->size_chunk;
	temp->middle_size = main->middle_size;
	temp->size_a = main->size_a;
	temp->size_b = main->size_b;
}

t_stacks	pass_stacks_to_temp(t_stacks main)
{
	t_stacks	temp;
	int			x;

	temp.a = ft_calloc(main.size_a, sizeof(int));
	fuck_norm(&temp, &main);
	x = 0;
	while (main.size_a--)
	{
		temp.a[x] = main.a[x];
		x++;
	}
	x = 0;
	if (main.size_b != 0)
	{
		temp.b = ft_calloc(main.size_b, sizeof(int));
		while (main.size_b--)
		{
			temp.b[x] = main.b[x];
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
