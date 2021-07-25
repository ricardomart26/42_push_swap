#include "../push_swap.h"


void    organize_stackB2(stacks_t *main)
{
    int i_in_stackb;
    i_in_stackb = where_to_putnbr2(main->stackA[0], main->stackB, main->sizeB); // Ver onde tem que ir o primeiro numero
    // printf("\n\n\t\t ENTERED IN ORGANIZED ");
    // // print_stacks(*main);
    // printf("\n\t(organize stack b) main->stackA[0] %d\n", main->stackA[0]);
    // printf("\n\t(organize stack b) i_in_stack %d\n", i_in_stackb);
    // printf("\n\t(organize stack b) main->sizeB %d\n", main->sizeB/2);
    // printf("\n\t(organize stack b) i_in_stack %d\n", i_in_stackb);

    if (i_in_stackb == 0)
    {
        printf("\n\t(organize stack b) first pb\n");
        *main = pb_funct(*main);
    }
    else if (i_in_stackb == main->sizeB)
    {
        // printf("\n\t(organize stack b) second pb\n");
        *main = pb_funct(*main);
        *main = rb_funct(*main, 1);
    }
    else if (i_in_stackb >= main->sizeB/2) // Se o i for acima do meio
        main = combo1(main);
    else if (i_in_stackb <= main->sizeB/2)
        main = combo2(main);
    // printf("\n\t(organize stack b)");
    // print_stacks(*main);
    // sleep(1);
}

void	set_two_numbers(stacks_t *main, moves_t *cmd)
{
    int temp;

    temp = main->stackA[cmd->num - 1];
    cmd->rra = cmd->num;
    printf("\n\t(push_to_beg_stackA2) temp = %d\n", temp);
    temp = main->stackA[cmd->num - 1];
    printf("\t(push_to_beg_stackA2) htemp = %d\n", temp);
    cmd->ra = cmd->num;
}
