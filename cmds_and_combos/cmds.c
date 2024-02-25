/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimartin <rimartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 02:20:23 by ricardo           #+#    #+#             */
/*   Updated: 2021/09/11 11:44:04 by rimartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	*organize_the_stack(int *stack, int size, int opt)
{
	int	x;
	int	size2;

	size2 = size;
	x = 0;
	if (opt)
		stack = realloc(stack, (sizeof(int) * size2));
	while (size2--)
	{
		stack[x] = stack[x + 1];
		x++;
	}
	stack[x] = '\0';
	return (stack);
}

int	*push_to_p(int *stack, int *size, int number)
{
	int	temp_size;
	int	x;
	int	temp;
	int	temp2;
	int	*new_stack;

	x = 1;
	temp_size = *size;
	*size += 1;
	new_stack = realloc(stack, ((*size + 1) * sizeof(int)));
	stack = new_stack;
	temp = stack[0];
	stack[0] = number;
	while (temp_size--)
	{
		temp2 = stack[x];
		stack[x] = temp;
		temp = temp2;
		x++;
	}
	return (stack);
}

t_stacks	pa_funct(t_stacks stacks, int opt)
{
	int	number;

	number = stacks.b[0];
	if (!stacks.b)
		perror("\n\tIN PB: stacks stack A esta vazio\n");
	if (stacks.size_a == 0)
	{
		stacks.a = ft_calloc(1, sizeof(int));
		stacks.a[0] = number;
		stacks.b = organize_the_stack(stacks.b, stacks.size_b, 0);
		stacks.size_a++;
	}
	else
	{
		stacks.a = push_to_p(stacks.a, &stacks.size_a, number);
		stacks.b = organize_the_stack(stacks.b, stacks.size_b, 1);
	}
	stacks.size_b--;
	if (stacks.size_b == 0)
		free(stacks.b);
	if (opt)
		write(1, "pa\n", 3);
	return (stacks);
}

t_stacks	pb_funct(t_stacks stacks, int opt)
{
	int	number;

	number = stacks.a[0];
	if (!stacks.a)
		perror("\n\tIN PB: stacks stack A esta vazio\n");
	if (stacks.size_b == 0)
	{
		stacks.b = ft_calloc(1, sizeof(int));
		stacks.b[0] = number;
		stacks.a = organize_the_stack(stacks.a, stacks.size_a, 0);
		stacks.size_b++;
	}
	else
	{
		stacks.b = push_to_p(stacks.b, &stacks.size_b, number);
		stacks.a = organize_the_stack(stacks.a, stacks.size_a, 1);
	}
	stacks.size_a--;
	if (stacks.size_a == 0)
		free(stacks.a);
	if (opt)
		write(1, "pb\n", 3);
	return (stacks);
}
