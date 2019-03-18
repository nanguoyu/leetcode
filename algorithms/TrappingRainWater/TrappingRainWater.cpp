// Source : https://leetcode.com/problems/trapping-rain-water/
// Author : nanguoyu
// Date   : 2019/3/19

/***********************************************************************************************
Given n non-negative integers representing an elevation map where the width of each bar is 1,
 compute how much water it is able to trap after raining.


The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6
 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!

Example:

Input: [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
 ************************************************************************************************/

int sumfun(int *height, int s, int e){
    int unit0=0;
    int h = height[s] > height[e] ? height[e] : height[s];
    for (int m = s+1; m < e; ++m) {
        if((h - height[m])>0){
            unit0 += (h - height[m]);
        }
    }
    return unit0;
}

int trap(int *height, int heightSize)
{
    if (heightSize <= 2) return 0;
    int sum = 0; int unit0=0;
    int *diff =(int *)malloc(sizeof(int)*(heightSize-1));
    for (int i = 0; i < heightSize-1; ++i) {
        diff[i]=height[i+1]-height[i];
    }
    int j = 0; int k=0,l=0;
    while ( j < heightSize - 1) {
        if(diff[j]<0){
            k=j;
            while(j < heightSize - 1 && diff[j]<=0) { j++;}
            while(j < heightSize - 1 && diff[j]>0) {j++;}
            int w=j; int max =j;
            while(j < heightSize - 1 && height[j]<height[k]) { if(height[max]<=height[j]){max=j;}j++;}
            if(height[max]<height[j]){max=j;}
            if(max!=w){j=max;}else{j=w;}
            l=j;
            unit0=sumfun(height,k,l);
            sum+=unit0;
        }else{
            j++;
        }
    }


    return sum;
}

int main()
{
    int numbers[] = {4,9,4,5,3,2};
    int numsSize = 6;
    //0,1,2,3,4,5,6,7,8,9,10,11
    int *nums = numbers;
    int res = trap(nums, numsSize);
    printf("%d\n", res);

    return 0;
}
