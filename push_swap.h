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
    int total;
    int num;
    int moves;
    int pos_stackb;
} moves_t;

#define pb 1
#define pa 1



int simulate_num2(stacks_t *temp, moves_t *cmd);
stacks_t   gen_moves(stacks_t main, int option, int counter, int pb_pa);
int where_to_putnbr2(int x, int *stackB, int size);

int move_bottom_of_stack(stacks_t **temp, int place, moves_t *cmd);
int move_top_of_stack(stacks_t **temp, int place, moves_t *cmd);
int special_cases(stacks_t **temp, moves_t *cmd, int place);
int simulate_num1(stacks_t *temp, moves_t *cmd);

int closer_to_beginning2(stacks_t main, int *chunk, int size, moves_t *cmd);
int closer_to_end2(stacks_t main, int *chunk, moves_t *cmd);

stacks_t get_av(stacks_t main, char **av);

stacks_t    do_easy_one2(stacks_t main);
stacks_t    do_not_so_easy_one(stacks_t main);
stacks_t    beast_mode(stacks_t main);
stacks_t    peanuts(stacks_t main, int size);

void        print_array(int *stack, int size);
stacks_t    push_chunk_to_b(stacks_t main, int *chunks);
stacks_t    do_not_so_easy_one(stacks_t main);

/* cmds */  
stacks_t    pa_funct(stacks_t main);
stacks_t    pb_funct(stacks_t main);
int         *push_to_p(int *stack, int *size, int number);
int         *organize_the_stack(int *stack, int size);

stacks_t    start_loop(stacks_t main, int *chunks);
/* cmds2 */
stacks_t ra_funct(stacks_t main, int option);
stacks_t rb_funct(stacks_t main, int option);
stacks_t rr_funct(stacks_t main);
stacks_t rra_funct(stacks_t main, int option);
stacks_t rrb_funct(stacks_t main, int option);
stacks_t rrr_funct(stacks_t main);

/* cmds3 */
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

void    init_struct(stacks_t *main, int ac);
void    init_cmd(moves_t *cmd);

void    print_stacks(stacks_t main);
void    get_attr_chunks(int **chunks, int sizeA, int *org);
int *organize_array(int *stack, int size);

#endif