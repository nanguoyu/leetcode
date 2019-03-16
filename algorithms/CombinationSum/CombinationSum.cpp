// Source : https://leetcode.com/problems/combination-sum/
// Author : nanguoyu
// Date   : 2019/3/16

/***********************************************************************************************
Given a set of candidate numbers (candidates) (without duplicates) and a target number (target),
 find all unique combinations in candidates where the candidate numbers sums to target.

The same repeated number may be chosen from candidates unlimited number of times.

Note:

All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
Example 1:

Input: candidates = [2,3,6,7], target = 7,
        A solution set is:
[
[7],
[2,2,3]
]
Example 2:

Input: candidates = [2,3,5], target = 8,
        A solution set is:
[
[2,2,2,2],
[2,3,3],
[3,5]
]
 ********************************************************************************************/


int comp(const void *a, const void *b)
{
    return *(int *) a - *(int *) b;
}



bool fun(int* buffer, int bufferSize, int * unit, int* unit_len, int target, int **res,int** columnSizes, int* returnSize, int candidatesSize){
    unit[*unit_len] = buffer[0];
    (*unit_len)+=1;
    //
    if(target-buffer[0]==0){
        int *len = (int *)malloc(sizeof(int)); *len =(*unit_len);
        (*columnSizes)[(*returnSize)]= (*unit_len);
//        printf("(*columnSizes)[%d] = %d",(*returnSize), (*columnSizes)[(*returnSize)]);
        int *new_unit = (int *)malloc(sizeof(int)*(*unit_len));
//        printf("\n SOULATION[%d]len = %d {",*returnSize,*unit_len);
        for (int i = 0; i < (*len); ++i) {new_unit[i]=unit[i];}
        res[(*returnSize)] = new_unit;

        (*returnSize)+=1;
        (*unit_len)-=1;
        return true;
    }else if(target-buffer[0]>0){

        if(bufferSize==0){

            return false;
        }else{
            for (int i = 0; i < bufferSize; ++i) {
                if(target-buffer[0]<buffer[i]) continue;
//                printf("[target] %d ",target-buffer[0]);
//                printf("try -[%d]%d- \n",(*unit_len),buffer[i]);
                fun(buffer+i,bufferSize-i, unit, unit_len,target-buffer[0],res,columnSizes,returnSize, candidatesSize);
            }
            (*unit_len)-=1;

        }
    }else{
//        printf("failing to try -[%d]%d- \n",(*unit_len-1),buffer[0]);
        (*unit_len)-=1;
        return false;
    }

    return false;
}

int** combinationSum(int* candidates, int candidatesSize, int target, int** columnSizes, int* returnSize) {
    qsort(candidates,(size_t)candidatesSize, sizeof(int), comp);
//    int **res = (int **)malloc(sizeof(int *)*(candidatesSize*candidatesSize));
    int **res = (int **)malloc(sizeof(int *)*1000);
//    *columnSizes = (int *)malloc(sizeof(int)*(candidatesSize*candidatesSize));
    *columnSizes = (int *)malloc(sizeof(int)*1000);
    *returnSize=0;
    for (int i = 0; i < candidatesSize; ++i) {
        int *unit = (int *)malloc(sizeof(int)*(target*2));
        int *unit_len = (int *)malloc(sizeof(int)); unit_len[0]=0;
        int *  buffer = &candidates[i]; int bufferSize = candidatesSize-i;
//        printf("[target] %d ",target);
//        printf("try -[%d]%d- \n",(*unit_len),buffer[0]);
        fun(buffer,bufferSize, unit, unit_len,target,res,columnSizes,returnSize, candidatesSize);
    }
    return res;
}

int main()
{
    int candidate[]={2,3,5}; int candidatesSize = 3; int target = 20;
    int*returnSize=(int *)malloc(sizeof(int));
    int *candidates = candidate;
    int **columnSizes = (int **)malloc(sizeof(int *));

    int** res= combinationSum(candidates,candidatesSize,target,columnSizes,returnSize);
    printf("\n%d\n",(*returnSize));
    for (int i = 0; i < *returnSize; ++i) {
        printf("(*columnSizes)[%d] = %d",i,(*columnSizes)[i]);
        for (int j = 0; j < (*columnSizes)[i]; ++j) {
            printf(" %d ",res[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    return 0;
}

