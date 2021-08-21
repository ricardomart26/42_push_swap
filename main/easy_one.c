/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easy_one.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricardo <ricardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 00:44:51 by ricardo           #+#    #+#             */
/*   Updated: 2021/08/21 19:17:23 by ricardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	treat_error(t_stacks *main)
{
	int	max;

	max = biggest_num(main->B, main->sizeB);
	if (main->B[0] < main->B[1] && main->B[1] != max)
		*main = sb_funct(*main, 1);
}

t_stacks	push_chunk_to_b(t_stacks main)
{
	int	counter;
	int	option;

	counter = 0;
	while (counter <= main.size_chunk + 1)
	{
		option = 0;
		option = check_four_opt(main, main.chunks);
		if (option == -1)
			break ;
		main = do_opt(main, main.chunks, option);
		if (main.sizeA == 3)
			break ;
		counter += 2;
	}
	return (main);
}

void	do_easy_one(t_stacks main)
{
	int		*org;
	t_moves	cmd;

	init_cmd(&cmd);
	while (main.sizeA != 3)
	{
		org = organize_array(main.A, main.sizeA - 1);
		init_main_loop(&main, org);
		if (main.sizeA >= 50)
			attr_chunks(&main, org, 11);
		else if (main.sizeA > 20)
			attr_chunks(&main, org, 4);
		else
			attr_chunks(&main, org, 2);
		main = push_chunk_to_b(main);
		free2(&org, &main.chunks);
	}
	cmd = B_correct(&main, main.sizeB);
	main = last3_A(main);
	while (main.B[0] < main.A[0] && main.sizeB != 0)
		main = pa_funct(main, 1);
	free_all_stacks_t(&main, main.sizeB);
}
