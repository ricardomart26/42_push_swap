#include "../push_swap.h"

stacks_t	pass_stacks_to_temp(stacks_t main)
{
	stacks_t	temp;
	int			x;

	temp.A = malloc(sizeof(int) * main.sizeA + 1);
	temp.lowest = main.lowest;
	temp.size_chunk = main.size_chunk;
	temp.middle_size = main.middle_size;
	temp.sizeA = main.sizeA;
	temp.sizeB = main.sizeB;
	x = 0;
	while (main.sizeA--)
	{
		temp.A[x] = main.A[x];
		x++;
	}
	x = 0;
	if (main.sizeB != 0)
	{
		temp.B = malloc(sizeof(int) * main.sizeB + 1);
		while (main.sizeB--)
		{
			temp.B[x] = main.B[x];
			x++;
		}
	}
	return (temp);
}

void    init_main_loop(stacks_t *main, int *org)
{
    main->lowest = org[0];
    if (main->sizeA % 2 != 0)
        main->middle_size = main->sizeA/2 + 1;
    else
        main->middle_size = main->sizeA/2;
}

void    init_cmd(moves_t *cmd)
{
    cmd->num = 0;
    cmd->pos_B = 0;
    cmd->total = 0;
    cmd->ra = 0;
    cmd->rb = 0;
    cmd->rr = 0;
    cmd->rra = 0;
    cmd->rrb = 0;
    cmd->rrr = 0;
}

void    init_struct(stacks_t *main, int ac)
{
    main->ac = ac - 1;
    main->A = calloc(ac - 1, sizeof(int));
    if (!main->A)
        return ;
    main->sizeA = main->ac;
    main->sizeB = 0;
}
