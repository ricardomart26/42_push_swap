/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricardo <ricardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 01:23:27 by ricardo           #+#    #+#             */
/*   Updated: 2021/08/12 01:33:01 by ricardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	print_array(int *stack, int size)
{
	int	i;

	i = 0;
	while (size + 1)
	{
		printf("\n\t%d print array %d", i, stack[i]);
		i++;
		size--;
	}
}

void	print_cmds(t_moves cmd)
{
	printf("\n\n\t************\n");
	printf("\t**  ra  = %d  **\n", cmd.ra);
	printf("\t**  rb  = %d  **\n", cmd.rb);
	printf("\t**  rr  = %d  **\n", cmd.rr);
	printf("\t**  rra  = %d **\n", cmd.rra);
	printf("\t**  rrb  = %d **\n", cmd.rrb);
	printf("\t**  rrr  = %d **\n", cmd.rrr);
	printf("\t**  pos B = %d **\n", cmd.pos_B);
	printf("\t**  num = %d **\n", cmd.num);
	printf("\t**  total = %d **\n", cmd.total);
	printf("\t****************\n");
}

void	print_stacks(t_stacks main)
{
	int	size;
	int	c;

	c = 0;
	if (main.sizeA > main.sizeB)
		size = main.sizeA;
	else
		size = main.sizeB;
	printf("\n\t************\n");
	printf("\t** A ** B **\n");
	printf("\t** %d ** %d **\n", main.sizeA, main.sizeB);
	printf("\t************\n");
	while (size--)
	{
		if (main.sizeA != 0 && main.sizeB != 0)
		{
			printf("\t** %d ** %d **\n", main.A[c], main.B[c]);
			main.sizeA--;
			main.sizeB--;
		}
		else if (main.sizeA != 0 && main.sizeB == 0)
		{
			printf("\t** %d **   **\n", main.A[c]);
			main.sizeA--;
		}
		else if (main.sizeA == 0 && main.sizeB != 0)
		{
			printf("\t**   ** %d **\n", main.B[c]);
			main.sizeB--;
		}
		c++;
	}
	printf("\t************\n");
	printf("\t************\n");
}
