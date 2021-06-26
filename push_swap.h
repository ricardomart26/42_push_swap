#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct stacks_s
{
    int *stackA;
    int *stackB;
    int sizeA;
    int sizeB;
    int ac;
    int lower_in_stack;
} stacks_t;

typedef struct chunks_s
{
    int *chunk1;
    int *chunk2;
    int *chunk3;
    int *chunk4;
    int size;
    int if_neg;
} chunks_t;


stacks_t do_easy_one(stacks_t main);
stacks_t do_not_so_easy_one(stacks_t main);
stacks_t beast_mode(stacks_t main);

/* cmds */
stacks_t pa(stacks_t main);
stacks_t pb(stacks_t main);
int    *push_to_p(int *stack, int *size, int number);
int    *organize_the_stack(int *stack, int size);


/* cmds2 */
stacks_t ra(stacks_t main, int option);
stacks_t rb(stacks_t main, int option);
stacks_t rr(stacks_t main);
stacks_t rra(stacks_t main, int option);
stacks_t rrb(stacks_t main, int option);

/* cmds3 */
stacks_t rrr(stacks_t main);
stacks_t sa(stacks_t main, int option);
stacks_t sb(stacks_t main, int option);
stacks_t ss(stacks_t main);


int ft_strlen(char *str);
int ft_atoi(char *str);

int ft_isntdigit(char c);
int is_valid(stacks_t main);

void    print_stacks(stacks_t main);

int do_chunk1(int *stackA, chunks_t *chunks, int lower);
int do_chunk2(int *stackA, chunks_t *chunks, int bigger);
int do_chunk3(int *stackA, chunks_t *chunks, int bigger);
int do_chunk4(int *stackA, chunks_t *chunks, int bigger);
void    get_attr_chunks(chunks_t *chunks, int sizeA);


int find_lower(int *stackA, int number);
int find_lower_limit(int *stackA, int number, int bigger);




#endif