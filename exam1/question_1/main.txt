#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXROWS 10
#define MAXCOLS 10
int grid[MAXROWS][MAXCOLS];

// A lone palm is a single tree that is surrounded on all sides by sand. 
// Each 2D grid may have some lone palms. Count the number of lone palms in 
// the grid and display it. A palm tree is represented by 0, sand is 
// represented by 1, and rock by 2. Note that two or more palms in adjacent 
// squares that are surrounded on all sides by sand are not considered to 
// be lone palms.

int surroundedBySand(int grid[MAXROWS][MAXCOLS], int row, int col, int max) {
    int directions[8][2] = { 
        {0,1}, {1,0}, {1,1}, {-1,-1},
        {-1,0}, {0,-1}, {1,-1}, {-1,1} 
    };

    if (row == 0 || col == 0 || row >= max || col >= max) {
        return 0;
    }

    for (int i = 0; i < 8; i++) {
        int r = row + directions[i][0];
        int c = col + directions[i][1];
        if (grid[r][c] != 1) {
            return 0;
        }
    }
    
    return 1;
};

int main() {
    freopen("q1_input.txt", "r", stdin);
	int rows, cols, numTestCases;
	scanf("%d", &numTestCases);


    for (int i = 0; i < numTestCases; i++) {
        printf("Test Case #%d \n", i + 1);
        scanf("%d", &rows);
        cols = rows;
        int count = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                scanf(" %d", &grid[i][j]); 
            }
        }

        int lone_palms = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 0 ) {
                    if (surroundedBySand(grid, i, j, rows)) {
                        count++;
                    }            
                }
            }
        }
        printf("%d \n", count);
    }

}