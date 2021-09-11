/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easy_one.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimartin <rimartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 00:44:51 by ricardo           #+#    #+#             */
/*   Updated: 2021/09/10 17:56:09 by rimartin         ###   ########.fr       */
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
		if (main.size_a == 3)
			break ;
		counter += 2;
	}
	return (main);
}

t_stacks	push_bigger_to_end(t_stacks main, int max_place, int size)
{
	if (max_place > main.size_a / 2)
	{
		while (max_place++ < size - 1)
		{
			if (main.a[0] > main.a[1])
				main = sa_funct(main, 0);
			main = rra_funct(main, 0);
		}
	}
	else
	{
		while (max_place-- > -1)
			main = ra_funct(main, 0);
		if (main.a[0] > main.a[1])
			main = sa_funct(main, 0);
	}
	return (main);
}

int	check_stacka(t_stacks main, int size)
{
	int	max;
	int	max_place;
	int	i;

	i = -1;
	max = biggest_num(main.a, size);
	max_place = place_in_array(main.a, max);
	if (is_correct(main.a, main.size_a))
		return (1);
	else if (max_place != size)
	{
		main = push_bigger_to_end(main, max_place, size);
		if (is_correct(main.a, main.size_a))
			return (1);
	}
	return (0);
}

t_stacks	check_stacka_real(t_stacks main, int size)
{
	int	max;
	int	max_place;
	int	i;

	i = -1;
	max = biggest_num(main.a, size);
	max_place = place_in_array(main.a, max);
	if (is_correct(main.a, main.size_a))
		return (main);
	else if (max_place != size)
	{
		main = push_bigger_to_end(main, max_place, size);
		if (is_correct(main.a, main.size_a))
			return (main);
	}
	return (main);
}

void	do_easy_one(t_stacks main)
{
	int		*org;
	t_moves	cmd;

	init_cmd(&cmd);
	while (main.size_a != 3)
	{
		org = organize_array(main.a, main.size_a - 1);
		init_main_loop(&main, org);
		if (main.size_a > 20)
			attr_chunks(&main, org, 11);
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
