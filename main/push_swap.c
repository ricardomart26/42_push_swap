/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimartin <rimartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 00:45:32 by ricardo           #+#    #+#             */
/*   Updated: 2021/09/11 11:38:42 by rimartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	push_everything_to_b(t_stacks *stacks, int *org)
{
	while (stacks->size_a != 3)
	{
		stacks->lowest = *org;
		stacks->middle_size = stacks->size_a / 2;
		stacks->lowest_pos = find(*org, stacks->a);
		if (stacks->lowest_pos == 0)
			*stacks = pb_funct(*stacks, 1);
		else if (stacks->lowest_pos > stacks->middle_size && stacks->size_a != 0)
		{
			while (stacks->lowest_pos++ != stacks->size_a)
				*stacks = rra_funct(*stacks, 1);
			*stacks = pb_funct(*stacks, 1);
		}
		else if (stacks->lowest_pos <= stacks->middle_size && stacks->size_a != 0)
		{
			while (stacks->lowest_pos-- != 0)
				*stacks = ra_funct(*stacks, 1);
			*stacks = pb_funct(*stacks, 1);
		}
		org++;
	}
}

t_stacks	do_only3(t_stacks stacks)
{
	if (stacks.ac == 2)
		return (sa_funct(stacks, 1));
	else
	{
		if (stacks.a[0] > stacks.a[1] && stacks.a[1]
			< stacks.a[2] && stacks.a[0] < stacks.a[2])
			stacks = sa_funct(stacks, 1);
		else if (stacks.a[0] > stacks.a[1] && stacks.a[1]
			< stacks.a[2] && stacks.a[0] > stacks.a[2])
			stacks = ra_funct(stacks, 1);
		else if (stacks.a[0] > stacks.a[1] && stacks.a[1] > stacks.a[2])
		{
			stacks = sa_funct(stacks, 1);
			stacks = rra_funct(stacks, 1);
		}
		else if (stacks.a[0] < stacks.a[1] && stacks.a[1]
			> stacks.a[2] && stacks.a[0] > stacks.a[2])
			stacks = rra_funct(stacks, 1);
		else if (stacks.a[0] < stacks.a[1] && stacks.a[1] > stacks.a[2])
		{
			stacks = rra_funct(stacks, 1);
			stacks = sa_funct(stacks, 1);
		}
		return (stacks);
	}
}

void	peanuts(t_stacks stacks)
{
	int	*org;

	if (stacks.ac <= 3)
	{
		do_only3(stacks);
		free_all_stacks_t(&stacks, stacks.size_b);
		return ;
	}
	org = organize_array(stacks.a, stacks.size_a - 1);
	push_everything_to_b(&stacks, org);
	free(org);
	org = NULL;
	stacks = do_only3(stacks);
	while (stacks.size_b != 0)
		stacks = pa_funct(stacks, 1);
	free_all_stacks_t(&stacks, stacks.size_b);
}

t_stacks	get_av(t_stacks stacks, char **av)
{
	int			x;
	long int	temp;

	x = 1;
	while (x < stacks.size_a + 1)
	{
		temp = ft_atoi(av[x], stacks);
		if (temp > 2147483647 || temp < -21474836478)
			error_mes(&stacks);
		stacks.a[x - 1] = (int)temp;
		x++;
	}
	return (stacks);
}

int	main(int ac, char **av)
{
	t_stacks	stacks;

	init_struct(&stacks, ac);
	stacks = get_av(stacks, av);
	if (is_valid(stacks) == 2)
	{
		free_all_stacks_t(&stacks, stacks.size_b);
		return (0);
	}
	if (ac < 20)
		peanuts(stacks);
	else if (ac <= 100)
		do_easy_one(stacks);
	else
		not_so_easy_one(stacks);
	return (0);
}
