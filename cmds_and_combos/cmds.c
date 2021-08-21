/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricardo <ricardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 02:20:23 by ricardo           #+#    #+#             */
/*   Updated: 2021/08/21 06:47:31 by ricardo          ###   ########.fr       */
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
		stack = realloc(stack, (sizeof(int) * size2) + 1);
	print_array(stack, size);
	while (size2--)
	{
		printf("stack %d\n", stack[x]);
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
	new_stack = realloc(stack, (*size * sizeof(int)) + 1);
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

	number = main.B[0];
	if (!main.B)
		perror("\n\tIN PB: main stack A esta vazio\n");
	if (main.sizeA == 0)
	{
		main.A = ft_calloc(1, sizeof(int) + 1);
		main.A[0] = number;
		main.B = organize_the_stack(main.B, main.sizeB, 0);
		main.sizeA++;
	}
	else
	{
		main.A = push_to_p(main.A, &main.sizeA, number);
		main.B = organize_the_stack(main.B, main.sizeB, 1);
	}
	main.sizeB--;
	if (main.sizeB == 0)
		free(main.B);
	if (opt)
		write(1, "pa\n", 4);
	return (main);
}

t_stacks	pb_funct(t_stacks main, int opt)
{
	int	number;

	number = main.A[0];
	if (!main.A)
		perror("\n\tIN PB: main stack A esta vazio\n");
	if (main.sizeB == 0)
	{
		main.B = ft_calloc(1, sizeof(int));
		main.B[0] = number;
		main.A = organize_the_stack(main.A, main.sizeA, 0);
		main.sizeB++;
	}
	else
	{
		main.B = push_to_p(main.B, &main.sizeB, number);
		main.A = organize_the_stack(main.A, main.sizeA, 1);
	}
	main.sizeA--;
	if (main.sizeA == 0)
		free(main.A);
	if (opt)
		write(1, "pb\n", 4);
	return (main);
}
