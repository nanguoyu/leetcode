// Source : https://oj.leetcode.com/problems/reverse-integer/
// Author : nanguoyu
// Date   : 2019-02-21

/**********************************************************************************
*
* Reverse digits of an integer.
*
* Example1: x =  123, return  321
* Example2: x = -123, return -321
*
*
* Have you thought about this?
*
* Here are some good questions to ask before coding. Bonus points for you if you have already thought through this!
*
* > If the integer's last digit is 0, what should the output be? ie, cases such as 10, 100.
*
* > Did you notice that the reversed integer might overflow? Assume the input is a 32-bit integer,
*   then the reverse of 1000000003 overflows. How should you handle such cases?
*
* > Throw an exception? Good, but what if throwing an exception is not an option?
*   You would then have to re-design the function (ie, add an extra parameter).
*
*
**********************************************************************************/

int reverse(int x) {
#include <math.h>
    signed int tenPower[10] = {1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};
    int result = 0;
    int length = 0;
    int temp =x;
    while (temp){
        temp/=10;
        length++;
    }
    if(!(x/10)){
        return x;
    }

    int a=0,b=0;
    int left=length,right=1;
    while(left>=right){

        if(left==10){
            a=(int)x/tenPower[9];
        }else{
            a=x %(int)(tenPower[left])/(tenPower[left-1]);
        }
        b=x %(int)(tenPower[right])/(tenPower[right-1]);

        if(abs(b)>2&&left-1==9){
            return 0;
        }

        if(result<0){
            if(-b*tenPower[left-1]-1>INT_MAX+result){
                return 0;
            }
        }
        if(result>0){
            if(b*tenPower[left-1]>INT_MAX-result){
                return 0;
            }
        }

        result+=b*tenPower[left-1];


        if(right-1==9&&abs(a)>2){
            return 0;
        }

        if(result<0){
            if(-a*tenPower[right-1]-1>INT_MAX+result){
                return 0;
            }
        }
        if(result>0){
            if(a*tenPower[right-1]>INT_MAX-result){
                return 0;
            }
        }

        result+=a*tenPower[right-1];

        if(left==right){
            result-=(int)a*tenPower[left-1];
        }

        left--;
        right++;

    }

    return result;
}