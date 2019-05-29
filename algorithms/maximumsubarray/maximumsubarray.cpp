// Source : https://leetcode.com/problems/maximum-subarray/
// Author : nanguoyu
// Date   : 2019/5/29

/**************************************************************************************************************
 * Given an integer array nums, find the contiguous subarray (containing at least one number)
 * which has the largest sum and return its sum.
 * Example:
 * Input: [-2,1,-3,4,-1,2,1,-5,4],
 * Output: 6
 * Explanation: [4,-1,2,1] has the largest sum = 6.
 * Follow up:
 * If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach,
 * which is more subtle.
 *
 * ************************************************************************************************************/

int maxSubArray(int* nums, int numsSize){
    if (numsSize==0) return 0;

    int * Ptr = nums;
    int i=0,j=0;
    int MAX = nums[0]; int sum = nums[0];
    while(i<=numsSize-1 && j<numsSize-1){
        if(Ptr[j+1]>=sum+Ptr[j+1]) {
            j++;i=j;
            sum = Ptr[j];
        }
        else{
            j++;
            sum = sum + Ptr[j];
        }

        if (sum>=MAX){
            MAX=sum;
           // printf("%d %d max=%d\n",i,j,MAX);
        }
    }

    return MAX;
}



int main()
{
    int numsSize = 9;
    int  nums[9] = {-2,1,-3,4,-1,2,1,-5,4};
    int *numsptr = nums;
    int a = maxSubArray(numsptr,numsSize);
    printf("%d\n",a);

    return 0;
}
