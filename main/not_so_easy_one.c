#include "../push_swap.h"

void	not_so_easy_one(t_stacks main)
{
	int		*org;
	t_moves	cmd;

	init_cmd(&cmd);
	while (main.sizeA != 3)
	{
		org = organize_array(main.A, main.sizeA - 1);
		init_main_loop(&main, org);
		if (main.sizeA > 100)
			attr_chunks(&main, org, 11);
		if (main.sizeA > 20)
			attr_chunks(&main, org, 6);
		else
			attr_chunks(&main, org, 2);
		main = push_chunk_to_b(main);
	}
	cmd = B_correct(&main, main.sizeB);
	main = last3_A(main);
	while (main.B[0] < main.A[0] && main.sizeB != 0)
		main = pa_funct(main, 1);
	free(main.B);
	main.B = NULL;
	free(main.A);
	main.A = NULL;
}
