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
    
    printf("\n************\n");
    printf("** A ** B **\n");
    printf("************\n");
    printf("** %d ** %d **\n", main.sizeA, main.sizeB);
    printf("************\n");

    while (size--)
    {
        if (main.sizeA != 0 && main.sizeB != 0)
        {
            printf("** %d ** %d **\n", main.stackA[c], main.stackB[c]);
            main.sizeA--;
            main.sizeB--;    
        }
        else if (main.sizeA != 0 && main.sizeB == 0)
        {
            printf("** %d **   **\n", main.stackA[c]);
            main.sizeA--;
        }
        else if (main.sizeA == 0 && main.sizeB != 0)
        {
            printf("**   ** %d **\n", main.stackB[c]);
            main.sizeA--;
        }
        c++;
    }
    printf("************\n");
    printf("************\n");



}