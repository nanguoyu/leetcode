// Source : https://oj.leetcode.com/problems/string-to-integer-atoi/
// Author : nanguoyu
// Date   : 2019-02-22

/**********************************************************************************
*
* Implement atoi to convert a string to an integer.
*
* Hint: Carefully consider all possible input cases. If you want a challenge,
*       please do not see below and ask yourself what are the possible input cases.
*
* Notes:
*   It is intended for this problem to be specified vaguely (ie, no given input specs).
*   You are responsible to gather all the input requirements up front.
*
*
* Requirements for atoi:
*
* The function first discards as many whitespace characters as necessary until the first
* non-whitespace character is found. Then, starting from this character, takes an optional
* initial plus or minus sign followed by as many numerical digits as possible, and interprets
* them as a numerical value.
*
* The string can contain additional characters after those that form the integral number,
* which are ignored and have no effect on the behavior of this function.
*
* If the first sequence of non-whitespace characters in str is not a valid integral number,
* or if no such sequence exists because either str is empty or it contains only whitespace
* characters, no conversion is performed.
*
* If no valid conversion could be performed, a zero value is returned. If the correct value
* is out of the range of representable values, INT_MAX (2147483647) or INT_MIN (-2147483648)
* is returned.
*
**********************************************************************************/


int myAtoi(char *str)
{
    int result = 0;
    int negative = 1;
    bool has_one_sign = false;
    int i = 0;
    while (str[i]) {
        if (str[i] != ' ') {
            if (47 < str[i] && str[i] < 58) {
                if (!has_one_sign) {
                    has_one_sign = true;
                }
                if (result > INT_MAX / 10) {

                    if (negative == -1) {
                        return INT_MIN;
                    } else {
                        return INT_MAX;
                    }
                } else if (INT_MAX - str[i] + 48 < result * 10) {
                    if (negative == -1) {
                        return INT_MIN;
                    } else {
                        return INT_MAX;
                    }
                }
                result = result * 10 - 48 + str[i];
            } else if (str[i] == 43 || str[i] == 45) {
                if (has_one_sign) {
                    break;
                } else {
                    has_one_sign = true;
                }

                negative = 44 - str[i];
                if (!str[i + 1]) {
                    return 0;
                }
                if (str[i + 1] < 48 || str[i + 1] > 57) {
                    return 0;
                }
            } else {
                if (has_one_sign) {
                    break;
                }
                return 0;
            }
        } else {
            if (has_one_sign) {
                break;
            }
        }
        i++;
    }
    return result * negative;
}




