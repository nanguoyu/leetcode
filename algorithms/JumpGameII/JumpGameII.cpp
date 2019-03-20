// Source : https://leetcode.com/problems/jump-game-ii/
// Author : nanguoyu
// Date   : 2019/3/20

/*****************************************************************************************************
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

Example:

Input: [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2.
Jump 1 step from index 0 to 1, then 3 steps to the last index.
Note:

You can assume that you can always reach the last index.
 **************************************************************************************************/

int jump(int* nums, int numsSize) {
    if(numsSize==1){return 0;}
    int res =0;
    for (int i = 0; i <numsSize; ) {
//        printf("from %d ",i);
        int max = i+1;

        for (int j = 1; j <=nums[i]; ++j) {
            if(numsSize>i+j){
                if(numsSize-1==i+j){
                    max = i+j;
//                    printf("jump to %d\n",max);
                    i=max;res++;return res;
                }
                if(nums[i+j]+i+j>=nums[max]+max){
                    max = i+j;
                }
            }else if(numsSize==i+j){
                max = i+j-1;
//                printf("jump to %d\n",max);
                i=max;res++;return res;
            }
        }
        /*如果下下一步跳不到下一步可跳的最远距离时，则跳到本次能跳的最远处*/
        if(max+nums[max]<=nums[i]){
//            printf("\n jump to %d then jump to %d is not as good as jump to %d directly\n",max,nums[max],nums[i]);
            max=nums[i];
        }
//        printf("jump to %d\n",max);
        i=max;
        res++;
        /*如果已经跳到了最远处，则不再计算下一步*/
        if(i==numsSize-1) break;
    }
    return res;
}


int main()
{
//    int num[]={7,0,9,6, 9 ,6,1, 7 ,9,0,1,2,9,0,3};
    int num[]={1,1};
    int *nums = num;
    int numsSzie =2;
    int res = jump(nums,numsSzie);
    printf("you need to jump %d times \n", res);
    printf("\n");

    return 0;
}
