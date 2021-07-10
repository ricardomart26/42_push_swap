#include "push_swap.h"

static int  find(int number, int *arr)
{
    int i;
    
    i = 0;
    while (arr[i])
    {
        // printf("\n\tarr[i] = %d", arr[i]);
        if (number == arr[i])
            return (i);
        i++;
    }
    return (-1);
}

static void    push_everything_to_b(stacks_t *main, int *org)
{   
    while (main->sizeA != 0)
    {
        main->lowest = *org;
        main->middle_size = main->sizeA/2;
        main->lowest_pos = find(*org, main->stackA);
        // printf("teste\n");
        // if (main->stackA[0] > main->stackA[1])
        //     *main = sa(*main, 1);
        if (main->lowest_pos == 0)
            *main = pb(*main);
        else if (main->lowest_pos > main->middle_size && main->sizeA != 0)
        {
            while (main->lowest_pos++ != main->sizeA)
                *main = rra(*main, 1);
            *main = pb(*main);
        }
        else if (main->lowest_pos <= main->middle_size && main->sizeA != 0)
        {
            while (main->lowest_pos-- != 0)
                *main = ra(*main, 1);
            *main = pb(*main);
        }
        org++;
        // print_stacks(*main);    
    }
}

stacks_t peanuts(stacks_t main, int size)
{
    int *org;
    (void)size;
    
    org = organize_array(main.stackA, main.sizeA - 1);
    // printf("\n\tStarting PEANUST baby!");
    push_everything_to_b(&main, org);
    while (main.sizeB != 0)
        main = pa(main);
    print_stacks(main);
    // printf("\n\t************* YOU DID %d MOVES **************\n", counter);
    return (main);
}
