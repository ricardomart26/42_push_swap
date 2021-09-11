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

static void	push_everything_to_b(t_stacks *main, int *org)
{
	while (main->size_a != 3)
	{
		main->lowest = *org;
		main->middle_size = main->size_a / 2;
		main->lowest_pos = find(*org, main->a);
		if (main->lowest_pos == 0)
			*main = pb_funct(*main, 1);
		else if (main->lowest_pos > main->middle_size && main->size_a != 0)
		{
			while (main->lowest_pos++ != main->size_a)
				*main = rra_funct(*main, 1);
			*main = pb_funct(*main, 1);
		}
		else if (main->lowest_pos <= main->middle_size && main->size_a != 0)
		{
			while (main->lowest_pos-- != 0)
				*main = ra_funct(*main, 1);
			*main = pb_funct(*main, 1);
		}
		org++;
	}
}

t_stacks	do_only3(t_stacks main)
{
	if (main.ac == 2)
		return (sa_funct(main, 1));
	else
	{
		if (main.a[0] > main.a[1] && main.a[1]
			< main.a[2] && main.a[0] < main.a[2])
			main = sa_funct(main, 1);
		else if (main.a[0] > main.a[1] && main.a[1]
			< main.a[2] && main.a[0] > main.a[2])
			main = ra_funct(main, 1);
		else if (main.a[0] > main.a[1] && main.a[1] > main.a[2])
		{
			main = sa_funct(main, 1);
			main = rra_funct(main, 1);
		}
		else if (main.a[0] < main.a[1] && main.a[1]
			> main.a[2] && main.a[0] > main.a[2])
			main = rra_funct(main, 1);
		else if (main.a[0] < main.a[1] && main.a[1] > main.a[2])
		{
			main = rra_funct(main, 1);
			main = sa_funct(main, 1);
		}
		return (main);
	}
}

void	peanuts(t_stacks main)
{
	int	*org;

	if (main.ac <= 3)
	{
		do_only3(main);
		free_all_stacks_t(&main, main.size_b);
		return ;
	}
	org = organize_array(main.a, main.size_a - 1);
	push_everything_to_b(&main, org);
	free(org);
	org = NULL;
	main = do_only3(main);
	while (main.size_b != 0)
		main = pa_funct(main, 1);
	free_all_stacks_t(&main, main.size_b);
}

t_stacks	get_av(t_stacks main, char **av)
{
	int			x;
	long int	temp;

	x = 1;
	while (x < main.size_a + 1)
	{
		temp = ft_atoi(av[x], main);
		if (temp > 2147483647 || temp < -21474836478)
			error_mes(&main);
		main.a[x - 1] = (int)temp;
		x++;
	}
	return (main);
}

int	main(int ac, char **av)
{
	t_stacks	main;

	init_struct(&main, ac);
	main = get_av(main, av);
	if (is_valid(main) == 2)
	{
		free_all_stacks_t(&main, main.size_b);
		return (0);
	}
	if (ac < 20)
		peanuts(main);
	else if (ac <= 100)
		do_easy_one(main);
	else
		not_so_easy_one(main);
}
