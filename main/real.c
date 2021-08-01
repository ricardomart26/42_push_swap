#include "../push_swap.h"


int real_num2(stacks_t *temp, moves_t cmd)
{
    init_cmd(&cmd);

    // printf("(sim num 2)Check this bitch %d %d\n", cmd.pos_stackb, cmd.num);
    cmd.total = special_cases(&temp, cmd, cmd.pos_stackb);

    if (cmd.total != 0)
        return (cmd.total);
    else if (cmd.pos_stackb >= temp->sizeB/2)
        cmd.total = move_bottom_of_stack(&temp, cmd.pos_stackb, cmd); // Se o i for acima do meio entao tens que fazer rb
    else if (cmd.pos_stackb <= temp->sizeB/2) // Se o i for acima do meio entao tens que fazer rrb
        cmd.total = move_top_of_stack(&temp, cmd.pos_stackb, cmd);
    return (cmd.total);
}

int real_num1(stacks_t *temp, moves_t cmd)
{
    init_cmd(&cmd);
    // printf("(sim num 1)Check this bitch %d\n", cmd.pos_stackb);
    cmd.total = special_cases(&temp, cmd, cmd.pos_stackb);

    if (cmd.total != 0)
        return (cmd.total);
    else if (cmd.pos_stackb >= temp->sizeB/2)
        cmd.total = move_bottom_of_stack(&temp, cmd.pos_stackb, cmd); // Se o i for acima do meio entao tens que fazer rb
    else if (cmd.pos_stackb <= temp->sizeB/2) // Se o i for acima do meio entao tens que fazer rrb
        cmd.total = move_top_of_stack(&temp, cmd.pos_stackb, cmd);
    return (cmd.total);
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