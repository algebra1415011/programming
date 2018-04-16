#include <stdio.h>
#include <stdlib.h>
#define ROW 6
#define COL 5

int min(int a, int b, int c)
{
    if (a < b) {
        return (a < c) ? a : c;
    } else {
        return (b < c) ? b : c;
    }
}

int main()
{
    int matrix[ROW][COL] = {
                {0, 0, 1, 1, 0}, 
                {0, 0, 0, 0, 1}, 
                {1, 0, 0, 0, 1},
                {0, 0, 0, 0, 1},
                {0, 0, 0, 0, 0},
                {1, 1, 1, 1, 1}};
                
    int output[ROW][COL] = {0};
    int i, j;
    int max = 1;
    
    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            if (matrix[i][j] == 0)
                output[i][j] = 1;
        }
    }
    
    for (i = 1; i < ROW; i++) {
        for (j = 1; j < COL; j++) {
            if (output[i][j]) {
                output[i][j] = min(output[i-1][j-1], output[i-1][j], output[i][j-1]) + 1;
                if (output[i][j] > max)
                    max = output[i][j];
            }
        }
    }
    
    printf("The maximum size of sub-square matrix is : %d\n", max);

     return 0;
}