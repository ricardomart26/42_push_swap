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


// void    push_chunk_to_b(stacks_t *main, int *chunk, int size, int divisor)
// {
//     while (main->sizeA/divisor != 0)
//     {
//         main->lowest = *chunk;
//         main->middle_size = main->sizeA/2;
//         main->lowest_pos = find(*chunk, main->stackA);
//         // printf("teste\n");
//         // if (main->stackA[0] > main->stackA[1])
//         //     *main = sa(*main, 1);
//         if (main->lowest_pos == 0)
//             *main = pb(*main);
//         else if (main->lowest_pos > main->middle_size && main->sizeA != 0)
//         {
//             while (main->lowest_pos++ != main->sizeA)
//                 *main = rra(*main, 1);
//             *main = pb(*main);
//         }
//         else if (main->lowest_pos <= main->middle_size && main->sizeA != 0)
//         {
//             while (main->lowest_pos-- != 0)
//                 *main = ra(*main, 1);
//             *main = pb(*main);
//         }
//         chunk++;
//         // print_stacks(*main);    
//     }
// }


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
    print_stacks(main);
    // printf("\n\t************* YOU DID %d MOVES **************\n", counter);
    return (main);
}


int find_closer_to_beginning(stacks_t main, int *chunk, int *hold_first, int size)
{
    int i;
    int x;

    i = 0;
    // printf("\n\tmiddle = %d", main.middle_size);
    // printf("\n\tsize= %d", size);

    while (size--)
    {
        x = 0;
        // print_array(chunk, main.middle_size);
        // sleep(2);
        while (main.stackA[i] != chunk[x] && x + 1 < main.middle_size)
        {
            // printf("\n\n\tstackA = %d", main.stackA[i]);
            // printf("\n\tchunk = %d", chunk[x]);
            // printf("\n\tx = %d", x);
            x++;
        }
        if (x + 1 == main.middle_size)
            i++;
        else
        {
            // printf("\n\tx + 2 = %d && middle = %d", x + 2, main.middle_size);
            *hold_first = i;
            // printf("\n\thold first = %d", *hold_first);
            // sleep(3);
            break;
        }
    }
    // printf("SAIU A TOA");
    if (size == 0)
        return (-1);
    else 
        return (1);
}

int find_closer_to_end(stacks_t main, int *chunk, int *hold_second)
{
    int size;
    int x;

    size = main.sizeA;
    // printf("\n\tmain.stackA = %d", main.stackA[size - 1]);
    // print_array(chunk, main.middle_size);
    // // sleep(2);

    while (main.stackA[size - 1])
    {
        x = 0;
        while (main.stackA[size - 1] != chunk[x] && x < main.middle_size)
            x++;
        if (x == main.middle_size)
            size--;
        else
        {
            *hold_second = x + 1;
            return (size - 1);
        }
    }
    return (-1);
}

stacks_t push_chunk_to_b(stacks_t main, chunk_t chunks, int *i)
{
    int hold_first;
    int hold_second;

    // printf("\n\tsizeB = %d\tmiddle_size = %d\n", main.sizeB, main.middle_size);
    // print_stacks(main);
    // sleep(2);
    while (main.sizeB != main.middle_size - 1)
    {
        // printf("\n\tstackA = %d", main.stackA[*i]);
        if ((!find_closer_to_beginning(main, chunks.chunks[*i], &hold_first, main.sizeA)))
            perror("\n\n\tCannot find first number in chunk\n");
        // printf("\tHold first = %d\n", hold_first);
        if ((!find_closer_to_end(main, chunks.chunks[*i], &hold_second)))
            perror("\n\n\tCannot find chunk number in stackA\n");
        // printf("\n\t = %d\t = %d\n",hold_first , hold_second);
        // sleep(2);
        if (hold_first >= hold_second)
        {
            while (hold_second-- != 1)
                main = rra(main, 1);
        }
        else if (hold_first-- < hold_second)
        {
            while (hold_first-- != -1)
                main = ra(main, 1);
        }
        main = pb(main);
        if (main.sizeB != 1)
        {
            while (!is_correct_stackB(main.stackB, main.sizeB))
            {
                
            }
        }
        print_stacks(main);
        // printf("\tHold second = %d\n", hold_second);
    }
    // printf("before i = %d\n", *i);

    // (*i)++;
    // printf("after i = %d\n", *i);
    return (main);
}

stacks_t do_easy_one(stacks_t main)
{
    chunk_t chunks;
    int *org;
    // int chunks_size = main.sizeA/2;
    int i;

    if (main.sizeA % 2 != 0)
        main.middle_size = main.sizeA/2 + 1;
    else
        main.middle_size = main.sizeA/2;

    i = 0;
    org = organize_array(main.stackA, main.sizeA - 1);
    get_attr_chunks(&chunks, main.sizeA, 2, org);
    main = push_chunk_to_b(main, chunks, &i);
    // print_stacks(main);
    // main = pb(main);
    // print_stacks(main);
    // print_array(chunks.chunks[0], chunks_size);
    // print_array(chunks.chunks[1], chunks_size);

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
    // main = start_loop(main, chunks);
    return (main);
}

// stacks_t    start_loop(stacks_t main, chunk_t chunks)
// {

// }