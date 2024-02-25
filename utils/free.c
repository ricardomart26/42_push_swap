/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimartin <rimartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 01:19:44 by ricardo           #+#    #+#             */
/*   Updated: 2021/09/11 11:39:17 by rimartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	error_mes(t_stacks *stacks)
{
	free_all_stacks_t(stacks, stacks->size_b);
	write(2, "Error\n", 7);
	exit(0);
}

void	free_all_stacks_t(t_stacks *stacks, int size_b)
{
	if (stacks->size_a)
	{
		free(stacks->a);
		stacks->a = NULL;
	}
	if (size_b)
	{
		free(stacks->b);
		stacks->b = NULL;
	}
}
