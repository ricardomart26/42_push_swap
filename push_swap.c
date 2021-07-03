#include "push_swap.h"
/* Exprimentar com 0 no av  */

// int    is_lowest(int *middle_size, int *lowest_pos, int size, int *stackA)
// {
//     int i;
//     int x;
//     int lowest;

//     *middle_size = size/2;
//     i = 0;
//     x = 0;
//     // printf("size = %d\n", size);
//     while (x + i != size)
//     {
//         if (stackA[i] > stackA[i + x] && x + i != size)
//             i++;
//         else if (x + i != size)
//             x++;
//     }
//     lowest = stackA[i];
//     *lowest_pos = i;
//     printf("lowest = %d\n", lowest);
//     printf("lowest_pos = %d\n", *lowest_pos);
//     printf("middle_size = %d\n", *middle_size);
//     return (lowest);
// }

int find(int number, int *arr)
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

void    push_everything_to_b(stacks_t *main, int *org)
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
    // print_stacks(main);
    // printf("\n\t************* YOU DID %d MOVES **************\n", counter);
    return (main);
}

stacks_t do_easy_one(stacks_t main)
{
    chunk_t chunks;
    int *org;

    org = organize_array(main.stackA, main.sizeA - 1);
    get_attr_chunks(&chunks, main.sizeA, 2, org);
    print_stacks(main);
    main = pb(main);
    print_stacks(main);
    // main = start_loop(main, chunks);
    return (main);
}

stacks_t do_not_so_easy_one(stacks_t main)
{
    chunk_t chunks;
    int *org;
    org = organize_array(main.stackA, main.sizeA - 1);
    get_attr_chunks(&chunks, main.sizeA, 4, org);
    print_stacks(main);
    main = pb(main);
    print_stacks(main);
    // main = start_loop(main, chunks);
    return (main);
}

stacks_t beast_mode(stacks_t main)
{
    chunk_t chunks;
    int *org;

    org = organize_array(main.stackA, main.sizeA - 1);
    get_attr_chunks(&chunks, main.sizeA, 11, org);
    print_stacks(main);
    main = pb(main);
    print_stacks(main);
    // main = start_loop(main, chunks);
    return (main);
}

// stacks_t    start_loop(stacks_t main, chunk_t chunks)
// {

// }