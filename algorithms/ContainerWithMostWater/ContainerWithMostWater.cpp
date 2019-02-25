// Source : https://oj.leetcode.com/problems/container-with-most-water/
// Author : nanguoyu
// Date   : 2019-02-25

/**********************************************************************************
*
* Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai).
* n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0).
*
* Find two lines, which together with x-axis forms a container, such that the container contains the most water.
*
* Note: You may not slant the container.
*
*
**********************************************************************************/

int maxAreaB(int* height, int heightSize) {
    //O(n^2)
    int result=0,mHeight=0;
    for (int i = 0; i <heightSize; ++i) {
        for (int j = i+1; j < heightSize; ++j) {
            mHeight=*(height+i)>*(height+j)?*(height+j):*(height+i);
            result = result<mHeight*(j-i)? mHeight*(j-i):result;
        }
    }
    return result;
}

int maxArea(int* height, int heightSize){
    //O(n)
    int i=0,j=heightSize-1;
    int result=0,mHeight=0;
    while(i!=j){
        mHeight=*(height+i)>*(height+j)?*(height+j):*(height+i);
        result = result<mHeight*(j-i)? mHeight*(j-i):result;
        if (*(height+i)<=*(height+j)){
            i++;
        } else{
            j--;
        }

    }
    return result;
}