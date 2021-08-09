#include "../push_swap.h"

stacks_t   gen_moves_fake(stacks_t main, int option, int counter, int pb_pa)
{
    while (counter)
    {
        if (option == 0)
            main = ra_funct(main, 0);
        if (option == 1)
            main = rra_funct(main, 0);
        if (option == 2)
            main = rb_funct(main, 0);
        if (option == 3)
            main = rrb_funct(main, 0);
        if (option == 4)
            main = rr_funct(main, 0);
        if (option == 5)
            main = rrr_funct(main, 0);
        counter--;
    }
    if (pb_pa == 1)
        main = pb_funct(main, 0);
    else if (pb_pa == 2)
        main = pa_funct(main, 0);

    return (main);
}

stacks_t   gen_moves_real(stacks_t main, int option, int counter, int pb_pa)
{
    if (counter > 20)
    {

        print_stacks(main);
        printf("\n\toption %d\n", option);
        sleep(2);
        exit(0);
    }
    while (counter)
    {
        if (option == 0)
            main = ra_funct(main, 1);
        if (option == 1)
            main = rra_funct(main, 1);
        if (option == 2)
            main = rb_funct(main, 1);
        if (option == 3)
            main = rrb_funct(main, 1);
        if (option == 4)
            main = rr_funct(main, 1);
        if (option == 5)
            main = rrr_funct(main, 1);
        counter--;
    }
    if (pb_pa == 1)
        main = pb_funct(main, 1);
    else if (pb_pa == 2)
        main = pa_funct(main, 1);

    return (main);
}


moves_t *rr_sim(moves_t *cmd, int rr, int ra, int rb)
{
    cmd->rr = rr;
    cmd->ra = ra;
    cmd->rb = rb;
    cmd->total = cmd->rr + cmd->ra + cmd->rb;
    return (cmd);
}

moves_t *rrr_sim(moves_t *cmd, int rrr, int rrb, int rra)
{
    cmd->rrr = rrr;
    cmd->rrb = rrb;
    cmd->rra = rra;
    cmd->total = cmd->rrr + cmd->rra + cmd->rrb;
    return (cmd);
}

int num1(stacks_t **temp, moves_t cmd)
{
    if (cmd.rr && !cmd.ra && !cmd.rb)
    {
        **temp = gen_moves_real(**temp, 4, cmd.rr, 1);
        return(cmd.rr + pb);
    }
    else if (cmd.rr)
    {
        **temp = gen_moves_real(**temp, 4, cmd.rr, 0);
        **temp = gen_moves_real(**temp, 0, cmd.ra, 0);
        **temp = gen_moves_real(**temp, 2, cmd.rb, 0);
        **temp = gen_moves_real(**temp, 3, cmd.rrb, 1);
        return (cmd.rr + cmd.ra + cmd.rb + cmd.rrb + pb);
    }
    else if (!cmd.rr)
    {

        **temp = gen_moves_real(**temp, 0, cmd.ra, 0);
        **temp = gen_moves_real(**temp, 2, cmd.rb, 0);
        **temp = gen_moves_real(**temp, 3, cmd.rrb, 0);
        **temp = pb_funct(**temp, 1);
        return (cmd.ra + cmd.rb + cmd.rrb + pb);
    }
    return (0);
}

int num2(stacks_t **temp, moves_t cmd)
{
    if (cmd.rrr && !cmd.rra && !cmd.rrb)
    {
        **temp = gen_moves_real(**temp, 5, cmd.rrr, 1);
        return(cmd.rrr + pb);
    }
    else if (cmd.rrr)
    {
        **temp = gen_moves_real(**temp, 5, cmd.rrr, 0);
        **temp = gen_moves_real(**temp, 1, cmd.rra, 0);
        **temp = gen_moves_real(**temp, 3, cmd.rrb, 0);
        **temp = gen_moves_real(**temp, 2, cmd.rb, 1);
        return (cmd.rrr + cmd.rra + cmd.rb + cmd.rrb + pb);
    }
    else if (!cmd.rrr)
    {
        **temp = gen_moves_real(**temp, 1, cmd.rra, 0);
        **temp = gen_moves_real(**temp, 2, cmd.rb, 0);
        **temp = gen_moves_real(**temp, 3, cmd.rrb, 1);
        return (cmd.rra + cmd.rb + cmd.rrb + pb);
    }
    return (0);
}


int num1_fake(stacks_t **temp, moves_t cmd)
{
    if (cmd.rr && !cmd.ra && !cmd.rb)
    {   
        **temp = gen_moves_fake(**temp, 4, cmd.rr, 1);
        return(cmd.rr + pb);
    }
    else if (cmd.rr)
    {
        **temp = gen_moves_fake(**temp, 4, cmd.rr, 0);
        **temp = gen_moves_fake(**temp, 0, cmd.ra, 0);
        **temp = gen_moves_fake(**temp, 2, cmd.rb, 0);
        **temp = gen_moves_fake(**temp, 3, cmd.rrb, 1);
        return (cmd.rr + cmd.ra + cmd.rb + cmd.rrb + pb);
    }
    else if (!cmd.rr)
    {

        **temp = gen_moves_fake(**temp, 0, cmd.ra, 0);
        **temp = gen_moves_fake(**temp, 2, cmd.rb, 0);
        **temp = gen_moves_fake(**temp, 3, cmd.rrb, 0);
        **temp = pb_funct(**temp, 0);
        return (cmd.ra + cmd.rb + cmd.rrb + pb);
    }
    return (0);
}

int num2_fake(stacks_t **temp, moves_t cmd)
{
    if (cmd.rrr && !cmd.rra && !cmd.rrb)
    {
        **temp = gen_moves_fake(**temp, 5, cmd.rrr, 1);
        return(cmd.rrr + pb);
    }
    else if (cmd.rrr)
    {
        **temp = gen_moves_fake(**temp, 5, cmd.rrr, 0);
        **temp = gen_moves_fake(**temp, 1, cmd.rra, 0);
        **temp = gen_moves_fake(**temp, 3, cmd.rrb, 0);
        **temp = gen_moves_fake(**temp, 2, cmd.rb, 1);
        return (cmd.rrr + cmd.rra + cmd.rb + cmd.rrb + pb);
    }
    else if (!cmd.rrr)
    {
        **temp = gen_moves_fake(**temp, 1, cmd.rra, 0);
        **temp = gen_moves_fake(**temp, 2, cmd.rb, 0);
        **temp = gen_moves_fake(**temp, 3, cmd.rrb, 1);
        return (cmd.rra + cmd.rb + cmd.rrb + pb);
    }
    return (0);
}