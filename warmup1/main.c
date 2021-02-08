#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "puzzle.h" 

int main() {
    int num_puzzles = 0; 
    FILE *fd = fopen("./inputs/input_problem_1.txt", "r");

    if (fd == NULL)
    {
        printf("File not found\n");
        exit(0);
    }

    num_puzzles = read_number(fd);

    for (int i = 0; i < num_puzzles; i++) {
        puzzle_t puzzle;
        init_puzzle(&puzzle);
        read_puzzle(&puzzle, fd);

        // for (int row= 0; row < puzzle.matrix_size; ++row) {
        //     for (int col = 0; col < puzzle.matrix_size; ++col) {
        //         printf("%c ", puzzle.matrix[row][col]);
        //     }
        //     printf("\n");
        // } 
    
        dump_puzzle(&puzzle);
        rm_puzzle(&puzzle);
    }


    fclose(fd);
    return 0;
}


// use structure to hold all elements of each individual structure
// and then pass a function to fill it

// create own test file with single problem