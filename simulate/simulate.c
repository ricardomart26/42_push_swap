#include "../push_swap.h"

// int put_last(stacks_t ***temp, moves_t cmd)
// {
//     /*
//     Se estiver na metade de baixo do stackA, e o numero 
//     for para a metade de cima do stack B.
//     Converter para rr, e se tiver mais ra fazer ate o numero 
//     da stackA ficar na 1º posição e fazer um pb e um rra
//     */
//     if (cmd.ra)
//     {
//         cmd.rr = 1;
//         cmd.ra--;
//         ***temp = gen_moves(***temp, 4, 1, 0);
//         if (!cmd.ra)
//         {
//             ***temp = gen_moves(***temp, 0, 0, 1);
//             return (cmd.rr + pb);
//         }
//         else
//         {
//             ***temp = gen_moves(***temp, 0, cmd.ra, 1);
//             return (cmd.rr - cmd.ra + pb);
//         }
//     }
//     else if (cmd.rra)
//     {
//         ***temp = gen_moves(***temp, 1, cmd.rra, 0);
//         if (cmd.ra == 0)
//         {
//             ***temp = gen_moves(***temp, 0, 0, 1);
//             return (cmd.rr + pb);
//         }
//     }
//     return (0);
// }

// int higgest_num(int *stack)
// {
//     int x;
//     int i;
//     int temp;

//     i = 0;
//     x = 0;
//     temp = 0;
//     while (stack[x] != 0)
//     {
//         if (temp < stack[x])
//         {
//             temp = stack[x];
//             i = x;
//         }
//         x++;
//     }
//     return (i);
// }



// void    reset_cmd(moves_t *cmd)
// {
//     cmd->num = 0;
//     cmd->pos_stackb = 0;
//     cmd->ra = 0;
//     cmd->rb = 0;
//     cmd->rr = 0;
//     cmd->rra = 0;
//     cmd->rrb = 0;
//     cmd->rrr = 0;
//     cmd->total = 0;
// }

int simulate_num2(stacks_t *temp, int *chunks, int opt)
{
    moves_t cmd;

    init_cmd(&cmd);
    closer_to_end2(*temp, chunks, &cmd);

    cmd = get_cmds(*temp, cmd, temp->sizeB);
    
    // printf("\n\t(simulate num 2)Before 2 , num is %d", cmd.num);
    // print_stacks(*temp);
    // print_cmds(cmd);
 
    if (opt)
        cmd.total = num2(&temp, cmd);
    else
        cmd.total = num2_fake(&temp, cmd);

    // printf("\n\t(simulate num 2)After 2");
    // print_stacks(*temp);
    
    return (cmd.total);
}

int simulate_num1(stacks_t *temp, int *chunks, int opt)
{
    moves_t cmd;

    init_cmd(&cmd);
    
    closer_to_beginning2(*temp, chunks, temp->sizeA, &cmd);

    cmd = get_cmds(*temp, cmd, temp->sizeB);
    
    // printf("\n\t(simulate num 1)Before 1, num is %d", cmd.num);
    // print_stacks(*temp);
    // print_cmds(cmd);
    
    if (opt)
        cmd.total = num1(&temp, cmd);
    else
        cmd.total = num1_fake(&temp, cmd);

    // printf("\n\t(simulate num 1)after");
    // print_stacks(*temp);
    
    return (cmd.total);
}
