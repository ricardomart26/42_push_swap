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

t_stacks	push_chunk_to_b(t_stacks stacks)
{
	int	counter;
	int	option;

	counter = 0;
	while (counter <= stacks.size_chunk + 1)
	{
		option = 0;
		option = check_four_opt(stacks, stacks.chunks);
		if (option == -1)
			break ;
		stacks = do_opt(stacks, stacks.chunks, option);
		if (stacks.size_a == 3)
			break ;
		counter += 2;
	}
	return (stacks);
}

t_stacks	push_bigger_to_end(t_stacks stacks, int max_place, int size)
{
	if (max_place > stacks.size_a / 2)
	{
		while (max_place++ < size - 1)
		{
			if (stacks.a[0] > stacks.a[1])
				stacks = sa_funct(stacks, 0);
			stacks = rra_funct(stacks, 0);
		}
	}
	else
	{
		while (max_place-- > -1)
			stacks = ra_funct(stacks, 0);
		if (stacks.a[0] > stacks.a[1])
			stacks = sa_funct(stacks, 0);
	}
	return (stacks);
}

int	check_stacka(t_stacks stacks, int size)
{
	int	max;
	int	max_place;

	max = biggest_num(stacks.a, size);
	max_place = place_in_array(stacks.a, max);
	if (is_correct(stacks.a, stacks.size_a))
		return (1);
	else if (max_place != size)
	{
		stacks = push_bigger_to_end(stacks, max_place, size);
		if (is_correct(stacks.a, stacks.size_a))
			return (1);
	}
	return (0);
}

t_stacks	check_stacka_real(t_stacks stacks, int size)
{
	int	max;
	int	max_place;

	max = biggest_num(stacks.a, size);
	max_place = place_in_array(stacks.a, max);
	if (is_correct(stacks.a, stacks.size_a))
		return (stacks);
	else if (max_place != size)
	{
		stacks = push_bigger_to_end(stacks, max_place, size);
		if (is_correct(stacks.a, stacks.size_a))
			return (stacks);
	}
	return (stacks);
}

void	do_easy_one(t_stacks stacks)
{
	int		*org;
	t_moves	cmd;

	init_cmd(&cmd);
	while (stacks.size_a != 3)
	{
		org = organize_array(stacks.a, stacks.size_a - 1);
		init_stacks_loop(&stacks, org);
		if (stacks.size_a > 20)
			attr_chunks(&stacks, org, 11);
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
