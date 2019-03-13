// Source : https://leetcode.com/problems/search-insert-position/
// Author : nanguoyu
// Date   : 2019/3/13

/*******************************************************************************
Given a sorted array and a target value, return the index if the target is found.
If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Example 1:

Input: [1,3,5,6], 5
Output: 2
Example 2:

Input: [1,3,5,6], 2
Output: 1
Example 3:

Input: [1,3,5,6], 7
Output: 4
Example 4:

Input: [1,3,5,6], 0
Output: 0
 ***********************************************************************************/


int find(int *nums, int left, int right, int target, bool * isexist)
{
    int medium = (right + left) / 2;
    if (target == nums[left]) return left;
    if (target == nums[right]) return right;
    if (target == nums[medium]) return medium;
    int res = -1;
    if(left==right-1){ *isexist = false;return left+1;}
    if (target > nums[medium]) {
        res = find(nums, medium, right, target, isexist);
        if (res != -1) {*isexist = true;return res;}
    } else {
        res = find(nums, left, medium, target, isexist);
        if (res != -1) {
            *isexist = true;
            return res;
        }
    }
    return res;
}

int searchInsert(int* nums, int numsSize, int target) {
    int res = 0;
    int left = 0;int right = numsSize - 1;int medium =  numsSize/2;
    bool isexist = true; bool * is_exist=&isexist;
    /*numsSize==0*/
    if (!numsSize){
        return res;}
    /*numsSize==1*/
    if(numsSize==1){
        if (target<=nums[0]){
            return res;
        } else{
            res=1;
            return res;
        }
    }
    /*numsSize>=2*/

    if (target == nums[left]){
        res=left;
    };
    if (target == nums[right]){
        res=right;
    };
    if (target == nums[medium]) {
        res=medium;
    };
    if (target > nums[left] && target < nums[right]) {
        res = find(nums, left, right, target, is_exist);
        if(!is_exist){

        }
    }else if(target > nums[right]) {
        res=right+1;
    } else if(target < nums[left]){
        res=left;
    }

    return res;


}