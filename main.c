#include "push_swap.h"

stacks_t get_av(stacks_t main, char **av)
{
    int x;

    x = 1;
    while (av[x])
    {
        main.stackA[x - 1] = ft_atoi(av[x]);
        x++;
    }
    // get_chunks(&main);
    
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

int main(int ac, char **av)
{
    stacks_t main;

    init_struct(&main, ac);
    main = get_av(main, av);
    if (!is_valid(main))
        perror("ERROR: NUMBER DUP\n\n");
    if (ac < 20)
        main = do_easy_one(main);
    else if (ac < 100)
        main = do_not_so_easy_one(main);
    else
        main = beast_mode(main);

    // if (ac < 50)
        // main = do_easy_one(main);
}