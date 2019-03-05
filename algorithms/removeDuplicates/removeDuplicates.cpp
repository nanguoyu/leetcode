// Source : https://leetcode.com/problems/remove-duplicates-from-sorted-array/
// Author : nanguoyu
// Date   : 2019/3/5

/***************************************************************************************************************************
Given a sorted array nums, remove the duplicates in-place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

Example 1:

Given nums = [1,1,2],

Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.

It doesn't matter what you leave beyond the returned length.
Example 2:

Given nums = [0,0,1,1,1,2,2,3,3,4],

Your function should return length = 5, with the first five elements of nums being modified to 0, 1, 2, 3, and 4 respectively.

It doesn't matter what values are set beyond the returned length.
Clarification:

Confused why the returned value is an integer but your answer is an array?

Note that the input array is passed in by reference, which means modification to the input array will be known to the caller as well.

Internally you can think of this:

nums is passed in by reference. (i.e., without making a copy)
int len = removeDuplicates(nums);

any modification to nums in your function would be known by the caller.
using the length returned by your function, it prints the first len elements.
for (int i = 0; i < len; i++) {
print(nums[i]);
}
********************************************************************************************************************/


/*
 * This solution is not a efficient method. Its time complexity is O(n^2)
 * I will rewrite it as soon as possible :)
 */

int removeDuplicates(int *nums, int numsSize)
{
    if (!numsSize) {
        return 0;
    } else if (numsSize == 1) {
        return 1;
    }

    int i = 1, j = 0;
    int t = nums[0];
    for (int k = 1; k < numsSize; ++k) {
        if (nums[k] == t) {
            if(k+1>=numsSize) break;
            for (j = k + 1; j < numsSize; ++j) {
                if (nums[j] != t) break;
            }
            if(j==numsSize) break;
            i++;

            nums[k]=nums[j];
            t = nums[k];
        } else if(nums[k] < t){
            if(k+1>=numsSize) break;
            for (j = k + 1; j < numsSize; ++j) {
                if (nums[j] >t) break;
            }
            if(j==numsSize) break;
            i++;
            nums[k]=nums[j];
            t = nums[k];
        }else{
            i++;
            t = nums[k];
        }
    }
    return i;

}