#include "../push_swap.h"

int put_last(stacks_t ***temp, moves_t *cmd)
{
    /*
    Se estiver na metade de baixo, e o numero for para a 
    metade de baixo do stack B.
    Converter para rr, e se tiver mais ra fazer ate o numero 
    da stackA ficar na 1º posição e fazer um pb e um rra
    */
    if (cmd->ra) 
    {
        cmd->rr = 1;
        cmd->ra--;
        ***temp = gen_moves(***temp, 4, 1, 0);
        if (!cmd->ra)
        {
            ***temp = gen_moves(***temp, 0, 0, 1);
            return (cmd->rr + pb + 1);
        }
        else
        {
            ***temp = gen_moves(***temp, 0, cmd->ra, 1);
            return (cmd->rr - cmd->ra + pb);
        }
    }
    else if (cmd->rra)
    {
        // Se estiver na metade de baixo, e o numero foir
        ***temp = gen_moves(***temp, 1, cmd->rra, 0);
        if (cmd->ra == 0)
        {
            ***temp = gen_moves(***temp, 0, 0, 1);
            return (cmd->rr + pb + 1);
        }
    }
    return (0);
}

int special_cases(stacks_t **temp, moves_t *cmd, int place)
{
    if (place == 0)
    {
        // printf("\n\t(simulate_first_num) cmd->pos_stackb = 0 ra %d\n", cmd->ra);
        if (cmd->ra)
            **temp = gen_moves(**temp, 0, cmd->ra, 1);
        else if (cmd->rra)
            **temp = gen_moves(**temp, 1, cmd->rra, 1);

        return (cmd->ra + pb);
    }
    else if (place == (*temp)->sizeB)
        return (put_last(&temp, cmd));
    return (0);
}

int simulate_num2(stacks_t *temp, moves_t *cmd)
{
    init_cmd(&cmd[0]);

    printf("\n\t(simulate num 2) Second simulate stack");
    print_stacks(*temp);
    cmd->total = special_cases(&temp, cmd, cmd->pos_stackb);
    if (cmd->total != 0)
        return (cmd->total);
    else if (cmd->pos_stackb >= temp->sizeB/2)
        cmd->total = move_bottom_of_stack(&temp, cmd->pos_stackb, cmd); // Se o i for acima do meio entao tens que fazer rb
    else if (cmd->pos_stackb <= temp->sizeB/2) // Se o i for acima do meio entao tens que fazer rrb
        cmd->total = move_top_of_stack(&temp, cmd->pos_stackb, cmd);
    return (cmd->total);
}

stacks_t   gen_moves(stacks_t main, int option, int counter, int pb_pa)
{

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
            main = rr_funct(main);
        if (option == 5)
            main = rrr_funct(main);
        counter--;
    }

    if (pb_pa == 1)
        main = pb_funct(main);
    else if (pb_pa == 2)
        main = pa_funct(main);
    // printf("\n\t(gen moves) done!");
    // printf("\n\t(simulate next) CHEGOU AQUI\n");
    // print_stacks(main);
    sleep(2);
    return (main);
}

int move_bottom_of_stack(stacks_t **temp, int place, moves_t *cmd)
{
    (void)temp;
    (void)place;
    (void)cmd;
    return (0);
}

int move_top_of_stack(stacks_t **temp, int place, moves_t *cmd)
{
    (void)temp;
    (void)place;
    (void)cmd;

    return (0);
}

int simulate_num1(stacks_t *temp, moves_t *cmd)
{
    init_cmd(&cmd[0]);
    printf("\n\t(simulate num 1) First simulate stack");
    print_stacks(*temp);
    cmd->total = special_cases(&temp, cmd, cmd->pos_stackb);

    if (cmd->total != 0)
    {
        print_stacks(*temp);
        sleep(2);
        printf("\n\t(simulate num 1) total = %d", cmd->total);
        return (cmd->total);    
    }
    else if (cmd->pos_stackb >= temp->sizeB/2)
        cmd->total = move_bottom_of_stack(&temp, cmd->pos_stackb, cmd); // Se o i for acima do meio entao tens que fazer rb
    else if (cmd->pos_stackb <= temp->sizeB/2) // Se o i for acima do meio entao tens que fazer rrb
        cmd->total = move_top_of_stack(&temp, cmd->pos_stackb, cmd);
    return (cmd->total);
}
