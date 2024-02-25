/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   not_so_easy_one.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimartin <rimartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 17:48:55 by rimartin          #+#    #+#             */
/*   Updated: 2021/09/10 17:55:52 by rimartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	not_so_easy_one(t_stacks stacks)
{
	int		*org;
	t_moves	cmd;

	init_cmd(&cmd);
	while (stacks.size_a != 3)
	{
		org = organize_array(stacks.a, stacks.size_a - 1);
		init_stacks_loop(&stacks, org);
		if (stacks.size_a > 100)
			attr_chunks(&stacks, org, 11);
		if (stacks.size_a > 20)
			attr_chunks(&stacks, org, 6);
		else
			attr_chunks(&stacks, org, 2);
		stacks = push_chunk_to_b(stacks);
		free2(&org, &stacks.chunks);
	}
	if (!is_correct_b(stacks.b, stacks.size_b))
		cmd = b_correct(&stacks, stacks.size_b);
	stacks = last3_a(stacks);
	stacks = fuck_norm3(stacks);
	while (stacks.b[0] < stacks.a[0] && stacks.size_b != 0)
		stacks = pa_funct(stacks, 1);
	free_all_stacks_t(&stacks, stacks.size_b);
}
