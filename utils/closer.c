#include "../push_swap.h"

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
            printf("\n\tNot in chunk stackA[%d] %d\n", i, main.stackA[i]);
            sleep(2);
            i++;
        }
        else
        {
            cmd->ra = i;
			cmd->rra = 0;
            cmd->num = main.stackA[i];
            if (cmd->num > 53)
            {
                printf("\n\t(closer to beg) num %d and why?\n", cmd->num);
            }
            printf("\n\t(find closer to beginning) stack[%d] %d\n", i, main.stackA[i]);
            sleep(2);
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
        {
            printf("\n\tNot in chunk stackA[%d] %d\n", size, main.stackA[size]);
            sleep(1);
            size--;
        }
        else
        {
			cmd->rra = main.sizeA - size;
            printf("\n\t(closer to end) size of chunk %d && rra %d\n", main.size_chunk, cmd->rra);
            print_stacks(main);
            sleep(5);
			cmd->ra = 0;
            cmd->num = main.stackA[size];
            if (cmd->num > 53)
            {
                printf("\n\t(closer to end)num %d and why?\n", cmd->num);
            }
            printf("\t(closer to end) 3 stack[%d] %d\n", main.sizeA - size, main.stackA[size]);
            sleep(2);
            return (size);
        }
    }
    return (-1);
}

