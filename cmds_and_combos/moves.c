#include "../push_swap.h"

void moves_rb(moves_t *cmd)
{
    cmd->rb = cmd->pos_stackb;
    if (cmd->ra == cmd->rb)
    {
        cmd->rr = cmd->ra;
        cmd->ra = 0;
        cmd->rb = 0;
    }
    else if (cmd->ra > cmd->rb)
    {
        cmd->rr = cmd->rb;
        cmd->ra -= cmd->rb;
        cmd->rb = 0;
    }
    else if (cmd->ra < cmd->rb)
    {
        cmd->rr = cmd->ra;
        cmd->rb -= cmd->ra;
        cmd->ra = 0;
    }
}

void    moves_rrb(moves_t *cmd)
{
    if (cmd->rra == cmd->rrb)
    {
        cmd->rrr = cmd->rra;
        cmd->rra = 0;
        cmd->rrb = 0;
    }
    else if (cmd->rra > cmd->rrb)
    {
        cmd->rrr = cmd->rrb;
        cmd->rra -= cmd->rrb;
        cmd->rrb = 0;
    }
    else if (cmd->rra < cmd->rrb)
    {
        cmd->rrr = cmd->rra;
        cmd->rrb -= cmd->rra;
        cmd->rra = 0;
    }
}


