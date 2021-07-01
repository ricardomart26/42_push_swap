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

} stacks_t;

typedef struct chunk_s
{
    int **chunks;
    int size;
    int if_neg;
    int middle_in_stack;

} chunk_t;


stacks_t do_easy_one(stacks_t main);
stacks_t do_not_so_easy_one(stacks_t main);
stacks_t beast_mode(stacks_t main);
void print_array(int *stack, int size);
chunk_t get_divisor_chunk(int *org, chunk_t chunks, int divisor, int size);

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
chunk_t *malloc_arrays(int size, int divisor, chunk_t *chunks);

// int do_chunk1(int *stackA, chunk_t *chunks, int lower, int divisor);
// int do_chunk3(int *stackA, chunk_t *chunks, int bigger, int divisor);
// int do_chunk2(int *stackA, chunk_t *chunks, int bigger, int divisor);
// int do_chunk4(int *stackA, chunk_t *chunks, int bigger, int divisor);
// void    get_attr_chunks2(chunk_t *chunks, int sizeA);

void    get_attr_chunks(chunk_t *chunks, int sizeA, int divisor);

int *organize_array(int *stack, int size);

// chunk_t get_chunks4(int *stackA, chunk_t chunks, int lower_in_stack);
// chunk_t get_chunks2(int *stackA, chunk_t chunks);
chunk_t get_divisor_chunks(int *org, chunk_t chunks, int divisor, int size);

// int find_lower(int *stackA, int number);
// int find_lower_limit(int *stackA, int number, int bigger);





#endif