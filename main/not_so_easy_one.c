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

void	not_so_easy_one(t_stacks main)
{
	int		*org;
	t_moves	cmd;

	init_cmd(&cmd);
	while (main.size_a != 3)
	{
		org = organize_array(main.a, main.size_a - 1);
		init_main_loop(&main, org);
		if (main.size_a > 100)
			attr_chunks(&main, org, 11);
		if (main.size_a > 20)
			attr_chunks(&main, org, 6);
		else
			attr_chunks(&main, org, 2);
		main = push_chunk_to_b(main);
		free2(&org, &main.chunks);
	}
	if (!is_correct_b(main.b, main.size_b))
		cmd = b_correct(&main, main.size_b);
	main = last3_a(main);
	main = fuck_norm3(main);
	while (main.b[0] < main.a[0] && main.size_b != 0)
		main = pa_funct(main, 1);
	free_all_stacks_t(&main, main.size_b);
}
