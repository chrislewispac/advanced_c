#ifndef __PUZZLE_H__
#define __PUZZLE_H__

#include <stdio.h>

#define MATRIX_SIZE 10

struct puzzle_type {
    int matrix_size;
    int num_words;
    char matrix[MATRIX_SIZE][MATRIX_SIZE];
    char* words[MATRIX_SIZE];
};

#define puzzle_t struct puzzle_type

void rm_puzzle(puzzle_t*);

void free_words(puzzle_t*);

void free_matrix(puzzle_t*);

void init_puzzle(puzzle_t*);

void dump_puzzle(puzzle_t*);

void read_puzzle(puzzle_t*, FILE*);

void read_words(puzzle_t*, FILE*);

int read_number(FILE*);

#endif  // __PUZZLE_H__