#include "../push_swap.h"


int real_num2(stacks_t *temp, moves_t cmd)
{
    cmd.total = num2(&temp, cmd);
    if (cmd.total != 0)
        return (cmd.total);
    return (0);
}

int real_num1(stacks_t *temp, moves_t cmd)
{
    cmd.total = num1(&temp, cmd);
    if (cmd.total != 0)
        return (cmd.total);
    return (0);

}

stacks_t    do_opt(stacks_t main, int *chunks, int option)
{
    // printf("\n\t(do opt) Got here option %d\n", option);
    if (option == 0)
        main = combo_opt0(main, chunks);
    else if (option == 1)
        main = combo_opt1(main, chunks);
    else if (option == 2)
        main = combo_opt2(main, chunks);
    else if (option == 3)
        main = combo_opt3(main, chunks);

    return (main);
}