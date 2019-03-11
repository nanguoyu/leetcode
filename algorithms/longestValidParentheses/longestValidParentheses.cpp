// Source : https://leetcode.com/problems/longest-valid-parentheses/
// Author : nanguoyu
// Date   : 2019/3/11

/******************************************************************
Given a string containing just the characters '(' and ')', find the
 length of the longest valid (well-formed) parentheses substring.

Example 1:

Input: "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()"
Example 2:

Input: ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()"
 *****************************************************************/


int longestValidParentheses(char *s)
{
    int len = 0;
    int i = 0, j = 0;
    int longest = 0;

    while (*(s + len)) { len++; }

    char *brackets = (char *) malloc(sizeof(char) * (len));
    memset(brackets, 0, (size_t) (len));

    int *pointIndex = (int *) malloc(sizeof(int) * len); int m=0;

    while (*(s + i)) {
        if (*(s + i) == '(') {
            brackets[j] = *(s + i); j++;
            pointIndex[m] = i; m++;

        } else if (*(s + i) == ')') {
            if (j > 0) {
                j--;m--;
            }
        }

        i++;
    }

    memset(brackets, 0, (size_t) (len)); i=0;j=0;int num=0;
    int w=0;
    while (*(s + i)) {
        if (*(s + i) == '(') {
            if(i==pointIndex[w]&&w<m){
                if(longest < num) { longest = num; } num = 0;
                w++;
            }else{
                brackets[j] = *(s + i); j++;
            }
        } else if (*(s + i) == ')') {
            if (j > 0) {
                j--;num += 2;
            } else {
                if(longest < num) { longest = num; } num = 0;
            }
        }

        i++;
    }
    if(longest < num) { longest = num; }

    return longest;
}

