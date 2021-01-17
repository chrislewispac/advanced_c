#ifndef __PUZZLE_H__
#define __PUZZLE_H__

#define MATRIX_SIZE 10

struct puzzle_t {
    int matrix_size;
    int num_words;
    char* words[];
    char matrix[MATRIX_SIZE][MATRIX_SIZE];
};

void init_puzzle(struct puzzle_t);

void free_words(char* []);

#endif  // __PUZZLE_H__