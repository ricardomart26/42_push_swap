/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easy_one.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricardo <ricardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 00:44:51 by ricardo           #+#    #+#             */
/*   Updated: 2021/08/30 01:01:00 by ricardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

t_stacks	push_bigger_to_end(t_stacks main, int max_place, int size)
{
	if (max_place > main.sizeA / 2)
	{
		while (max_place++ < size - 1)
		{
			if (main.A[0] > main.A[1])
				main = sa_funct(main, 0);
			main = rra_funct(main, 0);
		}
	}
	else
	{
		while (max_place-- > -1)
			main = ra_funct(main, 0);
		if (main.A[0] > main.A[1])
			main = sa_funct(main, 0);
	}
	return (main);
}

int	check_stackA(t_stacks main, int size)
{
	int	max;
	int	max_place;
	int	i;

	i = -1;
	max = biggest_num(main.A, size);
	max_place = place_in_array(main.A, max);
	if (is_correct(main.A, main.sizeA))
		return (1);
	else if (max_place != size)
	{
		main = push_bigger_to_end(main, max_place, size);
		if (is_correct(main.A, main.sizeA))
			return (1);
	}
	return (0);
}

t_stacks	check_stackA_real(t_stacks main, int size)
{
	int	max;
	int	max_place;
	int	i;

	i = -1;
	max = biggest_num(main.A, size);
	max_place = place_in_array(main.A, max);
	if (is_correct(main.A, main.sizeA))
		return (main);
	else if (max_place != size)
	{
		main = push_bigger_to_end(main, max_place, size);
		if (is_correct(main.A, main.sizeA))
			return (main);
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
		if (main.sizeA > 20)
			attr_chunks(&main, org, 11);
		else
			attr_chunks(&main, org, 2);
		main = push_chunk_to_b(main);
		free2(&org, &main.chunks);
	}
	if (!is_correct_B(main.B, main.sizeB))
		cmd = B_correct(&main, main.sizeB);
	main = last3_A(main);
	main = fuck_norm3(main);
	while (main.B[0] < main.A[0] && main.sizeB != 0)
		main = pa_funct(main, 1);
	free_all_stacks_t(&main, main.sizeB);
}
