
#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include<string>
#include<windows.h>

using namespace std;

int comp(const void *a, const void *b)
{
    return *(int *) a - *(int *) b;
}

struct ListNode {
    int val;
    struct ListNode *next;
};

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

