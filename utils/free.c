/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricardo <ricardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 01:19:44 by ricardo           #+#    #+#             */
/*   Updated: 2021/08/21 05:04:22 by ricardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	error_mes(t_stacks *main)
{
	free_all_stacks_t(main, main->sizeB);
	write(2, "Error\n", 7);
	exit(0);
}

void	free_all_stacks_t(t_stacks *main, int sizeB)
{
	if (main->sizeA)
	{
		free(main->A);
		main->A = NULL;
	}
	if (sizeB)
	{
		free(main->B);
		main->B = NULL;
	}
}
