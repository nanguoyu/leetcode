// Source : https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
// Author : nanguoyu
// Date   : 2019/3/12

/***********************************************************************************************************************
Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
 **********************************************************************************************************************/

int find(int *nums, int left, int right, int target)
{
    int medium = (right + left) / 2;
    if (target == nums[left]) return left;
    if (target == nums[right]) return right;
    if (target == nums[medium]) return medium;
    int res = -1;
    if (left == right - 1) { return -1; }
    if (target > nums[medium]) {
        res = find(nums, medium, right, target);
        if (res != -1) return res;
    } else {
        res = find(nums, left, medium, target);
        if (res != -1) return res;
    }

    return res;
}

int *searchRange(int *nums, int numsSize, int target, int *returnSize)
{
    int *result = (int *) malloc(sizeof(int *) * 2);
    result[0] = -1;
    result[1] = -1;
    int left = 0;
    int right = numsSize - 1;
    int medium = numsSize / 2;
    *returnSize = 2;
    /*numsSize==0*/
    if (!numsSize)
        return result;
    /*numsSize==1*/
    if (numsSize == 1) {
        if (target == nums[0]) {
            result[0] = 0;
            result[1] = 0;
            return result;
        } else {
            return result;
        }
    }
    /*numsSize>=2*/

    int res = -1;

    if (target == nums[left]) {res = left;};
    if (target == nums[right]) {res = right;};
    if (target == nums[medium]) {res = medium;};
    if (target > nums[left] && target < nums[right]) {res = find(nums, left, right, target);};

    if (res == -1) {
        return result;
    } else if (res == right) {
        result[1] = res;
        int i = right;
        for (; i >= left && nums[i] == target; --i) {}
        result[0] = i + 1;

    } else if (res == left) {
        result[0] = res;
        int i = left;
        for (; i <= right && nums[i] == target; ++i) {}
        result[1] = i - 1;

    } else {
        int i = res, j = res;
        for (; i >= left && nums[i] == target; --i) {}
        for (; j <= right && nums[j] == target; ++j) {}
        result[0] = i + 1;
        result[1] = j - 1;

    }

    return result;


}
