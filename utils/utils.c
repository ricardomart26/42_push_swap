#include "../push_swap.h"

int ft_strlen(char *str)
{
    int c;

    c = 0;
    while (str[c])
        c++;
    return (c);
}

int ft_atoi(char *str)
{
    int c;
    long int ret;
    int size;

    size = ft_strlen(str);
    if (*str == '0' && size == 1)
        return (0);
    if (size > 10)
        perror("ERROR: NUMBER TO BIG\n\n");
    ret = 0;
    c = 0;
    while (str[c])
    {
        if (ft_isntdigit(str[c]))
            perror("ERROR: That isnt a digit\n\n");
        ret += str[c] - '0';
        if (size != 1 && str[c + 1] != '\0')
            ret *= 10;
        c++;
    }
    if (ret > 2147483647)
        perror("ERROR: NUMBER TO BIG\n\n");
    // printf("\nret in atoi %ld\n", ret);
    return ((int)ret);
}

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

int  find(int number, int *arr)
{
    int i;
    
    i = 0;
    while (arr[i])
    {
        if (number == arr[i])
            return (i);
        i++;
    }
    return (-1);
}