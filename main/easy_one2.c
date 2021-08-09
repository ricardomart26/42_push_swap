#include "../push_swap.h"

stacks_t pass_stacks_to_temp(stacks_t main)
{
    stacks_t temp;
    int x;

    temp.stackA = malloc(sizeof(int) * main.sizeA  + 1);
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

void    free_all_cmd(moves_t **cmd)
{
    free(cmd[0]);
    free(cmd[1]);
}

int do_end(stacks_t temp, moves_t *cmd, int *chunks)
{
    int mv[2];

    mv[0] = simulate_next_f(temp, chunks, 0);
    mv[1] = simulate_next_s(temp, chunks, 0);

    printf("\n\t(do end) mv[0] %d mv[1] %d\n", mv[0], mv[1]);
    print_stacks(temp);
    exit(0);
    if (mv[0] >= mv[1])
        return (5);
    else if (mv[1] > mv[0])
        return (6);
}

int check_four_opt(stacks_t main, int *chunks)
{
    moves_t  *cmd;
    stacks_t temp;
    int movesss;
    int mv[4];

    cmd = calloc(2, sizeof(moves_t));
    // init_cmd(cmd);
    print_cmds(*cmd);
    print_cmds(cmd[1]);
    sleep(3);
    movesss = 0;
    
    temp = pass_stacks_to_temp(main);
    // printf("\n\t\t size_chunk - 1 %d && sizeB %d\n\n", temp.size_chunk - 1, temp.sizeB);
    // sleep(2);
    
    if (temp.size_chunk - 1 == temp.sizeB)
    {
        movesss = do_end(temp, cmd, chunks);
        printf("\n\t\t movesss %d\n\n", movesss);
        sleep(2);
        return (movesss);
    }
    
    movesss = simulate_num1(&temp, cmd[0], chunks);

    mv[0] = simulate_next_f(temp, chunks, movesss);
    mv[1] = simulate_next_s(temp, chunks, movesss);

    printf("\n\t**********FINISH NUM 1!**********\n");
    free_all_stacks_t(&temp);
    temp = pass_stacks_to_temp(main);
    
    movesss = simulate_num2(&temp, cmd[1], chunks);
    mv[2] = simulate_next_f(temp, chunks, movesss);
    mv[3] = simulate_next_s(temp, chunks, movesss);

    printf("\n\t**********FINISH NUM 2!**********\n");

    printf("\n\t(check four opt final) mv[0] %d mv[1] %d mv[2] %d mv[3] %d\n", mv[0], mv[1], mv[2], mv[3]);
    sleep(2);

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
    while (counter < main.size_chunk)
    {
        option = 0;
        option = check_four_opt(main, chunks);

        printf("\n\t(Finished sim)");
        main = do_opt(main, chunks, option);
        
        printf("\n\t(Finished real)");
        print_stacks(main);
        counter += 2;

        sleep(3);
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
        printf("\n\t(do easy one) Printing chunk and chunk size %d middle size %d\n", main.size_chunk, main.middle_size);
        print_stacks(main);
        print_array(chunks, main.middle_size);
        sleep(3);
        main = push_chunk_to_b2(main, chunks); // Empurrar a chunk para o stackB
    }
    return (main);
}
