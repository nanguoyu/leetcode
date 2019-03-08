// Source : https://leetcode.com/problems/substring-with-concatenation-of-all-words/
// Author : nanguoyu
// Date   : 2019/3/8

/*********************************************************************************************************
You are given a string, s, and a list of words, words, that are all of the same length.
Find all starting indices of substring(s) in s that is a concatenation of each word in words exactly once
and without any intervening characters.

Example 1:

Input:
s = "barfoothefoobarman",
        words = ["foo","bar"]
Output: [0,9]
Explanation: Substrings starting at index 0 and 9 are "barfoor" and "foobar" respectively.
The output order does not matter, returning [9,0] is fine too.
Example 2:

Input:
s = "wordgoodgoodgoodbestword",
        words = ["word","good","best","word"]
Output: []
 ************************************************************************************************************/


int *findSubstring(char *s, char **words, int wordsSize, int *returnSize)
{
#define nullptr 0
    if (!wordsSize) { return nullptr; }
    bool *matchable = (bool *) malloc(sizeof(bool) * wordsSize);
    int matchedNumber = 0;
    for (int j = 0; j < wordsSize; ++j) {
        matchable[j] = false;
    }
    int wordLength = (int) strlen(words[0]);
    int sLenghth = (int) strlen(s);
    int len = wordLength * wordsSize;
    if (sLenghth < len) { return nullptr; }
    int i = 0;
    int start = 0;
    *returnSize = 0;
    int MAX_Result = sLenghth - len + 1;
    int *result = (int *) malloc(sizeof(int) * MAX_Result);
//    cout<<"wordsSize "<<wordsSize<<" wordLength "<<wordLength<<" sLenghth "<<sLenghth<<" len "<<len<<endl;
    while ((matchedNumber > 0 && i <= sLenghth - wordLength * (wordsSize - matchedNumber)) ||
           (matchedNumber == 0 && i <= sLenghth - len)) {
        bool matchedInThisLoop = false;
        if (matchedNumber == 0) { start = i; }
        for (int k = 0; k < wordsSize; ++k) {
            if (s[i] == words[k][0]) {
                if (matchable[k]) continue;
                //找到字典里没有被匹配的单词，
                int w = i + 1;
                int h = 1;
                for (h = 1; h < wordLength; ++h, w++) {
                    if (s[w] == words[k][h]) {
                        continue;
                    } else { break; }
                }
                if (h == wordLength) {
                    matchedNumber++;
                    matchable[k] = true;
                    matchedInThisLoop = true;
                    break;
                } else { matchedInThisLoop = false; }
            }
        }
        if (matchedNumber > 0 && matchedNumber < wordsSize) {
            if (matchedInThisLoop) {
                i += wordLength;
            } else {
                // 之前已经有单词匹配了，但是这次没匹配上。
                for (int j = 0; j < wordsSize; ++j) {
                    matchable[j] = false;
                }
                matchedNumber = 0;
                i = start + 1;
            }
        } else if (matchedNumber == 0) {
            i++;
        } else if (matchedNumber == wordsSize) {
            result[*returnSize] = start;
            *returnSize = *returnSize + 1;
            for (int j = 0; j < wordsSize; ++j) {
                matchable[j] = false;
            }
            matchedNumber = 0;
            i = start + 1;
        }

    }

    return result;

}
