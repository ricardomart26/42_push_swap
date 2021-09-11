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

t_stacks	pa_funct(t_stacks main, int opt)
{
	int	number;

	number = main.b[0];
	if (!main.b)
		perror("\n\tIN PB: main stack A esta vazio\n");
	if (main.size_a == 0)
	{
		main.a = ft_calloc(1, sizeof(int));
		main.a[0] = number;
		main.b = organize_the_stack(main.b, main.size_b, 0);
		main.size_a++;
	}
	else
	{
		main.a = push_to_p(main.a, &main.size_a, number);
		main.b = organize_the_stack(main.b, main.size_b, 1);
	}
	main.size_b--;
	if (main.size_b == 0)
		free(main.b);
	if (opt)
		write(1, "pa\n", 3);
	return (main);
}

t_stacks	pb_funct(t_stacks main, int opt)
{
	int	number;

	number = main.a[0];
	if (!main.a)
		perror("\n\tIN PB: main stack A esta vazio\n");
	if (main.size_b == 0)
	{
		main.b = ft_calloc(1, sizeof(int));
		main.b[0] = number;
		main.a = organize_the_stack(main.a, main.size_a, 0);
		main.size_b++;
	}
	else
	{
		main.b = push_to_p(main.b, &main.size_b, number);
		main.a = organize_the_stack(main.a, main.size_a, 1);
	}
	main.size_a--;
	if (main.size_a == 0)
		free(main.a);
	if (opt)
		write(1, "pb\n", 3);
	return (main);
}
