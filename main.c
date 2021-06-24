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
    int ret;
    int size;

    size = ft_strlen(str);
    if (*str == '0' && size == 1)
        return (0);
    ret = 0;
    c = 0;
    while (str[c])
    {
        ret += str[c] - '0';
        if (size != 1 && str[c + 1] != '\0')
            ret *= 10;
        c++;
    }
    printf("\nret in atoi %d\n", ret);
    return (ret);
}

stacks_t get_av(stacks_t main, char **av)
{
    int x;

    x = 1;
    while (av[x])
    {
        main.stackA[x] = ft_atoi(av[x]);
        x++;
    }
    get_chunks(&main);
    
    return (main);
}

void    init_struct(stacks_t *main, int ac)
{
    main->ac = ac - 1;
    main->stackA = calloc(ac - 1, sizeof(int));
    if (!main->stackA)
        return ;
    main->sizeA = ac - 1;
}

stacks_t do_easy_one(stacks_t main)
{

}


int main(int ac, char **av)
{
    stacks_t main;

    init_struct(&main, ac);
    main = get_av(main, av);
    if (ac < 50)
        main = do_easy_one(main);
}