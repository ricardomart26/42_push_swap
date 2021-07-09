#include "push_swap.h"



int    *ft_swap(int *stack, int i)
{
    int temp;
    // printf("\ni %d", i);
    // printf("\n before %d %d", stack[i], stack[i + 1]);
    temp = stack[i + 1];
    stack[i + 1] = stack[i];
    stack[i] = temp;
    // printf("\n after %d %d", stack[i], stack[i + 1]);
    return (stack);
}

int *organize_array(int *stack, int size)
{
    int i;
    int *org;

    org = malloc(sizeof(int) * size + 1);
    i = -1;
    while (i++ < size)
        org[i] = stack[i];
    i = 0;
    // printf_array(stack, size);
    // printf("size = %d\n", size);
    while (!is_correct(org, size - 1))
    {
        // printf("i = %d\n", i);
        if (i >= size)
            i = 0;
        while (org[i] < org[i + 1] && i < size)
            i++;
        if (i < size)
            org = ft_swap(org, i);
        // printf("\n\tis organize array A = %d && org A + 1 %d", org[i], org[i + 1]);
        // printf();
        // print_array(org, size);
    }
    print_array(org, size + 1);
    printf("\n");

    return (org);
}
