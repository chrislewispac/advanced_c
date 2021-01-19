#include "puzzle.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* alloc_word_memory(char* line){
    char buffer[MATRIX_SIZE + 1];
    sscanf(line, "%s", buffer);
    size_t length = strlen(buffer) + 1;
    char* word = malloc(length);
    strncpy(word, buffer, length);
    return word;
}

void read_words(puzzle_t* puzzle, FILE* fd) {
    char buffer[MATRIX_SIZE * 2];
    for (int i=0; i< puzzle->num_words; ++i) {
        fgets(buffer, MATRIX_SIZE * 2, fd);
        puzzle->words[i] = alloc_word_memory(buffer);
    }
}

void read_matrix(puzzle_t* puzzle, FILE* fd) {
    char temp;
    char buffer[MATRIX_SIZE * 3];
    
    for (int row= 0; row < puzzle->matrix_size; ++row) {
        fgets(buffer, MATRIX_SIZE * 3, fd);
        // printf("%s\n", buffer);
        for (int col = 0; col < puzzle->matrix_size; ++col) {
           sscanf(&buffer[col*2], "%c", &puzzle->matrix[row][col]);
        //    fscanf(fd, "%c", &puzzle->matrix[row][col]);
           if (puzzle->matrix[row][col] == ' ') {
               puzzle->matrix[row][col] = '$';
           }
        }
        // fscanf(fd, "%[^\n]", buffer);
    } 
}

int read_number(FILE* fd) {
    int result = 0;
    char buffer[MATRIX_SIZE];
    fgets(buffer, MATRIX_SIZE, fd);
    sscanf(buffer, "%d", &result);
    return result;
}

void read_puzzle(puzzle_t* puzzle, FILE* fd) {
    puzzle->matrix_size =  read_number(fd);
    puzzle->num_words = read_number(fd);
    read_words(puzzle, fd);
    read_matrix(puzzle, fd);
}

void dump_puzzle(puzzle_t* puzzle) {
    printf("Matrix Size: %d\nNum Words: %d\n", puzzle->matrix_size, puzzle->num_words);
    for (int i=0; i < puzzle->num_words; ++i) {
        if (puzzle->words[i] != NULL) {
            printf("%s\n", puzzle->words[i]);
        }
    }
    if (puzzle->matrix_size > 0) {
        for (int row= 0; row < puzzle->matrix_size; ++row) {
            for (int col = 0; col < puzzle->matrix_size; ++col) {
                printf("%c ", puzzle->matrix[row][col]);
            }
            printf("\n");
        } 
    }
}

void init_puzzle(puzzle_t* puzzle) {
    free_matrix(puzzle);
    for (int i =0; i<MATRIX_SIZE; ++i) {
        puzzle->words[i] = NULL;
    }
    puzzle->num_words = 0;
    puzzle->matrix_size = 0;
}

void rm_puzzle(puzzle_t* puzzle) {
    free_matrix(puzzle);
    puzzle->matrix_size = 0;
    free_words(puzzle);
    puzzle->num_words = 0;
}

void free_matrix(puzzle_t* puzzle) {
    for (int row= 0; row < MATRIX_SIZE; ++row) {
        for (int col = 0; col < MATRIX_SIZE; ++col) {
            puzzle->matrix[row][col] = '0';
        }
    }
}

void free_words(puzzle_t* puzzle) {
    for (int i = 0; i < MATRIX_SIZE; ++i) {
        if (puzzle->words[i] != NULL) {
            free(puzzle->words[i]);
            puzzle->words[i] = NULL;
        }
    }
}