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
    // printf("\n\tCHECKKKKK THIS 1\n");    
    // print_stacks(main);
    
    temp.middle_size = main.middle_size;
    temp.sizeA = main.sizeA;
    temp.sizeB = main.sizeB;
    x = 0;
    while (main.stackA[x])
    {
        // printf("\n\tENTRA AQUI???\n");    

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
    // printf("\n\tCHECKKKKK THIS 2\n");
    // print_stacks(temp);
    return (temp);
}

void    get_pos(stacks_t main, moves_t **cmd)
{
    if (main.sizeB != 0)
    {
        cmd[0]->pos_stackb = where_to_putnbr2(cmd[0]->num, main.stackB, main.sizeB);
        cmd[1]->pos_stackb = where_to_putnbr2(cmd[1]->num, main.stackB, main.sizeB);
    }
    else
    {
        cmd[0]->pos_stackb = 0;
        cmd[1]->pos_stackb = 0;
    }
    // printf("\n\t(get pos) pos_num[0] %d pos_num[1] %d e ra[0] %d e ra[1] %d", cmd[0].pos_stackb, cmd[1].pos_stackb, cmd[0].ra, cmd[1].rra);

}

int check_four_opt(stacks_t main, int *chunks)
{
    moves_t *cmd;
    stacks_t temp;
    int movesss;
    int mv[4];

    cmd = malloc(sizeof(moves_t) * 2);
    movesss = 0;

    temp = pass_stacks_to_temp(main);
    if ((!closer_to_beginning2(main, chunks, main.sizeA, &cmd[0])))
        perror("\n\n\tCannot find first number in chunk\n"); // Encontrar primeiro numero dentro do stackA do inicio
    if ((!closer_to_end2(main, chunks, &cmd[1])))
    	perror("\n\n\tCannot find chunk number in stackA\n"); // Encontrar primeiro numero dentro do stackA do final    
    get_pos(main, &cmd); 
    movesss = simulate_num1(&temp, &cmd[0]);

    mv[0] = simulate_next_f(temp, chunks, movesss);
    printf("\n\t(check four opt/simnf0) Finished simulating the first one of the first %d\n", mv[0]);

    mv[1] = simulate_next_s(temp, chunks, movesss);
    printf("\n\t(check four opt/simnfs1) Finished simulating the second one of the first %d\n", mv[1]);

    free(temp.stackA);
    temp = pass_stacks_to_temp(main);

    movesss = simulate_num2(&temp, &cmd[1]);
    printf("\n\t(check four opt/simnum2) Finished simulating the simulate_num2 in check4opt %d\n", movesss);
    
    mv[2] = simulate_next_f(temp, chunks, movesss);
    printf("\n\t(check four opt/simnf2) Finished simulating the first one of the sec %d\n", mv[2]);

    mv[3] = simulate_next_s(temp, chunks, movesss);
    printf("\n\t(check four opt/end ) mv[0] %d mv[1] %d mv[2] %d mv[3] %d\n", mv[0], mv[1], mv[2], mv[3]);

    free(temp.stackA);
    temp = pass_stacks_to_temp(main);

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
        printf("\n\t(push chunk to b2) Got out of check four opt %d\n", option);
        if (option == 1)
            option = 2; 
        print_stacks(main);
        counter++;
        sleep(5);
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
