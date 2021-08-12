#include "../push_swap.h"

moves_t set_b(moves_t cmd, int rb, int rrb)
{
    cmd.rb = rb;
    cmd.rrb = rrb;
    if (cmd.rb != 0 && cmd.ra != 0)
        moves_rb(&cmd);
    else if (cmd.rrb != 0 && cmd.rra != 0)
        moves_rrb(&cmd);
    else
    {
        cmd.rrr = 0;
        cmd.rr = 0;
    }
    return (cmd);
}

moves_t place_to_put_nbr(stacks_t main, moves_t cmd, int size)
{
    int i;
    int diff;
    int temp;

    diff = 0;
    i = 0;
    while (i < size)
    {
        if (cmd.num > main.B[0] && cmd.num < main.B[size - 1] && i == 0)
        {
            cmd.pos_B = 0;
            break;
        }
        else
        {
            if (main.B[i] > cmd.num)
                temp = main.B[i] - cmd.num;   
            else if (main.B[i] < cmd.num)
                temp = cmd.num - main.B[i];
            if (i == 0)
            {
                diff = temp;
                if (main.B[i] > cmd.num)
                    cmd.pos_B = i + 1;   
                else if (main.B[i] < cmd.num)
                    cmd.pos_B = i;
                
            }
            else if (temp < diff)
            {
                if (main.B[i] > cmd.num)
                    cmd.pos_B = i + 1;   
                else if (main.B[i] < cmd.num)
                    cmd.pos_B = i;
                diff = temp;
            }
            i++;
        }
    }
    if (cmd.pos_B > main.sizeB/2)
        cmd = set_b(cmd, 0, size - cmd.pos_B);
    else if (cmd.pos_B <= main.sizeB/2)
        cmd = set_b(cmd, cmd.pos_B, 0);
    return (cmd);
}   

moves_t    get_cmds(stacks_t main, moves_t cmd, int size)
{
    int max;
    int max_place;
    int option;

    option = 0;
    if (size > 1)
    {
        max = biggest_num(main.B, size);
        max_place = place_in_array(main.B, max);
        if ((is_lowest_array(cmd.num, main.B, size) || cmd.num > max))
        {
            if (max_place == 0)
                set_b(cmd, 0, 0);
            else if (max_place == size - 1 && cmd.num > max)
                cmd = set_b(cmd, 0, 1);
            else if (max_place > main.sizeB/2)
                cmd = set_b(cmd, 0, size - max_place);
            else if (max_place <= main.sizeB/2)
                cmd = set_b(cmd, max_place, 0);
        }
        else if (size != main.size_chunk + 1)
            cmd = place_to_put_nbr(main, cmd, main.sizeB);
        cmd.total = 0;
    }
    else
    {
        cmd.pos_B = 0;
        cmd.rb = 0;
        cmd.rrb = 0;
        cmd.rr = 0;
        cmd.rrr = 0;
        cmd.total = 0;
    }   
    return (cmd);
}

