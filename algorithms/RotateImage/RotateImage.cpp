// Source : https://leetcode.com/problems/rotate-image/
// Author : nanguoyu
// Date   : 2019/3/24

/*******************************************************************************
You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Note:

You have to rotate the image in-place, which means you have to modify the
 input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

Example 1:

Given input matrix =
[
[1,2,3],
[4,5,6],
[7,8,9]
],

rotate the input matrix in-place such that it becomes:
[
[7,4,1],
[8,5,2],
[9,6,3]
]
Example 2:

Given input matrix =
[
[ 5, 1, 9,11],
[ 2, 4, 8,10],
[13, 3, 6, 7],
[15,14,12,16]
],

rotate the input matrix in-place such that it becomes:
[
[15,13, 2, 5],
[14, 3, 4, 1],
[12, 6, 8, 9],
[16, 7,10,11]
]
 **************************************************************************/


void fun(int **matrix, int matrixRowSize, int *matrixColSizes, int i,int j,int k, int l,int raw){
    if(i==k&&j==l){
        printf(" [%d,%d] \n",i,j);
        matrix[i][j]=raw;
    }
    else{
        printf(" [%d,%d] \n",i,j);
        int next = matrix[i][j];
        matrix[i][j]=raw;
        fun(matrix,matrixRowSize,matrixColSizes,j,matrixRowSize-1-i,k,l,next);
    }
}

void rotate(int **matrix, int matrixRowSize, int *matrixColSizes)
{
    for (int i = 0; i < matrixRowSize; ++i) {
        for (int j = 0; j <(*matrixColSizes); ++j) {
            printf(" %d ",matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    printf("start\n");
    for (int l = 0; l < matrixRowSize; ++l) {
        for (int i = l; i <(*matrixColSizes)-1-l; ++i) {
//            printf(" %d ",matrix[l][i]);
            printf("l=%d,i=%d\n",l,i);
            fun(matrix,matrixRowSize,matrixColSizes,i,matrixRowSize-1-l,l,i,matrix[l][i]);
        }
        printf("\n");
    }
    printf("\n");


}


int main()
{
    int matrix[3][3] =
            {
                    {5, 1, 9},
                    {2, 4, 8},
                    {13, 3, 6},
            };
    int matrixRowSize =3; int matrixColSize=matrixRowSize; int *matrixColSizes=&matrixColSize;
    int **b=(int **)malloc(sizeof(int*)*matrixRowSize);
    for (int i = 0; i < matrixRowSize; ++i) {
        b[i]=matrix[i];
    }
    rotate(b,matrixRowSize,matrixColSizes);
    printf("\n");
    for (int i = 0; i < matrixRowSize; ++i) {
        for (int j = 0; j <(*matrixColSizes); ++j) {
            printf(" %d ",matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    return 0;
}
