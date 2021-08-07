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



int simulate_num2(stacks_t *temp, moves_t cmd, int *chunks, int i)
{
    if (i == 1)
    {
        printf("\n\t(simulate num 2) Starting simulate check four opt 2\n");
        print_stacks(*temp);
    }
    else if (i == 2)
    {
        printf("\n\t(simulate num 2) Starting simulate sim cmd 2\n");
        print_stacks(*temp);
        
    }
    if ((!closer_to_end2(*temp, chunks, &cmd)))
    	perror("\n\n\tCannot find chunk number in stackA\n"); // Encontrar primeiro numero dentro do stackA do final    
    cmd = get_cmds(*temp, cmd, temp->sizeB);
    
    cmd.total = num2(&temp, cmd);
    printf("\n\t(simulate num 2)Done simulate 2\n");
    // print_stacks(*temp);
    // sleep(3);
    
    return (cmd.total);
}

int simulate_num1(stacks_t *temp, moves_t cmd, int *chunks, int i)
{
    if (i == 1)
    {
        printf("\n\t(simulate num 1) Starting simulate check four opt 1\n");
        print_stacks(*temp);
    }
    else if (i == 2)
    {
        printf("\n\t(simulate num 2) Starting simulate sim cmd 1\n");
        print_stacks(*temp);
        
    }
    if ((!closer_to_beginning2(*temp, chunks, temp->size_chunk, &cmd)))
        perror("\n\n\tCannot find first number in chunk\n"); // Encontrar primeiro numero dentro do stackA do inicio
    
    cmd = get_cmds(*temp, cmd, temp->sizeB);
    cmd.total = num1(&temp, cmd);
    printf("\n\t(simulate num 1)Done simulate 1\n");
    // print_stacks(*temp);
    // sleep(3);

    return (cmd.total);
}
