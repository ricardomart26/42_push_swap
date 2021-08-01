#include "../push_swap.h"

void    init_cmd(moves_t *cmd)
{
    cmd->rr = 0;
    cmd->rrr = 0;
}

void    init_struct(stacks_t *main, int ac)
{
    main->ac = ac - 1;
    main->stackA = calloc(ac - 1, sizeof(int));
    if (!main->stackA)
        return ;
    main->sizeA = ac - 1;
    main->sizeB = 0;
}
