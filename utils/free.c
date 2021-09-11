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

void	error_mes(t_stacks *main)
{
	free_all_stacks_t(main, main->size_b);
	write(2, "Error\n", 7);
	exit(0);
}

void	free_all_stacks_t(t_stacks *main, int size_b)
{
	if (main->size_a)
	{
		free(main->a);
		main->a = NULL;
	}
	if (size_b)
	{
		free(main->b);
		main->b = NULL;
	}
}
