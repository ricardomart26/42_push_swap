#include "../push_swap.h"

int *organize_array(int *stack, int size)
{
    int i;
    int *org;

    org = malloc(sizeof(int) * size + 1);
    i = -1;
    while (i++ < size)
        org[i] = stack[i];
    i = 0;
    // printf("size = %d\n", size);
    while (!is_correct(org, size))
    {
        if (i >= size)
            i = 0;
        while (org[i] < org[i + 1] && i < size)
            i++;
        if (i < size)
            org = ft_swap(org, i);
        // printf("\n\t(org array) array A = %d && org A + 1 %d\n", org[i], org[i + 1]);
    }
    // print_array(org, size);
    // printf("\n");
    // sleep(3);
    return (org);
}
