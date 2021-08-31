/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricardo <ricardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 01:17:26 by ricardo           #+#    #+#             */
/*   Updated: 2021/08/21 06:44:08 by ricardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_valid(t_stacks main)
{
	int	x;
	int	i;

	x = 0;
	if (is_correct(main.A, main.sizeA))
		return (2);
	while (main.A[x])
	{
		i = x + 1;
		while (main.A[i])
		{
			if (main.A[x] == main.A[i])
			{
				printf("dup %d\n", main.A[x]);
				error_mes(&main);
			}
			i++;
		}
		x++;
	}
	return (1);
}

int	ft_isntdigit(char c)
{
	if (c <= '9' && c >= '0')
		return (0);
	return (1);
}

int	is_correct(int *stack, int size)
{
	int	i;

	i = 0;
	while (i + 1 < size)
	{
		if (stack[i] < stack[i + 1])
			i++;
		else
			return (0);
	}
	return (1);
}

int	is_correct_B(int *B, int size)
{
	int	i;

	i = 0;
	while (size + 1)
	{
		if (B[i] > B[i + 1])
		{
			// printf("B[%d] %d >  B[%d] %d\n", i, B[i], i + 1, B[i + 1]);
			i++;
		}
		else
			return (0);
		size--;
	}
	return (1);
}
