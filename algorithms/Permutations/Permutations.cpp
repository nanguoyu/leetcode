// Source : https://leetcode.com/problems/permutations/
// Author : nanguoyu
// Date   : 2019/3/21

/*************************************************************************
Given a collection of distinct integers, return all possible permutations.

Example:

Input: [1,2,3]
Output:
[
[1,2,3],
[1,3,2],
[2,1,3],
[2,3,1],
[3,1,2],
[3,2,1]
]
 *************************************************************************/


int fun(int * prefix, int prelen,int *num,int numsSize,int **res,int *returnSize){
//#include<string.h>
    if(numsSize>1){
        for (int i = 0; i < numsSize; ++i) {
            prefix[prelen]=num[i];
            int *unit = (int *)malloc(sizeof(int)*(prelen+2));
//            memcpy(unit,prefix, sizeof(prefix));

            for (int j = 0; j <=prelen; ++j) {
                unit[j]=prefix[j];
            }

            int *nums = (int *)malloc(sizeof(int)*(numsSize-1));
            for (int j = 0,k=0; j < numsSize; ++j) {
                if(j!=i){nums[k]=num[j];
                    k++;}
            }
            fun(unit,prelen+1,nums,numsSize-1,res,returnSize);
        }
    }
    else if(numsSize==1){
        prefix[prelen++]=num[0];
        res[(*returnSize)++]=prefix;
        return 1;
    }
    return 0;
}

int** permute(int* nums, int numsSize, int* returnSize) {
    int size = 1;
    printf("[INPUT]:");
    for (int j = 1; j <=numsSize; ++j) {
        size*=j;
        printf("%d ",nums[j-1]);
    }
    printf("\n");
    int **res=(int **)malloc(sizeof(int *)*(size));
    int *prefix =(int *)malloc(sizeof(int));
    fun(prefix,0,nums,numsSize,res,returnSize);
    printf("size = %d\n",*returnSize);


    return res;
}


int main()
{
    int num[]={0,1};
    int *nums = num;
    int numsSize =2;
    int size=0;int *returnSize=&size;
    int **res = permute(nums,numsSize,returnSize);
    for (int i = 0; i < (*returnSize); ++i) {
        for (int j = 0; j < numsSize; ++j) {
            printf("%d ",res[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    return 0;
}