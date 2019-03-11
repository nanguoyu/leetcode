// Source : https://leetcode.com/problems/search-in-rotated-sorted-array/
// Author : nanguoyu
// Date   : 2019/3/11

/***************************************************************************************************
 Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

Your algorithm's runtime complexity must be in the order of O(log n).

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
 ***********************************************************************************/


int find(int *nums, int left, int right, int target)
{
    int medium = (right + left) / 2;
    if (target == nums[left]) return left;
    if (target == nums[right]) return right;
    if (target == nums[medium]) return medium;
    int res = -1;
    if(left==right-1){ return -1;}
    if (target > nums[medium]) {
        cout<<"?\n";

        res = find(nums, medium, right, target);
        if (res != -1) return res;
    } else {
        res = find(nums, left, medium, target);
        if (res != -1) return res;
    }

    return res;
}

int search(int *nums, int numsSize, int target)
{
    if (!numsSize)
        return -1;
    int left = 0;
    int right = numsSize - 1;
    int medium = 0;
    int res = -1;
    while (left<right && nums[left] > nums[right]) {
        left++;
    }
    cout<<left<<endl;
    int max = 0;
    if (0 == left) { max = nums[0]; } else { max = nums[left - 1]; }
    medium = left;
    left = 0;
    if (target == nums[left]) return left;
    if (target == nums[right]) return right;
    if (target == nums[medium]) return medium;
    if (target > nums[medium] && target < nums[right]) {
        res = find(nums, medium, right, target);
        if (res != -1) return res;
    } else if (target > nums[left] && target <=max) {
        res = find(nums, left, medium, target);
        if (res != -1) return res;
    }

    return res;


}