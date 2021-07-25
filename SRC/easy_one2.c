#include "../push_swap.h"

int where_to_putnbr2(int x, int *stackB, int size)
{
   int i;

    i = 0;
    while (i < size)
    {
        while (x < stackB[i])
            i++;
        return (i);
    }
    return (0);
}

stacks_t pass_stacks_to_temp(stacks_t main)
{
    stacks_t temp;
    int x;

    temp.stackA = malloc(sizeof(int) * main.sizeA);

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
        temp.stackB = malloc(sizeof(int) * main.sizeB);
        while (main.stackB[x])
        {
            temp.stackB[x] = main.stackB[x];
            x++;
        }
    }
    return (temp);
}

int simulate_next(stacks_t *temp, int *chunks)
{
    moves_t cmd[2];
    stacks_t temp2;

    if ((!closer_to_beginning2(*temp, chunks, temp->sizeA, &cmd[0])))
        perror("\n\n\tCannot find first number in chunk\n"); // Encontrar primeiro numero dentro do stackA do inicio
    if ((!closer_to_end2(*temp, chunks, &cmd[1])))
    	perror("\n\n\tCannot find chunk number in stackA\n"); // Encontrar primeiro numero dentro do stackA do final
    
    cmd[0].pos_stackb = where_to_putnbr2(cmd[0].num, temp->stackB, temp->sizeB);
    cmd[1].pos_stackb = where_to_putnbr2(cmd[1].num, temp->stackB, temp->sizeB);
    
    temp2 = pass_stacks_to_temp(*temp);
    cmd[0].moves += simulate_num1(&temp2, &cmd[0]);
    printf("\n\t(simulate next) cmd[0] moves %d", cmd[0].moves);
    temp2 = pass_stacks_to_temp(*temp);
    
    cmd[1].moves += simulate_num2(&temp2, &cmd[1]);
    printf("\n\t(simulate next) cmd[1] moves %d", cmd[1].moves);

    if (cmd[0].moves >= cmd[1].moves)
    {
        printf("\n\t(simulate next) beg is the best %d", cmd[0].moves);
        return (cmd[0].moves);
    }
    else
    {
        printf("\n\t(simulate next) end is the best %d", cmd[0].moves);
        return (cmd[1].moves);
    }
}

int check_four_opt(stacks_t main, int *chunks)
{
    moves_t cmd[2];
    stacks_t temp;

    temp = pass_stacks_to_temp(main);
     // Passar os numeros para o stackA
    if ((!closer_to_beginning2(main, chunks, main.sizeA, &cmd[0])))
        perror("\n\n\tCannot find first number in chunk\n"); // Encontrar primeiro numero dentro do stackA do inicio
    if ((!closer_to_end2(main, chunks, &cmd[1])))
    	perror("\n\n\tCannot find chunk number in stackA\n"); // Encontrar primeiro numero dentro do stackA do final
    
    if (main.sizeB != 0)
    {
        cmd[0].pos_stackb = where_to_putnbr2(cmd[0].num, main.stackB, main.sizeB);
        cmd[1].pos_stackb = where_to_putnbr2(cmd[1].num, main.stackB, main.sizeB);
    }
    else
    {
        cmd[0].pos_stackb = 0;
        cmd[1].pos_stackb = 0;
    }
    printf("\n\t(check four opt) pos_num[0] %d pos_num[1] %d e ra[0] %d e ra[1] %d", cmd[0].pos_stackb, cmd[1].pos_stackb, cmd[0].ra, cmd[1].ra);
    
    cmd[0].moves = simulate_num1(&temp, &cmd[0]);
    printf("\n\t(check four opt) Finished simulating the first one %d", cmd[0].moves);
    cmd[0].moves += simulate_next(&temp, chunks);
    printf("\n\t(check four opt) Finished simulating the next of the first one %d", cmd[0].moves);

    free(temp.stackA);
    temp = pass_stacks_to_temp(main);
    printf("\n\t(check four opt) num[0] %d num[1] %d e ra[0] %d e rra[1] %d\n", cmd[0].num, cmd[1].num, cmd[0].ra, cmd[1].rra);
    sleep(20);
    cmd[1].moves = simulate_num2(&temp, &cmd[1]);
    printf("\n\t(check four opt) Finished simulating the second one %d", cmd[1].moves);
    cmd[1].moves = simulate_next(&temp, chunks);
    printf("\n\t(check four opt) Finished simulating the next of second one %d", cmd[1].moves);

    print_stacks(temp);
    printf("\n\t(check four opt) moves[0] %d moves[1] %d", cmd[0].moves, cmd[1].moves);

    if (cmd[0].moves >= cmd[1].moves)
        return (1);
    else
        return (2);        
}
// ver tamanho do stackB, e em que index o numero deve ficar, e para que lado e mais rapido
stacks_t push_chunk_to_b2(stacks_t main, int *chunks)
{
    int counter;
    int beg_or_end;
    // printf("\n\tsizeB %d", main.sizeB);
    // printf("\n\tmiddle size %d", main.middle_size);
    counter = 0;
    printf("\n\t(push chunk to b2) counter %d middle %d\n", counter, main.middle_size);
    sleep(2);
    while (counter < main.middle_size - 1)
    {
        beg_or_end = 0;
        // printf("\n\t(push_chunk_to_b) sizeA %d\n", main.sizeA);
        beg_or_end = check_four_opt(main, chunks);
        printf("\n\t(push chunk to b2) Got out of check four opt %d\n", beg_or_end);
        sleep(2);
        printf("\n\t(push_chunk_to_b) sizeB %d", main.sizeB);
        if (beg_or_end == 1)
            beg_or_end = 2; 
        // if (main.sizeB)
        //     organize_stackB2(&main); // Ver qual maneira e mais facil de enviar o numero
        // else
        //     main = pb_funct(main);
        printf("\n\tACABOU A SIMULACAO\n");
        print_stacks(main);
        counter++;
        sleep(2);
    }
    return (main);
}

stacks_t do_easy_one2(stacks_t main)
{
    int *chunks;
    int *org;

    // Fazer um while com estes dois para poder dividir função
    // O middle size tem de ser updated
    // printf("(do_easy_one2) GOT HERE!\n");
    // sleep(2);
    while (main.sizeA != 3) // Enquanto nao houver 3 numeros no stackA
    {
        org = organize_array(main.stackA, main.sizeA - 1); // Organizar o array
        if (main.sizeA % 2 != 0) // ver se tamanho e par ou impar para saber onde esta o meio
            main.middle_size = main.sizeA/2 + 1; // Se for impar, como a divisao arredonda para baixo, aumentar 1
        else
            main.middle_size = main.sizeA/2; // Se for par so e preciso dividir por 2
        get_attr_chunks(&chunks, main.middle_size, org); // Receber a chunk1 e a chunk 2
        print_array(chunks, main.middle_size);
        main = push_chunk_to_b2(main, chunks); // Empurrar a chunk para o stackB
    }
    return (main);
}
