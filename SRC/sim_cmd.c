#include "../push_swap.h"

int do_rr_top(moves_t **cmd, stacks_t ***temp) // Dont know if it works
{
    if ((*cmd)->rb == (*cmd)->ra)
    {
        cmd = rr_sim(cmd, (*cmd)->ra, 0, 0);
        ***temp = gen_moves(***temp, 4, (*cmd)->rr, 1);
        return ((*cmd)->total);
    }
    else if ((*cmd)->rb > (*cmd)->ra)
    {
        cmd = rr_sim(cmd, (*cmd)->ra, (*cmd)->rb -= (*cmd)->ra, 0);
        ***temp = gen_moves(***temp, 4, (*cmd)->rr, 0);
        ***temp = gen_moves(***temp, 2, (*cmd)->rb, 1);
        // printf("\n\t(do rr top) rrb > rra total %d", (*cmd)->total);
        return ((*cmd)->total);
    }
    else if ((*cmd)->rb < (*cmd)->ra)
    {
        cmd = rr_sim(cmd, (*cmd)->rb, 0, (*cmd)->ra -= (*cmd)->rb);
        ***temp = gen_moves(***temp, 4, (*cmd)->rr, 0);
        ***temp = gen_moves(***temp, 0, (*cmd)->ra, 1);
        // printf("\n\t(do rr top) rrb < rra total %d", (*cmd)->total);
        return ((*cmd)->total);
    }
    return (0);
}

int do_rrr_bottom(moves_t **cmd, stacks_t ***temp)
{
    if ((*cmd)->rrb == (*cmd)->rra)
    {
        cmd = rrr_sim(cmd, (*cmd)->rra, 0, 0);
        ***temp = gen_moves(***temp, 5, (*cmd)->rrr, 1);
        return ((*cmd)->total);
    }
    else if ((*cmd)->rrb > (*cmd)->rra)
    {
        cmd = rrr_sim(cmd, (*cmd)->rra, (*cmd)->rrb -= (*cmd)->rra, 0);
        ***temp = gen_moves(***temp, 5, (*cmd)->rrr, 0);
        ***temp = gen_moves(***temp, 3, (*cmd)->rrb, 1);
        // printf("\n\t(do_rrr_bottom) rrb > rra total %d", (*cmd)->total);
        return ((*cmd)->total);
    }
    else if ((*cmd)->rrb < (*cmd)->rra)
    {
        cmd = rrr_sim(cmd, (*cmd)->rrb, 0, (*cmd)->rra -= (*cmd)->rrb);
        ***temp = gen_moves(***temp, 5, (*cmd)->rrr, 0);
        ***temp = gen_moves(***temp, 1, (*cmd)->rra, 1);
        // printf("\n\t(do_rrr_bottom) rrb < rra total %d", (*cmd)->total);
        return ((*cmd)->total);
    }
    return (0);
}

int move_bottom_of_stack(stacks_t **temp, int place, moves_t *cmd)
{
    int size;

    size = (*temp)->sizeB + 1;
    // printf("\n\t(move bottom of stack) rra %d size %d", cmd->rra, size);
    cmd->rrb = size - place;
    if (cmd->ra)
    {
        **temp = gen_moves(**temp, 0, cmd->ra, 0);
        **temp = gen_moves(**temp, 3, cmd->rrb, 1);
        return (cmd->ra + cmd->rrb + pb);
    }
    else if (cmd->rra)
        return (do_rrr_bottom(&cmd, &temp));
    else
    {
        **temp = gen_moves(**temp, 3, cmd->rrb, 1);
        return (cmd->rrb + pb);
    }

}

int move_top_of_stack(stacks_t **temp, int place, moves_t *cmd)
{
    int size;

    size = (*temp)->sizeB + 1;
    // printf("\n\t(move top of stack) rra %d size %d", cmd->rra, size);
    cmd->rrb = size - place;
    if (cmd->rra)
    {
        **temp = gen_moves(**temp, 1, cmd->rra, 0);
        **temp = gen_moves(**temp, 2, cmd->rb, 1);
        return (cmd->ra + cmd->rrb + pb);
    }
    else if (cmd->ra)
        return (do_rr_top(&cmd, &temp));
    else
        **temp = gen_moves(**temp, 2, cmd->rb, 1);

    return (cmd->rra + pb);
}
