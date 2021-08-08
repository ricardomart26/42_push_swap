#include "../push_swap.h"

moves_t set_b(moves_t cmd, int rb, int rrb)
{
    cmd.rb = rb;
    cmd.rrb = rrb;
    if (cmd.rb != 0 && cmd.ra != 0)
        moves_rb(&cmd);
    else if (cmd.rrb != 0 && cmd.rra != 0)
        moves_rrb(&cmd);
    return (cmd);
}

moves_t place_to_put_nbr(stacks_t main, moves_t cmd, int size)
{
    int i;
    int x;
    int diff;
    int temp;

    diff = 0;
    i = 0;
    while (i < size)
    {
        if (cmd.num > main.stackB[0] && cmd.num < main.stackB[size - 1] && i == 0)
        {
            cmd.pos_stackb = 0;
            break;
        }
        else
        {
            // printf("\n\tim here\n");
            temp = 0;
            if (main.stackB[i] > cmd.num)
                temp = main.stackB[i] - cmd.num;   
            else if (main.stackB[i] < cmd.num)
            {
                // printf("\n\t%d = %d - %d", cmd.num - main.stackB[i], cmd.num, main.stackB[i]);
                temp = cmd.num - main.stackB[i];
                // printf("\n\ttemp is %d\n", temp);
                // sleep(3);
            }
            if (i == 0)
            {
                diff = temp;
                if (main.stackB[i] > cmd.num)
                    cmd.pos_stackb = i + 1;   
                else if (main.stackB[i] < cmd.num)
                    cmd.pos_stackb = i;
                
            }
            else if (temp < diff)
            {
                printf("\nThe %d is closer to %d than %d the diff is %d and temp is %d\t", main.stackB[i], cmd.num, main.stackB[x], diff, temp);
                sleep(2);
                if (main.stackB[i] > cmd.num)
                    cmd.pos_stackb = i + 1;   
                else if (main.stackB[i] < cmd.num)
                    cmd.pos_stackb = i;
                diff = temp;
                x = i;
            }
            i++;
        }
    }
    if (cmd.pos_stackb > main.sizeB/2)
        cmd = set_b(cmd, 0, size - cmd.pos_stackb);
    else if (cmd.pos_stackb <= main.sizeB/2)
        cmd = set_b(cmd, cmd.pos_stackb, 0);
    return (cmd);
}   

moves_t    get_cmds(stacks_t main, moves_t cmd, int size)
{
    int max;
    int max_place;
    int option = 0;

    if (size > 1)
    {
        max = biggest_num(main.stackB, size);
        max_place = place_in_array(main.stackB, max);
        printf("\n\tmax %d and max_place %d size - 1 %d num %d\n", max, max_place, size - 1, cmd.num);
        if (is_lowest_array(cmd.num, main.stackB, size) || cmd.num > max && size != main.size_chunk)
        {
            if (cmd.num <= max)
            {
                if (max_place > main.sizeB/2)
                    cmd = set_b(cmd, 0, size - max_place);
                else if (max_place <= main.sizeB/2)
                    cmd = set_b(cmd, max_place, 0);
            }
            else if (max_place == 0)
                set_b(cmd, 0, 0);
            else if (max_place == size - 1 && cmd.num > max)
                set_b(cmd, 0, 1);
            else if (max_place > main.sizeB/2)
                cmd = set_b(cmd, 0, (size - max_place) + 1);
            else if (max_place <= main.sizeB/2)
                cmd = set_b(cmd, max_place, 0);
        }
        else if (size != main.size_chunk)
            cmd = place_to_put_nbr(main, cmd, main.sizeB);
        cmd.total = 0;
    }
    else
    {
        cmd.pos_stackb = 0;
        cmd.rb = 0;
        cmd.rrb = 0;
        cmd.rr = 0;
        cmd.rrr = 0;
        cmd.total = 0;
    }   
    return (cmd);
}

