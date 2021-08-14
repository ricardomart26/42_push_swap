#include "../push_swap.h"

t_moves	B_correct(t_stacks *main, int size)
{
	int		max;
	int		max_place;
	t_moves	cmd;

	init_cmd(&cmd);
	max = biggest_num(main->B, size);
	max_place = place_in_array(main->B, max);
	if (max_place <= size / 2)
	{
		*main = gen_moves_real(*main, 3, size - max_place, 0);
		cmd.rrb = size - max_place;
	}
	else if (max_place > size / 2)
	{
		*main = gen_moves_real(*main, 2, max_place, 0);
		cmd.rb = max_place;
	}
	return (cmd);
}

void	organize4_A(t_stacks *main)
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

t_stacks	last3_A(t_stacks main)
{
	if (!is_lowest_array(main.B[0], main.A, main.sizeA))
		organize4_A(&main);
	if (!is_correct(main.A, 3))
		main = do_only3(main);
	return (main);
}
