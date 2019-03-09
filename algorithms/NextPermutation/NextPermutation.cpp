// Source : https://leetcode.com/problems/next-permutation/
// Author : nanguoyu
// Date   : 2019/3/9

/**********************************************************************************************************************
* Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

* If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

* The replacement must be in-place and use only constant extra memory.

* Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
*
* 1,2,3 → 1,3,2
* 3,2,1 → 1,2,3
* 1,1,5 → 1,5,1
 **********************************************************************************************************************/

int cmp (const void * a, const void * b)
{
    return ( *(int*)a - *(int*)b );
}

void nextPermutation(int *nums, int numsSize)
{
    int i = numsSize-1;    int j = numsSize-1;
    int *pre = &nums[numsSize-1];
    for (; j >=0; --j) {
        if (nums[j] < *pre) {break; }
        pre = &nums[j];
    }
    if (j != -1) {
        for (; i >j; --i) {
            if (nums[i] > nums[j] && nums[i]<*pre) {
                int t = nums[i]; nums[i] = *pre; *pre = t;
            }
        }
        int t = nums[j]; nums[j] = *pre; *pre = t;
        qsort(nums+j+1, numsSize-j-1, sizeof(int), cmp);
    }else{
        qsort(nums, numsSize, sizeof(int), cmp);
    }
}
