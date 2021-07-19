#include "push_swap.h"

stacks_t beast_mode(stacks_t main)
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
            main.middle_size = main.sizeA/11 + 1; // Se for impar, como a divisao arredonda para baixo, aumentar 1
        else
            main.middle_size = main.sizeA/11; // Se for par so e preciso dividir por 2
        // So e preciso saber a primeira chunk, e nao a segunda?
        get_attr_chunks(&chunks, main.middle_size, org); // Receber a chunk1 e a chunk 2
        print_array(chunks, main.sizeA/2);
        main = push_chunk_to_b(main, chunks); // Empurrar a chunk para o stackB
    }
    return (main);
}
