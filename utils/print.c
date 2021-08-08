#include "../push_swap.h"

void print_array(int *stack, int size)
{
    int i;

    i = 0;

    while (size + 1)
    {
        printf("\n\t%d print array %d", i, stack[i]);
        i++;
        size--;
    }
}

void    print_cmds(moves_t cmd)
{
    printf("\n\n\t************\n");
    printf("\t**  ra  = %d  **\n", cmd.ra);
    printf("\t**  rb  = %d  **\n", cmd.rb);
    printf("\t**  rr  = %d  **\n", cmd.rr);
    printf("\t**  rra  = %d **\n", cmd.rra);
    printf("\t**  rrb  = %d **\n", cmd.rrb);
    printf("\t**  rrr  = %d **\n", cmd.rrr);
    printf("\t**  pos B = %d **\n", cmd.pos_stackb);
    printf("\t**  num = %d **\n", cmd.num);
    printf("\t**  total = %d **\n", cmd.total);
    printf("\t****************\n");
}

void    print_stacks(stacks_t main)
{
    int size;
    int c;

    c = 0;
    if (main.sizeA > main.sizeB)
        size = main.sizeA;
    else
        size = main.sizeB;
    
    printf("\n\n\t************\n");
    printf("\t** A ** B **\n");
    printf("\t************\n");
    printf("\t** %d ** %d **\n", main.sizeA, main.sizeB);
    printf("\t************\n");

    while (size--)
    {
        if (main.sizeA != 0 && main.sizeB != 0)
        {
            printf("\t** %d ** %d **\n", main.stackA[c], main.stackB[c]);
            main.sizeA--;
            main.sizeB--;    
        }
        else if (main.sizeA != 0 && main.sizeB == 0)
        {
            printf("\t** %d **   **\n", main.stackA[c]);
            main.sizeA--;
        }
        else if (main.sizeA == 0 && main.sizeB != 0)
        {
            printf("\t**   ** %d **\n", main.stackB[c]);
            main.sizeB--;
        }
        c++;
    }
    printf("\t************\n");
    printf("\t************\n");
}