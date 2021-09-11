/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimartin <rimartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 01:17:26 by ricardo           #+#    #+#             */
/*   Updated: 2021/09/11 11:37:02 by rimartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_valid(t_stacks main)
{
	int	x;
	int	i;

	x = 0;
	if (is_correct(main.a, main.size_a))
		return (2);
	while (main.a[x])
	{
		i = x + 1;
		while (main.a[i])
		{
			if (main.a[x] == main.a[i])
				error_mes(&main);
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

int	is_correct_b(int *b, int size)
{
	int	i;

	i = 0;
	while (size + 1)
	{
		if (b[i] > b[i + 1])
			i++;
		else
			return (0);
		size--;
	}
	return (1);
}
