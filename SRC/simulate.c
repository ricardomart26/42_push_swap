#include "../push_swap.h"

int put_last(stacks_t ***temp, moves_t cmd)
{
    /*
    Se estiver na metade de baixo do stackA, e o numero 
    for para a metade de cima do stack B.
    Converter para rr, e se tiver mais ra fazer ate o numero 
    da stackA ficar na 1º posição e fazer um pb e um rra
    */
    if (cmd.ra)
    {
        // printf("\n\t(put last) ra %d rb %d rrb %d rra %d\n", cmd.ra, cmd.rb, cmd.rrb, cmd.rrb);
        cmd.rr = 1;
        cmd.ra--;
        ***temp = gen_moves(***temp, 4, 1, 0);
        if (!cmd.ra)
        {
            ***temp = gen_moves(***temp, 0, 0, 1);
            // printf("\n\t(put last) nra: This amount of moves %d", cmd.rr + pb);
            return (cmd.rr + pb);
        }
        else
        {
            ***temp = gen_moves(***temp, 0, cmd.ra, 1);
            // printf("\n\t(put last) ra: This amount of moves %d", cmd.rr - cmd.ra + pb);
            return (cmd.rr - cmd.ra + pb);
        }
    }
    else if (cmd.rra)
    {
        // printf("\n\t(put last) ra %d rb %d rrb %d rra %d\n", cmd.ra, cmd.rb, cmd.rrb, cmd.rrb);
        // Se estiver na metade de baixo, e o numero fo
        ***temp = gen_moves(***temp, 1, cmd.rra, 0);
        if (cmd.ra == 0)
        {
            ***temp = gen_moves(***temp, 0, 0, 1);
            return (cmd.rr + pb);
        }
    }
    return (0);
}

int higgest_num(int *stack)
{
    int x;
    int i;
    int temp;

    i = 0;
    x = 0;
    temp = 0;
    while (stack[x] != 0)
    {
        if (temp < stack[x])
        {
            temp = stack[x];
            i = x;
        }
        x++;
    }
    // printf("\n\t(higgest num) %d %d\n", i, stack[i]);
    return (i);
}

int special_cases(stacks_t **temp, moves_t cmd, int place)
{
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
    if (place == 0)
    {
        // printf("\n\t(special cases) here? \n");
        printf("\n\tCHEGOU AQUI????? 5\n");

        if (cmd.ra)
            **temp = gen_moves(**temp, 0, cmd.ra, 1);
        else if (cmd.rra)
        {
            // print_stacks(**temp);
            **temp = gen_moves(**temp, 1, cmd.rra, 1);
        }
        else
            **temp = gen_moves(**temp, 1, 0, 1);

        return (cmd.ra + cmd.rra + pb);
    }
    else if (place == (*temp)->sizeB && cmd.num != (*temp)->lowest)
    {
        printf("\n\tCHEGOU AQUI????? 6\n");

        // printf("\n\t(special cases) here? 1\n");
        if ((*temp)->sizeB <= 1)
        {
            // printf("\n\t\t Size == 1 \t%d", cmd.ra + cmd.rra + pb);
            **temp = gen_moves(**temp, 0, cmd.ra, 0);
            **temp = gen_moves(**temp, 1, cmd.rra, 1);
            return (cmd.ra + cmd.rra + pb);
        }
        return (put_last(&temp, cmd));
    }
    return (0);
}

int simulate_num2(stacks_t *temp, moves_t cmd)
{
    init_cmd(&cmd);

    printf("(sim num 2)Check this bitch %d\n", cmd.pos_stackb);
    cmd.total = special_cases(&temp, cmd, cmd.pos_stackb);
    // printf("\n\t(simulate num 2) total %d\n", cmd.total);
    // sleep(2);
    if (cmd.total != 0)
        return (cmd.total);
    else if (cmd.pos_stackb >= temp->sizeB/2)
        cmd.total = move_bottom_of_stack(&temp, cmd.pos_stackb, cmd); // Se o i for acima do meio entao tens que fazer rb
    else if (cmd.pos_stackb <= temp->sizeB/2) // Se o i for acima do meio entao tens que fazer rrb
        cmd.total = move_top_of_stack(&temp, cmd.pos_stackb, cmd);
    // printf("\n\t.:::FINISHED SIMULATE NUM 2:::.\n");
    // print_stacks(*temp);
    return (cmd.total);
}

int simulate_num1(stacks_t *temp, moves_t cmd)
{
    // int place;
    init_cmd(&cmd);
    printf("(sim num 1)Check this bitch %d\n", cmd.pos_stackb);
    cmd.total = special_cases(&temp, cmd, cmd.pos_stackb);
    // printf("\n\t(simulate num 1) stack -> moves %d to push num %d B\n", cmd.total, cmd.num);
    if (cmd.total != 0)
        return (cmd.total);
    else if (cmd.pos_stackb >= temp->sizeB/2)
        cmd.total = move_bottom_of_stack(&temp, cmd.pos_stackb, cmd); // Se o i for acima do meio entao tens que fazer rb
    else if (cmd.pos_stackb <= temp->sizeB/2) // Se o i for acima do meio entao tens que fazer rrb
        cmd.total = move_top_of_stack(&temp, cmd.pos_stackb, cmd);
    

    // place = cmd.pos_stackb;
    // if (place <= temp->middle_size)
    // {
    //     cmd.rb = place;
    //     if (cmd.)
    // }
    // else if (place >= temp->middle_size)
    // {
    //     cmd.rb = temp->sizeB - place;

    // }
    // printf("\n\t.:::FINISHED SIMULATE NUM 1:::.\n");
    // print_stacks(*temp);
    return (cmd.total);
}
