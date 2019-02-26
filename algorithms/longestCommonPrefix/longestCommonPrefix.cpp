// Source : https://oj.leetcode.com/problems/longest-common-prefix/
// Author : nanguoyu
// Date   : 2019-02-26

/**********************************************************************************
*
* Write a function to find the longest common prefix string amongst an array of strings.
*
*
**********************************************************************************/

char* longestCommonPrefix(char** strs, int strsSize) {

    int i=0;
    char buffer;
    int j=0;
    char * result;
    if(!strsSize)return "\0";
    if(strsSize==1)return strs[0];
    while (strs[0][j]) {
        buffer = strs[0][j];
        for (i = 1; i < strsSize; ++i) {
            if (strs[i][j]!=buffer) {
                result=(char* ) malloc(sizeof(char)*(j+1));
                for (int k = 0; k < j; ++k) {
                    result[k]=strs[0][k];
                }
                result[j]=0;
                return result;
            }
        }
        j++;
    }
    result=(char* ) malloc(sizeof(char)*(j+1));
    for (int k = 0; k < j; ++k) {
        result[k]=strs[0][k];
    }
    result[j]=0;
    return result;
}