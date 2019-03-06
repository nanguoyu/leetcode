// Source : https://leetcode.com/problems/implement-strstr/
// Author : nanguoyu
// Date   : 2019/3/6

/*******************************************************************************************************
Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Example 1:

Input: haystack = "hello", needle = "ll"
Output: 2
Example 2:

Input: haystack = "aaaaa", needle = "bba"
Output: -1
Clarification:

What should we return when needle is an empty string? This is a great question to ask during an interview.

For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr()
 and Java's indexOf().
 **********************************************************************************************************/

int strStr(char *haystack, char *needle)
{
    if (!haystack[0] && !needle[0]) { return 0; }
    int i = 0, j = 0, k = -1;
    while (haystack[i]) {
        j = 0;
        while (needle[j] && haystack[i + j] && haystack[i + j] == needle[j]) {

            j++;
        }
        if (!needle[j]) {
            k = i;
            break;
        }
        i++;
    }

    return k;
}
