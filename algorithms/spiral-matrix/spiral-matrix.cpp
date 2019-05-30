// Source : https://leetcode.com/problems/spiral-matrix/
// Author : nanguoyu
// Date   : 2019/5/30

/*********************************************************************************************************
 * Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

Example 1:

Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
Output: [1,2,3,6,9,8,7,4,5]
Example 2:

Input:
[
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]
]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 *****************************************************************************************************/


void fun(int **matrix, int matrixSize, int *matrixColSize, int *returnSize, int *result, int prex, int prey){
    if(prex>=matrixSize/2 || prey>=(*matrixColSize)/2){
        if(prex>=matrixSize/2){
            /*top*/
            for (int i = 0+prex; i < (*matrixColSize)-prex; ++i) {
                result[*returnSize]=matrix[0+prey][i];
                printf(" %d ",result[*returnSize]);
                (*returnSize)++;
            }
        } else if (prey>=(*matrixColSize)/2){
            /*left*/
            for (int l = matrixSize-prey; l > 0+prey; --l) {
                result[*returnSize] = matrix[l][0+prex];
                printf(" %d ",result[*returnSize]);
                (*returnSize)++;
            }
        }

        prex++;prey++;
        printf("\n");
    } else{
        /*top*/
        for (int i = 0+prex; i < (*matrixColSize)-1-prex; ++i) {
            result[*returnSize]=matrix[0+prey][i];
            printf(" %d ",result[*returnSize]);
            (*returnSize)++;
        }
        /*right*/
        for (int j = 0+prey; j < matrixSize-1-prey; ++j) {
            result[*returnSize]=matrix[j][(*matrixColSize)-1-prex];
            printf(" %d ",result[*returnSize]);
            (*returnSize)++;
        }
        /*bottom*/
        for (int k = (*matrixColSize)-1-prex; k >0+prex; --k) {
            result[*returnSize]=matrix[matrixSize-1-prey][k];
            printf(" %d ",result[*returnSize]);
            (*returnSize)++;
        }
        /*left*/
        for (int l = matrixSize-1-prey; l > 0+prey; --l) {
            result[*returnSize] = matrix[l][0+prex];
            printf(" %d ",result[*returnSize]);
            (*returnSize)++;
        }
        prex++;prey++;
        fun(matrix, matrixSize, matrixColSize, returnSize, result, prex, prey);
    }

}

int *spiralOrder(int **matrix, int matrixSize, int *matrixColSize, int *returnSize)
{

    printf("[INFO] input\n");
    for (int i = 0; i < matrixSize; ++i) {
        for (int j = 0; j < *matrixColSize; ++j) {
            printf( " %d ",matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    if (matrixSize==0 || *matrixColSize==0){ return 0;}
    *returnSize = 0;
    int * result = (int *)malloc(sizeof(int)*(*matrixColSize)*matrixSize);
    fun(matrix, matrixSize, matrixColSize, returnSize, result, 0, 0);
    return result;
}


int main()
{
    int m[6][6] = {
            {1, 2, 3, 4, 5, 6},
            {11, 12, 13, 14, 15, 16},
            {21, 22, 23, 24, 25, 26},
            {31, 32, 33, 34, 35, 36},
            {41, 42, 43, 44, 45, 46},
            {51, 52, 53, 54, 55, 56}};
    int matrixSize = 6;
    int * matrixColSize = (int *)malloc(sizeof(int)); *matrixColSize=6;
    int * returnSize = (int *)malloc(sizeof(int));

    int ** matrix = (int **)malloc(sizeof(int *)*matrixSize);
    for (int i = 0; i < matrixSize; ++i) {
        int *mat = (int *) malloc(sizeof(int)*(*matrixColSize));
        for (int j = 0; j < *matrixColSize; ++j) {
            mat[j]=m[i][j];
        }
        matrix[i]=mat;
    }
    int * res = spiralOrder(matrix,matrixSize,matrixColSize,returnSize);

    return 0;
}
