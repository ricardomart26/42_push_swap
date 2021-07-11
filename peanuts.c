#include "push_swap.h"



static void    push_everything_to_b(stacks_t *main, int *org)
{   
    while (main->sizeA != 0) // Enquanto tiver numeros no stackA mandar para o stack B
    {
        main->lowest = *org; // Ver qual o numero mais baixo
        main->middle_size = main->sizeA/2; // Saber o tamanho do meio
        main->lowest_pos = find(*org, main->stackA); // Encontrar o index do numero
        if (main->lowest_pos == 0) // Se for 0 mandar para o stackB
            *main = pb(*main);
        else if (main->lowest_pos > main->middle_size && main->sizeA != 0) // Se estiver acima do meio fazer rra
        {
            while (main->lowest_pos++ != main->sizeA)
                *main = rra(*main, 1);
            *main = pb(*main);
        }
        else if (main->lowest_pos <= main->middle_size && main->sizeA != 0)  // Se estiver abaixo do meio fazer rra
        {
            while (main->lowest_pos-- != 0)
                *main = ra(*main, 1);
            *main = pb(*main);
        }
        org++; // Andar com o array organizado para ver proximo numero mais pequeno
    }
}

stacks_t peanuts(stacks_t main, int size)
{
    int *org;
    (void)size;
    
    org = organize_array(main.stackA, main.sizeA - 1); // Organizar o array 
    // printf("\n\tStarting PEANUST baby!");
    push_everything_to_b(&main, org);
    while (main.sizeB != 0)
        main = pa(main);
    print_stacks(main);
    // printf("\n\t************* YOU DID %d MOVES **************\n", counter);
    return (main);
}
