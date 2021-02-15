#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "puzzle.h"

const int DIRECTIONS = 8;

enum dir{RIGHT, LEFT, UP, DOWN, UPLEFT, UPRIGHT, DOWNRIGHT, DOWNLEFT};

typedef struct coord {
    int row;
    int col;
} coord;

int inBounds(coord c, int matrix_size) {
    return (c.col >= 0 && c.col < matrix_size && c.row >= 0 && c.row < matrix_size);
}

struct coord moveDown(coord c) {
    c.row++;
    return c;
}

struct coord moveUp(coord c) {
    c.row--;
    return c;
}

struct coord moveLeft(coord c) {
    c.col--;
    return c;
}

struct coord moveDownLeft(coord c) {
    c.col--;
    c.row++;
    return c;
}

struct coord moveUpLeft(coord c) {
    c.col--;
    c.row--;
    return c;
}

struct coord moveRight(coord c) {
    c.col++;
    return c;
}

struct coord moveUpRight(coord c) {
    c.col++;
    c.row--;
    return c;
}

struct coord moveDownRight(coord c) {
    c.col++;
    c.row++;
    return c;
}

int checkDirection(coord curr_coord, puzzle_t puzzle, char* word, int word_length, enum dir direction) {
    int char_index = 0;
    char curr_char = puzzle.matrix[curr_coord.row][curr_coord.col];
    char target = word[char_index];
    while (curr_char == target && char_index < word_length - 1) {
        // printf("found %c at coord (%d,%d) and char index \n", target, curr_coord.row, curr_coord.col);
        char_index++;
        target = word[char_index];
        switch(direction) {
            case RIGHT:
                curr_coord = moveRight(curr_coord);
                break;
            case LEFT:
                curr_coord = moveLeft(curr_coord);
                break;
            case DOWN:
                curr_coord = moveDown(curr_coord);
                break;
            case UP:
                curr_coord = moveUp(curr_coord);
                break;
            case UPRIGHT:
                curr_coord = moveUpRight(curr_coord);
                break;
            case DOWNRIGHT:
                curr_coord = moveDownRight(curr_coord);
                break;
            case UPLEFT:
                curr_coord = moveUpLeft(curr_coord);
                break;
            case DOWNLEFT:
                curr_coord = moveDownLeft(curr_coord);
                break;
            default:
                break;
        }
        
        if (inBounds(curr_coord, puzzle.matrix_size)) {
            curr_char = puzzle.matrix[curr_coord.row][curr_coord.col];
                        
            if (char_index == word_length - 1 && curr_char == target) {
                return 1;
            }
        }               
    }

    return 0;
}

int main() {
    int num_puzzles = 0; 
    FILE *fd = fopen("./input_problem_1.txt", "r");

    if (fd == NULL) {
        printf("File not found\n");
        exit(0);
    }

    num_puzzles = read_number(fd);

    for (int i = 0; i < num_puzzles; i++) {
        puzzle_t puzzle;
        init_puzzle(&puzzle);
        read_puzzle(&puzzle, fd);



        for (int i=0; i < puzzle.num_words; ++i) {
            if (puzzle.words[i] != NULL) {
                int num_found = 0;
                char* word = puzzle.words[i];
                int word_length;
                for (word_length = 0; word[word_length] != '\0'; ++word_length);
                
                
                for (int row= 0; row < puzzle.matrix_size; ++row) {
                    for (int col = 0; col < puzzle.matrix_size; ++col) {
                        struct coord curr_coord = {row, col};
                        // printf("searching for %s starting at %d, %d \n", word, curr_coord.row, curr_coord.col);
                        for (int dir_enum = RIGHT;  dir_enum <= DOWNLEFT; dir_enum++) {
                            num_found += checkDirection(curr_coord, puzzle, word, word_length, dir_enum);
                        }      
                    }
                } 
                printf("found %s %d times \n", word, num_found);
            }
        }

        printf("---------------------- \n");
        // dump_puzzle(&puzzle);
        rm_puzzle(&puzzle);
    }


    fclose(fd);
    return 0;
}