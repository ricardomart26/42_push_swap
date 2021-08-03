#include "../push_swap.h"

int biggest_num(int *stack, int size)
{
    int i;
    int temp;

    i = 0;
    temp = stack[i];
    if (size == 2)
    {
        if (stack[i] > stack[i + 1])
            return (stack[i]);
        else
            return (stack[i + 1]);
    }

    while (i < size - 1)
    {
        while (temp > stack[i] && i < size - 1)
        {
            printf("\n\ttemp %d stack[%d + 1] %d\n", temp, i, stack[i]);
            // sleep(1);
            i++;
        }
        if (temp < stack[i])
            temp = stack[i];
        i++;
    }
    return (temp);
}

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

moves_t set_b(moves_t cmd, int rb, int rrb)
{
    cmd.rb = rb;
    cmd.rrb = rrb;
    if (cmd.rb != 0 && cmd.ra != 0)
        moves_rb(&cmd);
    else if (cmd.rrb != 0 && cmd.rra != 0)
        moves_rrb(&cmd);
    return (cmd);
}

int is_lowest_array(int x, int *array, int size)
{
    int i;

    i = 0;
    while (array[i] > x && i < size)
        i++;

    if (i == size)
        return (1);
    else
        return (0);
}

int place_in_array(int *stack, int num)
{
    int i;

    i = 0;
    while (stack[i] != num)
        i++;
    return (i);
}

moves_t best_way_to_put_nbr_in_stackB(stacks_t main, moves_t cmd)
{
    int i;
    int x;
    int size;

    size = 0;
    while (main.stackB[size] != NULL)
        size++;
    
    x = 0;

    while (cmd.num > main.stackB[size - 1])
    {
        size--;
        x++;
    }
    i = 0;
    if (x == 0)
        while (cmd.num < main.stackB[i])
            i++;
    if (x)
        cmd = set_b(cmd, 0, x);
    else if (i)    
        cmd = set_b(cmd, i, 0);
    return (cmd);
}

moves_t    get_cmds(stacks_t main, moves_t cmd, int size)
{
    int max;
    int max_place;

    if (size > 1)
    {
        print_stacks(main);
        cmd.pos_stackb = 0;
        max = biggest_num(main.stackB, size);
        max_place = place_in_array(main.stackB, max);
        printf("\n\t(get cmds) max place %d num %d max %d\n", max_place, cmd.num, max);
        print_stacks(main);
        sleep(2);
        if (is_lowest_array(cmd.num, main.stackB, size) || cmd.num > max)
        {
            printf("\n\tIS LOWEST OR BIGGER THAN THE MAX %d\n", cmd.num);
            print_stacks(main);
            sleep(5);
            if (max_place == 0)
                set_b(cmd, 0, 0);
            else if (max_place > main.middle_size)
                cmd = set_b(cmd, 0, size - max_place);
            else if (max_place <= main.middle_size)
                cmd = set_b(cmd, max_place, 0);
        }
        else
            cmd = best_way_to_put_nbr_in_stackB(main, cmd);
        cmd.total = 0;
    }
    else
    {
        cmd.pos_stackb = 0;
        cmd.rb = 0;
        cmd.rrb = 0;
        cmd.rr = 0;
        cmd.rrr = 0;
        cmd.total = 0;
    }
    return (cmd);
}

void free_all_stacks_t(stacks_t *main)
{
    free(main->stackA);
    main->stackA = NULL;
    if (main->sizeB)
    {
        free(main->stackB);
        main->stackB = NULL;    
    }
        
}

void free_all_moves_t(moves_t *cmd)
{
    free(cmd);
    cmd = NULL;
}

int check_four_opt(stacks_t main, int *chunks)
{
    moves_t *cmd;
    stacks_t temp;
    int movesss;
    int mv[4];

    cmd = malloc(sizeof(moves_t) * 2 + 1);
    movesss = 0;
    if ((!closer_to_beginning2(main, chunks, main.size_chunk, &cmd[0])))
        perror("\n\n\tCannot find first number in chunk\n"); // Encontrar primeiro numero dentro do stackA do inicio
    if ((!closer_to_end2(main, chunks, &cmd[1])))
    	perror("\n\n\tCannot find chunk number in stackA\n"); // Encontrar primeiro numero dentro do stackA do final    
    
    temp = pass_stacks_to_temp(main);
    cmd[0] = get_cmds(main, cmd[0], temp.sizeB);
    // print_cmds(cmd, 0);

    printf("\n\t0\n");

    movesss = simulate_num1(&temp, cmd[0]);
    mv[0] = simulate_next_f(temp, chunks, movesss);
    mv[1] = simulate_next_s(temp, chunks, movesss);

    printf("\n\t**********FINISH NUM 1!**********\n");

    free_all_stacks_t(&temp);
    temp = pass_stacks_to_temp(main);

    cmd[1] = get_cmds(main, cmd[1], temp.sizeB);
    // print_cmds(cmd, 1);
    movesss = simulate_num2(&temp, cmd[1]);
    mv[2] = simulate_next_f(temp, chunks, movesss);
    mv[3] = simulate_next_s(temp, chunks, movesss);
    
    printf("\n\t**********FINISH NUM 2!**********\n");

    printf("\n\t(check four opt/end ) mv[0] %d mv[1] %d mv[2] %d mv[3] %d\n", mv[0], mv[1], mv[2], mv[3]);
    // sleep(3);
    free_all_stacks_t(&temp);
    temp = pass_stacks_to_temp(main);
    printf("\n\tteste\n");
    return(return_best_opt(mv, temp, chunks));     
}

// ver tamanho do stackB, e em que index o numero deve ficar, e para que lado e mais rapido
stacks_t push_chunk_to_b2(stacks_t main, int *chunks)
{
    int counter;
    int option;

    counter = 0;
    while (counter < main.middle_size - 1)
    {
        option = 0;
        option = check_four_opt(main, chunks);

        printf("\n\t(Finished sim)\n");

        main = do_opt(main, chunks, option);
 
        printf("\n\t(Finished real)\n");

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
        print_array(chunks, main.middle_size);
        // sleep(5);
        main = push_chunk_to_b2(main, chunks); // Empurrar a chunk para o stackB
    }
    return (main);
}
