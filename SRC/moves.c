#include "../push_swap.h"

int moves_rb(int place, moves_t cmd)
{
    cmd.rb = place;
    if (cmd.ra == cmd.rb)
        return (cmd.ra + cmd.rb + pb);
    else if (cmd.ra >= cmd.rb)
    {
        cmd.rr = cmd.rb;
        cmd.ra -= cmd.rb;
        return (cmd.rr + cmd.ra + pb);
    }
    else if (cmd.ra < cmd.rb)
    {
        cmd.rr = cmd.ra;
        cmd.rb -= cmd.ra;
        return (cmd.rr + cmd.rb + pb);
    }
    return (0);
}

int moves_rrb(stacks_t *main, int place, moves_t cmd)
{
    cmd.rrb = main->sizeB - place;
    if (cmd.rra == cmd.rrb)
        return (cmd.rra + cmd.rrb + pb);
    else if (cmd.rra >= cmd.rrb)
    {
        cmd.rrr = cmd.rrb;
        cmd.rra -= cmd.rrb;
        return (cmd.rrr + cmd.rra + pb);
    }
    else if (cmd.rra < cmd.rrb)
    {
        cmd.rrr = cmd.rra;
        cmd.rrb -= cmd.rra;
        return (cmd.rrr + cmd.rrb + pb);
    }
    return (0);
}


