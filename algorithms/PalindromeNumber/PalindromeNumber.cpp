// Source : https://oj.leetcode.com/problems/palindrome-number/
// Author : nanguoyu
// Date   : 2019-02-22

/**********************************************************************************
*
* Determine whether an integer is a palindrome. Do this without extra space.
*
*
* Some hints:
*
* Could negative integers be palindromes? (ie, -1)
*
* If you are thinking of converting the integer to string, note the restriction of using extra space.
*
* You could also try reversing an integer. However, if you have solved the problem "Reverse Integer",
* you know that the reversed integer might overflow. How would you handle such case?
*
* There is a more generic way of solving this problem.
*
*
**********************************************************************************/

bool isPalindrome(int x) {

    if(x<0){
        return false;
    }
    if(!(x/10)){
        return true;
    }

    int unit=0,lenght=0;
    int units[10]={0};
    while(x!=0){
        unit=x%10;
        x/=10;
        units[lenght]=unit;
        lenght++;
    }
    int left=0,right=lenght-1;
    while(left<=right){
        if (units[left]!=units[right]){
            return false;
        }
        left++;
        right--;
    }
    return true;


}


bool isPalindrome_B(int x) {
    if(x<0){
        return false;
    }
    int tenPower[10] = {1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};
    int length = 0;
    int temp =x;
    while (temp){
        temp/=10;
        length++;
    }

    if(!(x/10)){
        return true;
    }
    int a=0,b=0;
    int left=length-1,right=0;
    while(left>=right){
        if(left==9){
            a=x/tenPower[9];
        }else{
            a=x %(tenPower[left+1])/(tenPower[left]);
        }

        b=x %(tenPower[right+1])/(tenPower[right]);
        if (a!=b){
            return false;
        }
        left--;
        right++;

    }
    return true;

}