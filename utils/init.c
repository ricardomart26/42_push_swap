#include "../push_swap.h"

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
    cmd->pos_stackb = 0;
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
    main->stackA = calloc(ac - 1, sizeof(int));
    if (!main->stackA)
        return ;
    main->sizeA = main->ac;
    main->sizeB = 0;
}
