#include "push_swap.h"

void    print_stacks(stacks_t main)
{
    int size;
    int c;

    c = 0;
    if (main.sizeA > main.sizeB)
        size = main.sizeA;
    else
        size = main.sizeB;
    
    printf("\n\n\t************\n");
    printf("\t** A ** B **\n");
    printf("\t************\n");
    printf("\t** %d ** %d **\n", main.sizeA, main.sizeB);
    printf("\t************\n");

    while (size--)
    {
        if (main.sizeA != 0 && main.sizeB != 0)
        {
            printf("\t** %d ** %d **\n", main.stackA[c], main.stackB[c]);
            main.sizeA--;
            main.sizeB--;    
        }
        else if (main.sizeA != 0 && main.sizeB == 0)
        {
            printf("\t** %d **   **\n", main.stackA[c]);
            main.sizeA--;
        }
        else if (main.sizeA == 0 && main.sizeB != 0)
        {
            printf("\t**   ** %d **\n", main.stackB[c]);
            main.sizeB--;
        }
        c++;
    }
    printf("\t************\n");
    printf("\t************\n");



}