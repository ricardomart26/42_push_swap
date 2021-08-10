#include "../push_swap.h"

stacks_t pass_stacks_to_temp(stacks_t main)
{
    stacks_t temp;
    int x;

    temp.stackA = malloc(sizeof(int) * main.sizeA + 1);
    temp.lowest = main.lowest;
    temp.size_chunk = main.size_chunk;
    temp.middle_size = main.middle_size;
    temp.sizeA = main.sizeA;
    temp.sizeB = main.sizeB;
    x = 0;
    while (main.stackA[x])
    {
        temp.stackA[x] = main.stackA[x];
        x++;
    }
    x = 0;
    if (main.sizeB != 0)
    {
        temp.stackB = malloc(sizeof(int) * main.sizeB + 1);
        while (main.stackB[x])
        {
            temp.stackB[x] = main.stackB[x];
            x++;
        }
    }
    return (temp);
}

int do_end(stacks_t temp, int *chunks)
{
    int mv[2];
    moves_t cmd[2];

    init_cmd(&cmd[0]);
    init_cmd(&cmd[1]);

    if (temp.sizeB == 4)
    {
        closer_to_beginning2(temp, chunks, temp.sizeA, &cmd[0]);
        closer_to_end2(temp, chunks, &cmd[1]);
        if (cmd[0].num <= cmd[1].num)
            return (4);
        else
            return (5);

        // printf("\n\t(do final move) mv[0] %d mv[1] %d\n", mv[0], mv[1]);
        // print_stacks(temp);
        // sleep(3);
    }
    else
    {
        mv[0] = simulate_next_f(temp, chunks, 1);
        mv[1] = simulate_next_s(temp, chunks, 1);

        // printf("\n\t(do final move) mv[0] %d mv[1] %d\n", mv[0], mv[1]);
        // print_stacks(temp);
        // sleep(3);
        // exit(0);
        if (mv[0] <= mv[1])
            return (4);
        else if (mv[0] > mv[1])
            return (5);
    }
}

int search_in_chunk(stacks_t temp, int *chunk, int sizeA)
{
    int ret;
    int i;
    int x;

    i = 0;
    ret = 0;
    while (i < sizeA && ret < 2)
    {
        x = 0;
        while (temp.stackA[i] != chunk[x] && x < temp.size_chunk)
        {
            // printf("\n\tsize of chunk %d stackA[%d] %d and chunk[%d] %d\n", temp.size_chunk, i, temp.stackA[i], x, chunk[x]);
            x++;
        }
        if (x != temp.size_chunk)
        {
            // printf("\n\tstackA[%d] %d is in chunk[%d] %d\n", i, temp.stackA[i], x, chunk[x]);
            // sleep(2);
            ret++;
        } 
        i++;
    }
    return (ret);
}

int check_four_opt(stacks_t main, int *chunks)
{
    stacks_t temp;
    int movesss;
    int mv[4];
    int nums_in_chunk;

    movesss = 0;
    temp = pass_stacks_to_temp(main);
    
    nums_in_chunk = search_in_chunk(temp, chunks, temp.sizeA);
    if (nums_in_chunk == 0 || temp.sizeA < 3)
    {
        // printf("\n\tNo numbers of chunk in stackA\n");
        return (-1);
    }
    else if (nums_in_chunk == 1 || temp.sizeA == 4)
    {
        // printf("\n\tOnly one number of chunk in stackA\n");
        // sleep(3);
        movesss = do_end(temp, chunks);
        return (movesss);
    }
        
    movesss = simulate_num1(&temp, chunks, 0);
    mv[0] = simulate_next_f(temp, chunks, movesss);
    mv[1] = simulate_next_s(temp, chunks, movesss);

    free_all_stacks_t(&temp);
    temp = pass_stacks_to_temp(main);
    
    movesss = simulate_num2(&temp, chunks, 0);
    mv[2] = simulate_next_f(temp, chunks, movesss);
    mv[3] = simulate_next_s(temp, chunks, movesss);


    // printf("\n\t**********FINISH NUM 2!**********\n");

    // printf("\n\t(check four opt final) mv[0] %d mv[1] %d mv[2] %d mv[3] %d\n", mv[0], mv[1], mv[2], mv[3]);

    free_all_stacks_t(&temp);
    temp = pass_stacks_to_temp(main);
    return(return_best_opt(mv, temp, chunks));
}

// ver tamanho do stackB, e em que index o numero deve ficar, e para que lado e mais rapido
stacks_t push_chunk_to_b2(stacks_t main, int *chunks)
{
    int counter;
    int option;

    counter = 0;
    while (counter <= main.size_chunk + 1)
    {
        option = 0;
        option = check_four_opt(main, chunks);
        if (option == -1)
            break;
        // printf("\n\t(Finished sim)");
        main = do_opt(main, chunks, option);
        if (main.sizeA == 3)
            break;
        // printf("\n\t(Finished real)");
        // print_stacks(main);
        counter += 2;
        // printf("\n\tHEYYYYYY\n");
    }
    return (main);
}


void stackB_correct(stacks_t *main, int size)
{
    int max;
    int max_place;

    max = biggest_num(main->stackB, size);
    max_place = place_in_array(main->stackB, max);
    if (max_place <= size/2)
        *main = gen_moves_real(*main, 2, max_place, 0);
    else if (max_place > size /2)
        *main = gen_moves_real(*main, 3, size - max_place, 0);
}



stacks_t last3_stackA(stacks_t main)
{
    int lower;
    int lower_pos;

    // print_stacks(main);
    // sleep(2);
    lower_pos = 0;
    lower = 0;
    stackB_correct(&main, main.sizeB);
    if (!is_lowest_array(main.stackB[0], main.stackA, main.sizeA))
    {
        lower = lowest_num(main.stackA, main.sizeA);
        lower_pos = place_in_array(main.stackA, lower);
        // printf("\n\tlower %d lower_pos %d\n", lower, lower_pos);
        if (lower < main.stackB[0])
        {
            if (lower_pos == 2 && main.stackA[0] > main.stackA[1])
            {
                main = sa_funct(main, 1);
                while (main.stackA[main.sizeA - 1] < main.stackB[0])
                    main = pa_funct(main, 1);
                main = rra_funct(main, 1);
                while (main.stackB[0] < main.stackA[0] && main.sizeB != 0)
                    main = pa_funct(main, 1);
            }
        }
    }
    else if (!is_correct(main.stackA, 3))
    {
        if (main.stackA[0] > main.stackA[1])
            main = sa_funct(main, 1);
        while (!is_lowest_array(main.stackA[0], main.stackA, main.sizeA))
            main = ra_funct(main, 1);
        while (main.stackB[0] < main.stackA[0] && main.sizeB != 0)
            main = pa_funct(main, 1);
    }
    
    return (main);
}

stacks_t do_easy_one2(stacks_t main)
{
    int *chunks;
    int *org;

    // Fazer um while com estes dois para poder dividir função
    while (main.sizeA != 3) // Enquanto nao houver 3 numeros no stackA
    {
        org = organize_array(main.stackA, main.sizeA - 1); // Organizar o array
        main.lowest = org[0];
        if (main.sizeA % 2 != 0) // ver se tamanho e par ou impar para saber onde esta o meio
            main.middle_size = main.sizeA/2 + 1; // Se for impar, como a divisao arredonda para baixo, aumentar 1
        else
            main.middle_size = main.sizeA/2; // Se for par so e preciso dividir por 2
        main.size_chunk = get_attr_chunks(&chunks, main.middle_size, org); // Receber a chunk1 e a chunk 2
        // printf("\n\n\n\n\n\t(do easy one) Printing chunk and chunk size %d middle size %d\n", main.size_chunk, main.middle_size);
        // print_stacks(main);
        // print_array(chunks, main.middle_size);
        main = push_chunk_to_b2(main, chunks); // Empurrar a chunk para o stackB
    }
    // printf("\n\tHEYYYYYY\n");
    main = last3_stackA(main);
    // print_stacks(main);
    return (main);
}
