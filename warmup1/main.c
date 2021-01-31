#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "puzzle.h" 

void read_problem(puzzle_t* puzzle) {
    int num_tests = 0; 
    FILE *fd = fopen("sample.txt", "r");

    if (fd == NULL)
    {
        printf("File not found\n");
        exit(0);
    }


    read_puzzle(puzzle, fd);

    fclose(fd);
}

int main() {
    puzzle_t puzzle;
    init_puzzle(&puzzle);
    read_problem(&puzzle);
    // for (int row= 0; row < puzzle.matrix_size; ++row) {
    //     for (int col = 0; col < puzzle.matrix_size; ++col) {
    //         if (puzzle.matrix[row][col] == 'A') {
    //             printf("%c ", puzzle.matrix[row][col]);
    //         }
    //     }
    //     printf("\n");
    // } 
 
    dump_puzzle(&puzzle);
    rm_puzzle(&puzzle);
    return 0;
}


// use structure to hold all elements of each individual structure
// and then pass a function to fill it

// create own test file with single problem