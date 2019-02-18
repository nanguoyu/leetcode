// Source : https://oj.leetcode.com/problems/two-sum/
// Author : nanguoyu
// Date   : 2018-02-18

/**********************************************************************************
*
* Given an array of integers, find two numbers such that they add up to a specific target number.
*
* The function twoSum should return indices of the two numbers such that they add up to the target,
* where index1 must be less than index2. Please note that your returned answers (both index1 and index2)
* are not zero-based.
*
* You may assume that each input would have exactly one solution.
*
* Input: numbers={2, 7, 11, 15}, target=9
* Output: index1=1, index2=2
*
*
**********************************************************************************/

int* twoSum(int* nums, int numsSize, int target) {

    static int p[2]={0};
    for (int i = 0; i < numsSize; ++i) {
        for (int j = i+1; j < numsSize; ++j) {
            if(target-nums[i]==nums[j]){
                p[0]=i;p[1]=j;
                return p;
            }
        }
    }

    return 0;
}