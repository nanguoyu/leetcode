// Source : https://leetcode.com/problems/powx-n/
// Author : nanguoyu
// Date   : 2019/3/25

/******************************************************************
Implement pow(x, n), which calculates x raised to the power n (xn).

Example 1:

Input: 2.00000, 10
Output: 1024.00000
Example 2:

Input: 2.10000, 3
Output: 9.26100
Example 3:

Input: 2.00000, -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25
Note:

-100.0 < x < 100.0
n is a 32-bit signed integer, within the range [−231, 231 − 1]
 *****************************************************************/


double myPow(double x, int n) {
    if(x==1||n==0){ return 1;}
    if(n==1){ return x;}
    double res=1;double unit=x;
    while(n){
        if(n&1){
            res*=unit;
        }
        unit*=unit;
        n>>=1;
    }
    return res;
}

int main()
{
    double x=2;int n=3;
    double res = myPow(x,n);
    printf("%f",res);
    return 0;
}

