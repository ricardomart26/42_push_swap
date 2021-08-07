#include "../push_swap.h"

int is_lowest_array(int x, int *array, int size)
{
    int i;

    i = 0;
    while (array[i] > x && i < size)
        i++;

    if (i == size)
        return (1);
    else
        return (0);
}

int place_in_array(int *stack, int num)
{
    int i;

    i = 0;
    while (stack[i] != num)
        i++;
    return (i);
}

int biggest_num(int *stack, int size)
{
    int i;
    int temp;

    i = 0;
    temp = stack[i];
    if (size == 2)
    {
        if (stack[i] > stack[i + 1])
            return (stack[i]);
        else
            return (stack[i + 1]);
    }

    while (i < size - 1)
    {
        while (temp > stack[i] && i < size - 1)
        {
            // printf("\n\ttemp %d stack[%d + 1] %d\n", temp, i, stack[i]);
            // sleep(1);
            i++;
        }
        if (temp < stack[i])
            temp = stack[i];
        i++;
    }
    return (temp);
}
