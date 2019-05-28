// Source : http://leetcode-cn.com/problems/n-queens-ii/
// Author : nanguoyu
// Date   : 2019/5/28

/*********************************************************************************************************************
 *
The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.



Given an integer n, return the number of distinct solutions to the n-queens puzzle.

Example:

Input: 4
Output: 2
Explanation: There are two distinct solutions to the 4-queens puzzle as shown below.
[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
 *
 *
 *
 ******************************************************************************************************************** */

bool check(int n, int *row, int *col, int x, int y)
{
    /*
     * n board size
     * row[] queens in row
     * col[] queens in col
     * x y position will try
     * nq queens who not be set
     * */

    /*---*/
    if (row[x] != -1) { return false; }

    /*|*/
    if (col[y] != -1) { return false; }

    /*\*/
    for (int i = x - 1, j = y - 1; i >= 0 && j >= 0; i--, j--) {
        if (row[i] == j && col[j] == i) return false;
    }
    for (int i = x + 1, j = y + 1; i < n && j < n; i++, j++) {
        if (row[i] == j && col[j] == i) return false;
    }

    /*/*/
    for (int i = x - 1, j = y + 1; i >= 0 && j < n; i--, j++) {
        if (row[i] == j && col[j] == i) return false;
    }
    for (int i = x + 1, j = y - 1; i < n && j >= 0; i++, j--) {
        if (row[i] == j && col[j] == i) return false;
    }

    return true;
}

void dfs(int n, int *row, int *col, int x, int y, int *nq, int *returnSize)
{
    if ((*nq) == 0) {
        (*returnSize)++;
    }

    for (int l = x; l < n; ++l) {
        for (int k = y; k < n; ++k) {
            if (check(n, row, col, l, k)) {
                row[l] = k;
                col[k] = l;
                (*nq) -= 1;
                dfs(n, row, col, l + 1, 0, nq, returnSize);
                row[l] = -1;
                col[k] = -1;
                (*nq) += 1;
            }
        }
    }


}


int totalNQueens(int n)
{
    int * returnSize = (int *) malloc(sizeof(int));
    *returnSize = 0;
//    char ***res = (char ***) malloc(sizeof(char **) * 1000);
    int *row = (int *) malloc(n * sizeof(int));
    for (int j = 0; j < n; ++j) { row[j] = -1; }
    int *col = (int *) malloc(n * sizeof(int));
    for (int j = 0; j < n; ++j) { col[j] = -1; }
    int *nq = (int *) malloc(sizeof(int));
    (*nq) = n;

    dfs(n, row, col, 0, 0, nq, returnSize);
    return *returnSize;
}

int main()
{
    int n = 8;

    int a = totalNQueens(n);
    printf("%d\n",a);

    return 0;
}
