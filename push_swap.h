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
    int lowest;
    int lowest_pos;
    int middle_size;
} stacks_t;


typedef struct moves_s
{
    int ra;
    int rra;
    int rb;
    int rrb;
    int rr;
    int rrr;
    int num1;
    int num2;
    int num3;
    int num4;
    int moves1;
    int moves2;
    int moves3;
    int moves4;
} moves_t;

#define pb 1
#define pa 1



stacks_t    do_easy_one(stacks_t main);
stacks_t    do_not_so_easy_one(stacks_t main);
stacks_t    beast_mode(stacks_t main);
stacks_t    peanuts(stacks_t main, int size);

void        print_array(int *stack, int size);
stacks_t    push_chunk_to_b(stacks_t main, int *chunks);
stacks_t    do_easy_one(stacks_t main);
stacks_t    do_not_so_easy_one(stacks_t main);


/* cmds */  
stacks_t    pa(stacks_t main);
stacks_t    pb(stacks_t main);
int         *push_to_p(int *stack, int *size, int number);
int         *organize_the_stack(int *stack, int size);

stacks_t    start_loop(stacks_t main, int *chunks);
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
int  find(int number, int *arr);
int    *ft_swap(int *stack, int i);


int ft_isntdigit(char c);
int is_valid(stacks_t main);
int is_correct(int *stack, int size);
int is_correct_stackB(int *stackB, int size);

stacks_t *combo1(stacks_t *main);
stacks_t *combo2(stacks_t *main);
stacks_t do_easy_one2(stacks_t main);




void    print_stacks(stacks_t main);
void    get_attr_chunks(int **chunks, int sizeA, int *org);
int *organize_array(int *stack, int size);

#endif