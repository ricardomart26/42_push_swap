#include "../push_swap.h"

int closer_to_beginning2(stacks_t main, int *chunk, int size, moves_t *cmd)
{
    int i;
    int x;
    int size1;

    i = 0;
    while (size + 1)
    {
        x = 0;
        while (main.stackA[i] != chunk[x] && x < main.size_chunk + 1)
        {
            printf("\n\t(beg) Is %d inside of chunk[%d] %d", main.stackA[i], x, chunk[x]);
            x++;
        }
        if (x == main.size_chunk + 1)
            i++;
        else
        {
            printf("\n\n\t(beg) This num %d is really inside of chunk[%d] %d\n", main.stackA[i], x, chunk[x]);

            cmd->ra = i;
			cmd->rra = 0;
            cmd->num = main.stackA[i];
            break;
        }
        size--;
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
    while (size + 1)
    {
        x = 0;
        while (main.stackA[size] != chunk[x] && x < main.size_chunk + 1)
        {
            printf("\n\t(end) Is %d inside of chunk[%d] %d", main.stackA[size], x, chunk[x]);
            x++;
        }
        if (x == main.size_chunk + 1)
            size--;
        else
        {
            printf("\n\n\t(end) This num %d is really inside of chunk[%d] %d\n", main.stackA[size], x, chunk[x]);
			cmd->rra = main.sizeA - size;
			cmd->ra = 0;
            cmd->num = main.stackA[size];
            return (size);
        }
    }
    return (-1);
}

