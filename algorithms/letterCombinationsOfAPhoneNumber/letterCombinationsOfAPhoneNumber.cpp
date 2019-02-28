// Source : https://oj.leetcode.com/problems/letter-combinations-of-a-phone-number/
// Author : nanguoyu
// Date   : 2019/2/28

/**********************************************************************************
*
* Given a digit string, return all possible letter combinations that the number could represent.
*
* A mapping of digit to letters (just like on the telephone buttons) is given below.
*
* Input:Digit string "23"
* Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
*
* Note:
* Although the above answer is in lexicographical order, your answer could be in any order you want.
*
*
**********************************************************************************/
const char *number2letter[10][4] = {{""},{""},{"a", "b", "c"},
                                    {"d", "e", "f"},
                                    {"g", "h", "i"},
                                    {"j", "k", "l"},
                                    {"m", "n", "o"},
                                    {"p", "q", "r", "s"},
                                    {"t", "u", "v",},
                                    {"w", "x", "y", "z"}};

int fun(char *Prefix, char *PhoneStr, int *index, char **result, int lenght, int numberhasdone )
{
#include<string.h>


    char *lastphoneStr = PhoneStr + 1;
    if (numberhasdone <lenght) {
        for (int j = 0; j < 4; ++j) {

            if (number2letter[(*PhoneStr) - 48][j]) {
                char *pre = (char *) malloc(sizeof(char) * (lenght+1));
                pre[0] = 0;
                strcat(pre, Prefix);
                strcat(pre, number2letter[(*PhoneStr) - 48][j]);// 添加字母
                int number = numberhasdone;
                number++;
                fun(pre, lastphoneStr, index, result, lenght, number);

            }
        }

    } else {
        result[*index] = Prefix;
        (*index)++;

        return 0;
    }

    return 0;
}

char **letterCombinations(char *digits, int *returnSize)
{
    int length = 0;
    int *index = (int *) malloc(sizeof(int));
    *index=0;

    while (digits[length]) {
        length++;
    }
    if(!length)
        return 0;
    *returnSize = 1;


    for (int i = 0; i < length; ++i) {
        *returnSize *= 4;
    }

    char **result = (char **) malloc(sizeof(char *) * (*returnSize));

    for (int j = 0; j < 4; ++j) {

        if (number2letter[(*digits) - 48][j]) {
            char *pre = (char *) malloc(sizeof(char) * (length + 1));
            pre[0] = 0;
            strcat(pre, number2letter[(*digits) - 48][j]);// 添加字母

            int numberhasdone = 1;

            fun(pre, digits+1, index, result, length, numberhasdone);
        }
    }
    *returnSize = *index;
    return result;
}