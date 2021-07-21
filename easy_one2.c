#include "push_swap.h"

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

int find_closer_to_beginning2(stacks_t *main, int *chunk, int size, moves_t *cmd)
{
    int i;
    int x;

    i = 0;
    while (size--)
    {
        x = 0;
        while (main->stackA[i] != chunk[x] && x + 1 < main->middle_size)
            x++;
        if (x + 1 == main->middle_size)
            i++;
        else
        {
            cmd->ra = i;
			cmd->rra = 0;

            printf("\n\t(find closer to beginning) stack[%d] %d\n", i, main->stackA[i]);
            break;
        }
    }
    if (size == 0)
        return (-1);
    return (1);
}

int find_closer_to_end2(stacks_t *main, int *chunk, moves_t *cmd)
{
    int size;
    int x;

    size = main->sizeA - 1;
    // printf("\t(find closer to end) 1 stack[%d] %d\n", size, main->stackA[size]);
    while (size)
    {
        x = 0;
        // printf("\t(find closer to end) 2 stack[%d] %d\n", size, main->stackA[size]);
        while (main->stackA[size] != chunk[x] && x < size)
            x++;
        // printf("\t(find closer to end) 69 x %d e size %d\n", x, size);
        if (x == size)
        {
            size--;
            // printf("\t(find closer to end) size diminui-o\n");
        }
        else
        {
			cmd->rra = main->sizeA - size;
			cmd->ra = 0;
            printf("\t(find closer to end) 3 stack[%d] %d\n", size, main->stackA[size]);
            return (size);
        }
    }
    return (-1);
}

void    organize_stackB2(stacks_t *main)
{
    int i_in_stackb;
    i_in_stackb = where_to_putnbr2(main->stackA[0], main->stackB, main->sizeB); // Ver onde tem que ir o primeiro numero
    // printf("\n\n\t\t ENTERED IN ORGANIZED ");
    // // print_stacks(*main);
    // printf("\n\t(organize stack b) main->stackA[0] %d\n", main->stackA[0]);
    // printf("\n\t(organize stack b) i_in_stack %d\n", i_in_stackb);
    // printf("\n\t(organize stack b) main->sizeB %d\n", main->sizeB/2);
    // printf("\n\t(organize stack b) i_in_stack %d\n", i_in_stackb);

    if (i_in_stackb == 0)
    {
        printf("\n\t(organize stack b) first pb\n");
        *main = pb_funct(*main);
    }
    else if (i_in_stackb == main->sizeB)
    {
        // printf("\n\t(organize stack b) second pb\n");
        *main = pb_funct(*main);
        *main = rb_funct(*main, 1);
    }
    else if (i_in_stackb >= main->sizeB/2) // Se o i for acima do meio
        main = combo1(main);
    else if (i_in_stackb <= main->sizeB/2)
        main = combo2(main);
    // printf("\n\t(organize stack b)");
    // print_stacks(*main);
    // sleep(1);
}

void	set_two_numbers(stacks_t *main, moves_t *cmd)
{
    int temp;

	if (cmd->num1 >= cmd->num2)
    {
        temp = main->stackA[cmd->num1 - 1];
    	cmd->rra = cmd->num1;
        printf("\n\t(push_to_beg_stackA2) temp = %d\n", temp);
    } // Se estiver mais perto do final fazer rra ate ao inicio
    else if (cmd->num1 < cmd->num2) // Se estiver mais perto do incio fazer rra ate ao inicio
	{
        temp = main->stackA[cmd->num2 - 1];
        printf("\t(push_to_beg_stackA2) htemp = %d\n", temp);
        cmd->ra = cmd->num2;
    }
}

void    init_cmd(moves_t *cmd)
{
    cmd->rb = 0;
    cmd->rrb = 0;
    cmd->rr = 0;
    cmd->rrr = 0;
}


int simulate_first_num(stacks_t *main, int number, int place)
{
    moves_t cmd;
    
    init_cmd(&cmd);
    if (place == 0)
    {
        printf("\n\t(simulate_first_num) place = 0\n");
        return (cmd.ra + pb);
    }
    else if (place == main->sizeB)
    {
        // printf("\n\t(organize stack b) second pb\n");
        cmd.rr = 1;
        cmd.ra--;
        if (cmd.ra == 0)
            return (cmd.rr);
        return (cmd.rr - cmd.ra + pb);
    }
    else if (place >= main->sizeB/2)
    {
        cmd.rrb = moves_rrb(main, place); // Se o i for acima do meio entao tens que fazer rb
    } // Se o i for acima do meio entao tens que fazer rb
    else if (place <= main->sizeB/2) // Se o i for acima do meio entao tens que fazer rrb
        cmd.rb = moves_rb(main);
}

int simulate_second_num(stacks_t *main, int number, int place)
{
    moves_t cmd;
    
    init_cmd(&cmd);

    if (place == 0)
    {
        printf("\n\t(simulate_first_num) place = 0\n");
        return (cmd.rra + pb);
    }
    else if (place == main->sizeB)
    {
        // printf("\n\t(organize stack b) second pb\n");
        cmd.rrr = 1; 
        cmd.rra--;
        if (cmd.ra == 0)
            return (cmd.rr);
        return (cmd.rr - cmd.ra + pb);
    }
    else if (place >= main->sizeB/2)
    {
        cmd.rrb = moves_rrb(main, place); // Se o i for acima do meio entao tens que fazer rb

    } // Se o i for acima do meio entao tens que fazer rb
    else if (place <= main->sizeB/2) // Se o i for acima do meio entao tens que fazer rrb
        cmd.rb = moves_rb(main);
}

int check_four_opt(stacks_t main, int *chunks)
{
    int first_in_stackb;
    int second_in_stackb;
    int first_number;
    int second_number;
    int moves_first;
    int moves_second;
    moves_t cmd;
    
    if ((!find_closer_to_beginning2(&main, chunks, main.sizeA, &cmd)))
        perror("\n\n\tCannot find first number in chunk\n"); // Encontrar primeiro numero dentro do stackA do inicio
    if ((!find_closer_to_end2(&main, chunks, &cmd)))
    	perror("\n\n\tCannot find chunk number in stackA\n"); // Encontrar primeiro numero dentro do stackA do final
        
    first_number = main.stackA[cmd.num1 - 1];
    second_number = main.stackA[cmd.num2 - 1];
    cmd.rra = cmd.num1;
    cmd.ra = cmd.num2;

    first_in_stackb = where_to_putnbr2(first_number, main.stackB, main.sizeB); // Ver onde tem que ir o primeiro numero
    second_in_stackb = where_to_putnbr2(second_number, main.stackB, main.sizeB); // Ver onde tem que ir o primeiro numero
    
    cmd.moves1 = simulate_first_num(&main, first_number, first_in_stackb);
    cmd.moves2 = simulate_second_num(&main, second_number, second_in_stackb);
    cmd.moves3 = simulate_third_num(&main, second_number, second_in_stackb);
    cmd.moves4 = simulate_fourth_num(&main, second_number, second_in_stackb);

    if (moves_first >= moves_second)
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
    while (counter < main.middle_size - 1)
    {
        beg_or_end = 0;
        // printf("\n\t(push_chunk_to_b) sizeA %d\n", main.sizeA);

        printf("\n\t(push_chunk_to_b) hold_first %d hold_second %d\n", cmd.num1, main.hold_second);
		sets(&main);
        beg_or_end = check_four_opt(main);
        printf("\n\t(push_chunk_to_b) sizeB %d", main.sizeB);
        if (main.sizeB)
            organize_stackB2(&main); // Ver qual maneira e mais facil de enviar o numero
        else
        {
            // printf("\n\t(push_chunk_to_b) Foi este pb?\n");
            main = pb_funct(main);
        }
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
    int i;

    i = 1;
    // Fazer um while com estes dois para poder dividir função
    // O middle size tem de ser updated
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
