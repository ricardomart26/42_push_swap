#include "../push_swap.h"

void print_array(int *stack, int size)
{
    int i;

    i = 0;
    while (size)
    {
        printf("\n\t%d print array %d", i, stack[i]);
        i++;
        size--;
    }
}

void    print_cmds(moves_t *cmd, int i)
{
    printf("\n\n\t************\n");
    printf("\t**  ra  = %d  **\n", cmd[i].ra);
    printf("\t**  rb  = %d  **\n", cmd[i].rb);
    printf("\t**  rr  = %d  **\n", cmd[i].rr);
    printf("\t**  rra  = %d **\n", cmd[i].rra);
    printf("\t**  rrb  = %d **\n", cmd[i].rrb);
    printf("\t**  rrr  = %d **\n", cmd[i].rrr);
    printf("\t**  pos B = %d **\n", cmd[i].pos_stackb);
    printf("\t**  total = %d **\n", cmd[i].total);
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