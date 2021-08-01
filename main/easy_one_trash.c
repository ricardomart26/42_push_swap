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


// SPECIAL CASES

   // int hig;
    // int rrb;

    // if ((*temp)->lowest == cmd.num)
    // {
    //     printf("\n\t(special cases) If lowest number to stackB\n");
    //     if (cmd.ra)
    //     {
    //         printf("\n\t(special cases) Before ra's %d\n", cmd.ra);
    //         print_stacks(**temp);
    //         sleep(4);
    //         **temp = gen_moves(**temp, 0, cmd.ra, 0);
    //         printf("\n\t(special cases) After ra's\n");
    //         print_stacks(**temp);
    //         sleep(4);
    //     }
    //     else if (cmd.rra)
    //     {
    //         printf("\n\t(special cases) Before rra's %d\n", cmd.rra);
    //         print_stacks(**temp);
    //         sleep(4);
    //         **temp = gen_moves(**temp, 1, cmd.rra, 0);
    //         printf("\n\t(special cases) After rra's\n");
    //         print_stacks(**temp);
    //         sleep(4);
    //     }


    //     hig = higgest_num((*temp)->stackB);
    //     rrb = (*temp)->sizeB - hig;
    //     if (hig >= (*temp)->sizeB / 2)
    //     {
    //         printf("\n\t(special cases) Before rrb's %d\n", cmd.rrb);
    //         print_stacks(**temp);
    //         sleep(4);
    //         **temp = gen_moves(**temp, 3, rrb, 0);
    //         printf("\n\t(special cases) After rrb's\n");
    //         print_stacks(**temp);
    //         sleep(4);
    //     }
    //     else if (hig <= (*temp)->sizeB / 2)
    //     {
    //         printf("\n\t(special cases) Before rb's %d hig %d\n", cmd.rb, hig);
    //         print_stacks(**temp);
    //         sleep(4);
    //         **temp = gen_moves(**temp, 2, hig, 0);
    //         printf("\n\t(special cases) After rb's\n");
    //         print_stacks(**temp);
    //         sleep(4);
    //     }
    // }
 