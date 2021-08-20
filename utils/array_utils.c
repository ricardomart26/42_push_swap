/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricardo <ricardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 01:26:23 by ricardo           #+#    #+#             */
/*   Updated: 2021/08/12 01:27:34 by ricardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_lowest_array(int x, int *array, int size)
{
	int	i;

	i = 0;
	while (array[i] >= x && i < size)
		i++;
	if (i == size)
		return (1);
	else
		return (0);
}

int	place_in_array(int *stack, int num)
{
	int	i;

	i = 0;
	while (stack[i] != num)
		i++;
	return (i);
}

int	biggest_num(int *stack, int size)
{
	int	i;
	int	temp;

	i = 0;
	temp = stack[i];
	if (size == 2)
	{
		if (stack[i] > stack[i + 1])
			return (stack[i]);
		else
			return (stack[i + 1]);
	}
	while (i < size - 1)
	{
		while (temp > stack[i] && i < size - 1)
			i++;
		if (temp < stack[i])
			temp = stack[i];
		i++;
	}
	return (temp);
}

int	lowest_num(int *stack, int size)
{
	int	i;
	int	temp;

	i = 0;
	temp = stack[i];
	if (size == 2)
	{
		if (stack[i] < stack[i + 1])
			return (stack[i]);
		else
			return (stack[i + 1]);
	}
	while (i < size)
	{
		while (temp <= stack[i] && i < size)
			i++;
		if (temp > stack[i] && i != size)
			temp = stack[i];
		i++;
	}
	return (temp);
}

int	search_in_chunk(t_stacks temp, int *chunk, int sizeA)
{
	int	ret;
	int	i;
	int	x;

	i = 0;
	ret = 0;
	while (i < sizeA && ret < 3)
	{
		x = 0;
		while (temp.A[i] != chunk[x] && x < temp.size_chunk + 1)
			x++;
		if (x != temp.size_chunk + 1)
			ret++;
		i++;
	}
	return (ret);
}
