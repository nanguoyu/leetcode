// Source : https://leetcode.com/problems/4sum/
// Author : nanguoyu
// Date   : 2019/3/2

/*************************************
 * Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.
* Note:
* The solution set must not contain duplicate quadruplets.
* Example:
* Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.
* A solution set is:
* [
* [-1,  0, 0, 1],
* [-2, -1, 1, 2],
* [-2,  0, 0, 2]
* ]
 ************************************/


int comp(const void *a, const void *b)
{
    return *(int *) a - *(int *) b;
}

int **fourSum(int *nums, int numsSize, int target, int *returnSize)
{
#define  nullptr 0
    if (numsSize < 4) {
        *returnSize = 0;
        return nullptr;
    }
    qsort(nums, (size_t) numsSize, sizeof(int), comp);
    int **result = (int **) malloc(sizeof(int *) * 1000);
    *returnSize = 0;

    for (int i = 0; i <numsSize - 3; ++i) {
        if (i > 0 && nums[i - 1] == nums[i]) continue;

        for (int j = i + 1; j <numsSize - 2; ++j) {
            if (j > i+1 && nums[j - 1] == nums[j]) continue;
            int k = j + 1;
            int l = numsSize - 1;

            while (k < l) {
                if (target - nums[l] - nums[k] == nums[j] + nums[i]) {
                    int *unit = (int *) malloc(sizeof(int) * 4);
                    unit[0] = nums[i];
                    unit[1] = nums[j];
                    unit[2] = nums[k];
                    unit[3] = nums[l];
                    result[*returnSize] = unit;
                    (*returnSize)++;

                    while (k < numsSize - 1 && nums[k] == nums[k + 1]) k++;
                    k++;
                    while (l > 0 && nums[l] == nums[l - 1]) l--;
                    l--;

                } else if (target - nums[l] - nums[k] > nums[j] + nums[i]) {
                    while (k < numsSize - 1 && nums[k] == nums[k + 1]) k++;
                    k++;

                }else{
                    while (l > 0 && nums[l] == nums[l - 1]) l--;
                    l--;

                }
            }

        }
    }

    return result;
}


int main()
{
    int nums[] = {0,0,0,0};
    int numsSize = 4;
    int target = 0;
    int returnSize=0;
    int **a = fourSum(nums, numsSize, target, &returnSize);

    for (int i = 0; i < returnSize; ++i) {
        cout<<"[output]";
        for (int j = 0; j < 4; ++j) {
            cout<<a[i][j];
        }
        cout<<endl;
    }

    return 0;
}