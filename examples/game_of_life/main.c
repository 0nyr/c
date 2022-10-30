// console game of life on a 30x30 grid
// Path: examples/test/main.c

#include "stdio.h"
#include "stdlib.h"
#include "time.h"
// include usleep
#include "unistd.h"

#define GRID_WIDTH 10
#define GRID_HEIGHT 10
#define NB_OF_GENERATIONS 30

void init_grid(int grid[GRID_HEIGHT][GRID_WIDTH]);
void print_grid(int grid[GRID_HEIGHT][GRID_WIDTH]);
int count_neighbours(int grid[GRID_HEIGHT][GRID_WIDTH], int x, int y);
void update_grid(int grid[GRID_HEIGHT][GRID_WIDTH]);

int main() {
    int grid[GRID_HEIGHT][GRID_WIDTH];
    int i;

    init_grid(grid);
    print_grid(grid);

    for (i = 0; i < NB_OF_GENERATIONS; i++) {
        update_grid(grid);
        print_grid(grid);
        usleep(100000);
    }

    return 0;
}

void init_grid(int grid[GRID_HEIGHT][GRID_WIDTH]) {
    int x, y;

    for (y = 0; y < GRID_HEIGHT; y++) {
        for (x = 0; x < GRID_WIDTH; x++) {
            grid[y][x] = rand() % 2;
        }
    }
}

void print_grid(int grid[GRID_HEIGHT][GRID_WIDTH]) {
    int x, y;

    for (y = 0; y < GRID_HEIGHT; y++) {
        for (x = 0; x < GRID_WIDTH; x++) {
            if (grid[y][x]) {
                printf("0");
            } else {
                printf(" ");
            }
        };
        // newline after each row
        printf("\n");
    }
    
    // separator between generations
    printf("####################\n");
}

int count_neighbours(int grid[GRID_HEIGHT][GRID_WIDTH], int x, int y) {
    int i, j;
    int n = 0;

    for (i = -1; i <= 1; i++) {
        for (j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) {
                continue;
            }

            if (grid[(y + i + GRID_HEIGHT) % GRID_HEIGHT][(x + j + GRID_WIDTH) % GRID_WIDTH]) {
                n++;
            }
        }
    }

    return n;
}

void update_grid(int grid[GRID_HEIGHT][GRID_WIDTH]) {
    int x, y;
    int new_grid[GRID_HEIGHT][GRID_WIDTH];

    for (y = 0; y < GRID_HEIGHT; y++) {
        for (x = 0; x < GRID_WIDTH; x++) {
            int n = count_neighbours(grid, x, y);

            if (grid[y][x] == 1) {
                if (n < 2 || n > 3) {
                    new_grid[y][x] = 0;
                } else {
                    new_grid[y][x] = 1;
                }
            } else {
                if (n == 3) {
                    new_grid[y][x] = 1;
                } else {
                    new_grid[y][x] = 0;
                }
            }
        }
    }

    // replace old grid by new_grid
    for (y = 0; y < GRID_HEIGHT; y++) {
        for (x = 0; x < GRID_WIDTH; x++) {
            grid[y][x] = new_grid[y][x];
        }
    }

}