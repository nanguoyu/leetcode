// Source : https://leetcode.com/problems/sudoku-solver/
// Author : nanguoyu
// Date   : 2019/3/13
// SudokuSolver
/***********************************************************************************************
Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy all of the following rules:

Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
Empty cells are indicated by the character '.'.


A sudoku puzzle...


...and its solution numbers marked in red.

Note:

The given board contain only digits 1-9 and the character '.'.
You may assume that the given Sudoku puzzle will have a single unique solution.
The given board size is always 9x9.
 *********************************************************************************************/


bool fun(char **board, int row,int col,int (*row_group)[9], int (*col_group)[9], int (*grid_group)[9])
{
    bool is = false;
    if (board[row][col] == '.') {
        for (int k = 0; k < 9; ++k) {
            if (!row_group[row][k] && !col_group[col][k] && !grid_group[3 * (row / 3) + col / 3][k]) {

                row_group[row][k]=1;
                col_group[col][k]=1;
                grid_group[3 * (row / 3) + col / 3][k]=1;
                char *pre = (char *) malloc(sizeof(char) * 10); pre[0] = 0;
                char *kk = (char *) malloc(sizeof(char) * 2); kk[0]=k+49;kk[1]=0;

//                printf("k=%d kk = %s\n",k, kk);
                strncpy(pre, board[row], col);
                pre[col]=0;
                strcat(pre, kk);
                strcat(pre, &board[row][col+1]);
//                printf("%s\n",pre);
                board[row] = pre;

                int i= row,j=col;
                if(row<9) {col++;}
                if(col==9 && row<9) {col=0;row++;}
                if(col==9 && row==9) {return true;}
                is = fun(board,row,col,row_group,col_group,grid_group);

                if(is){
                    return true;}
                else{
                    row=i;col=j;
                    row_group[row][k]=0;
                    col_group[col][k]=0;
                    grid_group[3 * (row / 3) + col / 3][k]=0;
                    char *pre = (char *) malloc(sizeof(char) * 10); pre[0] = 0;
                    char *kk = (char *) malloc(sizeof(char) * 2); kk[0]='.';kk[1]=0;
                    strncpy(pre, board[row], col);
                    pre[col]=0;
                    strcat(pre, kk);
                    strcat(pre, &board[row][col+1]);
                    board[row] = pre;

                }
            }
        }

    }else{
        if(row<9) {col++;}
        if(col==9 && row==8) {return true;}
        if(col==9 && row<9) {col=0;row++;}
        is = fun(board,row,col,row_group,col_group,grid_group);
        if(is){return true;}
    }
    return false;

}

void solveSudoku(char **board, int boardRowSize, int *boardColSizes)
{


    int col[9][9] = {0}; int (*cp) [9]=col;
    int row[9][9] = {0}; int (*rp) [9]=row;
    int grid[9][9] = {0}; int (*gp) [9] =grid;
    for (int i = 0; i < boardRowSize; ++i) {
        for (int j = 0; j < *boardColSizes; ++j) {
            if (board[i][j] == '.') continue;
            int n = board[i][j] - 49;
            col[i][n] = 1;
            row[j][n] = 1;
            grid[3 * (i / 3) + j / 3][n] = 1;
        }
    }

    fun(board,0,0,cp,rp,gp);

}


int main()
{
    char *board[9] = {"53..7....",
                      "6..195...",
                      ".98....6.",
                      "8...6...3",
                      "4..8.3..1",
                      "7...2...6",
                      ".6....28.",
                      "...419..5",
                      "....8..79"};


    int boardRowSize=9; int *boardColSizes=&boardRowSize;
    solveSudoku(board, boardRowSize, boardColSizes);

    printf("\n");
    for (int i = 0; i < boardRowSize; ++i) {
        for (int j = 0; j < *boardColSizes; ++j) {
            printf(" %c ",board[i][j]);
        }
        printf("\n");
    }

    return 0;
}
