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

int special_cases(stacks_t **temp, moves_t cmd, int place)
{
    if (place == 0)
    {
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
    else if (place == (*temp)->sizeB)
    {
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

    cmd.total = special_cases(&temp, cmd, cmd.pos_stackb);
    printf("\n\t.:::FINISHED SIMULATE NUM 2:::.\n");
    print_stacks(*temp);
    // sleep(5);
    if (cmd.total != 0)
        return (cmd.total);
    else if (cmd.pos_stackb >= temp->sizeB/2)
        cmd.total = move_bottom_of_stack(&temp, cmd.pos_stackb, cmd); // Se o i for acima do meio entao tens que fazer rb
    else if (cmd.pos_stackb <= temp->sizeB/2) // Se o i for acima do meio entao tens que fazer rrb
        cmd.total = move_top_of_stack(&temp, cmd.pos_stackb, cmd);
    return (cmd.total);
}

int simulate_num1(stacks_t *temp, moves_t cmd)
{
    init_cmd(&cmd);
    
    printf("\n\t.:::FINISHED SIMULATE NUM 1:::.\n");
    print_stacks(*temp);
    cmd.total = special_cases(&temp, cmd, cmd.pos_stackb);
    printf("\n\t(simulate num 1) stack -> moves %d to push num %d B\n", cmd.total, cmd.num);
    if (cmd.total != 0)
        return (cmd.total);    

    else if (cmd.pos_stackb >= temp->sizeB/2)
        cmd.total = move_bottom_of_stack(&temp, cmd.pos_stackb, cmd); // Se o i for acima do meio entao tens que fazer rb
    else if (cmd.pos_stackb <= temp->sizeB/2) // Se o i for acima do meio entao tens que fazer rrb
        cmd.total = move_top_of_stack(&temp, cmd.pos_stackb, cmd);
    return (cmd.total);
}
