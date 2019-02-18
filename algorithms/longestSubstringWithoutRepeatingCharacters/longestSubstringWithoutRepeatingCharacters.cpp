// Source : https://oj.leetcode.com/problems/longest-substring-without-repeating-characters/
// Author : nanguoyu
// Date   : 2019-02-18

/**********************************************************************************
*
* Given a string, find the length of the longest substring without repeating characters.
* For example, the longest substring without repeating letters for "abcabcbb" is "abc",
* which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.
*
**********************************************************************************/
int lengthOfLongestSubstring(char* s){
    int length = 0;
    int tempt = 0;
    int ascii[256]={0};
    ascii[0]=1;
    int start = 0;
    int end = start;
    while(s[start]||s[end]){
        if(!ascii[s[end]]){
            tempt = end-start+1;
            if(tempt>length){
                length=tempt;
            }
            ascii[s[end]]+=1;
            end++;
        } else{
            ascii[s[start]]=0;
            start++;
        }


    }
    return length;

}
