#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include<string>
#include<windows.h>

using namespace std;


int comp_fun(const void*a,const void*b)
{
    int *aptr = *(int **)a;
    int *bptr = *(int **)b;
    if(aptr[0]!=bptr[0]){
        return aptr[0]-bptr[0];
    } else{
        return aptr[1]-bptr[1];
    }
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes){

    if (intervalsSize == 0) {
        if(!returnColumnSizes){
            returnColumnSizes = (int **)malloc(sizeof(int *));
        }
        *returnColumnSizes = NULL; }


    qsort(intervals, intervalsSize, sizeof(int) * 2, comp_fun);
    // printf("[INFO] input:\n");
    // for (int i = 0; i < intervalsSize; ++i) {
    //     for (int j = 0; j < intervalsColSize[i]; ++j) {
    //         printf(" %d ", intervals[i][j]);
    //     }
    //     printf("\n");
    // }

    if (!returnSize) {
        returnSize = (int *) malloc(sizeof(int));
    }
    *returnSize = 0;

    int **res = (int **) malloc(sizeof(int *) * intervalsSize);


    for (int k = 0; k < intervalsSize; k++) {
        int *unit = (int *) malloc(sizeof(int) * 2);
        unit[0] = intervals[k][0];
        int max_right = intervals[k][1];
        while (k+1<intervalsSize && (intervals[k][1] >= intervals[k + 1][0] || max_right >= intervals[k + 1][0])) {
            if(intervals[k][1]>=max_right){max_right=intervals[k][1];}
            k++;
        }
        if(intervals[k][1]>=max_right){max_right=intervals[k][1];}
        unit[1]=max_right;
        res[*returnSize]=unit; (*returnSize)++;

    }

    if(!returnColumnSizes){
        returnColumnSizes = (int **)malloc(sizeof(int *));
    }
    *returnColumnSizes = (int *)malloc(sizeof(int )*(*returnSize));
    for (int l = 0; l < *returnSize; ++l) {
        (*returnColumnSizes)[l]=2;
    }

    // printf("\n[INFO] output:\n");
    // for (int i = 0; i < *returnSize; ++i) {
    //     for (int j = 0; j < (*returnColumnSizes)[i]; ++j) {
    //         printf(" %d ", res[i][j]);
    //     }
    //     printf("\n");
    // }
    return res;
}


int main()
{


    return 0;
}

