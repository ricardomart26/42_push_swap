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
    return (main);
}

void    init_struct(stacks_t *main, int ac)
{
    main->ac = ac - 1;
    main->stackA = calloc(ac - 1, sizeof(int));
    if (!main->stackA)
        return ;
    main->sizeA = ac - 1;
    main->sizeB = 0;
}

int main(int ac, char **av)
{
    stacks_t main;

    init_struct(&main, ac); // Iniciar a struct do main, alocar memoria para o stackA, e o tamanho de sizeA
    main = get_av(main, av); // Passar os numeros para o stackA
    if (!is_valid(main)) // Verificar se tem numeros dup
        perror("ERROR: NUMBER DUP\n\n");
    if (ac < 20)
        main = peanuts(main, main.sizeA); 
    else if (ac < 99)
        main = do_easy_one2(main);
    else if (ac < 500)
        main = do_not_so_easy_one(main);
    else
        main = beast_mode(main);
}