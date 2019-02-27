// Source : https://oj.leetcode.com/problems/3sum/
// Author : nanguoyu
// Date   : 2019-02-27

/**********************************************************************************
*
* Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0?
* Find all unique triplets in the array which gives the sum of zero.
*
* Note:
*
* Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
* The solution set must not contain duplicate triplets.
*
*     For example, given array S = {-1 0 1 2 -1 -4},
*
*     A solution set is:
*     (-1, 0, 1)
*     (-1, -1, 2)
*
*
**********************************************************************************/

#include<stdlib.h>

int comp(const void *a, const void *b)
{
    return *(int *) a - *(int *) b;
}

typedef  struct numberVector {
    int num[3];
    bool isrepeat;
} numVector;

void DeRepeat(int index, numVector **nums, int numsSsie){
    cout<<"Derepeating:"<<nums[index]->num[0]<<" "<<nums[index]->num[1]<<" "<<nums[index]->num[2]<<endl;
    if (index==0){
        for (int i = 1; i < numsSsie; ++i) {
            if(nums[i]->num[0]==nums[index]->num[0] && nums[i]->num[1]==nums[index]->num[1] && nums[i]->num[2]==nums[index]->num[2]){
                nums[i]->isrepeat=true;
            }
        }
    }else if(index==numsSsie-1){
        for (int i = index-1; i >= 0; --i) {
            if(nums[i]->num[0]==nums[index]->num[0] && nums[i]->num[1]==nums[index]->num[1] && nums[i]->num[2]==nums[index]->num[2]){
                nums[i]->isrepeat=true;

            }
        }
    }else{
        for (int i = index+1; i < numsSsie; ++i) {
            if(nums[i]->num[0]==nums[index]->num[0] && nums[i]->num[1]==nums[index]->num[1] && nums[i]->num[2]==nums[index]->num[2]){
                nums[i]->isrepeat=true;

            }
        }
        for (int i = index-1; i >=0; --i) {
            if(nums[i]->num[0]==nums[index]->num[0] && nums[i]->num[1]==nums[index]->num[1] && nums[i]->num[2]==nums[index]->num[2]){
                nums[i]->isrepeat=true;

            }
        }
    }

}


int **threeSum(int *nums, int numsSize, int *returnSize)
{
#define  nullptr 0
    if (numsSize < 3) {
        *returnSize = 0;
        return nullptr;
    }
    qsort(nums, (size_t) numsSize, sizeof(int), comp);
    numVector **result = (numVector **) malloc(sizeof(numVector *) * 10000);
    *returnSize = 0;
    int i = 0, j = i + 1, k = numsSize-1;
//    int prei = 0, prej = 0, prek = 0;
//    bool first = false;

    while (i <= numsSize-2) {
        while (i+2 <= k) {
            while(j<=k-1){
                if (nums[i] + nums[j] + nums[k] == 0) {
                    numVector *unit = (numVector *) malloc(sizeof(numVector) * 3);
                    unit->num[0] = nums[i];unit->num[1] = nums[j];unit->num[2] = nums[k];
                    unit->isrepeat= false;
//                            cout << "i=" << i << " j=" << j << " k=" << k << "  ";
//                            cout << nums[i] << " + " << nums[j] << " + " << nums[k] << " = ";
//                            cout << nums[i] + nums[j] + nums[k] << endl;
                    result[*returnSize] = unit;
                    (*returnSize)++;
                }
                j++;
            }
            j=i+1;
            k--;
        }
        i++;
        j = i + 1;
        k = numsSize-1;
    }
    int **ResultThreeNums = (int **) malloc(sizeof(int *) * (*returnSize));
    if(*returnSize==0){
        return 0;
    }
    int length =0;
    for (int l = 0; l < *returnSize; ++l) {

        for (int n = 0; n < 3; ++n) {
            cout<<result[l]->num[n];
        }
        cout<<endl;
        if (!result[l]->isrepeat){
            DeRepeat(l, result, *returnSize);
            int *unit = (int *) malloc(sizeof(int) * 3);
            for (int m = 0; m < 3; ++m) {
                unit[m] = result[l]->num[m];
//                cout<<unit[m];
            }
//            cout<<endl;
            ResultThreeNums[length] = unit;

            ++length;
        }
    }

    *returnSize=length;

//    cout<<"---------"<<endl;

    return ResultThreeNums;
}




int **threeSum(int *nums, int numsSize, int *returnSize)
{
#define  nullptr 0
    if (numsSize < 3) {
        *returnSize = 0;
        return nullptr;
    }
    qsort(nums, (size_t) numsSize, sizeof(int), comp);
    int **result = (int **) malloc(sizeof(int *) * 10000);

    *returnSize = 0;
    int i = 0;


    for (i=0;i <numsSize-2;i++) {

        if (i>0 && nums[i-1]==nums[i]) continue;
        int j = i + 1;
        int k = numsSize-1;


        while(j<k){

            if (nums[i] + nums[j] + nums[k] == 0) {

                int *unit = (int *)malloc(sizeof(int)*3);
                unit[0]=nums[i];unit[1]=nums[j];unit[2]=nums[k];
//                cout << "i=" << i << " j=" << j << " k=" << k << "  ";
//                cout << nums[i] << " + " << nums[j] << " + " << nums[k] << " = ";
//                cout << nums[i] + nums[j] + nums[k] << endl;
                result[*returnSize] = unit;
                (*returnSize)++;
                while(j<numsSize-1 && nums[j]==nums[j+1]) j++;
                while(k>0 && nums[k]==nums[k-1]) k--;
                j++;
                k--;
            }else if (nums[i] + nums[j] + nums[k] > 0){
                while(k>0 && nums[k]==nums[k-1]) k--;
                k--;
            }else{
                while(j<numsSize-1 && nums[j]==nums[j+1]) j++;
                j++;
            }

        }

    }
    return result;
}
