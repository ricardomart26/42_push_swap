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
            return (cmd.rr + pb);
        }
        else
        {
            ***temp = gen_moves(***temp, 0, cmd.ra, 1);
            return (cmd.rr - cmd.ra + pb);
        }
    }
    else if (cmd.rra)
    {
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
    return (i);
}

// int special_cases(stacks_t **temp, moves_t cmd, int place)
// {
//     if (place == 0)
//     {
//         // if (cmd.num == 21)
//         // {
//             // print_stacks(**temp);
//             // sleep(5);
//             // exit(0);
//         // }
//         if (cmd.ra)
//             **temp = gen_moves(**temp, 0, cmd.ra, 1);
//         else if (cmd.rra)
//             **temp = gen_moves(**temp, 1, cmd.rra, 1);
//         else
//             **temp = gen_moves(**temp, 1, 0, 1);
//         return (cmd.ra + cmd.rra + pb);
//     }
//     else if (place == (*temp)->sizeB && cmd.num != (*temp)->lowest)
//     {
//         if ((*temp)->sizeB <= 1)
//         {
//             **temp = gen_moves(**temp, 0, cmd.ra, 0);
//             **temp = gen_moves(**temp, 1, cmd.rra, 1);
//             return (cmd.ra + cmd.rra + pb);
//         }
//         return (put_last(&temp, cmd));
//     }
//     return (0);
// }

int simulate_num2(stacks_t *temp, moves_t cmd)
{
    // init_cmd(&cmd);
    cmd.total = num2(&temp, cmd);
    // printf("\n\t simulate second\n");
    // print_stacks(*temp);
    // sleep(3);
    // printf("\n\t\n");
    if (cmd.total != 0)
        return (cmd.total);
    return (0);

}

int simulate_num1(stacks_t *temp, moves_t cmd)
{
    cmd.total = num1(&temp, cmd);
    // printf("\n\t simulate first\n");
    // print_stacks(*temp);
    // sleep(3);
    // printf("\n\tteste\n");
    if (cmd.total != 0)
        return (cmd.total);
    return (0);

}
