// Source : https://oj.leetcode.com/problems/integer-to-roman/
// Author : nanguoyu
// Date   : 2019-02-25

/**********************************************************************************
*
* Given an integer, convert it to a roman numeral.
*
* Input is guaranteed to be within the range from 1 to 3999.
*
**********************************************************************************/

char* intToRoman(int num) {
#include<string.h>
    const char *transformer[4][9]= {{"M","MM","MMM","0","0","0","0","0","0"},
                                    {"C","CC","CCC","CD","D","DC","DCC","DCCC","CM"},
                                    {"X","XX","XXX","XL","L","LX","LXX","LXXX","XC"},
                                    {"I","II","III","IV","V","VI","VII","VIII","IX"}};
    const int units[4] = {1000,100,10,1};
    char *result = (char *)malloc(sizeof(char )*16);
    result[0]=0;
    for (int i = 0; i <4; ++i) {
        if (num/units[i]){
            strcat(result,transformer[i][num/units[i]-1]);
            num = num%units[i];
        }
    }
    return result;
}