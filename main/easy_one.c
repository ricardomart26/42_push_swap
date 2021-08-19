/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easy_one.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricardo <ricardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 00:44:51 by ricardo           #+#    #+#             */
/*   Updated: 2021/08/12 02:53:27 by ricardo          ###   ########.fr       */
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
		treat_error(&main);
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
			main.size_chunk = attr_chunks(&main.chunks, main.sizeA, org, 11);
		if (main.sizeA > 20)
			main.size_chunk = attr_chunks(&main.chunks, main.sizeA, org, 4);
		else
			main.size_chunk = attr_chunks(&main.chunks, main.sizeA, org, 2);
		main = push_chunk_to_b(main);
	}
	main.chunks = NULL;
	cmd = B_correct(&main, main.sizeB);
	main = last3_A(main);
	while (main.B[0] < main.A[0] && main.sizeB != 0)
		main = pa_funct(main, 1);
	free(main.A);
	main.A = NULL;
}
