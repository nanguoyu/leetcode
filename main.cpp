
#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include<string>
#include<windows.h>

using namespace std;

/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

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

int main()
{
    int a[4] = {1, 1, 1, 0};
    int b = -100;
    cout<<threeSumClosest(a,4,-100)<<endl;
    return 0;
}