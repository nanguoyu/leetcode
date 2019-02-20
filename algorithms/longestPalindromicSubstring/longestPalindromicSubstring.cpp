// Source : https://oj.leetcode.com/problems/longest-palindromic-substring/
// Author : nanguoyu
// Date   : 2019-02-20

/**********************************************************************************
*
* Given a string S, find the longest palindromic substring in S.
* You may assume that the maximum length of S is 1000,
* and there exists one unique longest palindromic substring.
*
**********************************************************************************/


char *longestPalindrome(char *s)
{
    int i = 1;
    int left = 0, right = 2;

    int longest_length = 1;
    int longest_index_left = 0;
    int longest_index_right = 1;
    if(!s[0]||!s[1]){
        return s;
    }

    while (s[i]) {
        if (s[i] == s[left]) {
            int j = left, k = i;
            while (j >= 0 && s[k] && (s[j] == s[k])) {
                if (k - j + 1 >= longest_length) {
                    longest_length = k - j + 1;
                    longest_index_right = k;
                    longest_index_left = j;
                }
                k++;
                j--;
            }
        }
        if(s[right] == s[left]){
            int m = left, n = right;
            while(m>=0&&s[n]&&(s[m]==s[n])){
                if (n - m + 1 >= longest_length) {
                    longest_length = n - m + 1;
                    longest_index_right = n;
                    longest_index_left = m;
                }
                n++;
                m--;
            }
        }
        i++;
        left=i-1;
        right=i+1;
    }
    char *result = (char *)malloc(sizeof(char)*longest_length+1);
    int x =0;
    for (int l = longest_index_left; l <= longest_index_right; ++l) {
        result[x]=s[l];
        x++;
    }
    result[longest_length]=0;
    return result;
}