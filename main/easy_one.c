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

stacks_t	push_chunk_to_b(stacks_t main, int *chunks)
{
	int	counter;
	int	option;

	counter = 0;
	while (counter <= main.size_chunk + 1)
	{
		option = 0;
		option = check_four_opt(main, chunks);
		if (option == -1)
			break ;
		main = do_opt(main, chunks, option);
		if (main.sizeA == 3)
			break ;
		counter += 2;
	}
	return (main);
}

moves_t	B_correct(stacks_t *main, int size)
{
	int		max;
	int		max_place;
	moves_t	cmd;

	init_cmd(&cmd);
	max = biggest_num(main->B, size);
	max_place = place_in_array(main->B, max);
	if (max_place <= size / 2)
	{
		*main = gen_moves_fake(*main, 3, size - max_place, 0);
		cmd.rrb = size - max_place;
	}
	else if (max_place > size / 2)
	{
		*main = gen_moves_fake(*main, 2, max_place, 0);
		cmd.rb = max_place;
	}
	return (cmd);
}

void	organize4_A(stacks_t *main)
{
	int	lower;
	int	lower_pos;

	lower = lowest_num(main->A, main->sizeA);
	lower_pos = place_in_array(main->A, lower);
	if (lower_pos == 0 && main->A[1] < main->A[2])
	{
		*main = ra_funct(*main, 1);
		*main = pa_funct(*main, 1);
		*main = rra_funct(*main, 1);
	}
	if (lower_pos == 2 && main->A[0] > main->A[1])
	{
		*main = sa_funct(*main, 1);
		while (main->A[main->sizeA - 1] < main->B[0])
			*main = pa_funct(*main, 1);
	}
	else if (lower_pos == 2 && main->A[0] < main->A[1])
	{
		*main = pa_funct(*main, 1);
		*main = rra_funct(*main, 1);
	}
}

stacks_t	last3_A(stacks_t main)
{
	if (!is_lowest_array(main.B[0], main.A, main.sizeA))
		organize4_A(&main);
	if (!is_correct(main.A, 3))
	{
		if (main.A[0] > main.A[1] && main.A[1] < main.A[2])
			main = ra_funct(main, 1);
		if (main.A[0] > main.A[1])
			main = sa_funct(main, 1);
		if (is_lowest_array(main.A[3], main.A, main.sizeA))
			main = rra_funct(main, 1);
		while (!is_lowest_array(main.A[0], main.A, main.sizeA))
			main = ra_funct(main, 1);
	}
	return (main);
}

stacks_t	do_easy_one(stacks_t main)
{
	int		*chunks;
	int		*org;
	moves_t	cmd;

	init_cmd(&cmd);
	while (main.sizeA != 3)
	{
		org = organize_array(main.A, main.sizeA - 1);
		init_main_loop(&main, org);
		 if (main.sizeA > 100)
			main.size_chunk = get_attr_chunks(&chunks, main.sizeA, org, 11);
		if (main.sizeA > 20)
			main.size_chunk = get_attr_chunks(&chunks, main.sizeA, org, 6);
		else
			main.size_chunk = get_attr_chunks(&chunks, main.sizeA, org, 2);
		main = push_chunk_to_b(main, chunks);
	}
	cmd = B_correct(&main, main.sizeB);
	main = last3_A(main);
	while (main.B[0] < main.A[0] && main.sizeB != 0)
		main = pa_funct(main, 1);
	print_stacks(main);
	return (main);
}
