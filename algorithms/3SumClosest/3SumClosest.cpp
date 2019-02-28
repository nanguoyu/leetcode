// Source : https://oj.leetcode.com/problems/3sum-closest/
// Author : Hao Chen
// Date   : 2014-07-03

/**********************************************************************************
*
* Given an array S of n integers, find three integers in S such that the sum is
* closest to a given number, target. Return the sum of the three integers.
* You may assume that each input would have exactly one solution.
*
*     For example, given array S = {-1 2 1 -4}, and target = 1.
*
*     The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*
*
**********************************************************************************/
#include<stdlib.h>

int comp(const void *a, const void *b)
{
    return *(int *) a - *(int *) b;
}

int threeSumClosest(int *nums, int numsSize, int target)
{

#define  nullptr 0
    if (numsSize < 3) {
        return nullptr;
    }
    qsort(nums, (size_t) numsSize, sizeof(int), comp);
    int ClosetLength = INT_MAX;
    int ClostNumber = target;

    for (int i = 0; i < numsSize - 2; ++i) {
        int j = i + 1;
        int k = numsSize - 1;
        while (j < k) {
            int length = target - nums[j] - nums[k] - nums[i];

            if (length == 0) {
                return target;
            } else if (length < 0) {
                if (-length < ClosetLength) {
                    ClosetLength = -length;
                    ClostNumber = nums[j] + nums[k] + nums[i];
                }

                while (k > 0 && nums[k] == nums[k - 1]) k--;
                k--;
            } else {
                if (length < ClosetLength) {
                    ClosetLength = length;
                    ClostNumber = nums[j] + nums[k] + nums[i];
                }

                while (j < numsSize - 1 && nums[j] == nums[j + 1]) j++;
                j++;
            }

        }
    }
    return ClostNumber;
}