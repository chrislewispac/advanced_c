#include <stdio.h>
#include <stdlib.h>


const int NEIGHBORS = 8;

enum neighbor{RIGHT, LEFT, UP, DOWN, UPLEFT, UPRIGHT, DOWNRIGHT, DOWNLEFT};

typedef struct coord {
    int row;
    int col;
} coord;

struct puzzle_t {
    int image_size;
    int kernel_size;
    int image_matrix[10][10];
    int kernel_matrix[10][10];
    int output_matrix[10][10];
};


int inBounds(coord c, int matrix_size) {
    return (c.col >= 0 && c.col < matrix_size && c.row >= 0 && c.row < matrix_size);
}

void printMatrix(struct puzzle_t puzzle, int matrix[10][10]) {
    for(size_t i = 0; i < puzzle.image_size; ++i) {
        for(size_t j = 0; j < puzzle.image_size; ++j) {
            printf("%-3d ", matrix[i][j]);
        }
        puts("");
    }
    printf("--------------- \n");
}

void applyKernel(struct puzzle_t *puzzle, struct coord ic, struct coord kc) {
    int new_val = 0;
    
    new_val += puzzle->image_matrix[ic.row][ic.col] * puzzle->kernel_matrix[kc.row][kc.col];

    for (int dir_enum = RIGHT;  dir_enum <= DOWNLEFT; dir_enum++) {
        struct coord new_ic;
        switch(dir_enum) {
            case RIGHT:
                new_ic.row = ic.row;
                new_ic.col = ic.col + 1;
                if (inBounds(new_ic, puzzle->image_size) ) {
                    new_val += puzzle->image_matrix[new_ic.row][new_ic.col] * puzzle->kernel_matrix[kc.row][kc.col + 1];
                }
                break;
            case LEFT:
                new_ic.row = ic.row;
                new_ic.col = ic.col - 1;
                if (inBounds(new_ic, puzzle->image_size) ) {
                    new_val += puzzle->image_matrix[new_ic.row][new_ic.col] * puzzle->kernel_matrix[kc.row][kc.col - 1];
                } 
                break;
            case UP:
                new_ic.row = ic.row - 1;
                new_ic.col = ic.col;
                if (inBounds(new_ic, puzzle->image_size) ) {
                    new_val += puzzle->image_matrix[new_ic.row][new_ic.col] * puzzle->kernel_matrix[kc.row - 1][kc.col];
                } 
                break;
            case DOWN:
                new_ic.row = ic.row + 1;
                new_ic.col = ic.col;
                if (inBounds(new_ic, puzzle->image_size) ) {
                    new_val += puzzle->image_matrix[new_ic.row][new_ic.col] * puzzle->kernel_matrix[kc.row + 1][kc.col];
                } 
                break;
            case UPLEFT:
                new_ic.row = ic.row - 1;
                new_ic.col = ic.col - 1;
                if (inBounds(new_ic, puzzle->image_size) ) {
                    new_val += puzzle->image_matrix[new_ic.row][new_ic.col] * puzzle->kernel_matrix[kc.row - 1][kc.col - 1];
                } 
                break;
            case UPRIGHT:
                new_ic.row = ic.row - 1;
                new_ic.col = ic.col + 1;
                if (inBounds(new_ic, puzzle->image_size) ) {
                    new_val += puzzle->image_matrix[new_ic.row][new_ic.col] * puzzle->kernel_matrix[kc.row - 1][kc.col + 1];
                } 
                break;
            case DOWNLEFT:
                new_ic.row = ic.row + 1;
                new_ic.col = ic.col - 1;
                if (inBounds(new_ic, puzzle->image_size) ) {
                    new_val += puzzle->image_matrix[new_ic.row][new_ic.col] * puzzle->kernel_matrix[kc.row + 1][kc.col - 1];
                } 
                break;
            case DOWNRIGHT:
                new_ic.row = ic.row + 1;
                new_ic.col = ic.col + 1;
                if (inBounds(new_ic, puzzle->image_size) ) {
                    new_val += puzzle->image_matrix[new_ic.row][new_ic.col] * puzzle->kernel_matrix[kc.row + 1][kc.col + 1];
                } 
                break;
        }

    }  

    puzzle->output_matrix[ic.row][ic.col] = new_val;

}

int main() {
    FILE *fp;
    struct puzzle_t puzzle;
    int p_num = 1;

    fp = fopen("./input_problem_2.txt", "r");

    if (fp == NULL) exit(EXIT_FAILURE);

    while (p_num <= 10) {

        fscanf(fp, "%d", &puzzle.image_size);
        fscanf(fp, "%d", &puzzle.kernel_size);

        // read image matrix
        for(size_t i = 0; i < puzzle.image_size; ++i) {
            for(size_t j = 0; j < puzzle.image_size; ++j) {
                fscanf(fp, "%d", puzzle.image_matrix[i] + j);
            }
        }

        // print image matrix
        // printMatrix(puzzle, puzzle.image_matrix);

        // read kernel matrix
        for(size_t i = 0; i < puzzle.kernel_size; ++i) {
            for(size_t j = 0; j < puzzle.kernel_size; ++j) {
                fscanf(fp, "%d", puzzle.kernel_matrix[i] + j);
            }
        }

        //solve problem
        struct coord central_kernel = {1,1};
        struct coord curr_coord;

        for(int i = 0; i < puzzle.image_size; ++i) {
            for(int j = 0; j < puzzle.image_size; ++j) {
                curr_coord.row = i;
                curr_coord.col = j;
                applyKernel(&puzzle, curr_coord, central_kernel);
            }
        }

        // print image matrix
        printf("Test case: %d\n", p_num);
        printMatrix(puzzle, puzzle.output_matrix);

        p_num++;
    }

    fclose(fp);
    exit(EXIT_SUCCESS);
}