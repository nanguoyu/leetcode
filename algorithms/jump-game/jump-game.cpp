// Source : https://leetcode.com/problems/jump-game/submissions/
// Author : nanguoyu
// Date   : 2019/6/3

/***************************************************************************************************************
 Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

Example 1:

Input: [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum
             jump length is 0, which makes it impossible to reach the last index.
**************************************************************************************************************/

bool canJump(int* nums, int numsSize){

    if(numsSize <= 1){
        return true;
    }
    if(nums[0]>=numsSize-1){
        return true;
    }

    if(nums[0]==0 && numsSize>1){
        return false;
    }

    for (int i = 0; i <numsSize; ) {
        int max = i+1;

        for (int j = 1; j <=nums[i]; ++j) {
            if(numsSize-1>i+j){
                if(nums[i+j]+i+j>=nums[max]+max){
                    // 找到了下下一步可以跳的距离超过下一步跳的最远距离
                    max = i+j;
                }
            }else if(numsSize-1<=i+j){
                return true;
            }
        }
        /*如果下下一步跳不到下一步可跳的最远距离时，则跳到下一步能跳的最远处*/
        if(max+nums[max]<=nums[i]){
//            printf("\n jump to %d then jump to %d is not as good as jump to %d directly\n",max,nums[max],nums[i]);
            max=nums[i];
        }
        i=max;
        /*如果已经跳到了最远处，则不再计算下一步*/
        if(i==numsSize-1){
            break;
        }else if(nums[i]==0){
            return false;
        }
    }
    return true;
}

bool canJumpII(int* nums, int numsSize){

    if(numsSize <= 1){
        return true;
    }
    if(nums[0]>=numsSize-1){
        return true;
    }
    bool this_canJump = false;
    for(int i = nums[0]; i>0;i--){
        if(canJump(nums+i,numsSize-i)){
            this_canJump = true;
            return this_canJump;
        }
    }
    return this_canJump;


}



int main()
{
//    int num[]={7,0,9,6, 9 ,6,1, 7 ,9,0,1,2,9,0,3};
    int num[]={0,1};
    int *nums = num;
    int numsSzie =2;
    int res = canJump(nums,numsSzie);
    printf(" %d \n", res);

    return 0;
}