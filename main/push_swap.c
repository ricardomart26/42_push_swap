/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricardo <ricardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 00:45:32 by ricardo           #+#    #+#             */
/*   Updated: 2021/08/12 01:02:13 by ricardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	push_everything_to_b(stacks_t *main, int *org)
{
	while (main->sizeA != 3)
	{
		main->lowest = *org;
		main->middle_size = main->sizeA / 2;
		main->lowest_pos = find(*org, main->A);
		if (main->lowest_pos == 0)
			*main = pb_funct(*main, 1);
		else if (main->lowest_pos > main->middle_size && main->sizeA != 0)
		{
			while (main->lowest_pos++ != main->sizeA)
				*main = rra_funct(*main, 1);
			*main = pb_funct(*main, 1);
		}
		else if (main->lowest_pos <= main->middle_size && main->sizeA != 0)
		{
			while (main->lowest_pos-- != 0)
				*main = ra_funct(*main, 1);
			*main = pb_funct(*main, 1);
		}
		org++;
	}
}

stacks_t	do_only3(stacks_t main)
{
	if (main.ac == 2)
		return (sa_funct(main, 1));
	else
	{
		if (main.A[0] > main.A[1] && main.A[1]
			< main.A[2] && main.A[0] < main.A[2])
			main = sa_funct(main, 1);
		else if (main.A[0] > main.A[1] && main.A[1]
			< main.A[2] && main.A[0] > main.A[2])
			main = ra_funct(main, 1);
		else if (main.A[0] > main.A[1] && main.A[1] > main.A[2])
		{
			main = sa_funct(main, 1);
			main = rra_funct(main, 1);
		}
		else if (main.A[0] < main.A[1] && main.A[1]
			> main.A[2] && main.A[0] > main.A[2])
			main = rra_funct(main, 1);
		else if (main.A[0] < main.A[1] && main.A[1] > main.A[2])
		{
			main = rra_funct(main, 1);
			main = sa_funct(main, 1);
		}
		return (main);
	}
}

stacks_t	peanuts(stacks_t main)
{
	int	*org;

	if (main.ac <= 3)
		return (do_only3(main));
	org = organize_array(main.A, main.sizeA - 1);
	push_everything_to_b(&main, org);
	main = do_only3(main);
	while (main.sizeB != 0)
		main = pa_funct(main, 1);
	return (main);
}

stacks_t	get_av(stacks_t main, char **av)
{
	int			x;
	long int	temp;

	x = 1;
	while (av[x])
	{
		temp = ft_atoi(av[x]);
		if (temp > 2147483647 || temp < -21474836478)
			error_mes();
		main.A[x - 1] = (int)temp;
		x++;
	}
	return (main);
}

int	main(int ac, char **av)
{
	stacks_t	main;

	init_struct(&main, ac);
	main = get_av(main, av);
	if (is_valid(main) == 2)
		return (0);
	if (ac < 20)
		main = peanuts(main);
	else
		main = do_easy_one2(main);
}
