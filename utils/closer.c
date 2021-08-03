#include "../push_swap.h"

// moves_t *set_cmd_num(moves_t *cmd, int i, int number, int *counter)
// {
//     cmd->ra = i;
//     cmd->rra = 0;
//     cmd->num[*counter] = number;
//     (*counter)++;
// }

// int sec_closer_to_beginning2(stacks_t *main, int *chunk, int size, moves_t *cmd)
// {
//     int i;
//     int x;
//     int counter;

//     counter = 0;
//     i = 0;
//     while (size--)
//     {
//         x = 0;
//         while (main->stackA[i] != chunk[x] && x + 1 < main->middle_size)
//             x++;
//         if (x + 1 == main->middle_size)
//             i++;
//         else
//             cmd = set_cmd_num(cmd, i, main->stackA[i], &counter);
//         printf("\n\t(find closer to beginning) stack[%d] %d\n", i, main->stackA[i]);
//         if (counter >= 2)
//             break;
//     }
//     if (size == 0)
//         return (-1);
//     return (1);
// }   

// int sec_closer_to_end2(stacks_t *main, int *chunk, moves_t *cmd)
// {
//     int size;
//     int x;

//     size = main->sizeA - 1;
//     // printf("\t(find closer to end) 1 stack[%d] %d\n", size, main->stackA[size]);
//     while (size)
//     {
//         x = 0;
//         // printf("\t(find closer to end) 2 stack[%d] %d\n", size, main->stackA[size]);
//         while (main->stackA[size] != chunk[x] && x < size)
//             x++;
//         // printf("\t(find closer to end) 69 x %d e size %d\n", x, size);
//         if (x == size)
//         {
//             size--;
//             // printf("\t(find closer to end) size diminui-o\n");
//         }
//         else
//         {
// 			cmd->rra = main->sizeA - size;
// 			cmd->ra = 0;
//             cmd->num[0] = main->stackA[size];
//             printf("\t(find closer to end) 3 stack[%d] %d\n", size, main->stackA[size]);
//             return (size);
//         }
//     }
//     return (-1);
// }

int closer_to_beginning2(stacks_t main, int *chunk, int size, moves_t *cmd)
{
    int i;
    int x;
    int size1;

    i = 0;
    while (size--)
    {
        x = 0;
        while (main.stackA[i] != chunk[x] && x < main.size_chunk)
        {
            // printf("\n\tchunk[%d] %d\n", x, chunk[x]);
            // sleep(2);
            x++;
        }
        if (x == main.size_chunk)
        {
            // printf("\n\tNot in chunk stackA[%d] %d\n", i, main.stackA[i]);
            // sleep(2);
            i++;
        }
        else
        {
            cmd->ra = i;
			cmd->rra = 0;
            cmd->num = main.stackA[i];
            if (cmd->num > 513)
            {
                printf("\n\tnum %d and why?\n");
            }
            // printf("\n\t(find closer to beginning) stack[%d] %d\n", i, main.stackA[i]);
            // sleep(2);
            break;
        }
    }
    if (size == 0)
        return (-1);
    return (1);
}   

int closer_to_end2(stacks_t main, int *chunk, moves_t *cmd)
{
    int size;
    int x;

    size = main.sizeA - 1;
    while (size)
    {
        x = 0;
        while (main.stackA[size] != chunk[x] && x < main.size_chunk)
            x++;
        if (x == main.size_chunk)
            size--;
        else
        {
            printf("\n\tchunk %d\n", main.size_chunk);
            sleep(2);
			cmd->rra = main.size_chunk - size;
			cmd->ra = 0;
            cmd->num = main.stackA[size];
            if (cmd->num > 513)
            {
                printf("\n\tnum %d and why?\n");
            }
            // printf("\t(find closer to end) 3 stack[%d] %d\n", main.sizeA - size, main.stackA[size]);
            // sleep(2);
            return (size);
        }
    }
    return (-1);
}

