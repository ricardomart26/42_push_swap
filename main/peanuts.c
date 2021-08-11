#include "../push_swap.h"

static void	push_everything_to_b(stacks_t *main, int *org)
{
	while (main->sizeA != 3)
	{
		main->lowest = *org;
		main->middle_size = main->sizeA / 2;
		main->lowest_pos = find(*org, main->stackA);
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

void	do_only3(stacks_t *main)
{
	if (main->ac == 2)
		*main = sa_funct(*main, 1);
	else
	{
		if (main->stackA[0] > main->stackA[1] && main->stackA[1] < main->stackA[2] && main->stackA[0] < main->stackA[2])
			*main = sa_funct(*main, 1);
		if (main->stackA[0] > main->stackA[1] && main->stackA[1] < main->stackA[2] && main->stackA[0] > main->stackA[2])
			*main = ra_funct(*main, 1);
		else if (main->stackA[0] > main->stackA[1] && main->stackA[1] > main->stackA[2])
		{
			*main = sa_funct(*main, 1);
			*main = rra_funct(*main, 1);
		}
		else if (main->stackA[0] < main->stackA[1] && main->stackA[1] > main->stackA[2] && main->stackA[0] > main->stackA[2])
			*main = rra_funct(*main, 1);
		else if (main->stackA[0] < main->stackA[1] && main->stackA[1] > main->stackA[2] && main->stackA[0] < main->stackA[2])
		{
			*main = rra_funct(*main, 1);
			*main = sa_funct(*main, 1);
		}
	}
}
stacks_t	peanuts(stacks_t main)
{
	int	*org;

	if (main.ac <= 3)
	{
		do_only3(&main);
		return (main);
	}
	org = organize_array(main.stackA, main.sizeA - 1);
	push_everything_to_b(&main, org);
	do_only3(&main);
	while (main.sizeB != 0)
		main = pa_funct(main, 1);
	return (main);
}
