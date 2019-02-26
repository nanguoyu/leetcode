// Source : https://oj.leetcode.com/problems/roman-to-integer/
// Author : nanguoyu
// Date   : 2019-02-26

/**********************************************************************************
*
* Given a roman numeral, convert it to an integer.
*
* Input is guaranteed to be within the range from 1 to 3999.
*
**********************************************************************************/

int romanToInt(char *s)
{
    int result = 0;
    int i = 0;
    int C = 0;
    int X = 0;
    int I = 0;
    while (*(s + i)) {
        if (*(s + i) == 'M') {
            if (C == 1) {
                result += 900;
                result -= 100;
                i++;
            } else {
                while (*(s + i) == 'M') {
                    result += 1000;
                    i++;
                }
            }
        } else if (*(s + i) == 'C') {
            if (X == 1) {
                result += 90;
                result -= 10;
                i++;
            } else {
                while (*(s + i) == 'C') {
                    result += 100;
                    C++;
                    i++;
                }
            }
        } else if (*(s + i) == 'D') {
            if (C == 1) {
                result += 400;
                result -= 100;
            } else {
                result += 500;
            }
            i++;
        } else if (*(s + i) == 'X') {
            if (I == 1) {
                result += 9;
                result -= 1;
                i++;
            } else {
                while (*(s + i) == 'X') {
                    result += 10;
                    X++;
                    i++;
                }
            }
        } else if (*(s + i) == 'L') {
            if (X == 1) {
                result += 40;
                result -= 10;
            } else {
                result += 50;
            }
            i++;
        } else if (*(s + i) == 'I') {
            while (*(s + i) == 'I') {
                result += 1;
                I++;
                i++;
            }

        } else if (*(s + i) == 'V') {

            if (I == 1) {
                result += 4;
                result -= 1;
            } else {
                result += 5;
            }
            i++;
        }
        if (!*(s + i)) return result;
    }
    return 0;
}