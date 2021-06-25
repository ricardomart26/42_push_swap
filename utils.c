#include "push_swap.h"

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
