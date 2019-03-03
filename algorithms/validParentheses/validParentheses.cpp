// Source : https://leetcode.com/problems/valid-parentheses/
// Author : nanguoyu
// Date   : 2019/3/3

/**********************************************************************************
*
* Given a string containing just the characters '(', ')', '{', '}', '[' and ']',
* determine if the input string is valid.
*
* The brackets must close in the correct order, "()" and "()[]{}" are all valid
* but "(]" and "([)]" are not.
*
*
**********************************************************************************/

bool isValid(char* s) {
    int length =0;
    while(*(s+length)){length++;}
    char *brackets = (char *)malloc(sizeof(char )*(length));
    int i=0,j=0;
    memset(brackets, 0, (size_t) (length));

    while(*(s+i)){
        if ( *(s+i) == '('|| *(s+i) == '['||*(s+i) == '{'){
            brackets[j]=*(s+i);
            j++;
        } else if(*(s+i) == ')'||*(s+i) == ']'||*(s+i) == '}'){
            if (j>0){
                if((*(s+i)==')'&&brackets[j-1]=='(')||(*(s+i)==']'&&brackets[j-1]=='[')||(*(s+i)=='}'&&brackets[j-1]=='{')){
                    j--;i++;continue;
                }else { return false;}
            } else { return false;}
        }
        i++;
    }
    return i >= 0 && j == 0;
}
