// Source : https://leetcode.com/problems/first-missing-positive/
// Author : nanguoyu
// Date   : 2019/3/18

/***************************************************************************
Given an unsorted integer array, find the smallest missing positive integer.

Example 1:

Input: [1,2,0]
Output: 3
Example 2:

Input: [3,4,-1,1]
Output: 2
Example 3:

Input: [7,8,9,11,12]
Output: 1
Note:

Your algorithm should run in O(n) time and uses constant extra space.
 *************************************************************************/


void swap(int *a, int *b)
{
    int c = *a;
    *a = *b;
    *b = c;
}

int firstMissingPositive(int* nums, int numsSize) {
    int i = 0;
    while( i < numsSize) {
        if(nums[i]>0&& nums[i]<numsSize && nums[i]!=i+1 && nums[nums[i]-1]!=nums[i]){
            swap(nums+nums[i]-1,nums+i);
        };
        if(nums[i]==i+1 || nums[i]<=0 || nums[i]>=numsSize ||nums[nums[i]-1]==nums[i]){++i;}
    }


    int j=0;
    for (; j < numsSize; ++j) {
        if (j!=nums[j]-1) break;
    }
    return j+1;
}

int main()
{
    int numbers[]={1,1}; int numsSize=3;
    int *nums = numbers;
    int res = firstMissingPositive(nums,numsSize);
    printf("%d\n",res);

    return 0;
}


