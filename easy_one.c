#include "push_swap.h"

int where_to_putnbr(int x, int *stackB, int size)
{
    int i;

    i = 0;
    while (i < size)
    {
        while (x > stackB[i])
            i++;
        return (i);
    }
    return (0);
}

int find_closer_to_beginning(stacks_t main, int *chunk, int *hold_first, int size)
{
    int i;
    int x;

    i = 0;
    while (size--)
    {
        x = 0;
        while (main.stackA[i] != chunk[x] && x + 1 < main.middle_size)
            x++;
        if (x + 1 == main.middle_size)
            i++;
        else
        {
            *hold_first = i;
            break;
        }
    }
    if (size == 0)
        return (-1);
    return (1);
}

int find_closer_to_end(stacks_t main, int *chunk, int *hold_second)
{
    int size;
    int x;

    size = main.sizeA;
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

int    organize_stackB(stacks_t *main, int *org, int *control)
{
    int counter;
    int i_in_stackb;

    i_in_stackb = where_to_putnbr(main->stackA[0], main->stackB, main->sizeB);
    *main = pb(*main);
    if (i_in_stackb >= main->sizeB/2)
    {
        while (main->sizeB - i_in_stackb != 0)
            *main = rb(*main, 1);
    }
    if (i_in_stackb == 0)
    {
        *main = pb(*main);
        return (1);
    }
    if (i_in_stackb == main->sizeB - 1)
    {
        *main = pb(*main);
        *main = rb(*main, 1);
        return (1);
    }
    counter = 0;
    if (main->stackA[0] < main->stackB[main->sizeB - 1])
    {
        *control = 1;
        *main = pb(*main);
    }
    if (main->sizeB != 1)
    {
        while (!is_correct_stackB(main->stackB, main->sizeB))
        {
            if (main->stackA[0] < main->stackB[1])
            {
                if (main->stackB[0] == org[0])
                    *main = rb(*main, 1);
                *main = sb(*main, 1);
            }
            else
            {
                printf("\n\tstackB %d", main->stackB[main->sizeB - (counter + 1)]);
                sleep(2);
                while (main->stackA[0] < main->stackB[main->sizeB - (counter + 1)])
                {
                    *main = rrb(*main, 1);
                    counter++;
                }
            }
        }
    }
    return (counter);
}

// ver tamanho do stackB, e em que index o numero deve ficar, e para que lado e mais rapido
stacks_t push_chunk_to_b(stacks_t main, chunk_t chunks, int *i, int *org)
{
    int hold_first;
    int hold_second;
    int counter;
    int little_helper;

    little_helper = 0;
    while (main.sizeB != main.middle_size - 1)
        if ((!find_closer_to_beginning(main, chunks.chunks[*i], &hold_first, main.sizeA)))
    {
            perror("\n\n\tCannot find first number in chunk\n");
        if ((!find_closer_to_end(main, chunks.chunks[*i], &hold_second)))
            perror("\n\n\tCannot find chunk number in stackA\n");
        if (hold_first >= hold_second)
            while (hold_second-- != 1)
                main = rra(main, 1);
        else if (hold_first-- < hold_second)
            while (hold_first-- != -1)
                main = ra(main, 1);
        counter = organize_stackB(&main, org, &little_helper);
        // if (little_helper == 1)
        while (counter != 0)
        {
            main = rb(main, 1);
            counter--;
        }
        print_stacks(main);
    }
    return (main);
}

stacks_t do_easy_one(stacks_t main)
{
    chunk_t chunks;
    int *org;
    int i;

    i = 0;

    // Fazer um while com estes dois para poder dividir função
    // O middle size tem de ser updated
    while (main.sizeA != 3)
    {
        org = organize_array(main.stackA, main.sizeA - 1);
        if (main.sizeA % 2 != 0)
            main.middle_size = main.sizeA/2 + 1;
        else
            main.middle_size = main.sizeA/2;
        get_attr_chunks(&chunks, main.sizeA, 2, org);
        main = push_chunk_to_b(main, chunks, &i, org);
    }

    return (main);
}
