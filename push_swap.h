#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>

typedef struct stacks_s
{
    int *stackA;
    int *stackB;
    int sizeA;
    int sizeB;
    int ac;

} stacks_t;

stacks_t do_easy_one(stacks_t main);
stacks_t do_not_so_easy_one(stacks_t main);
stacks_t beast_mode(stacks_t main);


stacks_t sa(stacks_t main);
stacks_t sb(stacks_t main);
stacks_t ss(stacks_t main);
stacks_t ra(stacks_t main);
stacks_t rb(stacks_t main);
stacks_t rr(stacks_t main);
stacks_t rra(stacks_t main);
stacks_t rrb(stacks_t main);
stacks_t rrr(stacks_t main);
stacks_t pa(stacks_t main);
stacks_t pb(stacks_t main);

int ft_strlen(char *str);
int ft_atoi(char *str);

int ft_isntdigit(char c);
int is_valid(stacks_t main);

void    print_stacks(stacks_t main);



#endif