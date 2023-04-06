# Project Overview #

The Push Swap project is a sorting algorithm project that requires the implementation of two programs in C:

   - `push_swap`: A program that takes a list of integers as arguments and sorts them using a limited set of instructions.

The goal of the project is to sort a list of integers in the most efficient way possible, using as few instructions as possible.
How to Use

To use this project, simply clone this repository and navigate to the root directory. From there, you can compile the two programs by running make.

Once compiled, you can run the programs as follows:

    ./push_swap [list of integers]: This will sort the list of integers using the algorithm implemented in push_swap and output the required instructions to standard output.

Note that the list of integers should be provided as a space-separated list of integers.

Algorithm

The algorithm implemented in push_swap is a variation of the Quick Sort algorithm that uses two stacks to sort the list of integers. The algorithm works as follows:

    Divide the list of integers into multiple chuncks from the lower numbers to the biggest ones.
    Push the first the chunck to stack B and organize the numbers, and then repeat the same progress for the rest of the chuncks, and in the end send them to stack B.
    Implemented also simulations, to see which would be the most efficient way to send the chunk to stack B.
