#include "../push_swap.h"

int where_to_putnbr(int x, int *stackB, int size)
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
            // printf("\n\t(find closer to beginning) stack[%d] %d\n", i, main.stackA[i]);
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
            // printf("\n\t(find closer to end) stack[%d] %d\n", size - 1, main.stackA[size - 1]);
            return (size - 1);
        }
    }
    return (-1);
}

void    organize_stackB(stacks_t *main)
{
    int i_in_stackb;
    i_in_stackb = where_to_putnbr(main->stackA[0], main->stackB, main->sizeB); // Ver onde tem que ir o primeiro numero
    // printf("\n\n\t\t ENTERED IN ORGANIZED ");
    // // print_stacks(*main);
    // printf("\n\t(organize stack b) main->stackA[0] %d\n", main->stackA[0]);
    // printf("\n\t(organize stack b) i_in_stack %d\n", i_in_stackb);
    // printf("\n\t(organize stack b) main->sizeB %d\n", main->sizeB/2);
    // printf("\n\t(organize stack b) i_in_stack %d\n", i_in_stackb);

    if (i_in_stackb == 0)
    {
        // printf("\n\t(organize stack b) first pb\n");
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

// ver tamanho do stackB, e em que index o numero deve ficar, e para que lado e mais rapido
stacks_t push_chunk_to_b(stacks_t main, int *chunks)
{
    int hold_first; // Guardar primeiro numero dentro do stackB a partir do inicio dentro do chunk
    int hold_second; // Guardar primeiro numero dento do stackB a partir do final dentro do chunk
    int counter;
    // printf("\n\tsizeB %d", main.sizeB);
    // printf("\n\tmiddle size %d", main.middle_size);
    counter = 0;
    while (counter < main.middle_size - 1)
    {
        // printf("\n\t(push_chunk_to_b) sizeA %d\n", main.sizeA);
        if ((!find_closer_to_beginning(main, chunks, &hold_first, main.sizeA)))
            perror("\n\n\tCannot find first number in chunk\n"); // Encontrar primeiro numero dentro do stackA do inicio
        if ((!find_closer_to_end(main, chunks, &hold_second)))
            perror("\n\n\tCannot find chunk number in stackA\n"); // Encontrar primeiro numero dentro do stackA do final
        // printf("\n\t(push_chunk_to_b) hold_first %d hold_second %d\n", hold_first, hold_second);
        if (hold_first >= hold_second) // Se estiver mais perto do final fazer rra ate ao inicio
            while (hold_second-- != 1)
                main = rra_funct(main, 1);
        if (hold_first < hold_second) // Se estiver mais perto do incio fazer rra ate ao inicio
            while (hold_first-- != 0)
                main = ra_funct(main, 1);
        if (main.sizeB > 1)
            organize_stackB(&main); // Ver qual maneira e mais facil de enviar o numero
        else
            main = pb_funct(main);
        // print_stacks(main);
        counter++;
    }
    return (main);
}

stacks_t do_easy_one(stacks_t main)
{
    int *chunks;
    int *org;

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
        main = push_chunk_to_b(main, chunks); // Empurrar a chunk para o stackB
    }

    return (main);
}
