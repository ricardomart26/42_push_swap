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
    if (main.sizeB > 1)
    {
        while (i < size)
        {
            if (main.stackB[i] > cmd.num)
                temp = main.stackB[i] - cmd.num;   
            else if (main.stackB[i] < cmd.num)
                temp = cmd.num - main.stackB[i];
            if (i == 0)
                diff = temp;
            else if (temp < diff)
            {
                cmd.pos_stackb = i;
                
                temp = diff;
            }   
            i++;
        }
    }
    printf("\n\t(place to put nbr) num %d place %d lowest diff num %d\n", cmd.num, cmd.pos_stackb, main.stackB[cmd.pos_stackb]);
    if (cmd.pos_stackb > main.middle_size)
        cmd = set_b(cmd, 0, size - cmd.pos_stackb);
    else if (cmd.pos_stackb < main.middle_size)
        cmd = set_b(cmd, cmd.pos_stackb, 0);

    return (cmd);
}   

moves_t    get_cmds(stacks_t main, moves_t cmd, int size)
{
    int max;
    int max_place;

    if (size > 1)
    {
        print_stacks(main);
        cmd.pos_stackb = 0;
        max = biggest_num(main.stackB, size);
        max_place = place_in_array(main.stackB, max);

        print_stacks(main);
        printf("\n\tmax place %d max %d\n", max_place, max);
        sleep(3);
        if (is_lowest_array(cmd.num, main.stackB, size) || cmd.num > max)
        {
            if (max_place == 0)
                set_b(cmd, 0, 0);
            else if (max_place > main.middle_size)
                cmd = set_b(cmd, 0, size - max_place);
            else if (max_place <= main.middle_size)
                cmd = set_b(cmd, max_place, 0);
            
            // printf("\n\t(get_cmds) after setting the comands, lowest or higgest %d\n", cmd.num);
            // print_cmds(&cmd, 0);
            // print_stacks(main);
            // sleep(8);
        }
        else
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
    // printf("\n\t(get_cmds) after setting the comands\n");
    // print_cmds(&cmd, 0);
    // print_stacks(main);
    // sleep(8);
    return (cmd);
}

