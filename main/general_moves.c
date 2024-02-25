/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricardo <ricardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 01:11:23 by ricardo           #+#    #+#             */
/*   Updated: 2021/08/21 04:16:13 by ricardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stacks	gen_moves_fake(t_stacks stacks, int option, int counter, int pb_pa)
{
	while (counter)
	{
		if (option == 0)
			stacks = ra_funct(stacks, 0);
		if (option == 1)
			stacks = rra_funct(stacks, 0);
		if (option == 2)
			stacks = rb_funct(stacks, 0);
		if (option == 3)
			stacks = rrb_funct(stacks, 0);
		if (option == 4)
			stacks = rr_funct(stacks, 0);
		if (option == 5)
			stacks = rrr_funct(stacks, 0);
		counter--;
	}	
	if (pb_pa == 1)
		stacks = pb_funct(stacks, 0);
	else if (pb_pa == 2)
		stacks = pa_funct(stacks, 0);
	return (stacks);
}

t_stacks	gen_moves_real(t_stacks stacks, int option, int counter, int pb_pa)
{
	while (counter)
	{
		if (option == 0)
			stacks = ra_funct(stacks, 1);
		if (option == 1)
			stacks = rra_funct(stacks, 1);
		if (option == 2)
			stacks = rb_funct(stacks, 1);
		if (option == 3)
			stacks = rrb_funct(stacks, 1);
		if (option == 4)
			stacks = rr_funct(stacks, 1);
		if (option == 5)
			stacks = rrr_funct(stacks, 1);
		counter--;
	}
	if (pb_pa == 1)
		stacks = pb_funct(stacks, 1);
	else if (pb_pa == 2)
		stacks = pa_funct(stacks, 1);
	return (stacks);
}
