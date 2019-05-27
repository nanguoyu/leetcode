// Source : https://leetcode.com/problems/n-queens/
// Author : nanguoyu
// Date   : 2019/5/27


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

bool dfs(int n, int *row, int *col, int x, int y, int *nq, int *returnSize, char ***res)
{
    if ((*nq) == 0) {
//        printf("\n");
//        for (int i = 0; i < n; ++i) {
//            for (int j = 0; j < n; ++j) {
//                if (row[i] == j && col[j] == i) {
//                    printf(" Q ");
//                } else { printf(" . "); }
//            }
//            printf("\n\n");
//        }


        char **unit = (char **) malloc(sizeof(char *) * n);

        for (int i = 0; i < n; ++i) {
            char *munit = (char *) malloc(sizeof(char) * n);

            for ( int j = 0; j < n; ++j) {
                if (row[i] == j && col[j] == i) {
                    munit[j] = 'Q';
//                    printf("%c",munit[j]);
                } else {
                    munit[j] = '.';
//                    printf("%c",munit[j]);
                }
            }

            unit[i] = munit;
        }


        res[*returnSize] = unit;
        (*returnSize)++;
//        printf("\n\n");
        return true;
    }

    for (int l = x; l < n; ++l) {
        for (int k = y; k < n; ++k) {
            if (check(n, row, col, l, k)) {
                row[l] = k;
                col[k] = l;
                (*nq) -= 1;
                dfs(n, row, col, l + 1, 0, nq, returnSize, res);
                row[l] = -1;
                col[k] = -1;
                (*nq) += 1;
            }
        }
    }

    if ((*nq) != 0) {
        return false;
    } else {
        return true;
    }


}


char ***solveNQueens(int n, int *returnSize, int **returnColumnSizes)
{
    if (!returnSize) { returnSize = (int *) malloc(sizeof(int)); }
    *returnSize = 0;
    char ***res = (char ***) malloc(sizeof(char **) * 1000);
    int *row = (int *) malloc(n * sizeof(int));
    for (int j = 0; j < n; ++j) { row[j] = -1; }
    int *col = (int *) malloc(n * sizeof(int));
    for (int j = 0; j < n; ++j) { col[j] = -1; }
    int *nq = (int *) malloc(sizeof(int));
    (*nq) = n;

    dfs(n, row, col, 0, 0, nq, returnSize, res);

    *returnColumnSizes = (int *)malloc(sizeof(int ) *(*returnSize));
    for (int i = 0; i < (*returnSize); ++i) {
        (*returnColumnSizes)[i]=n;
    }
    return res;
}

int main()
{
    int n = 4;
    int *returnSize = (int *) malloc(sizeof(int));
    int **returnColumnSizes = (int **)malloc(sizeof(int *));
    char *** res = solveNQueens(n, returnSize, returnColumnSizes);

    for (int i = 0; i < *returnSize; ++i) {
        for (int j = 0; j < (*returnColumnSizes)[i]; ++j) {
            for (int k = 0; k < n; ++k) {
                printf(" %c ",res[i][j][k]);
            }
            printf("\n");
        }
        printf("\n\n");
    }
    printf("\n\n\n");
    return 0;
}